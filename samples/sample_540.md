[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Copying files as a transacted operation (Vista)

## Before you begin:
Windows Vista offers transaction protection for various file operations: create, delete, copy, move and more.  

See also:

* [Displaying standard progress dialog box when copying files](sample_508.md)  
* [Deleting file into the Recycle Bin](sample_321.md)  
  
***  


## Code:
```foxpro  
#DEFINE INVALID_HANDLE_VALUE -1
#DEFINE COPY_FILE_FAIL_IF_EXISTS 0x00000001
#DEFINE COPY_FILE_OPEN_SOURCE_FOR_WRITE 0x00000004

DO declare

LOCAL hTrans
hTrans = CreateTransaction(0, 0, 0, 0, 0, 1000, NULL)
IF hTrans = INVALID_HANDLE_VALUE
	? "CreateTransaction call failed:", GetLastError()
	RETURN
ENDIF

LOCAL cSrc, cDst, nResult
cSrc = "c:\temp\test.txt"
cDst = "c:\temp\test1.txt"

nResult = CopyFileTransacted(cSrc, cDst, 0, 0, 0,;
	BITOR(COPY_FILE_FAIL_IF_EXISTS,;
	COPY_FILE_OPEN_SOURCE_FOR_WRITE),;
	hTrans)
	
IF nResult = 0
	? "CopyFileTransacted call failed:", GetLastError()
	= RollbackTransaction(m.hTrans)
ELSE
	= CommitTransaction(m.hTrans)
ENDIF

= CloseHandle(hTrans)
* end of main

PROCEDURE declare
	DECLARE INTEGER CopyFileTransacted IN kernel32;
		STRING lpExistingFileName, STRING lpNewFileName,;
		INTEGER lpProgressRoutine, INTEGER lpData,;
		INTEGER pbCancel, INTEGER dwCopyFlags,;
		INTEGER hTransaction

	DECLARE INTEGER CloseHandle IN kernel32;
		INTEGER hObject

	DECLARE INTEGER CommitTransaction IN KtmW32;
		INTEGER TransactionHandle

	DECLARE INTEGER RollbackTransaction IN KtmW32;
		INTEGER TransactionHandle

	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER CreateTransaction IN KtmW32;
		INTEGER lpTransactionAttributes, INTEGER UOW,;
		INTEGER CreateOptions, INTEGER IsolationLevel,;
		INTEGER IsolationFlags, INTEGER Timeout,;
		STRING @Description  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CommitTransaction](../libraries/ktmw32/CommitTransaction.md)  
[CopyFileTransacted](../libraries/kernel32/CopyFileTransacted.md)  
[CreateTransaction](../libraries/ktmw32/CreateTransaction.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[RollbackTransaction](../libraries/ktmw32/RollbackTransaction.md)  
