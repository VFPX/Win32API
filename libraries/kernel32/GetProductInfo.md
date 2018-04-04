[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetProductInfo
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the product type for the operating system on the local computer, and maps the type to the product types supported by the specified operating system.
***  


## Declaration:
```foxpro  
BOOL WINAPI GetProductInfo(
  __in   DWORD dwOSMajorVersion,
  __in   DWORD dwOSMinorVersion,
  __in   DWORD dwSpMajorVersion,
  __in   DWORD dwSpMinorVersion,
  __out  PDWORD pdwReturnedProductType
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetProductInfo IN kernel32;
	LONG dwOSMajorVersion,;
	LONG dwOSMinorVersion,;
	LONG dwSpMajorVersion,;
	LONG dwSpMinorVersion,;
	LONG @pdwReturnedProductType  
```  
***  


## Parameters:
dwOSMajorVersion 
The major version number of the operating system. The minimum value is 6.

dwOSMinorVersion 
The minor version number of the operating system. The minimum value is 0.

dwSpMajorVersion 
The major version number of the operating system service pack. The minimum value is 0.

dwSpMinorVersion 
The minor version number of the operating system service pack. The minimum value is 0.

pdwReturnedProductType 
The product type. This parameter cannot be NULL.
  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
The combination of the dwOSMajorVersion, dwOSMinorVersion, dwSpMajorVersion, and dwSpMinorVersion parameters describes the maximum target operating system version for the application.  
  
If the software license is invalid or expired, the function succeeds but the pdwReturnedProductType parameter is set to PRODUCT_UNLICENSED (0xABCDABCD).  
  
Requires Windows Vista. To retrieve product type information on versions of Windows prior to 6.0.0.0, use the GetVersionEx function.  
  
***  

