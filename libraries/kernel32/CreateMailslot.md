<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CreateMailslot
Group: Mailslot - Library: kernel32    
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
```txt  
lpName
[in] Pointer to a null-terminated string specifying the name of the mailslot.

nMaxMessageSize
[in] Specifies the maximum size, in bytes, of a single message that can be written to the mailslots.

lReadTimeout
[in] Specifies the amount of time, in milliseconds, a read operation can wait for a message to be written to the mailslot before a time-out occurs.

lpSecurityAttributes
[in] Pointer to a SECURITY_ATTRIBUTES structure.  
```  
***  


## Return value:
If the function succeeds, the return value is a handle to the mailslot, for use in server mailslot operations.   
***  


## Comments:
The mailslot exists until one of the following conditions is true:  
<LI>The last (possibly inherited or duplicated) handle to it is closed using the CloseHandle function.  
<LI>The process owning the last (possibly inherited or duplicated) handle exits.  
  
The system uses the second method to destroy mailslots.   
  
***  

