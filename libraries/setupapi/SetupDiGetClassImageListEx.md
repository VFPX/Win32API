[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetupDiGetClassImageListEx
Group: [Setup API functions](../../functions_group.md#Setup_API_functions)  -  Library: [setupapi](../../Libraries.md#setupapi)  
***  


#### Builds an image list of bitmaps for every class installed on a local or remote system.

***  


## Code examples:
[How to view system icons for the classes installed on the local machine](../../samples/sample_544.md)  
[Enumerating devices installed on the local machine](../../samples/sample_545.md)  

## Declaration:
```foxpro  
WINSETUPAPI BOOL WINAPI
	SetupDiGetClassImageListEx(
	OUT PSP_CLASSIMAGELIST_DATA ClassImageListData,
	IN PCTSTR MachineName,
	OPTIONAL IN PVOID  Reserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetupDiGetClassImageListEx IN setupapi;
	STRING @ClassImageListData,;
	STRING MachineName,;
	INTEGER Reserved  
```  
***  


## Parameters:
ClassImageListData 
A pointer to an SP_CLASSIMAGELIST_DATA structure to receive information regarding the class image list, including a handle to the image list.

MachineName 
A pointer to NULL-terminated string that supplies the name of a remote system for whose classes SetupDiGetClassImageListEx must build the bitmap. 

Reserved 
Must be NULL.  
***  


## Return value:
The function returns TRUE if it is successful.  
***  


## Comments:
The cbSize field of the SP_CLASSIMAGELIST_DATA structure must be initialized with the size of the structure, in bytes, before calling this function or it will fail.   
  
The image list built by this function should be destroyed by calling SetupDiDestroyClassImageList.  
  
***  

