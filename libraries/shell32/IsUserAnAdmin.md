[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IsUserAnAdmin
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Tests whether the current user is a member of the Administrator"s group.
***  


## Code examples:
[Retrieving current user for the process](../../samples/sample_310.md)  

## Declaration:
```foxpro  
BOOL IsUserAnAdmin(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsUserAnAdmin IN shell32  
```  
***  


## Return value:
Returns TRUE if the user is a member of the Administrator"s group, FALSE if not.
  
***  

