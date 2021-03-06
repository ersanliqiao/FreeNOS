/*
 * Copyright (C) 2015 Niek Linnenbank
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

#ifndef __KERNEL_API_H
#define __KERNEL_API_H

#include <Log.h>
#include <System/Function.h>
#include <Types.h>

/**
 * @defgroup kernel kernel (generic)
 * @{
 */

/**
 * Enumeration of supported generic kernel API functions.
 *
 * Architectures or System implementations can optionally
 * introduce additional specific APIs.
 */
typedef enum APINumber
{
    IPCMessageNumber = 1,
    PrivExecNumber   = 2,
    ProcessCtlNumber = 3,
    SystemInfoNumber = 4,        
    VMCopyNumber     = 5,
    VMCtlNumber      = 6,
    IOCtlNumber      = 7
}
APINumber;

/**
 * Function which handles an kernel API (system call) request.
 * @return Status code of the APIHandler execution.
 */
typedef Error APIHandler(ulong, ulong, ulong, ulong, ulong);

/**
 * Various actions which may be performed inside an APIHandler.
 */
typedef enum Operation
{
    Create      = 0,
    Delete      = 1,
    Send        = 2,
    Receive     = 3,
    SendReceive = 4,
    Read        = 5,
    Write       = 6,
}
Operation;

/** Operator to print a Operation to a Log */
Log & operator << (Log &log, Operation op);

/*
 * Include generic kernel API functions.
 */

#include "API/IPCMessage.h"
#include "API/PrivExec.h"
#include "API/ProcessCtl.h"
#include "API/SystemInfo.h"
#include "API/VMCopy.h"
#include "API/VMCtl.h"
#include "API/IOCtl.h"

/**
 * @}
 */

#endif /* __KERNEL_API_H */
