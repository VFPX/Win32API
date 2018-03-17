<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ChooseColor
Group: Common Dialog Box - Library: comdlg32    
***  


#### The ChooseColor function creates a Color dialog box that enables the user to select a color.
***  


## Code examples:
[Using the ChooseColor function](../../samples/sample_264.md)  

## Declaration:
```foxpro  
BOOL ChooseColor(
  LPCHOOSECOLOR lpcc   // initialization data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ChooseColor IN comdlg32;
	STRING @lpcc  
```  
***  


## Parameters:
```txt  
lpcc
[in/out] Pointer to a CHOOSECOLOR structure that contains information used to initialize the dialog box.  
```  
***  


## Return value:
If the user clicks the OK button of the dialog box, the return value is nonzero. If the user cancels or closes the Color dialog box or an error occurs, the return value is zero.   
***  


## Comments:
Not many advantages this function gives to dump the good old GetColor, which is still dragged solicitously from version to version unchanged.  
  
***  

