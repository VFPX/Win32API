[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : VkKeyScan
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Translates a character to the corresponding virtual-key code and shift state for the current keyboard.
***  


## Code examples:
[How to activate Windows Calculator](../../samples/sample_026.md)  

## Declaration:
```foxpro  
SHORT VkKeyScan(
	TCHAR ch
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT VkKeyScan IN user32;
	INTEGER ch  
```  
***  


## Parameters:
ch
[in] Specifies the character to be translated into a virtual-key code.  
***  


## Return value:
If the function succeeds, the low-order byte of the return value contains the virtual-key code and the high-order byte contains the shift state, which can be a combination of bits.  
***  


## Comments:
1=Either SHIFT key is pressed.   
2=Either CTRL key is pressed.   
4=Either ALT key is pressed.   
8=The Hankaku key is pressed   
16=Reserved (defined by the keyboard layout driver).   
32=Reserved (defined by the keyboard layout driver).   
  
***  

