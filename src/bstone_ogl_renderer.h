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
// OpenGL renderer.
//
// !!! Internal usage only !!!
//


#ifndef BSTONE_OGL_RENDERER_INCLUDED
#define BSTONE_OGL_RENDERER_INCLUDED


#include "bstone_renderer.h"


namespace bstone
{


class OglXRenderer :
	public Renderer
{
public:
}; // OglXRenderer

using OglXRendererUPtr = std::unique_ptr<OglXRenderer>;


class OglRenderer :
	public OglXRenderer
{
public:
	OglRenderer();

	OglRenderer(
		OglRenderer&& rhs);

	~OglRenderer() override;


	const std::string& get_error_message() const override;


	RendererKind get_kind() const override;

	const std::string& get_name() const override;

	const std::string& get_description() const override;


	bool probe(
		const RendererPath renderer_path) override;

	RendererPath get_probe_path() const override;


	bool is_initialized() const override;

	bool initialize(
		const RendererInitializeParam& param) override;

	void uninitialize() override;


	RendererPath get_path() const override;


	void window_show(
		const bool is_visible) override;


	void color_buffer_set_clear_color(
		const RendererColor32& color) override;

	void set_2d_projection_matrix(
		const int width,
		const int height) override;

	void clear_buffers() override;

	void present() override;


	RendererIndexBufferUPtr index_buffer_create(
		const RendererIndexBufferCreateParam& param) override;


	RendererVertexBufferHandle vertex_buffer_create(
		const int vertex_count) override;

	void vertex_buffer_destroy(
		RendererVertexBufferHandle id) override;

	void vertex_buffer_update(
		RendererVertexBufferHandle id,
		const int offset,
		const int count,
		const RendererVertex* const vertices) override;


	RendererTexture2dHandle texture_2d_create(
		const RendererTextureCreateParam& param) override;

	void texture_2d_destroy(
		RendererTexture2dHandle texture_handle) override;

	void texture_2d_update(
		RendererTexture2dHandle texture_handle,
		const RendererTextureUpdateParam& param) override;


	void execute_command_sets(
		const RendererCommandSets& command_sets) override;


private:
	bool is_initialized_;
	std::string error_message_;

	RendererPath probe_renderer_path_;
	RendererPath renderer_path_;
	OglXRendererUPtr renderer_;


	template<typename TRenderer>
	bool probe_ogl_x(
		const RendererPath renderer_path)
	{
		auto ogl_x_renderer = TRenderer{};

		if (!ogl_x_renderer.probe(renderer_path))
		{
			probe_renderer_path_ = RendererPath::none;

			return false;
		}

		probe_renderer_path_ = renderer_path;

		return true;
	}

	template<typename TRenderer>
	bool initialize_ogl_x(
		const RendererInitializeParam param)
	{
		auto renderer = OglXRendererUPtr{new TRenderer{}};

		if (!renderer->initialize(param))
		{
			error_message_ = renderer->get_error_message();

			return false;
		}

		is_initialized_ = true;
		renderer_ = std::move(renderer);

		return true;
	}

	void uninitialize_internal(
		const bool is_dtor = false);
}; // OglRenderer


} // bstone


#endif // !BSTONE_OGL_RENDERER_INCLUDED