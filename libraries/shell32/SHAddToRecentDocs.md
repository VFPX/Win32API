[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHAddToRecentDocs
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Adds a document to the Shell"s list of recently used documents or clears all documents from the list.
***  


## Code examples:
[Accessing the list of Windows Recent Documents](../../samples/sample_094.md)  

## Declaration:
```foxpro  
VOID SHAddToRecentDocs(
    UINT uFlags,
    LPCVOID pv
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHAddToRecentDocs IN shell32;
    INTEGER uFlags,;
    STRING @ lpName  
```  
***  


## Parameters:
uFlags 
[in] Flag that indicates the meaning of the pv parameter. 

  
***  


## Return value:
pv 
[in] A pointer to either a NULL terminated string with the path and file name of the document, or a PIDL that identifies the document"s file object.  
***  


## Comments:
See also: [SHGetFolderPath](../shell32/SHGetFolderPath.md), [SHGetFolderLocation](..//SHGetFolderLocation.md), [SHSimpleIDListFromPath](../shell32/SHSimpleIDListFromPath.md), [SHGetPathFromIDList](../shell32/SHGetPathFromIDList.md).  
  
***  

