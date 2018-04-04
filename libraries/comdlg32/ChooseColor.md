[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ChooseColor
Group: [Common Dialog Box](../../functions_group.md#Common_Dialog_Box)  -  Library: [comdlg32](../../Libraries.md#comdlg32)  
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
lpcc 
[in/out] Pointer to a CHOOSECOLOR structure that contains information used to initialize the dialog box.   
***  


## Return value:
If the user clicks the OK button of the dialog box, the return value is nonzero. If the user cancels or closes the Color dialog box or an error occurs, the return value is zero.   
***  


## Comments:
Not many advantages this function gives to dump the good old GetColor, which is still dragged solicitously from version to version unchanged.  
  
***  

