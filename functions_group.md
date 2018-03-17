<link rel="stylesheet" type="text/css" href="css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# List of functions grouped by group name

## @icon-book Atom group
***  

[GlobalGetAtomName](libraries/kernel32/GlobalGetAtomName.md)  
```txt  
Retrieves a copy of the character string associated with the specified global atom.  
```  

***  


## @icon-book Authentication group
***  

[SCardConnect](libraries/winscard/SCardConnect.md)  
```txt  
Establishes a connection (using a specific resource manager context) between the calling application and a smart card contained by a specific reader.
  
```  

***  

[SCardControl](libraries/winscard/SCardControl.md)  
```txt  
The SCardControl function gives you direct control of the reader by sending specific control codes optionally accompanied with supporting input data.  
```  

***  

[SCardDisconnect](libraries/winscard/SCardDisconnect.md)  
```txt  
Terminates a connection previously opened between the calling application and a smart card in the target reader.  
```  

***  

[SCardEstablishContext](libraries/winscard/SCardEstablishContext.md)  
```txt  
Establishes the resource manager context (the scope) within which database operations are performed.  
```  

***  

[SCardGetAttrib](libraries/winscard/SCardGetAttrib.md)  
```txt  
Gets the current reader attributes for the given handle. It does not affect the state of the reader, driver, or card.
  
```  

***  

[SCardGetProviderId](libraries/winscard/SCardGetProviderId.md)  
```txt  
Returns the identifier (GUID) of the primary service provider for a given card.  
```  

***  

[SCardIsValidContext](libraries/winscard/SCardIsValidContext.md)  
```txt  
Determines whether a smart card context handle is valid.
  
```  

***  

[SCardListCards](libraries/winscard/SCardListCards.md)  
```txt  
Searches the smart card database and provides a list of named cards previously introduced to the system by the user.  
```  

***  

[SCardListInterfaces](libraries/winscard/SCardListInterfaces.md)  
```txt  
Provides a list of interfaces supplied by a given card.  
```  

***  

[SCardListReaderGroups](libraries/winscard/SCardListReaderGroups.md)  
```txt  
Provides the list of reader groups that have previously been introduced to the system.
  
```  

***  

[SCardListReaders](libraries/winscard/SCardListReaders.md)  
```txt  
Provides the list of readers within a set of named reader groups.  
```  

***  

[SCardReleaseContext](libraries/winscard/SCardReleaseContext.md)  
```txt  
Closes an established resource manager context, freeing any resources allocated under that context, including SCARDHANDLE objects and memory allocated using the SCARD_AUTOALLOCATE length designator.
  
```  

***  

[SCardStatus](libraries/winscard/SCardStatus.md)  
```txt  
Provides the current status of a smart card in a reader.  
```  

***  

[SCardTransmit](libraries/winscard/SCardTransmit.md)  
```txt  
Sends a service request to the smart card and expects to receive data back from the card.  
```  

***  


## @icon-book Authorization group
***  

[AdjustTokenPrivileges](libraries/advapi32/AdjustTokenPrivileges.md)  
```txt  
Enables or disables privileges in the specified access token.  
```  

***  

[GetTokenInformation](libraries/advapi32/GetTokenInformation.md)  
```txt  
Retrieves a specified type of information about an access token.  
```  

***  

[LookupPrivilegeDisplayName](libraries/advapi32/LookupPrivilegeDisplayName.md)  
```txt  
Retrieves the display name that represents a specified privilege.  
```  

***  

[LookupPrivilegeName](libraries/advapi32/LookupPrivilegeName.md)  
```txt  
Retrieves the name that corresponds to the privilege represented on a specific system by a specified locally unique identifier (LUID).  
```  

***  

[LookupPrivilegeValue](libraries/advapi32/LookupPrivilegeValue.md)  
```txt  
Retrieves the locally unique identifier (LUID) used on a specified system to locally represent the specified privilege name.  
```  

***  

[OpenProcessToken](libraries/advapi32/OpenProcessToken.md)  
```txt  
Opens the access token associated with a process.  
```  

***  


## @icon-book Bitmap group
***  

[AlphaBlend](libraries/msimg32/AlphaBlend.md)  
```txt  
The AlphaBlend function displays bitmaps that have transparent or semitransparent pixels.  
```  

***  

[BitBlt](libraries/gdi32/BitBlt.md)  
```txt  
The BitBlt function performs a bit-block transfer of the color data corresponding to a rectangle of pixels from the specified source device context into a destination device context.  
```  

***  

[CreateCompatibleBitmap](libraries/gdi32/CreateCompatibleBitmap.md)  
```txt  
Creates a bitmap compatible with the device that is associated with the specified device context.  
```  

***  

[CreateDIBSection](libraries/gdi32/CreateDIBSection.md)  
```txt  
Creates a DIB that applications can write to directly.  
```  

***  

[GetDIBits](libraries/gdi32/GetDIBits.md)  
```txt  
The GetDIBits function retrieves the bits of the specified compatible bitmap and copies them into a buffer as a DIB using the specified format.   
```  

***  

[GradientFill](libraries/msimg32/GradientFill.md)  
```txt  
The GradientFill function fills rectangle and triangle structures.   
```  

***  

[LoadBitmap](libraries/user32/LoadBitmap.md)  
```txt  
The LoadBitmap function loads the specified bitmap resource from a module"s executable file. This function has been superseded by the LoadImage function.   
```  

***  

[StretchBlt](libraries/gdi32/StretchBlt.md)  
```txt  
Copies a bitmap from a source rectangle into a destination rectangle, stretching or compressing the bitmap to fit the dimensions of the destination rectangle, if necessary.  
```  

***  

[StretchDIBits](libraries/gdi32/StretchDIBits.md)  
```txt  
The StretchDIBits function copies the color data for a rectangle of pixels in a DIB to the specified destination rectangle.  
```  

***  


## @icon-book Brush group
***  

[CreateSolidBrush](libraries/gdi32/CreateSolidBrush.md)  
```txt  
The CreateSolidBrush function creates a logical brush that has the specified solid color.   
```  

***  

[GetSysColorBrush](libraries/user32/GetSysColorBrush.md)  
```txt  
Retrieves a handle identifying a logical brush that corresponds to the specified color index.  
```  

***  


## @icon-book COM group
***  

[CLSIDFromString](libraries/ole32/CLSIDFromString.md)  
```txt  
Converts a string generated by the StringFromCLSID function back into the original CLSID.  
```  

***  

[CoCreateGuid](libraries/ole32/CoCreateGuid.md)  
```txt  
Creates a GUID, a unique 128-bit integer used for CLSIDs and interface identifiers.  
```  

***  

[CoTaskMemFree](libraries/ole32/CoTaskMemFree.md)  
```txt  
Frees a block of task memory previously allocated through a call to the CoTaskMemAlloc or CoTaskMemRealloc function.  
```  

***  

[CreateStreamOnHGlobal](libraries/ole32/CreateStreamOnHGlobal.md)  
```txt  
The CreateStreamOnHGlobal function creates a stream object stored in global memory.  
```  

***  

[GetHGlobalFromStream](libraries/ole32/GetHGlobalFromStream.md)  
```txt  
The GetHGlobalFromStream function retrieves the global memory handle to a stream that was created through a call to the CreateStreamOnHGlobal function.  
```  

***  

[StringFromGUID2](libraries/ole32/StringFromGUID2.md)  
```txt  
Converts a globally unique identifier (GUID) into a string of printable characters.  
```  

***  


## @icon-book Clipboard group
***  

[AddClipboardFormatListener](libraries/user32/AddClipboardFormatListener.md)  
```txt  
Places the given window in the system-maintained clipboard format listener list.  
```  

***  

[ChangeClipboardChain](libraries/user32/ChangeClipboardChain.md)  
```txt  
Removes a specified window from the chain of clipboard viewers.  
```  

***  

[CloseClipboard](libraries/user32/CloseClipboard.md)  
```txt  
Closes the clipboard.  
```  

***  

[CountClipboardFormats](libraries/user32/CountClipboardFormats.md)  
```txt  
The CountClipboardFormats function retrieves the number of different data formats currently on the clipboard  
```  

***  

[EmptyClipboard](libraries/user32/EmptyClipboard.md)  
```txt  
The EmptyClipboard function empties the clipboard and frees handles to data in the clipboard  
```  

***  

[EnumClipboardFormats](libraries/user32/EnumClipboardFormats.md)  
```txt  
The EnumClipboardFormats function lets you enumerate the data formats that are currently available on the clipboard  
```  

***  

[GetClipboardData](libraries/user32/GetClipboardData.md)  
```txt  
The GetClipboardData function retrieves data from the clipboard in a specified format. The clipboard must have been opened previously.  
```  

***  

[GetClipboardFormatName](libraries/user32/GetClipboardFormatName.md)  
```txt  
The GetClipboardFormatName function retrieves from the clipboard the name of the specified registered format. The function copies the name to the specified buffer.   
```  

***  

[GetClipboardOwner](libraries/user32/GetClipboardOwner.md)  
```txt  
The GetClipboardOwner function retrieves the window handle of the current owner of the clipboard  
```  

***  

[GetClipboardSequenceNumber](libraries/user32/GetClipboardSequenceNumber.md)  
```txt  
Retrieves the clipboard sequence number for the current window station.  
```  

***  

[GetClipboardViewer](libraries/user32/GetClipboardViewer.md)  
```txt  
The GetClipboardViewer function retrieves the handle of the first window in the clipboard viewer chain  
```  

***  

[GetOpenClipboardWindow](libraries/user32/GetOpenClipboardWindow.md)  
```txt  
Retrieves the handle to the window that currently has the clipboard open.  
```  

***  

[GetPriorityClipboardFormat](libraries/user32/GetPriorityClipboardFormat.md)  
```txt  
The GetPriorityClipboardFormat function retrieves the first available clipboard format in the specified list.  
```  

***  

[GetUpdatedClipboardFormats](libraries/user32/GetUpdatedClipboardFormats.md)  
```txt  
Retrieves the currently supported clipboard formats.  
```  

***  

[IsClipboardFormatAvailable](libraries/user32/IsClipboardFormatAvailable.md)  
```txt  
The IsClipboardFormatAvailable function determines whether the clipboard contains data in the specified format  
```  

***  

[OpenClipboard](libraries/user32/OpenClipboard.md)  
```txt  
The OpenClipboard function opens the clipboard for examination and prevents other applications from modifying the clipboard content  
```  

***  

[RegisterClipboardFormat](libraries/user32/RegisterClipboardFormat.md)  
```txt  
The RegisterClipboardFormat function registers a new clipboard format. This format can then be used as a valid clipboard format.   
```  

***  

[RemoveClipboardFormatListener](libraries/user32/RemoveClipboardFormatListener.md)  
```txt  
Removes the given window from the system-maintained clipboard format listener list.  
```  

***  

[SetClipboardData](libraries/user32/SetClipboardData.md)  
```txt  
The SetClipboardData function places data on the clipboard in a specified clipboard format  
```  

***  

[SetClipboardViewer](libraries/user32/SetClipboardViewer.md)  
```txt  
Adds the specified window to the chain of clipboard viewers.   
```  

***  


## @icon-book Color group
***  

[GetNearestColor](libraries/gdi32/GetNearestColor.md)  
```txt  
The GetNearestColor function returns a color value identifying a color from the system palette that will be displayed when the specified color value is used  
```  

***  


## @icon-book Common Dialog Box group
***  

[ChooseColor](libraries/comdlg32/ChooseColor.md)  
```txt  
The ChooseColor function creates a Color dialog box that enables the user to select a color.  
```  

***  

[ChooseFont](libraries/comdlg32/ChooseFont.md)  
```txt  
Creates a Font dialog box that enables the user to choose attributes for a logical font. These attributes include a typeface name, style (bold, italic, or regular), point size, effects (underline, strikeout, and text color), and a script (or character set).  
```  

***  

[CommDlgExtendedError](libraries/comdlg32/CommDlgExtendedError.md)  
```txt  
The CommDlgExtendedError function returns a common dialog box error code. This code indicates the most recent error to occur during the execution of one of the common dialog box functions.   
```  

***  

[FindText](libraries/comdlg32/FindText.md)  
```txt  
Creates a system-defined modeless Find dialog box that lets the user specify a string to search for and options to use when searching for text in a document.  
```  

***  

[GetFileTitle](libraries/comdlg32/GetFileTitle.md)  
```txt  
Retrieves the name of the specified file.  
```  

***  

[GetOpenFileName](libraries/comdlg32/GetOpenFileName.md)  
```txt  
The GetOpenFileName function creates an Open dialog box that lets the user specify the drive, directory, and the name of a file or set of files to open.  
```  

***  

[GetSaveFileName](libraries/comdlg32/GetSaveFileName.md)  
```txt  
The GetSaveFileName function creates a Save dialog box that lets the user specify the drive, directory, and name of a file to save.  
```  

***  

[PageSetupDlg](libraries/comdlg32/PageSetupDlg.md)  
```txt  
The PageSetupDlg function creates a Page Setup dialog box that enables the user to specify the attributes of a printed page.  
```  

***  

[PrintDlg](libraries/comdlg32/PrintDlg.md)  
```txt  
Displays a Print dialog box. The Print dialog box enables the user to specify the properties of a particular print job.  
```  

***  

[PrintDlgEx](libraries/comdlg32/PrintDlgEx.md)  
```txt  
The PrintDlgEx function displays a Print property sheet that enables the user to specify the properties of a particular print job.  
```  

***  

[TaskDialog](libraries/comctl32/TaskDialog.md)  
```txt  
Creates, displays, and operates a task dialog.  
```  

***  

[TaskDialogIndirect](libraries/comdlg32/TaskDialogIndirect.md)  
```txt  
Creates, displays, and operates a task dialog.  
```  

***  


## @icon-book Console group
***  

[AllocConsole](libraries/kernel32/AllocConsole.md)  
```txt  
The AllocConsole function allocates a new console for the calling process.  
```  

***  

[FillConsoleOutputAttribute](libraries/kernel32/FillConsoleOutputAttribute.md)  
```txt  
The FillConsoleOutputAttribute function sets the character attributes for a specified number of character cells, beginning at the specified coordinates in a screen buffer.  
```  

***  

[FillConsoleOutputCharacter](libraries/kernel32/FillConsoleOutputCharacter.md)  
```txt  
The FillConsoleOutputCharacter function writes a character to the console screen buffer a specified number of times, beginning at the specified coordinates.  
```  

***  

[FreeConsole](libraries/kernel32/FreeConsole.md)  
```txt  
The FreeConsole function detaches the calling process from its console.  
```  

***  

[GetConsoleScreenBufferInfo](libraries/kernel32/GetConsoleScreenBufferInfo.md)  
```txt  
The GetConsoleScreenBufferInfo function retrieves information about the specified console screen buffer.  
```  

***  

[GetConsoleWindow](libraries/kernel32/GetConsoleWindow.md)  
```txt  
The GetConsoleWindow function retrieves the window handle used by the console associated with the calling process.  
```  

***  

[GetStdHandle](libraries/kernel32/GetStdHandle.md)  
```txt  
The GetStdHandle function retrieves a handle for the standard input, standard output, or standard error device.  
```  

***  

[ReadConsole](libraries/kernel32/ReadConsole.md)  
```txt  
The ReadConsole function reads character input from the console input buffer and removes it from the buffer.  
```  

***  

[SetConsoleCursorPosition](libraries/kernel32/SetConsoleCursorPosition.md)  
```txt  
The SetConsoleCursorPosition function sets the cursor position in the specified console screen buffer.  
```  

***  

[SetConsoleTextAttribute](libraries/kernel32/SetConsoleTextAttribute.md)  
```txt  
The SetConsoleTextAttribute function sets the attributes of characters written to the console screen buffer by the WriteFile or WriteConsole function, or echoed by the ReadFile or ReadConsole function.   
```  

***  

[SetConsoleTitle](libraries/kernel32/SetConsoleTitle.md)  
```txt  
The SetConsoleTitle function sets the title bar string for the current console window.  
```  

***  

[WriteConsole](libraries/kernel32/WriteConsole.md)  
```txt  
The WriteConsole function writes a character string to a console screen buffer beginning at the current cursor location.  
```  

***  


## @icon-book Coordinate Space and Transformation group
***  

[ClientToScreen](libraries/gdi32/ClientToScreen.md)  
```txt  
Converts the client-area coordinates of a specified point to screen coordinates.  
```  

***  

[DPtoLP](libraries/gdi32/DPtoLP.md)  
```txt  
Converts device coordinates into logical coordinates.  
```  

***  

[GetGraphicsMode](libraries/gdi32/GetGraphicsMode.md)  
```txt  
Retrieves the current graphics mode for the specified device context.  
```  

***  

[GetMapMode](libraries/gdi32/GetMapMode.md)  
```txt  
Retrieves the current mapping mode.  
```  

***  

[GetWorldTransform](libraries/gdi32/GetWorldTransform.md)  
```txt  
Retrieves the current world-space to page-space transformation.  
```  

***  

[LPtoDP](libraries/gdi32/LPtoDP.md)  
```txt  
Converts logical coordinates into device coordinates.   
```  

***  

[ScreenToClient](libraries/user32/ScreenToClient.md)  
```txt  
The ScreenToClient function converts the screen coordinates of a specified point on the screen to client-area coordinates.  
```  

***  

[SetGraphicsMode](libraries/gdi32/SetGraphicsMode.md)  
```txt  
Sets the graphics mode for the specified device context.  
```  

***  

[SetMapMode](libraries/gdi32/SetMapMode.md)  
```txt  
Sets the mapping mode of the specified device context.  
```  

***  


## @icon-book Cryptography Reference group
***  

[CertCloseStore](libraries/crypt32/CertCloseStore.md)  
```txt  
Closes a certificate store handle and reduces the reference count on the store.  
```  

***  

[CertFindCertificateInStore](libraries/crypt32/CertFindCertificateInStore.md)  
```txt  
Finds the first or next certificate context in a certificate store that matches a search criteria established by the dwFindType and its associated pvFindPara.  
```  

***  

[CertFreeCertificateContext](libraries/crypt32/CertFreeCertificateContext.md)  
```txt  
Frees a certificate context by decrementing its reference count.  
```  

***  

[CertOpenSystemStore](libraries/crypt32/CertOpenSystemStore.md)  
```txt  
This is a simplified function that opens the most common system certificate store.  
```  

***  

[CryptAcquireContext](libraries/advapi32/CryptAcquireContext.md)  
```txt  
The CryptAcquireContext function is used to acquire a handle to a particular key container within a particular cryptographic service provider (CSP). This returned handle is used in calls to CryptoAPI functions that use the selected CSP.  
```  

***  

[CryptBinaryToString](libraries/crypt32/CryptBinaryToString.md)  
```txt  
Converts an array of bytes into a formatted string.  
```  

***  

[CryptCreateHash](libraries/advapi32/CryptCreateHash.md)  
```txt  
The CryptCreateHash function initiates the hashing of a stream of data. It creates and returns to the calling application a handle to a CSP hash object.  
```  

***  

[CryptDecrypt](libraries/advapi32/CryptDecrypt.md)  
```txt  
Decrypts data previously encrypted using the CryptEncrypt function.  
```  

***  

[CryptDeriveKey](libraries/advapi32/CryptDeriveKey.md)  
```txt  
Generates cryptographic session keys derived from a base data value.  
```  

***  

[CryptDestroyHash](libraries/advapi32/CryptDestroyHash.md)  
```txt  
The CryptDestroyHash function destroys the hash object referenced by the hHash parameter. After a hash object has been destroyed, it can no longer be used.  
```  

***  

[CryptDestroyKey](libraries/advapi32/CryptDestroyKey.md)  
```txt  
Releases the handle referenced by the hKey parameter. After a key handle has been released, it becomes invalid and cannot be used again.  
```  

***  

[CryptEncrypt](libraries/advapi32/CryptEncrypt.md)  
```txt  
Encrypts data. The algorithm used to encrypt the data is designated by the key held by the CSP module and is referenced by the hKey parameter.
  
```  

***  

[CryptEnumProviderTypes](libraries/advapi32/CryptEnumProviderTypes.md)  
```txt  
Retrieves the first or next types of cryptographic service provider (CSP) supported on the computer. Used in a loop, this function retrieves in sequence all of the CSP types available on a computer.
  
```  

***  

[CryptEnumProviders](libraries/advapi32/CryptEnumProviders.md)  
```txt  
Retrieves the first or next available cryptographic service providers (CSPs). Used in a loop, this function can retrieve in sequence all of the CSPs available on a computer.  
```  

***  

[CryptExportKey](libraries/advapi32/CryptExportKey.md)  
```txt  
Exports a cryptographic key or a key pair from a cryptographic service provider (CSP) in a secure manner.  
```  

***  

[CryptGenKey](libraries/advapi32/CryptGenKey.md)  
```txt  
Generates a random cryptographic session key or a public/private key pair. A handle to the key or key pair is returned in phKey. This handle can then be used as needed with any CryptoAPI function that requires a key handle.  
```  

***  

[CryptGenRandom](libraries/advapi32/CryptGenRandom.md)  
```txt  
Fills a buffer with cryptographically random bytes.  
```  

***  

[CryptGetDefaultProvider](libraries/advapi32/CryptGetDefaultProvider.md)  
```txt  
Finds the default cryptographic service provider (CSP) of a specified provider type. The CSP can be the default for either for the current user or for the computer (LocalMachine).   
```  

***  

[CryptGetHashParam](libraries/advapi32/CryptGetHashParam.md)  
```txt  
Retrieves data that governs the operations of a hash object. The actual hash value can be retrieved by using this function.
  
```  

***  

[CryptGetKeyParam](libraries/advapi32/CryptGetKeyParam.md)  
```txt  
Retrieves data that governs the operations of a key.  
```  

***  

[CryptGetProvParam](libraries/advapi32/CryptGetProvParam.md)  
```txt  
Retrieves parameters that govern the operations of a cryptographic service provider (CSP).  
```  

***  

[CryptHashData](libraries/advapi32/CryptHashData.md)  
```txt  
Adds data to a specified hash object.
  
```  

***  

[CryptImportKey](libraries/advapi32/CryptImportKey.md)  
```txt  
Transfers a cryptographic key from a key BLOB into a cryptographic service provider (CSP).  
```  

***  

[CryptProtectData](libraries/crypt32/CryptProtectData.md)  
```txt  
Performs encryption on the data in a DATA_BLOB structure. Scoped to local computer, or to user credentials.  
```  

***  

[CryptReleaseContext](libraries/advapi32/CryptReleaseContext.md)  
```txt  
The CryptReleaseContext function releases the handle of a cryptographic service provider (CSP) and a key container.  
```  

***  

[CryptStringToBinary](libraries/crypt32/CryptStringToBinary.md)  
```txt  
Converts a formatted string into an array of bytes.  
```  

***  

[CryptUnprotectData](libraries/crypt32/CryptUnprotectData.md)  
```txt  
Decrypts and does an integrity check of the data in a DATA_BLOB structure. Scoped to local computer, or to user credentials.  
```  

***  

[WinVerifyTrust](libraries/wintrust/WinVerifyTrust.md)  
```txt  
Performs a trust verification action on a specified object. The function passes the inquiry to a trust provider that supports the action identifier, if one exists.  
```  

***  


## @icon-book Cursor group
***  

[ClipCursor](libraries/user32/ClipCursor.md)  
```txt  
Confines the cursor to a rectangular area on the screen.  
```  

***  

[GetClipCursor](libraries/user32/GetClipCursor.md)  
```txt  
Retrieves the screen coordinates of the rectangular area to which the cursor is confined.  
```  

***  

[GetCursorInfo](libraries/user32/GetCursorInfo.md)  
```txt  
Retrieves information about the global cursor.  
```  

***  

[GetCursorPos](libraries/user32/GetCursorPos.md)  
```txt  
Retrieves the cursor"s position, in screen coordinates.  
```  

***  

[ShowCursor](libraries/user32/ShowCursor.md)  
```txt  
The ShowCursor function displays or hides the cursor.  
```  

***  


## @icon-book DNS Functions group
***  

[DnsValidateName](libraries/dnsapi/DnsValidateName.md)  
```txt  
Validates the status of a specified DNS name.  
```  

***  


## @icon-book Data Decompression Library group
***  

[RtlCompressBuffer](libraries/ntdll/RtlCompressBuffer.md)  
```txt  
Compresses a buffer and can be used by a file system driver to facilitate the implementation of file compression.  
```  

***  

[RtlDecompressBuffer](libraries/ntdll/RtlDecompressBuffer.md)  
```txt  
Decompresses an entire compressed buffer.  
```  

***  

[RtlGetCompressionWorkSpaceSize](libraries/ntdll/RtlGetCompressionWorkSpaceSize.md)  
```txt  
This function is used to determine the correct size of the WorkSpace buffer for the RtlCompressBuffer and RtlDecompressFragment functions.  
```  

***  


## @icon-book Debugging group
***  

[ReadProcessMemory](libraries/kernel32/ReadProcessMemory.md)  
```txt  
Reads data from an area of memory in a specified process.   
```  

***  

[WriteProcessMemory](libraries/kernel32/WriteProcessMemory.md)  
```txt  
Writes data to an area of memory in a specified process.   
```  

***  


## @icon-book Desktop Window Manager (DWM) group
***  

[DwmExtendFrameIntoClientArea](libraries/dwmapi/DwmExtendFrameIntoClientArea.md)  
```txt  
Extends the window frame behind the client area.  
```  

***  


## @icon-book Device Context group
***  

[ChangeDisplaySettings](libraries/user32/ChangeDisplaySettings.md)  
```txt  
The ChangeDisplaySettings function changes the settings of the default display device to the specified graphics mode.   
```  

***  

[CreateCompatibleDC](libraries/gdi32/CreateCompatibleDC.md)  
```txt  
Creates a memory device context (DC) compatible with the specified device.  
```  

***  

[CreateDC](libraries/gdi32/CreateDC.md)  
```txt  
The CreateDC function creates a device context (DC) for a device using the specified name.  
```  

***  

[DeleteDC](libraries/gdi32/DeleteDC.md)  
```txt  
Deletes the specified device context (DC).  
```  

***  

[DeleteObject](libraries/gdi32/DeleteObject.md)  
```txt  
Deletes a logical pen, brush, font, bitmap, region, or palette, freeing all system resources associated with the object. After the object is deleted, the specified handle is no longer valid.  
```  

***  

[EnumDisplayDevices](libraries/user32/EnumDisplayDevices.md)  
```txt  
The EnumDisplayDevices function lets you obtain information about the display devices in a system.   
```  

***  

[EnumDisplaySettings](libraries/user32/EnumDisplaySettings.md)  
```txt  
The EnumDisplaySettings function retrieves information about one of the graphics modes for a display device. To retrieve information for all the graphics modes of a display device, make a series of calls to this function.  
```  

***  

[GetDC](libraries/user32/GetDC.md)  
```txt  
The GetDC function retrieves a handle of a display device context (DC) for the client area of the specified window  
```  

***  

[GetDeviceCaps](libraries/gdi32/GetDeviceCaps.md)  
```txt  
The GetDeviceCaps function retrieves device-specific information for the specified device.  
```  

***  

[GetObject](libraries/gdi32/GetObject.md)  
```txt  
The GetObject function retrieves information for the specified graphics object.  
```  

***  

[GetObjectType](libraries/gdi32/GetObjectType.md)  
```txt  
The GetObjectType retrieves the type of the specified object.  
```  

***  

[ReleaseDC](libraries/user32/ReleaseDC.md)  
```txt  
The ReleaseDC function releases a device context (DC), freeing it for use by other applications. For memory device contexts use the DeleteDC function.  
```  

***  

[SelectObject](libraries/gdi32/SelectObject.md)  
```txt  
Selects an object into the specified device context (DC). The new object replaces the previous object of the same type.
  
```  

***  


## @icon-book Device Input and Output group
***  

[DeviceIoControl](libraries/kernel32/DeviceIoControl.md)  
```txt  
Sends a control code directly to a specified device driver, causing the corresponding device to perform the corresponding operation.  
```  

***  


## @icon-book Dialog Box group
***  

[GetDlgCtrlID](libraries/user32/GetDlgCtrlID.md)  
```txt  
Retrieves the identifier of the specified control.  
```  

***  

[GetDlgItem](libraries/user32/GetDlgItem.md)  
```txt  
Retrieves a handle to a control in the specified dialog box.   
```  

***  

[MessageBox](libraries/user32/MessageBox.md)  
```txt  
Creates, displays, and operates a message box. The message box contains an application-defined message and title, plus any combination of predefined icons and push buttons  
```  

***  

[MessageBoxIndirect](libraries/user32/MessageBoxIndirect.md)  
```txt  
Creates, displays, and operates a message box. The message box contains application-defined message text and title, any icon, and any combination of predefined push buttons.
  
```  

***  

[SetDlgItemInt](libraries/user32/SetDlgItemInt.md)  
```txt  
The SetDlgItemInt function sets the text of a control in a dialog box to the string representation of a specified integer value.   
```  

***  

[SetDlgItemText](libraries/user32/SetDlgItemText.md)  
```txt  
The SetDlgItemText function sets the title or text of a control in a dialog box.   
```  

***  


## @icon-book Dynamic-Link Library group
***  

[FreeLibrary](libraries/kernel32/FreeLibrary.md)  
```txt  
The FreeLibrary function decrements the reference count of the loaded dynamic-link library (DLL). When the reference count reaches zero, the module is unmapped from the address space of the calling process and the handle is no longer valid  
```  

***  

[GetModuleFileName](libraries/kernel32/GetModuleFileName.md)  
```txt  
Retrieves the full path and file name for the file containing the specified module.  
```  

***  

[GetModuleHandle](libraries/kernel32/GetModuleHandle.md)  
```txt  
Retrieves a module handle for the specified module if the file has been mapped into the address space of the calling process.  
```  

***  

[GetProcAddress](libraries/kernel32/GetProcAddress.md)  
```txt  
Retrieves the address of an exported function or variable from the specified dynamic-link library (DLL).
  
```  

***  

[LoadLibrary](libraries/kernel32/LoadLibrary.md)  
```txt  
The LoadLibrary function maps the specified executable module into the address space of the calling process.

  
```  

***  

[LoadLibraryEx](libraries/kernel32/LoadLibraryEx.md)  
```txt  
Maps the specified executable module into the address space of the calling process. The executable module can be a .dll or an .exe file. The specified module may cause other modules to be mapped into the address space.
  
```  

***  


## @icon-book Error Handling group
***  

[Beep](libraries/kernel32/Beep.md)  
```txt  
Generates simple tones on the speaker. The function is synchronous; it does not return control to its caller until the sound finishes.  
```  

***  

[FatalAppExit](libraries/kernel32/FatalAppExit.md)  
```txt  
The FatalAppExit function displays a message box and terminates the application when the message box is closed.   
```  

***  

[FlashWindow](libraries/user32/FlashWindow.md)  
```txt  
Flashes the specified window one time. It does not change the active state of the window  
```  

***  

[FlashWindowEx](libraries/user32/FlashWindowEx.md)  
```txt  
The FlashWindowEx function flashes the specified window. It does not change the active state of the window.  
```  

***  

[FormatMessage](libraries/kernel32/FormatMessage.md)  
```txt  
The FormatMessage function formats a message string. It can be used to obtain error message strings for the system error codes returned by GetLastError.  
```  

***  

[GetErrorMode](libraries/kernel32/GetErrorMode.md)  
```txt  
Retrieves the error mode for the current process.  
```  

***  

[GetLastError](libraries/kernel32/GetLastError.md)  
```txt  
The GetLastError function retrieves the calling thread"s last-error code value.  
```  

***  

[MessageBeep](libraries/user32/MessageBeep.md)  
```txt  
Plays a waveform sound. The waveform sound for each sound type is identified by an entry in the [sounds] section of the registry  
```  

***  

[SetErrorMode](libraries/kernel32/SetErrorMode.md)  
```txt  
Controls whether the system will handle the specified types of serious errors, or whether the process will handle them.  
```  

***  

[SetLastError](libraries/kernel32/SetLastError.md)  
```txt  
Sets the last-error code for the calling thread. This function is intended primarily for dynamic-link libraries (DLL). Calling this function after an error occurs lets the DLL emulate the behavior of the Win32 API.

If you are defining an error code for your application, be sure that your error code does not conflict with any system-defined error codes.
  
```  

***  


## @icon-book Event Logging group
***  

[ClearEventLog](libraries/advapi32/ClearEventLog.md)  
```txt  
Clears the specified event log, and optionally saves the current copy of the log to a backup file.  
```  

***  

[CloseEventLog](libraries/advapi32/CloseEventLog.md)  
```txt  
Closes a read handle to the specified event log.  
```  

***  

[DeregisterEventSource](libraries/advapi32/DeregisterEventSource.md)  
```txt  
Closes a write handle to the specified event log.  
```  

***  

[GetEventLogInformation](libraries/advapi32/GetEventLogInformation.md)  
```txt  
Retrieves information about the specified event log.  
```  

***  

[GetNumberOfEventLogRecords](libraries/advapi32/GetNumberOfEventLogRecords.md)  
```txt  
Retrieves the number of records in the specified event log.  
```  

***  

[GetOldestEventLogRecord](libraries/advapi32/GetOldestEventLogRecord.md)  
```txt  
Retrieves the absolute record number of the oldest record in the specified event log.  
```  

***  

[OpenEventLog](libraries/advapi32/OpenEventLog.md)  
```txt  
Opens a handle to the specified event log.  
```  

***  

[ReadEventLog](libraries/advapi32/ReadEventLog.md)  
```txt  
Reads a whole number of entries from the specified event log. The function can be used to read log entries in chronological or reverse chronological order.  
```  

***  

[RegisterEventSource](libraries/advapi32/RegisterEventSource.md)  
```txt  
Retrieves a registered handle to the specified event log.  
```  

***  

[ReportEvent](libraries/advapi32/ReportEvent.md)  
```txt  
Writes an entry at the end of the specified event log.  
```  

***  


## @icon-book Extensible Storage Engine (ESE, Jet Blue) group
***  

[JetAddColumn](libraries/esent/JetAddColumn.md)  
```txt  
Adds a new column to an existing table in an ESE database.  
```  

***  

[JetBeginSession](libraries/esent/JetBeginSession.md)  
```txt  
Starts new ESE session and initializes and returns an ESE session handle   
```  

***  

[JetBeginTransaction](libraries/esent/JetBeginTransaction.md)  
```txt  
Causes a session to enter a transaction and create a new save point.  
```  

***  

[JetCloseDatabase](libraries/esent/JetCloseDatabase.md)  
```txt  
Closes a database file that was previously opened with JetOpenDatabase.
  
```  

***  

[JetCloseTable](libraries/esent/JetCloseTable.md)  
```txt  
Closes an open table in a database. The table is a temporary table or a normal table.
  
```  

***  

[JetCommitTransaction](libraries/esent/JetCommitTransaction.md)  
```txt  
Commits the changes made to the state of the database during the current save point and migrates them to the previous save point.  
```  

***  

[JetCreateDatabase](libraries/esent/JetCreateDatabase.md)  
```txt  
Creates and attaches a database file to be used with the ESE database engine.  
```  

***  

[JetCreateInstance](libraries/esent/JetCreateInstance.md)  
```txt  
Allocates a new instance of the database engine for use in a single process.  
```  

***  

[JetCreateTable](libraries/esent/JetCreateTable.md)  
```txt  
Creates an empty table in an ESE database.
  
```  

***  

[JetDeleteTable](libraries/esent/JetDeleteTable.md)  
```txt  
Deletes a table in an ESE database.
  
```  

***  

[JetDetachDatabase](libraries/esent/JetDetachDatabase.md)  
```txt  
Releases a database file that was previously attached to a database session.  
```  

***  

[JetEndSession](libraries/esent/JetEndSession.md)  
```txt  
Ends the session, and cleans up and deallocates any resources associated with the specified session.  
```  

***  

[JetGetColumnInfo](libraries/esent/JetGetColumnInfo.md)  
```txt  
Retrieves information about a column.
  
```  

***  

[JetGotoBookmark](libraries/esent/JetGotoBookmark.md)  
```txt  
Positions a cursor to an index entry for the record that is associated with the specified bookmark.  
```  

***  

[JetInit](libraries/esent/JetInit.md)  
```txt  
Puts the database engine into a state where it can support application use of database files.  
```  

***  

[JetMove](libraries/esent/JetMove.md)  
```txt  
Positions a cursor at the start or end of an index and traverses the entries in that index either forward or backward.  
```  

***  

[JetOpenTable](libraries/esent/JetOpenTable.md)  
```txt  
Opens a cursor on an existing table.
  
```  

***  

[JetPrepareUpdate](libraries/esent/JetPrepareUpdate.md)  
```txt  
This is the first operation in performing an update, for the purposes of inserting a new record or replacing an existing record with new values.  
```  

***  

[JetRetrieveColumn](libraries/esent/JetRetrieveColumn.md)  
```txt  
Retrieves a single column value from the current record.  
```  

***  

[JetRollback](libraries/esent/JetRollback.md)  
```txt  
Undoes the changes made to the state of the database and returns to the last save point.  
```  

***  

[JetSetColumn](libraries/esent/JetSetColumn.md)  
```txt  
Modifies a single column value in a modified record to be inserted or to update the current record.  
```  

***  

[JetTerm](libraries/esent/JetTerm.md)  
```txt  
Initiates the shutdown of an instance that has been initialized by JetInit.
  
```  

***  

[JetUpdate](libraries/esent/JetUpdate.md)  
```txt  
Performs an update operation including inserting a new row into a table or updating an existing row.
  
```  

***  


## @icon-book File Management group
***  

[CopyFile](libraries/kernel32/CopyFile.md)  
```txt  
This function copies an existing file to a new file  
```  

***  

[CopyFileTransacted](libraries/kernel32/CopyFileTransacted.md)  
```txt  
Copies an existing file to a new file as a transacted operation, notifying the application of its progress through a callback function.  
```  

***  

[CreateDirectory](libraries/kernel32/CreateDirectory.md)  
```txt  
Creates a new directory. If the underlying file system supports security on files and directories, the function applies a specified security descriptor to the new directory.
  
```  

***  

[CreateFile](libraries/kernel32/CreateFile.md)  
```txt  
This function creates, opens, or truncates a file, communications resource, disk device, or console. It returns a handle that can be used to access the object. It can also open and return a handle to a directory.

Use the CloseHandle function to close an object handle returned by CreateFile  
```  

***  

[CreateFileTransacted](libraries/kernel32/CreateFileTransacted.md)  
```txt  
Creates or opens a file, file stream, or directory as a transacted operation. The function returns a handle that can be used to access the object.  
```  

***  

[CreateHardLink](libraries/kernel32/CreateHardLink.md)  
```txt  
Establishes a hard link between an existing file and a new file. This function is only supported on the NTFS file system.
  
```  

***  

[CreateSymbolicLink](libraries/kernel32/CreateSymbolicLink.md)  
```txt  
Creates a symbolic link.  
```  

***  

[DeleteFile](libraries/kernel32/DeleteFile.md)  
```txt  
The DeleteFile function deletes an existing file  
```  

***  

[DeleteFileTransacted](libraries/kernel32/DeleteFileTransacted.md)  
```txt  
Deletes an existing file as a transacted operation.  
```  

***  

[FindClose](libraries/kernel32/FindClose.md)  
```txt  
The FindClose function closes the specified search handle. The FindFirstFile and FindNextFile functions use the search handle to locate files with names that match a given name.  
```  

***  

[FindCloseChangeNotification](libraries/kernel32/FindCloseChangeNotification.md)  
```txt  
Stops change notification handle monitoring.  
```  

***  

[FindFirstChangeNotification](libraries/kernel32/FindFirstChangeNotification.md)  
```txt  
Creates a change notification handle and sets up initial change notification filter conditions.

A wait on a notification handle succeeds when a change matching the filter conditions occurs in the specified directory or subtree.
  
```  

***  

[FindFirstFile](libraries/kernel32/FindFirstFile.md)  
```txt  
The FindFirstFile function searches a directory for a file whose name matches the specified file name. FindFirstFile examines subdirectory names as well as file names.  
```  

***  

[FindNextChangeNotification](libraries/kernel32/FindNextChangeNotification.md)  
```txt  
Requests that the operating system signal a change notification handle the next time it detects an appropriate change.  
```  

***  

[FindNextFile](libraries/kernel32/FindNextFile.md)  
```txt  
The FindNextFile function continues a file search from a previous call to the FindFirstFile function.  
```  

***  

[FlushFileBuffers](libraries/kernel32/FlushFileBuffers.md)  
```txt  
Flushes the buffers of a specified file and causes all buffered data to be written to a file.  
```  

***  

[GetBinaryType](libraries/kernel32/GetBinaryType.md)  
```txt  
Determines whether a file is executable, and if so, what type of executable file it is. That last property determines which subsystem an executable file runs under.
  
```  

***  

[GetCurrentDirectory](libraries/kernel32/GetCurrentDirectory.md)  
```txt  
The GetCurrentDirectory function retrieves the current directory for the current process.
  
```  

***  

[GetDriveType](libraries/kernel32/GetDriveType.md)  
```txt  
The GetDriveType function determines whether a disk drive is a removable, fixed, CD-ROM, RAM disk, or network drive  
```  

***  

[GetFileAttributes](libraries/kernel32/GetFileAttributes.md)  
```txt  
Retrieves attributes for a specified file or directory.  
```  

***  

[GetFileAttributesEx](libraries/kernel32/GetFileAttributesEx.md)  
```txt  
Retrieves attributes for a specified file or directory.  
```  

***  

[GetFileInformationByHandle](libraries/kernel32/GetFileInformationByHandle.md)  
```txt  
The GetFileInformationByHandle function retrieves file information for a specified file.  
```  

***  

[GetFileType](libraries/kernel32/GetFileType.md)  
```txt  
The GetFileType function retrieves the file type for the specified file.  
```  

***  

[GetFullPathName](libraries/kernel32/GetFullPathName.md)  
```txt  
Retrieves the full path and file name of a specified file.
  
```  

***  

[GetLongPathName](libraries/kernel32/GetLongPathName.md)  
```txt  
The GetLongPathName function converts the specified path to its long form. If no long path is found, this function simply returns the specified name.   
```  

***  

[GetShortPathName](libraries/kernel32/GetShortPathName.md)  
```txt  
Retrieves the short path form of a specified input path  
```  

***  

[GetTempFileName](libraries/kernel32/GetTempFileName.md)  
```txt  
The GetTempFileName function creates a name for a temporary file.

The specified integer can be nonzero, in which case, the function creates the file name but does not create the file. If you specify zero for the integer, the function creates a unique file name and creates the file in the specified directory.  
```  

***  

[GetTempPath](libraries/kernel32/GetTempPath.md)  
```txt  
The GetTempPath function retrieves the path of the directory designated for temporary files  
```  

***  

[LockFile](libraries/kernel32/LockFile.md)  
```txt  
Locks a region in an open file. Locking a region prevents other processes from accessing the region.  
```  

***  

[MoveFile](libraries/kernel32/MoveFile.md)  
```txt  
The MoveFile function moves an existing file or a directory, including its children.

To specify how to move the file, use the MoveFileEx function  
```  

***  

[MoveFileTransacted](libraries/kernel32/MoveFileTransacted.md)  
```txt  
Moves an existing file or a directory, including its children, as a transacted operation.  
```  

***  

[OpenFile](libraries/kernel32/OpenFile.md)  
```txt  
The OpenFile function creates, opens, reopens, or deletes a file  
```  

***  

[QueryDosDevice](libraries/kernel32/QueryDosDevice.md)  
```txt  
Retrieves information about MS-DOS device names.  
```  

***  

[ReadDirectoryChangesW](libraries/kernel32/ReadDirectoryChangesW.md)  
```txt  
The ReadDirectoryChangesW function retrieves information describing the changes occurring within a directory.  
```  

***  

[ReadFile](libraries/kernel32/ReadFile.md)  
```txt  
Reads data from a file, starting at the position indicated by the file pointer.  
```  

***  

[RemoveDirectory](libraries/kernel32/RemoveDirectory.md)  
```txt  
The RemoveDirectory function deletes an existing empty directory. To recursively delete files and subdirectories in a directory, use the SHFileOperation function.  
```  

***  

[RemoveDirectoryTransacted](libraries/kernel32/RemoveDirectoryTransacted.md)  
```txt  
Deletes an existing empty directory as a transacted operation.  
```  

***  

[ReplaceFile](libraries/kernel32/ReplaceFile.md)  
```txt  
Replaces one file with another file, with the option of creating a backup copy of the original file.   
```  

***  

[SearchPath](libraries/kernel32/SearchPath.md)  
```txt  
The SearchPath function searches for the specified file.   
```  

***  

[SetCurrentDirectory](libraries/kernel32/SetCurrentDirectory.md)  
```txt  
The SetCurrentDirectory function changes the current directory for the current process.  
```  

***  

[SetEndOfFile](libraries/kernel32/SetEndOfFile.md)  
```txt  
Sets the physical file size for the specified file to the current position of the file pointer.  
```  

***  

[SetFileAttributes](libraries/kernel32/SetFileAttributes.md)  
```txt  
Sets a file"s attributes.
  
```  

***  

[SetFilePointer](libraries/kernel32/SetFilePointer.md)  
```txt  
The SetFilePointer function moves the file pointer of an open file.  
```  

***  

[SetFilePointerEx](libraries/kernel32/SetFilePointerEx.md)  
```txt  
Moves the file pointer of the specified file.  
```  

***  

[SetSearchPathMode](libraries/kernel32/SetSearchPathMode.md)  
```txt  
Sets the per-process mode that the SearchPath function uses when locating files.  
```  

***  

[UnlockFile](libraries/kernel32/UnlockFile.md)  
```txt  
Unlocks a region in an open file. Unlocking a region enables other processes to access the region.  
```  

***  

[WriteFile](libraries/kernel32/WriteFile.md)  
```txt  
The WriteFile function writes data to a file and is designed for both synchronous and asynchronous operation.   
```  

***  

[_lclose](libraries/kernel32/_lclose.md)  
```txt  
Closes the specified file so that it is no longer available for reading or writing.  
```  

***  

[_lopen](libraries/kernel32/_lopen.md)  
```txt  
Opens an existing file and sets the file pointer to the beginning of the file.  
```  

***  


## @icon-book File Mapping group
***  

[CreateFileMapping](libraries/kernel32/CreateFileMapping.md)  
```txt  
The CreateFileMapping function creates or opens a named or unnamed file mapping object for the specified file.  
```  

***  

[GetMappedFileName](libraries/kernel32/GetMappedFileName.md)  
```txt  
The GetMappedFileName function checks if the specified address is within a memory-mapped file in the address space of the specified process. If so, the function returns the name of the memory-mapped file.  
```  

***  

[MapViewOfFile](libraries/kernel32/MapViewOfFile.md)  
```txt  
The MapViewOfFile function maps a view of a file mapping into the address space of the calling process.  
```  

***  

[UnmapViewOfFile](libraries/kernel32/UnmapViewOfFile.md)  
```txt  
The UnmapViewOfFile function unmaps a mapped view of a file from the calling process"s address space.  
```  

***  


## @icon-book File System group
***  

[DeleteVolumeMountPoint](libraries/kernel32/DeleteVolumeMountPoint.md)  
```txt  
Unmounts the volume from the specified volume mount point.  
```  

***  

[FindFirstVolume](libraries/kernel32/FindFirstVolume.md)  
```txt  
Returns the name of a volume on a computer. This call is used to begin scanning the volumes of a computer.  
```  

***  

[FindFirstVolumeMountPoint](libraries/kernel32/FindFirstVolumeMountPoint.md)  
```txt  
Returns the name of a volume mount point on the specified volume. It is used to begin scanning the volume mount points on a volume.
  
```  

***  

[FindNextVolume](libraries/kernel32/FindNextVolume.md)  
```txt  
Continues a volume search started by a call to the FindFirstVolume function.  
```  

***  

[FindNextVolumeMountPoint](libraries/kernel32/FindNextVolumeMountPoint.md)  
```txt  
Continues a volume mount point search started by a call to the FindFirstVolumeMountPoint function.   
```  

***  

[FindVolumeClose](libraries/kernel32/FindVolumeClose.md)  
```txt  
Closes the specified volume search handle created with the FindFirstVolume and FindNextVolume call.  
```  

***  

[FindVolumeMountPointClose](libraries/kernel32/FindVolumeMountPointClose.md)  
```txt  
Closes the specified mount-point search handle.  
```  

***  

[GetCompressedFileSize](libraries/kernel32/GetCompressedFileSize.md)  
```txt  
Retrieves the actual number of bytes of disk storage used to store a specified file. If the file is located on a volume that supports compression/sparse files, and the file is compressed, the value obtained is the compressed/sparse size of the specified file  
```  

***  

[GetDiskFreeSpace](libraries/kernel32/GetDiskFreeSpace.md)  
```txt  
[Obsolete] Retrieves information about the specified disk, including the amount of free space on the disk.
  
```  

***  

[GetDiskFreeSpaceEx](libraries/kernel32/GetDiskFreeSpaceEx.md)  
```txt  
Retrieves information about the amount of space available on a disk volume: the total amount of space, the total amount of free space, and the total amount of free space available to the user associated with the calling thread.  
```  

***  

[GetFileSize](libraries/kernel32/GetFileSize.md)  
```txt  
Retrieves the size of a specified file.  
```  

***  

[GetFileSizeEx](libraries/kernel32/GetFileSizeEx.md)  
```txt  
The GetFileSizeEx function retrieves the size of the specified file.  
```  

***  

[GetLogicalDriveStrings](libraries/kernel32/GetLogicalDriveStrings.md)  
```txt  
The GetLogicalDriveStrings function fills a buffer with strings that specify valid drives in the system  
```  

***  

[GetLogicalDrives](libraries/kernel32/GetLogicalDrives.md)  
```txt  
The GetLogicalDrives function retrieves a bitmask representing the currently available disk drives  
```  

***  

[GetVolumeInformation](libraries/kernel32/GetVolumeInformation.md)  
```txt  
Retrieves information about a file system and volume whose root directory is specified.  
```  

***  

[GetVolumeNameForVolumeMountPoint](libraries/kernel32/GetVolumeNameForVolumeMountPoint.md)  
```txt  
Takes a volume mount point or root directory and returns the corresponding unique volume name.  
```  

***  

[GetVolumePathNamesForVolumeName](libraries/kernel32/GetVolumePathNamesForVolumeName.md)  
```txt  
Retrieves a list of path names for the specified volume name.
  
```  

***  

[SetVolumeLabel](libraries/kernel32/SetVolumeLabel.md)  
```txt  
The SetVolumeLabel function sets the label of a file system volume.  
```  

***  

[SetVolumeMountPoint](libraries/kernel32/SetVolumeMountPoint.md)  
```txt  
Mounts the specified volume at the specified volume mount point.  
```  

***  


## @icon-book Filled Shape group
***  

[FillRect](libraries/gdi32/FillRect.md)  
```txt  
The FillRect function fills a rectangle by using the specified brush. This function includes the left and top borders, but excludes the right and bottom borders of the rectangle.   
```  

***  

[Polygon](libraries/gdi32/Polygon.md)  
```txt  
The Polygon function draws a polygon consisting of two or more vertices connected by straight lines. The polygon is outlined by using the current pen and filled by using the current brush and polygon fill mode.  
```  

***  


## @icon-book Font and Text group
***  

[CreateFont](libraries/gdi32/CreateFont.md)  
```txt  
Creates a logical font with the specified characteristics. The logical font can subsequently be selected as the font for any device.  
```  

***  

[DrawText](libraries/user32/DrawText.md)  
```txt  
The DrawText function draws formatted text in the specified rectangle. It formats the text according to the specified method (expanding tabs, justifying characters, breaking lines, and so forth).   
```  

***  

[GetCharABCWidths](libraries/gdi32/GetCharABCWidths.md)  
```txt  
Retrieves the widths, in logical units, of consecutive characters in a specified range from the current TrueType font. This function succeeds only with TrueType fonts.  
```  

***  

[GetTextAlign](libraries/gdi32/GetTextAlign.md)  
```txt  
The GetTextAlign function retrieves the text-alignment setting for the specified device context.  
```  

***  

[GetTextCharacterExtra](libraries/gdi32/GetTextCharacterExtra.md)  
```txt  
The GetTextCharacterExtra function retrieves the current intercharacter spacing for the specified device context.   
```  

***  

[GetTextColor](libraries/gdi32/GetTextColor.md)  
```txt  
The GetTextColor function retrieves the current text color for the specified device context.  
```  

***  

[GetTextExtentPoint32](libraries/gdi32/GetTextExtentPoint32.md)  
```txt  
The GetTextExtentPoint32 function computes the width and height of the specified string of text.  
```  

***  

[GetTextFace](libraries/gdi32/GetTextFace.md)  
```txt  
The GetTextFace function retrieves the typeface name of the font that is selected into the specified device context.   
```  

***  

[GetTextMetrics](libraries/gdi32/GetTextMetrics.md)  
```txt  
The GetTextMetrics function fills the specified buffer with the metrics for the currently selected font.   
```  

***  

[SetTextAlign](libraries/gdi32/SetTextAlign.md)  
```txt  
The SetTextAlign function sets the text-alignment flags for the specified device context.   
```  

***  

[SetTextCharacterExtra](libraries/gdi32/SetTextCharacterExtra.md)  
```txt  
The SetTextCharacterExtra function sets the intercharacter spacing. Intercharacter spacing is added to each character, including break characters, when the system writes a line of text.   
```  

***  

[SetTextColor](libraries/gdi32/SetTextColor.md)  
```txt  
Sets the text color for the specified device context to the specified color.  
```  

***  

[TextOut](libraries/gdi32/TextOut.md)  
```txt  
Writes a character string at the specified location, using the currently selected font, background color, and text color.
  
```  

***  


## @icon-book GDI+ group
***  

[GdipGetImageDecoders](libraries/gdiplus/GdipGetImageDecoders.md)  
```txt  
The GetImageDecoders function gets an array of ImageCodecInfo objects that contain information about the available image decoders.  
```  

***  

[GdipGetImageDecodersSize](libraries/gdiplus/GdipGetImageDecodersSize.md)  
```txt  
The GetImageDecodersSize function gets the number of available image decoders and the total size of the array of ImageCodecInfo objects that is returned by the GetImageDecoders function.  
```  

***  

[GdipGetImageEncoders](libraries/gdiplus/GdipGetImageEncoders.md)  
```txt  
The GetImageEncoders function gets an array of ImageCodecInfo objects that contain information about the available image encoders.  
```  

***  

[GdipGetImageEncodersSize](libraries/gdiplus/GdipGetImageEncodersSize.md)  
```txt  
The GetImageEncodersSize function gets the number of available image encoders and the total size of the array of ImageCodecInfo objects that is returned by the GetImageEncoders function.  
```  

***  

[GdiplusShutdown](libraries/gdiplus/GdiplusShutdown.md)  
```txt  
The GdiplusShutdown function cleans up resources used by Microsoft® Windows® GDI+.  
```  

***  

[GdiplusStartup](libraries/gdiplus/GdiplusStartup.md)  
```txt  
The GdiplusStartup function initializes Microsoft® Windows® GDI+.  
```  

***  


## @icon-book GDI+ Bitmap group
***  

[GdipBitmapGetPixel](libraries/gdiplus/GdipBitmapGetPixel.md)  
```txt  
Gets the color value of an individual pixel.  
```  

***  

[GdipBitmapSetPixel](libraries/gdiplus/GdipBitmapSetPixel.md)  
```txt  
Sets the color value of an individual pixel.  
```  

***  

[GdipBitmapSetResolution](libraries/gdiplus/GdipBitmapSetResolution.md)  
```txt  
Sets the resolution of this Bitmap object.  
```  

***  

[GdipCloneBitmapArea](libraries/gdiplus/GdipCloneBitmapArea.md)  
```txt  
Creates a new Bitmap object by copying a portion of this bitmap.  
```  

***  

[GdipCreateBitmapFromGdiDib](libraries/gdiplus/GdipCreateBitmapFromGdiDib.md)  
```txt  
Creates a Bitmap object based on a BITMAPINFO structure and an array of pixel data.  
```  

***  

[GdipCreateBitmapFromGraphics](libraries/gdiplus/GdipCreateBitmapFromGraphics.md)  
```txt  
Creates a Bitmap object based on a Graphics object, a width, and a height.  
```  

***  

[GdipCreateBitmapFromHBITMAP](libraries/gdiplus/GdipCreateBitmapFromHBITMAP.md)  
```txt  
Creates a Bitmap object based on a handle to a Windows Microsoft® Windows® Graphics Device Interface (GDI) bitmap and a handle to a GDI palette.  
```  

***  

[GdipCreateBitmapFromHICON](libraries/gdiplus/GdipCreateBitmapFromHICON.md)  
```txt  
Creates a Bitmap object based on a handle to an icon.  
```  

***  

[GdipCreateHBITMAPFromBitmap](libraries/gdiplus/GdipCreateHBITMAPFromBitmap.md)  
```txt  
Creates a Microsoft® Windows® Graphics Device Interface (GDI) bitmap from this GDI+ Bitmap handle.
  
```  

***  

[GdipCreateHICONFromBitmap](libraries/gdiplus/GdipCreateHICONFromBitmap.md)  
```txt  
Creates an icon from this Bitmap object.  
```  

***  


## @icon-book GDI+ Brush group
***  

[GdipCreateSolidFill](libraries/gdiplus/GdipCreateSolidFill.md)  
```txt  
Creates a SolidBrush object based on a color.  
```  

***  

[GdipCreateTexture](libraries/gdiplus/GdipCreateTexture.md)  
```txt  
Creates a brush that contains an Image object that is used for the fill.  
```  

***  

[GdipDeleteBrush](libraries/gdiplus/GdipDeleteBrush.md)  
```txt  
Deletes the specified Brush object.  
```  

***  

[GdipScaleTextureTransform](libraries/gdiplus/GdipScaleTextureTransform.md)  
```txt  
Updates this texture brush"s current transformation matrix with the product of itself and a scaling matrix.  
```  

***  


## @icon-book GDI+ Font group
***  

[GdipCreateFont](libraries/gdiplus/GdipCreateFont.md)  
```txt  
Creates a Font handle based on a FontFamily handle, a size, a font style, and a unit of measurement.  
```  

***  

[GdipCreateFontFamilyFromName](libraries/gdiplus/GdipCreateFontFamilyFromName.md)  
```txt  
Creates a FontFamily handle based on specified font family name.  
```  

***  

[GdipDeleteFont](libraries/gdiplus/GdipDeleteFont.md)  
```txt  
Deletes the specified Font object.  
```  

***  

[GdipDeleteFontFamily](libraries/gdiplus/GdipDeleteFontFamily.md)  
```txt  
Deletes the specified FontFamily object.  
```  

***  

[GdipGetFamilyName](libraries/gdiplus/GdipGetFamilyName.md)  
```txt  
Gets the name of this font family.  
```  

***  

[GdipGetFontCollectionFamilyCount](libraries/gdiplus/GdipGetFontCollectionFamilyCount.md)  
```txt  
Gets the number of font families contained in this font collection  
```  

***  

[GdipGetFontCollectionFamilyList](libraries/gdiplus/GdipGetFontCollectionFamilyList.md)  
```txt  
Gets list of the font families contained in this font collection.  
```  

***  

[GdipIsStyleAvailable](libraries/gdiplus/GdipIsStyleAvailable.md)  
```txt  
Determines whether the specified style is available for this font family.  
```  

***  

[GdipNewInstalledFontCollection](libraries/gdiplus/GdipNewInstalledFontCollection.md)  
```txt  
Represents the fonts installed on the system  
```  

***  


## @icon-book GDI+ Graphics group
***  

[GdipCreateFromHDC](libraries/gdiplus/GdipCreateFromHDC.md)  
```txt  
Returns handle to the Graphics object associated with the device context.  
```  

***  

[GdipCreateFromHDC2](libraries/gdiplus/GdipCreateFromHDC2.md)  
```txt  
Returns handle to the Graphics object that is associated with a specified device context and a specified device.

  
```  

***  

[GdipCreateFromHWND](libraries/gdiplus/GdipCreateFromHWND.md)  
```txt  
Returns handle to the Graphics object associated with the windows handle.  
```  

***  

[GdipDeleteGraphics](libraries/gdiplus/GdipDeleteGraphics.md)  
```txt  
Deletes the Graphics object created by GdipCreateFromHWND, GdipCreateFromHDC or GdipCreateFromHDC2 function.  
```  

***  

[GdipDrawImageI](libraries/gdiplus/GdipDrawImageI.md)  
```txt  
Draws an image at a specified location.  
```  

***  

[GdipDrawImageRectI](libraries/gdiplus/GdipDrawImageRectI.md)  
```txt  
Draws an image  
```  

***  

[GdipDrawImageRectRectI](libraries/gdiplus/GdipDrawImageRectRectI.md)  
```txt  
Draws an image optionally using a ImageAttributes object.  
```  

***  

[GdipDrawLineI](libraries/gdiplus/GdipDrawLineI.md)  
```txt  
Uses a pen to draw a line.  
```  

***  

[GdipDrawPieI](libraries/gdiplus/GdipDrawPieI.md)  
```txt  
Draws a pie.
  
```  

***  

[GdipDrawRectangle](libraries/gdiplus/GdipDrawRectangle.md)  
```txt  
Uses a pen to draw a rectangle.  
```  

***  

[GdipFillPieI](libraries/gdiplus/GdipFillPieI.md)  
```txt  
Uses a brush to fill the interior of a pie.  
```  

***  

[GdipFillRectangle](libraries/gdiplus/GdipFillRectangle.md)  
```txt  
Uses a brush to fill the interior of a rectangle.  
```  

***  

[GdipGetDC](libraries/gdiplus/GdipGetDC.md)  
```txt  
Gets a handle to the device context associated with this Graphics object.
  
```  

***  

[GdipGetDpiX](libraries/gdiplus/GdipGetDpiX.md)  
```txt  
Gets the horizontal resolution, in dots per inch, of the display device associated with this Graphics handle.  
```  

***  

[GdipGetDpiY](libraries/gdiplus/GdipGetDpiY.md)  
```txt  
Gets the vertical resolution, in dots per inch, of the display device associated with this Graphics handle.  
```  

***  

[GdipGetPageScale](libraries/gdiplus/GdipGetPageScale.md)  
```txt  
Gets the scaling factor currently set for the page transformation of this Graphics handle.  
```  

***  

[GdipGetPageUnit](libraries/gdiplus/GdipGetPageUnit.md)  
```txt  
Returns an element of the Unit enumeration that indicates the unit of measure currently set for this Graphics handle.  
```  

***  

[GdipGetSmoothingMode](libraries/gdiplus/GdipGetSmoothingMode.md)  
```txt  
Determines whether smoothing (antialiasing) is applied to the Graphics object.  
```  

***  

[GdipReleaseDC](libraries/gdiplus/GdipReleaseDC.md)  
```txt  
Releases a device context handle obtained by a previous call to the GdipGetHDC with this Graphics handle.
  
```  

***  

[GdipResetWorldTransform](libraries/gdiplus/GdipResetWorldTransform.md)  
```txt  
Sets the world transformation matrix of this Graphics object to the identity matrix.  
```  

***  

[GdipRotateWorldTransform](libraries/gdiplus/GdipRotateWorldTransform.md)  
```txt  
Updates the world transformation matrix of this Graphics object with the product of itself and a rotation matrix.
  
```  

***  

[GdipSetClipRectI](libraries/gdiplus/GdipSetClipRectI.md)  
```txt  
Sets the clipping region of this Graphics object by a specified rectangle.  
```  

***  

[GdipSetPageScale](libraries/gdiplus/GdipSetPageScale.md)  
```txt  
Sets the scaling factor for the page transformation of this Graphics handle.  
```  

***  

[GdipSetPageUnit](libraries/gdiplus/GdipSetPageUnit.md)  
```txt  
Sets the unit of measure for this Graphics handle.   
```  

***  

[GdipSetSmoothingMode](libraries/gdiplus/GdipSetSmoothingMode.md)  
```txt  
Sets the rendering quality of the Graphics object.  
```  

***  

[GdipSetTextRenderingHint](libraries/gdiplus/GdipSetTextRenderingHint.md)  
```txt  
Sets the text rendering mode of this Graphics object.  
```  

***  

[GdipSetWorldTransform](libraries/gdiplus/GdipSetWorldTransform.md)  
```txt  
Sets the world transformation of this Graphics object.
  
```  

***  

[GdipTranslateWorldTransform](libraries/gdiplus/GdipTranslateWorldTransform.md)  
```txt  
Updates this Graphics object"s world transformation matrix with the product of itself and a translation matrix.  
```  

***  


## @icon-book GDI+ Image group
***  

[GdipDisposeImage](libraries/gdiplus/GdipDisposeImage.md)  
```txt  
The GdipDisposeImage releases an Image object.  
```  

***  

[GdipGetImageFlags](libraries/gdiplus/GdipGetImageFlags.md)  
```txt  
Gets a set of flags that indicate certain attributes of this Image object.
  
```  

***  

[GdipGetImageGraphicsContext](libraries/gdiplus/GdipGetImageGraphicsContext.md)  
```txt  
Creates a Graphics object that is associated with an Image object.  
```  

***  

[GdipGetImageHeight](libraries/gdiplus/GdipGetImageHeight.md)  
```txt  
Gets the height, in pixels, of this image.  
```  

***  

[GdipGetImageHorizontalResolution](libraries/gdiplus/GdipGetImageHorizontalResolution.md)  
```txt  
Gets the horizontal resolution of this image.  
```  

***  

[GdipGetImagePalette](libraries/gdiplus/GdipGetImagePalette.md)  
```txt  
Gets the color palette of this Image object.  
```  

***  

[GdipGetImagePaletteSize](libraries/gdiplus/GdipGetImagePaletteSize.md)  
```txt  
Gets the size, in bytes, of the color palette of this Image object.
  
```  

***  

[GdipGetImageRawFormat](libraries/gdiplus/GdipGetImageRawFormat.md)  
```txt  
Gets a globally unique identifier (GUID) that identifies the format of this Image object.  
```  

***  

[GdipGetImageType](libraries/gdiplus/GdipGetImageType.md)  
```txt  
Gets the type (bitmap or metafile) of this Image object.
  
```  

***  

[GdipGetImageVerticalResolution](libraries/gdiplus/GdipGetImageVerticalResolution.md)  
```txt  
Sets the vertical resolution of this image.  
```  

***  

[GdipGetImageWidth](libraries/gdiplus/GdipGetImageWidth.md)  
```txt  
Gets the width, in pixels, of this image.  
```  

***  

[GdipGetPropertyCount](libraries/gdiplus/GdipGetPropertyCount.md)  
```txt  
Gets the number of properties (pieces of metadata) stored in this Image object.   
```  

***  

[GdipGetPropertyIdList](libraries/gdiplus/GdipGetPropertyIdList.md)  
```txt  
Gets a list of the property identifiers used in the metadata of this Image object.  
```  

***  

[GdipGetPropertyItem](libraries/gdiplus/GdipGetPropertyItem.md)  
```txt  
Gets a specified property item (piece of metadata) from this Image object.  
```  

***  

[GdipGetPropertyItemSize](libraries/gdiplus/GdipGetPropertyItemSize.md)  
```txt  
Gets the size, in bytes, of a specified property item of this Image object.  
```  

***  

[GdipLoadImageFromFile](libraries/gdiplus/GdipLoadImageFromFile.md)  
```txt  
Creates an Image object based on a file.  
```  

***  

[GdipRemovePropertyItem](libraries/gdiplus/GdipRemovePropertyItem.md)  
```txt  
Removes a property item (piece of metadata) from this Image object.  
```  

***  

[GdipSaveImageToFile](libraries/gdiplus/GdipSaveImageToFile.md)  
```txt  
Saves this image to a file.  
```  

***  

[GdipSetImagePalette](libraries/gdiplus/GdipSetImagePalette.md)  
```txt  
Sets the color palette of this Image object.
  
```  

***  

[GdipSetPropertyItem](libraries/gdiplus/GdipSetPropertyItem.md)  
```txt  
Sets a property item (piece of metadata) for this Image object.  
```  

***  


## @icon-book GDI+ ImageAttributes group
***  

[GdipCreateImageAttributes](libraries/gdiplus/GdipCreateImageAttributes.md)  
```txt  
Creates new ImageAttributes object.  
```  

***  

[GdipDisposeImageAttributes](libraries/gdiplus/GdipDisposeImageAttributes.md)  
```txt  
Disposes the ImageAttributes object created by GdipCreateImageAttributes function.  
```  

***  

[GdipSetImageAttributesColorKeys](libraries/gdiplus/GdipSetImageAttributesColorKeys.md)  
```txt  
Sets the color key (transparency range) for a specified ColorAdjustType.  
```  

***  


## @icon-book GDI+ Matrix group
***  

[GdipCreateMatrix](libraries/gdiplus/GdipCreateMatrix.md)  
```txt  
Creates and initializes a Matrix object that represents the identity matrix.  
```  

***  

[GdipCreateMatrix2](libraries/gdiplus/GdipCreateMatrix2.md)  
```txt  
Creates and initializes a a 3 ×3 matrix that represents an affine transformation.  
```  

***  

[GdipDeleteMatrix](libraries/gdiplus/GdipDeleteMatrix.md)  
```txt  
Deletes the Matrix object created by GdipCreateMatrix, GdipCloneMatrix and similar functions.  
```  

***  

[GdipGetMatrixElements](libraries/gdiplus/GdipGetMatrixElements.md)  
```txt  
Gets the elements of this matrix. The elements are placed in an array in the order m11, m12, m21, m22, m31, m32, where mij denotes the element in row i, column j.
  
```  

***  

[GdipInvertMatrix](libraries/gdiplus/GdipInvertMatrix.md)  
```txt  
For invertible matrix, replaces the elements of this matrix with the elements of its inverse.

  
```  

***  

[GdipRotateMatrix](libraries/gdiplus/GdipRotateMatrix.md)  
```txt  
Updates this matrix with the product of itself and a rotation matrix.
  
```  

***  

[GdipScaleMatrix](libraries/gdiplus/GdipScaleMatrix.md)  
```txt  
Updates this matrix with the product of itself and a scaling matrix.  
```  

***  

[GdipSetMatrixElements](libraries/gdiplus/GdipSetMatrixElements.md)  
```txt  
Sets the elements of this matrix.  
```  

***  

[GdipShearMatrix](libraries/gdiplus/GdipShearMatrix.md)  
```txt  
Updates this matrix with the product of itself and a shearing matrix.
  
```  

***  

[GdipTranslateMatrix](libraries/gdiplus/GdipTranslateMatrix.md)  
```txt  
Updates this matrix with the product of itself and a translation matrix.
  
```  

***  


## @icon-book GDI+ PathGradient Brush group
***  

[GdipCreatePathGradientI](libraries/gdiplus/GdipCreatePathGradientI.md)  
```txt  
Creates a PathGradient Brush object based on an array of points. Initializes the wrap mode of the path gradient brush.  
```  

***  

[GdipSetPathGradientCenterColor](libraries/gdiplus/GdipSetPathGradientCenterColor.md)  
```txt  
Sets the center color of this path gradient brush. The center color is the color that appears at the brush`s center point.  
```  

***  

[GdipSetPathGradientCenterPointI](libraries/gdiplus/GdipSetPathGradientCenterPointI.md)  
```txt  
Sets the center point of this path gradient brush.  
```  

***  


## @icon-book GDI+ Pen group
***  

[GdipCreatePen1](libraries/gdiplus/GdipCreatePen1.md)  
```txt  
Creates a Pen object that uses a specified color and width.  
```  

***  

[GdipDeletePen](libraries/gdiplus/GdipDeletePen.md)  
```txt  
Deletes the specified Pen object.  
```  

***  


## @icon-book GDI+ StringFormat group
***  

[GdipCreateStringFormat](libraries/gdiplus/GdipCreateStringFormat.md)  
```txt  
Creates a StringFormat object based on string format flags and a language.  
```  

***  

[GdipDeleteStringFormat](libraries/gdiplus/GdipDeleteStringFormat.md)  
```txt  
Deletes the specified StringFormat object .  
```  

***  


## @icon-book GDI+ Text group
***  

[GdipDrawString](libraries/gdiplus/GdipDrawString.md)  
```txt  
Draws a string based on a font, a layout rectangle, and a format  
```  

***  

[GdipMeasureString](libraries/gdiplus/GdipMeasureString.md)  
```txt  
Measures the extent of the string in the specified font, format, and layout rectangle.
  
```  

***  


## @icon-book HTTP Functions (WinHTTP) group
***  

[WinHttpAddRequestHeaders](libraries/winhttp/WinHttpAddRequestHeaders.md)  
```txt  
The WinHttpAddRequestHeaders function adds one or more HTTP request headers to the HTTP request handle.  
```  

***  

[WinHttpCloseHandle](libraries/winhttp/WinHttpCloseHandle.md)  
```txt  
The WinHttpCloseHandle function closes a single HINTERNET handle.  
```  

***  

[WinHttpConnect](libraries/winhttp/WinHttpConnect.md)  
```txt  
Specifies the initial target server of an HTTP request and returns an HINTERNET connection handle to an HTTP session for that initial target.  
```  

***  

[WinHttpCrackUrl](libraries/winhttp/WinHttpCrackUrl.md)  
```txt  
The WinHttpCrackUrl function separates a URL into its component parts such as host name and path.  
```  

***  

[WinHttpOpen](libraries/winhttp/WinHttpOpen.md)  
```txt  
Initializes an application"s use of the WinHTTP functions and returns a WinHTTP-session handle.  
```  

***  

[WinHttpOpenRequest](libraries/winhttp/WinHttpOpenRequest.md)  
```txt  
The WinHttpOpenRequest function creates an HTTP request handle.  
```  

***  

[WinHttpQueryDataAvailable](libraries/winhttp/WinHttpQueryDataAvailable.md)  
```txt  
The WinHttpQueryDataAvailable function returns the number of bytes of data that are immediately available to be read with WinHttpReadData.  
```  

***  

[WinHttpQueryHeaders](libraries/winhttp/WinHttpQueryHeaders.md)  
```txt  
The WinHttpQueryHeaders function retrieves header information associated with an HTTP request.  
```  

***  

[WinHttpReadData](libraries/winhttp/WinHttpReadData.md)  
```txt  
The WinHttpReadData function reads data from a handle opened by the WinHttpOpenRequest function.  
```  

***  

[WinHttpReceiveResponse](libraries/winhttp/WinHttpReceiveResponse.md)  
```txt  
The WinHttpReceiveResponse function waits to receive the response to an HTTP request initiated by WinHttpSendRequest.  
```  

***  

[WinHttpSendRequest](libraries/winhttp/WinHttpSendRequest.md)  
```txt  
The WinHttpSendRequest function sends the specified request to the HTTP server.  
```  

***  

[WinHttpSetCredentials](libraries/winhttp/WinHttpSetCredentials.md)  
```txt  
The WinHttpSetCredentials function passes the required authorization credentials to the server.  
```  

***  


## @icon-book Handle and Object group
***  

[CloseHandle](libraries/kernel32/CloseHandle.md)  
```txt  
The CloseHandle function closes an open object handle.

The CloseHandle function closes handles to the following objects:
	- Access token
	- Communications device
	- Console input
	- Console screen buffer
	- Event
	- File
	- File mapping
	- Job
	- Mailslot
	- Mutex (<B>Mut</B>ually<B>Ex</B>clusive)
	- Named pipe
	- Process
	- Semaphore
	- Socket
  
```  

***  

[DuplicateHandle](libraries/kernel32/DuplicateHandle.md)  
```txt  
The DuplicateHandle function duplicates an object handle.
  
```  

***  

[GetHandleInformation](libraries/kernel32/GetHandleInformation.md)  
```txt  
The GetHandleInformation function retrieves certain properties of an object handle.  
```  

***  

[SetHandleInformation](libraries/kernel32/SetHandleInformation.md)  
```txt  
Sets certain properties of an object handle.  
```  

***  


## @icon-book Hook group
***  

[SetWindowsHookEx](libraries/user32/SetWindowsHookEx.md)  
```txt  
Installs an application-defined hook procedure into a hook chain.  
```  

***  

[UnhookWindowsHookEx](libraries/user32/UnhookWindowsHookEx.md)  
```txt  
Removes a hook procedure installed in a hook chain by the SetWindowsHookEx function.   
```  

***  


## @icon-book IP Helper group
***  

[GetAdaptersAddresses](libraries/iphlpapi/GetAdaptersAddresses.md)  
```txt  
Retrieves the addresses associated with the adapters on the local computer.  
```  

***  

[GetAdaptersInfo](libraries/iphlpapi/GetAdaptersInfo.md)  
```txt  
The GetAdaptersInfo function retrieves adapter information for the local computer.  
```  

***  

[GetBestInterface](libraries/iphlpapi/GetBestInterface.md)  
```txt  
Retrieves the index of the interface that has the best route to the specified IPv4 address.  
```  

***  

[GetBestRoute](libraries/iphlpapi/GetBestRoute.md)  
```txt  
Retrieves the best route to the specified destination IP address.
  
```  

***  

[GetIfEntry](libraries/iphlpapi/GetIfEntry.md)  
```txt  
The GetIfEntry function retrieves information for the specified interface on the local computer.  
```  

***  

[GetInterfaceInfo](libraries/iphlpapi/GetInterfaceInfo.md)  
```txt  
The GetInterfaceInfo function obtains a list of the network interface adapters on the local system.  
```  

***  

[GetIpAddrTable](libraries/iphlpapi/GetIpAddrTable.md)  
```txt  
The GetIpAddrTable function retrieves the interface–to–IP address mapping table.  
```  

***  

[GetIpNetTable](libraries/iphlpapi/GetIpNetTable.md)  
```txt  
The GetIpNetTable function retrieves the IP-to-physical address mapping table.  
```  

***  

[GetIpStatistics](libraries/iphlpapi/GetIpStatistics.md)  
```txt  
The GetIpStatistics function retrieves the IP statistics for the current computer.  
```  

***  

[GetNetworkParams](libraries/iphlpapi/GetNetworkParams.md)  
```txt  
The GetNetworkParams function retrieves network parameters for the local computer.  
```  

***  

[GetNumberOfInterfaces](libraries/iphlpapi/GetNumberOfInterfaces.md)  
```txt  
Returns the number of network interfaces on the local computer, including the loopback interface.   
```  

***  

[GetRTTAndHopCount](libraries/iphlpapi/GetRTTAndHopCount.md)  
```txt  
The GetRTTAndHopCount function determines the round-trip time (RTT) and hop count to the specified destination.  
```  

***  

[GetTcp6Table](libraries/iphlpapi/GetTcp6Table.md)  
```txt  
Retrieves the TCP connection table for IPv6.  
```  

***  

[GetTcpStatistics](libraries/iphlpapi/GetTcpStatistics.md)  
```txt  
The GetTcpStatistics function retrieves the TCP statistics for the local computer.  
```  

***  

[GetTcpTable](libraries/iphlpapi/GetTcpTable.md)  
```txt  
The GetTcpTable function retrieves the TCP connection table.  
```  

***  

[GetUdpTable](libraries/iphlpapi/GetUdpTable.md)  
```txt  
The GetUdpTable function retrieves the User Datagram Protocol (UDP) listener table.  
```  

***  

[IcmpCloseHandle](libraries/iphlpapi/IcmpCloseHandle.md)  
```txt  
Closes a handle opened by a call to IcmpCreateFile.  
```  

***  

[IcmpCreateFile](libraries/iphlpapi/IcmpCreateFile.md)  
```txt  
Opens a handle on which ICMP Echo Requests can be issued.
  
```  

***  

[IcmpSendEcho](libraries/iphlpapi/IcmpSendEcho.md)  
```txt  
Sends an ICMP Echo request and returns any replies. The call returns when the time-out has expired or the reply buffer is filled.  
```  

***  

[IpReleaseAddress](libraries/iphlpapi/IpReleaseAddress.md)  
```txt  
The IpReleaseAddress function releases an IP address previously obtained through Dynamic Host Configuration Protocol (DHCP).  
```  

***  

[IpRenewAddress](libraries/iphlpapi/IpRenewAddress.md)  
```txt  
The IpRenewAddress function renews a lease on an IP address previously obtained through Dynamic Host Configuration Protocol (DHCP).  
```  

***  

[SendARP](libraries/iphlpapi/SendARP.md)  
```txt  
Sends an ARP request to obtain the physical address that corresponds to the specified destination IP address.  
```  

***  

[if_indextoname](libraries/iphlpapi/if_indextoname.md)  
```txt  
Converts the local index for a network interface to the ANSI interface name.  
```  

***  

[if_nametoindex](libraries/iphlpapi/if_nametoindex.md)  
```txt  
Converts the ANSI interface name for a network interface to the local index for the interface.  
```  

***  


## @icon-book Icon group
***  

[CopyIcon](libraries/user32/CopyIcon.md)  
```txt  
Copies the specified icon from another module to the current module.  
```  

***  

[DestroyIcon](libraries/user32/DestroyIcon.md)  
```txt  
Destroys an icon and frees any memory the icon occupied.  
```  

***  

[DrawIcon](libraries/user32/DrawIcon.md)  
```txt  
Draws an icon or cursor into the specified device context.  
```  

***  

[ExtractAssociatedIcon](libraries/shell32/ExtractAssociatedIcon.md)  
```txt  
The ExtractAssociatedIcon function returns a handle to an indexed icon found in a file or an icon found in an associated executable file.  
```  

***  

[ExtractIcon](libraries/shell32/ExtractIcon.md)  
```txt  
Retrieves a handle to an icon from the specified executable file, dynamic-link library (DLL), or icon file.  
```  

***  

[GetIconInfo](libraries/user32/GetIconInfo.md)  
```txt  
The GetIconInfo function retrieves information about the specified icon or cursor.  
```  

***  

[LoadIcon](libraries/user32/LoadIcon.md)  
```txt  
Loads the specified icon resource from the executable (.exe) file associated with an application instance.
  
```  

***  


## @icon-book Internet Functions (WinInet) group
***  

[CreateMD5SSOHash](libraries/wininet/CreateMD5SSOHash.md)  
```txt  
Obtains the default Microsoft Passport password for a specified account or realm, creates an MD5 hash from it using a specified wide-character challenge string, and returns the result as a string of hexadecimal digit bytes.  
```  

***  

[DeleteUrlCacheEntry](libraries/wininet/DeleteUrlCacheEntry.md)  
```txt  
Removes the file associated with the source name from the cache, if the file exists.  
```  

***  

[DetectAutoProxyUrl](libraries/wininet/DetectAutoProxyUrl.md)  
```txt  
Attempts to determine the location of a WPAD autoproxy script.  
```  

***  

[FindCloseUrlCache](libraries/wininet/FindCloseUrlCache.md)  
```txt  
Closes the specified cache enumeration handle.  
```  

***  

[FindFirstUrlCacheEntry](libraries/wininet/FindFirstUrlCacheEntry.md)  
```txt  
Begins the enumeration of the Internet cache.  
```  

***  

[FindFirstUrlCacheGroup](libraries/wininet/FindFirstUrlCacheGroup.md)  
```txt  
Initiates the enumeration of the cache groups in the Internet cache.  
```  

***  

[FindNextUrlCacheEntry](libraries/wininet/FindNextUrlCacheEntry.md)  
```txt  
Retrieves the next entry in the Internet cache.  
```  

***  

[FindNextUrlCacheGroup](libraries/wininet/FindNextUrlCacheGroup.md)  
```txt  
Retrieves the next cache group in a cache group enumeration started by FindFirstUrlCacheGroup.  
```  

***  

[FtpCommand](libraries/wininet/FtpCommand.md)  
```txt  
Sends commands directly to an FTP server.  
```  

***  

[FtpCreateDirectory](libraries/wininet/FtpCreateDirectory.md)  
```txt  
Creates a new directory on the FTP server  
```  

***  

[FtpDeleteFile](libraries/wininet/FtpDeleteFile.md)  
```txt  
Deletes a file stored on the FTP server.  
```  

***  

[FtpFindFirstFile](libraries/wininet/FtpFindFirstFile.md)  
```txt  
Searches the specified directory of the given FTP session  
```  

***  

[FtpGetCurrentDirectory](libraries/wininet/FtpGetCurrentDirectory.md)  
```txt  
Retrieves the current directory for the specified FTP session  
```  

***  

[FtpGetFile](libraries/wininet/FtpGetFile.md)  
```txt  
Retrieves a file from the FTP server and stores it under the specified file name, creating a new local file in the process.  
```  

***  

[FtpGetFileSize](libraries/wininet/FtpGetFileSize.md)  
```txt  
Retrieves the file size of the requested FTP resource.  
```  

***  

[FtpOpenFile](libraries/wininet/FtpOpenFile.md)  
```txt  
Initiates access to a remote file on an FTP server for reading or writing.
  
```  

***  

[FtpPutFile](libraries/wininet/FtpPutFile.md)  
```txt  
Stores a file on the FTP server.  
```  

***  

[FtpRemoveDirectory](libraries/wininet/FtpRemoveDirectory.md)  
```txt  
Removes the specified directory on the FTP server.  
```  

***  

[FtpRenameFile](libraries/wininet/FtpRenameFile.md)  
```txt  
Renames a file stored on the FTP server.  
```  

***  

[FtpSetCurrentDirectory](libraries/wininet/FtpSetCurrentDirectory.md)  
```txt  
Changes to a different working directory on the FTP server  
```  

***  

[GetUrlCacheEntryInfo](libraries/wininet/GetUrlCacheEntryInfo.md)  
```txt  
Retrieves information about a cache entry.  
```  

***  

[HttpOpenRequest](libraries/wininet/HttpOpenRequest.md)  
```txt  
This function opens an HTTP request handle.  
```  

***  

[HttpQueryInfo](libraries/wininet/HttpQueryInfo.md)  
```txt  
Retrieves header information associated with an HTTP request.  
```  

***  

[HttpSendRequest](libraries/wininet/HttpSendRequest.md)  
```txt  
This function sends the specified request to the HTTP server.  
```  

***  

[InternetAttemptConnect](libraries/wininet/InternetAttemptConnect.md)  
```txt  
Attempts to make a connection to the Internet.  
```  

***  

[InternetAutodial](libraries/wininet/InternetAutodial.md)  
```txt  
Causes the modem to automatically dial the default Internet connection.  
```  

***  

[InternetAutodialHangup](libraries/wininet/InternetAutodialHangup.md)  
```txt  
Disconnects an automatic dial-up connection.  
```  

***  

[InternetCanonicalizeUrl](libraries/wininet/InternetCanonicalizeUrl.md)  
```txt  
Canonicalizes a URL, which includes converting unsafe characters and spaces into escape sequences.  
```  

***  

[InternetCheckConnection](libraries/wininet/InternetCheckConnection.md)  
```txt  
Allows an application to check if a connection to the Internet can be established.  
```  

***  

[InternetCloseHandle](libraries/wininet/InternetCloseHandle.md)  
```txt  
Closes a single Internet handle  
```  

***  

[InternetConnect](libraries/wininet/InternetConnect.md)  
```txt  
Opens an FTP, Gopher, or HTTP session for a given site  
```  

***  

[InternetCrackUrl](libraries/wininet/InternetCrackUrl.md)  
```txt  
Cracks a URL into its component parts.  
```  

***  

[InternetDial](libraries/wininet/InternetDial.md)  
```txt  
Initiates a connection to the Internet using a modem.  
```  

***  

[InternetFindNextFile](libraries/wininet/InternetFindNextFile.md)  
```txt  
Continues a file search started as a result of a previous call to FtpFindFirstFile or GopherFindFirstFile  
```  

***  

[InternetGetConnectedState](libraries/wininet/InternetGetConnectedState.md)  
```txt  
Retrieves the connected state of the local system.  
```  

***  

[InternetGetConnectedStateEx](libraries/wininet/InternetGetConnectedStateEx.md)  
```txt  
Retrieves the connected state of the specified Internet connection.  
```  

***  

[InternetGetCookie](libraries/wininet/InternetGetCookie.md)  
```txt  
This function retrieves the cookie for the specified URL.  
```  

***  

[InternetGetLastResponseInfo](libraries/wininet/InternetGetLastResponseInfo.md)  
```txt  
Retrieves the last Microsoft® Win32® Internet function error description or server response on the thread calling this function.  
```  

***  

[InternetGoOnline](libraries/wininet/InternetGoOnline.md)  
```txt  
Prompts the user for permission to initiate connection to a URL.  
```  

***  

[InternetOpen](libraries/wininet/InternetOpen.md)  
```txt  
Initializes an application"s use of the Microsoft® Win32® Internet functions  
```  

***  

[InternetOpenUrl](libraries/wininet/InternetOpenUrl.md)  
```txt  
Opens a resource specified by a complete FTP, Gopher, or HTTP URL.  
```  

***  

[InternetQueryDataAvailable](libraries/wininet/InternetQueryDataAvailable.md)  
```txt  
This function queries the amount of data available.  
```  

***  

[InternetQueryOption](libraries/wininet/InternetQueryOption.md)  
```txt  
Queries an Internet option on the specified handle  
```  

***  

[InternetReadFile](libraries/wininet/InternetReadFile.md)  
```txt  
Reads data from a handle opened by the InternetOpenUrl, FtpOpenFile, FtpCommand, GopherOpenFile, or HttpOpenRequest function
  
```  

***  

[InternetSetCookie](libraries/wininet/InternetSetCookie.md)  
```txt  
This function creates a cookie associated with the specified URL.  
```  

***  

[InternetSetFilePointer](libraries/wininet/InternetSetFilePointer.md)  
```txt  
Sets a file position for InternetReadFile.   
```  

***  

[InternetTimeFromSystemTime](libraries/wininet/InternetTimeFromSystemTime.md)  
```txt  
Formats a date and time according to the HTTP version 1.0 specification.  
```  

***  

[InternetTimeToSystemTime](libraries/wininet/InternetTimeToSystemTime.md)  
```txt  
Converts an HTTP time/date string to a SYSTEMTIME structure.  
```  

***  

[InternetWriteFile](libraries/wininet/InternetWriteFile.md)  
```txt  
Writes data to an open Internet file.  
```  

***  


## @icon-book Kernel Transaction Manager group
***  

[CommitTransaction](libraries/ktmw32/CommitTransaction.md)  
```txt  
Requests that the specified transaction be committed.  
```  

***  

[CreateTransaction](libraries/ktmw32/CreateTransaction.md)  
```txt  
Creates a new file system transaction object.  
```  

***  

[RollbackTransaction](libraries/ktmw32/RollbackTransaction.md)  
```txt  
Requests that the specified transaction be rolled back. This function is synchronous.  
```  

***  


## @icon-book Keyboard Input group
***  

[ActivateKeyboardLayout](libraries/user32/ActivateKeyboardLayout.md)  
```txt  
The ActivateKeyboardLayout function sets the input locale identifier (formerly called the keyboard layout handle) for the calling thread or the current process. The input locale identifier specifies a locale as well as the physical layout of the keyboard.  
```  

***  

[BlockInput](libraries/user32/BlockInput.md)  
```txt  
Blocks keyboard and mouse input events from reaching applications.  
```  

***  

[EnableWindow](libraries/user32/EnableWindow.md)  
```txt  
Enables or disables mouse and keyboard input to the specified window or control.  
```  

***  

[GetActiveWindow](libraries/user32/GetActiveWindow.md)  
```txt  
The GetActiveWindow function retrieves the window handle to the active window attached to the calling thread"s message queue.   
```  

***  

[GetAsyncKeyState](libraries/user32/GetAsyncKeyState.md)  
```txt  
The GetAsyncKeyState function determines whether a key is up or down at the time the function is called, and whether the key was pressed after a previous call to GetAsyncKeyState.   
```  

***  

[GetFocus](libraries/user32/GetFocus.md)  
```txt  
Retrieves the handle to the window that has the keyboard focus, if the window is attached to the calling thread"s message queue.  
```  

***  

[GetKBCodePage](libraries/user32/GetKBCodePage.md)  
```txt  
Returns the current code page.  
```  

***  

[GetKeyNameText](libraries/user32/GetKeyNameText.md)  
```txt  
The GetKeyNameText function retrieves a string that represents the name of a key.  
```  

***  

[GetKeyState](libraries/user32/GetKeyState.md)  
```txt  
The GetKeyState function retrieves the status of the specified virtual key. The status specifies whether the key is up, down, or toggled (on, off—alternating each time the key is pressed).   
```  

***  

[GetKeyboardLayout](libraries/user32/GetKeyboardLayout.md)  
```txt  
The GetKeyboardLayout function retrieves the active input locale identifier (formerly called the keyboard layout) for the specified thread. If the idThread parameter is zero, the input locale identifier for the active thread is returned.  
```  

***  

[GetKeyboardLayoutList](libraries/user32/GetKeyboardLayoutList.md)  
```txt  
The GetKeyboardLayoutList function retrieves the input locale identifiers (formerly called keyboard layout handles) corresponding to the current set of input locales in the system.   
```  

***  

[GetKeyboardLayoutName](libraries/user32/GetKeyboardLayoutName.md)  
```txt  
The GetKeyboardLayoutName function retrieves the name of the active input locale identifier (formerly called the keyboard layout).   
```  

***  

[GetKeyboardState](libraries/user32/GetKeyboardState.md)  
```txt  
The GetKeyboardState function copies the status of the 256 virtual keys to the specified buffer.  
```  

***  

[IsWindowEnabled](libraries/user32/IsWindowEnabled.md)  
```txt  
The IsWindowEnabled function determines whether the specified window is enabled for mouse and keyboard input.   
```  

***  

[MapVirtualKey](libraries/user32/MapVirtualKey.md)  
```txt  
Translates (maps) a virtual-key code into a scan code or character value, or translates a scan code into a virtual-key code.  
```  

***  

[RegisterHotKey](libraries/user32/RegisterHotKey.md)  
```txt  
The RegisterHotKey function defines a system-wide hot key.   
```  

***  

[SetFocus](libraries/user32/SetFocus.md)  
```txt  
Sets the keyboard focus to the specified window. The window must be attached to the calling thread"s message queue  
```  

***  

[SetKeyboardState](libraries/user32/SetKeyboardState.md)  
```txt  
The SetKeyboardState function copies a 256-byte array of keyboard key states into the calling thread"s keyboard input-state table.   
```  

***  

[ToAscii](libraries/user32/ToAscii.md)  
```txt  
Translates the specified virtual-key code and keyboard state to the corresponding character or characters.  
```  

***  

[UnregisterHotKey](libraries/user32/UnregisterHotKey.md)  
```txt  
The UnregisterHotKey function frees a hot key previously registered by the calling thread.   
```  

***  

[VkKeyScan](libraries/user32/VkKeyScan.md)  
```txt  
Translates a character to the corresponding virtual-key code and shift state for the current keyboard.  
```  

***  

[keybd_event](libraries/user32/keybd_event.md)  
```txt  
Synthesizes a keystroke.
  
```  

***  


## @icon-book MSHTML Reference group
***  

[ShowHTMLDialog](libraries/mshtml/ShowHTMLDialog.md)  
```txt  
Creates a modal dialog box that displays HTML.  
```  

***  


## @icon-book Mailslot group
***  

[CreateMailslot](libraries/kernel32/CreateMailslot.md)  
```txt  
The CreateMailslot function creates a mailslot with the specified name and returns a handle that a mailslot server can use to perform operations on it.   
```  

***  

[GetMailslotInfo](libraries/kernel32/GetMailslotInfo.md)  
```txt  
The GetMailslotInfo function retrieves information about the specified mailslot.   
```  

***  

[SetMailslotInfo](libraries/kernel32/SetMailslotInfo.md)  
```txt  
The SetMailslotInfo function sets the time-out value used by the specified mailslot for a read operation.   
```  

***  


## @icon-book Memory Management group
***  

[CopyMemory](libraries/kernel32/CopyMemory.md)  

***  

[FillMemory](libraries/kernel32/FillMemory.md)  
```txt  
The FillMemory function fills a block of memory with a specified value.  
```  

***  

[GetProcessHeap](libraries/kernel32/GetProcessHeap.md)  
```txt  
The GetProcessHeap function obtains a handle to the heap of the calling process. This handle can then be used in subsequent calls to the HeapAlloc, HeapReAlloc, HeapFree, and HeapSize functions.  
```  

***  

[GetProcessHeaps](libraries/kernel32/GetProcessHeaps.md)  
```txt  
The GetProcessHeaps function obtains handles to all of the heaps that are valid for the calling process.  
```  

***  

[GlobalAlloc](libraries/kernel32/GlobalAlloc.md)  
```txt  
The GlobalAlloc function allocates the specified number of bytes from the heap  
```  

***  

[GlobalFree](libraries/kernel32/GlobalFree.md)  
```txt  
The GlobalFree function frees the specified global memory object and invalidates its handle  
```  

***  

[GlobalLock](libraries/kernel32/GlobalLock.md)  
```txt  
The GlobalLock function locks a global memory object and returns a pointer to the first byte of the object"s memory block.  
```  

***  

[GlobalMemoryStatus](libraries/kernel32/GlobalMemoryStatus.md)  
```txt  
The GlobalMemoryStatus function obtains information about the system"s current usage of both physical and virtual memory.
  
```  

***  

[GlobalReAlloc](libraries/kernel32/GlobalReAlloc.md)  
```txt  
Changes the size or attributes of a specified global memory object. The size can increase or decrease.  
```  

***  

[GlobalSize](libraries/kernel32/GlobalSize.md)  
```txt  
The GlobalSize function retrieves the current size, in bytes, of the specified global memory object  
```  

***  

[GlobalUnlock](libraries/kernel32/GlobalUnlock.md)  
```txt  
Decrements the lock count associated with a memory object that was allocated with GMEM_MOVEABLE. This function has no effect on memory objects allocated with GMEM_FIXED.  
```  

***  

[HeapAlloc](libraries/kernel32/HeapAlloc.md)  
```txt  
The HeapAlloc function allocates a block of memory from a heap. The allocated memory is <Strong>not movable</Strong>.  
```  

***  

[HeapCompact](libraries/kernel32/HeapCompact.md)  
```txt  
Attempts to compact a specified heap. It compacts the heap by coalescing adjacent free blocks of memory and decommitting large free blocks of memory.  
```  

***  

[HeapFree](libraries/kernel32/HeapFree.md)  
```txt  
The HeapFree function frees a memory block allocated from a heap by the HeapAlloc or HeapReAlloc function.  
```  

***  

[HeapLock](libraries/kernel32/HeapLock.md)  
```txt  
Attempts to acquire the critical section object, or lock, that is associated with a specified heap.   
```  

***  

[HeapReAlloc](libraries/kernel32/HeapReAlloc.md)  
```txt  
The HeapReAlloc function reallocates a block of memory from a heap. This function enables you to resize a memory block and change other memory block properties. The allocated memory is not movable.  
```  

***  

[HeapSize](libraries/kernel32/HeapSize.md)  
```txt  
The HeapSize function retrieves the size of a memory block allocated from a heap by the HeapAlloc or HeapReAlloc function.  
```  

***  

[HeapUnlock](libraries/kernel32/HeapUnlock.md)  
```txt  
Releases ownership of the critical section object, or lock, that is associated with a specified heap. The HeapUnlock function reverses the action of the HeapLock function.  
```  

***  

[HeapValidate](libraries/kernel32/HeapValidate.md)  
```txt  
Attempts to validate a specified heap. The function scans all the memory blocks in the heap, and verifies that the heap control structures maintained by the heap manager are in a consistent state.

You can also use the HeapValidate function to validate a single memory block within a specified heap, without checking the validity of the entire heap.  
```  

***  

[HeapWalk](libraries/kernel32/HeapWalk.md)  
```txt  
Enumerates the memory blocks in a specified heap created or manipulated by heap memory allocators such as HeapAlloc, HeapReAlloc, and HeapFree.  
```  

***  

[LocalAlloc](libraries/kernel32/LocalAlloc.md)  
```txt  
The LocalAlloc function allocates the specified number of bytes from the heap.  
```  

***  

[LocalFree](libraries/kernel32/LocalFree.md)  
```txt  
The LocalFree function frees the specified local memory object and invalidates its handle.  
```  

***  

[LocalSize](libraries/kernel32/LocalSize.md)  
```txt  
The LocalSize function returns the current size of the specified local memory object, in bytes.  
```  

***  

[VirtualAllocEx](libraries/kernel32/VirtualAllocEx.md)  
```txt  
Reserves or commits a region of memory within the virtual address space of a specified process.  
```  

***  

[VirtualFreeEx](libraries/kernel32/VirtualFreeEx.md)  
```txt  
Releases, decommits, or releases and decommits a region of memory within the virtual address space of a specified process.  
```  

***  

[ZeroMemory](libraries/kernel32/ZeroMemory.md)  
```txt  
Fills a block of memory with zeros.  
```  

***  


## @icon-book Menu group
***  

[AppendMenu](libraries/user32/AppendMenu.md)  
```txt  
The AppendMenu function appends a new item to the end of the specified menu bar, drop-down menu, submenu, or shortcut menu.  
```  

***  

[CreateMenu](libraries/user32/CreateMenu.md)  
```txt  
The CreateMenu function creates a menu. The menu is initially empty, but it can be filled with menu items by using the InsertMenuItem, AppendMenu, and InsertMenu functions.  
```  

***  

[CreatePopupMenu](libraries/user32/CreatePopupMenu.md)  
```txt  
The CreatePopupMenu function creates a drop-down menu, submenu, or shortcut menu.

The menu is initially empty. You can insert or append menu items by using the InsertMenuItem function. You can also use the InsertMenu function to insert menu items and the AppendMenu function to append menu items.  
```  

***  

[DeleteMenu](libraries/user32/DeleteMenu.md)  
```txt  
Deletes an item from the specified menu. If the menu item opens a menu or submenu, this function destroys the handle to the menu or submenu and frees the memory used by the menu or submenu.  
```  

***  

[DestroyMenu](libraries/user32/DestroyMenu.md)  
```txt  
The DestroyMenu function destroys the specified menu and frees any memory that the menu occupies.  
```  

***  

[DrawMenuBar](libraries/user32/DrawMenuBar.md)  
```txt  
Redraws the menu bar of the specified window. If the menu bar changes after the system has created the window, this function must be called to draw the changed menu bar.  
```  

***  

[GetMenu](libraries/user32/GetMenu.md)  
```txt  
The GetMenu function retrieves a handle to the menu assigned to the specified window.   
```  

***  

[GetMenuBarInfo](libraries/user32/GetMenuBarInfo.md)  
```txt  
Retrieves information about the specified menu bar.  
```  

***  

[GetMenuItemCount](libraries/user32/GetMenuItemCount.md)  
```txt  
The GetMenuItemCount function determines the number of items in the specified menu.   
```  

***  

[GetMenuItemID](libraries/user32/GetMenuItemID.md)  
```txt  
The GetMenuItemID function retrieves the menu item identifier of a menu item located at the specified position in a menu.  
```  

***  

[GetMenuItemInfo](libraries/user32/GetMenuItemInfo.md)  
```txt  
The GetMenuItemInfo function retrieves information about a menu item.  
```  

***  

[GetMenuString](libraries/user32/GetMenuString.md)  
```txt  
The GetMenuString function copies the text string of the specified menu item into the specified buffer.
  
```  

***  

[GetSubMenu](libraries/user32/GetSubMenu.md)  
```txt  
Retrieves a handle to the drop-down menu or submenu activated by the specified menu item.  
```  

***  

[GetSystemMenu](libraries/user32/GetSystemMenu.md)  
```txt  
The GetSystemMenu function allows the application to access the window menu (also known as the system menu or the control menu) for copying and modifying.   
```  

***  

[InsertMenuItem](libraries/user32/InsertMenuItem.md)  
```txt  
The InsertMenuItem function inserts a new menu item at the specified position in a menu.  
```  

***  

[IsMenu](libraries/user32/IsMenu.md)  
```txt  
The IsMenu function determines whether a handle is a menu handle.   
```  

***  

[SetMenu](libraries/user32/SetMenu.md)  
```txt  
The SetMenu function assigns a new menu to the specified window.  
```  

***  

[TrackPopupMenuEx](libraries/user32/TrackPopupMenuEx.md)  
```txt  
The TrackPopupMenuEx function displays a shortcut menu at the specified location and tracks the selection of items on the shortcut menu. The shortcut menu can appear anywhere on the screen.  
```  

***  


## @icon-book Message and Message Queue group
***  

[BroadcastSystemMessage](libraries/user32/BroadcastSystemMessage.md)  
```txt  
Sends a message to the specified recipients. The recipients can be applications, installable drivers, network drivers, system-level device drivers, or any combination of these system components.  
```  

***  

[GetQueueStatus](libraries/user32/GetQueueStatus.md)  
```txt  
The GetQueueStatus function indicates the type of messages found in the calling thread"s message queue.  
```  

***  

[MQCloseQueue](libraries/mqrt/MQCloseQueue.md)  
```txt  
Closes a given queue or subqueue.  
```  

***  

[MQDeleteQueue](libraries/mqrt/MQDeleteQueue.md)  
```txt  
Deletes a queue from the directory service (in the case of public queues) or from the local computer (in the case of private queues).  
```  

***  

[MQHandleToFormatName](libraries/mqrt/MQHandleToFormatName.md)  
```txt  
Returns a format name for the queue or subqueue based on its handle.  
```  

***  

[MQOpenQueue](libraries/mqrt/MQOpenQueue.md)  
```txt  
Opens a queue for sending, peeking at, retrieving, or purging messages.   
```  

***  

[MQPathNameToFormatName](libraries/mqrt/MQPathNameToFormatName.md)  
```txt  
Returns a format name based on the path name provided.  
```  

***  

[MQPurgeQueue](libraries/mqrt/MQPurgeQueue.md)  
```txt  
Deletes all of the messages in a queue.  
```  

***  

[PeekMessage](libraries/user32/PeekMessage.md)  
```txt  
The PeekMessage function dispatches incoming sent messages, checks the thread message queue for a posted message, and retrieves the message (if any exist).  
```  

***  

[PostMessage](libraries/user32/PostMessage.md)  
```txt  
Places (posts) a message in the message queue associated with the thread that created the specified window and returns without waiting for the thread to process the message.
  
```  

***  

[PostQuitMessage](libraries/user32/PostQuitMessage.md)  
```txt  
Indicates to the system that a thread has made a request to terminate (quit). It is typically used in response to a WM_DESTROY message.  
```  

***  

[SendMessage](libraries/user32/SendMessage.md)  
```txt  
Sends the specified message to a window or windows. It calls the window procedure for the specified window and does not return until the window procedure has processed the message.   
```  

***  


## @icon-book Metafile group
***  

[CloseEnhMetaFile](libraries/gdi32/CloseEnhMetaFile.md)  
```txt  
The CloseEnhMetaFile function closes an enhanced-metafile device context and returns a handle that identifies an enhanced-format metafile.  
```  

***  

[CreateEnhMetaFile](libraries/gdi32/CreateEnhMetaFile.md)  
```txt  
The CreateEnhMetaFile function creates a device context for an enhanced-format metafile. This device context can be used to store a device-independent picture.  
```  

***  

[DeleteEnhMetaFile](libraries/gdi32/DeleteEnhMetaFile.md)  
```txt  
The DeleteEnhMetaFile function deletes an enhanced-format metafile or an enhanced-format metafile handle.   
```  

***  

[GetEnhMetaFile](libraries/gdi32/GetEnhMetaFile.md)  
```txt  
The GetEnhMetaFile function creates a handle that identifies the enhanced-format metafile stored in the specified file.  
```  

***  

[GetEnhMetaFileHeader](libraries/gdi32/GetEnhMetaFileHeader.md)  
```txt  
The GetEnhMetaFileHeader function retrieves the record containing the header for the specified enhanced-format metafile.  
```  

***  

[PlayEnhMetaFile](libraries/gdi32/PlayEnhMetaFile.md)  
```txt  
The PlayEnhMetaFile function displays the picture stored in the specified enhanced-format metafile.  
```  

***  


## @icon-book Monitor Configuration (Vista) group
***  

[DestroyPhysicalMonitors](libraries/dxva2/DestroyPhysicalMonitors.md)  
```txt  
Closes an array of open monitor handles. That is one of a scary name for API function.  
```  

***  

[GetMonitorBrightness](libraries/dxva2/GetMonitorBrightness.md)  
```txt  
Retrieves the minimum, maximum, and current brightness settings for a monitor.  
```  

***  

[GetMonitorCapabilities](libraries/dxva2/GetMonitorCapabilities.md)  
```txt  
Retrieves the configuration capabilities of a monitor. Call this function to find out which high-level monitor configuration functions are supported by the monitor.  
```  

***  

[GetMonitorContrast](libraries/dxva2/GetMonitorContrast.md)  
```txt  
Retrieves the minimum, maximum, and current contrast settings for a monitor.  
```  

***  

[GetNumberOfPhysicalMonitorsFromHMONITOR](libraries/dxva2/GetNumberOfPhysicalMonitorsFromHMONITOR.md)  
```txt  
Retrieves the number of physical monitors associated with an HMONITOR monitor handle.  
```  

***  

[GetPhysicalMonitorsFromHMONITOR](libraries/dxva2/GetPhysicalMonitorsFromHMONITOR.md)  
```txt  
Retrieves the physical monitors associated with an HMONITOR monitor handle.  
```  

***  

[SetMonitorBrightness](libraries/dxva2/SetMonitorBrightness.md)  
```txt  
Sets a monitor"s brightness value.  
```  

***  

[SetMonitorContrast](libraries/dxva2/SetMonitorContrast.md)  
```txt  
Sets the contrast value for a monitor.   
```  

***  


## @icon-book Mouse Input group
***  

[DragDetect](libraries/user32/DragDetect.md)  
```txt  
The DragDetect function captures the mouse and tracks its movement until the user releases the left button, presses the ESC key, or moves the mouse outside the drag rectangle around the specified point.  
```  

***  

[GetCapture](libraries/user32/GetCapture.md)  
```txt  
The GetCapture function retrieves a handle to the window (if any) that has captured the mouse. Only one window at a time can capture the mouse; this window receives mouse input whether or not the cursor is within its borders.   
```  

***  

[GetDoubleClickTime](libraries/user32/GetDoubleClickTime.md)  
```txt  
Retrieves the current double-click time for the mouse  
```  

***  

[GetMouseMovePointsEx](libraries/user32/GetMouseMovePointsEx.md)  
```txt  
Retrieves a history of up to 64 previous coordinates of the mouse or pen.  
```  

***  

[ReleaseCapture](libraries/user32/ReleaseCapture.md)  
```txt  
Releases the mouse capture from a window in the current thread and restores normal mouse input processing. A window that has captured the mouse receives all mouse input, regardless of the position of the cursor, except when a mouse button is clicked while the cursor hot spot is in the window of another thread.  
```  

***  

[SetCapture](libraries/user32/SetCapture.md)  
```txt  
The SetCapture function sets the mouse capture to the specified window belonging to the current thread.  
```  

***  

[SetDoubleClickTime](libraries/user32/SetDoubleClickTime.md)  
```txt  
Sets the double-click time for the mouse  
```  

***  

[SwapMouseButton](libraries/user32/SwapMouseButton.md)  
```txt  
The SwapMouseButton function reverses or restores the meaning of the left and right mouse buttons  
```  

***  


## @icon-book Multilingual User Interface group
***  

[GetProcessPreferredUILanguages](libraries/kernel32/GetProcessPreferredUILanguages.md)  
```txt  
Retrieves the process preferred UI languages.  
```  

***  

[GetThreadUILanguage](libraries/kernel32/GetThreadUILanguage.md)  
```txt  
Returns the language identifier of the first user interface language for the current thread.  
```  

***  

[GetUserDefaultUILanguage](libraries/kernel32/GetUserDefaultUILanguage.md)  
```txt  
Returns the language identifier for the user UI language for the current user.  
```  

***  

[SetProcessPreferredUILanguages](libraries/kernel32/SetProcessPreferredUILanguages.md)  
```txt  
Sets the process preferred UI languages for the application process.  
```  

***  


## @icon-book Multiple Display Monitors group
***  

[GetMonitorInfo](libraries/user32/GetMonitorInfo.md)  
```txt  
The GetMonitorInfo function retrieves information about a display monitor.  
```  

***  

[MonitorFromWindow](libraries/user32/MonitorFromWindow.md)  
```txt  
Retrieves a handle to the display monitor that has the largest area of intersection with the bounding rectangle of a specified window.
  
```  

***  


## @icon-book National Language Support group
***  

[CompareString](libraries/kernel32/CompareString.md)  
```txt  
Compares two character strings, for a locale specified by identifier.  
```  

***  

[GetACP](libraries/kernel32/GetACP.md)  
```txt  
Retrieves the current ANSI code-page identifier for the system.  
```  

***  

[GetCurrencyFormat](libraries/kernel32/GetCurrencyFormat.md)  
```txt  
Formats a number string as a currency string for a locale specified by identifier.  
```  

***  

[GetDateFormat](libraries/kernel32/GetDateFormat.md)  
```txt  
Formats a date as a date string for a locale specified by the locale identifier. The function formats either a specified date or the local system date.  
```  

***  

[GetLocaleInfo](libraries/kernel32/GetLocaleInfo.md)  
```txt  
Retrieves information about a locale.  
```  

***  

[GetNumberFormat](libraries/kernel32/GetNumberFormat.md)  
```txt  
Formats a number string as a number string customized for a locale specified by identifier.  
```  

***  

[GetOEMCP](libraries/kernel32/GetOEMCP.md)  
```txt  
Retrieves the current original equipment manufacturer (OEM) code-page identifier for the system.  
```  

***  

[GetStringTypeEx](libraries/kernel32/GetStringTypeEx.md)  
```txt  
Retrieves character type information for the characters in the specified source string. For each character in the string, the function sets one or more bits in the corresponding 16-bit element of the output array. Each bit identifies a given character type, for example, letter, digit, or neither.  
```  

***  

[GetSystemDefaultLCID](libraries/kernel32/GetSystemDefaultLCID.md)  
```txt  
Retrieves the system default locale identifier.  
```  

***  

[GetSystemDefaultLangID](libraries/kernel32/GetSystemDefaultLangID.md)  
```txt  
Retrieves the language identifier of the system locale.  
```  

***  

[GetSystemDefaultLocaleName](libraries/kernel32/GetSystemDefaultLocaleName.md)  
```txt  
Retrieves the system default locale name.  
```  

***  

[GetThreadLocale](libraries/kernel32/GetThreadLocale.md)  
```txt  
Retrieves the calling thread"s current locale.  
```  

***  

[GetUserDefaultLCID](libraries/kernel32/GetUserDefaultLCID.md)  
```txt  
Retrieves the user default–locale identifier.  
```  

***  

[GetUserDefaultLangID](libraries/kernel32/GetUserDefaultLangID.md)  
```txt  
Retrieves the language identifier of the current user locale.  
```  

***  

[GetUserDefaultLocaleName](libraries/kernel32/GetUserDefaultLocaleName.md)  
```txt  
Retrieves the user default locale name.  
```  

***  

[GetUserGeoID](libraries/kernel32/GetUserGeoID.md)  
```txt  
Retrieves information about the geographical location of the user.  
```  

***  

[LCIDToLocaleName](libraries/kernel32/LCIDToLocaleName.md)  
```txt  
Converts a locale identifier to a locale name.  
```  

***  

[LocaleNameToLCID](libraries/kernel32/LocaleNameToLCID.md)  
```txt  
Converts a locale name to a locale identifier.  
```  

***  

[NormalizeString](libraries/kernel32/NormalizeString.md)  
```txt  
Normalizes characters of a text string according to Unicode 4.0 TR#15.  
```  

***  

[SetUserGeoID](libraries/kernel32/SetUserGeoID.md)  
```txt  
Sets the geographical location identifier for the user. This identifier should have one of the values described in Table of Geographical Locations.  
```  

***  


## @icon-book Network Management group
***  

[NetApiBufferFree](libraries/netapi32/NetApiBufferFree.md)  
```txt  
Frees the memory that the NetApiBufferAllocate function allocates. Call NetApiBufferFree to free the memory that other network management functions return on Windows NT, Windows 2000, and Windows XP.  
```  

***  

[NetApiBufferSize](libraries/netapi32/NetApiBufferSize.md)  
```txt  
The NetApiBufferSize function returns the size, in bytes, of a buffer allocated by a call to the NetApiBufferAllocate function.  
```  

***  

[NetConnectionEnum](libraries/netapi32/NetConnectionEnum.md)  
```txt  
Lists all connections made to a shared resource on the server or all connections established from a particular computer.  
```  

***  

[NetFileClose](libraries/netapi32/NetFileClose.md)  
```txt  
The NetFileClose function forces a resource to close.  
```  

***  

[NetFileEnum](libraries/netapi32/NetFileEnum.md)  
```txt  
The NetFileEnum function returns information about some or all open files on a server, depending on the parameters specified.  
```  

***  

[NetFileGetInfo](libraries/netapi32/NetFileGetInfo.md)  
```txt  
The NetFileGetInfo function retrieves information about a particular opening of a server resource.  
```  

***  

[NetGetDCName](libraries/netapi32/NetGetDCName.md)  
```txt  
Returns the name of the primary domain controller (PDC). It does not return the name of the backup domain controller (BDC) for the specified domain.  
```  

***  

[NetGroupEnum](libraries/netapi32/NetGroupEnum.md)  
```txt  
The NetGroupEnum function retrieves information about each global group in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.  
```  

***  

[NetLocalGroupEnum](libraries/netapi32/NetLocalGroupEnum.md)  
```txt  
The NetLocalGroupEnum function returns information about each local group account on the specified server.  
```  

***  

[NetMessageBufferSend](libraries/netapi32/NetMessageBufferSend.md)  
```txt  
Sends a buffer of information to a registered message alias.
  
```  

***  

[NetMessageNameAdd](libraries/netapi32/NetMessageNameAdd.md)  
```txt  
Registers a message alias in the message name table. The function requires that the messenger service be started.
  
```  

***  

[NetMessageNameDel](libraries/netapi32/NetMessageNameDel.md)  
```txt  
Deletes a message alias in the message name table. The function requires that the messenger service be started.  
```  

***  

[NetMessageNameEnum](libraries/netapi32/NetMessageNameEnum.md)  
```txt  
Lists the message aliases that receive messages on a specified computer. The function requires that the messenger service be started.
  
```  

***  

[NetScheduleJobAdd](libraries/netapi32/NetScheduleJobAdd.md)  
```txt  
Submits a job to run at a specified future time and date.
  
```  

***  

[NetScheduleJobDel](libraries/netapi32/NetScheduleJobDel.md)  
```txt  
The NetScheduleJobDel function deletes a range of jobs queued to run at a computer.  
```  

***  

[NetScheduleJobEnum](libraries/netapi32/NetScheduleJobEnum.md)  
```txt  
Lists the jobs queued on a specified computer.   
```  

***  

[NetServerEnum](libraries/netapi32/NetServerEnum.md)  
```txt  
Lists all servers of the specified type that are visible in a domain.  
```  

***  

[NetServerGetInfo](libraries/netapi32/NetServerGetInfo.md)  
```txt  
The NetServerGetInfo function retrieves current configuration information for the specified server.  
```  

***  

[NetSessionEnum](libraries/netapi32/NetSessionEnum.md)  
```txt  
Provides information about sessions established on a server.  
```  

***  

[NetShareAdd](libraries/netapi32/NetShareAdd.md)  
```txt  
Shares a server resource.  
```  

***  

[NetShareDel](libraries/netapi32/NetShareDel.md)  
```txt  
Deletes a share name from a server"s list of shared resources, disconnecting all connections to the shared resource.  
```  

***  

[NetShareEnum](libraries/netapi32/NetShareEnum.md)  
```txt  
The NetShareEnum function retrieves information about each shared resource on a server or the local computer.  
```  

***  

[NetShareSetInfo](libraries/netapi32/NetShareSetInfo.md)  
```txt  
Sets the parameters of a shared resource.  
```  

***  

[NetUserAdd](libraries/netapi32/NetUserAdd.md)  
```txt  
Adds a user account and assigns a password and privilege level.
  
```  

***  

[NetUserChangePassword](libraries/netapi32/NetUserChangePassword.md)  
```txt  
Changes user`s password for a specified network server or domain.
  
```  

***  

[NetUserDel](libraries/netapi32/NetUserDel.md)  
```txt  
Deletes a user account from a server.  
```  

***  

[NetUserEnum](libraries/netapi32/NetUserEnum.md)  
```txt  
The NetUserEnum function provides information about all user accounts on a server.   
```  

***  

[NetUserGetGroups](libraries/netapi32/NetUserGetGroups.md)  
```txt  
The NetUserGetGroups function retrieves a list of global groups to which a specified user belongs.  
```  

***  

[NetUserGetInfo](libraries/netapi32/NetUserGetInfo.md)  
```txt  
Retrieves information about a particular user account on a server.  
```  

***  

[NetUserGetLocalGroups](libraries/netapi32/NetUserGetLocalGroups.md)  
```txt  
The NetUserGetLocalGroups function retrieves a list of local groups to which a specified user belongs.
  
```  

***  

[NetUserSetInfo](libraries/netapi32/NetUserSetInfo.md)  
```txt  
Sets the parameters of a user account.
  
```  

***  

[NetWkstaGetInfo](libraries/netapi32/NetWkstaGetInfo.md)  
```txt  
The NetWkstaGetInfo function returns information about the configuration of a workstation.  
```  

***  

[NetWkstaTransportEnum](libraries/netapi32/NetWkstaTransportEnum.md)  
```txt  
The NetWkstaTransportEnum function supplies information about transport protocols that are managed by the redirector, which is the software on the client computer that generates file requests to the server computer.  
```  

***  

[NetWkstaUserEnum](libraries/netapi32/NetWkstaUserEnum.md)  
```txt  
The NetWkstaUserEnum function lists information about all users currently logged on to the workstation. This list includes interactive, service and batch logons.  
```  

***  


## @icon-book ODBC API group
***  

[SQLAllocEnv](libraries/odbc32/SQLAllocEnv.md)  
```txt  
In ODBC 3.x, the ODBC 2.x function SQLAllocEnv has been replaced by SQLAllocHandle.  
```  

***  

[SQLAllocHandle](libraries/odbc32/SQLAllocHandle.md)  
```txt  
SQLAllocHandle allocates an environment, connection, statement, or descriptor handle.  
```  

***  

[SQLBindCol](libraries/odbc32/SQLBindCol.md)  
```txt  
SQLBindCol binds application data buffers to columns in the result set.  
```  

***  

[SQLBrowseConnect](libraries/odbc32/SQLBrowseConnect.md)  
```txt  
SQLBrowseConnect supports an iterative method of discovering and enumerating the attributes and attribute values required to connect to a data source. Each call to SQLBrowseConnect returns successive levels of attributes and attribute values.  
```  

***  

[SQLConfigDataSource](libraries/odbc32/SQLConfigDataSource.md)  
```txt  
SQLConfigDataSource adds, modifies, or deletes data sources.  
```  

***  

[SQLConnect](libraries/odbc32/SQLConnect.md)  
```txt  
SQLConnect establishes connections to a driver and a data source.   
```  

***  

[SQLCreateDataSource](libraries/odbc32/SQLCreateDataSource.md)  
```txt  
SQLCreateDataSource displays a dialog box with which the user can add a data source.  
```  

***  

[SQLDataSources](libraries/odbc32/SQLDataSources.md)  
```txt  
SQLDataSources returns information about a data source. This function is implemented solely by the Driver Manager.  
```  

***  

[SQLDisconnect](libraries/odbc32/SQLDisconnect.md)  
```txt  
SQLDisconnect closes the connection associated with a specific connection handle.  
```  

***  

[SQLDriverConnect](libraries/odbc32/SQLDriverConnect.md)  
```txt  
SQLDriverConnect is an alternative to SQLConnect. It supports data sources that require more connection information than the three arguments in SQLConnect, dialog boxes to prompt the user for all connection information, and data sources that are not defined in the system information.  
```  

***  

[SQLDrivers](libraries/odbc32/SQLDrivers.md)  
```txt  
SQLDrivers lists driver descriptions and driver attribute keywords.  
```  

***  

[SQLExecDirect](libraries/odbc32/SQLExecDirect.md)  
```txt  
SQLExecDirect executes a preparable statement, using the current values of the parameter marker variables if any parameters exist in the statement.  
```  

***  

[SQLFetch](libraries/odbc32/SQLFetch.md)  
```txt  
SQLFetch fetches the next rowset of data from the result set and returns data for all bound columns.  
```  

***  

[SQLFreeEnv](libraries/odbc32/SQLFreeEnv.md)  
```txt  
In ODBC 3.x, the ODBC 2.0 function SQLFreeEnv has been replaced by SQLFreeHandle.  
```  

***  

[SQLFreeHandle](libraries/odbc32/SQLFreeHandle.md)  
```txt  
SQLFreeHandle frees resources associated with a specific environment, connection, statement, or descriptor handle.  
```  

***  

[SQLGetConfigMode](libraries/odbc32/SQLGetConfigMode.md)  
```txt  
Retrieves the configuration mode that indicates where the Odbc.ini entry listing DSN values is in the system information.
  
```  

***  

[SQLGetConnectAttr](libraries/odbc32/SQLGetConnectAttr.md)  
```txt  
SQLGetConnectAttr returns the current setting of a connection attribute.  
```  

***  

[SQLGetDiagRec](libraries/odbc32/SQLGetDiagRec.md)  
```txt  
SQLGetDiagRec returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information.   
```  

***  

[SQLGetEnvAttr](libraries/odbc32/SQLGetEnvAttr.md)  
```txt  
SQLGetEnvAttr returns the current setting of an environment attribute.  
```  

***  

[SQLGetFunctions](libraries/odbc32/SQLGetFunctions.md)  
```txt  
SQLGetFunctions returns information about whether a driver supports a specific ODBC function.   
```  

***  

[SQLGetInfo](libraries/odbc32/SQLGetInfo.md)  
```txt  
SQLGetInfo returns general information about the driver and data source associated with a connection.  
```  

***  

[SQLGetInstalledDrivers](libraries/odbc32/SQLGetInstalledDrivers.md)  
```txt  
SQLGetInstalledDrivers reads the [ODBC Drivers] section of the system information and returns a list of descriptions of the installed drivers.  
```  

***  

[SQLGetPrivateProfileString](libraries/odbc32/SQLGetPrivateProfileString.md)  
```txt  
SQLGetPrivateProfileString gets a list of names of values or data corresponding to a value of the system information.  
```  

***  

[SQLInstallerError](libraries/odbccp32/SQLInstallerError.md)  
```txt  
SQLInstallerError returns error or status information for the ODBC installer functions.  
```  

***  

[SQLManageDataSources](libraries/odbc32/SQLManageDataSources.md)  
```txt  
SQLManageDataSources displays a dialog box with which users can set up, add, and delete data sources in the system information.  
```  

***  

[SQLNativeSql](libraries/odbc32/SQLNativeSql.md)  
```txt  
SQLNativeSql returns the SQL string as modified by the driver. SQLNativeSql does not execute the SQL statement.  
```  

***  

[SQLRowCount](libraries/odbc32/SQLRowCount.md)  
```txt  
SQLRowCount returns the number of rows affected by an UPDATE, INSERT, or DELETE statement.  
```  

***  

[SQLSetConfigMode](libraries/odbc32/SQLSetConfigMode.md)  
```txt  
Sets the configuration mode that indicates where the Odbc.ini entry listing DSN values is in the system information.
  
```  

***  

[SQLSetEnvAttr](libraries/odbc32/SQLSetEnvAttr.md)  
```txt  
SQLSetEnvAttr sets attributes that govern aspects of environments.  
```  

***  

[SQLTables](libraries/odbc32/SQLTables.md)  
```txt  
Returns the list of table, catalog, or schema names, and table types, stored in a specific data source. The driver returns the information as a result set.  
```  

***  


## @icon-book Painting and Drawing group
***  

[DrawAnimatedRects](libraries/user32/DrawAnimatedRects.md)  
```txt  
The DrawAnimatedRects function draws a wire-frame rectangle and animates it to indicate the opening of an icon or the minimizing or maximizing of a window.  
```  

***  

[DrawCaption](libraries/user32/DrawCaption.md)  
```txt  
The DrawCaption function draws a window caption.  
```  

***  

[DrawEdge](libraries/user32/DrawEdge.md)  
```txt  
The DrawEdge function draws one or more edges of rectangle.  
```  

***  

[DrawFrameControl](libraries/user32/DrawFrameControl.md)  
```txt  
The DrawFrameControl function draws a frame control of the specified type and style.  
```  

***  

[GdiFlush](libraries/gdi32/GdiFlush.md)  
```txt  
Flushes the calling thread`s current batch.  
```  

***  

[GdiGetBatchLimit](libraries/gdi32/GdiGetBatchLimit.md)  
```txt  
Returns the maximum number of function calls that can be accumulated in the calling thread`s current batch.   
```  

***  

[GdiSetBatchLimit](libraries/gdi32/GdiSetBatchLimit.md)  
```txt  
Sets the maximum number of function calls that can be accumulated in the calling thread`s current batch. The system flushes the current batch whenever this limit is exceeded.   
```  

***  

[GetBkMode](libraries/gdi32/GetBkMode.md)  
```txt  
Returns the current background mix mode for a specified device context. The background mix mode of a device context affects text, hatched brushes, and pen styles that are not solid lines.  
```  

***  

[GetBoundsRect](libraries/gdi32/GetBoundsRect.md)  
```txt  
The GetBoundsRect function obtains the current accumulated bounding rectangle for a specified device context. The system maintains an accumulated bounding rectangle for each application. An application can retrieve and set this rectangle.  
```  

***  

[GetWindowDC](libraries/user32/GetWindowDC.md)  
```txt  
The GetWindowDC function retrieves the device context (DC) for the entire window, including title bar, menus, and scroll bars  
```  

***  

[GetWindowRgnBox](libraries/user32/GetWindowRgnBox.md)  
```txt  
Retrieves the dimensions of the tightest bounding rectangle for the window region of a window.   
```  

***  

[LockWindowUpdate](libraries/user32/LockWindowUpdate.md)  
```txt  
The LockWindowUpdate function disables or enables drawing in the specified window. Only one window can be locked at a time.  
```  

***  

[PaintDesktop](libraries/user32/PaintDesktop.md)  
```txt  
Fills the clipping region in the specified device context with the desktop pattern or wallpaper.  
```  

***  

[SetBkColor](libraries/gdi32/SetBkColor.md)  
```txt  
The SetBkColor function sets the current background color to the specified color value, or to the nearest physical color if the device cannot represent the specified color value.   
```  

***  

[SetBkMode](libraries/gdi32/SetBkMode.md)  
```txt  
Sets the background mix mode of the specified device context. The background mix mode is used with text, hatched brushes, and pen styles that are not solid lines.  
```  

***  

[SetWindowRgn](libraries/user32/SetWindowRgn.md)  
```txt  
Sets the window region of a window. The window region determines the area within the window where the system permits drawing. The system does not display any portion of a window that lies outside of the window region  
```  

***  

[WindowFromDC](libraries/user32/WindowFromDC.md)  
```txt  
Returns a handle to the window associated with the specified display device context (DC).
  
```  

***  


## @icon-book Path group
***  

[BeginPath](libraries/gdi32/BeginPath.md)  
```txt  
The BeginPath function opens a path bracket in the specified device context.  
```  

***  

[EndPath](libraries/gdi32/EndPath.md)  
```txt  
The EndPath function closes a path bracket and selects the path defined by the bracket into the specified device context.  
```  

***  

[PathToRegion](libraries/gdi32/PathToRegion.md)  
```txt  
Creates a region from the path that is selected into the specified device context. The resulting region uses device coordinates.  
```  

***  


## @icon-book Performance Monitoring group
***  

[CreateToolhelp32Snapshot](libraries/kernel32/CreateToolhelp32Snapshot.md)  
```txt  
Takes a snapshot of the processes and the heaps, modules, and threads used by the processes.  
```  

***  

[EnumDeviceDrivers](libraries/psapi/EnumDeviceDrivers.md)  
```txt  
The EnumDeviceDrivers function retrieves the load address for each device driver in the system.  
```  

***  

[EnumProcessModules](libraries/psapi/EnumProcessModules.md)  
```txt  
The EnumProcessModules function retrieves a handle for each module in the specified process.  
```  

***  

[EnumProcesses](libraries/psapi/EnumProcesses.md)  
```txt  
The EnumProcesses function retrieves the process identifier for each process object in the system.  
```  

***  

[GetDeviceDriverBaseName](libraries/psapi/GetDeviceDriverBaseName.md)  
```txt  
The GetDeviceDriverBaseName function retrieves the base name of the specified device driver.  
```  

***  

[GetDeviceDriverFileName](libraries/psapi/GetDeviceDriverFileName.md)  
```txt  
The GetDeviceDriverFileName function retrieves the fully qualified path for the specified device driver.  
```  

***  

[GetModuleBaseName](libraries/psapi/GetModuleBaseName.md)  
```txt  
The GetModuleBaseName function retrieves the base name of the specified module.  
```  

***  

[GetModuleFileNameEx](libraries/psapi/GetModuleFileNameEx.md)  
```txt  
The GetModuleFileNameEx function retrieves the fully qualified path for the specified module.  
```  

***  

[GetPerformanceInfo](libraries/psapi/GetPerformanceInfo.md)  
```txt  
Retrieves the performance values contained in the PERFORMANCE_INFORMATION structure.  
```  

***  

[GetProcessMemoryInfo](libraries/psapi/GetProcessMemoryInfo.md)  
```txt  
Retrieves information about the memory usage of the specified process in the PROCESS_MEMORY_COUNTERS structure.  
```  

***  

[Process32First](libraries/kernel32/Process32First.md)  
```txt  
Retrieves information about the first process encountered in a system snapshot.  
```  

***  

[Process32Next](libraries/kernel32/Process32Next.md)  
```txt  
Retrieves information about the next process recorded in a system snapshot.  
```  

***  


## @icon-book Pipe group
***  

[ConnectNamedPipe](libraries/kernel32/ConnectNamedPipe.md)  
```txt  
Enables a named pipe server process to wait for a client process to connect to an instance of a named pipe.   
```  

***  

[CreateNamedPipe](libraries/kernel32/CreateNamedPipe.md)  
```txt  
Creates an instance of a named pipe and returns a handle for subsequent pipe operations.   
```  

***  

[CreatePipe](libraries/kernel32/CreatePipe.md)  
```txt  
The CreatePipe function creates an anonymous pipe, and returns handles to the read and write ends of the pipe.
  
```  

***  

[DisconnectNamedPipe](libraries/kernel32/DisconnectNamedPipe.md)  
```txt  
Disconnects the server end of a named pipe instance from a client process.  
```  

***  

[SetNamedPipeHandleState](libraries/kernel32/SetNamedPipeHandleState.md)  
```txt  
Sets the read mode and the blocking mode of the specified named pipe. If the specified handle is to the client end of a named pipe and if the named pipe server process is on a remote computer, the function can also be used to control local buffering.
  
```  

***  


## @icon-book PnP Configuration Manager group
***  

[CM_Connect_Machine](libraries/cfgmgr32/CM_Connect_Machine.md)  
```txt  
Creates a connection to a remote machine  
```  

***  

[CM_Disconnect_Machine](libraries/cfgmgr32/CM_Disconnect_Machine.md)  
```txt  
Removes a connection to a remote machine established in a previous call to CM_Connect_Machine.  
```  

***  

[CM_Get_Child_Ex](libraries/cfgmgr32/CM_Get_Child_Ex.md)  
```txt  
The function is used to retrieve a device instance handle to the first child node of a specified device node, in a local or a remote machine"s device tree.
  
```  

***  

[CM_Get_Sibling_Ex](libraries/cfgmgr32/CM_Get_Sibling_Ex.md)  
```txt  
Obtains a device instance handle to the next sibling node of a specified device node, in a local or a remote machine"s device tree.  
```  

***  

[CM_Locate_DevNode_Ex](libraries/cfgmgr32/CM_Locate_DevNode_Ex.md)  
```txt  
Obtains a device instance handle to the device node that is associated with a specified device instance identifier, on a local machine or a remote machine.
  
```  

***  

[CM_Request_Device_Eject_Ex](libraries/setupapi/CM_Request_Device_Eject_Ex.md)  
```txt  
Prepares a local or a remote device instance for safe removal, if the device is removable.  
```  

***  


## @icon-book Power Management group
***  

[GetPwrCapabilities](libraries/powrprof/GetPwrCapabilities.md)  
```txt  
The GetPwrCapabilities function retrieves information about the system power capabilities.  
```  

***  

[GetSystemPowerStatus](libraries/kernel32/GetSystemPowerStatus.md)  
```txt  
Retrieves the power status of the system. The status indicates whether the system is running on AC or DC power, whether the battery is currently charging, and how much battery life remains.  
```  

***  

[IsPwrSuspendAllowed](libraries/powrprof/IsPwrSuspendAllowed.md)  
```txt  
Determines whether the computer supports the sleep states.  
```  

***  

[SetSuspendState](libraries/powrprof/SetSuspendState.md)  
```txt  
The SetSuspendState function suspends the system by shutting power down. Depending on the Hibernate parameter, the system either enters a suspend (sleep) state or hibernation (S4).  
```  

***  

[SetSystemPowerState](libraries/kernel32/SetSystemPowerState.md)  
```txt  
The SetSystemPowerState function suspends the system by shutting power down. Depending on the ForceFlag parameter, the function either suspends operation immediately or requests permission from all applications and device drivers before doing so.  
```  

***  

[SetThreadExecutionState](libraries/kernel32/SetThreadExecutionState.md)  
```txt  
Enables applications to inform the system that it is in use, thereby preventing the system from entering the sleeping power state or turning off the display while the application is running.  
```  

***  


## @icon-book Printing and Print Spooler group
***  

[AddPort](libraries/setupapi/AddPort.md)  
```txt  
Adds the name of a port to the list of supported ports. The AddPort function is exported by the port monitor.  
```  

***  

[AddPrinter](libraries/winspool.drv/AddPrinter.md)  
```txt  
The AddPrinter function adds a printer to the list of supported printers for a specified server.   
```  

***  

[ClosePrinter](libraries/winspool.drv/ClosePrinter.md)  
```txt  
The ClosePrinter function closes the specified printer object.   
```  

***  

[ConfigurePort](libraries/winspool.drv/ConfigurePort.md)  
```txt  
The ConfigurePort function displays the port-configuration dialog box for a port on the specified server.   
```  

***  

[ConnectToPrinterDlg](libraries/winspool.drv/ConnectToPrinterDlg.md)  
```txt  
The ConnectToPrinterDlg function displays a dialog box that lets users browse and connect to printers on a network. If the user selects a printer, the function attempts to create a connection to it; if a suitable driver is not installed on the server, the user is given the option of creating a printer locally.   
```  

***  

[DeletePort](libraries/winspool.drv/DeletePort.md)  
```txt  
Displays a dialog box that allows the user to delete a port name.  
```  

***  

[DeviceCapabilities](libraries/winspool.drv/DeviceCapabilities.md)  
```txt  
The DeviceCapabilities function retrieves the capabilities of a printer device driver.  
```  

***  

[DocumentProperties](libraries/winspool.drv/DocumentProperties.md)  
```txt  
The DocumentProperties function retrieves or modifies printer initialization information or displays a printer-configuration property sheet for the specified printer.   
```  

***  

[EndDoc](libraries/gdi32/EndDoc.md)  
```txt  
The EndDoc function ends a print job.  
```  

***  

[EndPage](libraries/gdi32/EndPage.md)  
```txt  
The EndPage function notifies the device that the application has finished writing to a page. This function is typically used to direct the device driver to advance to a new page.  
```  

***  

[EnumForms](libraries/winspool.drv/EnumForms.md)  
```txt  
The EnumForms function enumerates the forms supported by the specified printer.  
```  

***  

[EnumJobs](libraries/winspool.drv/EnumJobs.md)  
```txt  
The EnumJobs function retrieves information about a specified set of print jobs for a specified printer.   
```  

***  

[EnumPorts](libraries/winspool.drv/EnumPorts.md)  
```txt  
The EnumPorts function enumerates the ports that are available for printing on a specified server.  
```  

***  

[EnumPrintProcessorDatatypes](libraries/winspool.drv/EnumPrintProcessorDatatypes.md)  
```txt  
The EnumPrintProcessorDatatypes function enumerates the data types that a specified print processor supports.  
```  

***  

[EnumPrintProcessors](libraries/winspool.drv/EnumPrintProcessors.md)  
```txt  
The EnumPrintProcessors function enumerates the print processors installed on the specified server.  
```  

***  

[EnumPrinterData](libraries/winspool.drv/EnumPrinterData.md)  
```txt  
The EnumPrinterData function enumerates configuration data for a specified printer.   
```  

***  

[EnumPrinterDrivers](libraries/winspool.drv/EnumPrinterDrivers.md)  
```txt  
Enumerates the printer drivers installed on a specified printer server.  
```  

***  

[EnumPrinters](libraries/winspool.drv/EnumPrinters.md)  
```txt  
The EnumPrinters function enumerates available printers, print servers, domains, or print providers.  
```  

***  

[Escape](libraries/gdi32/Escape.md)  
```txt  
The Escape function enables applications to access capabilities of a particular device not directly available through GDI. Escape calls made by an application are translated and sent to the driver.   
```  

***  

[FindClosePrinterChangeNotification](libraries/winspool.drv/FindClosePrinterChangeNotification.md)  
```txt  
Closes a change notification object created by calling the FindFirstPrinterChangeNotification function.  
```  

***  

[FindFirstPrinterChangeNotification](libraries/winspool.drv/FindFirstPrinterChangeNotification.md)  
```txt  
Creates a change notification object and returns a handle to the object. You can then use this handle in a call to one of the wait functions to monitor changes to the printer or print server.
  
```  

***  

[FindNextPrinterChangeNotification](libraries/winspool.drv/FindNextPrinterChangeNotification.md)  
```txt  
Retrieves information about the most recent change notification for a change notification object associated with a printer or print server. Call this function when a wait operation on the change notification object is satisfied.  
```  

***  

[FreePrinterNotifyInfo](libraries/winspool.drv/FreePrinterNotifyInfo.md)  
```txt  
Frees a system-allocated buffer created by the FindNextPrinterChangeNotification function.
  
```  

***  

[GetDefaultPrinter](libraries/winspool.drv/GetDefaultPrinter.md)  
```txt  
The GetDefaultPrinter function retrieves the printer name of the default printer for the current user on the local computer.  
```  

***  

[GetPrintProcessorDirectory](libraries/winspool.drv/GetPrintProcessorDirectory.md)  
```txt  
The GetPrintProcessorDirectory function retrieves the path for the print processor on the specified server.   
```  

***  

[GetPrinter](libraries/winspool.drv/GetPrinter.md)  
```txt  
The GetPrinter function retrieves information about a specified printer.   
```  

***  

[GetPrinterData](libraries/winspool.drv/GetPrinterData.md)  
```txt  
The GetPrinterData function retrieves configuration data for the specified printer or print server.   
```  

***  

[GetPrinterDriverDirectory](libraries/winspool.drv/GetPrinterDriverDirectory.md)  
```txt  
The GetPrinterDriverDirectory function retrieves the path of the printer-driver directory.   
```  

***  

[OpenPrinter](libraries/winspool.drv/OpenPrinter.md)  
```txt  
The OpenPrinter function retrieves a handle to the specified printer or print server or other types of handles in the print subsystem.  
```  

***  

[PrinterProperties](libraries/winspool.drv/PrinterProperties.md)  
```txt  
The PrinterProperties function displays a printer-properties property sheet for the specified printer.   
```  

***  

[SetDefaultPrinter](libraries/winspool.drv/SetDefaultPrinter.md)  
```txt  
Sets the printer name of the default printer for the current user on the local computer.  
```  

***  

[SetJob](libraries/winspool.drv/SetJob.md)  
```txt  
The SetJob function pauses, resumes, cancels, or restarts a print job on a specified printer. You can also use the SetJob function to set print job parameters, such as the print job priority and the document name.   
```  

***  

[SetPrinter](libraries/winspool.drv/SetPrinter.md)  
```txt  
The SetPrinter function sets the data for a specified printer or sets the state of the specified printer by pausing printing, resuming printing, or clearing all print jobs.   
```  

***  

[StartDoc](libraries/gdi32/StartDoc.md)  
```txt  
The StartDoc function starts a print job.  
```  

***  

[StartPage](libraries/gdi32/StartPage.md)  
```txt  
The StartPage function prepares the printer driver to accept data.  
```  

***  


## @icon-book Process and Thread group
***  

[AssignProcessToJobObject](libraries/kernel32/AssignProcessToJobObject.md)  
```txt  
Assigns a process to an existing job object.  
```  

***  

[CommandLineToArgvW](libraries/shell32/CommandLineToArgvW.md)  
```txt  
Parses a Unicode command-line string, and returns a pointer to a set of Unicode argument strings and a count of arguments, similar to the standard C run-time argv and argc values  
```  

***  

[CreateJobObject](libraries/kernel32/CreateJobObject.md)  
```txt  
Creates or opens a job object.
  
```  

***  

[CreateProcess](libraries/kernel32/CreateProcess.md)  
```txt  
The CreateProcess function creates a new process and its primary thread. The new process runs the specified executable file.

The CreateProcess function is used to run a new program. The WinExec and LoadModule functions are still available, but they are implemented as calls to CreateProcess  
```  

***  

[CreateProcessAsUser](libraries/advapi32/CreateProcessAsUser.md)  
```txt  
The CreateProcessAsUser function creates a new process and its primary thread. The new process then runs the specified executable file. The CreateProcessAsUser function is similar to the CreateProcess function, except that the new process runs in the security context of the user represented by the hToken parameter.  
```  

***  

[CreateProcessWithLogonW](libraries/advapi32/CreateProcessWithLogonW.md)  
```txt  
The CreateProcessWithLogonW function creates a new process and its primary thread. The new process then runs the specified executable file in the security context of the specified credentials (user, domain, and password). It can optionally load the user profile for the specified user.  
```  

***  

[ExitProcess](libraries/kernel32/ExitProcess.md)  
```txt  
The ExitProcess function ends a process and all its threads.  
```  

***  

[FreeEnvironmentStrings](libraries/kernel32/FreeEnvironmentStrings.md)  
```txt  
The FreeEnvironmentStrings function frees a block of environment strings.  
```  

***  

[GetCommandLine](libraries/kernel32/GetCommandLine.md)  
```txt  
Returns a pointer to the command-line string for the current process.  
```  

***  

[GetCurrentProcess](libraries/kernel32/GetCurrentProcess.md)  
```txt  
The GetCurrentProcess function retrieves a <Strong>pseudo</Strong> handle for the current process.  
```  

***  

[GetCurrentProcessId](libraries/kernel32/GetCurrentProcessId.md)  
```txt  
The GetCurrentProcessId function retrieves the process identifier of the calling process.  
```  

***  

[GetCurrentThread](libraries/kernel32/GetCurrentThread.md)  
```txt  
The GetCurrentThread function retrieves a <Strong>pseudo</Strong> handle for the current thread.  
```  

***  

[GetCurrentThreadId](libraries/kernel32/GetCurrentThreadId.md)  
```txt  
The GetCurrentThreadId function retrieves the thread identifier of the calling thread.  
```  

***  

[GetEnvironmentStrings](libraries/kernel32/GetEnvironmentStrings.md)  
```txt  
Retrieves the environment block for the current process.
  
```  

***  

[GetEnvironmentVariable](libraries/kernel32/GetEnvironmentVariable.md)  
```txt  
Retrieves the value of the specified variable from the environment block of the calling process. The value is in the form of a null-terminated string of characters.  
```  

***  

[GetPriorityClass](libraries/kernel32/GetPriorityClass.md)  
```txt  
Retrieves the priority class for the specified process. This value, together with the priority value of each thread of the process, determines each thread"s base priority level.  
```  

***  

[GetProcessIoCounters](libraries/kernel32/GetProcessIoCounters.md)  
```txt  
Retrieves accounting information for all I/O operations performed by the specified process.  
```  

***  

[GetProcessTimes](libraries/kernel32/GetProcessTimes.md)  
```txt  
Retrieves timing information for the specified process.  
```  

***  

[GetProcessVersion](libraries/kernel32/GetProcessVersion.md)  
```txt  
Retrieves the major and minor version numbers of the system on which the specified process expects to run.  
```  

***  

[GetStartupInfo](libraries/kernel32/GetStartupInfo.md)  
```txt  
Retrieves the contents of the STARTUPINFO structure that was specified when the calling process was created.  
```  

***  

[GetThreadPriority](libraries/kernel32/GetThreadPriority.md)  
```txt  
Retrieves the priority value for the specified thread. This value, together with the priority class of the thread"s process, determines the thread"s base-priority level.  
```  

***  

[IsWow64Process](libraries/kernel32/IsWow64Process.md)  
```txt  
Determines whether the specified process is running under WOW64.  
```  

***  

[OpenProcess](libraries/kernel32/OpenProcess.md)  
```txt  
The OpenProcess function opens an existing process object.  
```  

***  

[RegisterServiceProcess](libraries/kernel32/RegisterServiceProcess.md)  
```txt  
The RegisterServiceProcess function registers or unregisters a service process. A service process continues to run after the user logs off.   
```  

***  

[SetEnvironmentVariable](libraries/kernel32/SetEnvironmentVariable.md)  
```txt  
The SetEnvironmentVariable function sets the value of an environment variable for the current process.  
```  

***  

[SetPriorityClass](libraries/kernel32/SetPriorityClass.md)  
```txt  
Sets the priority class for the specified process. This value together with the priority value of each thread of the process determines each thread"s base priority level.  
```  

***  

[SetThreadPriority](libraries/kernel32/SetThreadPriority.md)  
```txt  
Sets the priority value for the specified thread. This value, together with the priority class of the thread"s process, determines the thread"s base priority level.  
```  

***  

[Sleep](libraries/kernel32/Sleep.md)  
```txt  
The Sleep function suspends the execution of the current thread for the specified interval  
```  

***  

[TerminateJobObject](libraries/kernel32/TerminateJobObject.md)  
```txt  
Terminates all processes currently associated with the job.
  
```  

***  

[TerminateProcess](libraries/kernel32/TerminateProcess.md)  
```txt  
The TerminateProcess function terminates the specified process and all of its threads.  
```  

***  

[WinExec](libraries/kernel32/WinExec.md)  
```txt  
The WinExec function runs the specified application.

Note  This function is provided only for compatibility with 16-bit Windows. Win32-based applications should use the CreateProcess function
  
```  

***  


## @icon-book Raw Input group
***  

[GetRawInputData](libraries/user32/GetRawInputData.md)  
```txt  
Retrieves the raw input from the specified device.  
```  

***  

[GetRawInputDeviceInfo](libraries/user32/GetRawInputDeviceInfo.md)  
```txt  
Retrieves information about the raw input device.  
```  

***  

[GetRawInputDeviceList](libraries/user32/GetRawInputDeviceList.md)  
```txt  
Enumerates the raw input devices attached to the system.  
```  

***  

[RegisterRawInputDevices](libraries/user32/RegisterRawInputDevices.md)  
```txt  
Registers the devices that supply the raw input data.  
```  

***  


## @icon-book Region group
***  

[CombineRgn](libraries/gdi32/CombineRgn.md)  
```txt  
The CombineRgn function combines two regions and stores the result in a third region. The two regions are combined according to the specified mode.  
```  

***  

[CreateEllipticRgn](libraries/gdi32/CreateEllipticRgn.md)  
```txt  
The CreateEllipticRgn function creates an elliptical region.  
```  

***  

[CreateRectRgn](libraries/gdi32/CreateRectRgn.md)  
```txt  
Creates a rectangular region.  
```  

***  

[CreateRoundRectRgn](libraries/gdi32/CreateRoundRectRgn.md)  
```txt  
Creates a rectangular region with rounded corners.  
```  

***  

[FrameRgn](libraries/gdi32/FrameRgn.md)  
```txt  
The FrameRgn function draws a border around the specified region by using the specified brush.  
```  

***  

[GetRegionData](libraries/gdi32/GetRegionData.md)  
```txt  
Fills the specified buffer with data describing a region. This data includes the dimensions of the rectangles that make up the region.  
```  

***  

[GetRgnBox](libraries/gdi32/GetRgnBox.md)  
```txt  
Retrieves the bounding rectangle of the specified region.  
```  

***  


## @icon-book Registry group
***  

[GetPrivateProfileSectionNames](libraries/kernel32/GetPrivateProfileSectionNames.md)  
```txt  
The GetPrivateProfileSectionNames function retrieves the names of all sections in an initialization file.  
```  

***  

[GetPrivateProfileString](libraries/kernel32/GetPrivateProfileString.md)  
```txt  
Retrieves a string from the specified section in an initialization file.  
```  

***  

[GetProfileString](libraries/kernel32/GetProfileString.md)  
```txt  
Retrieves the string associated with a key in the specified section of the Win.ini file.  
```  

***  

[RegCloseKey](libraries/advapi32/RegCloseKey.md)  
```txt  
The RegCloseKey function releases a handle to the specified registry key.  
```  

***  

[RegCreateKeyEx](libraries/advapi32/RegCreateKeyEx.md)  
```txt  
The RegCreateKeyEx function creates the specified registry key. If the key already exists, the function opens it.  
```  

***  

[RegDeleteKey](libraries/advapi32/RegDeleteKey.md)  
```txt  
The RegDeleteKey function deletes a subkey, including all of its values.  
```  

***  

[RegDeleteValue](libraries/advapi32/RegDeleteValue.md)  
```txt  
The RegDeleteValue function removes a named value from the specified registry key.  
```  

***  

[RegEnumKey](libraries/advapi32/RegEnumKey.md)  
```txt  
The RegEnumKey function enumerates subkeys of the specified open registry key. The function retrieves the name of one subkey each time it is called.  
```  

***  

[RegEnumKeyEx](libraries/advapi32/RegEnumKeyEx.md)  
```txt  
The RegEnumKeyEx function enumerates subkeys of the specified open registry key. The function retrieves information about one subkey each time it is called.  
```  

***  

[RegEnumValue](libraries/advapi32/RegEnumValue.md)  
```txt  
Enumerates the values for the specified open registry key.  
```  

***  

[RegOpenKeyEx](libraries/advapi32/RegOpenKeyEx.md)  
```txt  
The RegOpenKeyEx function opens the specified registry key.  
```  

***  

[RegQueryInfoKey](libraries/advapi32/RegQueryInfoKey.md)  
```txt  
The RegQueryInfoKey function retrieves information about the specified registry key.  
```  

***  

[RegQueryValueEx](libraries/advapi32/RegQueryValueEx.md)  
```txt  
Retrieves the type and data for a specified value name associated with an open registry key.  
```  

***  

[RegSaveKey](libraries/advapi32/RegSaveKey.md)  
```txt  
The RegSaveKey function saves the specified key and all of its subkeys and values to a new file.  
```  

***  

[RegSetValueEx](libraries/advapi32/RegSetValueEx.md)  
```txt  
The RegSetValueEx function sets the data and type of a specified value under a registry key.  
```  

***  

[SHEnumKeyEx](libraries/shlwapi/SHEnumKeyEx.md)  
```txt  
Enumerates the subkeys of the specified open registry key.  
```  

***  

[SHRegCloseUSKey](libraries/shlwapi/SHRegCloseUSKey.md)  
```txt  
Closes a handle to a user-specific registry key.  
```  

***  

[SHRegEnumUSKey](libraries/shlwapi/SHRegEnumUSKey.md)  
```txt  
Enumerates the subkeys of a user-specific key.  
```  

***  

[SHRegOpenUSKey](libraries/shlwapi/SHRegOpenUSKey.md)  
```txt  
Opens a user-specific registry key.  
```  

***  

[WritePrivateProfileSection](libraries/kernel32/WritePrivateProfileSection.md)  
```txt  
Replaces the keys and values for the specified section in an initialization file.  
```  

***  

[WritePrivateProfileString](libraries/kernel32/WritePrivateProfileString.md)  
```txt  
The WritePrivateProfileString function copies a string into the specified section of an initialization file.  
```  

***  


## @icon-book Remote Access Service (RAS) group
***  

[RasEnumAutodialAddresses](libraries/rasapi32/RasEnumAutodialAddresses.md)  
```txt  
The RasEnumAutodialAddresses function returns a list of all addresses in the AutoDial mapping database.  
```  

***  

[RasEnumConnections](libraries/rasapi32/RasEnumConnections.md)  
```txt  
The RasEnumConnections function lists all active RAS connections. It returns each connection"s handle and phone-book entry name.   
```  

***  

[RasEnumDevices](libraries/rasapi32/RasEnumDevices.md)  
```txt  
The RasEnumDevices function returns the name and type of all available RAS-capable devices.  
```  

***  

[RasGetCountryInfo](libraries/rasapi32/RasGetCountryInfo.md)  
```txt  
The RasGetCountryInfo function retrieves country-specific dialing information from the Windows Telephony list of countries.  
```  

***  

[RasPhonebookDlg](libraries/rasdlg/RasPhonebookDlg.md)  
```txt  
The RasPhonebookDlg function displays the main Dial-Up Networking dialog box. From this modal dialog box, the user can dial, edit, or delete a selected phone-book entry, create a new phone-book entry, or specify user preferences. The RasPhonebookDlg function returns when the dialog box closes.  
```  

***  


## @icon-book Remote Application Programming (RAPI) group
***  

[CeCloseHandle](libraries/rapi/CeCloseHandle.md)  
```txt  
This function closes an open object handle.  
```  

***  

[CeCopyFile](libraries/rapi/CeCopyFile.md)  
```txt  
This function copies an existing file to a new file.  
```  

***  

[CeCreateDatabase](libraries/rapi/CeCreateDatabase.md)  
```txt  
This function creates a new database.  
```  

***  

[CeCreateDirectory](libraries/rapi/CeCreateDirectory.md)  
```txt  
This function creates a new directory.  
```  

***  

[CeCreateFile](libraries/rapi/CeCreateFile.md)  
```txt  
This function creates, opens, or truncates a file, pipe, communications resource, disk device, or console. It returns a handle that can be used to access the object. It can also open and return a handle to a directory.  
```  

***  

[CeCreateProcess](libraries/rapi/CeCreateProcess.md)  
```txt  
This function is used to run a new program. It creates a new process and its primary thread. The new process executes the specified executable file.  
```  

***  

[CeDeleteDatabase](libraries/rapi/CeDeleteDatabase.md)  
```txt  
This function removes a database from the object store.  
```  

***  

[CeDeleteFile](libraries/rapi/CeDeleteFile.md)  
```txt  
This function deletes an existing file from the object store.  
```  

***  

[CeDeleteRecord](libraries/rapi/CeDeleteRecord.md)  
```txt  
This function deletes a record from a database.  
```  

***  

[CeEnumDBVolumes](libraries/rapi/CeEnumDBVolumes.md)  
```txt  
This function enumerates all mounted database volumes and returns the name for each.   
```  

***  

[CeFindAllFiles](libraries/rapi/CeFindAllFiles.md)  
```txt  
This function retrieves information about all files and directories in the given directory of the Windows CE object store.   
```  

***  

[CeFindFirstDatabaseEx](libraries/rapi/CeFindFirstDatabaseEx.md)  
```txt  
This function opens an enumeration context for all databases in a database volume.   
```  

***  

[CeFindFirstFile](libraries/rapi/CeFindFirstFile.md)  
```txt  
This function searches a directory for a file whose name matches the specified filename. CeFindFirstFile examines subdirectory names as well as filenames.  
```  

***  

[CeFindNextDatabaseEx](libraries/rapi/CeFindNextDatabaseEx.md)  
```txt  
This function retrieves the next database in an enumeration context.  
```  

***  

[CeGetFileSize](libraries/rapi/CeGetFileSize.md)  
```txt  
This function retrieves the size, in bytes, of the specified file.  
```  

***  

[CeGetLastError](libraries/rapi/CeGetLastError.md)  
```txt  
This function returns the calling thread"s last-error code value.   
```  

***  

[CeGetSpecialFolderPath](libraries/rapi/CeGetSpecialFolderPath.md)  
```txt  
This function gets the path to a special shell folder.  
```  

***  

[CeGetStoreInformation](libraries/rapi/CeGetStoreInformation.md)  
```txt  
This function fills in a STORE_INFORMATION structure with the size of the object store and the amount of free space currently in the object store.   
```  

***  

[CeGetSystemInfo](libraries/rapi/CeGetSystemInfo.md)  
```txt  
This function returns information about the current system.   
```  

***  

[CeGetSystemPowerStatusEx](libraries/rapi/CeGetSystemPowerStatusEx.md)  
```txt  
This function retrieves the power status of the system.  
```  

***  

[CeGetTempPath](libraries/rapi/CeGetTempPath.md)  
```txt  
This function gets the path to the directory designated for temporary files.   
```  

***  

[CeGetVersionEx](libraries/rapi/CeGetVersionEx.md)  
```txt  
This function obtains extended information about the version of the operating system that is currently running.   
```  

***  

[CeGlobalMemoryStatus](libraries/rapi/CeGlobalMemoryStatus.md)  
```txt  
This function gets information on the physical and virtual memory of the system.  
```  

***  

[CeMoveFile](libraries/rapi/CeMoveFile.md)  
```txt  
This function renames an existing file or a directory — including all its children.  
```  

***  

[CeOidGetInfoEx](libraries/rapi/CeOidGetInfoEx.md)  
```txt  
This function retrieves information about an object in the object store or a mounted database volume.   
```  

***  

[CeOpenDatabase](libraries/rapi/CeOpenDatabase.md)  
```txt  
This function opens an existing database on any database volume, including mounted databases.   
```  

***  

[CeRapiFreeBuffer](libraries/rapi/CeRapiFreeBuffer.md)  
```txt  
This function frees the memory on the desktop computer allocated by a call to CeFindAllDatabases, CeFindAllFiles, or CeReadRecordProps.   
```  

***  

[CeRapiGetError](libraries/rapi/CeRapiGetError.md)  
```txt  
This function reports remote API related failures. CeRapiGetError can be used to determine if a call failed due to a failure in the remote API.   
```  

***  

[CeRapiInit](libraries/rapi/CeRapiInit.md)  
```txt  
This function attempts to initialize the Windows CE remote application programming interface (RAPI).  
```  

***  

[CeRapiInitEx](libraries/rapi/CeRapiInitEx.md)  
```txt  
This function attempts to initialize the Windows CE remote application programming interface (RAPI) and initially returns an event handle.  
```  

***  

[CeRapiInvoke](libraries/rapi/CeRapiInvoke.md)  
```txt  
This function can be used as a general-purpose mechanism to remotely execute a routine on the Windows CE device.  
```  

***  

[CeRapiUninit](libraries/rapi/CeRapiUninit.md)  
```txt  
This function uninitializes the Windows CE remote application programming interface (RAPI).   
```  

***  

[CeReadFile](libraries/rapi/CeReadFile.md)  
```txt  
This function reads data from a file, starting at the position indicated by the file pointer.   
```  

***  

[CeReadRecordProps](libraries/rapi/CeReadRecordProps.md)  
```txt  
This function reads properties from the current record.  
```  

***  

[CeRegCloseKey](libraries/rapi/CeRegCloseKey.md)  
```txt  
This function releases the handle of the specified key.  
```  

***  

[CeRegCreateKeyEx](libraries/rapi/CeRegCreateKeyEx.md)  
```txt  
This function creates the specified key. If the key already exists in the registry, the function opens it.   
```  

***  

[CeRegDeleteKey](libraries/rapi/CeRegDeleteKey.md)  
```txt  
This function deletes a named subkey from the specified registry key. The subkey to be deleted cannot have any subkeys.  
```  

***  

[CeRegDeleteValue](libraries/rapi/CeRegDeleteValue.md)  
```txt  
This function removes a named value from the specified registry key.   
```  

***  

[CeRegEnumKeyEx](libraries/rapi/CeRegEnumKeyEx.md)  
```txt  
This function enumerates subkeys of the specified open registry key.   
```  

***  

[CeRegEnumValue](libraries/rapi/CeRegEnumValue.md)  
```txt  
This function enumerates the values for the specified open registry key. CeRegEnumValue copies one indexed value name and data block for the key each time it is called.  
```  

***  

[CeRegOpenKeyEx](libraries/rapi/CeRegOpenKeyEx.md)  
```txt  
This function opens the specified key.  
```  

***  

[CeRegQueryInfoKey](libraries/rapi/CeRegQueryInfoKey.md)  
```txt  
This function retrieves information about a specified registry key.  
```  

***  

[CeRegQueryValueEx](libraries/rapi/CeRegQueryValueEx.md)  
```txt  
This function retrieves the type and data for a specified value name associated with an open registry key.   
```  

***  

[CeRegSetValueEx](libraries/rapi/CeRegSetValueEx.md)  
```txt  
This function stores data in the value field of an open registry key. It can also set additional value and type information for the specified key.   
```  

***  

[CeRemoveDirectory](libraries/rapi/CeRemoveDirectory.md)  
```txt  
This function deletes an existing empty directory.  
```  

***  

[CeSeekDatabase](libraries/rapi/CeSeekDatabase.md)  
```txt  
This function seeks the specified record in an open database.  
```  

***  

[CeSetFilePointer](libraries/rapi/CeSetFilePointer.md)  
```txt  
This function moves the file pointer of an open file.  
```  

***  

[CeWriteFile](libraries/rapi/CeWriteFile.md)  
```txt  
This function writes data to a file on remote Windows CE device.  
```  

***  

[CeWriteRecordProps](libraries/rapi/CeWriteRecordProps.md)  
```txt  
This function writes a set of properties to a single record, creating the record if necessary.  
```  

***  


## @icon-book Remote Procedure Call (RPC) group
***  

[RpcStringFree](libraries/rpcrt4/RpcStringFree.md)  
```txt  
Frees a character string allocated by the RPC run-time library.  
```  

***  

[UuidCompare](libraries/rpcrt4/UuidCompare.md)  
```txt  
Compare two UUIDs and determine their order. The returned value gives the order.  
```  

***  

[UuidCreate](libraries/rpcrt4/UuidCreate.md)  
```txt  
Creates a new UUID.  
```  

***  

[UuidCreateNil](libraries/rpcrt4/UuidCreateNil.md)  
```txt  
Creates a nil-valued UUID.  
```  

***  

[UuidCreateSequential](libraries/rpcrt4/UuidCreateSequential.md)  
```txt  
Creates a new UUID.  
```  

***  

[UuidFromString](libraries/rpcrt4/UuidFromString.md)  
```txt  
Converts a string to a UUID.  
```  

***  

[UuidToString](libraries/rpcrt4/UuidToString.md)  
```txt  
Converts a UUID to a string.  
```  

***  


## @icon-book Resource group
***  

[BeginUpdateResource](libraries/kernel32/BeginUpdateResource.md)  
```txt  
The BeginUpdateResource function returns a handle that can be used by the UpdateResource function to add, delete, or replace resources in an executable file.  
```  

***  

[CopyImage](libraries/user32/CopyImage.md)  
```txt  
Creates a new image (icon, cursor, or bitmap) and copies the attributes of the specified image to the new one. If necessary, the function stretches the bits to fit the desired size of the new image.  
```  

***  

[EndUpdateResource](libraries/kernel32/EndUpdateResource.md)  
```txt  
The EndUpdateResource function ends a resource update in an executable file.  
```  

***  

[FindResource](libraries/kernel32/FindResource.md)  
```txt  
The FindResource function determines the location of a resource with the specified type and name in the specified module.  
```  

***  

[LoadImage](libraries/user32/LoadImage.md)  
```txt  
The LoadImage function loads an icon, cursor, animated cursor, or bitmap.  
```  

***  

[LoadResource](libraries/kernel32/LoadResource.md)  
```txt  
The LoadResource function loads the specified resource into global memory.  
```  

***  

[LoadString](libraries/user32/LoadString.md)  
```txt  
Loads a string resource from the executable file associated with a specified module, copies the string into a buffer, and appends a terminating null character.  
```  

***  

[LockResource](libraries/kernel32/LockResource.md)  
```txt  
The LockResource function locks the specified resource in memory.  
```  

***  

[SizeofResource](libraries/kernel32/SizeofResource.md)  
```txt  
The SizeofResource function returns the size, in bytes, of the specified resource.  
```  

***  

[UpdateResource](libraries/kernel32/UpdateResource.md)  
```txt  
The UpdateResource function adds, deletes, or replaces a resource in an executable file.  
```  

***  


## @icon-book Security group
***  

[ConvertSidToStringSid](libraries/advapi32/ConvertSidToStringSid.md)  
```txt  
Converts a security identifier (SID) to a string format suitable for display, storage, or transmission.  
```  

***  

[GetAce](libraries/advapi32/GetAce.md)  
```txt  
Obtains a pointer to an access control entry (ACE) in an access control list (ACL).
  
```  

***  

[GetAclInformation](libraries/advapi32/GetAclInformation.md)  
```txt  
Retrieves information about an access control list (ACL).
  
```  

***  

[GetFileSecurity](libraries/advapi32/GetFileSecurity.md)  
```txt  
The GetFileSecurity function obtains specified information about the security of a file or directory.   
```  

***  

[GetLengthSid](libraries/advapi32/GetLengthSid.md)  
```txt  
The GetLengthSid function returns the length, in bytes, of a valid security identifier (SID).  
```  

***  

[GetNamedSecurityInfo](libraries/advapi32/GetNamedSecurityInfo.md)  
```txt  
The GetNamedSecurityInfo function retrieves a copy of the security descriptor for an object specified by name.  
```  

***  

[GetSecurityDescriptorDacl](libraries/advapi32/GetSecurityDescriptorDacl.md)  
```txt  
Retrieves a pointer to the discretionary access control list (DACL) in a specified security descriptor.  
```  

***  

[GetSecurityDescriptorOwner](libraries/advapi32/GetSecurityDescriptorOwner.md)  
```txt  
The GetSecurityDescriptorOwner function retrieves the owner information from a security descriptor.  
```  

***  

[ImpersonateLoggedOnUser](libraries/advapi32/ImpersonateLoggedOnUser.md)  
```txt  
The ImpersonateLoggedOnUser function lets the calling thread impersonate the security context of a logged-on user. The user is represented by a token handle.  
```  

***  

[IsValidSid](libraries/advapi32/IsValidSid.md)  
```txt  
The IsValidSid function validates a security identifier (SID) by verifying that the revision number is within a known range, and that the number of subauthorities is less than the maximum.  
```  

***  

[IsWellKnownSid](libraries/advapi32/IsWellKnownSid.md)  
```txt  
Compares a SID to a well known SID and returns TRUE if they match.
  
```  

***  

[LogonUser](libraries/advapi32/LogonUser.md)  
```txt  
The LogonUser function attempts to log a user on to the local computer. The local computer is the computer from which LogonUser was called. You cannot use LogonUser to log on to a remote computer.   
```  

***  

[LookupAccountName](libraries/advapi32/LookupAccountName.md)  
```txt  
Accepts the name of a system and an account as input. It retrieves a security identifier (SID) for the account and the name of the domain on which the account was found.
  
```  

***  

[LookupAccountSid](libraries/advapi32/LookupAccountSid.md)  
```txt  
The LookupAccountSid function accepts a security identifier (SID) as input. It retrieves the name of the account for this SID and the name of the first domain on which this SID is found.  
```  

***  

[LsaClose](libraries/advapi32/LsaClose.md)  
```txt  
The LsaClose function closes a handle to a Policy or TrustedDomain object.  
```  

***  

[LsaEnumerateLogonSessions](libraries/secur32/LsaEnumerateLogonSessions.md)  
```txt  
Retrieves the set of existing logon session identifiers (LUIDs) and the number of sessions.
  
```  

***  

[LsaFreeMemory](libraries/advapi32/LsaFreeMemory.md)  
```txt  
The LsaFreeMemory function frees memory allocated for an output buffer by an LSA function call.  
```  

***  

[LsaFreeReturnBuffer](libraries/secur32/LsaFreeReturnBuffer.md)  
```txt  
Frees the memory used by a buffer previously allocated by the LSA.  
```  

***  

[LsaGetLogonSessionData](libraries/secur32/LsaGetLogonSessionData.md)  
```txt  
Retrieves information about a specified logon session.  
```  

***  

[LsaLookupSids](libraries/advapi32/LsaLookupSids.md)  
```txt  
The LsaLookupSids function looks up the names that correspond to an array of SIDs.  
```  

***  

[LsaOpenPolicy](libraries/advapi32/LsaOpenPolicy.md)  
```txt  
The LsaOpenPolicy function opens a handle to the Policy object on a local or remote system.  
```  

***  

[RevertToSelf](libraries/advapi32/RevertToSelf.md)  
```txt  
The RevertToSelf function terminates the impersonation of a client application.  
```  

***  


## @icon-book Service group
***  

[CloseServiceHandle](libraries/advapi32/CloseServiceHandle.md)  
```txt  
The CloseServiceHandle function closes a handle to a service control manager or service object.  
```  

***  

[ControlService](libraries/advapi32/ControlService.md)  
```txt  
The ControlService function sends a control code to a service.
  
```  

***  

[CreateService](libraries/advapi32/CreateService.md)  
```txt  
Creates a service object and adds it to the specified service control manager database.  
```  

***  

[DeleteService](libraries/advapi32/DeleteService.md)  
```txt  
Marks the specified service for deletion from the service control manager database.  
```  

***  

[EnumServicesStatus](libraries/advapi32/EnumServicesStatus.md)  
```txt  
The EnumServicesStatus function enumerates services in the specified service control manager database.  
```  

***  

[GetUserObjectInformation](libraries/user32/GetUserObjectInformation.md)  
```txt  
The GetUserObjectInformation function retrieves information about a window station or desktop object.  
```  

***  

[LockServiceDatabase](libraries/advapi32/LockServiceDatabase.md)  
```txt  
The LockServiceDatabase function requests ownership of the service control manager database lock. Only one process can own the lock at any given time.
  
```  

***  

[OpenSCManager](libraries/advapi32/OpenSCManager.md)  
```txt  
The OpenSCManager function establishes a connection to the service control manager on the specified computer and opens the specified service control manager database.
  
```  

***  

[OpenService](libraries/advapi32/OpenService.md)  
```txt  
The OpenService function opens an existing service.
  
```  

***  

[StartService](libraries/advapi32/StartService.md)  
```txt  
The StartService function starts a service.
  
```  

***  

[UnlockServiceDatabase](libraries/advapi32/UnlockServiceDatabase.md)  
```txt  
The UnlockServiceDatabase function unlocks a service control manager database by releasing the specified lock.
  
```  

***  


## @icon-book Setup API functions group
***  

[SetupCloseInfFile](libraries/setupapi/SetupCloseInfFile.md)  
```txt  
Closes the INF file opened by a call to SetupOpenInfFile and any INF files appended to it by SetupOpenAppendInfFile.  
```  

***  

[SetupDiDestroyClassImageList](libraries/setupapi/SetupDiDestroyClassImageList.md)  
```txt  
Destroys a class image list that was built by a call to SetupDiGetClassImageList or SetupDiGetClassImageListEx.
  
```  

***  

[SetupDiGetClassImageIndex](libraries/setupapi/SetupDiGetClassImageIndex.md)  
```txt  
Retrieves the index within the class image list of a specified class.  
```  

***  

[SetupDiGetClassImageListEx](libraries/setupapi/SetupDiGetClassImageListEx.md)  
```txt  
Builds an image list of bitmaps for every class installed on a local or remote system.
  
```  

***  

[SetupGetInfFileList](libraries/setupapi/SetupGetInfFileList.md)  
```txt  
Returns a list of INF files located in a caller-specified directory to a call-supplied buffer.  
```  

***  

[SetupGetInfInformation](libraries/setupapi/SetupGetInfInformation.md)  
```txt  
Returns the SP_INF_INFORMATION structure for the specified INF file to a caller-supplied buffer.
  
```  

***  

[SetupOpenInfFile](libraries/setupapi/SetupOpenInfFile.md)  
```txt  
The SetupOpenInfFile function opens an INF file and returns a handle to it.  
```  

***  


## @icon-book Shell Functions group
***  

[AssocQueryString](libraries/shlwapi/AssocQueryString.md)  
```txt  
Searches for and retrieves a file or protocol association-related string from the registry.  
```  

***  

[DllGetVersion](libraries/shell32/DllGetVersion.md)  
```txt  
Implemented by many of the Microsoft® Windows® Shell dynamic-link libraries (DLLs) to allow applications to obtain DLL-specific version information.  
```  

***  

[DragAcceptFiles](libraries/user32/DragAcceptFiles.md)  
```txt  
Registers whether a window accepts dropped files.  
```  

***  

[DragFinish](libraries/shell32/DragFinish.md)  
```txt  
Releases memory that the system allocated for use in transferring file names to the application.  
```  

***  

[DragQueryFile](libraries/shell32/DragQueryFile.md)  
```txt  
Retrieves the names of dropped files that result from a successful drag-and-drop operation.  
```  

***  

[DragQueryPoint](libraries/shell32/DragQueryPoint.md)  
```txt  
Retrieves the position of the mouse pointer at the time a file was dropped during a drag-and-drop operation.  
```  

***  

[FileIconInit](libraries/shell32/FileIconInit.md)  
```txt  
Reinitializes the system image list.  
```  

***  

[FindExecutable](libraries/shell32/FindExecutable.md)  
```txt  
Retrieves the name of and handle to the executable (.exe) file associated with the specified file name.  
```  

***  

[GetFileNameFromBrowse](libraries/shell32/GetFileNameFromBrowse.md)  
```txt  
This function creates an Open dialog box that lets the user specify the drive, directory, and name of a file to open.   
```  

***  

[GetMenuContextHelpId](libraries/user32/GetMenuContextHelpId.md)  
```txt  
Retrieves the Help context identifier associated with the specified menu.  
```  

***  

[GetWindowContextHelpId](libraries/user32/GetWindowContextHelpId.md)  
```txt  
The GetWindowContextHelpId function retrieves the help context identifier, if any, associated with the specified window.

Windows NT only  
```  

***  

[InetIsOffline](libraries/urlmon/InetIsOffline.md)  
```txt  
Determines whether or not the system is connected to the Internet.  
```  

***  

[IsUserAnAdmin](libraries/shell32/IsUserAnAdmin.md)  
```txt  
Tests whether the current user is a member of the Administrator"s group.  
```  

***  

[LoadUserProfile](libraries/userenv/LoadUserProfile.md)  
```txt  
Loads the specified user"s profile. The profile can be a local user profile or a roaming user profile.  
```  

***  

[PathMakeUniqueName](libraries/shell32/PathMakeUniqueName.md)  
```txt  
Creates a unique path name from a template.  
```  

***  

[PathYetAnotherMakeUniqueName](libraries/shell32/PathYetAnotherMakeUniqueName.md)  
```txt  
Creates a unique filename based on an existing filename.  
```  

***  

[RealDriveType](libraries/shell32/RealDriveType.md)  
```txt  
Determines the drive type based on the drive number.  
```  

***  

[RestartDialog](libraries/shell32/RestartDialog.md)  
```txt  
Displays a dialog box that prompts the user to restart Microsoft® Windows®. When the user clicks the button, the function calls ExitWindowsEx to attempt to restart Windows.  
```  

***  

[SHAddToRecentDocs](libraries/shell32/SHAddToRecentDocs.md)  
```txt  
Adds a document to the Shell"s list of recently used documents or clears all documents from the list.  
```  

***  

[SHBrowseForFolder](libraries/shell32/SHBrowseForFolder.md)  
```txt  
Displays a dialog box that enables the user to select a Shell folder.   
```  

***  

[SHCreateDirectory](libraries/shell32/SHCreateDirectory.md)  
```txt  
Creates a folder.  
```  

***  

[SHEmptyRecycleBin](libraries/shell32/SHEmptyRecycleBin.md)  
```txt  
Empties the Recycle Bin on the specified drive.   
```  

***  

[SHFileOperation](libraries/shell32/SHFileOperation.md)  
```txt  
Copies, moves, renames, or deletes a file system object.  
```  

***  

[SHFormatDrive](libraries/shell32/SHFormatDrive.md)  
```txt  
The SHFormatDrive API provides access to the Shell"s format dialog box. This allows applications that want to format disks to bring up the same dialog box that the Shell uses for disk formatting.
  
```  

***  

[SHGetFileInfo](libraries/shell32/SHGetFileInfo.md)  
```txt  
Retrieves information about an object in the file system, such as a file, a folder, a directory, or a drive root.
  
```  

***  

[SHGetFolderPath](libraries/shell32/SHGetFolderPath.md)  
```txt  
Takes the CSIDL of a folder and returns the pathname.  
```  

***  

[SHGetPathFromIDList](libraries/shell32/SHGetPathFromIDList.md)  
```txt  
Converts an item identifier list to a file system path.
  
```  

***  

[SHGetSpecialFolderLocation](libraries/shell32/SHGetSpecialFolderLocation.md)  
```txt  
Retrieves a pointer to the ITEMIDLIST structure of a special folder.  
```  

***  

[SHGetStockIconInfo](libraries/shell32/SHGetStockIconInfo.md)  
```txt  
Retrieves information about system-defined Shell icons.  
```  

***  

[SHParseDisplayName](libraries/shell32/SHParseDisplayName.md)  
```txt  
Translates a Shell namespace object"s display name into an item identifier list and returns the attributes of the object. This function is the preferred method to convert a string to a pointer to an item identifier list (PIDL).  
```  

***  

[SHQueryRecycleBin](libraries/shell32/SHQueryRecycleBin.md)  
```txt  
Retrieves the size of the Recycle Bin, and the number of items in it, on the specified drive.   
```  

***  

[SHSimpleIDListFromPath](libraries/shell32/SHSimpleIDListFromPath.md)  
```txt  
Returns a pointer to an ITEMIDLIST structure when passed a path.  
```  

***  

[ShellAbout](libraries/shell32/ShellAbout.md)  
```txt  
Displays a Shell About dialog box  
```  

***  

[ShellExecute](libraries/shell32/ShellExecute.md)  
```txt  
Performs an operation on a specified file.  
```  

***  

[ShellExecuteEx](libraries/shell32/ShellExecuteEx.md)  
```txt  
Performs an action on a file.  
```  

***  

[Shell_GetImageLists](libraries/shell32/Shell_GetImageLists.md)  
```txt  
Retrieves system image lists for large and small icons -- undocumented.  
```  

***  

[Shell_NotifyIcon](libraries/shell32/Shell_NotifyIcon.md)  
```txt  
Sends a message to the taskbar"s status area.  
```  

***  

[UnloadUserProfile](libraries/userenv/UnloadUserProfile.md)  
```txt  
Unloads a user"s profile that was loaded by the LoadUserProfile function.  
```  

***  

[WinHelp](libraries/user32/WinHelp.md)  
```txt  
The WinHelp function starts Windows Help (WINHELP.EXE) and passes additional data indicating the nature of the help requested by the application  
```  

***  


## @icon-book Shell Lightweight Utility APIs -- Path Functions group
***  

[PathBuildRoot](libraries/shlwapi/PathBuildRoot.md)  
```txt  
Creates a root path from a given drive number.  
```  

***  

[PathCombine](libraries/shlwapi/PathCombine.md)  
```txt  
Concatenates two strings that represent properly formed paths into one path; also concatenates any relative path elements.  
```  

***  

[PathCompactPathEx](libraries/shlwapi/PathCompactPathEx.md)  
```txt  
Truncates a path to fit within a certain number of characters by replacing path components with ellipses.  
```  

***  

[PathFileExists](libraries/shlwapi/PathFileExists.md)  
```txt  
Determines whether a path to a file system object such as a file or directory is valid.  
```  

***  

[PathFindExtension](libraries/shlwapi/PathFindExtension.md)  
```txt  
Searches a path for an extension.  
```  

***  

[PathFindFileName](libraries/shlwapi/PathFindFileName.md)  
```txt  
Searches a path for a file name.  
```  

***  

[PathFindOnPath](libraries/netapi32/PathFindOnPath.md)  
```txt  
Searches for a file.  
```  

***  

[PathGetDriveNumber](libraries/shlwapi/PathGetDriveNumber.md)  
```txt  
Searches a path for a drive letter within the range of "A" to "Z" and returns the corresponding drive number.  
```  

***  

[PathGetShortPath](libraries/shell32/PathGetShortPath.md)  
```txt  
Retrieves the short path form of a specified input path.
  
```  

***  

[PathIsDirectory](libraries/shlwapi/PathIsDirectory.md)  
```txt  
Verifies that a path is a valid directory.  
```  

***  

[PathIsNetworkPath](libraries/shlwapi/PathIsNetworkPath.md)  
```txt  
Determines whether a path string represents a network resource.  
```  

***  

[PathIsRelative](libraries/shlwapi/PathIsRelative.md)  
```txt  
Searches a path and determines if it is relative.  
```  

***  

[PathIsRoot](libraries/shlwapi/PathIsRoot.md)  
```txt  
Parses a path to determine if it is a directory root.  
```  

***  

[PathIsURL](libraries/shlwapi/PathIsURL.md)  
```txt  
Tests a given string to determine if it conforms to a valid URL format.  
```  

***  

[PathRenameExtension](libraries/shlwapi/PathRenameExtension.md)  
```txt  
Replaces the extension of a file name with a new extension.  
```  

***  

[PathSearchAndQualify](libraries/shlwapi/PathSearchAndQualify.md)  
```txt  
Determines if a given path is correctly formatted and fully qualified.  
```  

***  

[UrlEscape](libraries/shlwapi/UrlEscape.md)  
```txt  
Converts characters in a URL that might be altered during transport across the Internet ("unsafe" characters) into their corresponding escape sequences.  
```  

***  

[UrlGetPart](libraries/shlwapi/UrlGetPart.md)  
```txt  
Accepts a URL string and returns a specified part of that URL.  
```  

***  

[UrlHash](libraries/shlwapi/UrlHash.md)  
```txt  
Hashes a URL string.  
```  

***  

[UrlUnescape](libraries/shlwapi/UrlUnescape.md)  
```txt  
Converts escape sequences back into ordinary characters.  
```  

***  


## @icon-book Shell Lightweight Utility APIs -- misc. functions group
***  

[DllInstall](libraries/shlwapi/DllInstall.md)  
```txt  
Handles installation and setup for a dynamic-link library (DLL).   
```  

***  

[HashData](libraries/shlwapi/HashData.md)  
```txt  
Hashes an array of data.  
```  

***  


## @icon-book Shell Lightweight Utility APIs -- string functions group
***  

[ChrCmpI](libraries/shlwapi/ChrCmpI.md)  
```txt  
Performs a comparison between two characters. The comparison is not case sensitive.  
```  

***  

[StrCpy](libraries/shlwapi/StrCpy.md)  
```txt  
Copies one string to another.  
```  

***  

[StrDup](libraries/shlwapi/StrDup.md)  
```txt  
Duplicates a string.  
```  

***  

[wnsprintf](libraries/shlwapi/wnsprintf.md)  
```txt  
Takes a variable-length argument list and returns the values of the arguments as a printf-style formatted string.   
```  

***  


## @icon-book Simple MAPI group
***  

[MAPIAddress](libraries/mapi32/MAPIAddress.md)  
```txt  
The MAPIAddress function creates or modifies a set of address list entries.  
```  

***  

[MAPIFindNext](libraries/mapi32/MAPIFindNext.md)  
```txt  
The MAPIFindNext function retrieves the next (or first) message identifier of a specified type of incoming message.   
```  

***  

[MAPIFreeBuffer](libraries/mapi32/MAPIFreeBuffer.md)  
```txt  
The MAPIFreeBuffer function frees memory allocated by the messaging system.  
```  

***  

[MAPILogoff](libraries/mapi32/MAPILogoff.md)  
```txt  
The MAPILogoff function ends a session with the messaging system.  
```  

***  

[MAPILogon](libraries/mapi32/MAPILogon.md)  
```txt  
The MAPILogon function begins a Simple MAPI session, loading the default message store and address book providers.  
```  

***  

[MAPIReadMail](libraries/mapi32/MAPIReadMail.md)  
```txt  
The MAPIReadMail function retrieves a message for reading.   
```  

***  

[MAPIResolveName](libraries/mapi32/MAPIResolveName.md)  
```txt  
The MAPIResolveName function transforms a message recipient"s name as entered by a user to an unambiguous address list entry.  
```  

***  

[MAPISendDocuments](libraries/mapi32/MAPISendDocuments.md)  
```txt  
The MAPISendDocuments function sends a standard message with one or more attached files and a cover note.   
```  

***  

[MAPISendMail](libraries/mapi32/MAPISendMail.md)  
```txt  
The MAPISendMail function sends a message.   
```  

***  


## @icon-book String group
***  

[CharLower](libraries/user32/CharLower.md)  
```txt  
Converts a character string or a single character to lowercase. If the operand is a character string, the function converts the characters in place.  
```  

***  

[CharToOem](libraries/user32/CharToOem.md)  
```txt  
Translates a string into the OEM-defined character set.
  
```  

***  

[CharUpper](libraries/user32/CharUpper.md)  
```txt  
Converts a character string or a single character to uppercase. If the operand is a character string, the function converts the characters in place.  
```  

***  

[OemToChar](libraries/user32/OemToChar.md)  
```txt  
Translates a string from the OEM-defined character set into either an ANSI or a wide-character string.
  
```  

***  

[StrCmpC](libraries/shlwapi/StrCmpC.md)  
```txt  
Compares strings using C run-time (ASCII) collation rules. The comparison is case-sensitive.  
```  

***  

[StrFormatByteSize](libraries/shlwapi/StrFormatByteSize.md)  
```txt  
Converts a numeric value into a string that represents the number expressed as a size value in bytes, kilobytes, megabytes, or gigabytes, depending on the size.  
```  

***  

[StrFromTimeInterval](libraries/shlwapi/StrFromTimeInterval.md)  
```txt  
Converts a time interval, specified in milliseconds, to a string.  
```  

***  

[StrToInt](libraries/shlwapi/StrToInt.md)  
```txt  
Converts a decimal string to an integer. The StrToLong macro differs from this function in name only.  
```  

***  

[StrToIntEx](libraries/shlwapi/StrToIntEx.md)  
```txt  
Converts a decimal or hexadecimal string to an integer.  
```  

***  

[StrTrim](libraries/shlwapi/StrTrim.md)  
```txt  
Removes (trims) specified leading and trailing characters from a string.  
```  

***  


## @icon-book Synchronization group
***  

[CreateEvent](libraries/kernel32/CreateEvent.md)  
```txt  
The CreateEvent function creates or opens a named or unnamed event object.  
```  

***  

[CreateMutex](libraries/kernel32/CreateMutex.md)  
```txt  
Creates or opens a named or unnamed mutex object.  
```  

***  

[CreateSemaphore](libraries/kernel32/CreateSemaphore.md)  
```txt  
The CreateSemaphore function creates a named or unnamed semaphore object  
```  

***  

[CreateWaitableTimer](libraries/kernel32/CreateWaitableTimer.md)  
```txt  
Creates or opens a waitable timer object.  
```  

***  

[OpenEvent](libraries/kernel32/OpenEvent.md)  
```txt  
The OpenEvent function opens an existing named event object.  
```  

***  

[OpenSemaphore](libraries/kernel32/OpenSemaphore.md)  
```txt  
The OpenSemaphore function returns a handle of an existing named semaphore object  
```  

***  

[OpenWaitableTimer](libraries/kernel32/OpenWaitableTimer.md)  
```txt  
Opens an existing named waitable timer object.  
```  

***  

[ReleaseMutex](libraries/kernel32/ReleaseMutex.md)  
```txt  
Releases ownership of the specified mutex object.  
```  

***  

[ReleaseSemaphore](libraries/kernel32/ReleaseSemaphore.md)  
```txt  
The ReleaseSemaphore function increases the count of the specified semaphore object by a specified amount  
```  

***  

[ResetEvent](libraries/kernel32/ResetEvent.md)  
```txt  
The ResetEvent function sets the specified event object to the nonsignaled state.  
```  

***  

[SetEvent](libraries/kernel32/SetEvent.md)  
```txt  
The SetEvent function sets the specified event object to the signaled state.  
```  

***  

[SetWaitableTimer](libraries/kernel32/SetWaitableTimer.md)  
```txt  
Activates the specified waitable timer. When the due time arrives, the timer is signaled and the thread that set the timer calls the optional completion routine.  
```  

***  

[WaitForSingleObject](libraries/kernel32/WaitForSingleObject.md)  
```txt  
The WaitForSingleObject function returns when the specified object is in the signaled state or when the time-out interval elapses  
```  

***  


## @icon-book System Information group
***  

[ExpandEnvironmentStrings](libraries/kernel32/ExpandEnvironmentStrings.md)  
```txt  
Expands environment-variable strings and replaces them with their defined values.  
```  

***  

[GetComputerName](libraries/kernel32/GetComputerName.md)  
```txt  
Retrieves the computer name of the current system. This name is established at system startup, when it is initialized from the registry  
```  

***  

[GetComputerNameEx](libraries/kernel32/GetComputerNameEx.md)  
```txt  
The GetComputerNameEx function retrieves a NetBIOS or DNS name associated with the local computer. The names are established at system startup, when the system reads them from the registry.  
```  

***  

[GetComputerObjectName](libraries/secur32/GetComputerObjectName.md)  
```txt  
The GetComputerObjectName function retrieves the local computer"s name in a specified format.  
```  

***  

[GetCurrentHwProfile](libraries/advapi32/GetCurrentHwProfile.md)  
```txt  
Retrieves information about the current hardware profile for the local computer.  
```  

***  

[GetKeyboardType](libraries/user32/GetKeyboardType.md)  
```txt  
Retrieves information about the current keyboard.  
```  

***  

[GetNativeSystemInfo](libraries/kernel32/GetNativeSystemInfo.md)  
```txt  
Retrieves information about the current system to an application running under WOW64.   
```  

***  

[GetProductInfo](libraries/kernel32/GetProductInfo.md)  
```txt  
Retrieves the product type for the operating system on the local computer, and maps the type to the product types supported by the specified operating system.  
```  

***  

[GetSysColor](libraries/user32/GetSysColor.md)  
```txt  
Retrieves the current color of the specified display element. Display elements are the parts of a window and the Windows display that appear on the system display screen  
```  

***  

[GetSystemDirectory](libraries/kernel32/GetSystemDirectory.md)  
```txt  
The GetSystemDirectory function retrieves the path of the system directory. The system directory contains such files as dynamic-link libraries, drivers, and font files.
  
```  

***  

[GetSystemInfo](libraries/kernel32/GetSystemInfo.md)  
```txt  
Returns information about the current system.  
```  

***  

[GetSystemMetrics](libraries/user32/GetSystemMetrics.md)  
```txt  
Retrieves various system metrics (widths and heights of display elements) and system configuration settings.
  
```  

***  

[GetSystemRegistryQuota](libraries/kernel32/GetSystemRegistryQuota.md)  
```txt  
Retrieves the current size of the registry and the maximum size that the registry is allowed to attain on the system.  
```  

***  

[GetSystemWow64Directory](libraries/kernel32/GetSystemWow64Directory.md)  
```txt  
Retrieves the path of the system directory used by WOW64. This directory is not present on 32-bit Windows.  
```  

***  

[GetUserName](libraries/advapi32/GetUserName.md)  
```txt  
Retrieves the user name of the current thread. This is the name of the user currently logged onto the system.  
```  

***  

[GetUserNameEx](libraries/secur32/GetUserNameEx.md)  
```txt  
Retrieves the name of the user or other security principal associated with the calling thread. You can specify the format of the returned name.  
```  

***  

[GetVersion](libraries/kernel32/GetVersion.md)  
```txt  
The GetVersion function returns the current version number of Windows and information about the operating system platform  
```  

***  

[GetVersionEx](libraries/kernel32/GetVersionEx.md)  
```txt  
The GetVersionEx function obtains extended information about the version of the operating system that is currently running  
```  

***  

[GetWindowsDirectory](libraries/kernel32/GetWindowsDirectory.md)  
```txt  
The GetWindowsDirectory function retrieves the path of the Windows directory. The Windows directory contains such files as applications, initialization files, and help files.
  
```  

***  

[IsNetworkAlive](libraries/sensapi/IsNetworkAlive.md)  
```txt  
The IsNetworkAlive function determines whether the local system is connected to a network and the type of network connection. For example, whether the local system has connectivity to a LAN, WAN, or both networks.  
```  

***  

[SetComputerName](libraries/kernel32/SetComputerName.md)  
```txt  
The SetComputerName function stores a new NetBIOS name for the local computer. The name is stored in the registry and takes effect the next time the user restarts the computer.   
```  

***  

[SetSysColors](libraries/user32/SetSysColors.md)  
```txt  
Sets the colors for one or more display elements. Display elements are the various parts of a window and the Windows display that appear on the system display screen  
```  

***  

[SystemParametersInfo](libraries/user32/SystemParametersInfo.md)  
```txt  
The SystemParametersInfo function retrieves or sets the value of one of the system-wide parameters. This function can also update the user profile while setting a parameter.  
```  

***  


## @icon-book System Shutdown group
***  

[ExitWindows](libraries/user32/ExitWindows.md)  
```txt  
Logs the current user off  
```  

***  

[ExitWindowsEx](libraries/user32/ExitWindowsEx.md)  
```txt  
Either logs off, shuts down, or shuts down and restarts the system  
```  

***  

[InitiateShutdown](libraries/advapi32/InitiateShutdown.md)  
```txt  
Initiates a shutdown and restart of the specified computer, and restarts any applications that have been registered for restart.  
```  

***  

[InitiateSystemShutdown](libraries/advapi32/InitiateSystemShutdown.md)  
```txt  
Initiates a shutdown and optional restart of the specified computer.  
```  

***  

[LockWorkStation](libraries/user32/LockWorkStation.md)  
```txt  
The LockWorkStation function locks the workstation"s display, protecting it from unauthorized use.  
```  

***  


## @icon-book Terminal Services group
***  

[WTSCloseServer](libraries/wtsapi32/WTSCloseServer.md)  
```txt  
Closes an open handle to a terminal server.  
```  

***  

[WTSEnumerateProcesses](libraries/wtsapi32/WTSEnumerateProcesses.md)  
```txt  
Retrieves information about the active processes on a specified terminal server.  
```  

***  

[WTSEnumerateServers](libraries/wtsapi32/WTSEnumerateServers.md)  
```txt  
Returns a list of all terminal servers within the specified Windows NT domain.
  
```  

***  

[WTSEnumerateSessions](libraries/wtsapi32/WTSEnumerateSessions.md)  
```txt  
Retrieves a list of sessions on a specified terminal server.  
```  

***  

[WTSFreeMemory](libraries/wtsapi32/WTSFreeMemory.md)  
```txt  
Frees memory allocated by a Terminal Services function.
  
```  

***  

[WTSOpenServer](libraries/wtsapi32/WTSOpenServer.md)  
```txt  
Opens a handle to the specified terminal server.
  
```  

***  

[WTSQuerySessionInformation](libraries/wtsapi32/WTSQuerySessionInformation.md)  
```txt  
Retrieves session information for the specified session on the specified terminal server. It can be used to query session information on local and remote terminal servers.
  
```  

***  

[WTSRegisterSessionNotification](libraries/wtsapi32/WTSRegisterSessionNotification.md)  
```txt  
Registers the specified window to receive session change notifications.
  
```  

***  

[WTSSendMessage](libraries/wtsapi32/WTSSendMessage.md)  
```txt  
Displays a message box on the client desktop of a specified Terminal Services session.  
```  

***  

[WTSUnRegisterSessionNotification](libraries/wtsapi32/WTSUnRegisterSessionNotification.md)  
```txt  
Unregisters the specified window so that it receives no further session change notifications.  
```  

***  


## @icon-book Time group
***  

[CompareFileTime](libraries/kernel32/CompareFileTime.md)  
```txt  
The CompareFileTime function compares two file times.  
```  

***  

[FileTimeToLocalFileTime](libraries/kernel32/FileTimeToLocalFileTime.md)  
```txt  
The FileTimeToLocalFileTime function converts a file time to a local file time.  
```  

***  

[FileTimeToSystemTime](libraries/kernel32/FileTimeToSystemTime.md)  
```txt  
The FileTimeToSystemTime function converts a file time to system time format.  
```  

***  

[GetFileTime](libraries/kernel32/GetFileTime.md)  
```txt  
Retrieves the date and time that a file was created, last accessed, and last modified.  
```  

***  

[GetLocalTime](libraries/kernel32/GetLocalTime.md)  
```txt  
Retrieves the current local date and time.  
```  

***  

[GetSystemTime](libraries/kernel32/GetSystemTime.md)  
```txt  
Retrieves the current system date and time. The system time is expressed in Coordinated Universal Time (UTC).  
```  

***  

[GetSystemTimeAdjustment](libraries/kernel32/GetSystemTimeAdjustment.md)  
```txt  
Determines whether the system is applying periodic time adjustments to its time-of-day clock at each clock interrupt, along with the value and period of any such adjustments.  
```  

***  

[GetSystemTimeAsFileTime](libraries/kernel32/GetSystemTimeAsFileTime.md)  
```txt  
The GetSystemTimeAsFileTime function retrieves the current system date and time. The information is in Coordinated Universal Time (UTC) format.  
```  

***  

[GetTickCount](libraries/kernel32/GetTickCount.md)  
```txt  
Retrieves the number of milliseconds that have elapsed since the system was started.  
```  

***  

[GetTimeZoneInformation](libraries/kernel32/GetTimeZoneInformation.md)  
```txt  
Retrieves the current time-zone parameters. These parameters control the translations between Coordinated Universal Time (UTC) and local time.  
```  

***  

[LocalFileTimeToFileTime](libraries/kernel32/LocalFileTimeToFileTime.md)  
```txt  
Converts a local file time to a file time based on the Coordinated Universal Time (UTC).  
```  

***  

[QueryPerformanceCounter](libraries/kernel32/QueryPerformanceCounter.md)  
```txt  
The QueryPerformanceCounter function retrieves the current value of the high-resolution performance counter.  
```  

***  

[QueryPerformanceFrequency](libraries/kernel32/QueryPerformanceFrequency.md)  
```txt  
The QueryPerformanceFrequency function retrieves the frequency of the high-resolution performance counter, if one exists. The frequency cannot change while the system is running.  
```  

***  

[SetFileTime](libraries/kernel32/SetFileTime.md)  
```txt  
Sets the date and time that a file was created, last accessed, or last modified.  
```  

***  

[SetTimeZoneInformation](libraries/kernel32/SetTimeZoneInformation.md)  
```txt  
The SetTimeZoneInformation function sets the current time-zone parameters. These parameters control translations from Coordinated Universal Time (UTC) to local time.  
```  

***  

[SystemTimeToFileTime](libraries/kernel32/SystemTimeToFileTime.md)  
```txt  
The SystemTimeToFileTime function converts a system time to a file time.  
```  

***  


## @icon-book URL Monikers group
***  

[CreateURLMonikerEx](libraries/urlmon/CreateURLMonikerEx.md)  
```txt  
Creates a URL moniker from a full URL, or from a base context URL moniker and a partial URL.  
```  

***  

[FindMediaType](libraries/urlmon/FindMediaType.md)  
```txt  
Retrieves the 32-bit value assigned to the specified media type.  
```  

***  

[IsValidURL](libraries/urlmon/IsValidURL.md)  
```txt  
Determines if a specified string is a valid URL.  
```  

***  

[ObtainUserAgentString](libraries/urlmon/ObtainUserAgentString.md)  
```txt  
Retrieves the user agent string in use.  
```  

***  

[URLDownloadToCacheFile](libraries/urlmon/URLDownloadToCacheFile.md)  
```txt  
Downloads data into the Internet cache and returns the file name of the cache location for retrieving the bits.  
```  

***  

[URLDownloadToFile](libraries/urlmon/URLDownloadToFile.md)  
```txt  
Downloads bits from the Internet and saves them to a file.  
```  

***  

[UrlMkGetSessionOption](libraries/urlmon/UrlMkGetSessionOption.md)  
```txt  
Retrieves options for the current Internet session.  
```  

***  


## @icon-book Unicode and Character Set group
***  

[MultiByteToWideChar](libraries/kernel32/MultiByteToWideChar.md)  
```txt  
The MultiByteToWideChar function maps a character string to a wide-character (Unicode) string.  
```  

***  

[WideCharToMultiByte](libraries/kernel32/WideCharToMultiByte.md)  
```txt  
The WideCharToMultiByte function maps a wide-character string (Unicode) to a new character string.  
```  

***  


## @icon-book Version Information group
***  

[GetFileVersionInfo](libraries/version/GetFileVersionInfo.md)  
```txt  
Retrieves version information for the specified file.  
```  

***  

[GetFileVersionInfoSize](libraries/version/GetFileVersionInfoSize.md)  
```txt  
The GetFileVersionInfoSize function determines whether the operating system can retrieve version information for a specified file.  
```  

***  


## @icon-book Virtual Hard Disk (Win7) group
***  

[AttachVirtualDisk](libraries/virtdisk/AttachVirtualDisk.md)  
```txt  
Attaches a virtual hard disk (VHD) by locating an appropriate VHD provider to accomplish the attachment.  
```  

***  

[CreateVirtualDisk](libraries/virtdisk/CreateVirtualDisk.md)  
```txt  
Creates a virtual hard disk (VHD) image file, either using default parameters or using an existing virtual disk or physical disk.  
```  

***  

[DetachVirtualDisk](libraries/virtdisk/DetachVirtualDisk.md)  
```txt  
Detaches a virtual hard disk (VHD) by locating an appropriate VHD provider to accomplish the operation.  
```  

***  

[OpenVirtualDisk](libraries/virtdisk/OpenVirtualDisk.md)  
```txt  
Opens a virtual hard disk (VHD) for use.  
```  

***  


## @icon-book Window group
***  

[BringWindowToTop](libraries/user32/BringWindowToTop.md)  
```txt  
Brings the specified window to the top of the Z order. If the window is a top-level window, it is activated. If the window is a child window, the top-level parent window associated with the child window is activated.  
```  

***  

[CloseWindow](libraries/user32/CloseWindow.md)  
```txt  
The CloseWindow function minimizes (but does not destroy) the specified window.  
```  

***  

[CreateWindow](libraries/user32/CreateWindow.md)  
```txt  
The CreateWindow function creates an overlapped, pop-up, or child window.

To use extended window styles in addition to the styles supported by CreateWindow, use the CreateWindowEx function.  
```  

***  

[CreateWindowEx](libraries/user32/CreateWindowEx.md)  
```txt  
Creates an overlapped, pop-up, or child window with an extended window style; otherwise, this function is identical to the CreateWindow function  
```  

***  

[DestroyWindow](libraries/user32/DestroyWindow.md)  
```txt  
The DestroyWindow function destroys the specified window. The function sends WM_DESTROY and WM_NCDESTROY messages to the window to deactivate it and remove the keyboard focus from it.  
```  

***  

[EndTask](libraries/user32/EndTask.md)  
```txt  
The EndTask function is called to forcibly close a specified window.  
```  

***  

[FindWindow](libraries/user32/FindWindow.md)  
```txt  
Retrieves a handle to the top-level window whose class name and window name match the specified strings.  
```  

***  

[FindWindowEx](libraries/user32/FindWindowEx.md)  
```txt  
Retrieves a handle to a window whose class name and window name match the specified strings. The function searches child windows, beginning with the one following the specified child window.  
```  

***  

[GetAncestor](libraries/user32/GetAncestor.md)  
```txt  
The GetAncestor function retrieves the handle to the ancestor of the specified window.  
```  

***  

[GetClientRect](libraries/user32/GetClientRect.md)  
```txt  
Retrieves the coordinates of a window"s client area.  
```  

***  

[GetDesktopWindow](libraries/user32/GetDesktopWindow.md)  
```txt  
The GetDesktopWindow function returns the handle of the Windows desktop window. The desktop window covers the entire screen. The desktop window is the area on top of which all icons and other windows are painted  
```  

***  

[GetForegroundWindow](libraries/user32/GetForegroundWindow.md)  
```txt  
The GetForegroundWindow function returns a handle to the foreground window (the window with which the user is currently working). The system assigns a slightly higher priority to the thread that creates the foreground window than it does to other threads.  
```  

***  

[GetGUIThreadInfo](libraries/user32/GetGUIThreadInfo.md)  
```txt  
Retrieves information about the active window or a specified graphical user interface (GUI) thread.   
```  

***  

[GetParent](libraries/user32/GetParent.md)  
```txt  
The GetParent function retrieves a handle to the specified window"s parent or owner. To retrieve a handle to a specified ancestor, use the GetAncestor function.  
```  

***  

[GetShellWindow](libraries/user32/GetShellWindow.md)  
```txt  
The GetShellWindow function returns a handle to the Shell"s desktop window.  
```  

***  

[GetWindow](libraries/user32/GetWindow.md)  
```txt  
The GetWindow function retrieves the handle of a window that has the specified relationship to the specified window.  
```  

***  

[GetWindowInfo](libraries/user32/GetWindowInfo.md)  
```txt  
The GetWindowInfo function retrieves information about the specified window.  
```  

***  

[GetWindowPlacement](libraries/user32/GetWindowPlacement.md)  
```txt  
The GetWindowPlacement function retrieves the show state and the restored, minimized, and maximized positions of the specified window.   
```  

***  

[GetWindowRect](libraries/user32/GetWindowRect.md)  
```txt  
Retrieves the dimensions of the bounding rectangle of the specified window.
  
```  

***  

[GetWindowText](libraries/user32/GetWindowText.md)  
```txt  
The GetWindowText function copies the text of the specified window"s title bar (if it has one) into a buffer  
```  

***  

[GetWindowTextLength](libraries/user32/GetWindowTextLength.md)  
```txt  
The GetWindowTextLength function retrieves the length, in characters, of the specified window"s title bar text  
```  

***  

[GetWindowThreadProcessId](libraries/user32/GetWindowThreadProcessId.md)  
```txt  
Retrieves the identifier of the thread that created the specified window and, optionally, the identifier of the process that created the window.  
```  

***  

[InternalGetWindowText](libraries/user32/InternalGetWindowText.md)  
```txt  
This function is similar to the GetWindowText function. However, it obtains the window text directly from the window structure associated with the specified window"s handle and then always provides the text as a unicode string.   
```  

***  

[IsChild](libraries/user32/IsChild.md)  
```txt  
The IsChild function tests whether a window is a child window or descendant window of a specified parent window  
```  

***  

[IsIconic](libraries/user32/IsIconic.md)  
```txt  
The IsIconic function determines whether the specified window is minimized (iconic).  
```  

***  

[IsWindow](libraries/user32/IsWindow.md)  
```txt  
The IsWindow function determines whether the specified window handle identifies an existing window  
```  

***  

[IsWindowVisible](libraries/user32/IsWindowVisible.md)  
```txt  
The IsWindowVisible function retrieves the visibility state of the specified window  
```  

***  

[IsZoomed](libraries/user32/IsZoomed.md)  
```txt  
The IsZoomed function determines whether a window is maximized.   
```  

***  

[MoveWindow](libraries/user32/MoveWindow.md)  
```txt  
The MoveWindow function changes the position and dimensions of the specified window.  
```  

***  

[RealGetWindowClass](libraries/user32/RealGetWindowClass.md)  
```txt  
Retrieves a string that specifies the window type  
```  

***  

[SetForegroundWindow](libraries/user32/SetForegroundWindow.md)  
```txt  
The SetForegroundWindow function puts the thread that created the specified window into the foreground and activates the window. Keyboard input is directed to the window, and various visual cues are changed for the user  
```  

***  

[SetLayeredWindowAttributes](libraries/user32/SetLayeredWindowAttributes.md)  
```txt  
The SetLayeredWindowAttributes function sets the opacity and transparency color key of a layered window.  
```  

***  

[SetParent](libraries/user32/SetParent.md)  
```txt  
The SetParent function changes the parent window of the specified child window.  
```  

***  

[SetWindowPos](libraries/user32/SetWindowPos.md)  
```txt  
The SetWindowPos function changes the size, position, and Z order of a child, pop-up, or top-level window.  
```  

***  

[SetWindowText](libraries/user32/SetWindowText.md)  
```txt  
Changes the text of the specified window"s title bar (if it has one). If the specified window is a control, the text of the control is changed.  
```  

***  

[ShowWindow](libraries/user32/ShowWindow.md)  
```txt  
The ShowWindow function sets the show state for the specified window.  
```  

***  

[SwitchToThisWindow](libraries/user32/SwitchToThisWindow.md)  
```txt  
The function is called to switch focus to a specified window and bring it to the foreground.   
```  

***  


## @icon-book Window Class group
***  

[GetClassInfo](libraries/user32/GetClassInfo.md)  
```txt  
The GetClassInfo function retrieves information about a window class.   
```  

***  

[GetClassInfoEx](libraries/user32/GetClassInfoEx.md)  
```txt  
The GetClassInfoEx function retrieves information about a window class, including a handle to the small icon associated with the window class.  
```  

***  

[GetClassLong](libraries/user32/GetClassLong.md)  
```txt  
Retrieves the specified 32-bit (long) value from the WNDCLASSEX structure associated with the specified window.  
```  

***  

[GetClassName](libraries/user32/GetClassName.md)  
```txt  
The GetClassName function retrieves the name of the class to which the specified window belongs.  
```  

***  

[GetWindowLong](libraries/user32/GetWindowLong.md)  
```txt  
Retrieves information about the specified window. The function also retrieves the 32-bit (long) value at the specified offset into the extra window memory.  
```  

***  

[RegisterClassEx](libraries/user32/RegisterClassEx.md)  
```txt  
Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function.  
```  

***  

[SetWindowLong](libraries/user32/SetWindowLong.md)  
```txt  
Changes an attribute of the specified window. The function also sets the 32-bit (long) value at the specified offset into the extra window memory.  
```  

***  

[UnregisterClass](libraries/user32/UnregisterClass.md)  
```txt  
Unregisters a window class, freeing the memory required for the class.  
```  

***  


## @icon-book Window Procedure group
***  

[CallWindowProc](libraries/user32/CallWindowProc.md)  
```txt  
The CallWindowProc function passes message information to the specified window procedure.  
```  

***  

[DefWindowProc](libraries/user32/DefWindowProc.md)  
```txt  
The DefWindowProc function calls the default window procedure to provide default processing for any window messages that an application does not process. This function ensures that every message is processed. DefWindowProc is called with the same parameters received by the window procedure.   
```  

***  

[WindowProc](libraries/kernel32/WindowProc.md)  
```txt  
The WindowProc function is an application-defined function that processes messages sent to a window. The WNDPROC type defines a pointer to this callback function. WindowProc is a placeholder for the application-defined function name.  
```  

***  


## @icon-book Window Property group
***  

[GetProp](libraries/user32/GetProp.md)  
```txt  
Retrieves a data handle from the property list of the specified window. The character string identifies the handle to be retrieved. The string and handle must have been added to the property list by a previous call to the SetProp function.  
```  

***  

[RemoveProp](libraries/user32/RemoveProp.md)  
```txt  
The RemoveProp function removes an entry from the property list of the specified window. The specified character string identifies the entry to be removed.   
```  

***  

[SetProp](libraries/user32/SetProp.md)  
```txt  
Adds a new entry or changes an existing entry in the property list of the specified window.  
```  

***  


## @icon-book Window Station and Desktop group
***  

[CloseDesktop](libraries/user32/CloseDesktop.md)  
```txt  
Closes an open handle to a desktop object.  
```  

***  

[CreateDesktop](libraries/user32/CreateDesktop.md)  
```txt  
Creates a new desktop, associates it with the current window station of the calling process, and assigns it to the calling thread.  
```  

***  

[GetThreadDesktop](libraries/user32/GetThreadDesktop.md)  
```txt  
The GetThreadDesktop function retrieves a handle to the desktop associated with a specified thread.  
```  

***  

[OpenDesktop](libraries/user32/OpenDesktop.md)  
```txt  
The OpenDesktop function opens the specified desktop object.  
```  

***  

[OpenInputDesktop](libraries/user32/OpenInputDesktop.md)  
```txt  
Opens the desktop that receives user input.
  
```  

***  

[SetThreadDesktop](libraries/user32/SetThreadDesktop.md)  
```txt  
Assigns the specified desktop to the calling thread. All subsequent operations on the desktop use the access rights granted to hDesktop.  
```  

***  

[SwitchDesktop](libraries/user32/SwitchDesktop.md)  
```txt  
Makes a desktop visible and activates it. This enables the desktop to receive input from the user.  
```  

***  


## @icon-book Windows Controls group
***  

[ImageList_Add](libraries/comctl32/ImageList_Add.md)  
```txt  
Adds an image or images to an image list.  
```  

***  

[ImageList_Create](libraries/comctl32/ImageList_Create.md)  
```txt  
Creates a new image list.  
```  

***  

[ImageList_Destroy](libraries/comctl32/ImageList_Destroy.md)  
```txt  
Destroys an image list.  
```  

***  

[ImageList_GetIconSize](libraries/comctl32/ImageList_GetIconSize.md)  
```txt  
Retrieves the dimensions of images in an image list. All images in an image list have the same dimensions.  
```  

***  

[ImageList_GetImageCount](libraries/comctl32/ImageList_GetImageCount.md)  
```txt  
Retrieves the number of images in an image list.   
```  

***  

[ImageList_GetImageInfo](libraries/comctl32/ImageList_GetImageInfo.md)  
```txt  
Retrieves information about an image in the image list.   
```  

***  

[ImageList_Remove](libraries/comctl32/ImageList_Remove.md)  
```txt  
Removes an image from an image list.  
```  

***  

[InitCommonControlsEx](libraries/comctl32/InitCommonControlsEx.md)  
```txt  
Registers specific common control classes from the common control dynamic-link library (DLL).  
```  

***  


## @icon-book Windows Multimedia group
***  

[AVIFileExit](libraries/avifil32/AVIFileExit.md)  
```txt  
The AVIFileExit function exits the AVIFile library and decrements the reference count for the library.  
```  

***  

[AVIFileGetStream](libraries/avifil32/AVIFileGetStream.md)  
```txt  
The AVIFileGetStream function returns the address of a stream interface that is associated with a specified AVI file.  
```  

***  

[AVIFileInfo](libraries/avifil32/AVIFileInfo.md)  
```txt  
The AVIFileInfo function obtains information about an AVI file.  
```  

***  

[AVIFileInit](libraries/avifil32/AVIFileInit.md)  
```txt  
The AVIFileInit function initializes the AVIFile library.  
```  

***  

[AVIFileOpen](libraries/avifil32/AVIFileOpen.md)  
```txt  
The AVIFileOpen function opens an AVI file and returns the address of a file interface used to access it.  
```  

***  

[AVIFileRelease](libraries/avifil32/AVIFileRelease.md)  
```txt  
The AVIFileRelease function decrements the reference count of an AVI file interface handle and closes the file if the count reaches zero.  
```  

***  

[AVIFileWriteData](libraries/avifil32/AVIFileWriteData.md)  
```txt  
Writes supplementary data (other than normal header, format, and stream data) to the file.
  
```  

***  

[AVIStreamGetFrame](libraries/avifil32/AVIStreamGetFrame.md)  
```txt  
The AVIStreamGetFrame function returns the address of a decompressed video frame.  
```  

***  

[AVIStreamGetFrameClose](libraries/avifil32/AVIStreamGetFrameClose.md)  
```txt  
The AVIStreamGetFrameClose function releases resources used to decompress video frames.  
```  

***  

[AVIStreamGetFrameOpen](libraries/avifil32/AVIStreamGetFrameOpen.md)  
```txt  
The AVIStreamGetFrameOpen function prepares to decompress video frames from the specified video stream.  
```  

***  

[AVIStreamInfo](libraries/avifil32/AVIStreamInfo.md)  
```txt  
The AVIStreamInfo function obtains stream header information.  
```  

***  

[AVIStreamLength](libraries/avifil32/AVIStreamLength.md)  
```txt  
The AVIStreamLength function returns the length of the stream.  
```  

***  

[AVIStreamReadFormat](libraries/avifil32/AVIStreamReadFormat.md)  
```txt  
The AVIStreamReadFormat function reads the stream format data.  
```  

***  

[AVIStreamRelease](libraries/avifil32/AVIStreamRelease.md)  
```txt  
The AVIStreamRelease function decrements the reference count of an AVI stream interface handle, and closes the stream if the count reaches zero.  
```  

***  

[AVIStreamStart](libraries/avifil32/AVIStreamStart.md)  
```txt  
The AVIStreamStart function returns the starting sample number for the stream.  
```  

***  

[AVIStreamTimeToSample](libraries/avifil32/AVIStreamTimeToSample.md)  
```txt  
The AVIStreamTimeToSample function converts from milliseconds to samples.  
```  

***  

[DrawDibClose](libraries/msvfw32/DrawDibClose.md)  
```txt  
The DrawDibClose function closes a DrawDib DC and frees the resources DrawDib allocated for it.  
```  

***  

[DrawDibDraw](libraries/msvfw32/DrawDibDraw.md)  
```txt  
The DrawDibDraw function draws a DIB to the screen.  
```  

***  

[DrawDibOpen](libraries/msvfw32/DrawDibOpen.md)  
```txt  
The DrawDibOpen function opens the DrawDib library for use and creates a DrawDib DC for drawing.  
```  

***  

[PlaySound](libraries/winmm/PlaySound.md)  
```txt  
Plays a sound specified by the given file name, resource, or system event.  
```  

***  

[capCreateCaptureWindow](libraries/avicap32/capCreateCaptureWindow.md)  
```txt  
The capCreateCaptureWindow function creates a capture window.
  
```  

***  

[capGetDriverDescription](libraries/avicap32/capGetDriverDescription.md)  
```txt  
The capGetDriverDescription function retrieves the version description of the capture driver.
  
```  

***  

[mciGetDeviceID](libraries/winmm/mciGetDeviceID.md)  
```txt  
Retrieves the device identifier corresponding to the name of an open device.  
```  

***  

[mciGetErrorString](libraries/winmm/mciGetErrorString.md)  
```txt  
The mciGetErrorString function retrieves a string that describes the specified MCI error code.   
```  

***  

[mciSendCommand](libraries/winmm/mciSendCommand.md)  
```txt  
Sends a command message to the specified MCI device.  
```  

***  

[mciSendString](libraries/winmm/mciSendString.md)  
```txt  
The <b>mciSendString</b> function sends a command string to an MCI device. The device that the command is sent to is specified in the command string.   
```  

***  

[midiOutClose](libraries/winmm/midiOutClose.md)  
```txt  
Closes the specified MIDI output device.
  
```  

***  

[midiOutGetDevCaps](libraries/winmm/midiOutGetDevCaps.md)  
```txt  
Queries a specified MIDI output device to determine its capabilities.
  
```  

***  

[midiOutGetNumDevs](libraries/winmm/midiOutGetNumDevs.md)  
```txt  
Retrieves the number of MIDI output devices present in the system.  
```  

***  

[midiOutOpen](libraries/winmm/midiOutOpen.md)  
```txt  
Opens a MIDI output device for playback.
  
```  

***  

[midiOutReset](libraries/winmm/midiOutReset.md)  
```txt  
Turns off all notes on all MIDI channels for the specified MIDI output device.  
```  

***  

[midiOutShortMsg](libraries/winmm/midiOutShortMsg.md)  
```txt  
Sends a short MIDI message to the specified MIDI output device.  
```  

***  

[mixerClose](libraries/winmm/mixerClose.md)  
```txt  
The mixerClose function closes the specified mixer device.  
```  

***  

[mixerGetControlDetails](libraries/winmm/mixerGetControlDetails.md)  
```txt  
Retrieves details about a single control associated with an audio line.  
```  

***  

[mixerGetDevCaps](libraries/winmm/mixerGetDevCaps.md)  
```txt  
The mixerGetDevCaps function queries a specified mixer device to determine its capabilities.  
```  

***  

[mixerGetID](libraries/winmm/mixerGetID.md)  
```txt  
Retrieves the device identifier for a mixer device associated with a specified device handle.  
```  

***  

[mixerGetLineControls](libraries/winmm/mixerGetLineControls.md)  
```txt  
The mixerGetLineControls function retrieves one or more controls associated with an audio line.  
```  

***  

[mixerGetLineInfo](libraries/winmm/mixerGetLineInfo.md)  
```txt  
The mixerGetLineInfo function retrieves information about a specific line of a mixer device.  
```  

***  

[mixerGetNumDevs](libraries/winmm/mixerGetNumDevs.md)  
```txt  
The mixerGetNumDevs function retrieves the number of mixer devices present in the system.  
```  

***  

[mixerOpen](libraries/winmm/mixerOpen.md)  
```txt  
The mixerOpen function opens a specified mixer device and ensures that the device will not be removed until the application closes the handle.  
```  

***  

[mixerSetControlDetails](libraries/winmm/mixerSetControlDetails.md)  
```txt  
Sets properties of a single control associated with an audio line.  
```  

***  

[mmioAscend](libraries/winmm/mmioAscend.md)  
```txt  
The mmioAscend function ascends out of a chunk in a RIFF file descended into with the mmioDescend function or created with the mmioCreateChunk function.  
```  

***  

[mmioClose](libraries/winmm/mmioClose.md)  
```txt  
The mmioClose function closes a file that was opened by using the mmioOpen function.  
```  

***  

[mmioCreateChunk](libraries/winmm/mmioCreateChunk.md)  
```txt  
The mmioCreateChunk function creates a chunk in a RIFF file that was opened by using the mmioOpen function.  
```  

***  

[mmioDescend](libraries/winmm/mmioDescend.md)  
```txt  
The mmioDescend function descends into a chunk of a RIFF file that was opened by using the mmioOpen function. It can also search for a given chunk.  
```  

***  

[mmioFlush](libraries/winmm/mmioFlush.md)  
```txt  
The mmioFlush function writes the I/O buffer of a file to disk if the buffer has been written to.  
```  

***  

[mmioOpen](libraries/winmm/mmioOpen.md)  
```txt  
The mmioOpen function opens a file for unbuffered or buffered I/O. The file can be a standard file, a memory file, or an element of a custom storage system.  
```  

***  

[mmioRead](libraries/winmm/mmioRead.md)  
```txt  
The mmioRead function reads a specified number of bytes from a file opened by using the mmioOpen function.  
```  

***  

[mmioSeek](libraries/winmm/mmioSeek.md)  
```txt  
Changes the current file position in a file opened by using the mmioOpen function.   
```  

***  

[mmioWrite](libraries/winmm/mmioWrite.md)  
```txt  
Writes a specified number of bytes to a file opened by using the mmioOpen function.
  
```  

***  

[sndPlaySound](libraries/winmm/sndPlaySound.md)  
```txt  
The sndPlaySound function plays a waveform sound specified either by a filename or by an entry in the registry or the WIN.INI file.   
```  

***  

[timeGetDevCaps](libraries/winmm/timeGetDevCaps.md)  
```txt  
Queries the timer device to determine its resolution.  
```  

***  

[waveInAddBuffer](libraries/winmm/waveInAddBuffer.md)  
```txt  
The waveInAddBuffer function sends an input buffer to the given waveform-audio input device. When the buffer is filled, the application is notified.  
```  

***  

[waveInClose](libraries/winmm/waveInClose.md)  
```txt  
The waveInClose function closes the given waveform-audio input device.  
```  

***  

[waveInGetDevCaps](libraries/winmm/waveInGetDevCaps.md)  
```txt  
The waveInGetDevCaps function retrieves the capabilities of a given waveform-audio input device.  
```  

***  

[waveInGetErrorText](libraries/winmm/waveInGetErrorText.md)  
```txt  
The waveInGetErrorText function retrieves a textual description of the error identified by the given error number.  
```  

***  

[waveInGetNumDevs](libraries/winmm/waveInGetNumDevs.md)  
```txt  
The waveInGetNumDevs function returns the number of waveform-audio input devices present in the system.  
```  

***  

[waveInGetPosition](libraries/winmm/waveInGetPosition.md)  
```txt  
The waveInGetPosition function retrieves the current input position of the given waveform-audio input device.  
```  

***  

[waveInOpen](libraries/winmm/waveInOpen.md)  
```txt  
The waveInOpen function opens the given waveform-audio input device for recording.  
```  

***  

[waveInPrepareHeader](libraries/winmm/waveInPrepareHeader.md)  
```txt  
The waveInPrepareHeader function prepares a buffer for waveform-audio input.  
```  

***  

[waveInReset](libraries/winmm/waveInReset.md)  
```txt  
The waveInReset function stops input on the given waveform-audio input device and resets the current position to zero. All pending buffers are marked as done and returned to the application.  
```  

***  

[waveInStart](libraries/winmm/waveInStart.md)  
```txt  
The waveInStart function starts input on the given waveform-audio input device.  
```  

***  

[waveInStop](libraries/winmm/waveInStop.md)  
```txt  
The waveInStop function stops waveform-audio input.  
```  

***  

[waveInUnprepareHeader](libraries/winmm/waveInUnprepareHeader.md)  
```txt  
The waveInUnprepareHeader function cleans up the preparation performed by the waveInPrepareHeader function. This function must be called after the device driver fills a buffer and returns it to the application. You must call this function before freeing the buffer.  
```  

***  

[waveOutClose](libraries/winmm/waveOutClose.md)  
```txt  
The waveOutClose function closes the given waveform-audio output device.  
```  

***  

[waveOutGetDevCaps](libraries/winmm/waveOutGetDevCaps.md)  
```txt  
Retrieves the capabilities of a given waveform-audio output device.  
```  

***  

[waveOutGetErrorText](libraries/winmm/waveOutGetErrorText.md)  
```txt  
Retrieves a textual description of the error identified by the given error number.  
```  

***  

[waveOutGetNumDevs](libraries/winmm/waveOutGetNumDevs.md)  
```txt  
Retrieves the number of waveform-audio output devices present in the system.  
```  

***  

[waveOutGetPosition](libraries/winmm/waveOutGetPosition.md)  
```txt  
The waveOutGetPosition function retrieves the current playback position of the given waveform-audio output device.
  
```  

***  

[waveOutGetVolume](libraries/winmm/waveOutGetVolume.md)  
```txt  
The waveOutGetVolume function retrieves the current volume level of the specified waveform-audio output device.  
```  

***  

[waveOutOpen](libraries/winmm/waveOutOpen.md)  
```txt  
The waveOutOpen function opens the given waveform-audio output device for playback.  
```  

***  

[waveOutPrepareHeader](libraries/winmm/waveOutPrepareHeader.md)  
```txt  
The waveOutPrepareHeader function prepares a waveform-audio data block for playback with waveOutWrite function.  
```  

***  

[waveOutReset](libraries/winmm/waveOutReset.md)  
```txt  
The waveOutReset function stops playback on the given waveform-audio output device and resets the current position to zero. All pending playback buffers are marked as done and returned to the application.  
```  

***  

[waveOutSetVolume](libraries/winmm/waveOutSetVolume.md)  
```txt  
The waveOutSetVolume function sets the volume level of the specified waveform-audio output device.  
```  

***  

[waveOutUnprepareHeader](libraries/winmm/waveOutUnprepareHeader.md)  
```txt  
The waveOutUnprepareHeader function cleans up the preparation performed by the waveOutPrepareHeader function. This function must be called after the device driver is finished with a data block. You must call this function before freeing the buffer.  
```  

***  

[waveOutWrite](libraries/winmm/waveOutWrite.md)  
```txt  
The waveOutWrite function sends a data block to the given waveform-audio output device.  
```  

***  


## @icon-book Windows Networking group
***  

[NetGetJoinInformation](libraries/netapi32/NetGetJoinInformation.md)  
```txt  
The NetGetJoinInformation function retrieves join status information for the specified computer.  
```  

***  

[NetJoinDomain](libraries/netapi32/NetJoinDomain.md)  
```txt  
The NetJoinDomain function joins a computer to a workgroup or domain.
  
```  

***  

[NetUnjoinDomain](libraries/netapi32/NetUnjoinDomain.md)  
```txt  
The NetUnjoinDomain function unjoins a computer from a workgroup or a domain.
  
```  

***  

[WNetAddConnection](libraries/mpr/WNetAddConnection.md)  
```txt  
The WNetAddConnection function enables the calling application to connect a local device to a network resource.   
```  

***  

[WNetAddConnection2](libraries/mpr/WNetAddConnection2.md)  
```txt  
The WNetAddConnection2 function makes a connection to a network resource. The function can redirect a local device to the network resource.  
```  

***  

[WNetCancelConnection2](libraries/mpr/WNetCancelConnection2.md)  
```txt  
The WNetCancelConnection2 function cancels an existing network connection. You can also call the function to remove remembered network connections that are not currently connected.  
```  

***  

[WNetCloseEnum](libraries/mpr/WNetCloseEnum.md)  
```txt  
The WNetCloseEnum function ends a network resource enumeration started by a call to the WNetOpenEnum function.  
```  

***  

[WNetConnectionDialog](libraries/mpr/WNetConnectionDialog.md)  
```txt  
The WNetConnectionDialog function starts a general browsing dialog box for connecting to network resources. The function requires a handle to the owner window for the dialog box.  
```  

***  

[WNetConnectionDialog1](libraries/mpr/WNetConnectionDialog1.md)  
```txt  
Brings up a general browsing dialog for connecting to network resources.  
```  

***  

[WNetDisconnectDialog](libraries/mpr/WNetDisconnectDialog.md)  
```txt  
The WNetDisconnectDialog function starts a general browsing dialog box for disconnecting from network resources. The function requires a handle to the owner window for the dialog box.  
```  

***  

[WNetEnumResource](libraries/mpr/WNetEnumResource.md)  
```txt  
The WNetEnumResource function continues an enumeration of network resources that was started by a call to the WNetOpenEnum function.   
```  

***  

[WNetGetConnection](libraries/mpr/WNetGetConnection.md)  
```txt  
The WNetGetConnection function retrieves the name of the network resource associated with a local device.  
```  

***  

[WNetGetLastError](libraries/odbc32/WNetGetLastError.md)  
```txt  
The WNetGetLastError function retrieves the most recent extended error code set by a WNet function.   
```  

***  

[WNetGetNetworkInformation](libraries/mpr/WNetGetNetworkInformation.md)  
```txt  
The WNetGetNetworkInformation function returns extended information about a specific network provider whose name was returned by a previous network enumeration.  
```  

***  

[WNetGetProviderName](libraries/mpr/WNetGetProviderName.md)  
```txt  
The WNetGetProviderName function obtains the provider name for a specific type of network.   
```  

***  

[WNetGetUniversalName](libraries/mpr/WNetGetUniversalName.md)  
```txt  
The WNetGetUniversalName function takes a drive-based path for a network resource and returns an information structure that contains a more universal form of the name.   
```  

***  

[WNetGetUser](libraries/mpr/WNetGetUser.md)  
```txt  
The WNetGetUser function retrieves the current default user name, or the user name used to establish a network connection.   
```  

***  

[WNetOpenEnum](libraries/mpr/WNetOpenEnum.md)  
```txt  
The WNetOpenEnum function starts an enumeration of network resources or existing connections. You can continue the enumeration by calling the WNetEnumResource function.  
```  

***  


## @icon-book Windows Sockets 2 (Winsock) group
***  

[WSACleanup](libraries/ws2_32/WSACleanup.md)  
```txt  
The WSACleanup function terminates use of the Ws2_32.dll.  
```  

***  

[WSACloseEvent](libraries/ws2_32/WSACloseEvent.md)  
```txt  
The WSACloseEvent function closes an open event object handle.  
```  

***  

[WSAConnect](libraries/ws2_32/WSAConnect.md)  
```txt  
Establishes a connection to another socket application, exchanges connect data, and specifies required quality of service based on the specified FLOWSPEC structure.
  
```  

***  

[WSACreateEvent](libraries/ws2_32/WSACreateEvent.md)  
```txt  
The WSACreateEvent function creates a new event object.  
```  

***  

[WSAEnumProtocols](libraries/iphlpapi/WSAEnumProtocols.md)  
```txt  
The WSAEnumProtocols function retrieves information about available transport protocols.  
```  

***  

[WSAEventSelect](libraries/ws2_32/WSAEventSelect.md)  
```txt  
The WSAEventSelect function specifies an event object to be associated with the specified set of FD_XXX network events.  
```  

***  

[WSAGetLastError](libraries/ws2_32/WSAGetLastError.md)  
```txt  
The WSAGetLastError function returns the error status for the last operation that failed.  
```  

***  

[WSARecv](libraries/ws2_32/WSARecv.md)  
```txt  
Receives data from a connected socket.  
```  

***  

[WSASend](libraries/ws2_32/WSASend.md)  
```txt  
Sends data on a connected socket.  
```  

***  

[WSAStartup](libraries/ws2_32/WSAStartup.md)  
```txt  
The WSAStartup function initiates use of Ws2_32.dll by a process.  
```  

***  

[WSAWaitForMultipleEvents](libraries/ws2_32/WSAWaitForMultipleEvents.md)  
```txt  
The WSAWaitForMultipleEvents function returns either when one or all of the specified event objects are in the signaled state, or when the time-out interval expires.  
```  

***  

[accept](libraries/ws2_32/accept.md)  
```txt  
The accept function permits an incoming connection attempt on a socket.  
```  

***  

[bind](libraries/ws2_32/bind.md)  
```txt  
The bind function associates a local address (IP address and port) with a socket.  
```  

***  

[closesocket](libraries/ws2_32/closesocket.md)  
```txt  
The closesocket function closes an existing socket.  
```  

***  

[gethostbyaddr](libraries/ws2_32/gethostbyaddr.md)  
```txt  
The gethostbyaddr function retrieves the host information corresponding to a network address.  
```  

***  

[gethostbyname](libraries/ws2_32/gethostbyname.md)  
```txt  
The gethostbyname function retrieves host information corresponding to a host name from a host database.  
```  

***  

[gethostname](libraries/ws2_32/gethostname.md)  
```txt  
The gethostname function retrieves the standard host name for the local computer.  
```  

***  

[getnameinfo](libraries/ws2_32/getnameinfo.md)  
```txt  
Provides protocol-independent name resolution from an address to an ANSI host name and from a port number to the ANSI service name.  
```  

***  

[getprotobyname](libraries/iphlpapi/getprotobyname.md)  
```txt  
The getprotobyname function retrieves the protocol information corresponding to a protocol name.  
```  

***  

[getprotobynumber](libraries/ws2_32/getprotobynumber.md)  
```txt  
The getprotobynumber function retrieves protocol information corresponding to a protocol number.  
```  

***  

[getservbyname](libraries/ws2_32/getservbyname.md)  
```txt  
The getservbyname function retrieves service information corresponding to a service name and protocol.  
```  

***  

[getservbyport](libraries/ws2_32/getservbyport.md)  
```txt  
The getservbyport function retrieves service information corresponding to a port and protocol.  
```  

***  

[getsockopt](libraries/ws2_32/getsockopt.md)  
```txt  
The getsockopt function retrieves a socket option.  
```  

***  

[htonl](libraries/ws2_32/htonl.md)  
```txt  
The htonl function converts a u_long from host to TCP/IP network byte order (which is big endian).  
```  

***  

[htons](libraries/ws2_32/htons.md)  
```txt  
The htons function converts a u_short from host to TCP/IP network byte order (which is big-endian).  
```  

***  

[inet_addr](libraries/ws2_32/inet_addr.md)  
```txt  
The inet_addr function converts a string containing an (Ipv4) Internet Protocol dotted address into a proper address for the IN_ADDR structure.  
```  

***  

[inet_ntoa](libraries/ws2_32/inet_ntoa.md)  
```txt  
The inet_ntoa function converts an (Ipv4) Internet network address into a string in Internet standard dotted format.  
```  

***  

[listen](libraries/ws2_32/listen.md)  
```txt  
The listen function places a socket in a state in which it is listening for an incoming connection.  
```  

***  

[ntohl](libraries/ws2_32/ntohl.md)  
```txt  
The ntohl function converts a u_long from TCP/IP network order to host byte order (which is little-endian on Intel processors).  
```  

***  

[ntohs](libraries/ws2_32/ntohs.md)  
```txt  
The ntohs function converts a u_short from TCP/IP network byte order to host byte order (which is little-endian on Intel processors).  
```  

***  

[recv](libraries/ws2_32/recv.md)  
```txt  
The <Strong>recv</Strong> function receives data from a connected or bound socket.  
```  

***  

[recvfrom](libraries/ws2_32/recvfrom.md)  
```txt  
Receives a datagram and stores the source address.  
```  

***  

[send](libraries/ws2_32/send.md)  
```txt  
The <Strong>send</Strong> function sends data on a connected socket.
  
```  

***  

[sendto](libraries/ws2_32/sendto.md)  
```txt  
Sends data to a specific destination.  
```  

***  

[setsockopt](libraries/ws2_32/setsockopt.md)  
```txt  
The setsockopt function sets a socket option.  
```  

***  

[socket](libraries/ws2_32/socket.md)  
```txt  
The <B>socket</B> function creates a socket that is bound to a specific service provider.  
```  

***  

[ws_connect](libraries/ws2_32/ws_connect.md)  
```txt  
The <Strong>connect</Strong> function establishes a connection to a specified socket.
  
```  

***  

[ws_select](libraries/ws2_32/ws_select.md)  
```txt  
The <Strong>select</Strong> function determines the status of one or more sockets, waiting if necessary, to perform synchronous I/O.
  
```  

***  

