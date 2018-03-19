[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CertFreeCertificateContext
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
pCertContext 
[in] A pointer to the CERT_CONTEXT to be freed.   
***  


## Return value:
The function always returns nonzero.  
***  


## Comments:
See also: CertFindCertificateInStore.  
  
***  

