[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Converting characters to upper or lower case

## Code:
```foxpro  
DECLARE INTEGER CharLower IN user32 STRING @ lpsz
DECLARE INTEGER CharUpper IN user32 STRING @ lpsz
	
lcText = "Jack and Jill went up the hill"

? CharLower (@lcText)
? lcText

? CharUpper (@lcText)
? lcText  
```  
***  


## Listed functions:
[CharLower](../libraries/user32/CharLower.md)  
[CharUpper](../libraries/user32/CharUpper.md)  

## Comment:
Both these functions work slower then the native VFP case converting functions. At least I have found them to be slower on my computer comparing their performance on long cycles.  
  
The only reason that I can see in using these functions is passing the parameter by a reference.  
  
Also there may be some flavours from the side of Unicode strings. I"m not sure at this point.  
  
***  

