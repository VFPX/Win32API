[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetUserNameEx
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [secur32](../../Libraries.md#secur32)  
***  


#### Retrieves the name of the user or other security principal associated with the calling thread. You can specify the format of the returned name.
***  


## Declaration:
```foxpro  
BOOLEAN WINAPI GetUserNameEx(
  __in     EXTENDED_NAME_FORMAT NameFormat,
  __out    LPTSTR lpNameBuffer,
  __inout  PULONG lpnSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetUserNameEx IN secur32;
	INTEGER NameFormat,;
	STRING @lpNameBuffer,;
	LONG @lpnSize  
```  
***  


## Parameters:
NameFormat [in] 
The format of the name. This parameter is a value from the EXTENDED_NAME_FORMAT enumeration type.

lpNameBuffer [out] 
A pointer to a buffer that receives the name in the specified format.

lpnSize [in, out] 
On input, this variable specifies the size of the lpNameBuffer buffer, in TCHARs.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
If the thread is impersonating a client, GetUserNameEx returns the name of the client.  
  
***  

