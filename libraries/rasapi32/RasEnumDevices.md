[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RasEnumDevices
Group: [Remote Access Service (RAS)](../../functions_group.md#Remote_Access_Service_(RAS))  -  Library: [rasapi32](../../Libraries.md#rasapi32)  
***  


#### The RasEnumDevices function returns the name and type of all available RAS-capable devices.
***  


## Code examples:
[Retrieving the name and type of all available RAS-capable devices](../../samples/sample_325.md)  

## Declaration:
```foxpro  
DWORD RasEnumDevices(
  LPRASDEVINFO lpRasDevInfo,  // buffer to receive
                              //  information about RAS devices
  LPDWORD lpcb,               // size, in bytes, of the buffer
  LPDWORD lpcDevices          // receives the number of
                              //  entries written to the buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RasEnumDevices IN rasapi32;
	STRING  @ lpRasDevInfo,;
	INTEGER @ lpcb,;
	INTEGER @ lpcDevices  
```  
***  


## Parameters:
lpRasDevInfo 
[in] Pointer to a buffer that receives an array of RASDEVINFO structures, one for each RAS-capable device.

lpcb 
[in, out] Pointer to a variable that, on input, contains the size, in bytes, of the lpRasDevInfo buffer. 

lpcDevices 
[out] Pointer to a variable that receives the number of RASDEVINFO structures written to the lpRasDevInfo buffer.   
***  


## Return value:
If the function succeeds, the return value is zero.  
***  

