/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "rooOpenUDID.h"

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*rooOpenUDID_init_t)();
typedef       bool(*rooOpenUDID_isInitialized_t)();
typedef const char *(*rooOpenUDID_getValue_t)();

/**
 * struct that gets filled in by rooOpenUDIDRegister
 */
typedef struct rooOpenUDIDFuncs
{
    rooOpenUDID_init_t m_rooOpenUDID_init;
    rooOpenUDID_isInitialized_t m_rooOpenUDID_isInitialized;
    rooOpenUDID_getValue_t m_rooOpenUDID_getValue;
} rooOpenUDIDFuncs;

static rooOpenUDIDFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xa2e3bc2d, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: rooOpenUDID");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xa2e3bc2d, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool rooOpenUDIDAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void rooOpenUDID_init()
{
    IwTrace(ROOOPENUDID_VERBOSE, ("calling rooOpenUDID[0] func: rooOpenUDID_init"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_rooOpenUDID_init();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

bool rooOpenUDID_isInitialized()
{
    IwTrace(ROOOPENUDID_VERBOSE, ("calling rooOpenUDID[1] func: rooOpenUDID_isInitialized"));

    if (!_extLoad())
        return false;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_rooOpenUDID_isInitialized();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

const char * rooOpenUDID_getValue()
{
    IwTrace(ROOOPENUDID_VERBOSE, ("calling rooOpenUDID[2] func: rooOpenUDID_getValue"));

    if (!_extLoad())
        return NULL;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    const char * ret = g_Ext.m_rooOpenUDID_getValue();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}
