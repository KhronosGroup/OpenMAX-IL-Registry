/*
 * Copyright (c) 2011 The Khronos Group Inc. 
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions: 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software. 
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
 *
*/

#ifndef CPA_ContentPipe_h
#define CPA_ContentPipe_h

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus
  /** CPA_IN is used to identify inputs to an CP function.  This designation
    will also be used in the case of a pointer that points
    to a parameter that is used as an input. */
#ifndef CPA_IN
#define CPA_IN
#endif

/** CPA_OUT is used to identify outputs from an CP function.  This designation
    will also be used in the case of a pointer that points to a parameter
    that is used as an output. */
#ifndef CPA_OUT
#define CPA_OUT
#endif


/** CPA_INOUT is used to identify parameters that may be either inputs or
    outputs from an CP function at the same time.  This designation will
    also be used in the case of a pointer that  points to a parameter that
    is used both as an input and an output. */
#ifndef CPA_INOUT
#define CPA_INOUT
#endif

typedef enum CPA_BOOL {
    CPA_FALSE = 0,
    CPA_TRUE = !CPA_FALSE,
    CPA_BOOL_MAX = 0x7FFFFFFF
} CPA_BOOL;

typedef void* CPA_PTR;

typedef char* CPA_STRING;

typedef unsigned char CPA_BYTE;

typedef void* CPA_INTERFACE;

typedef void* CPA_HANDLE;

typedef unsigned char CPA_U8;

typedef signed char CPA_S8;

typedef unsigned short CPA_U16;

typedef signed short CPA_S16;

typedef unsigned long CPA_U32;

typedef signed long CPA_S32;

/* Users with compilers that cannot accept 64 bits arithmetic shall not
   define the CPA_64BITSSUPPORTED macro.  It should be noted that this may cause
   some components to fail to compile if the component was written to require
   64 bit integral types.  However, these components would NOT compile anyway
   since the compiler does not support the way the component was written.
*/
#ifdef CPA_64BITSSUPPORTED

typedef uint64_t  CPA_U64;

typedef int64_t  CPA_S64;

#else /* unknown*/

typedef unsigned long long CPA_U64;

typedef signed long long CPA_S64;

#endif /* CPA_64BITSSUPPORTED */

typedef enum CPA_RESULTTYPE{
    CPA_OK,
    CPA_OKEOS,
    CPA_OKPOSITIONEXCEED2GB,
    CPA_EPOSNOTAVAIL,
    CPA_EUNKNOWN,
    CPA_EACCESS,
    CPA_EAGAIN,
    CPA_EALREADY,
    CPA_EBUSY,
    CPA_ECONNREFUSED,
    CPA_ECONNRESET,
    CPA_EEXIST,
    CPA_EFBIG,
    CPA_EINVAL,
    CPA_EIO,
    CPA_ENOENT,
    CPA_EURINOTSUPP,
    CPA_ENOMEM,
    CPA_ENOSPC,
    CPA_ENO_RECOVERY,
    CPA_EOPNOTSUPP,
    CPA_ETIMEDOUT,
    CPA_EVERSION,
    CPA_RESULTKhronosExtensions = 0x6F000000, /* Reserved region for introducing Khronos Standard Extensions */
    CPA_RESULTVendorStartUnused = 0x7F000000, /* Reserved region for introducing Vendor Extensions */
    CPA_RESULTMax = 0x7FFFFFFF
} CPA_RESULTTYPE;

#define CPA_POSITION_NA -1

#ifdef CPA_64BITSSUPPORTED
#define CPA_POSITION_32_MAX 0x000000007FFFFFFF
typedef CPA_S64 CPA_POSITIONTYPE;
#else
#define CPA_POSITION_32_MAX 0x7FFFFFFF
typedef CPA_S32 CPA_POSITIONTYPE;
#endif

typedef union CPA_VERSIONTYPE
{
    struct
    {
        CPA_U8 nVersionMajor;
        CPA_U8 nVersionMinor;
        CPA_U8 nRevision;
    };
    CPA_U32 nVersionID;
} CPA_VERSIONTYPE;

typedef enum CPA_ORIGINTYPE {
    CPA_OriginBegin,
    CPA_OriginFirst,
    CPA_OriginCur,
    CPA_OriginLast,
    CPA_OriginEnd,
    CPA_OriginKhronosExtensions = 0x6F000000, /* Reserved region for introducing Khronos Standard Extensions */
    CPA_OriginVendorStartUnused = 0x7F000000, /* Reserved region for introducing Vendor Extensions */
    CPA_OriginMax = 0X7FFFFFFF
} CPA_ORIGINTYPE;

typedef struct CPA_POSITIONINFOTYPE {
    CPA_POSITIONTYPE nDataBegin;
    CPA_POSITIONTYPE nDataFirst;
    CPA_POSITIONTYPE nDataCur;
    CPA_POSITIONTYPE nDataLast;
    CPA_POSITIONTYPE nDataEnd;
} CPA_POSITIONINFOTYPE;

typedef enum CPA_ACCESSTYPE {
    CPA_AccessRead,
    CPA_AccessWrite,
    CPA_AccessReadWrite ,
    CPA_AccessKhronosExtensions = 0x6F000000, /* Reserved region for introducing Khronos Standard Extensions */
    CPA_AccessVendorStartUnused = 0x7F000000, /* Reserved region for introducing Vendor Extensions */
    CPA_AccessMax = 0X7FFFFFFF
} CPA_ACCESSTYPE;

typedef enum CPA_CHECKBYTESRESULTTYPE
{
    CPA_CheckBytesOk,
    CPA_CheckBytesNotReady,
    CPA_CheckBytesInsufficientBytes,
    CPA_CheckBytesTooLargeRequest,
    CPA_CheckBytesKhronosExtensions = 0x6F000000, /* Reserved region for introducing Khronos Standard Extensions */
    CPA_CheckBytesVendorStartUnused = 0x7F000000, /* Reserved region for introducing Vendor Extensions */
    CPA_CheckBytesMax = 0X7FFFFFFF
} CPA_CHECKBYTESRESULTTYPE;

typedef enum CPA_EVENTTYPE{
    CPA_EventBytesToReadAvailable,
    CPA_EventBytesToWriteAvailable,
    CPA_EventPipeDisconnected,
    CPA_EventEndOfStream,
    CPA_EventKhronosExtensions = 0x6F000000, /* Reserved region for introducing Khronos Standard Extensions. */
    CPA_EventVendorStartUnused = 0x7F000000, /* Reserved region for introducing Vendor Extensions. */
    CPA_EventMax = 0X7FFFFFFF
} CPA_EVENTTYPE;

typedef CPA_RESULTTYPE (*CPA_CALLBACKTYPE)(CPA_HANDLE hPipe, CPA_EVENTTYPE eEvent, CPA_PTR ClientContext);

CPA_RESULTTYPE CPA_GetContentPipe( CPA_OUT CPA_HANDLE *hPipe);

typedef struct CPA_PIPETYPE
{
    CPA_VERSIONTYPE nApiVersion;

    CPA_RESULTTYPE (*CPA_ReleaseContentPipeType)( CPA_INOUT CPA_HANDLE *hPipe);

    CPA_RESULTTYPE (*CPA_SetConfig)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_HANDLE hContent,CPA_IN CPA_STRING szKey, CPA_IN CPA_PTR value);

    CPA_RESULTTYPE (*CPA_GetConfig)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_HANDLE hContent,CPA_IN CPA_STRING szKey, CPA_OUT CPA_PTR value);

    CPA_RESULTTYPE (*CPA_Open)( CPA_IN CPA_HANDLE hPipe, CPA_OUT CPA_HANDLE *hContent, CPA_IN CPA_STRING szURI, CPA_IN CPA_ACCESSTYPE eAccess );

    CPA_RESULTTYPE (*CPA_Create)( CPA_IN CPA_HANDLE hPipe, CPA_OUT CPA_HANDLE *hContent, CPA_IN CPA_STRING szURI );

    CPA_RESULTTYPE (*CPA_Close)( CPA_IN CPA_HANDLE hPipe, CPA_INOUT CPA_HANDLE *hContent );

    CPA_RESULTTYPE (*CPA_CheckAvailableBytesToRead)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_HANDLE hContent, CPA_IN CPA_U32 nBytesRequested, CPA_OUT CPA_CHECKBYTESRESULTTYPE* peResult );

    CPA_RESULTTYPE (*CPA_CheckAvailableBytesToWrite)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_HANDLE hContent, CPA_IN CPA_U32 nBytesRequested, CPA_OUT CPA_CHECKBYTESRESULTTYPE* peResult );

    CPA_RESULTTYPE (*CPA_SetPosition)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_HANDLE hContent, CPA_IN CPA_POSITIONTYPE nOffset, CPA_IN CPA_ORIGINTYPE eOrigin );

    CPA_RESULTTYPE (*CPA_GetPositions)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_HANDLE hContent, CPA_OUT CPA_POSITIONINFOTYPE* pPosition );

    CPA_RESULTTYPE (*CPA_GetCurrentPosition)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_HANDLE hContent, CPA_OUT CPA_POSITIONINFOTYPE* pPosition );

    CPA_RESULTTYPE (*CPA_Read)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_HANDLE hContent, CPA_OUT CPA_BYTE* pData, CPA_INOUT CPA_U32* pSize );

    CPA_RESULTTYPE (*CPA_ReadBuffer)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_HANDLE hContent, CPA_OUT CPA_BYTE** ppBuffer, CPA_INOUT CPA_U32* pSize, CPA_IN CPA_BOOL bForbidCopy );

    CPA_RESULTTYPE (*CPA_ReleaseReadBuffer)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_HANDLE hContent, CPA_IN CPA_BYTE* pBuffer );

    CPA_RESULTTYPE (*CPA_Write)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_HANDLE hContent, CPA_IN CPA_BYTE *pData, CPA_INOUT CPA_U32* pSize );

    CPA_RESULTTYPE (*CPA_RegisterCallback)( CPA_IN CPA_HANDLE hPipe, CPA_IN CPA_CALLBACKTYPE ClientCallback, CPA_IN CPA_PTR ClientContext );

} CPA_PIPETYPE;

#define CP_GetApiVersion( hPipe ) \
    ((CP_PIPETYPE*)hPipe)->nApiVersion

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CPA_ContentPipe_h */
