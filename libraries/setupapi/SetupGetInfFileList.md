[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetupGetInfFileList
Group: [Setup API functions](../../functions_group.md#Setup_API_functions)  -  Library: [setupapi](../../Libraries.md#setupapi)  
***  


#### Returns a list of INF files located in a caller-specified directory to a call-supplied buffer.
***  


## Code examples:
[Listing INF files in a specified directory](../../samples/sample_169.md)  

## Declaration:
```foxpro  
BOOL SetupGetInfFileList(
  PCTSTR DirectoryPath,    // optional, the directory path
  DWORD InfStyle,          // style of the INF file
  PTSTR ReturnBuffer,      // optional, receives the file list
  DWORD ReturnBufferSize,  // size of the supplied buffer
  PDWORD RequiredSize      // optional, buffer size needed
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetupGetInfFileList IN setupapi;
	STRING    DirectoryPath,;
	INTEGER   InfStyle,;
	STRING  @ ReturnBuffer,;
	INTEGER   ReturnBufferSize,;
	INTEGER @ RequiredSize  
```  
***  


## Parameters:
DirectoryPath 
An optional parameter that points to a null-terminated string containing the path of the directory in which to search. If this value is NULL, the %windir%\inf directory is used. 

InfStyle 
Specifies the style of INF file to search for. 

ReturnBuffer 
If not NULL, points to a caller-supplied buffer in which this function returns the list of all INF files of the desired style(s) that were found in the specified subdirectory. 

ReturnBufferSize 
Specifies the size of the buffer pointed to by the ReturnBuffer parameter. 

RequiredSize 
If not NULL, points to a caller-supplied variable in which this function returns the required size for the buffer pointed to by the ReturnBuffer parameter.   
***  


## Return value:
If the function succeeds, the return value is a non-zero value. If the function fails, the return value is zero.   
***  


## Comments:
Under WinMe this function returns -- to my experience -- only a small part of INF files existing in a directory.  
  
***  

