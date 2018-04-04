[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : Process32Next
Group: [Performance Monitoring](../../functions_group.md#Performance_Monitoring)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves information about the next process recorded in a system snapshot.
***  


## Code examples:
[Enumerating Processes -- Win9*](../../samples/sample_164.md)  

## Declaration:
```foxpro  
BOOL WINAPI Process32Next(
  HANDLE hSnapshot,
  LPPROCESSENTRY32 lppe
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER Process32Next IN kernel32;
	INTEGER hSnapshot,;
	STRING @ lppe  
```  
***  


## Parameters:
hSnapshot 
[in] Handle to the snapshot returned from a previous call to the CreateToolhelp32Snapshot function. 

lppe 
[out] Pointer to a PROCESSENTRY32 structure.  
***  


## Return value:
Returns TRUE if the next entry of the process list has been copied to the buffer or FALSE otherwise.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows 2000 and later.  
Windows 95/98/Me: Included in Windows 95 and later.  
  
***  

