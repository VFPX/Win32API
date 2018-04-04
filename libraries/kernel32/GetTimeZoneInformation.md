[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetTimeZoneInformation
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the current time-zone parameters. These parameters control the translations between Coordinated Universal Time (UTC) and local time.
***  


## Code examples:
[Retrieving information specific to the current Time Zone](../../samples/sample_073.md)  

## Declaration:
```foxpro  
DWORD GetTimeZoneInformation(
  LPTIME_ZONE_INFORMATION lpTimeZoneInformation // time zone
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTimeZoneInformation IN kernel32;
	STRING @ lpTimeZoneInformation  
```  
***  


## Parameters:
lpTimeZoneInformation 
[out] Pointer to a TIME_ZONE_INFORMATION structure to receive the current time-zone parameters.  
***  


## Return value:
If the function succeeds, the return value is one of the following values: 
#DEFINE TIME_ZONE_ID_UNKNOWN     0
#DEFINE TIME_ZONE_ID_STANDARD    1
#DEFINE TIME_ZONE_ID_DAYLIGHT    2
  
***  


## Comments:
This registry key contains attributes for all Time Zones.   
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Time Zones  
  
***  

