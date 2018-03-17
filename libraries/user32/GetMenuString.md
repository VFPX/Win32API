<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetMenuString
Group: Menu - Library: user32    
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
```txt  
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
```  
***  


## Return value:
If the function succeeds, the return value specifies the number of characters copied to the buffer, not including the terminating null character.  
***  

