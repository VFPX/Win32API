<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : IsUserAnAdmin
Group: Shell Functions - Library: shell32    
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

