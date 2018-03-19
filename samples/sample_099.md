[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Converting strings between ANSI and OEM

## Code:
```foxpro  
DECLARE SHORT CharToOem IN user32;
	STRING lpszSrc,;
	STRING @ lpszDst

DECLARE SHORT OemToChar IN user32;
	STRING lpszSrc,;
	STRING @ lpszDst

* source string of Cyrillic characters (1251)
lcSrc = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÜÛÚÝÞ‗" +;
	"אבגדהוזחטיךכלםמןנסעףפץצקרשüûת‎‏ÿ"

* a buffer for destination string
lcDst = SPACE(Len(lcSrc))
	
? lcSrc

* converting from ANSI to OEM
= CharToOem (lcSrc, @lcDst)
? lcDst

* converting back from OEM to ANSI
= OemToChar (lcDst, @lcSrc)
? lcSrc  
```  
***  


## Listed functions:
[CharToOem](../libraries/user32/CharToOem.md)  
[OemToChar](../libraries/user32/OemToChar.md)  
