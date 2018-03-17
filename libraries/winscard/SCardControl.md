<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SCardControl
Group: Authentication - Library: winscard    
***  


#### The SCardControl function gives you direct control of the reader by sending specific control codes optionally accompanied with supporting input data.
***  


## Declaration:
```foxpro  
LONG SCardControl(
  __in   SCARDHANDLE hCard,
  __in   DWORD dwControlCode,
  __in   LPCVOID lpInBuffer,
  __in   DWORD nInBufferSize,
  __out  LPVOID lpOutBuffer,
  __in   DWORD nOutBufferSize,
  __out  LPDWORD lpBytesReturned
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardControl IN Winscard;
	INTEGER hCard,;
	LONG dwControlCode,;
	STRING lpInBuffer,;
	LONG nInBufferSize,;
	STRING @lpOutBuffer,;
	LONG nOutBufferSize,;
	LONG @lpBytesReturned  
```  
***  


## Parameters:
```txt  
hCard [in]
Reference value returned from SCardConnect.

dwControlCode [in]
Control code for the operation. This value identifies the specific operation to be performed.

lpInBuffer [in]
Pointer to a buffer that contains the data required to perform the operation.

nInBufferSize [in]
Size, in bytes, of the buffer pointed to by lpInBuffer.

lpOutBuffer [out]
Pointer to a buffer that receives the operation"s output data.

nOutBufferSize [in]
Size, in bytes, of the buffer pointed to by lpOutBuffer.

lpBytesReturned [out]
Pointer to a DWORD that receives the size, in bytes, of the data stored into the buffer pointed to by lpOutBuffer.  
```  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:
You can call it any time after a successful call to SCardConnect and before a successful call to SCardDisconnect. The effect on the state of the reader depends on the control code.  
  
***  

