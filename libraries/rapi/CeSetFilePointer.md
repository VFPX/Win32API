<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeSetFilePointer
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function moves the file pointer of an open file.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
DWORD CeSetFilePointer(
  HANDLE hFile,
  LONG lDistanceToMove,
  PLONG lpDistanceToMoveHigh,
  DWORD dwMoveMethod
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeSetFilePointer IN rapi;
	INTEGER hFile,;
	LONG    lDistanceToMove,;
	LONG    lpDistanceToMoveHigh,;
	INTEGER dwMoveMethod
  
```  
***  


## Parameters:
```txt  
hFile
[in] Handle to the file whose file pointer is to be moved.

lDistanceToMove
[in] Low-order 32 bits of a signed value that specifies the number of bytes to move the file pointer.

lpDistanceToMoveHigh
[in] Pointer to the high-order 32 bits of the signed 64-bit distance to move.

dwMoveMethod
[in] Specifies the starting point for the file pointer move: bof, current, eof.  
```  
***  


## Return value:
The low-order DWORD of the new file pointer indicates success and that lpDistanceToMoveHigh is NULL.  
***  

