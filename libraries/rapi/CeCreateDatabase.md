[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeCreateDatabase
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function creates a new database.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the Object Store Databases](../../samples/sample_445.md)  

## Declaration:
```foxpro  
CEOID CeCreateDatabase(
  LPWSTR lpszName,
  DWORD dwDbaseType,
  WORD wNumSortOrder,
  SORTORDERSPEC* rgSortSpecs
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeCreateDatabase IN rapi;
	STRING  lpszName,;
	INTEGER dwDbaseType,;
	SHORT   wNumSortOrder,;
	INTEGER rgSortSpecs
  
```  
***  


## Parameters:
lpszName 
[in] Long pointer to a null-terminated string that specifies the name for the new database.

dwDbaseType 
[in] Specifies the type identifier for the database. 

wNumSortOrder 
[in] Number of sort orders active in the database, with four being the maximum number.

rgSortSpecs 
[in] Pointer to an array of actual sort order descriptions.  
***  


## Return value:
The object identifier of the newly created database � not a handle to an open database � indicates success.  
***  


## Comments:
The name can have up to 32 characters, including the terminating null character.  
  
See also: [CeOpenDatabase](CeOpenDatabase.md), [CeDeleteDatabase](CeDeleteDatabase.md), [CeWriteRecordProps](CeWriteRecordProps.md) and [CeDeleteRecord](CeDeleteRecord.md) functions.  
  
***  

