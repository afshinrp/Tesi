/*
    FreeRTOS.org V4.7.2 - Copyright (C) 2003-2008 Richard Barry.

    This file is part of the FreeRTOS.org distribution.

    FreeRTOS.org is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FreeRTOS.org is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FreeRTOS.org; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes FreeRTOS.org, without being obliged to provide
    the source code for any proprietary components.  See the licensing section
    of http://www.FreeRTOS.org for full details of how and when the exception
    can be applied.

    ***************************************************************************

    Please ensure to read the configuration and relevant port sections of the
    online documentation.

    +++ http://www.FreeRTOS.org +++
    Documentation, latest information, license and contact details.

    +++ http://www.SafeRTOS.com +++
    A version that is certified for use in safety critical systems.

    +++ http://www.OpenRTOS.com +++
    Commercial support, development, porting, licensing and training services.

    ***************************************************************************
*/
#ifndef BASIC_WEB_SERVER_H
#define BASIC_WEB_SERVER_H

/// The function that implements the WEB server task. 
T_uezError BasicWebStart(T_uezDevice aNetwork);

#endif
