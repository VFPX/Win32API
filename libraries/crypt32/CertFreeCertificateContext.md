<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CertFreeCertificateContext
Group: Cryptography Reference - Library: crypt32    
***  


#### Frees a certificate context by decrementing its reference count.
***  


## Declaration:
```foxpro  
BOOL WINAPI CertFreeCertificateContext(
	PCCERT_CONTEXT pCertContext
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CertFreeCertificateContext IN crypt32;
	INTEGER pCertContext
  
```  
***  


## Parameters:
```txt  
pCertContext
[in] A pointer to the CERT_CONTEXT to be freed.  
```  
***  


## Return value:
The function always returns nonzero.  
***  


## Comments:
See also: CertFindCertificateInStore.  
  
***  

