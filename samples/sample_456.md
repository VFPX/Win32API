[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to generate GUID values

## Before you begin:
The result is returned in a format like that of the following sample:  
<font color=#0000a0>{557cf400-1a04-11d3-9a73-0000f81ef32e}</font>  

See also:

* [Generating random UUID values](sample_024.md)  
* [Generating sequential UUID values](sample_587.md)  

  
***  


## Code:
```foxpro  
DO declare

LOCAL cGUID, cGUIDString, cGUID1
cGUID = REPLICATE(CHR(0), 16)  && 128 bits

IF CoCreateGuid(@cGUID) = 0
	cGUIDString = StringFromGUID(cGUID)
	? cGUID
	? cGUIDString
	
	* converting from String back to GUID
	cGUID1 = REPLICATE(CHR(0), 16)
	= CLSIDFromString(STRCONV(cGUIDString,5), @cGUID1)
	? cGUID1
ENDIF
* end of main

FUNCTION StringFromGUID(cGUID)
	LOCAL cBuffer, nBufsize
	nBufsize=128
	cBuffer = REPLICATE(CHR(0), nBufsize*2)
	= StringFromGUID2(cGUID, @cBuffer, nBufsize)
	cBuffer = SUBSTR(cBuffer, 1, AT(CHR(0)+CHR(0), cBuffer))
RETURN STRCONV(cBuffer, 6)

PROCEDURE declare
	DECLARE INTEGER CoCreateGuid IN ole32 STRING @pguid

	DECLARE INTEGER CLSIDFromString IN ole32;
		STRING lpsz, STRING @pclsid

	DECLARE INTEGER StringFromGUID2 IN ole32;
		STRING rguid, STRING @lpsz, INTEGER cchMax  
```  
***  


## Listed functions:
[CLSIDFromString](../libraries/ole32/CLSIDFromString.md)  
[CoCreateGuid](../libraries/ole32/CoCreateGuid.md)  
[StringFromGUID2](../libraries/ole32/StringFromGUID2.md)  

## Comment:
The [GUID](https://en.wikipedia.org/wiki/Universally_unique_identifier) is a *unique* 128-bit integer used for [CLSID](https://msdn.microsoft.com/en-us/library/windows/desktop/ms691424(v=vs.85).aspx)s and interface identifiers.  
  

* * *  
Having a connection to SQL Server, Guids can be generated with the NewId() function.

```foxpro
FUNCTION NewGuid() As String  
	IF SQLEXEC(1, "SELECT NewId() As guid", "csGuid") > 0  
		RETURN csGuid.guid  
	ELSE  
		RETURN NULL  
	ENDIF
```

Another way is using the Scriptlet.TypeLib COM. Note that you must create a new instance of the class for each Guid to be generated, which probably produces some overhead.  
```foxpro
obj = CreateObject("Scriptlet.TypeLib")  
? SUBSTR(obj.GUID,2,36)
```
After a simple test I can estimate that the COM procedure is 5 to 10% faster than the SQL one (local server); and API is the winner creating GUID 15-20 times faster than COM -- for example, 0.24 seconds versus 4 seconds per 10,000 guids created.   
  
On the same computer C# code generated 1,000,000 guids in 1.05 seconds.  
  
***  

