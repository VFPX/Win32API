[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CertFindCertificateInStore
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [crypt32](../../Libraries.md#crypt32)  
***  


#### Finds the first or next certificate context in a certificate store that matches a search criteria established by the dwFindType and its associated pvFindPara.
***  


## Declaration:
```foxpro  
PCCERT_CONTEXT WINAPI CertFindCertificateInStore(
	HCERTSTORE hCertStore,
	DWORD dwCertEncodingType,
	DWORD dwFindFlags,
	DWORD dwFindType,
	const void* pvFindPara,
	PCCERT_CONTEXT pPrevCertContext
);

  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CertFindCertificateInStore IN crypt32;
	INTEGER hCertStore,;
	LONG dwCertEncodingType,;
	LONG dwFindFlags,;
	LONG dwFindType,;
	INTEGER pvFindPara,;
	INTEGER pPrevCertContext  
```  
***  


## Parameters:
hCertStore 
[in] A handle of the certificate store to be searched. See CertOpenSystemStore, CertOpenStore.

dwCertEncodingType 
[in] Specifies the type of encoding used. Both the certificate and message encoding types must be specified by combining them with a bitwise-OR operation.

dwFindFlags 
[in] Used with some dwFindType values to modify the search criteria.

dwFindType 
[in] Specifies the type of search being made.

pvFindPara 
[in] Points to a data item or structure used with dwFindType.

pPrevCertContext 
[in] A pointer to the last CERT_CONTEXT structure returned by this function (previous call). This parameter must be NULL on the first call of the function.  
***  


## Return value:
If the function succeeds, the function returns a pointer to a read-only CERT_CONTEXT structure.  
***  


## Comments:
A non-NULLCERT_CONTEXT that CertFindCertificateInStore returns must be freed by CertFreeCertificateContext or by being passed as the pPrevCertContext parameter on a subsequent call to CertFindCertificateInStore.  
  
```foxpro
#DEFINE PKCS_7_ASN_ENCODING 0x00010000  
#DEFINE X509_ASN_ENCODING 1  
#DEFINE CERT_FIND_ANY 0  
  
LOCAL hBuffer  
hBuffer = 0  
  
hBuffer = CertFindCertificateInStore(hStore,;  
	BITOR(PKCS_7_ASN_ENCODING, X509_ASN_ENCODING),;  
	0, CERT_FIND_ANY, 0, 0)  
  
? "Pointer to CERT_CONTEXT structure:", hBuffer  
  
IF hBuffer <> 0  
	= CertFreeCertificateContext(hBuffer)  
ENDIF
```

***  

