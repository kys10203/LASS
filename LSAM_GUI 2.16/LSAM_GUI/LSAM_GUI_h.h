

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __LSAM_GUI_h_h__
#define __LSAM_GUI_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILSAM_GUI_FWD_DEFINED__
#define __ILSAM_GUI_FWD_DEFINED__
typedef interface ILSAM_GUI ILSAM_GUI;

#endif 	/* __ILSAM_GUI_FWD_DEFINED__ */


#ifndef __LSAM_GUI_FWD_DEFINED__
#define __LSAM_GUI_FWD_DEFINED__

#ifdef __cplusplus
typedef class LSAM_GUI LSAM_GUI;
#else
typedef struct LSAM_GUI LSAM_GUI;
#endif /* __cplusplus */

#endif 	/* __LSAM_GUI_FWD_DEFINED__ */


#ifndef __ILSAM_Config_FWD_DEFINED__
#define __ILSAM_Config_FWD_DEFINED__
typedef interface ILSAM_Config ILSAM_Config;

#endif 	/* __ILSAM_Config_FWD_DEFINED__ */


#ifndef __LSAM_Config_FWD_DEFINED__
#define __LSAM_Config_FWD_DEFINED__

#ifdef __cplusplus
typedef class LSAM_Config LSAM_Config;
#else
typedef struct LSAM_Config LSAM_Config;
#endif /* __cplusplus */

#endif 	/* __LSAM_Config_FWD_DEFINED__ */


#ifndef __ILSAM_ParamSet_FWD_DEFINED__
#define __ILSAM_ParamSet_FWD_DEFINED__
typedef interface ILSAM_ParamSet ILSAM_ParamSet;

#endif 	/* __ILSAM_ParamSet_FWD_DEFINED__ */


#ifndef __LSAM_ParamSet_FWD_DEFINED__
#define __LSAM_ParamSet_FWD_DEFINED__

#ifdef __cplusplus
typedef class LSAM_ParamSet LSAM_ParamSet;
#else
typedef struct LSAM_ParamSet LSAM_ParamSet;
#endif /* __cplusplus */

#endif 	/* __LSAM_ParamSet_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LSAM_GUI_LIBRARY_DEFINED__
#define __LSAM_GUI_LIBRARY_DEFINED__

/* library LSAM_GUI */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_LSAM_GUI;

#ifndef __ILSAM_GUI_DISPINTERFACE_DEFINED__
#define __ILSAM_GUI_DISPINTERFACE_DEFINED__

/* dispinterface ILSAM_GUI */
/* [uuid] */ 


EXTERN_C const IID DIID_ILSAM_GUI;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D0E2FB43-5655-4F30-9D35-43B8230E9D02")
    ILSAM_GUI : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ILSAM_GUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILSAM_GUI * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILSAM_GUI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILSAM_GUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILSAM_GUI * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILSAM_GUI * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILSAM_GUI * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILSAM_GUI * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ILSAM_GUIVtbl;

    interface ILSAM_GUI
    {
        CONST_VTBL struct ILSAM_GUIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILSAM_GUI_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILSAM_GUI_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILSAM_GUI_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILSAM_GUI_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILSAM_GUI_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILSAM_GUI_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILSAM_GUI_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ILSAM_GUI_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LSAM_GUI;

#ifdef __cplusplus

class DECLSPEC_UUID("873568C0-64A6-4379-8769-3E69CEEEAFF9")
LSAM_GUI;
#endif

#ifndef __ILSAM_Config_DISPINTERFACE_DEFINED__
#define __ILSAM_Config_DISPINTERFACE_DEFINED__

/* dispinterface ILSAM_Config */
/* [uuid] */ 


EXTERN_C const IID DIID_ILSAM_Config;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A66129B0-442B-4E4D-B974-0D81FE968A3E")
    ILSAM_Config : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ILSAM_ConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILSAM_Config * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILSAM_Config * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILSAM_Config * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILSAM_Config * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILSAM_Config * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILSAM_Config * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILSAM_Config * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ILSAM_ConfigVtbl;

    interface ILSAM_Config
    {
        CONST_VTBL struct ILSAM_ConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILSAM_Config_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILSAM_Config_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILSAM_Config_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILSAM_Config_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILSAM_Config_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILSAM_Config_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILSAM_Config_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ILSAM_Config_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LSAM_Config;

#ifdef __cplusplus

class DECLSPEC_UUID("6D59744A-1DCA-4BB4-9A98-F911AF330922")
LSAM_Config;
#endif

#ifndef __ILSAM_ParamSet_DISPINTERFACE_DEFINED__
#define __ILSAM_ParamSet_DISPINTERFACE_DEFINED__

/* dispinterface ILSAM_ParamSet */
/* [uuid] */ 


EXTERN_C const IID DIID_ILSAM_ParamSet;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9BE3EAEB-69CB-4002-8CED-ECC808C8CFDC")
    ILSAM_ParamSet : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ILSAM_ParamSetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILSAM_ParamSet * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILSAM_ParamSet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILSAM_ParamSet * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILSAM_ParamSet * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILSAM_ParamSet * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILSAM_ParamSet * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILSAM_ParamSet * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ILSAM_ParamSetVtbl;

    interface ILSAM_ParamSet
    {
        CONST_VTBL struct ILSAM_ParamSetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILSAM_ParamSet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILSAM_ParamSet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILSAM_ParamSet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILSAM_ParamSet_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILSAM_ParamSet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILSAM_ParamSet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILSAM_ParamSet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ILSAM_ParamSet_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LSAM_ParamSet;

#ifdef __cplusplus

class DECLSPEC_UUID("B1A9513E-15A4-41C2-BEA0-400A4A181604")
LSAM_ParamSet;
#endif
#endif /* __LSAM_GUI_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


