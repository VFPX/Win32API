<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CertCloseStore
Group: Cryptography Reference - Library: crypt32    
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
```txt  
hCertStore
[in] Handle of the certificate store to be closed.

dwFlags
[in] Typically, this parameter uses the default value zero.  
```  
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
There needs to be a corresponding call to CertCloseStore for each successful call to the CertOpenSystemStore, CertOpenStore or CertDuplicateStore functions.  
  
***  

