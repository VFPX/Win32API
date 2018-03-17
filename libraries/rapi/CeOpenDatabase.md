<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeOpenDatabase
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function opens an existing database on any database volume, including mounted databases. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the Object Store Databases](../../samples/sample_445.md)  

## Declaration:
```foxpro  
HANDLE CeOpenDatabaseEx(
  PCEGUID pceguid,
  PCEOID poid,
  LPWSTR lpszName,
  CEPROPID propid,
  DWORD dwFlags,
  CENOTIFYREQUEST* pRequest
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE CeOpenDatabase IN rapi;
	INTEGER poid,;
	STRING  lpszName,;
	INTEGER propid,;
	INTEGER dwFlags,;
	INTEGER hwndNotify
  
```  
***  


## Parameters:
```txt  
pceguid
[in] Pointer to the CEGUID that contains the globally unique identifier of a mounted database.

poid
[in] Pointer to the object identifier of the database to be opened.

lpszName
[in] Long pointer to the null-terminated string that contains the name of the database to be opened. This is used along with pceguid to specify the database if the value pointed to by poid is 0.

propid
[in] Property identifier of the primary sort key for the database.

dwFlags
[in] Specifies an action flag.

pRequest
[in] Pointer to a CENOTIFICATION structure that requests notifications be sent to an identified window.  
```  
***  


## Return value:
A handle to the open database indicates success. INVALID_HANDLE_VALUE (-1) indicates failure.  
***  


## Comments:
An application must use the CeCloseHandle (RAPI) function to close the handle returned by the CeOpenDatabaseEx (RAPI) function.   
  
Changes to Windows CE databases are committed after each individual call, not when opening and closing a database.  
  
***  

