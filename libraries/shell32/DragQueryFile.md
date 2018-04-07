[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DragQueryFile
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Retrieves the names of dropped files that result from a successful drag-and-drop operation.
***  


## Code examples:
[Dragging files from Explorer window and dropping them on FoxPro control (requires VFP9)](../../samples/sample_323.md)  

## Declaration:
```foxpro  
UINT DragQueryFile(
	HDROP hDrop,
	UINT iFile,
	LPTSTR lpszFile,
	UINT cch
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DragQueryFile IN shell32;
	INTEGER  hDrop,;
	INTEGER  iFile,;
	STRING @ lpszFile,;
	INTEGER  cch
  
```  
***  


## Parameters:
hDrop
Identifier of the structure containing the file names of the dropped files.

iFile
Index of the file to query. 

lpszFile
Address of a buffer to receive the file name of a dropped file when the function returns. 

cch
Size, in characters, of the lpszFile buffer.  
***  


## Return value:
When the function copies a file name to the buffer, the return value is a count of the characters copied, not including the terminating null character.  
***  


## Comments:
If the index value is 0xFFFFFFFF, the return value is a count of the dropped files. Note that the index variable itself returns unchanged, and will therefore remain 0xFFFFFFFF.  
  
If the index value is between zero and the total number of dropped files and the lpszFile buffer address is NULL, the return value is the required size, in characters, of the buffer, not including the terminating null character.  
  
See also: [DragAcceptFiles](../user32/DragAcceptFiles.md), [DragFinish](../shell32/DragFinish.md).  
  
***  

