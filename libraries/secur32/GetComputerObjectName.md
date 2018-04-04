[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetComputerObjectName
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [secur32](../../Libraries.md#secur32)  
***  


#### The GetComputerObjectName function retrieves the local computer"s name in a specified format.
***  


## Code examples:
[Retrieving local computer and user names](../../samples/sample_041.md)  

## Declaration:
```foxpro  
BOOLEAN GetComputerObjectName(
  EXTENDED_NAME_FORMAT NameFormat,
  LPTSTR lpNameBuffer,
  PULONG nSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetComputerObjectName IN secur32;
	INTEGER   NameFormat,;
	STRING  @ lpNameBuffer,;
	INTEGER @ nSize
  
```  
***  


## Parameters:
NameFormat 
[in] Format for the name. This parameter is a value from the EXTENDED_NAME_FORMAT enumeration type.

lpNameBuffer 
[out] Pointer to a buffer that receives the name in the specified format. 

nSize 
[in, out] On input, specifies the size of the lpNameBuffer buffer, in TCHARs.   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
Client: Requires Windows XP or Windows 2000 Professional.  
  
***  

