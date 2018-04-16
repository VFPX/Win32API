[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Generating UUID values from numbers

## Before you begin:
The [UUID structure](http://msdn.microsoft.com/en-us/library/windows/desktop/aa379358(v=vs.85).aspx) is an array of 16 bytes. Therefore a GUID value can be produced simply by stuffing array with bytes.  
  
***  


## Code:
```foxpro  
#DEFINE RPC_S_OK 0
DO declare

LOCAL cUUID, nIndex

cUUID = ;
		CHR(0xb3) +;
		CHR(0xb2) +;
		CHR(0xb1) +;
		CHR(0xb0) +;
	CHR(0xc1) +;
	CHR(0xc0) +;
		CHR(0xd1) +;
		CHR(0xd0) +;
	CHR(0xe1) +;
	CHR(0xe0) +;
		CHR(0xf5) +;
		CHR(0xf4) +;
		CHR(0xf3) +;
		CHR(0xf2) +;
		CHR(0xf1) +;
		CHR(0xf0)
	
store StringFromUUID(m.cUUID) TO _cliptext
* Output:
* B0B1B2B3-C0C1-D0D1-E1E0-F5F4F3F2F1F0

FOR nIndex = 1 TO 5
	cUUID = PADL(num2dwordR(nIndex), 16, CHR(0))
	? StringFromUUID(m.cUUID)
NEXT
* Output:
* 00000000-0000-0000-0000-000000000001
* 00000000-0000-0000-0000-000000000002
* 00000000-0000-0000-0000-000000000003
* 00000000-0000-0000-0000-000000000004
* 00000000-0000-0000-0000-000000000005

FOR nIndex = 0xf001 TO 0xf005
	cUUID = PADL(num2dwordR(nIndex), 16, CHR(0))
	? StringFromUUID(m.cUUID)
NEXT
* Output:
* 00000000-0000-0000-0000-00000000F001
* 00000000-0000-0000-0000-00000000F002
* 00000000-0000-0000-0000-00000000F003
* 00000000-0000-0000-0000-00000000F004
* 00000000-0000-0000-0000-00000000F005

* end of main

FUNCTION StringFromUUID(cUUID As String) As String
	LOCAL hBuffer, nBufsize, cResult
	cResult = ""
	hBuffer = 0

	IF UuidToString(@cUUID, @hBuffer) = RPC_S_OK
		nBufsize = 36
		cResult = REPLICATE(CHR(0), nBufsize)
		MemToStr(@cResult, hBuffer, nBufsize)
		RpcStringFree(@hBuffer)
	ENDIF
RETURN UPPER(STRTRAN(m.cResult, CHR(0), ""))

PROCEDURE declare
	DECLARE INTEGER RpcStringFree IN Rpcrt4;
		LONG @StringUuid
		
	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @, INTEGER, INTEGER
		
	DECLARE INTEGER UuidToString IN Rpcrt4;
		STRING @Uuid,;
		LONG @StringUuid
		
FUNCTION num2dwordR(lnValue)
#DEFINE m0 0x0000100
#DEFINE m1 0x0010000
#DEFINE m2 0x1000000
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b3)+Chr(b2)+Chr(b1)+Chr(b0)  
```  
***  


## Listed functions:
[RpcStringFree](../libraries/rpcrt4/RpcStringFree.md)  
[UuidToString](../libraries/rpcrt4/UuidToString.md)  

## Comment:
The max number that can be used with this approach is 0xffffffff.  
  
***  

