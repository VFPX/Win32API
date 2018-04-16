[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SCardGetAttrib
Group: [Authentication](../../functions_group.md#Authentication)  -  Library: [winscard](../../Libraries.md#winscard)  
***  


#### Gets the current reader attributes for the given handle. It does not affect the state of the reader, driver, or card.

***  


## Declaration:
```foxpro  
LONG SCardGetAttrib(
  __in     SCARDHANDLE hCard,
  __in     DWORD dwAttrId,
  __out    LPBYTE pbAttr,
  __inout  LPDWORD pcbAttrLen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardGetAttrib IN Winscard;
	INTEGER hCard,;
	LONG dwAttrId,;
	STRING @pbAttr,;
	LONG @pcbAttrLen  
```  
***  


## Parameters:
hCard [in] 
Reference value returned from SCardConnect.

dwAttrId [in] 
Identifier for the attribute to get.

pbAttr [out] 
Pointer to a buffer that receives the attribute whose ID is supplied in dwAttrId.

pcbAttrLen [in, out] 
Length of the pbAttr buffer in bytes, and receives the actual length of the received attribute.  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:
In Winsmcrd.h file the SCARD_ATTR_VALUE macro is used to define the attribute constants.  
  
```foxpro
#define SCARD_ATTR_VENDOR_NAME  
	SCARD_ATTR_VALUE(SCARD_CLASS_VENDOR_INFO, 0x0100)
```
The statement above can be translated into VFP code as follows:  
  
```foxpro
#DEFINE SCARD_ATTR_VENDOR_NAME;  
	BITOR(BITLSHIFT(SCARD_CLASS_VENDOR_INFO, 16), 0x0100)
```
  
***  

