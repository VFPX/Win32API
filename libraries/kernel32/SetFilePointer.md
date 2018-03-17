<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetFilePointer
Group: File Management - Library: kernel32    
***  


#### The SetFilePointer function moves the file pointer of an open file.
***  


## Code examples:
[Using InternetSetFilePointer when resuming interrupted download from the Internet](../../samples/sample_191.md)  

## Declaration:
```foxpro  
DWORD SetFilePointer(
  HANDLE hFile,                // handle to file
  LONG lDistanceToMove,        // bytes to move pointer
  PLONG lpDistanceToMoveHigh,  // bytes to move pointer
  DWORD dwMoveMethod           // starting point
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetFilePointer IN kernel32;
	INTEGER hFile,;
	INTEGER lDistanceToMove,;
	INTEGER lpDistanceToMoveHigh,;
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
[in] Starting point for the file pointer move -- a predefined value.  
```  
***  


## Return value:
If the SetFilePointer function succeeds and lpDistanceToMoveHigh is NULL, the return value is the low-order DWORD of the new file pointer. If lpDistanceToMoveHigh is not NULL, the function returns the low order DWORD of the new file pointer, and puts the high-order DWORD of the new file pointer into the LONG pointed to by that parameter.   
***  


## Comments:
This function stores the file pointer in two LONG values. To work with file pointers that are larger than a single LONG value, it is easier to use the SetFilePointerEx function.  
  
***  

