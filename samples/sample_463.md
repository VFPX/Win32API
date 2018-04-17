[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# CryptoAPI: Collection of Providers class

## Short description:
The CryptoAPI Providers class presents collection of cryptographic service providers (CSP) available on a computer. Each provider is described with type, name, collections of available containers and algorithms.  
***  


## Before you begin:
This class presents a collection of cryptographic service providers (CSP) available on a computer. Each provider is described with type, name, collections of available containers and algorithms.  

Code samples based on this class:  
* [list of cryptographic service providers](sample_464.md)  

See also:

* [Simple class that encrypts and decrypts files using Cryptography API Functions ](sample_511.md)  
* [How to create MD-5 and SHA-1 hash values from a string](sample_483.md)  

  
***  


## Code:
```foxpro  
DEFINE CLASS providers As Collection
#DEFINE CRYPT_FIRST           1
#DEFINE CRYPT_USER_DEFAULT    2
#DEFINE CRYPT_MACHINE_DEFAULT 1
#DEFINE PP_ENUMALGS           1
#DEFINE PP_ENUMCONTAINERS     2
#DEFINE PROV_RSA_FULL         1
#DEFINE CRYPT_NEWKEYSET     0x0008 && creates new container
#DEFINE CRYPT_DELETEKEYSET  0x0010 && deletes existing container
#DEFINE MS_DEF_PROV  "Microsoft Base Cryptographic Provider v1.0"

PROCEDURE Init
	THIS.declare
	THIS.EnumProviders

PROCEDURE Destroy
	THIS.ReleaseProviders

FUNCTION GetDefaultProviderUser(nProvType) As provider
RETURN THIS.GetDefaultProvider(nProvType, CRYPT_USER_DEFAULT)

FUNCTION GetDefaultProviderMachine(nProvType) As provider
RETURN THIS.GetDefaultProvider(nProvType, CRYPT_MACHINE_DEFAULT)

PROTECTED FUNCTION GetDefaultProvider(nProvType, nFlags) As provider
	LOCAL cBuffer, nBufsize
	nBufsize=250
	cBuffer=REPLICATE(CHR(0), m.nBufsize)
	= CryptGetDefaultProvider(nProvType, 0, m.nFlags,;
		@cBuffer, @nBufsize)
	cBuffer = ALLTRIM(STRTRAN(SUBSTR(cBuffer, 1, nBufsize), CHR(0),""))
RETURN THIS.GetProvider(m.cBuffer)

FUNCTION GetProvider(vId) As provider
	LOCAL oProvider As provider
	DO CASE
	CASE VARTYPE(vId)="N" AND BETWEEN(m.vId, 1, THIS.Count)
		oProvider = THIS.Item(vId)
	CASE VARTYPE(vId)="C"
		TRY
			oProvider = THIS.Item(UPPER(ALLTRIM(vId)))
		CATCH
			oProvider = CREATEOBJECT("provider", vId, 0)
		ENDTRY
	OTHERWISE
		oProvider = CREATEOBJECT("provider", "", 0)
	ENDCASE
RETURN oProvider

PROTECTED PROCEDURE ReleaseProviders
	LOCAL oProvider As provider
	FOR EACH oProvider IN THIS
		oProvider.ReleaseContext
	NEXT

PROTECTED PROCEDURE EnumProviders
	LOCAL nIndex, nType, cBuffer, nBufsize
	nIndex=0

	DO WHILE .T.
		nType=0
		nBufsize=250
		cBuffer=REPLICATE(CHR(0), nBufsize)

		IF CryptEnumProviders(nIndex, 0,0, @nType,;
			@cBuffer, @nBufsize)=0
			EXIT
		ENDIF
		cBuffer = ALLTRIM(STRTRAN(SUBSTR(cBuffer, 1, nBufsize), CHR(0),""))

		LOCAL oProvider As provider
		oProvider = CREATEOBJECT("provider", m.cBuffer, m.nType)
		THIS.Add(oProvider, UPPER(cBuffer))

		nIndex=nIndex+1
	ENDDO

PROTECTED PROCEDURE declare
	DECLARE INTEGER CryptEnumProviders IN advapi32;
		INTEGER dwIndex, INTEGER pdwReserved, INTEGER dwFlags,;
		INTEGER @pdwProvType, STRING @pszProvName, INTEGER @pcbProvName

	DECLARE INTEGER CryptEnumProviderTypes IN advapi32;
		INTEGER dwIndex, INTEGER pdwReserved, INTEGER dwFlags,;
		INTEGER @pdwProvType, STRING @pszTypeName, INTEGER @pcbTypeName

	DECLARE INTEGER CryptGetDefaultProvider IN advapi32;
		INTEGER dwProvType, INTEGER pdwReserved, INTEGER dwFlags,;
		STRING @pszProvName, INTEGER @pcbProvName

	DECLARE INTEGER CryptGetProvParam IN advapi32;
		INTEGER hProv, INTEGER dwParam, STRING @pbData,;
		INTEGER @pdwDataLen, INTEGER dwFlags

	DECLARE INTEGER CryptAcquireContext IN advapi32;
		INTEGER @hProvHandle, STRING cContainer, ;
		STRING cProvider, INTEGER nProvType, INTEGER nFlags

	DECLARE INTEGER CryptReleaseContext IN advapi32;
		INTEGER hProvHandle, INTEGER nReserved

	DECLARE INTEGER CryptGenKey IN advapi32;
		INTEGER hProv, INTEGER Algid, INTEGER dwFlags, INTEGER @phKey

	DECLARE INTEGER CryptGetKeyParam IN advapi32;
		INTEGER hKey, INTEGER dwParam, STRING @pbData,;
		INTEGER @pdwDataLen, INTEGER dwFlags

	DECLARE INTEGER CryptCreateHash IN advapi32;
		INTEGER hProv, INTEGER Algid, INTEGER hKey,;
		INTEGER dwFlags, INTEGER @phHash

	DECLARE INTEGER CryptDestroyKey IN advapi32 INTEGER hKey
	DECLARE INTEGER CryptDestroyHash IN advapi32 INTEGER hHash
	DECLARE LONG GetLastError IN kernel32
ENDDEFINE

DEFINE CLASS provider As Session
	errorcode=0
	provtype=0
	provname=""
	context=0
	keycontainers=0
	algorithms=0

PROCEDURE Init(cName, nType)
	THIS.provtype=INT(m.nType)
	THIS.provname=ALLTRIM(m.cName)
	THIS.keycontainers = CREATEOBJECT("Collection")
	THIS.algorithms = CREATEOBJECT("Collection")

PROCEDURE Destroy
	THIS.ReleaseContext

PROCEDURE ReleaseContext
	IF THIS.context <> 0
		= CryptReleaseContext(THIS.context, 0)
		THIS.context=0
	ENDIF

FUNCTION AcquireContext(cContainer As String) As Boolean
	IF VARTYPE(cContainer) <> "C"
		cContainer=Null  && default container
	ENDIF
RETURN THIS.AcquireContext_(m.cContainer, 0)

FUNCTION CreateContainer(cContainer As String) As Boolean
	IF VARTYPE(m.cContainer) <> "C" OR EMPTY(m.cContainer)
		RETURN .F.
	ENDIF
RETURN THIS.AcquireContext_(m.cContainer, CRYPT_NEWKEYSET)

PROCEDURE DeleteContainer(cContainer As String)
	IF VARTYPE(m.cContainer) <> "C" OR EMPTY(m.cContainer)
		RETURN .F.
	ENDIF
	THIS.AcquireContext_(m.cContainer, CRYPT_DELETEKEYSET)

PROTECTED FUNCTION AcquireContext_(cContainer, nFlags)
	THIS.ReleaseContext

	LOCAL nContext
	STORE 0 TO nContext, THIS.errorcode
	IF CryptAcquireContext(@nContext, m.cContainer,;
		THIS.provname, THIS.provtype, m.nFlags) = 0
		THIS.errorcode = GetLastError()
	ENDIF
	THIS.context = m.nContext

	THIS.keycontainers = CREATEOBJECT("Collection")
	THIS.algorithms = CREATEOBJECT("Collection")

	IF THIS.errorcode = 0
		THIS.EnumContainers
		THIS.EnumAlgorithms
	ENDIF
RETURN (THIS.context <> 0)

PROTECTED PROCEDURE EnumContainers
	LOCAL cContainer
	cContainer = THIS.GetProvParam(PP_ENUMCONTAINERS,;
		"C",CRYPT_FIRST)

	DO WHILE .T.
		cContainer = ALLTRIM(STRTRAN(cContainer, CHR(0), ""))
		IF EMPTY(m.cContainer)
			EXIT
		ELSE
			LOCAL oContainer
			oContainer = CREATEOBJECT("keycontainer", m.cContainer)
			THIS.keycontainers.Add(m.oContainer, m.cContainer)
			oContainer=Null
		ENDIF
		cContainer = THIS.GetProvParam(PP_ENUMCONTAINERS)
	ENDDO

PROTECTED PROCEDURE EnumAlgorithms
	LOCAL cBuffer
	cBuffer = THIS.GetProvParam(PP_ENUMALGS, "C", CRYPT_FIRST)
	DO WHILE .T.
		cBuffer = THIS.GetProvParam(PP_ENUMALGS, "C")
		IF EMPTY(m.cBuffer)
			EXIT
		ENDIF

		LOCAL oAlg
		oAlg = CREATEOBJECT("algorithm", m.cBuffer)
		IF NOT EMPTY(oAlg.algname)
			THIS.algorithms.Add(m.oAlg, TRANSFORM(oAlg.algid))
		ENDIF
		oAlg=Null
	ENDDO

PROCEDURE GetProvParam(nParamId, cVartype, nFlags)
	IF VARTYPE(m.nFlags) <> "N"
		nFlags=0
	ENDIF
	IF VARTYPE(m.cVartype) <> "C"
		cVartype="C"
	ENDIF

	LOCAL nResult, cBuffer, nBufsize
	cBuffer = Null
	nBufsize=0
	= CryptGetProvParam(THIS.context, m.nParamId, cBuffer,;
		@nBufsize, m.nFlags)

	THIS.errorcode=0
	cBuffer = REPLICATE(CHR(0), nBufsize)
	IF CryptGetProvParam(THIS.context, m.nParamId, @cBuffer,;
		@nBufsize, m.nFlags) = 0
		THIS.errorcode = GetLastError()
	ENDIF
	
	DO CASE
	CASE cVartype="C"
		RETURN m.cBuffer
	CASE cVartype="N" AND nBufsize=0
		RETURN 0
	CASE cVartype="N" AND nBufsize=1  && BYTE
		RETURN ASC(m.cBuffer)
	CASE cVartype="N" AND nBufsize=2  && WORD
		RETURN buf2word(m.cBuffer)
	CASE cVartype="N" AND nBufsize=4  && DWORD
		RETURN buf2dword(m.cBuffer)
	OTHERWISE
		RETURN m.cBuffer
	ENDCASE
ENDDEFINE

DEFINE CLASS keycontainer As Session
	containername=""
PROCEDURE Init(cName)
	THIS.containername = m.cName
ENDDEFINE

DEFINE CLASS algorithm As Session
	algid=0
	bitlen=0
	algname=""
PROCEDURE Init(cBuffer)
	LOCAL nNameLen
	THIS.algid = buf2dword(SUBSTR(m.cBuffer,1,4))
	THIS.bitlen = buf2dword(SUBSTR(m.cBuffer,5,4))
	nNameLen = buf2dword(SUBSTR(m.cBuffer,9,4))
	THIS.algname = ALLTRIM(STRTRAN(SUBSTR(m.cBuffer, 13,;
		m.nNameLen), CHR(0), ""))
ENDDEFINE

DEFINE CLASS sessionkey As Session
	errorcode=0
	provider=0
	algorithm=0
	keyflag=0
	hkey=0

PROCEDURE Init(oProvider, oAlgorithm, nFlags)
	THIS.provider=m.oProvider
	THIS.algorithm=m.oAlgorithm
	THIS.keyflag = IIF(VARTYPE(nFlags)="N", nFlags, 0)
	THIS.GenKey

PROCEDURE Destroy
	THIS.DestroyKey

PROTECTED PROCEDURE DestroyKey
	IF THIS.hkey <> 0
		= CryptDestroyKey(THIS.hkey)
		THIS.hkey=0
	ENDIF

PROTECTED PROCEDURE GenKey
	LOCAL hKey
	hKey=0
	IF CryptGenKey(THIS.provider.context, THIS.algorithm.algid,;
		THIS.keyflag, @hKey)=0
		THIS.errorcode = GetLastError()
	ENDIF
	THIS.hkey = m.hKey
RETURN (THIS.hkey<>0)

PROCEDURE GetKeyParam(nParamId, cVartype, nFlags)
	DECLARE INTEGER CryptGetKeyParam IN advapi32;
		INTEGER hKey, INTEGER dwParam, STRING @pbData,;
		INTEGER @pdwDataLen, INTEGER dwFlags

	IF VARTYPE(m.nFlags) <> "N"
		nFlags=0
	ENDIF
	IF VARTYPE(m.cVartype) <> "C"
		cVartype="C"
	ENDIF

	LOCAL nResult, cBuffer, nBufsize
	cBuffer = Null
	nBufsize=0
	= CryptGetKeyParam(THIS.hkey, m.nParamId, cBuffer,;
		@nBufsize, m.nFlags)

	THIS.errorcode=0
	cBuffer = REPLICATE(CHR(0), nBufsize)
	IF CryptGetKeyParam(THIS.hkey, m.nParamId, @cBuffer,;
		@nBufsize, m.nFlags) = 0
		THIS.errorcode = GetLastError()
	ENDIF

	DO CASE
	CASE cVartype="C"
		RETURN m.cBuffer
	CASE cVartype="N" AND nBufsize=0
		RETURN 0
	CASE cVartype="N" AND nBufsize=1  && BYTE
		RETURN ASC(m.cBuffer)
	CASE cVartype="N" AND nBufsize=2  && WORD
		RETURN buf2word(m.cBuffer)
	CASE cVartype="N" AND nBufsize=4  && DWORD
		RETURN buf2dword(m.cBuffer)
	OTHERWISE
		RETURN m.cBuffer
	ENDCASE
ENDDEFINE

DEFINE CLASS hash As Session
	errorcode=0
	provider=0
	algorithm=0
	sessionkey=0
	hash=0

PROCEDURE Init(oProvider, oAlgorithm, oKey)
	THIS.provider=m.oProvider
	THIS.algorithm=m.oAlgorithm
	THIS.sessionkey=m.oKey
	THIS.GenHash

PROCEDURE Destroy
	THIS.DestroyHash

PROTECTED PROCEDURE DestroyHash
	IF THIS.hash <> 0
		= CryptDestroyHash(THIS.hash)
		THIS.hash=0
	ENDIF

PROTECTED PROCEDURE GenHash
	LOCAL hash
	hash=0
	IF CryptCreateHash(THIS.provider.context, THIS.algorithm.algid,;
		THIS.sessionkey.hkey, 0, @m.hash) = 0
		THIS.errorcode = GetLastError()
	ENDIF
	THIS.hash = m.hash
RETURN (THIS.hash <> 0)
ENDDEFINE

*********************** static members ***********************
FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256  
```  
***  


## Listed functions:
[CryptAcquireContext](../libraries/advapi32/CryptAcquireContext.md)  
[CryptCreateHash](../libraries/advapi32/CryptCreateHash.md)  
[CryptDestroyHash](../libraries/advapi32/CryptDestroyHash.md)  
[CryptDestroyKey](../libraries/advapi32/CryptDestroyKey.md)  
[CryptEnumProviderTypes](../libraries/advapi32/CryptEnumProviderTypes.md)  
[CryptEnumProviders](../libraries/advapi32/CryptEnumProviders.md)  
[CryptGenKey](../libraries/advapi32/CryptGenKey.md)  
[CryptGetDefaultProvider](../libraries/advapi32/CryptGetDefaultProvider.md)  
[CryptGetKeyParam](../libraries/advapi32/CryptGetKeyParam.md)  
[CryptGetProvParam](../libraries/advapi32/CryptGetProvParam.md)  
[CryptReleaseContext](../libraries/advapi32/CryptReleaseContext.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  

## Comment:
MSDN defines cryptographic service provider (CSP) as *an independent software module that actually performs cryptography algorithms for authentication, encoding, and encryption*.  
  

***  

