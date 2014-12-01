/** @file
    @brief Header

    @date 2014

    @author
    Ryan Pavlik
    <ryan@sensics.com>
    <http://sensics.com>
*/

// Copyright 2014 Sensics, Inc.
//
// All rights reserved.
//
// (Final version intended to be licensed under
// the Apache License, Version 2.0)

#ifndef INCLUDED_DevicesWithParameters_h_GUID_45F0E8B4_E094_4AAF_7D19_0EF3AFB7A11C
#define INCLUDED_DevicesWithParameters_h_GUID_45F0E8B4_E094_4AAF_7D19_0EF3AFB7A11C

// Internal Includes
#include "VRPNMultiserver.h"

// Library/third-party includes
#include <osvr/Util/PluginCallbackTypesC.h>

// Standard includes
// - none
typedef void (*DriverConstructor)(BoundServer &server, const char *params);

template <DriverConstructor F>
OSVR_ReturnCode wrappedConstructor(OSVR_PluginRegContext ctx,
                                   const char *params, void *userData) {
    VRPNMultiserverData *data = static_cast<VRPNMultiserverData *>(userData);
    BoundServer server(*data, ctx);
    try {
        F(server, params);
        return OSVR_RETURN_SUCCESS;
    } catch (...) {
        return OSVR_RETURN_FAILURE;
    }
}

void createYEI(BoundServer &server, const char *params);

#endif // INCLUDED_DevicesWithParameters_h_GUID_45F0E8B4_E094_4AAF_7D19_0EF3AFB7A11C