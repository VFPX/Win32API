[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeWriteRecordProps
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function writes a set of properties to a single record, creating the record if necessary.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the Object Store Databases](../../samples/sample_445.md)  

## Declaration:
```foxpro  
CEOID CeWriteRecordProps(
  HANDLE hDbase,
  CEOID oidRecord,
  WORD cPropID,
  CEPROPVAL* rgPropVal
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeWriteRecordProps IN rapi;
	INTEGER hDbase,;
	INTEGER oidRecord,;
	SHORT   cPropID,;
	INTEGER rgPropVal
  
```  
***  


## Parameters:
hDbase 
[in] Handle to an open database. The database must have been opened by a previous call to the CeOpenDatabase function. 

oidRecord 
[in] Object identifier of the record to which the specified properties are to be written. If this parameter is 0, a new record is created and filled in with the specified properties. 

cPropID 
[in] Number of properties in the array specified by the rgPropVal parameter. The cPropID parameter must not be 0. 

rgPropVal 
[in] Pointer to an array of CEPROPVAL structures that specify the property values to be written to the specified record.  
***  


## Return value:
The object identifier of the record to which the properties were written indicates success. Zero indicates failure.  
***  


## Comments:
To delete a property set the CEDB_PROPDELETE flag in the appropriate property value. Even if you have all properties for the record deleted, it still stays in the database. Use CeDeleteRecord function to delete a record.  
  
See also: [CeReadRecordProps](CeReadRecordProps.md), [CeOpenDatabase](CeOpenDatabase.md), [CeDeleteRecord](CeDeleteRecord.md) functions.  
  
***  

