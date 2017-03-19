

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0620 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for C:\Users\gemin\AppData\Local\Temp\InheritedPage.idl-931469a8:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0620 
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
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __InheritedPage_h_h__
#define __InheritedPage_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#if defined(__cplusplus)
#if defined(__MIDL_USE_C_ENUM)
#define MIDL_ENUM enum
#else
#define MIDL_ENUM enum class
#endif
#endif


/* Forward Declarations */ 

#ifndef ____x_ABI_CTesting_CIInheritedPage_FWD_DEFINED__
#define ____x_ABI_CTesting_CIInheritedPage_FWD_DEFINED__
typedef interface __x_ABI_CTesting_CIInheritedPage __x_ABI_CTesting_CIInheritedPage;

#ifdef __cplusplus
namespace ABI {
    namespace Testing {
        interface IInheritedPage;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CTesting_CIInheritedPage_FWD_DEFINED__ */


/* header files for imported files */
#include "inspectable.h"
#include "windows.ui.xaml.controls.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_InheritedPage_0000_0000 */
/* [local] */ 

#ifdef __cplusplus
namespace ABI {
namespace Testing {
class InheritedPage;
} /*Testing*/
}
#endif

#if !defined(____x_ABI_CTesting_CIInheritedPage_INTERFACE_DEFINED__)
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Testing_IInheritedPage[] = L"Testing.IInheritedPage";
#endif /* !defined(____x_ABI_CTesting_CIInheritedPage_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_InheritedPage_0000_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_InheritedPage_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_InheritedPage_0000_0000_v0_0_s_ifspec;

#ifndef ____x_ABI_CTesting_CIInheritedPage_INTERFACE_DEFINED__
#define ____x_ABI_CTesting_CIInheritedPage_INTERFACE_DEFINED__

/* interface __x_ABI_CTesting_CIInheritedPage */
/* [uuid][object] */ 



/* interface ABI::Testing::IInheritedPage */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CTesting_CIInheritedPage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace Testing {
            
            MIDL_INTERFACE("325246d5-c808-4a2e-97f7-abafe4f429f1")
            IInheritedPage : public ::IInspectable
            {
            public:
            };

            extern const __declspec(selectany) IID & IID_IInheritedPage = __uuidof(IInheritedPage);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CTesting_CIInheritedPageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CTesting_CIInheritedPage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CTesting_CIInheritedPage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CTesting_CIInheritedPage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CTesting_CIInheritedPage * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CTesting_CIInheritedPage * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CTesting_CIInheritedPage * This,
            /* [out] */ TrustLevel *trustLevel);
        
        END_INTERFACE
    } __x_ABI_CTesting_CIInheritedPageVtbl;

    interface __x_ABI_CTesting_CIInheritedPage
    {
        CONST_VTBL struct __x_ABI_CTesting_CIInheritedPageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CTesting_CIInheritedPage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CTesting_CIInheritedPage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CTesting_CIInheritedPage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CTesting_CIInheritedPage_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CTesting_CIInheritedPage_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CTesting_CIInheritedPage_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CTesting_CIInheritedPage_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_InheritedPage_0000_0001 */
/* [local] */ 

#ifndef RUNTIMECLASS_Testing_InheritedPage_DEFINED
#define RUNTIMECLASS_Testing_InheritedPage_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Testing_InheritedPage[] = L"Testing.InheritedPage";
#endif


/* interface __MIDL_itf_InheritedPage_0000_0001 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_InheritedPage_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_InheritedPage_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


