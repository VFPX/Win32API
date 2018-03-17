<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetErrorMode
Group: Error Handling - Library: kernel32    
***  


#### Controls whether the system will handle the specified types of serious errors, or whether the process will handle them.
***  


## Code examples:
[Using the SetErrorMode for determining if a floppy drive is ready](../../samples/sample_227.md)  

## Declaration:
```foxpro  
UINT SetErrorMode(
  UINT uMode   // process error mode
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetErrorMode IN kernel32;
	INTEGER uMode  
```  
***  


## Parameters:
```txt  
uMode
[in] Specifies the process error mode.  
```  
***  


## Return value:
The return value is the previous state of the error-mode bit flags.   
***  


## Comments:
See also: GetErrorMode   
  
***  

