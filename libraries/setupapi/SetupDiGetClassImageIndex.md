[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetupDiGetClassImageIndex
Group: [Setup API functions](../../functions_group.md#Setup_API_functions)  -  Library: [setupapi](../../Libraries.md#setupapi)  
***  


#### Retrieves the index within the class image list of a specified class.
***  


## Code examples:
[How to view system icons for the classes installed on the local machine](../../samples/sample_544.md)  
[Enumerating devices installed on the local machine](../../samples/sample_545.md)  

## Declaration:
```foxpro  
WINSETUPAPI BOOL WINAPI
	SetupDiGetClassImageIndex(
	IN PSP_CLASSIMAGELIST_DATA ClassImageListData,
	IN LPGUID ClassGuid,
	OUT PINT ImageIndex
	);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetupDiGetClassImageIndex IN setupapi;
	STRING ClassImageListData,;
	STRING ClassGuid,;
	LONG @ImageIndex  
```  
***  


## Parameters:
ClassImageListData 
A pointer to an SP_CLASSIMAGELIST_DATA structure that describes a class image list that includes the image for the device setup class that is specified by the ClassGuid parameter. 

ClassGuid 
A pointer to the GUID of the device setup class for which to retrieve the index of the class image in the specified class image list. 

ImageIndex 
A pointer to an INT-typed variable that receives the index of the specified class image in the class image list.  
***  


## Return value:
The function returns TRUE if it is successful.  
***  


## Comments:
In the Usage, the value of <Em>cImageListData</Em> is obtained through call to the SetupDiGetClassImageListEx function.  
  
The cClassGuid is 16-byte string variable containing the GUID of a installed class. For example, the Class GUID for the <Em>USB Root Hub</Em> is {36fc9e60-c465-11cf-8056-444553540000}.  
  
See also: [CLSIDFromString](../ole32/CLSIDFromString.md), [CM_Locate_DevNode_Ex,](..//CM_Locate_DevNode_Ex,.md).  
	CM_Get_DevNode_Registry_Property_Ex   
  
***  

