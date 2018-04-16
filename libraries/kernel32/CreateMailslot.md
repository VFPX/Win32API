[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateMailslot
Group: [Mailslot](../../functions_group.md#Mailslot)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The CreateMailslot function creates a mailslot with the specified name and returns a handle that a mailslot server can use to perform operations on it. 
***  


## Code examples:
[Creating a mailslot](../../samples/sample_267.md)  
[Peer-to-peer LAN messenger built with Mailslot API functions](../../samples/sample_410.md)  

## Declaration:
```foxpro  
HANDLE CreateMailslot(
  LPCTSTR lpName,                 // mailslot name
  DWORD nMaxMessageSize,          // maximum message size
  DWORD lReadTimeout,             // read time-out interval
  LPSECURITY_ATTRIBUTES lpSecAttr // inheritance option
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateMailslot IN kernel32;
	STRING  lpName,;
	INTEGER nMaxMessageSize,;
	INTEGER lReadTimeout,;
	INTEGER lpSecurityAttributes  
```  
***  


## Parameters:
lpName 
[in] Pointer to a null-terminated string specifying the name of the mailslot. 

nMaxMessageSize 
[in] Specifies the maximum size, in bytes, of a single message that can be written to the mailslots. 

lReadTimeout 
[in] Specifies the amount of time, in milliseconds, a read operation can wait for a message to be written to the mailslot before a time-out occurs. 

lpSecurityAttributes 
[in] Pointer to a SECURITY_ATTRIBUTES structure.   
***  


## Return value:
If the function succeeds, the return value is a handle to the mailslot, for use in server mailslot operations.   
***  


## Comments:
The mailslot exists until one of the following conditions is true:  
* The last (possibly inherited or duplicated) handle to it is closed using the CloseHandle function.  
* The process owning the last (possibly inherited or duplicated) handle exits.  
  
The system uses the second method to destroy mailslots.   
  
***  

