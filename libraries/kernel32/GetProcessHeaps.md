[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetProcessHeaps
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
NumberOfHeaps 
[in] Specifies the maximum number of heap handles that can be stored into the buffer pointed to by ProcessHeaps. 

ProcessHeaps 
[out] Pointer to a buffer to receive an array of heap handles.   
***  


## Return value:
The return value is the number of heap handles that are valid for the calling process.   
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.5 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

