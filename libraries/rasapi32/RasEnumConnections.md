[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RasEnumConnections
Group: [Remote Access Service (RAS)](../../functions_group.md#Remote_Access_Service_(RAS))  -  Library: [rasapi32](../../Libraries.md#rasapi32)  
***  


#### The RasEnumConnections function lists all active RAS connections. It returns each connection"s handle and phone-book entry name. 
***  


## Code examples:
[Retrieving list of all active RAS connections](../../samples/sample_326.md)  

## Declaration:
```foxpro  
DWORD RasEnumConnections(
  LPRASCONN lprasconn,   // buffer to receive connections data
  LPDWORD lpcb,          // size in bytes of buffer
  LPDWORD lpcConnections // number of connections written to buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RasEnumConnections IN rasapi32;
	STRING  @ lprasconn,;
	INTEGER @ lpcb,;
	INTEGER @ lpcConnections
  
```  
***  


## Parameters:
lprasconn 
[in, out] Pointer to a buffer that receives, on output, an array of RASCONN structures, one for each RAS connection. 

lpcb 
[in, out] Pointer to a variable that, on input, contains the size, in bytes, of the buffer specified by lprasconn. 

lpcConnections 
[out] Pointer to a variable that receives the number of RASCONN structures written to the buffer specified by lprasconn.   
***  


## Return value:
If the function succeeds, the return value is zero.  
***  

