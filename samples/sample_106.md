[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Converting a decimal string to an integer

## Code:
```foxpro  
DECLARE INTEGER StrToInt IN Shlwapi STRING lpSrc
DECLARE INTEGER StrToLong IN Shlwapi STRING lpSrc
	
= _show("0")
= _show("1")
= _show("abc")
= _show("54")
= _show("0x100")
= _show("2001")
= _show("2 * 3")
= _show("3.14")

PROCEDURE _show(cSrc)
	? cSrc, StrToInt(cSrc), VAL(cSrc)  
```  
***  


## Listed functions:
[StrToInt](../libraries/shlwapi/StrToInt.md)  

## Comment:
Native TryParse in C# works a few time faster than the StrToIntEx. But the latter"s flags are less complex that the NumberStyles flags.  
  
***  

