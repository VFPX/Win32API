<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetTimeZoneInformation
Group: Time - Library: kernel32    
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
```txt  
lpTimeZoneInformation
[out] Pointer to a TIME_ZONE_INFORMATION structure to receive the current time-zone parameters.  
```  
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

