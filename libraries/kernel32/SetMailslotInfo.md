[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetMailslotInfo
Group: [Mailslot](../../functions_group.md#Mailslot)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The SetMailslotInfo function sets the time-out value used by the specified mailslot for a read operation. 
***  


## Code examples:
[Creating a mailslot](../../samples/sample_267.md)  

## Declaration:
```foxpro  
BOOL SetMailslotInfo(
  HANDLE hMailslot,    // mailslot handle
  DWORD lReadTimeout   // read time-out interval
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetMailslotInfo IN kernel32;
	INTEGER hMailslot,;
	INTEGER lReadTimeout  
```  
***  


## Parameters:
hMailslot 
[in] Handle to a mailslot. The CreateMailslot function must create this handle. 

lReadTimeout 
[in] Specifies the amount of time, in milliseconds, a read operation can wait for a message to be written to the mailslot before a time-out occurs.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

