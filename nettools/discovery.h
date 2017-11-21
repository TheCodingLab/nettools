/*
* nettols is a library for comonly used network stuff for windows and linux
* Copyright (C) 2017  TheCodingLab
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include "defines.h"
#include "socket.h"

namespace nettools
{
    typedef bool(*callback_discovery_request)(const socket_address_ptr);
    typedef void(*callback_discovery_found)(const socket_address_ptr);
    typedef void(*callback_discovery_ping_result)(const socket_address_ptr, u32, bool);

    NETTOOLS_EXPORT void discovery_init(u16);
    NETTOOLS_EXPORT void discovery_set_handlers(callback_discovery_request, callback_discovery_found, callback_discovery_ping_result);
    NETTOOLS_EXPORT void discovery_search(u16, bool = true);
    NETTOOLS_EXPORT void discovery_update();
    NETTOOLS_EXPORT void discovery_ping(const socket_address_ptr);
    NETTOOLS_EXPORT void discovery_close();
}