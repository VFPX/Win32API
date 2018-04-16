[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ShellExecute
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Performs an operation on a specified file.
***  


## Code examples:
[How to access a file using not its name but an alias (hard link)](../../samples/sample_018.md)  
[Using Shell for performing operations on files](../../samples/sample_093.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Accessing examples contained in this reference from a VFP application](../../samples/sample_197.md)  
[Reading the structure of VFP main menu](../../samples/sample_337.md)  
[Saving local machine ODBC Registry Entries to XML file](../../samples/sample_379.md)  
[Mapping and disconnecting network drives](../../samples/sample_387.md)  
[Accessing Windows Control Panel from VFP Application](../../samples/sample_391.md)  
[GDI+: creating scaled copy of image file](../../samples/sample_460.md)  
[Accessing examples contained in this reference through Web Services](../../samples/sample_469.md)  
[Accessing Adobe Reader 7.0 main menu from VFP application](../../samples/sample_495.md)  
[GDI+: converting text strings to images and saving in a graphics file](../../samples/sample_513.md)  
[GDI+: Drawing a Pie Chart](../../samples/sample_514.md)  
[GDI+: cropping images](../../samples/sample_515.md)  
[How to control Adobe Reader 9.0 (SDI mode) from VFP application](../../samples/sample_550.md)  
[How to display Windows On-Screen Keyboard](../../samples/sample_582.md)  
[GDI+: creating a gradient](../../samples/sample_596.md)  

## Declaration:
```foxpro  
HINSTANCE ShellExecute(
    HWND hwnd,
    LPCTSTR lpOperation,
    LPCTSTR lpFile,
    LPCTSTR lpParameters,
    LPCTSTR lpDirectory,
    INT nShowCmd
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ShellExecute IN shell32;
	INTEGER hwnd,;
	STRING  lpOperation,;
	STRING  lpFile,;
	STRING  lpParameters,;
	STRING  lpDirectory,;
	INTEGER nShowCmd  
```  
***  


## Parameters:
hwnd 
Handle to a parent window. This window receives any message boxes that an application produces, such as error reporting. 

lpVerb 
A string, referred to as a verb, that specifies the action to be performed: edit, explore, find, open, print

lpFile 
Address of a null-terminated string that specifies the file or object on which to execute the specified verb. 

lpParameters 
If the lpFile parameter specifies an executable file, lpParameters is an address to a null-terminated string that specifies the parameters to be passed to the application.

lpDirectory 
Address of a null-terminated string that specifies the default directory. 

nShowCmd 
Flags that specify how an application is to be displayed when it is opened.  
***  


## Return value:
Returns a value greater than 32 if successful, or an error value that is less than or equal to 32 otherwise. . The return value is cast as an HINSTANCE for backward compatibility with 16-bit Microsoft&reg; Windows&reg; applications. It is not a true HINSTANCE, however.  
***  


## Comments:
The following verbs are commonly used: <Em>edit, explore, find, open, print</Em> and <Em>properties</Em>.  
  
See also: [ShellExecuteEx](../shell32/ShellExecuteEx.md), [CreateProcess](../kernel32/CreateProcess.md), [AssocQueryString](../shlwapi/AssocQueryString.md).  
  
***  

