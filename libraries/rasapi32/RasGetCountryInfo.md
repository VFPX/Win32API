[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RasGetCountryInfo
Group: [Remote Access Service (RAS)](../../functions_group.md#Remote_Access_Service_(RAS))  -  Library: [rasapi32](../../Libraries.md#rasapi32)  
***  


#### The RasGetCountryInfo function retrieves country-specific dialing information from the Windows Telephony list of countries.
***  


## Code examples:
[Retrieving country-specific dialing information from the Windows Telephony list of countries](../../samples/sample_329.md)  

## Declaration:
```foxpro  
DWORD RasGetCountryInfo(
  LPRASCTRYINFO lpRasCtryInfo,
                    // buffer that receives country information
  LPDWORD lpdwSize  // size, in bytes, of the buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RasGetCountryInfo IN rasapi32;
	STRING  @ lpRasCtryInfo,;
	INTEGER @ lpdwSize
  
```  
***  


## Parameters:
lpRasCtryInfo 
[in, out] Pointer to a RASCTRYINFO structure that, on output, receives the country-specific dialing information followed by additional bytes for a country description string. 

lpdwSize 
[in, out] Pointer to a variable that, on input, specifies the size, in bytes, of the buffer pointed to by the lpRasCtryInfo parameter.   
***  


## Return value:
If the function succeeds, the return value is zero.  
***  


## Comments:
For more information about country-specific dialing information and Telephony Application Programming Interface (TAPI) country identifiers, see the TAPI portion of the Platform SDK.   
  
***  

