[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpCommand
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Sends commands directly to an FTP server.
***  


## Code examples:
[Using FtpCommand](../../samples/sample_059.md)  

## Declaration:
```foxpro  
BOOL FtpCommand(
    HINTERNET hConnect,
    BOOL fExpectResponse,
    DWORD dwFlags,
    LPCTSTR lpszCommand,
    DWORD_PTR dwContext,
    HINTERNET *phFtpCommand
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpCommand IN wininet;
	INTEGER   hConnect,;
	INTEGER   fExpectResponse,;
	INTEGER   dwFlags,;
	STRING    lpszCommand,;
	STRING  @ dwContext,;
	INTEGER @ phFtpCommand
  
```  
***  


## Parameters:
hConnect
[in] HINTERNET handle returned from a call to InternetConnect

fExpectResponse
[in] BOOLvalue that indicates whether or not the application expects a response from the FTP server

dwFlags
[in] Unsigned long integer value that contains the flags that control this function

lpszCommand
[in] Pointer to a string value that contains the command to send to the FTP server

dwContext
[in] Pointer to an unsigned long integer value that contains an application-defined value 

phFtpCommand
[out] Pointer to an HINTERNET handle that will be created if a valid data socket is opened
  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise  
***  


## Comments:
The complete list of service commands can be found in the [FTP specification](http://www.faqs.org/rfcs/rfc765.html).  
  

***  

