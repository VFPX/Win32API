[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeDeleteDatabase
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function removes a database from the object store.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the Object Store Databases](../../samples/sample_445.md)  

## Declaration:
```foxpro  
BOOL CeDeleteDatabase(
  CEOID oidDbase
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeDeleteDatabase IN rapi;
	INTEGER oidDbase  
```  
***  


## Parameters:
oidDbase 
[in] Object identifier of the database to be deleted.  
***  


## Return value:
TRUE indicates success.  
***  


## Comments:
See also: [CeCreateDatabase](CeCreateDatabase.md), [CeOpenDatabase](CeOpenDatabase.md) and [CeOidGetInfoEx](CeOidGetInfoEx.md) functions.  
  
***  

