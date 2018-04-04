[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ReportEvent
Group: [Event Logging](../../functions_group.md#Event_Logging)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Writes an entry at the end of the specified event log.
***  


## Declaration:
```foxpro  
BOOL ReportEvent(
  HANDLE hEventLog,
  WORD wType,
  WORD wCategory,
  DWORD dwEventID,
  PSID lpUserSid,
  WORD wNumStrings,
  DWORD dwDataSize,
  LPCTSTR* lpStrings,
  LPVOID lpRawData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ReportEvent IN advapi32;
	INTEGER hEventLog,;
	INTEGER wType,;
	INTEGER wCategory,;
	LONG dwEventID,;
	INTEGER lpUserSid,;
	INTEGER wNumStrings,;
	LONG dwDataSize,;
	STRING @lpStrings,;
	STRING @lpRawData
  
```  
***  


## Parameters:
hEventLog 
[in] A handle to the event log. This handle is returned by the RegisterEventSource function.

wType 
[in] The type of event to be logged -- list of predefined values .

wCategory 
[in] The event category. This is source-specific information; the category can have any value. 

dwEventID 
[in] The event identifier. The event identifier specifies the entry in the message file associated with the event source.

lpUserSid 
[in] A pointer to the current user"s security identifier. This parameter can be NULL if the security identifier is not required. 

wNumStrings 
[in] The number of insert strings in the array pointed to by the lpStrings parameter. A value of zero indicates that no strings are present. 

dwDataSize 
[in] The number of bytes of event-specific raw (binary) data to write to the log. If this parameter is zero, no event-specific data is present. 

lpStrings 
[in] A pointer to a buffer containing an array of null-terminated strings that are merged into the message before Event Viewer displays the string to the user. 

lpRawData 
[in] A pointer to the buffer containing the binary data. This parameter must be a valid pointer (or NULL), even if the dwDataSize parameter is zero.   
***  


## Return value:
If the function succeeds, the return value is nonzero, indicating that the entry was written to the log.  
***  


## Comments:
As of Windows XP SP2, <Em>hEventLog</Em> parameter cannot be a handle to the Security log. To write an event to the Security log, use the AuthzReportSecurityEvent function.  
  
  
***  

