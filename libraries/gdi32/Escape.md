[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : Escape
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The Escape function enables applications to access capabilities of a particular device not directly available through GDI. Escape calls made by an application are translated and sent to the driver. 
***  


## Code examples:
[Printing text with the Escape function](../../samples/sample_357.md)  

## Declaration:
```foxpro  
int Escape(
  HDC hdc,           // handle to DC
  int nEscape,       // escape function
  int cbInput,       // size of input structure
  LPCSTR lpvInData,  // input structure
  LPVOID lpvOutData  // output structure
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER Escape IN gdi32;
	INTEGER hdc,;
	INTEGER nEscape,;
	INTEGER cbInput,;
	INTEGER lpvInData,;
	INTEGER lpvOutData  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

nEscape 
[in] Specifies the escape function to be performed. 

cbInput 
[in] Specifies the number of bytes of data pointed to by the lpvInData parameter. 

lpvInData 
[in] Pointer to the input structure required for the specified escape. 

lpvOutData 
[out] Pointer to the structure that receives output from this escape.  
***  


## Return value:
If the function succeeds, the return value is greater than zero, except with the QUERYESCSUPPORT printer escape, which checks for implementation only. If the escape is not implemented, the return value is zero.  
***  

