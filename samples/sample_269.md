[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using mailslots to send messages on the network

## Before you begin:
This example shows how to broadcast system alerts using mailslots as an alternative to NET SEND command.  

On Windows XP computer, make sure that the Messenger service is running:  

![](../images/messengerservice.png)  
On Win9* computer, start WINPOPUP.EXE if no other messaging system is active.  

See also:

* [Using the NetMessageBufferSend to send messages on the network](sample_494.md)  
* [Peer-to-peer LAN messenger built with Mailslot API functions](sample_410.md)  
* [How to create non-blocking Winsock server](sample_412.md)  
* [A client for testing non-blocking Winsock server](sample_413.md)  
* [Using named pipes to pass data between processes](sample_522.md)  
* [Using WM_COPYDATA for interprocess communication](sample_536.md)  
  
***  


## Code:
```foxpro  
DO decl
#DEFINE OPEN_EXISTING          3
#DEFINE GENERIC_WRITE          0x40000000
#DEFINE FILE_SHARE_READ        1
#DEFINE INVALID_HANDLE_VALUE  -1
#DEFINE FILE_ATTRIBUTE_NORMAL  128

LOCAL lcSender, lcDest, lcMessage

* the local computer name is chosen as a message recipient
* to test this code without disturbing your colleagues
lcDest = GetCompName()

* usually you choose any other valid network name,
* which can be a computer or domain name,
* or an asterick (*) for the primary domain
*lcDest = "MYSERVER"

lcSender = "VFP Application"
lcMessage = "Test message from VFP application"
? "Bytes sent:", SendMsg (lcSender, lcDest, lcMessage)
* end of main

PROCEDURE SendMsg (lcSender, lcDest, lcMessage)
	LOCAL lcFilename, hFile, lcBuffer, lnBytesWritten
	
	* a mailslot with this name already exists on your computer
	* created by the Messenger Service
	lcFilename = "\\" + lcDest + "\Mailslot\Messngr"

	* the mailslot is a pseudofile
	* subjected to regular file functions
	hFile = CreateFile (lcFilename, GENERIC_WRITE, FILE_SHARE_READ,;
		0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0)

	IF hFile = INVALID_HANDLE_VALUE
		RETURN 0
	ENDIF

	lnBytesWritten = 0
	lcBuffer = lcSender + Chr(0) + lcDest + Chr(0) + lcMessage
	= WriteFile(hFile, @lcBuffer, Len(lcBuffer), @lnBytesWritten, 0)
	= CloseHandle (hFile)
RETURN lnBytesWritten

FUNCTION GetCompName
* returns name of a local computer (similar to SYS(0))
	LOCAL lcBuffer, lnLength
	lnLength = 250
	lcBuffer = SPACE(lnLength)
	= GetComputerName (@lcBuffer, @lnLength)
RETURN  Left(lcBuffer, lnLength)

PROCEDURE  decl
	DECLARE INTEGER CreateFile IN kernel32;
		STRING lpFileName, INTEGER dwDesiredAccess,;
	    INTEGER dwShareMode, INTEGER lpSecurityAttr,;
    	INTEGER dwCreationDisp, INTEGER dwFlagsAndAttr, INTEGER hTplFile

	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER WriteFile IN kernel32;
		INTEGER hFile, STRING @lpBuffer, INTEGER nBt2Write,;
		INTEGER @lpBtWritten, INTEGER lpOverlapped

	DECLARE INTEGER GetComputerName IN kernel32;
		STRING @lpBuffer, INTEGER @nSize  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[GetComputerName](../libraries/kernel32/GetComputerName.md)  
[WriteFile](../libraries/kernel32/WriteFile.md)  

## Comment:
`\\[destination]\mailslot\\messngr` is undocumented mailslot name, though it is widely used exactly for this purpose -- for sending popup messages. As I already mentioned, this is an equivalent of NET SEND command.   
  
In this example a message is sent to the local computer, just to avoid disturbing others. As a destination, you also can choose any computer or server name on your LAN. An asterick (*) is for the primary domain. With this name chosen as a destination you will be granted an immediate attention of all your co-workers.   
  
On target computer, TCP port 139 (NetBIOS) is assigned to receive messages.  
  
Also the NetMessageBufferSend function (Unicode-based) can be used for sending messages on a network. If compared to this function, the mailslot approach can send messages no longer than 128 characters. Though it returns much faster than sometimes the NetMessageBufferSend does.  
  
***  
 
[Microsoft Messenger Removal](http://www.theeldergeek.com/messenger_removal.htm)  
  
***  

