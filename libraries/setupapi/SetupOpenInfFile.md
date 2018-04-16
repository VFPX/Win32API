[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetupOpenInfFile
Group: [Setup API functions](../../functions_group.md#Setup_API_functions)  -  Library: [setupapi](../../Libraries.md#setupapi)  
***  


#### The SetupOpenInfFile function opens an INF file and returns a handle to it.
***  


## Code examples:
[Listing INF files in a specified directory](../../samples/sample_169.md)  

## Declaration:
```foxpro  
HINF SetupOpenInfFile(
  PCTSTR FileName, // name of the INF to open
  PCTSTR InfClass, // optional, the class of the INF file
  DWORD InfStyle,  // specifies the style of the INF file
  PUINT ErrorLine  // optional, receives error information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetupOpenInfFile IN setupapi;
	STRING    FileName,;
	INTEGER   InfClass,;
	INTEGER   InfStyle,;
	INTEGER @ ErrorLine  
```  
***  


## Parameters:
FileName 
Points to a null-terminated string containing the name (and optional path) of the INF file to be opened. 

InfClass 
An optional parameter that points to a null-terminated string containing the class of INF file desired. 

InfStyle 
Specifies the style of INF file to open. 

ErrorLine 
An optional parameter that points to a caller-supplied variable to which this function returns the (1-based) line number where an error occurred during loading of the INF file.   
***  


## Return value:
The function returns a handle to the opened INF file if it is successful. Otherwise, the return value is INVALID_HANDLE_VALUE (-1).   
***  


## Comments:
See: [SetupCloseInfFile](SetupCloseInfFile.md).  
  
***  

