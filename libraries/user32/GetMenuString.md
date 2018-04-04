[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetMenuString
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetMenuString function copies the text string of the specified menu item into the specified buffer.

***  


## Code examples:
[Reading the structure of VFP main menu](../../samples/sample_337.md)  

## Declaration:
```foxpro  
int GetMenuString(
	HMENU hMenu,
	UINT uIDItem,
	LPTSTR lpString,
	int nMaxCount,
	UINT uFlag
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMenuString IN user32;
	INTEGER   hMenu,;
	INTEGER   uIDItem,;
	STRING  @ lpString,;
	INTEGER @ nMaxCount,;
	INTEGER   uFlag
  
```  
***  


## Parameters:
hMenu
[in] Handle to the menu. 

uIDItem
[in] Specifies the menu item to be changed, as determined by the uFlag parameter. 

lpString
[out] Pointer to the buffer that receives the null-terminated string.

nMaxCount
[in] Specifies the maximum length, in characters, of the string to be copied. 

uFlag
[in] Specifies how the uIDItem parameter is interpreted: MF_BYCOMMAND or MF_BYPOSITION  
***  


## Return value:
If the function succeeds, the return value specifies the number of characters copied to the buffer, not including the terminating null character.  
***  

