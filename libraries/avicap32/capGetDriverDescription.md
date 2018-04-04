[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : capGetDriverDescription
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [avicap32](../../Libraries.md#avicap32)  
***  


#### The capGetDriverDescription function retrieves the version description of the capture driver.

***  


## Code examples:
[Using Video Capture: enumerating installed capture drivers](../../samples/sample_438.md)  

## Declaration:
```foxpro  
BOOL VFWAPI capGetDriverDescription(
  WORD wDriverIndex,
  LPSTR lpszName,
  INT cbName,
  LPSTR lpszVer,
  INT cbVer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER capGetDriverDescription IN avicap32;
	INTEGER   wDriverIndex,;
	STRING  @ lpszName,;
	INTEGER   cbName,;
	STRING  @ lpszVer,;
	INTEGER   cbVer
  
```  
***  


## Parameters:
wDriverIndex
Index of the capture driver. The index can range from 0 through 9.

lpszName
Pointer to a buffer containing a null-terminated string corresponding to the capture driver name.

cbName
Length, in bytes, of the buffer pointed to by lpszName.

lpszVer
Pointer to a buffer containing a null-terminated string corresponding to the description of the capture driver.

cbVer
Length, in bytes, of the buffer pointed to by lpszVer.
  
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  

