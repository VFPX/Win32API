[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeCloseHandle
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
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
hObject 
[in] Handle to an open object.   
***  


## Return value:
Nonzero indicates success.  
***  


## Comments:
Use CeCloseHandle to close handles returned by calls to the CeCreateFile function. Use CeFindClose to close handles returned by calls to the CeFindFirstFile function.  
  
***  

