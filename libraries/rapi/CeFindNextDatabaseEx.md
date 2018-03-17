<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeFindNextDatabaseEx
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function retrieves the next database in an enumeration context.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the Object Store Databases](../../samples/sample_445.md)  

## Declaration:
```foxpro  
CEOID CeFindNextDatabaseEx(
  HANDLE hEnum,
  PCEGUID pceguid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeFindNextDatabaseEx IN rapi;
	INTEGER  hEnum,;
	STRING @ pceguid  
```  
***  


## Parameters:
```txt  
hEnum
[in] Handle returned from CeFindFirstDatabaseEx.

pceguid
[in] Pointer to the CEGUID that contains the globally unique identifier of a mounted database.  
```  
***  


## Return value:
A valid CEOID indicates success. Zero indicates failure or a lack of additional databases.  
***  


## Comments:
To find all matching databases, CeFindNextDatabaseEx (RAPI) is called in a loop until 0 is returned. When enumeration is complete, the hEnum handle must be closed by calling the CeCloseHandle (RAPI) function.  
  
See also: CeFindFirstDatabaseEx.  
  
***  

