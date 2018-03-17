<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetProcessHeaps
Group: Memory Management - Library: kernel32    
***  


#### The GetProcessHeaps function obtains handles to all of the heaps that are valid for the calling process.
***  


## Code examples:
[Obtaining heap handles and enumerating memory blocks for the current VFP session (WinNT only)](../../samples/sample_176.md)  

## Declaration:
```foxpro  
DWORD GetProcessHeaps(
  DWORD NumberOfHeaps,  //max.number of heap handles
  PHANDLE ProcessHeaps  //buffer for heap handles
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetProcessHeaps IN kernel32;
	INTEGER   NumberOfHeaps,;
	STRING  @ ProcessHeaps  
```  
***  


## Parameters:
```txt  
NumberOfHeaps
[in] Specifies the maximum number of heap handles that can be stored into the buffer pointed to by ProcessHeaps.

ProcessHeaps
[out] Pointer to a buffer to receive an array of heap handles.  
```  
***  


## Return value:
The return value is the number of heap handles that are valid for the calling process.   
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.5 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

