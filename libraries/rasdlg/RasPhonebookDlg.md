<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : RasPhonebookDlg
Group: Remote Access Service (RAS) - Library: rasdlg    
***  


#### The RasPhonebookDlg function displays the main Dial-Up Networking dialog box. From this modal dialog box, the user can dial, edit, or delete a selected phone-book entry, create a new phone-book entry, or specify user preferences. The RasPhonebookDlg function returns when the dialog box closes.
***  


## Code examples:
[Displaying the main Dial-Up Networking dialog box](../../samples/sample_331.md)  

## Declaration:
```foxpro  
BOOL RasPhonebookDlg(
  LPTSTR lpszPhonebook,  // pointer to the full path and
                         //  file name of the phone-book file
  LPTSTR lpszEntry,      // pointer to the name of the
                         //  phone-book entry to highlight
  LPRASPBDLG lpInfo      // pointer to a structure that
                         //  contains additional parameters
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RasPhonebookDlg IN rasapi32;
	STRING @ lpszPhonebook,;
	STRING @ lpszEntry,;
	STRING @ lpInfo
  
```  
***  


## Parameters:
```txt  
lpszPhonebook
[in] Pointer to a null-terminated string that specifies the full path and file name of a phone-book (PBK) file.

lpszEntry
[in] Pointer to a null-terminated string that specifies the name of the phone-book entry to highlight initially.

lpInfo
[in, out] Pointer to the RASPBDLG structure that specifies additional input and output parameters.  
```  
***  


## Return value:
If the user selects the Dial button and the function establishes a connection, the return value is a nonzero value.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

