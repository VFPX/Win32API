<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : capGetDriverDescription
Group: Windows Multimedia - Library: avicap32    
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
```txt  
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
  
```  
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  

