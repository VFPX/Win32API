[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetupGetInfInformation
Group: [Setup API functions](../../functions_group.md#Setup_API_functions)  -  Library: [setupapi](../../Libraries.md#setupapi)  
***  


#### Returns the SP_INF_INFORMATION structure for the specified INF file to a caller-supplied buffer.

***  


## Code examples:
[Returning some basic information for the specified INF file](../../samples/sample_123.md)  

## Declaration:
```foxpro  
BOOL SetupGetInfInformation(
  LPCVOID InfSpec,         // handle or filename of the INF file
  DWORD SearchControl,     // how to search for the INF file
  PSP_INF_INFORMATION ReturnBuffer,
                           // optional, receives the INF info
  DWORD ReturnBufferSize,  // size of the supplied buffer
  PDWORD RequiredSize      // optional, buffer size needed
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SetupGetInfInformation IN Setupapi;
	STRING    InfSpec,;
	INTEGER   SearchControl,;
	STRING  @ ReturnBuffer,;
	INTEGER   ReturnBufferSize,;
	INTEGER @ RequiredSize  
```  
***  


## Parameters:
InfSpec 
A handle or a filename for an INF file, depending on the value of SearchControl. 

SearchControl 
This parameter is a constant (see an example to this function)

ReturnBuffer 
If not NULL, ReturnBuffer points to a caller-supplied buffer in which this function returns the SP_INF_INFORMATION structure. 

ReturnBufferSize 
Size of the ReturnBuffer in bytes. 

RequiredSize 
If not NULL, points to a caller-supplied variable in which this function returns the required size, in bytes, for the buffer pointed to by ReturnBuffer.  
***  


## Return value:
If the function succeeds, the return value is a non-zero value. If the function fails, the return value is zero. 
  
***  

