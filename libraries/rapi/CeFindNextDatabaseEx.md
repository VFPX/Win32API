[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeFindNextDatabaseEx
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
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
hEnum 
[in] Handle returned from CeFindFirstDatabaseEx. 

pceguid 
[in] Pointer to the CEGUID that contains the globally unique identifier of a mounted database.   
***  


## Return value:
A valid CEOID indicates success. Zero indicates failure or a lack of additional databases.  
***  


## Comments:
To find all matching databases, CeFindNextDatabaseEx (RAPI) is called in a loop until 0 is returned. When enumeration is complete, the hEnum handle must be closed by calling the CeCloseHandle (RAPI) function.  
  
See also: [CeFindFirstDatabaseEx](../rapi/CeFindFirstDatabaseEx.md).  
  
***  

