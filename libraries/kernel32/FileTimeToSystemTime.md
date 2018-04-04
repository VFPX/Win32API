[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FileTimeToSystemTime
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FileTimeToSystemTime function converts a file time to system time format.
***  


## Code examples:
[Retrieving list of files on the FTP directory](../../samples/sample_046.md)  
[Downloading files from the FTP server using InternetReadFile](../../samples/sample_063.md)  
[A procedure for setting file times](../../samples/sample_128.md)  
[HOWTO: Use the Win32 API to Access File Dates and Times](../../samples/sample_177.md)  
[Building a tree of subdirectories for a given path using FindFile functions](../../samples/sample_236.md)  
[How to retrieve information about a cache entry (Internet Explorer)](../../samples/sample_332.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  
[How to delete IE cookies, clear IE history and delete files in Temporary Internet Files directory](../../samples/sample_471.md)  
[How to find when the application started](../../samples/sample_534.md)  

## Declaration:
```foxpro  
BOOL FileTimeToSystemTime(
  CONST FILETIME *lpFileTime,  // file time to convert
  LPSYSTEMTIME lpSystemTime    // receives system time
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FileTimeToSystemTime IN kernel32.dll;
	STRING @ lpFileTime,;
	STRING @ lpSystemTime  
```  
***  


## Parameters:
lpFileTime 
[in] Pointer to a FILETIME structure containing the file time to convert to system date and time format. 

lpSystemTime 
[out] Pointer to a SYSTEMTIME structure to receive the converted file time. 
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
FileTime structure contains two DWORDs -- Lo and Hi time. This function converts them into several words within the SYSTEMTIME structure: Year, Month, DayOfWeek, Day, Hour, Minute etc.  
  
Not all file systems can record creation and last access time and not all file systems record them in the same manner. On some FTP restoring file times you may have the last write time only, and creation time, and last access time values empty.  
  
***  

