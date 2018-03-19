[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to fill a buffer with random bytes using Cryptography API Functions

## Before you begin:
Use this code to fill a large buffer (a string) with random characters. MS even insists that these characters would be far more random than any created by standard random function.  
  
***  


## Code:
```foxpro  
#DEFINE PROV_RSA_FULL 1
#DEFINE CRYPT_VERIFYCONTEXT 0xf0000000
DO declare

LOCAL hProvider, cBuffer
hProvider=0

* obtain CSP handle
IF CryptAcquireContext(@hProvider, NULL, NULL,;
	PROV_RSA_FULL, CRYPT_VERIFYCONTEXT) = 0
	? "Call to CryptAcquireContext failed:", GetLastError()
	RETURN
ENDIF

* allocate buffer that will receive random data
cBuffer = REPLICATE(CHR(0), 1024)

* fill the buffer with cryptographically random bytes
IF CryptGenRandom(m.hProvider, LEN(m.cBuffer), @cBuffer) = 0
	? "Call to CryptGenRandom failed:", GetLastError()
ELSE
	CREATE CURSOR cs (randbytes M)
	INSERT INTO cs VALUES (m.cBuffer)
	MODIFY MEMO randbytes NOWAIT
ENDIF

= CryptReleaseContext(m.hProvider, 0)
* end of main

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER CryptGenRandom IN advapi32;
		INTEGER hProv, LONG dwLen, STRING @pbBuffer

	DECLARE INTEGER CryptAcquireContext IN advapi32;
		INTEGER @hProvHandle, STRING cContainer, ;
		STRING cProvider, INTEGER nProvType, INTEGER nFlags

	DECLARE INTEGER CryptReleaseContext IN advapi32;
		INTEGER hProvHandle, INTEGER nReserved  
```  
***  


## Listed functions:
[CryptAcquireContext](../libraries/advapi32/CryptAcquireContext.md)  
[CryptGenRandom](../libraries/advapi32/CryptGenRandom.md)  
[CryptReleaseContext](../libraries/advapi32/CryptReleaseContext.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
