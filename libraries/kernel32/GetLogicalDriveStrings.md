[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetLogicalDriveStrings
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetLogicalDriveStrings function fills a buffer with strings that specify valid drives in the system
***  


## Code examples:
[Using the GetLogicalDriveStrings](../../samples/sample_017.md)  
[Retrieving information about MS-DOS device names using QueryDosDevice (WinNT only)](../../samples/sample_241.md)  
[Using File Mapping for enumerating files opened by Visual FoxPro](../../samples/sample_473.md)  

## Declaration:
```foxpro  
DWORD GetLogicalDriveStrings(
  DWORD nBufferLength,  // size of buffer
  LPTSTR lpBuffer       // drive strings buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetLogicalDriveStrings IN kernel32;
As "GetLogicalDriveStringsA";
	INTEGER  nBufferLength,;
	STRING @ lpBuffer As String
  
```  
***  


## Parameters:
nBufferLength 
[in] Specifies the maximum size, in characters, of the buffer pointed to by lpBuffer

lpBuffer 
[out] Pointer to a buffer that receives a series of null-terminated strings, one for each valid drive in the system, that end with a second null character  
***  


## Return value:
If the function succeeds, the return value is the length, in characters, of the strings copied to the buffer  
***  

