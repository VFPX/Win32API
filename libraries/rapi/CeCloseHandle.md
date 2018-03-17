<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeCloseHandle
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function closes an open object handle.
***  


## Code examples:
[Pocket PC: base class](../../samples/sample_440.md)  
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  
[PocketPC: custom RAPI class for executing routines on remote Windows CE device](../../samples/sample_466.md)  

## Declaration:
```foxpro  
BOOL CeCloseHandle(
  HANDLE hObject
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeCloseHandle IN rapi;
	INTEGER hObject  
```  
***  


## Parameters:
```txt  
hObject
[in] Handle to an open object.  
```  
***  


## Return value:
Nonzero indicates success.  
***  


## Comments:
Use CeCloseHandle to close handles returned by calls to the CeCreateFile function. Use CeFindClose to close handles returned by calls to the CeFindFirstFile function.  
  
***  

