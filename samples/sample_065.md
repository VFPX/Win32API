[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Setting the date and time that a file was created

## Code:
```foxpro  
#DEFINE OF_READ 0
#DEFINE OF_WRITE 1
DO declare

* create buffers for structures
lcFileTime = REPLICATE(CHR(0), 8)  && FILETIME
lcSystemTime = REPLICATE(CHR(0), 16)  && SYSTEMTIME

* retrive the system time and convert it to the file time format
*= GetSystemTime (@lcSystemTime)
*= SystemTimeToFileTime (@lcSystemTime, @lcFileTime)

* same but using a shorter way
= GetSystemTimeAsFileTime(@lcFileTime)

* open file before modifying its time and date
lcFile = "c:\temp\temp.txt"    && use valid file name
lcBuff = REPLICATE(CHR(0), 250)  && a buffer for OFSTRUCT structure
hFile = OpenFile(lcFile, @lcBuff, OF_WRITE)

IF hFile > 0
	* usage: SetFileTime(hFile, <creation>, <lastaccess>, <lastwrite>)
	* replace with zeros those datetime parameters you want to keep unchanged
	* so the following call is about to change only the creation datetime

	IF SetFileTime(hFile, @lcFileTime, 0, 0) = 0
		? "SetFileTime failed with error:", GetLastError()
	ELSE
		? "Ok!"
	ENDIF

	= CloseHandle(hFile)
ELSE
	* 2=ERROR_FILE_NOT_FOUND
	* 3=ERROR_PATH_NOT_FOUND
	* 5=ERROR_ACCESS_DENIED
	? "OpenFile failed with error:", GetLastError()
ENDIF
* end of main

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject
	DECLARE GetSystemTime IN kernel32 STRING @lpSystemTime

	DECLARE GetSystemTimeAsFileTime IN kernel32;
		STRING @lpSystemTimeAsFileTime

	DECLARE INTEGER SystemTimeToFileTime IN kernel32;
		STRING @ lpSystemTime, STRING @ lpFileTime

	DECLARE INTEGER SetFileTime IN kernel32;
		INTEGER hFile, STRING @lpCreationTime,;
		STRING @lpLastAccessTime, STRING @lpLastWriteTime

	DECLARE INTEGER OpenFile IN kernel32;
		STRING lpFileName, STRING @lpReOpenBuff, INTEGER wStyle  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetSystemTime](../libraries/kernel32/GetSystemTime.md)  
[GetSystemTimeAsFileTime](../libraries/kernel32/GetSystemTimeAsFileTime.md)  
[OpenFile](../libraries/kernel32/OpenFile.md)  
[SetFileTime](../libraries/kernel32/SetFileTime.md)  
[SystemTimeToFileTime](../libraries/kernel32/SystemTimeToFileTime.md)  

## Comment:
The file handle must have been created with GENERIC_WRITE access to the file.   
  
I tried to create the handle by using native FOPEN() function with different attributes. It did not work.  
  
You can change any of three file time values or a combination of them. But not all file systems can record creation and last access time and not all file systems record them in the same manner. This way you can set the creation time to be later than its access and modification times.  
  
* * *  
In C# version, I use managed FileInfo object instead of accessing file times through the System.Runtime.InteropServices namespace.  
  
***  

