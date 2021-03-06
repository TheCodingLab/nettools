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

#define MAX_NAME_LENGTH 32

namespace nettools
{
    struct network_interface
    {
        char m_name[MAX_NAME_LENGTH];
        hardware_address m_mac_address;
        inet_address m_unicast_addr;
        inet_address m_subnet_addr;
        inet_address m_network_addr;
        inet_address m_broadcast_addr;
    };

    struct network_interface_list;

    typedef network_interface *network_interface_t;
    typedef network_interface_list *network_interface_list_t;

    NETTOOLS_EXPORT network_interface_list_t interface_query_list();
    NETTOOLS_EXPORT network_interface_t interface_query_next(network_interface_list_t);
    NETTOOLS_EXPORT void interface_query_close(network_interface_list_t);

    NETTOOLS_EXPORT network_interface interface_query();
}