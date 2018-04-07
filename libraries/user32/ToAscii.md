[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ToAscii
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Translates the specified virtual-key code and keyboard state to the corresponding character or characters.
***  


## Code examples:
[Capturing keyboard activity of another application with the Raw Input API (VFP9)](../../samples/sample_572.md)  

## Declaration:
```foxpro  
int WINAPI ToAscii(
  __in      UINT uVirtKey,
  __in      UINT uScanCode,
  __in_opt  const BYTE *lpKeyState,
  __out     LPWORD lpChar,
  __in      UINT uFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ToAscii IN user32;
	LONG uVirtKey,;
	LONG uScanCode,;
	STRING @lpKeyState,;
	INTEGER @lpChar,;
	LONG uFlags  
```  
***  


## Parameters:
uVirtKey [in]
The virtual-key code to be translated. See Virtual-Key Codes.

uScanCode [in]
The hardware scan code of the key to be translated. The high-order bit of this value is set if the key is up (not pressed).

lpKeyState [in, optional]
A pointer to a 256-byte array that contains the current keyboard state.

lpChar [out]
The buffer that receives the translated character or characters.

uFlags [in]
This parameter must be 1 if a menu is active, or 0 otherwise.  
***  


## Return value:
If the specified key is a dead key, the return value is negative. Otherwise, it is the number of charachters copied to the buffer, from 0 to 2.  
***  


## Comments:
The function translates the code using the input language and physical keyboard layout identified by the keyboard layout handle.  
  
To specify a handle to the keyboard layout to use to translate the specified code, use the ToAsciiEx function.  
  
See also: [MapVirtualKey](../user32/MapVirtualKey.md), [GetKeyboardState](../user32/GetKeyboardState.md).  
  
***  

