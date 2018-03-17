<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetComputerName
Group: System Information - Library: kernel32    
***  


#### The SetComputerName function stores a new NetBIOS name for the local computer. The name is stored in the registry and takes effect the next time the user restarts the computer. 
***  


## Declaration:
```foxpro  
BOOL SetComputerName(
  LPCTSTR lpComputerName  // computer name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetComputerName IN kernel32;
	STRING lpComputerName  
```  
***  


## Parameters:
```txt  
lpComputerName
[in] Pointer to a null-terminated character string that specifies the name that will be the computer name the next time the computer is started. The name must not be longer than MAX_COMPUTERNAME_LENGTH characters (31).  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

