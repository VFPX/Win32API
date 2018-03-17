<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CryptGetDefaultProvider
Group: Cryptography Reference - Library: advapi32    
***  


#### Finds the default cryptographic service provider (CSP) of a specified provider type. The CSP can be the default for either for the current user or for the computer (LocalMachine). 
***  


## Code examples:
[CryptoAPI: Collection of Providers class](../../samples/sample_463.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptGetDefaultProvider(
	DWORD dwProvType,
	DWORD* pdwReserved,
	DWORD dwFlags,
	LPTSTR pszProvName,
	DWORD* pcbProvName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptGetDefaultProvider IN advapi32;
	INTEGER   dwProvType,;
	INTEGER   pdwReserved,;
	INTEGER   dwFlags,;
	STRING  @ pszProvName,;
	INTEGER @ pcbProvName
  
```  
***  


## Parameters:
```txt  
dwProvType
[in] Specifies the provider type for which the default CSP name is to be found.

pdwReserved
[in] Reserved for future use and must be NULL.

dwFlags
[in] The following flag values are defined: CRYPT_MACHINE_DEFAULT, CRYPT_USER_DEFAULT

pszProvName
[out] Pointer to a null-terminated character string buffer to receive the name of the default CSP.

pcbProvName
[in, out] Pointer to a DWORD value specifying the size, in bytes, of the buffer pointed to by the pszProvName parameter.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero (TRUE).  
***  


## Comments:
<code><font color=#0000a0>#DEFINE PROV_RSA_FULL       1  
#DEFINE PROV_RSA_SIG        2  
#DEFINE PROV_DSS            3  
#DEFINE PROV_FORTEZZA       4  
#DEFINE PROV_MS_EXCHANGE    5  
#DEFINE PROV_SSL            6  
#DEFINE PROV_RSA_SCHANNEL   12  
#DEFINE PROV_DSS_DH         13  
#DEFINE PROV_EC_ECDSA_SIG   14  
#DEFINE PROV_EC_ECNRA_SIG   15  
#DEFINE PROV_EC_ECDSA_FULL  16  
#DEFINE PROV_EC_ECNRA_FULL  17  
#DEFINE PROV_SPYRUS_LYNKS   20  
</font></code>  
  
***  

