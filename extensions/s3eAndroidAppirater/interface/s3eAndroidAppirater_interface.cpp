/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"

#include "s3eAndroidAppirater.h"

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef  s3eResult(*AppiraterInit_t)(const char* cTitle, const char* cMsg, int iDays, int iLaunches);

/**
 * struct that gets filled in by s3eAndroidAppiraterRegister
 */
typedef struct s3eAndroidAppiraterFuncs
{
    AppiraterInit_t m_AppiraterInit;
} s3eAndroidAppiraterFuncs;

static s3eAndroidAppiraterFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xf598d199, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE, "error loading extension: s3eAndroidAppirater");
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xf598d199, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eAndroidAppiraterAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

s3eResult AppiraterInit(const char* cTitle, const char* cMsg, int iDays, int iLaunches)
{
    IwTrace(ANDROIDAPPIRATER_VERBOSE, ("calling s3eAndroidAppirater[0] func: AppiraterInit"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

    return g_Ext.m_AppiraterInit(cTitle, cMsg, iDays, iLaunches);
}