[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Validating URLs using moniker functions

## Code:
```foxpro  
#DEFINE S_OK                   0
#DEFINE S_FALSE                1
#DEFINE E_INVALIDARG 0x80070057

DECLARE INTEGER IsValidURL IN urlmon;
	INTEGER pBC, STRING szURL, INTEGER dwReserved

= validateUrl ("https://github.com")
= validateUrl ("www.microsoft.com")
= validateUrl ("http://if protocol prefix included it validates everything")

PROCEDURE  validateUrl (lcUrl)
	LOCAL lnResult
	lnResult = IsValidURL (0, a2w(lcUrl), 0)

	? "Validating:", lcUrl, "-> "
	DO CASE
	CASE lnResult = S_OK
		?? "URL is valid"
	CASE lnResult = S_FALSE
		?? "URL is INvalid"
	CASE lnResult = E_INVALIDARG
		?? "One of the parameters is invalid"
	OTHER
		?? "Have no idea"
	ENDCASE

FUNCTION a2w (lcStr)
* converts source string to wide-chars
	LOCAL lcResult, ii
	lcResult = ""
	FOR ii=1 TO Len(lcStr)
		lcResult = lcResult + SUBSTR(lcStr, ii,1) + Chr(0)
	ENDFOR
RETURN lcResult+Chr(0)  
```  
***  


## Listed functions:
[IsValidURL](../libraries/urlmon/IsValidURL.md)  

## Comment:
At least now this function does not look much useful to me.  
  
***  

