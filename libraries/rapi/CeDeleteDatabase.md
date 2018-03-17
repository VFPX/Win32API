<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeDeleteDatabase
Group: Remote Application Programming (RAPI) - Library: rapi    
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
```txt  
oidDbase
[in] Object identifier of the database to be deleted.  
```  
***  


## Return value:
TRUE indicates success.  
***  


## Comments:
See also CeCreateDatabase, CeOpenDatabase and CeOidGetInfoEx functions.  
  
***  

