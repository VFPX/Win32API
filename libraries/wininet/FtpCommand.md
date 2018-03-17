<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FtpCommand
Group: Internet Functions (WinInet) - Library: wininet    
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
```txt  
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
  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise  
***  


## Comments:
The complete list of service commands can be found in the <a href="http://www.faqs.org/rfcs/rfc765.html">FTP specification</a>.  
  
Wininet has some limitations on this command. Sometimes it returns 12003 error code. Follow two Microsoft links on this subject:  
  
<LI><a href="http://support.microsoft.com/support/kb/articles/Q168/4/92.ASP">PRB: FTP WinInet APIs Report Error 12003</a></LI>  
<LI><a href="http://support.microsoft.com/support/kb/articles/Q255/2/04.ASP">FtpCommand() WinInet Function Stops Responding</a></LI>  
  
***  

