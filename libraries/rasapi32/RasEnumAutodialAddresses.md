[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RasEnumAutodialAddresses
Group: [Remote Access Service (RAS)](../../functions_group.md#Remote_Access_Service_(RAS))  -  Library: [rasapi32](../../Libraries.md#rasapi32)  
***  


#### The RasEnumAutodialAddresses function returns a list of all addresses in the AutoDial mapping database.
***  


## Code examples:
[List of addresses in the AutoDial mapping database](../../samples/sample_330.md)  

## Declaration:
```foxpro  
DWORD RasEnumAutodialAddresses(
  LPTSTR *lppAddresses,    // pointer to buffer that
                           //  receives network address strings
  LPDWORD lpdwcbAddresses, // pointer to size, in bytes,
                           //  of the buffer
  LPDWORD lpdwcAddresses   // pointer to number of strings returned
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RasEnumAutodialAddresses IN rasapi32;
	STRING  @ lppAddresses,;
	INTEGER @ lpdwcbAddresses,;
	INTEGER @ lpdwcAddresses
  
```  
***  


## Parameters:
lppAddresses 
[in, out] Pointer to an array of string pointers, with additional space for the storage of the strings themselves at the end of the buffer. 

lpdwcbAddresses 
[in, out] Pointer to a variable that, on input, contains the size, in bytes, of the buffer specified by the lppAddresses parameter. 

lpdwcAddresses 
[out] Pointer to a variable that receives the number of address strings returned in the lppAddresses buffer.   
***  


## Return value:
If the function succeeds, the return value is zero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

