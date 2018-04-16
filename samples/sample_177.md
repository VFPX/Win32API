[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# HOWTO: Use the Win32 API to Access File Dates and Times

## Before you begin:
This sample code originates from [HOWTO: Use the Win32 API to Access File Dates and Times](https://jeffpar.github.io/kbarchive/kb/188/Q188977/)  

Unfortunately two regrettable errors make the original code unusable: missing @ character in GetFileTime call, and **hex2dec** function, never being tested I guess. So I was bold enough to make some fixes to it:  
  
***  


## Code:
```foxpro  
*********************************************************
* Function getftime
* Return the create date and time, last access date and time,
* last write date and time from a passed filename.
*
* Passed:
* lcFileName (by value): fully-qualified filename
*
* Returns:
* Logical .t. if completed successfully, .f. if not.
*
* Return variables:
* ldCreateDate (date, by reference): Creation date
* lcCreateTime (character, by reference): Creation time (HH:MM:SS.mm)
* ldAccessDate (date, by reference): Last access date
* lcAccessTime (character, by reference): Last access time (HH:MM:SS.mm)
* lcLastWriteDate (date, by reference): Last write date
* lcLastWriteTime (character, by reference): Last write time (HH:MM:SS.mm)

STORE {} TO m.createdate, m.accessdate, m.lastwritedate
STORE "" TO m.createtime, m.accesstime, m.lastwritetime

m.OK = getftime("C:\Test.txt", @m.createdate, @m.createtime, ;
	@m.accessdate, @m.accesstime, @m.lastwritedate, @m.lastwritetime)

IF m.OK
	? "Create date:      ", m.createdate
	? "Create time:      " , m.createtime
	? "Last access date: ", m.accessdate
	? "Last access time: ", m.accesstime
	? "Last write date:  ", m.lastwritedate
	? "Last write time:  ", m.lastwritetime
ELSE
	? "Error getting file times"
ENDIF
* End of usage example.

FUNCTION getftime
PARAMETERS lcFileName, ldCreateDate, lcCreateTime, ldAccessDate,;
	lcAccessTime, ldLastWriteDate, lcLastWriteTime

* DEFINEs for file share mode.
#DEFINE FILE_SHARE_READ  1
#DEFINE FILE_SHARE_WRITE 2

* DEFINEs for access right
 #DEFINE GENERIC_READ  hex2dec("80000000")
 #DEFINE GENERIC_WRITE hex2dec("40000000")

* DEFINES for Create Mode.
#DEFINE CREATE_NEW  1
#DEFINE CREATE_ALWAYS 2
#DEFINE OPEN_EXISTING 3
#DEFINE OPEN_ALWAYS 4
#DEFINE TRUNCATE_EXISTING 5

* File flag.
#DEFINE FILE_ATTRIBUTE_NORMAL hex2dec("80")

	* Blank filename or nonexistent file, no need to continue.
	IF EMPTY(lcFileName) OR NOT FILE(lcFileName)
		RETURN .F.
	ENDIF

	DECLARE INTEGER CreateFile IN kernel32;
		STRING lpFileName, INTEGER dwDesiredAccess,;
		INTEGER dwShareMode, INTEGER lpSecurityAttributes,;
		INTEGER dwCreationDisposition,;
		INTEGER dwFlagsAndAttributes, INTEGER hTemplateFile

	DECLARE INTEGER GetFileTime IN kernel32;
		INTEGER hFile, STRING @lpCreationTime,;
		STRING @lpLastAccessTime, STRING @lpLastWriteTime

	DECLARE INTEGER FileTimeToLocalFileTime IN kernel32;
		STRING @lpFileTime, STRING @lpLocalFileTime

	DECLARE INTEGER FileTimeToSystemTime IN kernel32;
		STRING @lpFileTime, STRING @lpSystemTime

	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	* 2 DWORDs * 4 bytes each = an 8-byte buffer.
	STORE SPACE(8) TO CreationTime, LastAccessTime, lastwritetime

	* Same buffers for local time.
	STORE SPACE(8) TO LocalCreationTime,;
		LocalLastAccessTime, LocalLastWriteTime

	* 16-byte buffers for when we convert from the FILETIME
	* structs to the more human-readable SYSTEMTIME structures.
	STORE SPACE(16) TO ctSystemTime, laSystemTime, lwSystemTime

	* Open an existing file.
	lhFileHandle = CreateFile(lcFileName, GENERIC_READ,;
		FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0)

	IF lhFileHandle <= 0
		=MESSAGEB ("Error in CreateFile - " + lcFileName + ": Error code - " + ;
			LTRIM(STR(GetLastError())))
		RETURN .F.
	ENDIF

	* Make the GetFileTime call, to get Create, Access and Update times.
	m.retval = GetFileTime (lhFileHandle,;
		@CreationTime, @LastAccessTime, @lastwritetime)

	IF m.retval = 0
	* 32 = Sharing violation
	* 87 = Invalid parameter
		=MESSAGEB("Error calling GetFileTime. Error code: " + ;
			LTRIM(STR(GetLastError())))
		RETURN .F.
	ENDIF

* Successfully performed the GetFileTime call -
* now convert each of the three times to local time.
* If any of them fail, then exit.
	IF     FileTimeToLocalFileTime (@CreationTime, @LocalCreationTime) = 0;
		OR FileTimeToLocalFileTime (@LastAccessTime,@LocalLastAccessTime) = 0;
		OR FileTimeToLocalFileTime (@lastwritetime, @LocalLastWriteTime) = 0

		= MESSAGEB("FileTimeToLocalFileTime Failed. Error code: " + ;
			LTRIM(STR(GetLastError())))
		RETURN .F.
	ENDIF

* Now you have a local filetime, convert each to a systemtime that
* you can work with.
* If any of the calls fail, then exit.
	IF     FileTimeToSystemTime (@LocalCreationTime, @ctSystemTime) = 0;
		OR FileTimeToSystemTime (@LocalLastAccessTime, @laSystemTime) = 0;
		OR FileTimeToSystemTime (@LocalLastWriteTime, @lwSystemTime) = 0

		= MESSAGEB("FileTimeToSystemTime call failed. Error code: " ;
			+ LTRIM(STR(GetLastError())))
		RETURN .F.
	ENDIF

	ctstYear = Str2Word(LEFT(ctSystemTime, 2))
	ctstMonth = Str2Word(SUBSTR(ctSystemTime, 3, 2))
	ctstDayofWeek = Str2Word(SUBSTR(ctSystemTime, 5, 2))
	ctstDay = Str2Word(SUBSTR(ctSystemTime, 7, 2))
	ctstHour = Str2Word(SUBSTR(ctSystemTime, 9, 2))
	ctstMinute = Str2Word(SUBSTR(ctSystemTime, 11, 2))
	ctstSecond = Str2Word(SUBSTR(ctSystemTime, 13, 2))
	ctstMilliSecond = Str2Word(SUBSTR(ctSystemTime, 15, 2))

* Unpack the integers in last access time SystemTime structure.
	lastYear = Str2Word(LEFT(laSystemTime, 2))
	lastMonth = Str2Word(SUBSTR(laSystemTime, 3, 2))
	lastDayofWeek = Str2Word(SUBSTR(laSystemTime, 5, 2))
	lastDay = Str2Word(SUBSTR(laSystemTime, 7, 2))
	lastHour = Str2Word(SUBSTR(laSystemTime, 9, 2))
	lastMinute = Str2Word(SUBSTR(laSystemTime, 11, 2))
	lastSecond = Str2Word(SUBSTR(laSystemTime, 13, 2))
	lastMilliSecond = Str2Word(SUBSTR(laSystemTime, 15, 2))

* Unpack the integers in last write time SystemTime structure.
	lwstYear = Str2Word(LEFT(lwSystemTime, 2))
	lwstMonth = Str2Word(SUBSTR(lwSystemTime, 3, 2))
	lwstDayofWeek = Str2Word(SUBSTR(lwSystemTime, 5, 2))
	lwstDay = Str2Word(SUBSTR(lwSystemTime, 7, 2))
	lwstHour = Str2Word(SUBSTR(lwSystemTime, 9, 2))
	lwstMinute = Str2Word(SUBSTR(lwSystemTime, 11, 2))
	lwstSecond = Str2Word(SUBSTR(lwSystemTime, 13, 2))
	lwstMilliSecond = Str2Word(SUBSTR(lwSystemTime, 15, 2))

* Close the file handle.
	llRetCode = CloseHandle(lhFileHandle)

* Format the return variables.
	ldCreateDate = CTOD(LTRIM(STR(ctstMonth)) + "/" + ;
		LTRIM(STR(ctstDay)) + "/" + LTRIM(STR(ctstYear)))

	lcCreateTime = PADL(LTRIM(STR(ctstHour)), 2, "0") + ":" + ;
		PADL(LTRIM(STR(ctstMinute)), 2, "0") + ":" + ;
		PADL(LTRIM(STR(ctstSecond)), 2, "0") + "." + ;
		PADL(LTRIM(STR(ctstMilliSecond)), 3, "0")

	ldAccessDate = CTOD(LTRIM(STR(lastMonth)) + "/" + ;
		LTRIM(STR(lastDay)) + "/" + LTRIM(STR(lastYear)))

	lcAccessTime = PADL(LTRIM(STR(lastHour)), 2, "0") + ":" + ;
		PADL(LTRIM(STR(lastMinute)), 2, "0") + ":" + ;
		PADL(LTRIM(STR(lastSecond)), 2, "0") + "." + ;
		PADL(LTRIM(STR(lastMilliSecond)), 3, "0")

	ldLastWriteDate = CTOD(LTRIM(STR(lwstMonth))+ ;
		"/"+LTRIM(STR(lwstDay)) + "/" + LTRIM(STR(lwstYear)))

	lcLastWriteTime = PADL(LTRIM(STR(lwstHour)), 2, "0") + ":" + ;
		PADL(LTRIM(STR(lwstMinute)), 2, "0") + ":" + ;
		PADL(LTRIM(STR(lwstSecond)), 2, "0") + "." + ;
		PADL(LTRIM(STR(lwstMilliSecond)), 3, "0")

* Function hex2dec - Convert a character hex value into decimal.
* Handy for dealing with Hex declarations in API calls.
* Passed: m.hex (character hex value)
* Returns: Decimal value
FUNCTION hex2dec
PARAMETER m.hex
	m.decimal = 0
	FOR i = LEN(m.hex) TO 1 STEP -1
		m.decimal = m.decimal + (AT(SUBSTR(m.hex, i, 1), ;
			"0123456789ABCDEF") - 1) * 16 ^ (LEN(m.hex) - i)
	NEXT
RETURN m.decimal

* Function str2word - Converts low-high format string representation
* to a 16-bit integer (word) value. Useful for unrolling structure
* members containg WORD types.
*
* Passed: Low-high string representation of 16-bit integer
* Returns: numeric value
FUNCTION Str2Word
PARAMETERS m.wordstr
	PRIVATE i, m.retval

	m.retval = 0
	FOR i = 0 TO 8 STEP 8
		m.retval = m.retval + (ASC(m.wordstr) * (2^i))
		m.wordstr = RIGHT(m.wordstr, LEN(m.wordstr) - 1)
	NEXT
RETURN m.retval  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[FileTimeToLocalFileTime](../libraries/kernel32/FileTimeToLocalFileTime.md)  
[FileTimeToSystemTime](../libraries/kernel32/FileTimeToSystemTime.md)  
[GetFileTime](../libraries/kernel32/GetFileTime.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  

## Comment:
It seems that calling MODIFY FILE in VFP6 completely removes the previous file state, because the file creation time changes to become equivalent to the last write time. This is in contrast to the Notepad editing, which preserves the original creation datetime value.  
  
FoxPro ADIR() function places information about files into an array and then returns the number of files. It returns only date and time the file was last modified.  
  
In C# version, I use managed FileInfo object instead of accessing file times through the System.Runtime.InteropServices namespace.  
  
***  

