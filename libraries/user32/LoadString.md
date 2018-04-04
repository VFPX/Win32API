[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LoadString
Group: [Resource](../../functions_group.md#Resource)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Loads a string resource from the executable file associated with a specified module, copies the string into a buffer, and appends a terminating null character.
***  


## Code examples:
[Loading a string resource from an executable file](../../samples/sample_213.md)  

## Declaration:
```foxpro  
int LoadString(
  HINSTANCE hInstance,  // handle to resource module
  UINT uID,             // resource identifier
  LPTSTR lpBuffer,      // resource buffer
  int nBufferMax        // size of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LoadString IN user32;
	INTEGER hInstance,;
	INTEGER uID,;
	INTEGER lpBuffer,;
	INTEGER nBufferMax  
```  
***  


## Parameters:
hInstance 
[in] Handle to an instance of the module whose executable file contains the string resource. 
uID 
[in] Specifies the integer identifier of the string to be loaded. 

lpBuffer 
[out] Pointer to the buffer to receive the string. 

nBufferMax 
[in] Specifies the size of the buffer, in TCHARs.   
***  


## Return value:
If the function succeeds, the return value is the number of TCHARs copied into the buffer, not including the null-terminating character, or zero if the string resource does not exist.   
***  

