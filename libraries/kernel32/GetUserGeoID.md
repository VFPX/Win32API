<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetUserGeoID
Group: National Language Support - Library: kernel32    
***  


#### Retrieves information about the geographical location of the user.
***  


## Declaration:
```foxpro  
GEOID GetUserGeoID(
  _In_  GEOCLASS GeoClass
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetUserGeoID IN kernel32;
	INTEGER GeoClass  
```  
***  


## Parameters:
```txt  
GeoClass [in]
Geographical location class to return. Possible values are defined by the SYSGEOCLASS enumeration.  
```  
***  


## Return value:
Returns the geographical location identifier of the user if SetUserGeoID has been called before to set the identifier.  
***  


## Comments:
See also: SetUserGeoID   
  
<a href="http://msdn.microsoft.com/en-us/library/windows/desktop/dd374073(v=vs.85).aspx">Table of Geographical Locations</a>  
  
***  

