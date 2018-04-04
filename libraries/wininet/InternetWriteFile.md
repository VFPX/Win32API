[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetWriteFile
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Writes data to an open Internet file.
***  


## Code examples:
[Uploading file to the FTP server using InternetWriteFile](../../samples/sample_062.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
BOOL InternetWriteFile(
    HINTERNET hFile,
    LPCVOID lpBuffer,
    DWORD dwNumberOfBytesToWrite,
    LPDWORD lpdwNumberOfBytesWritten
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetWriteFile IN wininet;
	INTEGER   hFile,;
	STRING  @ sBuffer,;
	INTEGER   lNumBytesToWrite,;
	INTEGER @ dwNumberOfBytesWritten  
```  
***  


## Parameters:
hFile
[in] Valid HINTERNET handle returned from a previous call to FtpOpenFile or an HINTERNET handle sent by HttpSendRequestEx.

lpBuffer
[in] Pointer to a buffer that contains the data to be written to the file.

dwNumberOfBytesToWrite
[in] Unsigned long integer value that contains the number of bytes to write to the file.

lpdwNumberOfBytesWritten
[out] Pointer to an unsigned long integer variable that receives the number of bytes written to the buffer.  
***  


## Return value:
Returns TRUE if the function succeeds, or FALSE otherwise.  
***  


## Comments:
This function is convenient when you want to store a local file on the FTP copying it as a series of relatively small pieces. In this case you can stop, suspend or abort the process and display its progress using the intervals between sending pieces.  
  
***  

