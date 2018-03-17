<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeGetTempPath
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function gets the path to the directory designated for temporary files. 
***  


## Declaration:
```foxpro  
DWORD CeGetTempPath(
  DWORD nBufferLength,
  LPWSTR lpBuffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeGetTempPath IN rapi;
	INTEGER nBufferLength,;
	LONG    lpBuffer  
```  
***  


## Parameters:
```txt  
nBufferLength
[in] Size of lpBuffer in characters.

lpBuffer
[out] Long pointer to the buffer for the folder path. The returned string ends in a backslash (\).  
```  
***  


## Return value:
The return value is the length, in characters, of the string copied to lpBuffer, not including the terminating null character.  
***  


## Comments:
If CeGetTempPath fails, the return value is 0. To determine if a function failed because of RAPI errors, call CeRapiGetError. To determine if a function failed because of non-RAPI errors, call CeGetLastError.  
  
***  

