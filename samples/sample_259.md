[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Printf-style formatted text output in VFP

## Before you begin:
The wnsprintf function is similar to the **printf** function from the C language, also with variable number of input parameters, though some limited. It does not support floating point or pointer types.  
  
***  


## Code:
```foxpro  
? printf("Width=%d, Height=%4d, Alignment=%s", 100, 200, "Center")

PROCEDURE  printf (lcSource, p0, p1, p2, p3, p4, p5, p6, p7,;
	p8,p9,p10,p11,p12,p13,p14,p15)
* VFP Help: A maximum of 27 parameters can be passed
* from a calling program

	LOCAL lnIndex, lcDecl, lvValue, lcType, lcDecl,;
		lnResult, lcTarget

	lcDecl = ""
	FOR lnIndex=0 TO 15
		IF lnIndex <= PARAMETERS()-2
			lvValue = EVAL("p" + LTRIM(STR(lnIndex)))
			lcType = TYPE("lvValue")

			DO CASE
			CASE lcType = "C"
				lcDecl = lcDecl + ", STRING"
			CASE lcType = "N"
				lcDecl = lcDecl + ", INTEGER"
			ENDCASE
		ELSE
			lcDecl = lcDecl + ", INTEGER"
		ENDIF

	ENDFOR

	* every time this function has to be redeclared
	* according to the parameters passed to it

	lcDecl = "DECLARE INTEGER wnsprintf IN Shlwapi " +;
		"STRING @lpOut, INTEGER cchLimitIn, STRING pszFmt" +;
		lcDecl

	&lcDecl

	lcTarget = Space(4096)
	lnResult = wnsprintf (@lcTarget, Len(lcTarget), lcSource,;
		p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15)
RETURN  Left(lcTarget, lnResult)  
```  
***  


## Listed functions:
[wnsprintf](../libraries/shlwapi/wnsprintf.md)  

## Comment:
This is quite unusual situation for a Win32 function requiring a variable number of parameters. So is the approach to declare the wnsprintf function through a macro substitution.   
  
Valid % specifiers (quite possible there could be some more)
* %d, %i - integer  
* %u - unsigned decimal  
* %s - string  
* %x, %X - unsigned hex value  

This function does not support the %o option (unsigned octal value), that is strange.  
  
***  

