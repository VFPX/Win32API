[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetComputerName
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the computer name of the current system. This name is established at system startup, when it is initialized from the registry
***  


## Code examples:
[Retrieving local computer and user names](../../samples/sample_041.md)  
[Using mailslots to send messages on the network](../../samples/sample_269.md)  

## Declaration:
```foxpro  
BOOL GetComputerName(
	LPTSTR  lpBuffer,	// address of name buffer
	LPDWORD  nSize 	// address of size of name buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetComputerName IN kernel32;
	STRING  @ lpBuffer,;
	INTEGER @ nSize  
```  
***  


## Parameters:
lpBuffer
Points to a buffer to receive the null-terminated character string containing the computer name. 

nSize
Points to a variable that specifies the maximum size, in characters, of the buffer. This value should be large enough to contain MAX_COMPUTERNAME_LENGTH + 1 characters.  
***  


## Return value:
If the function succeeds, the return value is TRUE and the variable at nSize contains the number of characters copied to the destination buffer  
***  


## Comments:
SYS(0) -- the network machine information -- returns computer name and user name in one string.  
  
***  

