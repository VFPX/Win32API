[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CertCloseStore
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [crypt32](../../Libraries.md#crypt32)  
***  


#### Closes a certificate store handle and reduces the reference count on the store.
***  


## Declaration:
```foxpro  
BOOL WINAPI CertCloseStore(
	HCERTSTORE hCertStore,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CertCloseStore IN crypt32;
	INTEGER hCertStore,;
	LONG dwFlags  
```  
***  


## Parameters:
hCertStore 
[in] Handle of the certificate store to be closed.

dwFlags 
[in] Typically, this parameter uses the default value zero.   
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
There needs to be a corresponding call to CertCloseStore for each successful call to the CertOpenSystemStore, CertOpenStore or CertDuplicateStore functions.  
  
***  

