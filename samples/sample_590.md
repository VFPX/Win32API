[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Generating random cryptographic keys

## Short description:
The CryptKeyHelper class defined in the code sample below is a wrapper around Windows API Cryptography functions. It implements methods allowing to generate a random cryptographic key, to export the key to a specified file, and to import a key from a specified file.  
***  

## Code:
```foxpro  
#DEFINE CALG_DES 0x00006601  && 56 bits
#DEFINE CALG_3DES 0x00006603  && 168 bits

* 40, 128 bits
#DEFINE CALG_RC2 0x00006602
#DEFINE CALG_RC4 0x00006801

* 384 bits to 16,384 bits in 8-bit increments.
#DEFINE CALG_RSA_KEYX 0x0000a400
#DEFINE CALG_RSA_SIGN 0x00002400

LOCAL obj as CryptKeyHelper
obj = CREATEOBJECT("CryptKeyHelper")

IF NOT obj.GenerateRandomKey(CALG_RC4, 128)
	? "GenerateRandomKey failed:",;
		TRANSFORM(obj.LastWin32Error, "@0")
	RETURN
ENDIF

LOCAL cKeyFile
cKeyFile = "samplekey.txt"

IF NOT obj.ExportKeyToFile(m.cKeyFile)
	? "ExportKeyToFile failed:",;
		TRANSFORM(obj.LastWin32Error, "@0")
	RETURN
ENDIF

MODIFY FILE (m.cKeyFile)

IF NOT obj.ImportKeyFromFile(m.cKeyFile)
	? "ImportKeyFromFilefailed:",;
		TRANSFORM(obj.LastWin32Error, "@0")
ENDIF

? "Key imported from file successfully"
* end of main

DEFINE CLASS CryptKeyHelper as Session
#DEFINE CRYPT_VERIFYCONTEXT 0xf0000000
#DEFINE PROV_RSA_FULL 1
#DEFINE CRYPT_EXPORTABLE 1

#DEFINE NTE_BAD_KEY 0x80090003
#DEFINE NTE_BAD_ALGID 0x80090008
#DEFINE NTE_BAD_FLAGS 0x80090009

#DEFINE PLAINTEXTKEYBLOB 8

PROTECTED hProv, hKey
	hProv = 0
	hKey = 0
	LastWin32Error=0
	
PROCEDURE Init
	THIS.declare
	IF NOT THIS.GetContext()
		RETURN .F.
	ENDIF

PROCEDURE Destroy
	THIS.DestroyKey
	THIS.ReleaseContext

PROCEDURE GenerateRandomKey
LPARAMETERS nAlgId, nKeyBits
	THIS.DestroyKey
	THIS.LastWin32Error = 0

	LOCAL nFlags, hKey
	
	IF EMPTY(m.nKeyBits)
		nKeyBits = 40
	ENDIF
	
	nFlags = BITOR(CRYPT_EXPORTABLE,;
		BITLSHIFT(nKeyBits, 16))

	hKey = 0
	
	IF CryptGenKey(;
		THIS.hProv, m.nAlgId, m.nFlags, @hKey) > 0
		THIS.hKey = m.hKey
		RETURN .T.
	ENDIF

	THIS.LastWin32Error = GetLastError()
RETURN .F.

PROCEDURE ImportKeyFromFile
LPARAMETERS cFilename
	LOCAL cBuffer, hKey
	
	cBuffer = FILETOSTR(m.cFilename)
	hKey = 0
	
	IF CryptImportKey(;
		THIS.hProv, m.cBuffer, LEN(m.cBuffer),;
		0, CRYPT_EXPORTABLE, @hKey) > 0
	
		THIS.DestroyKey
		THIS.hKey = m.hKey
		RETURN .T.
	ENDIF

	THIS.LastWin32Error = GetLastError()
RETURN .F.

PROCEDURE ExportKeyToFile
LPARAMETERS cFilename
	IF THIS.hKey = 0
		RETURN .F.
	ENDIF
	
	LOCAL nBlobLength, cBuffer
	nBlobLength = 0

	= CryptExportKey(;
		THIS.hKey, 0, PLAINTEXTKEYBLOB,;
		0, 0, @nBlobLength)
		
	IF nBlobLength = 0
		THIS.LastWin32Error = GetLastError()
		RETURN .F.
	ENDIF
		
	cBuffer = REPLICATE(CHR(0), m.nBlobLength)

	IF CryptExportKey(;
		THIS.hKey, 0, PLAINTEXTKEYBLOB, 0,;
		@cBuffer, @nBlobLength) > 0

		STRTOFILE(m.cBuffer, m.cFilename)
		RETURN .T.
	ENDIF
	
	THIS.LastWin32Error = GetLastError()
RETURN .F.

PROTECTED PROCEDURE ReleaseContext
	= CryptReleaseContext(THIS.hProv, 0)
	THIS.hProv = 0

PROTECTED PROCEDURE DestroyKey
	IF THIS.hKey <> 0
		= CryptDestroyKey(THIS.hKey)
		THIS.hKey= 0
	ENDIF

PROTECTED PROCEDURE GetContext
* get handle to the crypto provider
	LOCAL hProv
	hProv = 0
	IF CryptAcquireContext(@hProv, NULL, NULL,;
		PROV_RSA_FULL, CRYPT_VERIFYCONTEXT) = 0
		RETURN .F.
	ENDIF
	THIS.hProv = m.hProv
RETURN .T.

PROTECTED PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER CryptAcquireContext IN advapi32;
		INTEGER @hProvHandle, STRING cContainer, ;
		STRING cProvider, INTEGER nProvType, INTEGER nFlags

	DECLARE INTEGER CryptReleaseContext IN advapi32;
		INTEGER hProvHandle, INTEGER nReserved

	DECLARE INTEGER CryptGenKey IN advapi32;
		INTEGER hProv, INTEGER Algid,;
		INTEGER dwFlags, INTEGER @phKey

	DECLARE INTEGER CryptExportKey IN advapi32;
		INTEGER hKey, INTEGER hExpKey,;
		INTEGER dwBlobType, INTEGER dwFlags,;
		STRING @pbData, INTEGER @pdwDataLen

	DECLARE INTEGER CryptImportKey IN advapi32;
		INTEGER hProv, STRING @pbData,;
		INTEGER dwDataLen, INTEGER hPubKey,;
		INTEGER dwFlags, INTEGER @phKey

	DECLARE INTEGER CryptDestroyKey IN advapi32;
		INTEGER hKey

ENDDEFINE  
```  
***  


## Listed functions:
[CryptAcquireContext](../libraries/advapi32/CryptAcquireContext.md)  
[CryptDestroyKey](../libraries/advapi32/CryptDestroyKey.md)  
[CryptExportKey](../libraries/advapi32/CryptExportKey.md)  
[CryptGenKey](../libraries/advapi32/CryptGenKey.md)  
[CryptImportKey](../libraries/advapi32/CryptImportKey.md)  
[CryptReleaseContext](../libraries/advapi32/CryptReleaseContext.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
