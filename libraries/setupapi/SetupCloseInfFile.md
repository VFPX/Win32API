[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetupCloseInfFile
Group: [Setup API functions](../../functions_group.md#Setup_API_functions)  -  Library: [setupapi](../../Libraries.md#setupapi)  
***  


#### Closes the INF file opened by a call to SetupOpenInfFile and any INF files appended to it by SetupOpenAppendInfFile.
***  


## Code examples:
[Listing INF files in a specified directory](../../samples/sample_169.md)  

## Declaration:
```foxpro  
VOID SetupCloseInfFile(
  HINF InfHandle  // handle to the INF file to close
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SetupCloseInfFile IN setupapi;
	INTEGER InfHandle  
```  
***  


## Parameters:
InfHandle 
Handle to the INF file to close.   
***  

