/*
BStone: A Source port of
Blake Stone: Aliens of Gold and Blake Stone: Planet Strike

Copyright (c) 1992-2013 Apogee Entertainment, LLC
Copyright (c) 2013-2020 Boris I. Bendovsky (bibendovsky@hotmail.com)

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
// Missing data in original source code release.
//


#include <cstdint>


// Force compiler to emit a symbol.
extern const std::uint8_t vgapal[768];


const std::uint8_t vgapal[768] =
{
	0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x05, 0x05, 0x05, 0x07, 0x07, 0x07, 0x09,
	0x09, 0x09, 0x0B, 0x0B, 0x0B, 0x0D, 0x0D, 0x0D, 0x0F, 0x0F, 0x0F, 0x11, 0x11, 0x11, 0x13, 0x13,
	0x13, 0x15, 0x15, 0x15, 0x17, 0x17, 0x17, 0x19, 0x19, 0x19, 0x1B, 0x1B, 0x1B, 0x1D, 0x1D, 0x1D,
	0x08, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x12, 0x00, 0x00, 0x17, 0x00, 0x00, 0x1C, 0x01, 0x01, 0x21,
	0x01, 0x01, 0x26, 0x02, 0x02, 0x2B, 0x03, 0x03, 0x30, 0x04, 0x04, 0x31, 0x09, 0x09, 0x33, 0x0E,
	0x0E, 0x34, 0x14, 0x14, 0x36, 0x19, 0x19, 0x37, 0x1F, 0x1F, 0x39, 0x26, 0x26, 0x3B, 0x2D, 0x2D,
	0x0B, 0x05, 0x00, 0x0F, 0x07, 0x00, 0x14, 0x09, 0x00, 0x19, 0x0C, 0x00, 0x1D, 0x0E, 0x01, 0x22,
	0x11, 0x01, 0x26, 0x13, 0x02, 0x2B, 0x16, 0x03, 0x30, 0x19, 0x04, 0x31, 0x1C, 0x09, 0x33, 0x20,
	0x0E, 0x34, 0x24, 0x14, 0x36, 0x27, 0x19, 0x37, 0x2B, 0x1F, 0x39, 0x30, 0x26, 0x3B, 0x34, 0x2D,
	0x0B, 0x0B, 0x00, 0x0F, 0x0F, 0x00, 0x14, 0x14, 0x00, 0x19, 0x19, 0x00, 0x1D, 0x1E, 0x01, 0x21,
	0x22, 0x02, 0x25, 0x26, 0x03, 0x29, 0x2A, 0x05, 0x2D, 0x2E, 0x07, 0x31, 0x32, 0x09, 0x33, 0x33,
	0x0E, 0x34, 0x35, 0x14, 0x36, 0x36, 0x1A, 0x38, 0x38, 0x20, 0x39, 0x39, 0x27, 0x3B, 0x3B, 0x2E,
	0x03, 0x05, 0x00, 0x08, 0x0B, 0x00, 0x0D, 0x11, 0x00, 0x11, 0x17, 0x00, 0x16, 0x1D, 0x00, 0x1B,
	0x23, 0x00, 0x1F, 0x29, 0x00, 0x24, 0x2F, 0x00, 0x26, 0x30, 0x04, 0x29, 0x32, 0x0A, 0x2C, 0x34,
	0x10, 0x2F, 0x36, 0x17, 0x32, 0x38, 0x1E, 0x35, 0x39, 0x26, 0x38, 0x3B, 0x2D, 0x3B, 0x3D, 0x36,
	0x00, 0x05, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x11, 0x00, 0x00, 0x17, 0x00, 0x00, 0x1D, 0x00, 0x00,
	0x23, 0x00, 0x00, 0x29, 0x00, 0x00, 0x30, 0x00, 0x04, 0x31, 0x04, 0x0A, 0x33, 0x0A, 0x11, 0x35,
	0x11, 0x17, 0x36, 0x17, 0x1E, 0x38, 0x1E, 0x26, 0x3A, 0x26, 0x2E, 0x3B, 0x2E, 0x36, 0x3D, 0x36,
	0x00, 0x05, 0x03, 0x00, 0x0B, 0x07, 0x00, 0x11, 0x0A, 0x00, 0x17, 0x0E, 0x00, 0x1D, 0x12, 0x01,
	0x23, 0x16, 0x01, 0x29, 0x1A, 0x01, 0x2F, 0x1E, 0x06, 0x30, 0x21, 0x0C, 0x32, 0x24, 0x12, 0x34,
	0x27, 0x18, 0x36, 0x2B, 0x1F, 0x38, 0x2F, 0x27, 0x39, 0x32, 0x2E, 0x3B, 0x36, 0x36, 0x3D, 0x3A,
	0x00, 0x05, 0x05, 0x00, 0x0B, 0x0B, 0x00, 0x11, 0x11, 0x00, 0x17, 0x17, 0x00, 0x1D, 0x1D, 0x00,
	0x23, 0x23, 0x00, 0x29, 0x29, 0x00, 0x2F, 0x2F, 0x04, 0x30, 0x30, 0x0A, 0x32, 0x32, 0x10, 0x34,
	0x34, 0x17, 0x36, 0x36, 0x1E, 0x38, 0x38, 0x26, 0x39, 0x39, 0x2D, 0x3B, 0x3B, 0x36, 0x3D, 0x3D,
	0x00, 0x05, 0x0B, 0x00, 0x07, 0x0F, 0x00, 0x0A, 0x14, 0x00, 0x0C, 0x19, 0x01, 0x0F, 0x1D, 0x01,
	0x11, 0x22, 0x02, 0x14, 0x26, 0x03, 0x17, 0x2B, 0x04, 0x1A, 0x30, 0x09, 0x1D, 0x31, 0x0E, 0x21,
	0x33, 0x14, 0x24, 0x34, 0x19, 0x28, 0x36, 0x1F, 0x2B, 0x37, 0x26, 0x30, 0x39, 0x2D, 0x34, 0x3B,
	0x00, 0x00, 0x0B, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x14, 0x00, 0x00, 0x19, 0x01, 0x01, 0x1D, 0x01,
	0x01, 0x22, 0x02, 0x02, 0x26, 0x03, 0x03, 0x2B, 0x04, 0x04, 0x30, 0x0A, 0x0A, 0x32, 0x10, 0x10,
	0x34, 0x17, 0x17, 0x36, 0x1E, 0x1E, 0x38, 0x26, 0x26, 0x39, 0x2D, 0x2D, 0x3B, 0x36, 0x36, 0x3D,
	0x1D, 0x1D, 0x1D, 0x1F, 0x1F, 0x1F, 0x21, 0x21, 0x21, 0x23, 0x23, 0x23, 0x26, 0x26, 0x26, 0x28,
	0x28, 0x28, 0x2A, 0x2A, 0x2A, 0x2C, 0x2C, 0x2C, 0x2F, 0x2F, 0x2F, 0x31, 0x31, 0x31, 0x33, 0x33,
	0x33, 0x36, 0x36, 0x36, 0x38, 0x38, 0x38, 0x3A, 0x3A, 0x3A, 0x3C, 0x3C, 0x3C, 0x3F, 0x3F, 0x3F,
	0x0F, 0x06, 0x00, 0x10, 0x07, 0x00, 0x12, 0x08, 0x01, 0x14, 0x0A, 0x01, 0x15, 0x0B, 0x02, 0x17,
	0x0D, 0x03, 0x18, 0x0E, 0x05, 0x1A, 0x10, 0x06, 0x1C, 0x12, 0x08, 0x32, 0x33, 0x0A, 0x32, 0x2C,
	0x09, 0x32, 0x24, 0x08, 0x31, 0x1C, 0x07, 0x31, 0x14, 0x06, 0x30, 0x0C, 0x05, 0x30, 0x04, 0x04,
	0x0B, 0x00, 0x05, 0x0F, 0x00, 0x07, 0x14, 0x00, 0x09, 0x19, 0x00, 0x0C, 0x1D, 0x01, 0x0E, 0x22,
	0x01, 0x11, 0x26, 0x02, 0x13, 0x2B, 0x03, 0x16, 0x30, 0x04, 0x19, 0x31, 0x09, 0x1C, 0x33, 0x0E,
	0x20, 0x34, 0x14, 0x24, 0x36, 0x19, 0x27, 0x37, 0x1F, 0x2B, 0x39, 0x26, 0x30, 0x3B, 0x2D, 0x34,
	0x08, 0x05, 0x02, 0x0C, 0x07, 0x03, 0x10, 0x0A, 0x04, 0x14, 0x0D, 0x06, 0x18, 0x10, 0x07, 0x1C,
	0x12, 0x08, 0x20, 0x15, 0x09, 0x25, 0x18, 0x0B, 0x28, 0x1B, 0x0F, 0x2A, 0x1E, 0x13, 0x2C, 0x21,
	0x16, 0x2F, 0x24, 0x1B, 0x31, 0x28, 0x20, 0x34, 0x2C, 0x25, 0x36, 0x2F, 0x2A, 0x39, 0x34, 0x30,
	0x02, 0x05, 0x08, 0x03, 0x07, 0x0C, 0x05, 0x0A, 0x10, 0x06, 0x0D, 0x14, 0x08, 0x10, 0x18, 0x09,
	0x12, 0x1C, 0x0B, 0x15, 0x20, 0x0D, 0x18, 0x24, 0x0F, 0x1B, 0x28, 0x13, 0x1E, 0x2A, 0x16, 0x21,
	0x2C, 0x1B, 0x24, 0x2F, 0x20, 0x28, 0x31, 0x25, 0x2C, 0x34, 0x2A, 0x2F, 0x36, 0x30, 0x34, 0x39,
	0x07, 0x07, 0x08, 0x3E, 0x3E, 0x3F, 0x18, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00,
	0x3E, 0x00, 0x07, 0x08, 0x07, 0x1D, 0x1E, 0x1D, 0x3E, 0x3F, 0x3E, 0x1D, 0x1E, 0x1D, 0x0A, 0x0A,
	0x33, 0x1E, 0x1E, 0x39, 0x36, 0x39, 0x3E, 0x1E, 0x1E, 0x39, 0x0A, 0x0A, 0x33, 0x26, 0x00, 0x22,
}; // vgapal
