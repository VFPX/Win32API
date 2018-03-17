<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetupDiDestroyClassImageList
Group: Setup API functions - Library: setupapi    
***  


#### Destroys a class image list that was built by a call to SetupDiGetClassImageList or SetupDiGetClassImageListEx.

***  


## Code examples:
[How to view system icons for the classes installed on the local machine](../../samples/sample_544.md)  
[Enumerating devices installed on the local machine](../../samples/sample_545.md)  

## Declaration:
```foxpro  
WINSETUPAPI BOOL WINAPI
	SetupDiDestroyClassImageList(
	IN PSP_CLASSIMAGELIST_DATA
	ClassImageListData
	);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetupDiDestroyClassImageList IN setupapi;
	STRING ClassImageListData  
```  
***  


## Parameters:
```txt  
ClassImageListData
A pointer to an SP_CLASSIMAGELIST_DATA structure that contains the class image list to destroy.  
```  
***  


## Return value:
The function returns TRUE if it is successful.  
***  


## Comments:
See also: SetupDiGetClassImageListEx, SetupDiGetClassImageIndex   
  
***  

