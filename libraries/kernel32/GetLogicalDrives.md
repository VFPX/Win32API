<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetLogicalDrives
Group: File System - Library: kernel32    
***  


#### The GetLogicalDrives function retrieves a bitmask representing the currently available disk drives
***  


## Code examples:
[Retrieving list of available disk drives](../../samples/sample_013.md)  
[Disconnecting USB Mass Storage Device programmatically](../../samples/sample_553.md)  

## Declaration:
```foxpro  
DWORD GetLogicalDrives(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetLogicalDrives IN kernel32  
```  
***  


## Parameters:
```txt  
This function has no parameters  
```  
***  


## Return value:
If the function succeeds, the return value is a bitmask representing the currently available disk drives. Bit position 0 (the least-significant bit) is drive A, bit position 1 is drive B, bit position 2 is drive C, and so on  
***  

