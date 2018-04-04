[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLInstallerError
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbccp32](../../Libraries.md#odbccp32)  
***  


#### SQLInstallerError returns error or status information for the ODBC installer functions.
***  


## Code examples:
[How to display a dialog box with which the user can add a data source (DSN)](../../samples/sample_380.md)  
[Adding an ODBC data source with the SQLConfigDataSource; use automatic or interactive mode](../../samples/sample_381.md)  

## Declaration:
```foxpro  
RETCODE SQLInstallerError(
	WORD iError,
	DWORD * pfErrorCode,
	LPSTR lpszErrorMsg,
	WORD cbErrorMsgMax,
	WORD * pcbErrorMsg
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SQLInstallerError IN odbccp32;
	INTEGER   iError,;
	INTEGER @ pfErrorCode,;
	STRING  @ lpszErrorMsg,;
	INTEGER   cbErrorMsgMax,;
	INTEGER @ pcbErrorMsg
  
```  
***  


## Parameters:
iError 
[Input]
Error record number. Valid numbers are from 1 through 8. 

pfErrorCode 
[Output]
Installer error code. 

lpszErrorMsg 
[Output]
Pointer to storage for the error message text. 

cbErrorMsgMax 
[Input]
Maximum length of the szErrorMsg buffer.

cbErrorMsgMax 
[Input]
Maximum length of the szErrorMsg buffer.

pcbErrorMsg 
[Output]
Pointer to the total number of bytes available to return in lpszErrorMsg.
  
***  


## Return value:
SQL_SUCCESS (0), SQL_SUCCESS_WITH_INFO, SQL_NO_DATA, or SQL_ERROR.  
***  

