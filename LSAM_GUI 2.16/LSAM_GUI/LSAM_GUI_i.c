

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Sun Nov 21 21:39:22 2021
 */
/* Compiler settings for LSAM_GUI.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_LSAM_GUI,0xB7EE2888,0xDB4D,0x4665,0xBF,0xE1,0x21,0x4E,0x53,0x69,0x05,0x6B);


MIDL_DEFINE_GUID(IID, DIID_ILSAM_GUI,0xD0E2FB43,0x5655,0x4F30,0x9D,0x35,0x43,0xB8,0x23,0x0E,0x9D,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_LSAM_GUI,0x873568C0,0x64A6,0x4379,0x87,0x69,0x3E,0x69,0xCE,0xEE,0xAF,0xF9);


MIDL_DEFINE_GUID(IID, DIID_ILSAM_Config,0xA66129B0,0x442B,0x4E4D,0xB9,0x74,0x0D,0x81,0xFE,0x96,0x8A,0x3E);


MIDL_DEFINE_GUID(CLSID, CLSID_LSAM_Config,0x6D59744A,0x1DCA,0x4BB4,0x9A,0x98,0xF9,0x11,0xAF,0x33,0x09,0x22);


MIDL_DEFINE_GUID(IID, DIID_ILSAM_ParamSet,0x9BE3EAEB,0x69CB,0x4002,0x8C,0xED,0xEC,0xC8,0x08,0xC8,0xCF,0xDC);


MIDL_DEFINE_GUID(CLSID, CLSID_LSAM_ParamSet,0xB1A9513E,0x15A4,0x41C2,0xBE,0xA0,0x40,0x0A,0x4A,0x18,0x16,0x04);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



