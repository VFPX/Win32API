[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : OpenFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The OpenFile function creates, opens, reopens, or deletes a file
***  


## Code examples:
[Setting the date and time that a file was created](../../samples/sample_065.md)  
[Using GetFileSize](../../samples/sample_114.md)  
[Locking and unlocking file of a VFP table](../../samples/sample_154.md)  
[Comparing file times](../../samples/sample_171.md)  
[Using InternetSetFilePointer when resuming interrupted download from the Internet](../../samples/sample_191.md)  
[Retrieving file information for the VFP executable running](../../samples/sample_242.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  
[How to set Creation Date/Time for a folder (WinNT)](../../samples/sample_399.md)  
[Using File Mapping for enumerating files opened by Visual FoxPro](../../samples/sample_473.md)  

## Declaration:
```foxpro  
HFILE OpenFile(
  LPCSTR lpFileName,        // file name
  LPOFSTRUCT lpReOpenBuff,  // file information
  UINT uStyle               // action and attributes
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenFile IN kernel32;
	STRING   lpFileName,;
	STRING @ lpReOpenBuff,;
	INTEGER  wStyle  
```  
***  


## Parameters:
lpFileName 
[in] Pointer to a null-terminated string that names the file to be opened

lpReOpenBuff 
[out] Pointer to the OFSTRUCT structure that receives information about the file when it is first opened. The structure can be used in subsequent calls to the OpenFile function to refer to the open file

uStyle 
[in] Specifies the action to take  
***  


## Return value:
If the function succeeds, the return value specifies a file handle  
***  


## Comments:
After being open the file can be closed by CloseHandle. And oh, of course it can be read, written etc.  
  
***  

