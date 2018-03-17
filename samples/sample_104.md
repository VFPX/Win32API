<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# High-powered ALLTRIM

## Code:
```foxpro  
DECLARE SHORT StrTrim IN Shlwapi As StrTrim;
   	STRING @ pszSource,;
   	STRING   pszTrimChars

lcSrc = "____//Turtle Soup/  "
	
* notice: three characters included in the list
* of characters to be trimmed
lcTrimChars = "_ /"

? "Before: ", "["+ lcSrc +"]"
= StrTrim (@lcSrc, lcTrimChars)
? "After:  ", "[" + LEFT(lcSrc, AT(Chr(0),lcSrc)-1) + "]"  
```  
***  


## Listed functions:
[StrTrim](../libraries/shlwapi/StrTrim.md)  

## Comment:
Unlike the native ALLTRIM, this function can remove not only blanks but any other characters included in the trim character list.  
  
For example, to trim a text, surrounded with any combination of blanks, tabs and quotations, include in this list those three characters:  
	- space  
	- tab (Chr(9))  
	- "  
  
***  

