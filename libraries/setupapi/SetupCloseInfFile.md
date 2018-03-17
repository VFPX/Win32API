<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetupCloseInfFile
Group: Setup API functions - Library: setupapi    
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
```txt  
InfHandle
Handle to the INF file to close.  
```  
***  

