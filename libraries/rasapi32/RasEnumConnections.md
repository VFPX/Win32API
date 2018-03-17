<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : RasEnumConnections
Group: Remote Access Service (RAS) - Library: rasapi32    
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
```txt  
lprasconn
[in, out] Pointer to a buffer that receives, on output, an array of RASCONN structures, one for each RAS connection.

lpcb
[in, out] Pointer to a variable that, on input, contains the size, in bytes, of the buffer specified by lprasconn.

lpcConnections
[out] Pointer to a variable that receives the number of RASCONN structures written to the buffer specified by lprasconn.  
```  
***  


## Return value:
If the function succeeds, the return value is zero.  
***  

