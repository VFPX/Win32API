<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : RealDriveType
Group: Shell Functions - Library: shell32    
***  


#### Determines the drive type based on the drive number.
***  


## Code examples:
[Displaying the drive type value](../../samples/sample_012.md)  

## Declaration:
```foxpro  
int RealDriveType(
	int iDrive,
	BOOL fOKToHitNet
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RealDriveType IN shell32;
	INTEGER iDrive,;
	INTEGER fOKToHitNet
  
```  
***  


## Parameters:
```txt  
iDrive
[in] The number of the drive that you want to test. "A:" corresponds to 0, "B:" to 1, and so on.

fOKToHitNet
[in] Reserved. Must be set to 0.  
```  
***  


## Return value:
Returns a predefined value.  
***  


## Comments:
See also GetDriveType function.  
  
***  

