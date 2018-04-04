[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetComputerNameEx
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetComputerNameEx function retrieves a NetBIOS or DNS name associated with the local computer. The names are established at system startup, when the system reads them from the registry.
***  


## Code examples:
[Retrieving local computer and user names](../../samples/sample_041.md)  

## Declaration:
```foxpro  
BOOL GetComputerNameEx(
  COMPUTER_NAME_FORMAT NameType,
  LPTSTR lpBuffer,
  LPDWORD lpnSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetComputerNameEx IN kernel32;
	INTEGER   NameType,;
	STRING  @ lpBuffer,;
	INTEGER @ lpnSize  
```  
***  


## Parameters:
NameType 
[in] Type of name to retrieve. This parameter is a value from the COMPUTER_NAME_FORMAT enumeration type.

lpBuffer 
[out] Pointer to a buffer that receives a null-terminated string containing the computer name or the cluster virtual server name. 

lpnSize 
[in, out] On input, specifies the size of the buffer.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

