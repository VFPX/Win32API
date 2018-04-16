[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CertOpenSystemStore
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [crypt32](../../Libraries.md#crypt32)  
***  


#### This is a simplified function that opens the most common system certificate store.
***  


## Declaration:
```foxpro  
HCERTSTORE WINAPI CertOpenSystemStore(
	HCRYPTPROV_LEGACY hprov,
	LPTCSTR szSubsystemProtocol
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CertOpenSystemStore IN crypt32;
	INTEGER hprov,;
	STRING szSubsystemProtocol  
```  
***  


## Parameters:
hprov 
[in] This parameter is not used and should be set to NULL.

szSubsystemProtocol 
[in] A string that names a system store (CA, MY, ROOT, SPC).  
***  


## Return value:
If the function succeeds, the function returns a handle to the certificate store.
  
***  


## Comments:
If the system store name provided in <Em>szSubsystemProtocol</Em> parameter is not the name of an existing system store, a new system store will be created and used.  
  
After use, the store should be closed by using CertCloseStore.  
  
```foxpro
#DEFINE CERT_CLOSE_STORE_FORCE_FLAG 1  
#DEFINE CERT_CLOSE_STORE_CHECK_FLAG 2  
  
LOCAL hStore  
hStore = CertOpenSystemStore(0, "CA")  
? "Cert.store handle:", hStore  
  
IF hStore = 0  
	? "Error:", GetLastError()  
ELSE  
	= CertCloseStore(hStore, 0)  
ENDIF
```

***  

