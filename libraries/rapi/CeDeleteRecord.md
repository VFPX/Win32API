[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeDeleteRecord
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function deletes a record from a database.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the Object Store Databases](../../samples/sample_445.md)  

## Declaration:
```foxpro  
BOOL CeDeleteRecord(
  HANDLE hDatabase,
  CEOID oidRecord
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeDeleteRecord IN rapi;
	INTEGER hDatabase,;
	INTEGER oidRecord
  
```  
***  


## Parameters:
hDatabase 
[in] Handle to the database from which the record is to be deleted. The database must be open. Open a database by calling the CeOpenDatabase function. 

oidRecord 
[in] Object identifier of the record to be deleted; this is obtained from CeOpenDatabase.  
***  


## Return value:
TRUE indicates success.  
***  


## Comments:
To add new record call CeWriteRecordProps with <Em>oidRecord</Em> set to zero. To delete a property of a record call CeWriteRecordProps with the CEDB_PROPDELETE flag set.  
  
See also [CeOpenDatabase](CeOpenDatabase.md), [CeWriteRecordProps](CeWriteRecordProps.md) functions.  
  
***  

