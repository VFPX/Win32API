[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving list of Global Atom names

## Code:
```foxpro  
#DEFINE MAX_ATOM_LENGTH 250

DECLARE INTEGER GlobalGetAtomName IN kernel32;
    INTEGER nAtom,;
    STRING @lpBuffer,;
    INTEGER nSize

CREATE CURSOR cs (atom N(12), atomname C(MAX_ATOM_LENGTH))

* scanning the string atoms
FOR nAtom = 0xC000 TO 0xFFFF
    lpBuffer = REPLICATE(CHR(0), MAX_ATOM_LENGTH)

    lnResult = GlobalGetAtomName(;
    				nAtom,;
    				@lpBuffer,;
    				MAX_ATOM_LENGTH)

    IF lnResult > 0
        INSERT INTO cs;
        VALUES (nAtom, LEFT(lpBuffer, lnResult))
    ENDIF
ENDFOR

SELECT cs
GO TOP
BROWSE NORMAL NOWAIT  
```  
***  


## Listed functions:
[GlobalGetAtomName](../libraries/kernel32/GlobalGetAtomName.md)  

## Comment:
Not too many applications for the Atoms I could come with. Direct DDE programming with atoms hardly fascinates any VFP programmer :)  
  
Atoms can be used in a way similar to public variables for saving different states of the application. Atom name stays in the local atom table until the application terminates.  
  
If you want to prevent users starting application B prior to starting application A, make the A to create a global atom that can be used by application B as a confirmation that application A has started.  
  
Knowing atoms created by specific applications, one may guess about those applications. For example, atom "FireFox" appears and stays in the global table when the FireFox browser starts. By itself, this knowledge is rather useless. In certain circumstances, who knows, it can make a difference.  
  
* * *  
The names of all registered window classes are kept in an atom table internal to USER32. The value returned by the RegisterClass function is that atom. You can also retrieve the atom for a window class by asking a window of that class for its class atom via GetClassWord(hwnd, GCW_ATOM).  
  
* * *  
Read article <a href="http://blogs.msdn.com/b/oldnewthing/archive/2004/10/11/240744.aspx">What"s the atom returned by RegisterClass useful for?</a> on <a href="http://blogs.msdn.com/b/oldnewthing/">The OldNew Thing</a> blog.  
  
***  

