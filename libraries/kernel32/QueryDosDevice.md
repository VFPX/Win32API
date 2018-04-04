[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : QueryDosDevice
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves information about MS-DOS device names.
***  


## Code examples:
[Retrieving information about MS-DOS device names using QueryDosDevice (WinNT only)](../../samples/sample_241.md)  
[Using File Mapping for enumerating files opened by Visual FoxPro](../../samples/sample_473.md)  

## Declaration:
```foxpro  
DWORD QueryDosDevice(
  LPCTSTR lpDeviceName, // MS-DOS device name string
  LPTSTR lpTargetPath,  // query results buffer
  DWORD ucchMax         // maximum size of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER QueryDosDevice IN kernel32;
	INTEGER   lpDeviceName,;
	STRING  @ lpTargetPath,;
	INTEGER   ucchMax  
```  
***  


## Parameters:
lpDeviceName 
[in] Pointer to an MS-DOS device name string specifying the target of the query. 

lpTargetPath 
[out] Pointer to a buffer that will receive the result of the query. 

ucchMax 
[in] Specifies the maximum number of TCHARs that can be stored into the buffer pointed to by lpTargetPath.   
***  


## Return value:
If the function succeeds, the return value is the number of TCHARs stored into the buffer pointed to by lpTargetPath.   
***  


## Comments:
Windows 98/Me: QueryDosDeviceW is supported by the Microsoft Layer for Unicode. To use this, you must add certain files to your application.  
  
***  

