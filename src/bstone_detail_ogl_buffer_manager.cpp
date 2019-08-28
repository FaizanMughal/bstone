/*
BStone: A Source port of
Blake Stone: Aliens of Gold and Blake Stone: Planet Strike

Copyright (c) 1992-2013 Apogee Entertainment, LLC
Copyright (c) 2013-2019 Boris I. Bendovsky (bibendovsky@hotmail.com)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the
Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/


//
// OpenGL buffer object manager (implementation).
//


#include "bstone_precompiled.h"
#include "bstone_detail_ogl_buffer_manager.h"

#include "bstone_exception.h"
#include "bstone_uptr_resource_list.h"

#include "bstone_detail_ogl_index_buffer.h"
#include "bstone_detail_ogl_vao_manager.h"
#include "bstone_detail_ogl_vertex_buffer.h"


namespace bstone
{
namespace detail
{


// ==========================================================================
// OglBufferManager
//

OglBufferManager::OglBufferManager() = default;

OglBufferManager::~OglBufferManager() = default;

//
// OglBufferManager
// ==========================================================================


// ==========================================================================
// GenericOglBufferManager
//

class GenericOglBufferManager :
	public OglBufferManager
{
public:
	GenericOglBufferManager(
		const OglStatePtr ogl_state,
		const OglVaoManagerPtr ogl_vao_manager);

	~GenericOglBufferManager() override;


	RendererIndexBufferPtr index_buffer_create(
		const RendererIndexBufferCreateParam& param) override;

	RendererVertexBufferPtr vertex_buffer_create(
		const RendererVertexBufferCreateParam& param) override;


	void buffer_destroy(
		const RendererBufferPtr buffer) override;


	bool buffer_set_current(
		const RendererBufferKind buffer_kind,
		const RendererBufferPtr index_buffer) override;


private:
	const OglStatePtr ogl_state_;
	const OglVaoManagerPtr ogl_vao_manager_;

	using IndexBuffers = UPtrResourceList<OglIndexBuffer, OglIndexBufferFactory, Exception>;
	IndexBuffers index_buffers_;

	using VertexBuffers = UPtrResourceList<OglVertexBuffer, OglVertexBufferFactory, Exception>;
	RendererBufferPtr vertex_buffer_current_;
	VertexBuffers vertex_buffers_;


	void initialize();
}; // GenericOglBufferManager

using GenericOglBufferManagerPtr = GenericOglBufferManager*;
using GenericOglBufferManagerUPtr = std::unique_ptr<GenericOglBufferManager>;

//
// GenericOglBufferManager
// ==========================================================================


// ==========================================================================
// GenericOglBufferManager
//

GenericOglBufferManager::GenericOglBufferManager(
	const OglStatePtr ogl_state,
	const OglVaoManagerPtr ogl_vao_manager)
	:
	ogl_state_{ogl_state},
	ogl_vao_manager_{ogl_vao_manager},
	index_buffers_{},
	vertex_buffer_current_{},
	vertex_buffers_{}
{
	initialize();
}

GenericOglBufferManager::~GenericOglBufferManager() = default;

RendererIndexBufferPtr GenericOglBufferManager::index_buffer_create(
	const RendererIndexBufferCreateParam& param)
{
	return index_buffers_.add(ogl_state_, param);
}

RendererVertexBufferPtr GenericOglBufferManager::vertex_buffer_create(
	const RendererVertexBufferCreateParam& param)
{
	return vertex_buffers_.add(ogl_state_, param);
}

void GenericOglBufferManager::buffer_destroy(
	const RendererBufferPtr buffer)
{
	if (!buffer)
	{
		throw Exception{"Null buffer."};
	}

	const auto buffer_kind = buffer->get_kind();

	switch (buffer_kind)
	{
		case RendererBufferKind::index:
			index_buffers_.remove(buffer);
			break;

		case RendererBufferKind::vertex:
			vertex_buffers_.remove(buffer);
			break;

		default:
			throw Exception{"Unsupported buffer kind."};
	}
}

bool GenericOglBufferManager::buffer_set_current(
	const RendererBufferKind buffer_kind,
	const RendererBufferPtr buffer)
{
	RendererBufferPtr* buffer_current_ptr = nullptr;

	switch (buffer_kind)
	{
		case RendererBufferKind::index:
			return ogl_vao_manager_->index_buffer_set_current(buffer);

		case RendererBufferKind::vertex:
			buffer_current_ptr = &vertex_buffer_current_;

			break;

		default:
			throw Exception{"Unsupported buffer kind."};
	}

	if (!buffer_current_ptr)
	{
		throw Exception{"Null current buffer."};
	}

	if (*buffer_current_ptr == buffer)
	{
		return false;
	}

	*buffer_current_ptr = buffer;

	return true;
}

void GenericOglBufferManager::initialize()
{
	if (!ogl_state_)
	{
		throw Exception{"Null OpenGL state."};
	}
}

//
// GenericOglBufferManager
// ==========================================================================


// ==========================================================================
// OglBufferManagerFactory
//

OglBufferManagerUPtr OglBufferManagerFactory::create(
	const OglStatePtr ogl_state,
	const OglVaoManagerPtr ogl_vao_manager)
{
	return std::make_unique<GenericOglBufferManager>(ogl_state, ogl_vao_manager);
}

//
// OglBufferManagerFactory
// ==========================================================================


} // detail
} // bstone