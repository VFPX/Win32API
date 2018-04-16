[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RealDriveType
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
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
iDrive
[in] The number of the drive that you want to test. "A:" corresponds to 0, "B:" to 1, and so on.

fOKToHitNet
[in] Reserved. Must be set to 0.  
***  


## Return value:
Returns a predefined value.  
***  


## Comments:
See also [GetDriveType](../kernel32/GetDriveType.md) function.  
  
***  

