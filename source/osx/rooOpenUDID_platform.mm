/*
 * osx-specific implementation of the rooOpenUDID extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "rooOpenUDID_internal.h"
#include <time.h>
#include <stdio.h>

char g_rooOpenUDID_str[128] = {0}; 
s3eResult rooOpenUDIDInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void rooOpenUDIDTerminate_platform()
{
    // Add any platform-specific termination code here
}

void rooOpenUDID_init_platform()
{
}

bool rooOpenUDID_isInitialized_platform()
{
    return false;
}

const char * rooOpenUDID_getValue_platform()
{
    time_t t;
    time( &t );
    snprintf( &g_rooOpenUDID_str[0], 128, "%d", (int)t );
    return g_rooOpenUDID_str;
}
