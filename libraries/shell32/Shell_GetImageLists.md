[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : Shell_GetImageLists
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Retrieves system image lists for large and small icons -- undocumented.
***  


## Declaration:
```foxpro  
BOOL Shell_GetImageLists(
	HIMAGELIST *phiml,
	HIMAGELIST *phimlSmall
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER Shell_GetImageLists IN shell32;
	INTEGER @phiml,;
	INTEGER @phimlSmall
  
```  
***  


## Parameters:
phiml
[in] Pointer to the handle of an image list which, on success, receives the system image list for large (32 x 32) icons.

phimlSmall
[in] Pointer to the handle of an image list which, on success, receives the system image list for small (16 x 16) icons.  
***  


## Return value:
Returns TRUE on success.  
***  


## Comments:
This function is available through Microsoft Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.  
  
```foxpro
LOCAL hImg, hImgSmall  
STORE 0 TO hImg, hImgSmall  
  
? Shell_GetImageLists(@hImg, @hImgSmall)  
? hImg, hImgSmall
```
  

***  

