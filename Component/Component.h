

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0620 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for C:\Users\gemin\AppData\Local\Temp\Component.idl-0f13cba2:
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

#ifndef __Component_h__
#define __Component_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ____x_ABI_CComponent_CIComponent_FWD_DEFINED__
#define ____x_ABI_CComponent_CIComponent_FWD_DEFINED__
typedef interface __x_ABI_CComponent_CIComponent __x_ABI_CComponent_CIComponent;

#ifdef __cplusplus
namespace ABI {
    namespace Component {
        interface IComponent;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CComponent_CIComponent_FWD_DEFINED__ */


/* header files for imported files */
#include "inspectable.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_Component_0000_0000 */
/* [local] */ 

#if !defined(____x_ABI_CComponent_CIComponent_INTERFACE_DEFINED__)
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Component_IComponent[] = L"Component.IComponent";
#endif /* !defined(____x_ABI_CComponent_CIComponent_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_Component_0000_0000 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0000_v0_0_s_ifspec;

#ifndef ____x_ABI_CComponent_CIComponent_INTERFACE_DEFINED__
#define ____x_ABI_CComponent_CIComponent_INTERFACE_DEFINED__

/* interface __x_ABI_CComponent_CIComponent */
/* [uuid][object] */ 



/* interface ABI::Component::IComponent */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CComponent_CIComponent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace Component {
            
            MIDL_INTERFACE("731fcdee-39ba-4d24-9e28-e0f57d27922a")
            IComponent : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE SayHello( 
                    HSTRING Hello) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_IComponent = __uuidof(IComponent);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CComponent_CIComponentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CComponent_CIComponent * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CComponent_CIComponent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CComponent_CIComponent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CComponent_CIComponent * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CComponent_CIComponent * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CComponent_CIComponent * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *SayHello )( 
            __x_ABI_CComponent_CIComponent * This,
            HSTRING Hello);
        
        END_INTERFACE
    } __x_ABI_CComponent_CIComponentVtbl;

    interface __x_ABI_CComponent_CIComponent
    {
        CONST_VTBL struct __x_ABI_CComponent_CIComponentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CComponent_CIComponent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CComponent_CIComponent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CComponent_CIComponent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CComponent_CIComponent_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CComponent_CIComponent_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CComponent_CIComponent_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CComponent_CIComponent_SayHello(This,Hello)	\
    ( (This)->lpVtbl -> SayHello(This,Hello) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CComponent_CIComponent_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_Component_0000_0001 */
/* [local] */ 

#ifdef __cplusplus
namespace ABI {
namespace Component {
class Component;
} /*Component*/
}
#endif

#ifndef RUNTIMECLASS_Component_Component_DEFINED
#define RUNTIMECLASS_Component_Component_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Component_Component[] = L"Component.Component";
#endif


/* interface __MIDL_itf_Component_0000_0001 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HSTRING_UserSize(     unsigned long *, unsigned long            , HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserMarshal(  unsigned long *, unsigned char *, HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserUnmarshal(unsigned long *, unsigned char *, HSTRING * ); 
void                      __RPC_USER  HSTRING_UserFree(     unsigned long *, HSTRING * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


