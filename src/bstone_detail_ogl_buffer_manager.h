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
// OpenGL buffer object manager (implementation interface).
//


#ifndef BSTONE_DETAIL_OGL_BUFFER_MANAGER_INCLUDED
#define BSTONE_DETAIL_OGL_BUFFER_MANAGER_INCLUDED


#include <memory>

#include "bstone_renderer.h"


namespace bstone
{


class RendererBuffer;
using RendererBufferPtr = RendererBuffer*;

class RendererIndexBuffer;
using RendererIndexBufferPtr = RendererIndexBuffer*;

class RendererVertexBuffer;
using RendererVertexBufferPtr = RendererVertexBuffer*;


namespace detail
{


class OglState;
using OglStatePtr = OglState*;

class OglVaoManager;
using OglVaoManagerPtr = OglVaoManager*;


// ==========================================================================
// OglBufferManager
//

class OglBufferManager
{
protected:
	OglBufferManager();


public:
	virtual ~OglBufferManager();


	virtual RendererIndexBufferPtr index_buffer_create(
		const RendererIndexBufferCreateParam& param) = 0;

	virtual RendererVertexBufferPtr vertex_buffer_create(
		const RendererVertexBufferCreateParam& param) = 0;


	virtual void buffer_destroy(
		const RendererBufferPtr buffer) = 0;


	virtual bool buffer_set_current(
		const RendererBufferKind buffer_kind,
		const RendererBufferPtr buffer) = 0;
}; // OglBufferManager

using OglBufferManagerPtr = OglBufferManager*;
using OglBufferManagerUPtr = std::unique_ptr<OglBufferManager>;

//
// OglBufferManager
// ==========================================================================


// ==========================================================================
// OglBufferManagerFactory
//

struct OglBufferManagerFactory final
{
	static OglBufferManagerUPtr create(
		const OglStatePtr ogl_state,
		const OglVaoManagerPtr ogl_vao_manager);
}; // OglBufferManagerFactory

//
// OglBufferManagerFactory
// ==========================================================================


} // detail
} // bstone


#endif // !BSTONE_DETAIL_OGL_BUFFER_MANAGER_INCLUDED