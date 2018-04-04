[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeFindFirstDatabaseEx
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function opens an enumeration context for all databases in a database volume. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the Object Store Databases](../../samples/sample_445.md)  

## Declaration:
```foxpro  
HANDLE CeFindFirstDatabaseEx(
  PCEGUID pceguid,
  DWORD dwDbaseType
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeFindFirstDatabaseEx IN rapi;
	STRING  @ pceguid,;
	INTEGER   dwDbaseType  
```  
***  


## Parameters:
pceguid 
[in] Pointer to the CEGUID that contains the globally unique identifier of a mounted database volume.

dwDbaseType 
[in] Specifies the type identifier of the databases to enumerate.  
***  


## Return value:
A handle to an enumeration context indicates success. INVALID_HANDLE_VALUE indicates failure.   
***  


## Comments:
This function only returns the handle to an enumeration context. To begin enumerating databases, an application must call the CeFindNextDatabaseEx (RAPI) function.   
  
When an application is done with the handle to the enumeration context, an application uses CeCloseHandle to release the resources associated with the enumeration context.  
  
***  

