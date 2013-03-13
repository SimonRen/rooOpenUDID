/*
 * osx-specific implementation of the rooOpenUDID extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "rooOpenUDID_internal.h"

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
    return NULL;
}
