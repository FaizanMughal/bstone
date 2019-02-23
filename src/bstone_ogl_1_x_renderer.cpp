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
// OpenGL 1.x renderer.
//
// !!! Internal usage only !!!
//



#include "bstone_precompiled.h"
#include "bstone_ogl_1_x_renderer.h"
#include <cassert>
#include "bstone_ogl_renderer_utils.h"


namespace bstone
{


// ==========================================================================
// Ogl1XRenderer::IndexBuffer
//

Ogl1XRenderer::IndexBuffer::IndexBuffer(
	Ogl1XRenderer* renderer)
	:
	renderer_{renderer},
	count_{},
	byte_depth_{},
	size_in_bytes_{},
	data_type_{},
	data_{}
{
	assert(renderer_);
}

Ogl1XRenderer::IndexBuffer::~IndexBuffer()
{
	renderer_->index_buffers_.remove_if(
		[&](const auto& item)
		{
			return this == item;
		}
	);
}

RendererIndexBuffer::Value Ogl1XRenderer::IndexBuffer::fetch_index(
	const int offset)
{
	if (offset >= 0 && offset < count_)
	{
		assert(!"Invalid offset.");

		return 0;
	}

	const auto data_offset = byte_depth_ * offset;
	const auto data = &data_[data_offset];

	Value result;

	switch (byte_depth_)
	{
	case 1:
		result = *reinterpret_cast<const std::uint8_t*>(data);
		break;

	case 2:
		result = *reinterpret_cast<const std::uint16_t*>(data);
		break;

	case 4:
		result = *reinterpret_cast<const std::uint32_t*>(data);
		break;

	default:
		assert(!"Invalid byte depth.");

		result = 0;
		break;
	}

	return result;
}

void Ogl1XRenderer::IndexBuffer::update(
	const RendererIndexBufferUpdateParam& param)
{
	auto error_message = std::string{};

	if (!RendererUtils::validate_index_buffer_update_param(param, error_message))
	{
		assert(!"Invalid update parameter.");

		return;
	}

	if (param.offset_ >= count_)
	{
		assert(!"Offset out of range.");

		return;
	}

	if (param.count_ > count_)
	{
		assert(!"Count out of range.");

		return;
	}

	if ((param.offset_ + param.count_) > count_)
	{
		assert(!"Block out of range.");

		return;
	}


	const auto offset_in_bytes = param.offset_ * byte_depth_;
	const auto size_in_bytes = param.count_ * byte_depth_;

	std::uninitialized_copy_n(
		static_cast<const std::uint8_t*>(param.indices_),
		size_in_bytes,
		data_.begin() + offset_in_bytes
	);
}

bool Ogl1XRenderer::IndexBuffer::initialize(
	const RendererIndexBufferCreateParam& param,
	std::string& error_message)
{
	if (!RendererUtils::validate_index_buffer_create_param(param, error_message))
	{
		return false;
	}

	auto byte_depth = 0;
	auto data_type = GLenum{};

	if (param.index_count_ <= 0x100)
	{
		byte_depth = 1;
		data_type = GL_UNSIGNED_BYTE;
	}
	else if (param.index_count_ <= 0x10'000)
	{
		byte_depth = 2;
		data_type = GL_UNSIGNED_SHORT;
	}
	else
	{
		byte_depth = 4;
		data_type = GL_UNSIGNED_INT;
	}

	const auto size_in_bytes = param.index_count_ * byte_depth;

	count_ = param.index_count_;
	byte_depth_ = byte_depth;
	size_in_bytes_ = size_in_bytes;
	data_type_ = data_type;
	data_.resize(size_in_bytes);

	return true;
}

//
// Ogl1XRenderer::IndexBuffer
// ==========================================================================


// ==========================================================================
// Ogl1XRenderer
//

Ogl1XRenderer::Ogl1XRenderer()
	:
	is_initialized_{},
	error_message_{},
	probe_renderer_path_{},
	sdl_window_{},
	sdl_gl_context_{},
	palette_{},
	two_d_projection_matrix_{},
	index_buffers_{},
	vertex_buffers_{},
	texture_buffer_{},
	textures_2d_{}
{
}

Ogl1XRenderer::Ogl1XRenderer(
	Ogl1XRenderer&& rhs)
	:
	is_initialized_{std::move(rhs.is_initialized_)},
	error_message_{std::move(rhs.error_message_)},
	probe_renderer_path_{std::move(rhs.probe_renderer_path_)},
	sdl_window_{std::move(rhs.sdl_window_)},
	sdl_gl_context_{std::move(rhs.sdl_gl_context_)},
	palette_{std::move(rhs.palette_)},
	two_d_projection_matrix_{std::move(rhs.two_d_projection_matrix_)},
	index_buffers_{std::move(rhs.index_buffers_)},
	vertex_buffers_{std::move(rhs.vertex_buffers_)},
	texture_buffer_{std::move(rhs.texture_buffer_)},
	textures_2d_{std::move(rhs.textures_2d_)}
{
	rhs.is_initialized_ = false;
	rhs.sdl_window_ = nullptr;
	rhs.sdl_gl_context_ = nullptr;
}

Ogl1XRenderer::~Ogl1XRenderer()
{
	uninitialize_internal(true);
}

const std::string& Ogl1XRenderer::get_error_message() const
{
	return error_message_;
}

RendererKind Ogl1XRenderer::get_kind() const
{
	return RendererKind::opengl;
}

const std::string& Ogl1XRenderer::get_name() const
{
	static const auto result = std::string{"ogl1"};

	return result;
}

const std::string& Ogl1XRenderer::get_description() const
{
	static const auto result = std::string{"OpenGL 1.x"};

	return result;
}

bool Ogl1XRenderer::probe(
	const RendererPath renderer_path)
{
	return probe_or_initialize(true, renderer_path, RendererInitializeParam{});
}

RendererPath Ogl1XRenderer::get_probe_path() const
{
	return probe_renderer_path_;
}

bool Ogl1XRenderer::is_initialized() const
{
	return is_initialized_;
}

bool Ogl1XRenderer::initialize(
	const RendererInitializeParam& param)
{
	uninitialize_internal();

	return probe_or_initialize(false, RendererPath::none, param);
}

void Ogl1XRenderer::uninitialize()
{
	uninitialize_internal();
}

RendererPath Ogl1XRenderer::get_path() const
{
	if (!is_initialized_)
	{
		return RendererPath::none;
	}

	return RendererPath::ogl_1_x;
}

void Ogl1XRenderer::window_show(
	const bool is_visible)
{
	if (!is_initialized_)
	{
		return;
	}

	static_cast<void>(RendererUtils::show_window(sdl_window_, is_visible, error_message_));
}

void Ogl1XRenderer::color_buffer_set_clear_color(
	const RendererColor32& color)
{
	assert(is_initialized_);

	OglRendererUtils::set_color_buffer_clear_color(color);
}

void Ogl1XRenderer::clear_buffers()
{
	assert(is_initialized_);

	OglRendererUtils::clear_buffers();
}

void Ogl1XRenderer::present()
{
	assert(is_initialized_);

	OglRendererUtils::swap_window(sdl_window_);
}

void Ogl1XRenderer::set_2d_projection_matrix(
	const int width,
	const int height)
{
	assert(is_initialized_);
	assert(width > 0);
	assert(height > 0);

	const auto& new_matrix = OglRendererUtils::build_2d_projection_matrix(width, height);

	if (two_d_projection_matrix_ == new_matrix)
	{
		return;
	}

	two_d_projection_matrix_ = new_matrix;
}

RendererIndexBufferUPtr Ogl1XRenderer::index_buffer_create(
	const RendererIndexBufferCreateParam& param)
{
	auto index_buffer = IndexBufferUPtr{new IndexBuffer{this}};

	index_buffers_.emplace_back(index_buffer.get());

	if (!index_buffer->initialize(param, error_message_))
	{
		error_message_ = "Failed to create an index buffer. " + error_message_;

		return nullptr;
	}

	return index_buffer;
}

RendererVertexBufferHandle Ogl1XRenderer::vertex_buffer_create(
	const int vertex_count)
{
	assert(is_initialized_);
	assert(vertex_count > 0 && (vertex_count % 4) == 0);

	vertex_buffers_.emplace_back();
	auto& vertex_buffer = vertex_buffers_.back();

	vertex_buffer.resize(vertex_count);

	return reinterpret_cast<RendererVertexBufferHandle>(&vertex_buffer);
}

void Ogl1XRenderer::vertex_buffer_destroy(
	RendererVertexBufferHandle id)
{
	assert(is_initialized_);
	assert(id);

	vertex_buffers_.remove_if(
		[=](const auto& item)
		{
			return reinterpret_cast<const VertexBuffer*>(id) == &item;
		}
	);
}

void Ogl1XRenderer::vertex_buffer_update(
	RendererVertexBufferHandle id,
	const int offset,
	const int count,
	const RendererVertex* const vertices)
{
	assert(is_initialized_);
	assert(id);
	assert(offset >= 0);
	assert(count > 0);
	assert(vertices != nullptr);

	auto& vertex_buffer = *reinterpret_cast<VertexBuffer*>(id);
	const auto max_vertex_count = static_cast<int>(vertex_buffer.size());

	assert(offset < max_vertex_count);
	assert(count <= max_vertex_count);
	assert(count <= (max_vertex_count - offset));

	std::uninitialized_copy_n(vertices, count, vertex_buffer.begin() + offset);
}

void Ogl1XRenderer::execute_command_sets(
	const RendererCommandSets& command_sets)
{
	assert(!command_sets.empty());

	for (auto& command_set : command_sets)
	{
		const auto& commands = command_set.commands_;

		for (int i = 0; i < command_set.count_; ++i)
		{
			const auto& command = commands[i];

			switch (command.id_)
			{
			case RendererCommandId::set_2d:
				execute_command_set_2d();
				break;

			case RendererCommandId::update_palette:
				execute_command_update_palette(command.update_palette_);
				break;

			case RendererCommandId::draw_quads:
				execute_command_draw_quads(command.draw_quads_);
				break;

			default:
				assert(!"Unsupported command id.");
				break;
			}
		}
	}
}

bool Ogl1XRenderer::probe_or_initialize(
	const bool is_probe,
	const RendererPath probe_renderer_path,
	const RendererInitializeParam& param)
{
	const auto renderer_path = (is_probe ? probe_renderer_path : param.renderer_path_);

	if (renderer_path != RendererPath::ogl_1_x)
	{
		error_message_ = "Invalid renderer path value.";

		return false;
	}

	auto is_succeed = true;
	auto sdl_window = SdlWindowPtr{};
	auto sdl_gl_context = SdlGlContext{};

	if (is_succeed)
	{
		if (is_probe)
		{
			if (!OglRendererUtils::create_probe_window_and_context(sdl_window, sdl_gl_context, error_message_))
			{
				is_succeed = false;
			}
		}
		else
		{
			auto window_param = RendererUtilsCreateWindowParam{};
			window_param.is_opengl_ = true;
			window_param.window_ = param.window_;

			if (!OglRendererUtils::create_window_and_context(window_param, sdl_window, sdl_gl_context, error_message_))
			{
				is_succeed = false;
			}
		}
	}

	if (is_succeed)
	{
		if (!OglRendererUtils::resolve_symbols_1_1())
		{
			error_message_ = "Failed to load OpenGL 1.1 symbols.";

			is_succeed = false;
		}
	}

	if (!is_succeed)
	{
		OglRendererUtils::destroy_window_and_context(sdl_window, sdl_gl_context);

		return false;
	}

	is_initialized_ = true;
	sdl_window_ = sdl_window;
	sdl_gl_context_ = sdl_gl_context;

	if (!is_probe)
	{
		OglRendererUtils::clear_buffers();
		OglRendererUtils::swap_window(sdl_window);
	}

	return true;
}

RendererTexture2dHandle Ogl1XRenderer::texture_2d_create(
	const RendererTextureCreateParam& param)
{
	assert(is_initialized_);
	assert(RendererUtils::validate_renderer_texture_create_param(param, error_message_));

	auto texture_2d = Texture2d{};
	texture_2d.width_ = param.width_;
	texture_2d.height_ = param.height_;

	texture_2d.actual_width_ = RendererUtils::find_nearest_pot_value(param.width_);
	texture_2d.actual_height_ = RendererUtils::find_nearest_pot_value(param.height_);

	texture_2d.indexed_pixels_ = param.indexed_pixels_;
	texture_2d.indexed_alphas_ = param.indexed_alphas_;

	texture_2d.is_npot_ = (
		texture_2d.width_ != texture_2d.actual_width_ ||
		texture_2d.height_ != texture_2d.actual_height_);

	const auto internal_format = (texture_2d.indexed_alphas_ ? GL_RGBA8 : GL_RGB8);

	auto ogl_id = GLuint{};

	::glGenTextures(1, &ogl_id);
	assert(!OglRendererUtils::was_errors());
	assert(ogl_id != 0);

	::glBindTexture(GL_TEXTURE_2D, ogl_id);
	assert(!OglRendererUtils::was_errors());

	::glTexImage2D(
		GL_TEXTURE_2D, // target
		0, // level
		internal_format, // internal format
		texture_2d.actual_width_, // width
		texture_2d.actual_height_, // height
		0, // border
		GL_RGBA, // format
		GL_UNSIGNED_BYTE, // type
		nullptr // pixels
	);

	assert(!OglRendererUtils::was_errors());

	::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	assert(!OglRendererUtils::was_errors());

	::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	assert(!OglRendererUtils::was_errors());

	::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	assert(!OglRendererUtils::was_errors());

	::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	assert(!OglRendererUtils::was_errors());

	update_indexed_texture(0, texture_2d);

	texture_2d.ogl_id_ = ogl_id;

	textures_2d_.push_back(texture_2d);

	return reinterpret_cast<RendererTexture2dHandle>(&textures_2d_.back());
}

void Ogl1XRenderer::texture_2d_destroy(
	RendererTexture2dHandle texture_handle)
{
	assert(is_initialized_);
	assert(texture_handle);

	const auto texture_end_it = textures_2d_.end();

	auto texture_2d_it = std::find_if(
		textures_2d_.begin(),
		texture_end_it,
		[=](const auto& item)
		{
			return reinterpret_cast<const Texture2d*>(texture_handle) == &item;
		}
	);

	assert(texture_2d_it != texture_end_it);

	::glDeleteTextures(1, &texture_2d_it->ogl_id_);
	assert(!OglRendererUtils::was_errors());

	static_cast<void>(textures_2d_.erase(texture_2d_it));
}

void Ogl1XRenderer::texture_2d_update(
	RendererTexture2dHandle texture_handle,
	const RendererTextureUpdateParam& param)
{
	assert(is_initialized_);
	assert(texture_handle);
	assert(RendererUtils::validate_renderer_texture_update_param(param, error_message_));

	const auto texture_end_it = textures_2d_.end();

	auto texture_2d_it = std::find_if(
		textures_2d_.begin(),
		texture_end_it,
		[=](const auto& item)
		{
			return reinterpret_cast<const Texture2d*>(texture_handle) == &item;
		}
	);

	assert(texture_2d_it != texture_end_it);

	auto& texture_2d = *texture_2d_it;
	texture_2d.indexed_pixels_ = param.indexed_pixels_;

	::glBindTexture(GL_TEXTURE_2D, texture_2d.ogl_id_);
	assert(!OglRendererUtils::was_errors());

	update_indexed_texture(0, texture_2d);
}

void Ogl1XRenderer::uninitialize_internal(
	const bool is_dtor)
{
	if (sdl_gl_context_)
	{
		static_cast<void>(OglRendererUtils::make_context_current(sdl_window_, nullptr, error_message_));
	}

	OglRendererUtils::destroy_window_and_context(sdl_window_, sdl_gl_context_);

	if (!is_dtor)
	{
		palette_ = {};
		two_d_projection_matrix_ = {};
		index_buffers_.clear();
		vertex_buffers_.clear();
		texture_buffer_.clear();
	}

	for (const auto& texture_2d : textures_2d_)
	{
		::glDeleteTextures(1, &texture_2d.ogl_id_);
		assert(!OglRendererUtils::was_errors());
	}

	textures_2d_.clear();
}

void Ogl1XRenderer::update_indexed_texture(
	const int mipmap_level,
	const Texture2d& texture_2d)
{
	assert(mipmap_level == 0);

	const auto has_alpha = (texture_2d.indexed_alphas_ != nullptr);
	const auto area = texture_2d.actual_width_ * texture_2d.actual_height_;

	texture_buffer_.clear();
	texture_buffer_.resize(area);

	if (!texture_2d.is_npot_)
	{
		for (int i = 0; i < area; ++i)
		{
			texture_buffer_[i] = palette_[texture_2d.indexed_pixels_[i]];

			const auto is_transparent = (!has_alpha || (has_alpha && !texture_2d.indexed_alphas_[i]));

			if (is_transparent)
			{
				texture_buffer_[i].a_ = 0x00;
			}
		}
	}
	else
	{
		// Resample.
		//

		const auto src_du_d =
			static_cast<double>(texture_2d.width_) /
			static_cast<double>(texture_2d.actual_width_);

		const auto src_dv_d =
			static_cast<double>(texture_2d.height_) /
			static_cast<double>(texture_2d.actual_height_);

		auto src_v_d = 0.5 * src_dv_d;

		for (int h = 0; h < texture_2d.actual_height_; ++h)
		{
			const auto src_v = static_cast<int>(src_v_d);

			auto src_u_d = 0.5 * src_du_d;

			for (int w = 0; w < texture_2d.actual_width_; ++w)
			{
				const auto src_u = static_cast<int>(src_u_d);

				const auto src_index = (src_v * texture_2d.width_) + src_u;

				const auto dst_index =
					((texture_2d.actual_height_ - 1 - h) * texture_2d.actual_width_) + w;

				texture_buffer_[dst_index] = palette_[texture_2d.indexed_pixels_[src_index]];

				const auto is_transparent =
					(!has_alpha || (has_alpha && !texture_2d.indexed_alphas_[src_index]));

				if (is_transparent)
				{
					texture_buffer_[dst_index].a_ = 0x00;
				}

				src_u_d += src_du_d;
			}

			src_v_d += src_dv_d;
		}
	}

	::glTexSubImage2D(
		GL_TEXTURE_2D, // target
		0, // level
		0, // xoffset
		0, // yoffset
		texture_2d.actual_width_, // width
		texture_2d.actual_height_, // height
		GL_RGBA, // format
		GL_UNSIGNED_BYTE, // type
		texture_buffer_.data() // pixels
	);

	assert(!OglRendererUtils::was_errors());
}

void Ogl1XRenderer::update_indexed_textures()
{
	for (const auto& texture_2d : textures_2d_)
	{
		update_indexed_texture(0, texture_2d);
	}
}

int Ogl1XRenderer::fetch_index(
	const IndexBuffer& index_buffer,
	const int offset)
{
	const auto data_offset = index_buffer.byte_depth_ * offset;
	const auto data = &index_buffer.data_[data_offset];

	unsigned int result;

	switch (index_buffer.byte_depth_)
	{
	case 1:
		result = *reinterpret_cast<const std::uint8_t*>(data);
		break;

	case 2:
		result = *reinterpret_cast<const std::uint16_t*>(data);
		break;

	case 4:
		result = *reinterpret_cast<const std::int32_t*>(data);
		break;

	default:
		result = 0;
		break;
	}

	return result;
}

void Ogl1XRenderer::execute_command_set_2d()
{
	// Enable 2D texturing.
	//
	::glEnable(GL_TEXTURE_2D);
	assert(!OglRendererUtils::was_errors());

	// Disable depth test.
	//
	::glDisable(GL_DEPTH_TEST);
	assert(!OglRendererUtils::was_errors());

	// Model-view.
	//
	::glMatrixMode(GL_MODELVIEW);
	assert(!OglRendererUtils::was_errors());

	::glLoadIdentity();
	assert(!OglRendererUtils::was_errors());

	// Projection.
	//
	::glMatrixMode(GL_PROJECTION);
	assert(!OglRendererUtils::was_errors());

	::glLoadMatrixf(two_d_projection_matrix_.get_data());
	assert(!OglRendererUtils::was_errors());
}

void Ogl1XRenderer::execute_command_update_palette(
	const RendererCommand::UpdatePalette& command)
{
	assert(command.offset_ >= 0);
	assert(command.offset_ < 256);
	assert(command.count_ >= 0);
	assert(command.count_ <= 256);
	assert((command.offset_ + command.count_) <= 256);
	assert(command.colors_ != nullptr);

	const auto is_modified = !std::equal(
		palette_.begin() + command.offset_,
		palette_.begin() + command.offset_ + command.count_,
		command.colors_
	);

	if (!is_modified)
	{
		return;
	}

	std::uninitialized_copy_n(
		command.colors_,
		command.count_,
		palette_.begin() + command.offset_
	);

	update_indexed_textures();
}

void Ogl1XRenderer::execute_command_draw_quads(
	const RendererCommand::DrawQuads& command)
{
	assert(command.count_ > 0);
	assert(command.index_offset_ >= 0);
	assert(command.texture_2d_handle_);
	assert(command.index_buffer_);
	assert(command.vertex_buffer_handle_);

	const auto triangles_per_quad = 2;
	const auto triangle_count = command.count_ * triangles_per_quad;

	const auto indices_per_triangle = 3;
	const auto indices_per_quad = triangles_per_quad * indices_per_triangle;
	const auto index_count = indices_per_quad * command.count_;

	auto& texture_2d = *reinterpret_cast<Texture2d*>(command.texture_2d_handle_);
	auto& index_buffer = *reinterpret_cast<IndexBuffer*>(command.index_buffer_);
	auto& vertex_buffer = *reinterpret_cast<VertexBuffer*>(command.vertex_buffer_handle_);

	assert(command.index_offset_ < index_buffer.count_);
	assert(command.count_ <= index_buffer.count_);
	assert((command.index_offset_ + command.count_) <= index_buffer.count_);

	const auto stride = static_cast<GLsizei>(sizeof(RendererVertex));
	const auto vertex_buffer_data = reinterpret_cast<const std::uint8_t*>(vertex_buffer.data());

	::glBindTexture(GL_TEXTURE_2D, texture_2d.ogl_id_);
	assert(!OglRendererUtils::was_errors());

	// Diffuse.
	//
	::glEnableClientState(GL_COLOR_ARRAY);
	assert(!OglRendererUtils::was_errors());

	::glColorPointer(
		4, // size
		GL_UNSIGNED_BYTE, // type
		stride, // stride
		vertex_buffer_data + offsetof(RendererVertex, rgba_) // pointer
	);

	assert(!OglRendererUtils::was_errors());

	// Texture coordinates.
	//
	::glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	assert(!OglRendererUtils::was_errors());

	::glTexCoordPointer(
		2, // size
		GL_FLOAT, // type
		stride, // stride
		vertex_buffer_data + offsetof(RendererVertex, uv_) // pointer
	);

	assert(!OglRendererUtils::was_errors());

	// Position.
	//
	::glEnableClientState(GL_VERTEX_ARRAY);
	assert(!OglRendererUtils::was_errors());

	::glVertexPointer(
		3, // size
		GL_FLOAT, // type
		stride, // stride
		vertex_buffer_data + offsetof(RendererVertex, xyz_) // pointer
	);

	assert(!OglRendererUtils::was_errors());

	// Draw the quads.
	//

	const auto index_buffer_data =
		index_buffer.data_.data() +
		(index_buffer.byte_depth_ * command.index_offset_);

	::glDrawElements(
		GL_TRIANGLES, // mode
		index_count, // count
		index_buffer.data_type_, // type
		index_buffer_data // indices
	);

	assert(!OglRendererUtils::was_errors());

	// Disable the state.
	//
	::glBindTexture(GL_TEXTURE_2D, 0);
	assert(!OglRendererUtils::was_errors());

	::glDisableClientState(GL_VERTEX_ARRAY);
	assert(!OglRendererUtils::was_errors());

	::glDisableClientState(GL_COLOR_ARRAY);
	assert(!OglRendererUtils::was_errors());

	::glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	assert(!OglRendererUtils::was_errors());
}

//
// Ogl1XRenderer
// ==========================================================================


} // bstone