[<img src="images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# List of functions grouped by library name
<a name="advapi32" />

# ![](images/fox1.png) Library: advapi32
<details>

***  

[AdjustTokenPrivileges](libraries/advapi32/AdjustTokenPrivileges.md)  
Enables or disables privileges in the specified access token.  

***  

[ClearEventLog](libraries/advapi32/ClearEventLog.md)  
Clears the specified event log, and optionally saves the current copy of the log to a backup file.  

***  

[CloseEventLog](libraries/advapi32/CloseEventLog.md)  
Closes a read handle to the specified event log.  

***  

[CloseServiceHandle](libraries/advapi32/CloseServiceHandle.md)  
The CloseServiceHandle function closes a handle to a service control manager or service object.  

***  

[ControlService](libraries/advapi32/ControlService.md)  
The ControlService function sends a control code to a service.
  

***  

[ConvertSidToStringSid](libraries/advapi32/ConvertSidToStringSid.md)  
Converts a security identifier (SID) to a string format suitable for display, storage, or transmission.  

***  

[CreateProcessAsUser](libraries/advapi32/CreateProcessAsUser.md)  
The CreateProcessAsUser function creates a new process and its primary thread. The new process then runs the specified executable file. The CreateProcessAsUser function is similar to the CreateProcess function, except that the new process runs in the security context of the user represented by the hToken parameter.  

***  

[CreateProcessWithLogonW](libraries/advapi32/CreateProcessWithLogonW.md)  
The CreateProcessWithLogonW function creates a new process and its primary thread. The new process then runs the specified executable file in the security context of the specified credentials (user, domain, and password). It can optionally load the user profile for the specified user.  

***  

[CreateService](libraries/advapi32/CreateService.md)  
Creates a service object and adds it to the specified service control manager database.  

***  

[CryptAcquireContext](libraries/advapi32/CryptAcquireContext.md)  
The CryptAcquireContext function is used to acquire a handle to a particular key container within a particular cryptographic service provider (CSP). This returned handle is used in calls to CryptoAPI functions that use the selected CSP.  

***  

[CryptCreateHash](libraries/advapi32/CryptCreateHash.md)  
The CryptCreateHash function initiates the hashing of a stream of data. It creates and returns to the calling application a handle to a CSP hash object.  

***  

[CryptDecrypt](libraries/advapi32/CryptDecrypt.md)  
Decrypts data previously encrypted using the CryptEncrypt function.  

***  

[CryptDeriveKey](libraries/advapi32/CryptDeriveKey.md)  
Generates cryptographic session keys derived from a base data value.  

***  

[CryptDestroyHash](libraries/advapi32/CryptDestroyHash.md)  
The CryptDestroyHash function destroys the hash object referenced by the hHash parameter. After a hash object has been destroyed, it can no longer be used.  

***  

[CryptDestroyKey](libraries/advapi32/CryptDestroyKey.md)  
Releases the handle referenced by the hKey parameter. After a key handle has been released, it becomes invalid and cannot be used again.  

***  

[CryptEncrypt](libraries/advapi32/CryptEncrypt.md)  
Encrypts data. The algorithm used to encrypt the data is designated by the key held by the CSP module and is referenced by the hKey parameter.
  

***  

[CryptEnumProviders](libraries/advapi32/CryptEnumProviders.md)  
Retrieves the first or next available cryptographic service providers (CSPs). Used in a loop, this function can retrieve in sequence all of the CSPs available on a computer.  

***  

[CryptEnumProviderTypes](libraries/advapi32/CryptEnumProviderTypes.md)  
Retrieves the first or next types of cryptographic service provider (CSP) supported on the computer. Used in a loop, this function retrieves in sequence all of the CSP types available on a computer.
  

***  

[CryptExportKey](libraries/advapi32/CryptExportKey.md)  
Exports a cryptographic key or a key pair from a cryptographic service provider (CSP) in a secure manner.  

***  

[CryptGenKey](libraries/advapi32/CryptGenKey.md)  
Generates a random cryptographic session key or a public/private key pair. A handle to the key or key pair is returned in phKey. This handle can then be used as needed with any CryptoAPI function that requires a key handle.  

***  

[CryptGenRandom](libraries/advapi32/CryptGenRandom.md)  
Fills a buffer with cryptographically random bytes.  

***  

[CryptGetDefaultProvider](libraries/advapi32/CryptGetDefaultProvider.md)  
Finds the default cryptographic service provider (CSP) of a specified provider type. The CSP can be the default for either for the current user or for the computer (LocalMachine).   

***  

[CryptGetHashParam](libraries/advapi32/CryptGetHashParam.md)  
Retrieves data that governs the operations of a hash object. The actual hash value can be retrieved by using this function.
  

***  

[CryptGetKeyParam](libraries/advapi32/CryptGetKeyParam.md)  
Retrieves data that governs the operations of a key.  

***  

[CryptGetProvParam](libraries/advapi32/CryptGetProvParam.md)  
Retrieves parameters that govern the operations of a cryptographic service provider (CSP).  

***  

[CryptHashData](libraries/advapi32/CryptHashData.md)  
Adds data to a specified hash object. 
  

***  

[CryptImportKey](libraries/advapi32/CryptImportKey.md)  
Transfers a cryptographic key from a key BLOB into a cryptographic service provider (CSP).  

***  

[CryptReleaseContext](libraries/advapi32/CryptReleaseContext.md)  
The CryptReleaseContext function releases the handle of a cryptographic service provider (CSP) and a key container.  

***  

[DeleteService](libraries/advapi32/DeleteService.md)  
Marks the specified service for deletion from the service control manager database.  

***  

[DeregisterEventSource](libraries/advapi32/DeregisterEventSource.md)  
Closes a write handle to the specified event log.  

***  

[EnumServicesStatus](libraries/advapi32/EnumServicesStatus.md)  
The EnumServicesStatus function enumerates services in the specified service control manager database.  

***  

[GetAce](libraries/advapi32/GetAce.md)  
Obtains a pointer to an access control entry (ACE) in an access control list (ACL).
  

***  

[GetAclInformation](libraries/advapi32/GetAclInformation.md)  
Retrieves information about an access control list (ACL).
  

***  

[GetCurrentHwProfile](libraries/advapi32/GetCurrentHwProfile.md)  
Retrieves information about the current hardware profile for the local computer.  

***  

[GetEventLogInformation](libraries/advapi32/GetEventLogInformation.md)  
Retrieves information about the specified event log.  

***  

[GetFileSecurity](libraries/advapi32/GetFileSecurity.md)  
The GetFileSecurity function obtains specified information about the security of a file or directory.   

***  

[GetLengthSid](libraries/advapi32/GetLengthSid.md)  
The GetLengthSid function returns the length, in bytes, of a valid security identifier (SID).  

***  

[GetNamedSecurityInfo](libraries/advapi32/GetNamedSecurityInfo.md)  
The GetNamedSecurityInfo function retrieves a copy of the security descriptor for an object specified by name.  

***  

[GetNumberOfEventLogRecords](libraries/advapi32/GetNumberOfEventLogRecords.md)  
Retrieves the number of records in the specified event log.  

***  

[GetOldestEventLogRecord](libraries/advapi32/GetOldestEventLogRecord.md)  
Retrieves the absolute record number of the oldest record in the specified event log.  

***  

[GetSecurityDescriptorDacl](libraries/advapi32/GetSecurityDescriptorDacl.md)  
Retrieves a pointer to the discretionary access control list (DACL) in a specified security descriptor.  

***  

[GetSecurityDescriptorOwner](libraries/advapi32/GetSecurityDescriptorOwner.md)  
The GetSecurityDescriptorOwner function retrieves the owner information from a security descriptor.  

***  

[GetTokenInformation](libraries/advapi32/GetTokenInformation.md)  
Retrieves a specified type of information about an access token.  

***  

[GetUserName](libraries/advapi32/GetUserName.md)  
Retrieves the user name of the current thread. This is the name of the user currently logged onto the system.  

***  

[ImpersonateLoggedOnUser](libraries/advapi32/ImpersonateLoggedOnUser.md)  
The ImpersonateLoggedOnUser function lets the calling thread impersonate the security context of a logged-on user. The user is represented by a token handle.  

***  

[InitiateShutdown](libraries/advapi32/InitiateShutdown.md)  
Initiates a shutdown and restart of the specified computer, and restarts any applications that have been registered for restart.  

***  

[InitiateSystemShutdown](libraries/advapi32/InitiateSystemShutdown.md)  
Initiates a shutdown and optional restart of the specified computer.  

***  

[IsValidSid](libraries/advapi32/IsValidSid.md)  
The IsValidSid function validates a security identifier (SID) by verifying that the revision number is within a known range, and that the number of subauthorities is less than the maximum.  

***  

[IsWellKnownSid](libraries/advapi32/IsWellKnownSid.md)  
Compares a SID to a well known SID and returns TRUE if they match.
  

***  

[LockServiceDatabase](libraries/advapi32/LockServiceDatabase.md)  
The LockServiceDatabase function requests ownership of the service control manager database lock. Only one process can own the lock at any given time.
  

***  

[LogonUser](libraries/advapi32/LogonUser.md)  
The LogonUser function attempts to log a user on to the local computer. The local computer is the computer from which LogonUser was called. You cannot use LogonUser to log on to a remote computer.   

***  

[LookupAccountName](libraries/advapi32/LookupAccountName.md)  
Accepts the name of a system and an account as input. It retrieves a security identifier (SID) for the account and the name of the domain on which the account was found.
  

***  

[LookupAccountSid](libraries/advapi32/LookupAccountSid.md)  
The LookupAccountSid function accepts a security identifier (SID) as input. It retrieves the name of the account for this SID and the name of the first domain on which this SID is found.  

***  

[LookupPrivilegeDisplayName](libraries/advapi32/LookupPrivilegeDisplayName.md)  
Retrieves the display name that represents a specified privilege.  

***  

[LookupPrivilegeName](libraries/advapi32/LookupPrivilegeName.md)  
Retrieves the name that corresponds to the privilege represented on a specific system by a specified locally unique identifier (LUID).  

***  

[LookupPrivilegeValue](libraries/advapi32/LookupPrivilegeValue.md)  
Retrieves the locally unique identifier (LUID) used on a specified system to locally represent the specified privilege name.  

***  

[LsaClose](libraries/advapi32/LsaClose.md)  
The LsaClose function closes a handle to a Policy or TrustedDomain object.  

***  

[LsaFreeMemory](libraries/advapi32/LsaFreeMemory.md)  
The LsaFreeMemory function frees memory allocated for an output buffer by an LSA function call.  

***  

[LsaLookupSids](libraries/advapi32/LsaLookupSids.md)  
The LsaLookupSids function looks up the names that correspond to an array of SIDs.  

***  

[LsaOpenPolicy](libraries/advapi32/LsaOpenPolicy.md)  
The LsaOpenPolicy function opens a handle to the Policy object on a local or remote system.  

***  

[OpenEventLog](libraries/advapi32/OpenEventLog.md)  
Opens a handle to the specified event log.  

***  

[OpenProcessToken](libraries/advapi32/OpenProcessToken.md)  
Opens the access token associated with a process.  

***  

[OpenSCManager](libraries/advapi32/OpenSCManager.md)  
The OpenSCManager function establishes a connection to the service control manager on the specified computer and opens the specified service control manager database.
  

***  

[OpenService](libraries/advapi32/OpenService.md)  
The OpenService function opens an existing service.
  

***  

[ReadEventLog](libraries/advapi32/ReadEventLog.md)  
Reads a whole number of entries from the specified event log. The function can be used to read log entries in chronological or reverse chronological order.  

***  

[RegCloseKey](libraries/advapi32/RegCloseKey.md)  
The RegCloseKey function releases a handle to the specified registry key.  

***  

[RegCreateKeyEx](libraries/advapi32/RegCreateKeyEx.md)  
The RegCreateKeyEx function creates the specified registry key. If the key already exists, the function opens it.  

***  

[RegDeleteKey](libraries/advapi32/RegDeleteKey.md)  
The RegDeleteKey function deletes a subkey, including all of its values.  

***  

[RegDeleteValue](libraries/advapi32/RegDeleteValue.md)  
The RegDeleteValue function removes a named value from the specified registry key.  

***  

[RegEnumKey](libraries/advapi32/RegEnumKey.md)  
The RegEnumKey function enumerates subkeys of the specified open registry key. The function retrieves the name of one subkey each time it is called.  

***  

[RegEnumKeyEx](libraries/advapi32/RegEnumKeyEx.md)  
The RegEnumKeyEx function enumerates subkeys of the specified open registry key. The function retrieves information about one subkey each time it is called.  

***  

[RegEnumValue](libraries/advapi32/RegEnumValue.md)  
Enumerates the values for the specified open registry key.  

***  

[RegisterEventSource](libraries/advapi32/RegisterEventSource.md)  
Retrieves a registered handle to the specified event log.  

***  

[RegOpenKeyEx](libraries/advapi32/RegOpenKeyEx.md)  
The RegOpenKeyEx function opens the specified registry key.  

***  

[RegQueryInfoKey](libraries/advapi32/RegQueryInfoKey.md)  
The RegQueryInfoKey function retrieves information about the specified registry key.  

***  

[RegQueryValueEx](libraries/advapi32/RegQueryValueEx.md)  
Retrieves the type and data for a specified value name associated with an open registry key.  

***  

[RegSaveKey](libraries/advapi32/RegSaveKey.md)  
The RegSaveKey function saves the specified key and all of its subkeys and values to a new file.  

***  

[RegSetValueEx](libraries/advapi32/RegSetValueEx.md)  
The RegSetValueEx function sets the data and type of a specified value under a registry key.  

***  

[ReportEvent](libraries/advapi32/ReportEvent.md)  
Writes an entry at the end of the specified event log.  

***  

[RevertToSelf](libraries/advapi32/RevertToSelf.md)  
The RevertToSelf function terminates the impersonation of a client application.  

***  

[StartService](libraries/advapi32/StartService.md)  
The StartService function starts a service.
  

***  

[UnlockServiceDatabase](libraries/advapi32/UnlockServiceDatabase.md)  
The UnlockServiceDatabase function unlocks a service control manager database by releasing the specified lock.
  

***  

</details>
<a name="avicap32" />

# ![](images/fox1.png) Library: avicap32
<details>

***  

[capCreateCaptureWindow](libraries/avicap32/capCreateCaptureWindow.md)  
The capCreateCaptureWindow function creates a capture window.
  

***  

[capGetDriverDescription](libraries/avicap32/capGetDriverDescription.md)  
The capGetDriverDescription function retrieves the version description of the capture driver.
  

***  

</details>
<a name="avifil32" />

# ![](images/fox1.png) Library: avifil32
<details>

***  

[AVIFileExit](libraries/avifil32/AVIFileExit.md)  
The AVIFileExit function exits the AVIFile library and decrements the reference count for the library.  

***  

[AVIFileGetStream](libraries/avifil32/AVIFileGetStream.md)  
The AVIFileGetStream function returns the address of a stream interface that is associated with a specified AVI file.  

***  

[AVIFileInfo](libraries/avifil32/AVIFileInfo.md)  
The AVIFileInfo function obtains information about an AVI file.  

***  

[AVIFileInit](libraries/avifil32/AVIFileInit.md)  
The AVIFileInit function initializes the AVIFile library.  

***  

[AVIFileOpen](libraries/avifil32/AVIFileOpen.md)  
The AVIFileOpen function opens an AVI file and returns the address of a file interface used to access it.  

***  

[AVIFileRelease](libraries/avifil32/AVIFileRelease.md)  
The AVIFileRelease function decrements the reference count of an AVI file interface handle and closes the file if the count reaches zero.  

***  

[AVIFileWriteData](libraries/avifil32/AVIFileWriteData.md)  
Writes supplementary data (other than normal header, format, and stream data) to the file.
  

***  

[AVIStreamGetFrame](libraries/avifil32/AVIStreamGetFrame.md)  
The AVIStreamGetFrame function returns the address of a decompressed video frame.  

***  

[AVIStreamGetFrameClose](libraries/avifil32/AVIStreamGetFrameClose.md)  
The AVIStreamGetFrameClose function releases resources used to decompress video frames.  

***  

[AVIStreamGetFrameOpen](libraries/avifil32/AVIStreamGetFrameOpen.md)  
The AVIStreamGetFrameOpen function prepares to decompress video frames from the specified video stream.  

***  

[AVIStreamInfo](libraries/avifil32/AVIStreamInfo.md)  
The AVIStreamInfo function obtains stream header information.  

***  

[AVIStreamLength](libraries/avifil32/AVIStreamLength.md)  
The AVIStreamLength function returns the length of the stream.  

***  

[AVIStreamReadFormat](libraries/avifil32/AVIStreamReadFormat.md)  
The AVIStreamReadFormat function reads the stream format data.  

***  

[AVIStreamRelease](libraries/avifil32/AVIStreamRelease.md)  
The AVIStreamRelease function decrements the reference count of an AVI stream interface handle, and closes the stream if the count reaches zero.  

***  

[AVIStreamStart](libraries/avifil32/AVIStreamStart.md)  
The AVIStreamStart function returns the starting sample number for the stream.  

***  

[AVIStreamTimeToSample](libraries/avifil32/AVIStreamTimeToSample.md)  
The AVIStreamTimeToSample function converts from milliseconds to samples.  

***  

</details>
<a name="cfgmgr32" />

# ![](images/fox1.png) Library: cfgmgr32
<details>

***  

[CM_Connect_Machine](libraries/cfgmgr32/CM_Connect_Machine.md)  
Creates a connection to a remote machine  

***  

[CM_Disconnect_Machine](libraries/cfgmgr32/CM_Disconnect_Machine.md)  
Removes a connection to a remote machine established in a previous call to CM_Connect_Machine.  

***  

[CM_Get_Child_Ex](libraries/cfgmgr32/CM_Get_Child_Ex.md)  
The function is used to retrieve a device instance handle to the first child node of a specified device node, in a local or a remote machine"s device tree.
  

***  

[CM_Get_Sibling_Ex](libraries/cfgmgr32/CM_Get_Sibling_Ex.md)  
Obtains a device instance handle to the next sibling node of a specified device node, in a local or a remote machine"s device tree.  

***  

[CM_Locate_DevNode_Ex](libraries/cfgmgr32/CM_Locate_DevNode_Ex.md)  
Obtains a device instance handle to the device node that is associated with a specified device instance identifier, on a local machine or a remote machine.
  

***  

</details>
<a name="comctl32" />

# ![](images/fox1.png) Library: comctl32
<details>

***  

[ImageList_Add](libraries/comctl32/ImageList_Add.md)  
Adds an image or images to an image list.  

***  

[ImageList_Create](libraries/comctl32/ImageList_Create.md)  
Creates a new image list.  

***  

[ImageList_Destroy](libraries/comctl32/ImageList_Destroy.md)  
Destroys an image list.  

***  

[ImageList_GetIconSize](libraries/comctl32/ImageList_GetIconSize.md)  
Retrieves the dimensions of images in an image list. All images in an image list have the same dimensions.  

***  

[ImageList_GetImageCount](libraries/comctl32/ImageList_GetImageCount.md)  
Retrieves the number of images in an image list.   

***  

[ImageList_GetImageInfo](libraries/comctl32/ImageList_GetImageInfo.md)  
Retrieves information about an image in the image list.   

***  

[ImageList_Remove](libraries/comctl32/ImageList_Remove.md)  
Removes an image from an image list.  

***  

[InitCommonControlsEx](libraries/comctl32/InitCommonControlsEx.md)  
Registers specific common control classes from the common control dynamic-link library (DLL).  

***  

[TaskDialog](libraries/comctl32/TaskDialog.md)  
Creates, displays, and operates a task dialog.  

***  

</details>
<a name="comdlg32" />

# ![](images/fox1.png) Library: comdlg32
<details>

***  

[ChooseColor](libraries/comdlg32/ChooseColor.md)  
The ChooseColor function creates a Color dialog box that enables the user to select a color.  

***  

[ChooseFont](libraries/comdlg32/ChooseFont.md)  
Creates a Font dialog box that enables the user to choose attributes for a logical font. These attributes include a typeface name, style (bold, italic, or regular), point size, effects (underline, strikeout, and text color), and a script (or character set).  

***  

[CommDlgExtendedError](libraries/comdlg32/CommDlgExtendedError.md)  
The CommDlgExtendedError function returns a common dialog box error code. This code indicates the most recent error to occur during the execution of one of the common dialog box functions.   

***  

[FindText](libraries/comdlg32/FindText.md)  
Creates a system-defined modeless Find dialog box that lets the user specify a string to search for and options to use when searching for text in a document.  

***  

[GetFileTitle](libraries/comdlg32/GetFileTitle.md)  
Retrieves the name of the specified file.  

***  

[GetOpenFileName](libraries/comdlg32/GetOpenFileName.md)  
The GetOpenFileName function creates an Open dialog box that lets the user specify the drive, directory, and the name of a file or set of files to open.  

***  

[GetSaveFileName](libraries/comdlg32/GetSaveFileName.md)  
The GetSaveFileName function creates a Save dialog box that lets the user specify the drive, directory, and name of a file to save.  

***  

[PageSetupDlg](libraries/comdlg32/PageSetupDlg.md)  
The PageSetupDlg function creates a Page Setup dialog box that enables the user to specify the attributes of a printed page.  

***  

[PrintDlg](libraries/comdlg32/PrintDlg.md)  
Displays a Print dialog box. The Print dialog box enables the user to specify the properties of a particular print job.  

***  

[PrintDlgEx](libraries/comdlg32/PrintDlgEx.md)  
The PrintDlgEx function displays a Print property sheet that enables the user to specify the properties of a particular print job.  

***  

[TaskDialogIndirect](libraries/comdlg32/TaskDialogIndirect.md)  
Creates, displays, and operates a task dialog.  

***  

</details>
<a name="crypt32" />

# ![](images/fox1.png) Library: crypt32
<details>

***  

[CertCloseStore](libraries/crypt32/CertCloseStore.md)  
Closes a certificate store handle and reduces the reference count on the store.  

***  

[CertFindCertificateInStore](libraries/crypt32/CertFindCertificateInStore.md)  
Finds the first or next certificate context in a certificate store that matches a search criteria established by the dwFindType and its associated pvFindPara.  

***  

[CertFreeCertificateContext](libraries/crypt32/CertFreeCertificateContext.md)  
Frees a certificate context by decrementing its reference count.  

***  

[CertOpenSystemStore](libraries/crypt32/CertOpenSystemStore.md)  
This is a simplified function that opens the most common system certificate store.  

***  

[CryptBinaryToString](libraries/crypt32/CryptBinaryToString.md)  
Converts an array of bytes into a formatted string.  

***  

[CryptProtectData](libraries/crypt32/CryptProtectData.md)  
Performs encryption on the data in a DATA_BLOB structure. Scoped to local computer, or to user credentials.  

***  

[CryptStringToBinary](libraries/crypt32/CryptStringToBinary.md)  
Converts a formatted string into an array of bytes.  

***  

[CryptUnprotectData](libraries/crypt32/CryptUnprotectData.md)  
Decrypts and does an integrity check of the data in a DATA_BLOB structure. Scoped to local computer, or to user credentials.  

***  

</details>
<a name="dnsapi" />

# ![](images/fox1.png) Library: dnsapi
<details>

***  

[DnsValidateName](libraries/dnsapi/DnsValidateName.md)  
Validates the status of a specified DNS name.  

***  

</details>
<a name="dwmapi" />

# ![](images/fox1.png) Library: dwmapi
<details>

***  

[DwmExtendFrameIntoClientArea](libraries/dwmapi/DwmExtendFrameIntoClientArea.md)  
Extends the window frame behind the client area.  

***  

</details>
<a name="dxva2" />

# ![](images/fox1.png) Library: dxva2
<details>

***  

[DestroyPhysicalMonitors](libraries/dxva2/DestroyPhysicalMonitors.md)  
Closes an array of open monitor handles. That is one of a scary name for API function.  

***  

[GetMonitorBrightness](libraries/dxva2/GetMonitorBrightness.md)  
Retrieves the minimum, maximum, and current brightness settings for a monitor.  

***  

[GetMonitorCapabilities](libraries/dxva2/GetMonitorCapabilities.md)  
Retrieves the configuration capabilities of a monitor. Call this function to find out which high-level monitor configuration functions are supported by the monitor.  

***  

[GetMonitorContrast](libraries/dxva2/GetMonitorContrast.md)  
Retrieves the minimum, maximum, and current contrast settings for a monitor.  

***  

[GetNumberOfPhysicalMonitorsFromHMONITOR](libraries/dxva2/GetNumberOfPhysicalMonitorsFromHMONITOR.md)  
Retrieves the number of physical monitors associated with an HMONITOR monitor handle.  

***  

[GetPhysicalMonitorsFromHMONITOR](libraries/dxva2/GetPhysicalMonitorsFromHMONITOR.md)  
Retrieves the physical monitors associated with an HMONITOR monitor handle.  

***  

[SetMonitorBrightness](libraries/dxva2/SetMonitorBrightness.md)  
Sets a monitor"s brightness value.  

***  

[SetMonitorContrast](libraries/dxva2/SetMonitorContrast.md)  
Sets the contrast value for a monitor.   

***  

</details>
<a name="esent" />

# ![](images/fox1.png) Library: esent
<details>

***  

[JetAddColumn](libraries/esent/JetAddColumn.md)  
Adds a new column to an existing table in an ESE database.  

***  

[JetBeginSession](libraries/esent/JetBeginSession.md)  
Starts new ESE session and initializes and returns an ESE session handle   

***  

[JetBeginTransaction](libraries/esent/JetBeginTransaction.md)  
Causes a session to enter a transaction and create a new save point.  

***  

[JetCloseDatabase](libraries/esent/JetCloseDatabase.md)  
Closes a database file that was previously opened with JetOpenDatabase.
  

***  

[JetCloseTable](libraries/esent/JetCloseTable.md)  
Closes an open table in a database. The table is a temporary table or a normal table.
  

***  

[JetCommitTransaction](libraries/esent/JetCommitTransaction.md)  
Commits the changes made to the state of the database during the current save point and migrates them to the previous save point.  

***  

[JetCreateDatabase](libraries/esent/JetCreateDatabase.md)  
Creates and attaches a database file to be used with the ESE database engine.  

***  

[JetCreateInstance](libraries/esent/JetCreateInstance.md)  
Allocates a new instance of the database engine for use in a single process.  

***  

[JetCreateTable](libraries/esent/JetCreateTable.md)  
Creates an empty table in an ESE database.
  

***  

[JetDeleteTable](libraries/esent/JetDeleteTable.md)  
Deletes a table in an ESE database.
  

***  

[JetDetachDatabase](libraries/esent/JetDetachDatabase.md)  
Releases a database file that was previously attached to a database session.  

***  

[JetEndSession](libraries/esent/JetEndSession.md)  
Ends the session, and cleans up and deallocates any resources associated with the specified session.  

***  

[JetGetColumnInfo](libraries/esent/JetGetColumnInfo.md)  
Retrieves information about a column.
  

***  

[JetGotoBookmark](libraries/esent/JetGotoBookmark.md)  
Positions a cursor to an index entry for the record that is associated with the specified bookmark.  

***  

[JetInit](libraries/esent/JetInit.md)  
Puts the database engine into a state where it can support application use of database files.  

***  

[JetMove](libraries/esent/JetMove.md)  
Positions a cursor at the start or end of an index and traverses the entries in that index either forward or backward.  

***  

[JetOpenTable](libraries/esent/JetOpenTable.md)  
Opens a cursor on an existing table.
  

***  

[JetPrepareUpdate](libraries/esent/JetPrepareUpdate.md)  
This is the first operation in performing an update, for the purposes of inserting a new record or replacing an existing record with new values.  

***  

[JetRetrieveColumn](libraries/esent/JetRetrieveColumn.md)  
Retrieves a single column value from the current record.  

***  

[JetRollback](libraries/esent/JetRollback.md)  
Undoes the changes made to the state of the database and returns to the last save point.  

***  

[JetSetColumn](libraries/esent/JetSetColumn.md)  
Modifies a single column value in a modified record to be inserted or to update the current record.  

***  

[JetTerm](libraries/esent/JetTerm.md)  
Initiates the shutdown of an instance that has been initialized by JetInit.
  

***  

[JetUpdate](libraries/esent/JetUpdate.md)  
Performs an update operation including inserting a new row into a table or updating an existing row.
  

***  

</details>
<a name="gdi32" />

# ![](images/fox1.png) Library: gdi32
<details>

***  

[BeginPath](libraries/gdi32/BeginPath.md)  
The BeginPath function opens a path bracket in the specified device context.  

***  

[BitBlt](libraries/gdi32/BitBlt.md)  
The BitBlt function performs a bit-block transfer of the color data corresponding to a rectangle of pixels from the specified source device context into a destination device context.  

***  

[ClientToScreen](libraries/gdi32/ClientToScreen.md)  
Converts the client-area coordinates of a specified point to screen coordinates.  

***  

[CloseEnhMetaFile](libraries/gdi32/CloseEnhMetaFile.md)  
The CloseEnhMetaFile function closes an enhanced-metafile device context and returns a handle that identifies an enhanced-format metafile.  

***  

[CombineRgn](libraries/gdi32/CombineRgn.md)  
The CombineRgn function combines two regions and stores the result in a third region. The two regions are combined according to the specified mode.  

***  

[CreateCompatibleBitmap](libraries/gdi32/CreateCompatibleBitmap.md)  
Creates a bitmap compatible with the device that is associated with the specified device context.  

***  

[CreateCompatibleDC](libraries/gdi32/CreateCompatibleDC.md)  
Creates a memory device context (DC) compatible with the specified device.  

***  

[CreateDC](libraries/gdi32/CreateDC.md)  
The CreateDC function creates a device context (DC) for a device using the specified name.  

***  

[CreateDIBSection](libraries/gdi32/CreateDIBSection.md)  
Creates a DIB that applications can write to directly.  

***  

[CreateEllipticRgn](libraries/gdi32/CreateEllipticRgn.md)  
The CreateEllipticRgn function creates an elliptical region.  

***  

[CreateEnhMetaFile](libraries/gdi32/CreateEnhMetaFile.md)  
The CreateEnhMetaFile function creates a device context for an enhanced-format metafile. This device context can be used to store a device-independent picture.  

***  

[CreateFont](libraries/gdi32/CreateFont.md)  
Creates a logical font with the specified characteristics. The logical font can subsequently be selected as the font for any device.  

***  

[CreateRectRgn](libraries/gdi32/CreateRectRgn.md)  
Creates a rectangular region.  

***  

[CreateRoundRectRgn](libraries/gdi32/CreateRoundRectRgn.md)  
Creates a rectangular region with rounded corners.  

***  

[CreateSolidBrush](libraries/gdi32/CreateSolidBrush.md)  
The CreateSolidBrush function creates a logical brush that has the specified solid color.   

***  

[DeleteDC](libraries/gdi32/DeleteDC.md)  
Deletes the specified device context (DC).  

***  

[DeleteEnhMetaFile](libraries/gdi32/DeleteEnhMetaFile.md)  
The DeleteEnhMetaFile function deletes an enhanced-format metafile or an enhanced-format metafile handle.   

***  

[DeleteObject](libraries/gdi32/DeleteObject.md)  
Deletes a logical pen, brush, font, bitmap, region, or palette, freeing all system resources associated with the object. After the object is deleted, the specified handle is no longer valid.  

***  

[DPtoLP](libraries/gdi32/DPtoLP.md)  
Converts device coordinates into logical coordinates.  

***  

[EndDoc](libraries/gdi32/EndDoc.md)  
The EndDoc function ends a print job.  

***  

[EndPage](libraries/gdi32/EndPage.md)  
The EndPage function notifies the device that the application has finished writing to a page. This function is typically used to direct the device driver to advance to a new page.  

***  

[EndPath](libraries/gdi32/EndPath.md)  
The EndPath function closes a path bracket and selects the path defined by the bracket into the specified device context.  

***  

[Escape](libraries/gdi32/Escape.md)  
The Escape function enables applications to access capabilities of a particular device not directly available through GDI. Escape calls made by an application are translated and sent to the driver.   

***  

[FillRect](libraries/gdi32/FillRect.md)  
The FillRect function fills a rectangle by using the specified brush. This function includes the left and top borders, but excludes the right and bottom borders of the rectangle.   

***  

[FrameRgn](libraries/gdi32/FrameRgn.md)  
The FrameRgn function draws a border around the specified region by using the specified brush.  

***  

[GdiFlush](libraries/gdi32/GdiFlush.md)  
Flushes the calling thread`s current batch.  

***  

[GdiGetBatchLimit](libraries/gdi32/GdiGetBatchLimit.md)  
Returns the maximum number of function calls that can be accumulated in the calling thread`s current batch.   

***  

[GdiSetBatchLimit](libraries/gdi32/GdiSetBatchLimit.md)  
Sets the maximum number of function calls that can be accumulated in the calling thread`s current batch. The system flushes the current batch whenever this limit is exceeded.   

***  

[GetBkMode](libraries/gdi32/GetBkMode.md)  
Returns the current background mix mode for a specified device context. The background mix mode of a device context affects text, hatched brushes, and pen styles that are not solid lines.  

***  

[GetBoundsRect](libraries/gdi32/GetBoundsRect.md)  
The GetBoundsRect function obtains the current accumulated bounding rectangle for a specified device context. The system maintains an accumulated bounding rectangle for each application. An application can retrieve and set this rectangle.  

***  

[GetCharABCWidths](libraries/gdi32/GetCharABCWidths.md)  
Retrieves the widths, in logical units, of consecutive characters in a specified range from the current TrueType font. This function succeeds only with TrueType fonts.  

***  

[GetDeviceCaps](libraries/gdi32/GetDeviceCaps.md)  
The GetDeviceCaps function retrieves device-specific information for the specified device.  

***  

[GetDIBits](libraries/gdi32/GetDIBits.md)  
The GetDIBits function retrieves the bits of the specified compatible bitmap and copies them into a buffer as a DIB using the specified format.   

***  

[GetEnhMetaFile](libraries/gdi32/GetEnhMetaFile.md)  
The GetEnhMetaFile function creates a handle that identifies the enhanced-format metafile stored in the specified file.  

***  

[GetEnhMetaFileHeader](libraries/gdi32/GetEnhMetaFileHeader.md)  
The GetEnhMetaFileHeader function retrieves the record containing the header for the specified enhanced-format metafile.  

***  

[GetGraphicsMode](libraries/gdi32/GetGraphicsMode.md)  
Retrieves the current graphics mode for the specified device context.  

***  

[GetMapMode](libraries/gdi32/GetMapMode.md)  
Retrieves the current mapping mode.  

***  

[GetNearestColor](libraries/gdi32/GetNearestColor.md)  
The GetNearestColor function returns a color value identifying a color from the system palette that will be displayed when the specified color value is used  

***  

[GetObject](libraries/gdi32/GetObject.md)  
The GetObject function retrieves information for the specified graphics object.  

***  

[GetObjectType](libraries/gdi32/GetObjectType.md)  
The GetObjectType retrieves the type of the specified object.  

***  

[GetRegionData](libraries/gdi32/GetRegionData.md)  
Fills the specified buffer with data describing a region. This data includes the dimensions of the rectangles that make up the region.  

***  

[GetRgnBox](libraries/gdi32/GetRgnBox.md)  
Retrieves the bounding rectangle of the specified region.  

***  

[GetTextAlign](libraries/gdi32/GetTextAlign.md)  
The GetTextAlign function retrieves the text-alignment setting for the specified device context.  

***  

[GetTextCharacterExtra](libraries/gdi32/GetTextCharacterExtra.md)  
The GetTextCharacterExtra function retrieves the current intercharacter spacing for the specified device context.   

***  

[GetTextColor](libraries/gdi32/GetTextColor.md)  
The GetTextColor function retrieves the current text color for the specified device context.  

***  

[GetTextExtentPoint32](libraries/gdi32/GetTextExtentPoint32.md)  
The GetTextExtentPoint32 function computes the width and height of the specified string of text.  

***  

[GetTextFace](libraries/gdi32/GetTextFace.md)  
The GetTextFace function retrieves the typeface name of the font that is selected into the specified device context.   

***  

[GetTextMetrics](libraries/gdi32/GetTextMetrics.md)  
The GetTextMetrics function fills the specified buffer with the metrics for the currently selected font.   

***  

[GetWorldTransform](libraries/gdi32/GetWorldTransform.md)  
Retrieves the current world-space to page-space transformation.  

***  

[LPtoDP](libraries/gdi32/LPtoDP.md)  
Converts logical coordinates into device coordinates.   

***  

[PathToRegion](libraries/gdi32/PathToRegion.md)  
Creates a region from the path that is selected into the specified device context. The resulting region uses device coordinates.  

***  

[PlayEnhMetaFile](libraries/gdi32/PlayEnhMetaFile.md)  
The PlayEnhMetaFile function displays the picture stored in the specified enhanced-format metafile.  

***  

[Polygon](libraries/gdi32/Polygon.md)  
The Polygon function draws a polygon consisting of two or more vertices connected by straight lines. The polygon is outlined by using the current pen and filled by using the current brush and polygon fill mode.  

***  

[SelectObject](libraries/gdi32/SelectObject.md)  
Selects an object into the specified device context (DC). The new object replaces the previous object of the same type. 
  

***  

[SetBkColor](libraries/gdi32/SetBkColor.md)  
The SetBkColor function sets the current background color to the specified color value, or to the nearest physical color if the device cannot represent the specified color value.   

***  

[SetBkMode](libraries/gdi32/SetBkMode.md)  
Sets the background mix mode of the specified device context. The background mix mode is used with text, hatched brushes, and pen styles that are not solid lines.  

***  

[SetGraphicsMode](libraries/gdi32/SetGraphicsMode.md)  
Sets the graphics mode for the specified device context.  

***  

[SetMapMode](libraries/gdi32/SetMapMode.md)  
Sets the mapping mode of the specified device context.  

***  

[SetTextAlign](libraries/gdi32/SetTextAlign.md)  
The SetTextAlign function sets the text-alignment flags for the specified device context.   

***  

[SetTextCharacterExtra](libraries/gdi32/SetTextCharacterExtra.md)  
The SetTextCharacterExtra function sets the intercharacter spacing. Intercharacter spacing is added to each character, including break characters, when the system writes a line of text.   

***  

[SetTextColor](libraries/gdi32/SetTextColor.md)  
Sets the text color for the specified device context to the specified color.  

***  

[StartDoc](libraries/gdi32/StartDoc.md)  
The StartDoc function starts a print job.  

***  

[StartPage](libraries/gdi32/StartPage.md)  
The StartPage function prepares the printer driver to accept data.  

***  

[StretchBlt](libraries/gdi32/StretchBlt.md)  
Copies a bitmap from a source rectangle into a destination rectangle, stretching or compressing the bitmap to fit the dimensions of the destination rectangle, if necessary.  

***  

[StretchDIBits](libraries/gdi32/StretchDIBits.md)  
The StretchDIBits function copies the color data for a rectangle of pixels in a DIB to the specified destination rectangle.  

***  

[TextOut](libraries/gdi32/TextOut.md)  
Writes a character string at the specified location, using the currently selected font, background color, and text color. 
  

***  

</details>
<a name="gdiplus" />

# ![](images/fox1.png) Library: gdiplus
<details>

***  

[GdipBitmapGetPixel](libraries/gdiplus/GdipBitmapGetPixel.md)  
Gets the color value of an individual pixel.  

***  

[GdipBitmapSetPixel](libraries/gdiplus/GdipBitmapSetPixel.md)  
Sets the color value of an individual pixel.  

***  

[GdipBitmapSetResolution](libraries/gdiplus/GdipBitmapSetResolution.md)  
Sets the resolution of this Bitmap object.  

***  

[GdipCloneBitmapArea](libraries/gdiplus/GdipCloneBitmapArea.md)  
Creates a new Bitmap object by copying a portion of this bitmap.  

***  

[GdipCreateBitmapFromGdiDib](libraries/gdiplus/GdipCreateBitmapFromGdiDib.md)  
Creates a Bitmap object based on a BITMAPINFO structure and an array of pixel data.  

***  

[GdipCreateBitmapFromGraphics](libraries/gdiplus/GdipCreateBitmapFromGraphics.md)  
Creates a Bitmap object based on a Graphics object, a width, and a height.  

***  

[GdipCreateBitmapFromHBITMAP](libraries/gdiplus/GdipCreateBitmapFromHBITMAP.md)  
Creates a Bitmap object based on a handle to a Windows Microsoft&reg; Windows&reg; Graphics Device Interface (GDI) bitmap and a handle to a GDI palette.  

***  

[GdipCreateBitmapFromHICON](libraries/gdiplus/GdipCreateBitmapFromHICON.md)  
Creates a Bitmap object based on a handle to an icon.  

***  

[GdipCreateFont](libraries/gdiplus/GdipCreateFont.md)  
Creates a Font handle based on a FontFamily handle, a size, a font style, and a unit of measurement.  

***  

[GdipCreateFontFamilyFromName](libraries/gdiplus/GdipCreateFontFamilyFromName.md)  
Creates a FontFamily handle based on specified font family name.  

***  

[GdipCreateFromHDC](libraries/gdiplus/GdipCreateFromHDC.md)  
Returns handle to the Graphics object associated with the device context.  

***  

[GdipCreateFromHDC2](libraries/gdiplus/GdipCreateFromHDC2.md)  
Returns handle to the Graphics object that is associated with a specified device context and a specified device.

  

***  

[GdipCreateFromHWND](libraries/gdiplus/GdipCreateFromHWND.md)  
Returns handle to the Graphics object associated with the windows handle.  

***  

[GdipCreateHBITMAPFromBitmap](libraries/gdiplus/GdipCreateHBITMAPFromBitmap.md)  
Creates a Microsoft&reg; Windows&reg; Graphics Device Interface (GDI) bitmap from this GDI+ Bitmap handle.
  

***  

[GdipCreateHICONFromBitmap](libraries/gdiplus/GdipCreateHICONFromBitmap.md)  
Creates an icon from this Bitmap object.  

***  

[GdipCreateImageAttributes](libraries/gdiplus/GdipCreateImageAttributes.md)  
Creates new ImageAttributes object.  

***  

[GdipCreateMatrix](libraries/gdiplus/GdipCreateMatrix.md)  
Creates and initializes a Matrix object that represents the identity matrix.  

***  

[GdipCreateMatrix2](libraries/gdiplus/GdipCreateMatrix2.md)  
Creates and initializes a 3x3 matrix that represents an affine transformation.  

***  

[GdipCreatePathGradientI](libraries/gdiplus/GdipCreatePathGradientI.md)  
Creates a PathGradient Brush object based on an array of points. Initializes the wrap mode of the path gradient brush.  

***  

[GdipCreatePen1](libraries/gdiplus/GdipCreatePen1.md)  
Creates a Pen object that uses a specified color and width.  

***  

[GdipCreateSolidFill](libraries/gdiplus/GdipCreateSolidFill.md)  
Creates a SolidBrush object based on a color.  

***  

[GdipCreateStringFormat](libraries/gdiplus/GdipCreateStringFormat.md)  
Creates a StringFormat object based on string format flags and a language.  

***  

[GdipCreateTexture](libraries/gdiplus/GdipCreateTexture.md)  
Creates a brush that contains an Image object that is used for the fill.  

***  

[GdipDeleteBrush](libraries/gdiplus/GdipDeleteBrush.md)  
Deletes the specified Brush object.  

***  

[GdipDeleteFont](libraries/gdiplus/GdipDeleteFont.md)  
Deletes the specified Font object.  

***  

[GdipDeleteFontFamily](libraries/gdiplus/GdipDeleteFontFamily.md)  
Deletes the specified FontFamily object.  

***  

[GdipDeleteGraphics](libraries/gdiplus/GdipDeleteGraphics.md)  
Deletes the Graphics object created by GdipCreateFromHWND, GdipCreateFromHDC or GdipCreateFromHDC2 function.  

***  

[GdipDeleteMatrix](libraries/gdiplus/GdipDeleteMatrix.md)  
Deletes the Matrix object created by GdipCreateMatrix, GdipCloneMatrix and similar functions.  

***  

[GdipDeletePen](libraries/gdiplus/GdipDeletePen.md)  
Deletes the specified Pen object.  

***  

[GdipDeleteStringFormat](libraries/gdiplus/GdipDeleteStringFormat.md)  
Deletes the specified StringFormat object .  

***  

[GdipDisposeImage](libraries/gdiplus/GdipDisposeImage.md)  
The GdipDisposeImage releases an Image object.  

***  

[GdipDisposeImageAttributes](libraries/gdiplus/GdipDisposeImageAttributes.md)  
Disposes the ImageAttributes object created by GdipCreateImageAttributes function.  

***  

[GdipDrawImageI](libraries/gdiplus/GdipDrawImageI.md)  
Draws an image at a specified location.  

***  

[GdipDrawImageRectI](libraries/gdiplus/GdipDrawImageRectI.md)  
Draws an image  

***  

[GdipDrawImageRectRectI](libraries/gdiplus/GdipDrawImageRectRectI.md)  
Draws an image optionally using a ImageAttributes object.  

***  

[GdipDrawLineI](libraries/gdiplus/GdipDrawLineI.md)  
Uses a pen to draw a line.  

***  

[GdipDrawPieI](libraries/gdiplus/GdipDrawPieI.md)  
Draws a pie.
  

***  

[GdipDrawRectangle](libraries/gdiplus/GdipDrawRectangle.md)  
Uses a pen to draw a rectangle.  

***  

[GdipDrawString](libraries/gdiplus/GdipDrawString.md)  
Draws a string based on a font, a layout rectangle, and a format  

***  

[GdipFillPieI](libraries/gdiplus/GdipFillPieI.md)  
Uses a brush to fill the interior of a pie.  

***  

[GdipFillRectangle](libraries/gdiplus/GdipFillRectangle.md)  
Uses a brush to fill the interior of a rectangle.  

***  

[GdipGetDC](libraries/gdiplus/GdipGetDC.md)  
Gets a handle to the device context associated with this Graphics object.
  

***  

[GdipGetDpiX](libraries/gdiplus/GdipGetDpiX.md)  
Gets the horizontal resolution, in dots per inch, of the display device associated with this Graphics handle.  

***  

[GdipGetDpiY](libraries/gdiplus/GdipGetDpiY.md)  
Gets the vertical resolution, in dots per inch, of the display device associated with this Graphics handle.  

***  

[GdipGetFamilyName](libraries/gdiplus/GdipGetFamilyName.md)  
Gets the name of this font family.  

***  

[GdipGetFontCollectionFamilyCount](libraries/gdiplus/GdipGetFontCollectionFamilyCount.md)  
Gets the number of font families contained in this font collection  

***  

[GdipGetFontCollectionFamilyList](libraries/gdiplus/GdipGetFontCollectionFamilyList.md)  
Gets list of the font families contained in this font collection.  

***  

[GdipGetImageDecoders](libraries/gdiplus/GdipGetImageDecoders.md)  
The GetImageDecoders function gets an array of ImageCodecInfo objects that contain information about the available image decoders.  

***  

[GdipGetImageDecodersSize](libraries/gdiplus/GdipGetImageDecodersSize.md)  
The GetImageDecodersSize function gets the number of available image decoders and the total size of the array of ImageCodecInfo objects that is returned by the GetImageDecoders function.  

***  

[GdipGetImageEncoders](libraries/gdiplus/GdipGetImageEncoders.md)  
The GetImageEncoders function gets an array of ImageCodecInfo objects that contain information about the available image encoders.  

***  

[GdipGetImageEncodersSize](libraries/gdiplus/GdipGetImageEncodersSize.md)  
The GetImageEncodersSize function gets the number of available image encoders and the total size of the array of ImageCodecInfo objects that is returned by the GetImageEncoders function.  

***  

[GdipGetImageFlags](libraries/gdiplus/GdipGetImageFlags.md)  
Gets a set of flags that indicate certain attributes of this Image object.
  

***  

[GdipGetImageGraphicsContext](libraries/gdiplus/GdipGetImageGraphicsContext.md)  
Creates a Graphics object that is associated with an Image object.  

***  

[GdipGetImageHeight](libraries/gdiplus/GdipGetImageHeight.md)  
Gets the height, in pixels, of this image.  

***  

[GdipGetImageHorizontalResolution](libraries/gdiplus/GdipGetImageHorizontalResolution.md)  
Gets the horizontal resolution of this image.  

***  

[GdipGetImagePalette](libraries/gdiplus/GdipGetImagePalette.md)  
Gets the color palette of this Image object.  

***  

[GdipGetImagePaletteSize](libraries/gdiplus/GdipGetImagePaletteSize.md)  
Gets the size, in bytes, of the color palette of this Image object.
  

***  

[GdipGetImageRawFormat](libraries/gdiplus/GdipGetImageRawFormat.md)  
Gets a globally unique identifier (GUID) that identifies the format of this Image object.  

***  

[GdipGetImageType](libraries/gdiplus/GdipGetImageType.md)  
Gets the type (bitmap or metafile) of this Image object.
  

***  

[GdipGetImageVerticalResolution](libraries/gdiplus/GdipGetImageVerticalResolution.md)  
Sets the vertical resolution of this image.  

***  

[GdipGetImageWidth](libraries/gdiplus/GdipGetImageWidth.md)  
Gets the width, in pixels, of this image.  

***  

[GdipGetMatrixElements](libraries/gdiplus/GdipGetMatrixElements.md)  
Gets the elements of this matrix. The elements are placed in an array in the order m11, m12, m21, m22, m31, m32, where mij denotes the element in row i, column j.
  

***  

[GdipGetPageScale](libraries/gdiplus/GdipGetPageScale.md)  
Gets the scaling factor currently set for the page transformation of this Graphics handle.  

***  

[GdipGetPageUnit](libraries/gdiplus/GdipGetPageUnit.md)  
Returns an element of the Unit enumeration that indicates the unit of measure currently set for this Graphics handle.  

***  

[GdipGetPropertyCount](libraries/gdiplus/GdipGetPropertyCount.md)  
Gets the number of properties (pieces of metadata) stored in this Image object.   

***  

[GdipGetPropertyIdList](libraries/gdiplus/GdipGetPropertyIdList.md)  
Gets a list of the property identifiers used in the metadata of this Image object.  

***  

[GdipGetPropertyItem](libraries/gdiplus/GdipGetPropertyItem.md)  
Gets a specified property item (piece of metadata) from this Image object.  

***  

[GdipGetPropertyItemSize](libraries/gdiplus/GdipGetPropertyItemSize.md)  
Gets the size, in bytes, of a specified property item of this Image object.  

***  

[GdipGetSmoothingMode](libraries/gdiplus/GdipGetSmoothingMode.md)  
Determines whether smoothing (antialiasing) is applied to the Graphics object.  

***  

[GdipInvertMatrix](libraries/gdiplus/GdipInvertMatrix.md)  
For invertible matrix, replaces the elements of this matrix with the elements of its inverse.

  

***  

[GdipIsStyleAvailable](libraries/gdiplus/GdipIsStyleAvailable.md)  
Determines whether the specified style is available for this font family.  

***  

[GdipLoadImageFromFile](libraries/gdiplus/GdipLoadImageFromFile.md)  
Creates an Image object based on a file.  

***  

[GdiplusShutdown](libraries/gdiplus/GdiplusShutdown.md)  
The GdiplusShutdown function cleans up resources used by Microsoft&reg; Windows&reg; GDI+.  

***  

[GdiplusStartup](libraries/gdiplus/GdiplusStartup.md)  
The GdiplusStartup function initializes Microsoft&reg; Windows&reg; GDI+.  

***  

[GdipMeasureString](libraries/gdiplus/GdipMeasureString.md)  
Measures the extent of the string in the specified font, format, and layout rectangle.
  

***  

[GdipNewInstalledFontCollection](libraries/gdiplus/GdipNewInstalledFontCollection.md)  
Represents the fonts installed on the system  

***  

[GdipReleaseDC](libraries/gdiplus/GdipReleaseDC.md)  
Releases a device context handle obtained by a previous call to the GdipGetHDC with this Graphics handle.
  

***  

[GdipRemovePropertyItem](libraries/gdiplus/GdipRemovePropertyItem.md)  
Removes a property item (piece of metadata) from this Image object.  

***  

[GdipResetWorldTransform](libraries/gdiplus/GdipResetWorldTransform.md)  
Sets the world transformation matrix of this Graphics object to the identity matrix.  

***  

[GdipRotateMatrix](libraries/gdiplus/GdipRotateMatrix.md)  
Updates this matrix with the product of itself and a rotation matrix.
  

***  

[GdipRotateWorldTransform](libraries/gdiplus/GdipRotateWorldTransform.md)  
Updates the world transformation matrix of this Graphics object with the product of itself and a rotation matrix.
  

***  

[GdipSaveImageToFile](libraries/gdiplus/GdipSaveImageToFile.md)  
Saves this image to a file.  

***  

[GdipScaleMatrix](libraries/gdiplus/GdipScaleMatrix.md)  
Updates this matrix with the product of itself and a scaling matrix.  

***  

[GdipScaleTextureTransform](libraries/gdiplus/GdipScaleTextureTransform.md)  
Updates this texture brush"s current transformation matrix with the product of itself and a scaling matrix.  

***  

[GdipSetClipRectI](libraries/gdiplus/GdipSetClipRectI.md)  
Sets the clipping region of this Graphics object by a specified rectangle.  

***  

[GdipSetImageAttributesColorKeys](libraries/gdiplus/GdipSetImageAttributesColorKeys.md)  
Sets the color key (transparency range) for a specified ColorAdjustType.  

***  

[GdipSetImagePalette](libraries/gdiplus/GdipSetImagePalette.md)  
Sets the color palette of this Image object.
  

***  

[GdipSetMatrixElements](libraries/gdiplus/GdipSetMatrixElements.md)  
Sets the elements of this matrix.  

***  

[GdipSetPageScale](libraries/gdiplus/GdipSetPageScale.md)  
Sets the scaling factor for the page transformation of this Graphics handle.  

***  

[GdipSetPageUnit](libraries/gdiplus/GdipSetPageUnit.md)  
Sets the unit of measure for this Graphics handle.   

***  

[GdipSetPathGradientCenterColor](libraries/gdiplus/GdipSetPathGradientCenterColor.md)  
Sets the center color of this path gradient brush. The center color is the color that appears at the brush`s center point.  

***  

[GdipSetPathGradientCenterPointI](libraries/gdiplus/GdipSetPathGradientCenterPointI.md)  
Sets the center point of this path gradient brush.  

***  

[GdipSetPropertyItem](libraries/gdiplus/GdipSetPropertyItem.md)  
Sets a property item (piece of metadata) for this Image object.  

***  

[GdipSetSmoothingMode](libraries/gdiplus/GdipSetSmoothingMode.md)  
Sets the rendering quality of the Graphics object.  

***  

[GdipSetTextRenderingHint](libraries/gdiplus/GdipSetTextRenderingHint.md)  
Sets the text rendering mode of this Graphics object.  

***  

[GdipSetWorldTransform](libraries/gdiplus/GdipSetWorldTransform.md)  
Sets the world transformation of this Graphics object.
  

***  

[GdipShearMatrix](libraries/gdiplus/GdipShearMatrix.md)  
Updates this matrix with the product of itself and a shearing matrix.
  

***  

[GdipTranslateMatrix](libraries/gdiplus/GdipTranslateMatrix.md)  
Updates this matrix with the product of itself and a translation matrix.
  

***  

[GdipTranslateWorldTransform](libraries/gdiplus/GdipTranslateWorldTransform.md)  
Updates this Graphics object"s world transformation matrix with the product of itself and a translation matrix.  

***  

</details>
<a name="iphlpapi" />

# ![](images/fox1.png) Library: iphlpapi
<details>

***  

[GetAdaptersAddresses](libraries/iphlpapi/GetAdaptersAddresses.md)  
Retrieves the addresses associated with the adapters on the local computer.  

***  

[GetAdaptersInfo](libraries/iphlpapi/GetAdaptersInfo.md)  
The GetAdaptersInfo function retrieves adapter information for the local computer.  

***  

[GetBestInterface](libraries/iphlpapi/GetBestInterface.md)  
Retrieves the index of the interface that has the best route to the specified IPv4 address.  

***  

[GetBestRoute](libraries/iphlpapi/GetBestRoute.md)  
Retrieves the best route to the specified destination IP address.
  

***  

[GetIfEntry](libraries/iphlpapi/GetIfEntry.md)  
The GetIfEntry function retrieves information for the specified interface on the local computer.  

***  

[GetInterfaceInfo](libraries/iphlpapi/GetInterfaceInfo.md)  
The GetInterfaceInfo function obtains a list of the network interface adapters on the local system.  

***  

[GetIpAddrTable](libraries/iphlpapi/GetIpAddrTable.md)  
The GetIpAddrTable function retrieves the interface�to�IP address mapping table.  

***  

[GetIpNetTable](libraries/iphlpapi/GetIpNetTable.md)  
The GetIpNetTable function retrieves the IP-to-physical address mapping table.  

***  

[GetIpStatistics](libraries/iphlpapi/GetIpStatistics.md)  
The GetIpStatistics function retrieves the IP statistics for the current computer.  

***  

[GetNetworkParams](libraries/iphlpapi/GetNetworkParams.md)  
The GetNetworkParams function retrieves network parameters for the local computer.  

***  

[GetNumberOfInterfaces](libraries/iphlpapi/GetNumberOfInterfaces.md)  
Returns the number of network interfaces on the local computer, including the loopback interface.   

***  

[getprotobyname](libraries/iphlpapi/getprotobyname.md)  
The getprotobyname function retrieves the protocol information corresponding to a protocol name.  

***  

[GetRTTAndHopCount](libraries/iphlpapi/GetRTTAndHopCount.md)  
The GetRTTAndHopCount function determines the round-trip time (RTT) and hop count to the specified destination.  

***  

[GetTcp6Table](libraries/iphlpapi/GetTcp6Table.md)  
Retrieves the TCP connection table for IPv6.  

***  

[GetTcpStatistics](libraries/iphlpapi/GetTcpStatistics.md)  
The GetTcpStatistics function retrieves the TCP statistics for the local computer.  

***  

[GetTcpTable](libraries/iphlpapi/GetTcpTable.md)  
The GetTcpTable function retrieves the TCP connection table.  

***  

[GetUdpTable](libraries/iphlpapi/GetUdpTable.md)  
The GetUdpTable function retrieves the User Datagram Protocol (UDP) listener table.  

***  

[IcmpCloseHandle](libraries/iphlpapi/IcmpCloseHandle.md)  
Closes a handle opened by a call to IcmpCreateFile.  

***  

[IcmpCreateFile](libraries/iphlpapi/IcmpCreateFile.md)  
Opens a handle on which ICMP Echo Requests can be issued.
  

***  

[IcmpSendEcho](libraries/iphlpapi/IcmpSendEcho.md)  
Sends an ICMP Echo request and returns any replies. The call returns when the time-out has expired or the reply buffer is filled.  

***  

[if_indextoname](libraries/iphlpapi/if_indextoname.md)  
Converts the local index for a network interface to the ANSI interface name.  

***  

[if_nametoindex](libraries/iphlpapi/if_nametoindex.md)  
Converts the ANSI interface name for a network interface to the local index for the interface.  

***  

[IpReleaseAddress](libraries/iphlpapi/IpReleaseAddress.md)  
The IpReleaseAddress function releases an IP address previously obtained through Dynamic Host Configuration Protocol (DHCP).  

***  

[IpRenewAddress](libraries/iphlpapi/IpRenewAddress.md)  
The IpRenewAddress function renews a lease on an IP address previously obtained through Dynamic Host Configuration Protocol (DHCP).  

***  

[SendARP](libraries/iphlpapi/SendARP.md)  
Sends an ARP request to obtain the physical address that corresponds to the specified destination IP address.  

***  

[WSAEnumProtocols](libraries/iphlpapi/WSAEnumProtocols.md)  
The WSAEnumProtocols function retrieves information about available transport protocols.  

***  

</details>
<a name="kernel32" />

# ![](images/fox1.png) Library: kernel32
<details>

***  

[AllocConsole](libraries/kernel32/AllocConsole.md)  
The AllocConsole function allocates a new console for the calling process.  

***  

[AssignProcessToJobObject](libraries/kernel32/AssignProcessToJobObject.md)  
Assigns a process to an existing job object.  

***  

[Beep](libraries/kernel32/Beep.md)  
Generates simple tones on the speaker. The function is synchronous; it does not return control to its caller until the sound finishes.  

***  

[BeginUpdateResource](libraries/kernel32/BeginUpdateResource.md)  
The BeginUpdateResource function returns a handle that can be used by the UpdateResource function to add, delete, or replace resources in an executable file.  

***  

[CloseHandle](libraries/kernel32/CloseHandle.md)  
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
  

***  

[CompareFileTime](libraries/kernel32/CompareFileTime.md)  
The CompareFileTime function compares two file times.  

***  

[CompareString](libraries/kernel32/CompareString.md)  
Compares two character strings, for a locale specified by identifier.  

***  

[ConnectNamedPipe](libraries/kernel32/ConnectNamedPipe.md)  
Enables a named pipe server process to wait for a client process to connect to an instance of a named pipe.   

***  

[CopyFile](libraries/kernel32/CopyFile.md)  
This function copies an existing file to a new file  

***  

[CopyFileTransacted](libraries/kernel32/CopyFileTransacted.md)  
Copies an existing file to a new file as a transacted operation, notifying the application of its progress through a callback function.  

***  

[CopyMemory](libraries/kernel32/CopyMemory.md)  


***  

[CreateDirectory](libraries/kernel32/CreateDirectory.md)  
Creates a new directory. If the underlying file system supports security on files and directories, the function applies a specified security descriptor to the new directory. 
  

***  

[CreateEvent](libraries/kernel32/CreateEvent.md)  
The CreateEvent function creates or opens a named or unnamed event object.  

***  

[CreateFile](libraries/kernel32/CreateFile.md)  
This function creates, opens, or truncates a file, communications resource, disk device, or console. It returns a handle that can be used to access the object. It can also open and return a handle to a directory.

Use the CloseHandle function to close an object handle returned by CreateFile  

***  

[CreateFileMapping](libraries/kernel32/CreateFileMapping.md)  
The CreateFileMapping function creates or opens a named or unnamed file mapping object for the specified file.  

***  

[CreateFileTransacted](libraries/kernel32/CreateFileTransacted.md)  
Creates or opens a file, file stream, or directory as a transacted operation. The function returns a handle that can be used to access the object.  

***  

[CreateHardLink](libraries/kernel32/CreateHardLink.md)  
Establishes a hard link between an existing file and a new file. This function is only supported on the NTFS file system.
  

***  

[CreateJobObject](libraries/kernel32/CreateJobObject.md)  
Creates or opens a job object.
  

***  

[CreateMailslot](libraries/kernel32/CreateMailslot.md)  
The CreateMailslot function creates a mailslot with the specified name and returns a handle that a mailslot server can use to perform operations on it.   

***  

[CreateMutex](libraries/kernel32/CreateMutex.md)  
Creates or opens a named or unnamed mutex object.  

***  

[CreateNamedPipe](libraries/kernel32/CreateNamedPipe.md)  
Creates an instance of a named pipe and returns a handle for subsequent pipe operations.   

***  

[CreatePipe](libraries/kernel32/CreatePipe.md)  
The CreatePipe function creates an anonymous pipe, and returns handles to the read and write ends of the pipe.
  

***  

[CreateProcess](libraries/kernel32/CreateProcess.md)  
The CreateProcess function creates a new process and its primary thread. The new process runs the specified executable file.

The CreateProcess function is used to run a new program. The WinExec and LoadModule functions are still available, but they are implemented as calls to CreateProcess  

***  

[CreateSemaphore](libraries/kernel32/CreateSemaphore.md)  
The CreateSemaphore function creates a named or unnamed semaphore object  

***  

[CreateSymbolicLink](libraries/kernel32/CreateSymbolicLink.md)  
Creates a symbolic link.  

***  

[CreateToolhelp32Snapshot](libraries/kernel32/CreateToolhelp32Snapshot.md)  
Takes a snapshot of the processes and the heaps, modules, and threads used by the processes.  

***  

[CreateWaitableTimer](libraries/kernel32/CreateWaitableTimer.md)  
Creates or opens a waitable timer object.  

***  

[DeleteFile](libraries/kernel32/DeleteFile.md)  
The DeleteFile function deletes an existing file  

***  

[DeleteFileTransacted](libraries/kernel32/DeleteFileTransacted.md)  
Deletes an existing file as a transacted operation.  

***  

[DeleteVolumeMountPoint](libraries/kernel32/DeleteVolumeMountPoint.md)  
Unmounts the volume from the specified volume mount point.  

***  

[DeviceIoControl](libraries/kernel32/DeviceIoControl.md)  
Sends a control code directly to a specified device driver, causing the corresponding device to perform the corresponding operation.  

***  

[DisconnectNamedPipe](libraries/kernel32/DisconnectNamedPipe.md)  
Disconnects the server end of a named pipe instance from a client process.  

***  

[DuplicateHandle](libraries/kernel32/DuplicateHandle.md)  
The DuplicateHandle function duplicates an object handle. 
  

***  

[EndUpdateResource](libraries/kernel32/EndUpdateResource.md)  
The EndUpdateResource function ends a resource update in an executable file.  

***  

[ExitProcess](libraries/kernel32/ExitProcess.md)  
The ExitProcess function ends a process and all its threads.  

***  

[ExpandEnvironmentStrings](libraries/kernel32/ExpandEnvironmentStrings.md)  
Expands environment-variable strings and replaces them with their defined values.  

***  

[FatalAppExit](libraries/kernel32/FatalAppExit.md)  
The FatalAppExit function displays a message box and terminates the application when the message box is closed.   

***  

[FileTimeToLocalFileTime](libraries/kernel32/FileTimeToLocalFileTime.md)  
The FileTimeToLocalFileTime function converts a file time to a local file time.  

***  

[FileTimeToSystemTime](libraries/kernel32/FileTimeToSystemTime.md)  
The FileTimeToSystemTime function converts a file time to system time format.  

***  

[FillConsoleOutputAttribute](libraries/kernel32/FillConsoleOutputAttribute.md)  
The FillConsoleOutputAttribute function sets the character attributes for a specified number of character cells, beginning at the specified coordinates in a screen buffer.  

***  

[FillConsoleOutputCharacter](libraries/kernel32/FillConsoleOutputCharacter.md)  
The FillConsoleOutputCharacter function writes a character to the console screen buffer a specified number of times, beginning at the specified coordinates.  

***  

[FillMemory](libraries/kernel32/FillMemory.md)  
The FillMemory function fills a block of memory with a specified value.  

***  

[FindClose](libraries/kernel32/FindClose.md)  
The FindClose function closes the specified search handle. The FindFirstFile and FindNextFile functions use the search handle to locate files with names that match a given name.  

***  

[FindCloseChangeNotification](libraries/kernel32/FindCloseChangeNotification.md)  
Stops change notification handle monitoring.  

***  

[FindFirstChangeNotification](libraries/kernel32/FindFirstChangeNotification.md)  
Creates a change notification handle and sets up initial change notification filter conditions. 

A wait on a notification handle succeeds when a change matching the filter conditions occurs in the specified directory or subtree. 
  

***  

[FindFirstFile](libraries/kernel32/FindFirstFile.md)  
The FindFirstFile function searches a directory for a file whose name matches the specified file name. FindFirstFile examines subdirectory names as well as file names.  

***  

[FindFirstVolume](libraries/kernel32/FindFirstVolume.md)  
Returns the name of a volume on a computer. This call is used to begin scanning the volumes of a computer.  

***  

[FindFirstVolumeMountPoint](libraries/kernel32/FindFirstVolumeMountPoint.md)  
Returns the name of a volume mount point on the specified volume. It is used to begin scanning the volume mount points on a volume.
  

***  

[FindNextChangeNotification](libraries/kernel32/FindNextChangeNotification.md)  
Requests that the operating system signal a change notification handle the next time it detects an appropriate change.  

***  

[FindNextFile](libraries/kernel32/FindNextFile.md)  
The FindNextFile function continues a file search from a previous call to the FindFirstFile function.  

***  

[FindNextVolume](libraries/kernel32/FindNextVolume.md)  
Continues a volume search started by a call to the FindFirstVolume function.  

***  

[FindNextVolumeMountPoint](libraries/kernel32/FindNextVolumeMountPoint.md)  
Continues a volume mount point search started by a call to the FindFirstVolumeMountPoint function.   

***  

[FindResource](libraries/kernel32/FindResource.md)  
The FindResource function determines the location of a resource with the specified type and name in the specified module.  

***  

[FindVolumeClose](libraries/kernel32/FindVolumeClose.md)  
Closes the specified volume search handle created with the FindFirstVolume and FindNextVolume call.  

***  

[FindVolumeMountPointClose](libraries/kernel32/FindVolumeMountPointClose.md)  
Closes the specified mount-point search handle.  

***  

[FlushFileBuffers](libraries/kernel32/FlushFileBuffers.md)  
Flushes the buffers of a specified file and causes all buffered data to be written to a file.  

***  

[FormatMessage](libraries/kernel32/FormatMessage.md)  
The FormatMessage function formats a message string. It can be used to obtain error message strings for the system error codes returned by GetLastError.  

***  

[FreeConsole](libraries/kernel32/FreeConsole.md)  
The FreeConsole function detaches the calling process from its console.  

***  

[FreeEnvironmentStrings](libraries/kernel32/FreeEnvironmentStrings.md)  
The FreeEnvironmentStrings function frees a block of environment strings.  

***  

[FreeLibrary](libraries/kernel32/FreeLibrary.md)  
The FreeLibrary function decrements the reference count of the loaded dynamic-link library (DLL). When the reference count reaches zero, the module is unmapped from the address space of the calling process and the handle is no longer valid  

***  

[GetACP](libraries/kernel32/GetACP.md)  
Retrieves the current ANSI code-page identifier for the system.  

***  

[GetBinaryType](libraries/kernel32/GetBinaryType.md)  
Determines whether a file is executable, and if so, what type of executable file it is. That last property determines which subsystem an executable file runs under.
  

***  

[GetCommandLine](libraries/kernel32/GetCommandLine.md)  
Returns a pointer to the command-line string for the current process.  

***  

[GetCompressedFileSize](libraries/kernel32/GetCompressedFileSize.md)  
Retrieves the actual number of bytes of disk storage used to store a specified file. If the file is located on a volume that supports compression/sparse files, and the file is compressed, the value obtained is the compressed/sparse size of the specified file  

***  

[GetComputerName](libraries/kernel32/GetComputerName.md)  
Retrieves the computer name of the current system. This name is established at system startup, when it is initialized from the registry  

***  

[GetComputerNameEx](libraries/kernel32/GetComputerNameEx.md)  
The GetComputerNameEx function retrieves a NetBIOS or DNS name associated with the local computer. The names are established at system startup, when the system reads them from the registry.  

***  

[GetConsoleScreenBufferInfo](libraries/kernel32/GetConsoleScreenBufferInfo.md)  
The GetConsoleScreenBufferInfo function retrieves information about the specified console screen buffer.  

***  

[GetConsoleWindow](libraries/kernel32/GetConsoleWindow.md)  
The GetConsoleWindow function retrieves the window handle used by the console associated with the calling process.  

***  

[GetCurrencyFormat](libraries/kernel32/GetCurrencyFormat.md)  
Formats a number string as a currency string for a locale specified by identifier.  

***  

[GetCurrentDirectory](libraries/kernel32/GetCurrentDirectory.md)  
The GetCurrentDirectory function retrieves the current directory for the current process. 
  

***  

[GetCurrentProcess](libraries/kernel32/GetCurrentProcess.md)  
The GetCurrentProcess function retrieves a <Strong>pseudo</Strong> handle for the current process.  

***  

[GetCurrentProcessId](libraries/kernel32/GetCurrentProcessId.md)  
The GetCurrentProcessId function retrieves the process identifier of the calling process.  

***  

[GetCurrentThread](libraries/kernel32/GetCurrentThread.md)  
The GetCurrentThread function retrieves a <Strong>pseudo</Strong> handle for the current thread.  

***  

[GetCurrentThreadId](libraries/kernel32/GetCurrentThreadId.md)  
The GetCurrentThreadId function retrieves the thread identifier of the calling thread.  

***  

[GetDateFormat](libraries/kernel32/GetDateFormat.md)  
Formats a date as a date string for a locale specified by the locale identifier. The function formats either a specified date or the local system date.  

***  

[GetDiskFreeSpace](libraries/kernel32/GetDiskFreeSpace.md)  
[Obsolete] Retrieves information about the specified disk, including the amount of free space on the disk. 
  

***  

[GetDiskFreeSpaceEx](libraries/kernel32/GetDiskFreeSpaceEx.md)  
Retrieves information about the amount of space available on a disk volume: the total amount of space, the total amount of free space, and the total amount of free space available to the user associated with the calling thread.  

***  

[GetDriveType](libraries/kernel32/GetDriveType.md)  
The GetDriveType function determines whether a disk drive is a removable, fixed, CD-ROM, RAM disk, or network drive  

***  

[GetEnvironmentStrings](libraries/kernel32/GetEnvironmentStrings.md)  
Retrieves the environment block for the current process.
  

***  

[GetEnvironmentVariable](libraries/kernel32/GetEnvironmentVariable.md)  
Retrieves the value of the specified variable from the environment block of the calling process. The value is in the form of a null-terminated string of characters.  

***  

[GetErrorMode](libraries/kernel32/GetErrorMode.md)  
Retrieves the error mode for the current process.  

***  

[GetFileAttributes](libraries/kernel32/GetFileAttributes.md)  
Retrieves attributes for a specified file or directory.  

***  

[GetFileAttributesEx](libraries/kernel32/GetFileAttributesEx.md)  
Retrieves attributes for a specified file or directory.  

***  

[GetFileInformationByHandle](libraries/kernel32/GetFileInformationByHandle.md)  
The GetFileInformationByHandle function retrieves file information for a specified file.  

***  

[GetFileSize](libraries/kernel32/GetFileSize.md)  
Retrieves the size of a specified file.  

***  

[GetFileSizeEx](libraries/kernel32/GetFileSizeEx.md)  
The GetFileSizeEx function retrieves the size of the specified file.  

***  

[GetFileTime](libraries/kernel32/GetFileTime.md)  
Retrieves the date and time that a file was created, last accessed, and last modified.  

***  

[GetFileType](libraries/kernel32/GetFileType.md)  
The GetFileType function retrieves the file type for the specified file.  

***  

[GetFullPathName](libraries/kernel32/GetFullPathName.md)  
Retrieves the full path and file name of a specified file. 
  

***  

[GetHandleInformation](libraries/kernel32/GetHandleInformation.md)  
The GetHandleInformation function retrieves certain properties of an object handle.  

***  

[GetLastError](libraries/kernel32/GetLastError.md)  
The GetLastError function retrieves the calling thread"s last-error code value.  

***  

[GetLocaleInfo](libraries/kernel32/GetLocaleInfo.md)  
Retrieves information about a locale.  

***  

[GetLocalTime](libraries/kernel32/GetLocalTime.md)  
Retrieves the current local date and time.  

***  

[GetLogicalDrives](libraries/kernel32/GetLogicalDrives.md)  
The GetLogicalDrives function retrieves a bitmask representing the currently available disk drives  

***  

[GetLogicalDriveStrings](libraries/kernel32/GetLogicalDriveStrings.md)  
The GetLogicalDriveStrings function fills a buffer with strings that specify valid drives in the system  

***  

[GetLongPathName](libraries/kernel32/GetLongPathName.md)  
The GetLongPathName function converts the specified path to its long form. If no long path is found, this function simply returns the specified name.   

***  

[GetMailslotInfo](libraries/kernel32/GetMailslotInfo.md)  
The GetMailslotInfo function retrieves information about the specified mailslot.   

***  

[GetMappedFileName](libraries/kernel32/GetMappedFileName.md)  
The GetMappedFileName function checks if the specified address is within a memory-mapped file in the address space of the specified process. If so, the function returns the name of the memory-mapped file.  

***  

[GetModuleFileName](libraries/kernel32/GetModuleFileName.md)  
Retrieves the full path and file name for the file containing the specified module.  

***  

[GetModuleHandle](libraries/kernel32/GetModuleHandle.md)  
Retrieves a module handle for the specified module if the file has been mapped into the address space of the calling process.  

***  

[GetNativeSystemInfo](libraries/kernel32/GetNativeSystemInfo.md)  
Retrieves information about the current system to an application running under WOW64.   

***  

[GetNumberFormat](libraries/kernel32/GetNumberFormat.md)  
Formats a number string as a number string customized for a locale specified by identifier.  

***  

[GetOEMCP](libraries/kernel32/GetOEMCP.md)  
Retrieves the current original equipment manufacturer (OEM) code-page identifier for the system.  

***  

[GetPriorityClass](libraries/kernel32/GetPriorityClass.md)  
Retrieves the priority class for the specified process. This value, together with the priority value of each thread of the process, determines each thread"s base priority level.  

***  

[GetPrivateProfileSectionNames](libraries/kernel32/GetPrivateProfileSectionNames.md)  
The GetPrivateProfileSectionNames function retrieves the names of all sections in an initialization file.  

***  

[GetPrivateProfileString](libraries/kernel32/GetPrivateProfileString.md)  
Retrieves a string from the specified section in an initialization file.  

***  

[GetProcAddress](libraries/kernel32/GetProcAddress.md)  
Retrieves the address of an exported function or variable from the specified dynamic-link library (DLL). 
  

***  

[GetProcessHeap](libraries/kernel32/GetProcessHeap.md)  
The GetProcessHeap function obtains a handle to the heap of the calling process. This handle can then be used in subsequent calls to the HeapAlloc, HeapReAlloc, HeapFree, and HeapSize functions.  

***  

[GetProcessHeaps](libraries/kernel32/GetProcessHeaps.md)  
The GetProcessHeaps function obtains handles to all of the heaps that are valid for the calling process.  

***  

[GetProcessIoCounters](libraries/kernel32/GetProcessIoCounters.md)  
Retrieves accounting information for all I/O operations performed by the specified process.  

***  

[GetProcessPreferredUILanguages](libraries/kernel32/GetProcessPreferredUILanguages.md)  
Retrieves the process preferred UI languages.  

***  

[GetProcessTimes](libraries/kernel32/GetProcessTimes.md)  
Retrieves timing information for the specified process.  

***  

[GetProcessVersion](libraries/kernel32/GetProcessVersion.md)  
Retrieves the major and minor version numbers of the system on which the specified process expects to run.  

***  

[GetProductInfo](libraries/kernel32/GetProductInfo.md)  
Retrieves the product type for the operating system on the local computer, and maps the type to the product types supported by the specified operating system.  

***  

[GetProfileString](libraries/kernel32/GetProfileString.md)  
Retrieves the string associated with a key in the specified section of the Win.ini file.  

***  

[GetShortPathName](libraries/kernel32/GetShortPathName.md)  
Retrieves the short path form of a specified input path  

***  

[GetStartupInfo](libraries/kernel32/GetStartupInfo.md)  
Retrieves the contents of the STARTUPINFO structure that was specified when the calling process was created.  

***  

[GetStdHandle](libraries/kernel32/GetStdHandle.md)  
The GetStdHandle function retrieves a handle for the standard input, standard output, or standard error device.  

***  

[GetStringTypeEx](libraries/kernel32/GetStringTypeEx.md)  
Retrieves character type information for the characters in the specified source string. For each character in the string, the function sets one or more bits in the corresponding 16-bit element of the output array. Each bit identifies a given character type, for example, letter, digit, or neither.  

***  

[GetSystemDefaultLangID](libraries/kernel32/GetSystemDefaultLangID.md)  
Retrieves the language identifier of the system locale.  

***  

[GetSystemDefaultLCID](libraries/kernel32/GetSystemDefaultLCID.md)  
Retrieves the system default locale identifier.  

***  

[GetSystemDefaultLocaleName](libraries/kernel32/GetSystemDefaultLocaleName.md)  
Retrieves the system default locale name.  

***  

[GetSystemDirectory](libraries/kernel32/GetSystemDirectory.md)  
The GetSystemDirectory function retrieves the path of the system directory. The system directory contains such files as dynamic-link libraries, drivers, and font files.
  

***  

[GetSystemInfo](libraries/kernel32/GetSystemInfo.md)  
Returns information about the current system.  

***  

[GetSystemPowerStatus](libraries/kernel32/GetSystemPowerStatus.md)  
Retrieves the power status of the system. The status indicates whether the system is running on AC or DC power, whether the battery is currently charging, and how much battery life remains.  

***  

[GetSystemRegistryQuota](libraries/kernel32/GetSystemRegistryQuota.md)  
Retrieves the current size of the registry and the maximum size that the registry is allowed to attain on the system.  

***  

[GetSystemTime](libraries/kernel32/GetSystemTime.md)  
Retrieves the current system date and time. The system time is expressed in Coordinated Universal Time (UTC).  

***  

[GetSystemTimeAdjustment](libraries/kernel32/GetSystemTimeAdjustment.md)  
Determines whether the system is applying periodic time adjustments to its time-of-day clock at each clock interrupt, along with the value and period of any such adjustments.  

***  

[GetSystemTimeAsFileTime](libraries/kernel32/GetSystemTimeAsFileTime.md)  
The GetSystemTimeAsFileTime function retrieves the current system date and time. The information is in Coordinated Universal Time (UTC) format.  

***  

[GetSystemWow64Directory](libraries/kernel32/GetSystemWow64Directory.md)  
Retrieves the path of the system directory used by WOW64. This directory is not present on 32-bit Windows.  

***  

[GetTempFileName](libraries/kernel32/GetTempFileName.md)  
The GetTempFileName function creates a name for a temporary file. 

The specified integer can be nonzero, in which case, the function creates the file name but does not create the file. If you specify zero for the integer, the function creates a unique file name and creates the file in the specified directory.  

***  

[GetTempPath](libraries/kernel32/GetTempPath.md)  
The GetTempPath function retrieves the path of the directory designated for temporary files  

***  

[GetThreadLocale](libraries/kernel32/GetThreadLocale.md)  
Retrieves the calling thread"s current locale.  

***  

[GetThreadPriority](libraries/kernel32/GetThreadPriority.md)  
Retrieves the priority value for the specified thread. This value, together with the priority class of the thread"s process, determines the thread"s base-priority level.  

***  

[GetThreadUILanguage](libraries/kernel32/GetThreadUILanguage.md)  
Returns the language identifier of the first user interface language for the current thread.  

***  

[GetTickCount](libraries/kernel32/GetTickCount.md)  
Retrieves the number of milliseconds that have elapsed since the system was started.  

***  

[GetTimeZoneInformation](libraries/kernel32/GetTimeZoneInformation.md)  
Retrieves the current time-zone parameters. These parameters control the translations between Coordinated Universal Time (UTC) and local time.  

***  

[GetUserDefaultLangID](libraries/kernel32/GetUserDefaultLangID.md)  
Retrieves the language identifier of the current user locale.  

***  

[GetUserDefaultLCID](libraries/kernel32/GetUserDefaultLCID.md)  
Retrieves the user default�locale identifier.  

***  

[GetUserDefaultLocaleName](libraries/kernel32/GetUserDefaultLocaleName.md)  
Retrieves the user default locale name.  

***  

[GetUserDefaultUILanguage](libraries/kernel32/GetUserDefaultUILanguage.md)  
Returns the language identifier for the user UI language for the current user.  

***  

[GetUserGeoID](libraries/kernel32/GetUserGeoID.md)  
Retrieves information about the geographical location of the user.  

***  

[GetVersion](libraries/kernel32/GetVersion.md)  
The GetVersion function returns the current version number of Windows and information about the operating system platform  

***  

[GetVersionEx](libraries/kernel32/GetVersionEx.md)  
The GetVersionEx function obtains extended information about the version of the operating system that is currently running  

***  

[GetVolumeInformation](libraries/kernel32/GetVolumeInformation.md)  
Retrieves information about a file system and volume whose root directory is specified.  

***  

[GetVolumeNameForVolumeMountPoint](libraries/kernel32/GetVolumeNameForVolumeMountPoint.md)  
Takes a volume mount point or root directory and returns the corresponding unique volume name.  

***  

[GetVolumePathNamesForVolumeName](libraries/kernel32/GetVolumePathNamesForVolumeName.md)  
Retrieves a list of path names for the specified volume name.
  

***  

[GetWindowsDirectory](libraries/kernel32/GetWindowsDirectory.md)  
The GetWindowsDirectory function retrieves the path of the Windows directory. The Windows directory contains such files as applications, initialization files, and help files.
  

***  

[GlobalAlloc](libraries/kernel32/GlobalAlloc.md)  
The GlobalAlloc function allocates the specified number of bytes from the heap  

***  

[GlobalFree](libraries/kernel32/GlobalFree.md)  
The GlobalFree function frees the specified global memory object and invalidates its handle  

***  

[GlobalGetAtomName](libraries/kernel32/GlobalGetAtomName.md)  
Retrieves a copy of the character string associated with the specified global atom.  

***  

[GlobalLock](libraries/kernel32/GlobalLock.md)  
The GlobalLock function locks a global memory object and returns a pointer to the first byte of the object"s memory block.  

***  

[GlobalMemoryStatus](libraries/kernel32/GlobalMemoryStatus.md)  
The GlobalMemoryStatus function obtains information about the system"s current usage of both physical and virtual memory.
  

***  

[GlobalReAlloc](libraries/kernel32/GlobalReAlloc.md)  
Changes the size or attributes of a specified global memory object. The size can increase or decrease.  

***  

[GlobalSize](libraries/kernel32/GlobalSize.md)  
The GlobalSize function retrieves the current size, in bytes, of the specified global memory object  

***  

[GlobalUnlock](libraries/kernel32/GlobalUnlock.md)  
Decrements the lock count associated with a memory object that was allocated with GMEM_MOVEABLE. This function has no effect on memory objects allocated with GMEM_FIXED.  

***  

[HeapAlloc](libraries/kernel32/HeapAlloc.md)  
The HeapAlloc function allocates a block of memory from a heap. The allocated memory is <Strong>not movable</Strong>.  

***  

[HeapCompact](libraries/kernel32/HeapCompact.md)  
Attempts to compact a specified heap. It compacts the heap by coalescing adjacent free blocks of memory and decommitting large free blocks of memory.  

***  

[HeapFree](libraries/kernel32/HeapFree.md)  
The HeapFree function frees a memory block allocated from a heap by the HeapAlloc or HeapReAlloc function.  

***  

[HeapLock](libraries/kernel32/HeapLock.md)  
Attempts to acquire the critical section object, or lock, that is associated with a specified heap.   

***  

[HeapReAlloc](libraries/kernel32/HeapReAlloc.md)  
The HeapReAlloc function reallocates a block of memory from a heap. This function enables you to resize a memory block and change other memory block properties. The allocated memory is not movable.  

***  

[HeapSize](libraries/kernel32/HeapSize.md)  
The HeapSize function retrieves the size of a memory block allocated from a heap by the HeapAlloc or HeapReAlloc function.  

***  

[HeapUnlock](libraries/kernel32/HeapUnlock.md)  
Releases ownership of the critical section object, or lock, that is associated with a specified heap. The HeapUnlock function reverses the action of the HeapLock function.  

***  

[HeapValidate](libraries/kernel32/HeapValidate.md)  
Attempts to validate a specified heap. The function scans all the memory blocks in the heap, and verifies that the heap control structures maintained by the heap manager are in a consistent state. 

You can also use the HeapValidate function to validate a single memory block within a specified heap, without checking the validity of the entire heap.  

***  

[HeapWalk](libraries/kernel32/HeapWalk.md)  
Enumerates the memory blocks in a specified heap created or manipulated by heap memory allocators such as HeapAlloc, HeapReAlloc, and HeapFree.  

***  

[IsWow64Process](libraries/kernel32/IsWow64Process.md)  
Determines whether the specified process is running under WOW64.  

***  

[LCIDToLocaleName](libraries/kernel32/LCIDToLocaleName.md)  
Converts a locale identifier to a locale name.  

***  

[LoadLibrary](libraries/kernel32/LoadLibrary.md)  
The LoadLibrary function maps the specified executable module into the address space of the calling process.

  

***  

[LoadLibraryEx](libraries/kernel32/LoadLibraryEx.md)  
Maps the specified executable module into the address space of the calling process. The executable module can be a .dll or an .exe file. The specified module may cause other modules to be mapped into the address space.
  

***  

[LoadResource](libraries/kernel32/LoadResource.md)  
The LoadResource function loads the specified resource into global memory.  

***  

[LocalAlloc](libraries/kernel32/LocalAlloc.md)  
The LocalAlloc function allocates the specified number of bytes from the heap.  

***  

[LocaleNameToLCID](libraries/kernel32/LocaleNameToLCID.md)  
Converts a locale name to a locale identifier.  

***  

[LocalFileTimeToFileTime](libraries/kernel32/LocalFileTimeToFileTime.md)  
Converts a local file time to a file time based on the Coordinated Universal Time (UTC).  

***  

[LocalFree](libraries/kernel32/LocalFree.md)  
The LocalFree function frees the specified local memory object and invalidates its handle.  

***  

[LocalSize](libraries/kernel32/LocalSize.md)  
The LocalSize function returns the current size of the specified local memory object, in bytes.  

***  

[LockFile](libraries/kernel32/LockFile.md)  
Locks a region in an open file. Locking a region prevents other processes from accessing the region.  

***  

[LockResource](libraries/kernel32/LockResource.md)  
The LockResource function locks the specified resource in memory.  

***  

[MapViewOfFile](libraries/kernel32/MapViewOfFile.md)  
The MapViewOfFile function maps a view of a file mapping into the address space of the calling process.  

***  

[MoveFile](libraries/kernel32/MoveFile.md)  
The MoveFile function moves an existing file or a directory, including its children.

To specify how to move the file, use the MoveFileEx function  

***  

[MoveFileTransacted](libraries/kernel32/MoveFileTransacted.md)  
Moves an existing file or a directory, including its children, as a transacted operation.  

***  

[MultiByteToWideChar](libraries/kernel32/MultiByteToWideChar.md)  
The MultiByteToWideChar function maps a character string to a wide-character (Unicode) string.  

***  

[NormalizeString](libraries/kernel32/NormalizeString.md)  
Normalizes characters of a text string according to Unicode 4.0 TR#15.  

***  

[OpenEvent](libraries/kernel32/OpenEvent.md)  
The OpenEvent function opens an existing named event object.  

***  

[OpenFile](libraries/kernel32/OpenFile.md)  
The OpenFile function creates, opens, reopens, or deletes a file  

***  

[OpenProcess](libraries/kernel32/OpenProcess.md)  
The OpenProcess function opens an existing process object.  

***  

[OpenSemaphore](libraries/kernel32/OpenSemaphore.md)  
The OpenSemaphore function returns a handle of an existing named semaphore object  

***  

[OpenWaitableTimer](libraries/kernel32/OpenWaitableTimer.md)  
Opens an existing named waitable timer object.  

***  

[Process32First](libraries/kernel32/Process32First.md)  
Retrieves information about the first process encountered in a system snapshot.  

***  

[Process32Next](libraries/kernel32/Process32Next.md)  
Retrieves information about the next process recorded in a system snapshot.  

***  

[QueryDosDevice](libraries/kernel32/QueryDosDevice.md)  
Retrieves information about MS-DOS device names.  

***  

[QueryPerformanceCounter](libraries/kernel32/QueryPerformanceCounter.md)  
The QueryPerformanceCounter function retrieves the current value of the high-resolution performance counter.  

***  

[QueryPerformanceFrequency](libraries/kernel32/QueryPerformanceFrequency.md)  
The QueryPerformanceFrequency function retrieves the frequency of the high-resolution performance counter, if one exists. The frequency cannot change while the system is running.  

***  

[ReadConsole](libraries/kernel32/ReadConsole.md)  
The ReadConsole function reads character input from the console input buffer and removes it from the buffer.  

***  

[ReadDirectoryChangesW](libraries/kernel32/ReadDirectoryChangesW.md)  
The ReadDirectoryChangesW function retrieves information describing the changes occurring within a directory.  

***  

[ReadFile](libraries/kernel32/ReadFile.md)  
Reads data from a file, starting at the position indicated by the file pointer.  

***  

[ReadProcessMemory](libraries/kernel32/ReadProcessMemory.md)  
Reads data from an area of memory in a specified process.   

***  

[RegisterServiceProcess](libraries/kernel32/RegisterServiceProcess.md)  
The RegisterServiceProcess function registers or unregisters a service process. A service process continues to run after the user logs off.   

***  

[ReleaseMutex](libraries/kernel32/ReleaseMutex.md)  
Releases ownership of the specified mutex object.  

***  

[ReleaseSemaphore](libraries/kernel32/ReleaseSemaphore.md)  
The ReleaseSemaphore function increases the count of the specified semaphore object by a specified amount  

***  

[RemoveDirectory](libraries/kernel32/RemoveDirectory.md)  
The RemoveDirectory function deletes an existing empty directory. To recursively delete files and subdirectories in a directory, use the SHFileOperation function.  

***  

[RemoveDirectoryTransacted](libraries/kernel32/RemoveDirectoryTransacted.md)  
Deletes an existing empty directory as a transacted operation.  

***  

[ReplaceFile](libraries/kernel32/ReplaceFile.md)  
Replaces one file with another file, with the option of creating a backup copy of the original file.   

***  

[ResetEvent](libraries/kernel32/ResetEvent.md)  
The ResetEvent function sets the specified event object to the nonsignaled state.  

***  

[SearchPath](libraries/kernel32/SearchPath.md)  
The SearchPath function searches for the specified file.   

***  

[SetComputerName](libraries/kernel32/SetComputerName.md)  
The SetComputerName function stores a new NetBIOS name for the local computer. The name is stored in the registry and takes effect the next time the user restarts the computer.   

***  

[SetConsoleCursorPosition](libraries/kernel32/SetConsoleCursorPosition.md)  
The SetConsoleCursorPosition function sets the cursor position in the specified console screen buffer.  

***  

[SetConsoleTextAttribute](libraries/kernel32/SetConsoleTextAttribute.md)  
The SetConsoleTextAttribute function sets the attributes of characters written to the console screen buffer by the WriteFile or WriteConsole function, or echoed by the ReadFile or ReadConsole function.   

***  

[SetConsoleTitle](libraries/kernel32/SetConsoleTitle.md)  
The SetConsoleTitle function sets the title bar string for the current console window.  

***  

[SetCurrentDirectory](libraries/kernel32/SetCurrentDirectory.md)  
The SetCurrentDirectory function changes the current directory for the current process.  

***  

[SetEndOfFile](libraries/kernel32/SetEndOfFile.md)  
Sets the physical file size for the specified file to the current position of the file pointer.  

***  

[SetEnvironmentVariable](libraries/kernel32/SetEnvironmentVariable.md)  
The SetEnvironmentVariable function sets the value of an environment variable for the current process.  

***  

[SetErrorMode](libraries/kernel32/SetErrorMode.md)  
Controls whether the system will handle the specified types of serious errors, or whether the process will handle them.  

***  

[SetEvent](libraries/kernel32/SetEvent.md)  
The SetEvent function sets the specified event object to the signaled state.  

***  

[SetFileAttributes](libraries/kernel32/SetFileAttributes.md)  
Sets a file"s attributes. 
  

***  

[SetFilePointer](libraries/kernel32/SetFilePointer.md)  
The SetFilePointer function moves the file pointer of an open file.  

***  

[SetFilePointerEx](libraries/kernel32/SetFilePointerEx.md)  
Moves the file pointer of the specified file.  

***  

[SetFileTime](libraries/kernel32/SetFileTime.md)  
Sets the date and time that a file was created, last accessed, or last modified.  

***  

[SetHandleInformation](libraries/kernel32/SetHandleInformation.md)  
Sets certain properties of an object handle.  

***  

[SetLastError](libraries/kernel32/SetLastError.md)  
Sets the last-error code for the calling thread. This function is intended primarily for dynamic-link libraries (DLL). Calling this function after an error occurs lets the DLL emulate the behavior of the Win32 API. 

If you are defining an error code for your application, be sure that your error code does not conflict with any system-defined error codes. 
  

***  

[SetMailslotInfo](libraries/kernel32/SetMailslotInfo.md)  
The SetMailslotInfo function sets the time-out value used by the specified mailslot for a read operation.   

***  

[SetNamedPipeHandleState](libraries/kernel32/SetNamedPipeHandleState.md)  
Sets the read mode and the blocking mode of the specified named pipe. If the specified handle is to the client end of a named pipe and if the named pipe server process is on a remote computer, the function can also be used to control local buffering.
  

***  

[SetPriorityClass](libraries/kernel32/SetPriorityClass.md)  
Sets the priority class for the specified process. This value together with the priority value of each thread of the process determines each thread"s base priority level.  

***  

[SetProcessPreferredUILanguages](libraries/kernel32/SetProcessPreferredUILanguages.md)  
Sets the process preferred UI languages for the application process.  

***  

[SetSearchPathMode](libraries/kernel32/SetSearchPathMode.md)  
Sets the per-process mode that the SearchPath function uses when locating files.  

***  

[SetSystemPowerState](libraries/kernel32/SetSystemPowerState.md)  
The SetSystemPowerState function suspends the system by shutting power down. Depending on the ForceFlag parameter, the function either suspends operation immediately or requests permission from all applications and device drivers before doing so.  

***  

[SetThreadExecutionState](libraries/kernel32/SetThreadExecutionState.md)  
Enables applications to inform the system that it is in use, thereby preventing the system from entering the sleeping power state or turning off the display while the application is running.  

***  

[SetThreadPriority](libraries/kernel32/SetThreadPriority.md)  
Sets the priority value for the specified thread. This value, together with the priority class of the thread"s process, determines the thread"s base priority level.  

***  

[SetTimeZoneInformation](libraries/kernel32/SetTimeZoneInformation.md)  
The SetTimeZoneInformation function sets the current time-zone parameters. These parameters control translations from Coordinated Universal Time (UTC) to local time.  

***  

[SetUserGeoID](libraries/kernel32/SetUserGeoID.md)  
Sets the geographical location identifier for the user. This identifier should have one of the values described in Table of Geographical Locations.  

***  

[SetVolumeLabel](libraries/kernel32/SetVolumeLabel.md)  
The SetVolumeLabel function sets the label of a file system volume.  

***  

[SetVolumeMountPoint](libraries/kernel32/SetVolumeMountPoint.md)  
Mounts the specified volume at the specified volume mount point.  

***  

[SetWaitableTimer](libraries/kernel32/SetWaitableTimer.md)  
Activates the specified waitable timer. When the due time arrives, the timer is signaled and the thread that set the timer calls the optional completion routine.  

***  

[SizeofResource](libraries/kernel32/SizeofResource.md)  
The SizeofResource function returns the size, in bytes, of the specified resource.  

***  

[Sleep](libraries/kernel32/Sleep.md)  
The Sleep function suspends the execution of the current thread for the specified interval  

***  

[SystemTimeToFileTime](libraries/kernel32/SystemTimeToFileTime.md)  
The SystemTimeToFileTime function converts a system time to a file time.  

***  

[TerminateJobObject](libraries/kernel32/TerminateJobObject.md)  
Terminates all processes currently associated with the job.
  

***  

[TerminateProcess](libraries/kernel32/TerminateProcess.md)  
The TerminateProcess function terminates the specified process and all of its threads.  

***  

[UnlockFile](libraries/kernel32/UnlockFile.md)  
Unlocks a region in an open file. Unlocking a region enables other processes to access the region.  

***  

[UnmapViewOfFile](libraries/kernel32/UnmapViewOfFile.md)  
The UnmapViewOfFile function unmaps a mapped view of a file from the calling process"s address space.  

***  

[UpdateResource](libraries/kernel32/UpdateResource.md)  
The UpdateResource function adds, deletes, or replaces a resource in an executable file.  

***  

[VirtualAllocEx](libraries/kernel32/VirtualAllocEx.md)  
Reserves or commits a region of memory within the virtual address space of a specified process.  

***  

[VirtualFreeEx](libraries/kernel32/VirtualFreeEx.md)  
Releases, decommits, or releases and decommits a region of memory within the virtual address space of a specified process.  

***  

[WaitForSingleObject](libraries/kernel32/WaitForSingleObject.md)  
The WaitForSingleObject function returns when the specified object is in the signaled state or when the time-out interval elapses  

***  

[WideCharToMultiByte](libraries/kernel32/WideCharToMultiByte.md)  
The WideCharToMultiByte function maps a wide-character string (Unicode) to a new character string.  

***  

[WindowProc](libraries/kernel32/WindowProc.md)  
The WindowProc function is an application-defined function that processes messages sent to a window. The WNDPROC type defines a pointer to this callback function. WindowProc is a placeholder for the application-defined function name.  

***  

[WinExec](libraries/kernel32/WinExec.md)  
The WinExec function runs the specified application. 

Note  This function is provided only for compatibility with 16-bit Windows. Win32-based applications should use the CreateProcess function
  

***  

[WriteConsole](libraries/kernel32/WriteConsole.md)  
The WriteConsole function writes a character string to a console screen buffer beginning at the current cursor location.  

***  

[WriteFile](libraries/kernel32/WriteFile.md)  
The WriteFile function writes data to a file and is designed for both synchronous and asynchronous operation.   

***  

[WritePrivateProfileSection](libraries/kernel32/WritePrivateProfileSection.md)  
Replaces the keys and values for the specified section in an initialization file.  

***  

[WritePrivateProfileString](libraries/kernel32/WritePrivateProfileString.md)  
The WritePrivateProfileString function copies a string into the specified section of an initialization file.  

***  

[WriteProcessMemory](libraries/kernel32/WriteProcessMemory.md)  
Writes data to an area of memory in a specified process.   

***  

[ZeroMemory](libraries/kernel32/ZeroMemory.md)  
Fills a block of memory with zeros.  

***  

[_lclose](libraries/kernel32/_lclose.md)  
Closes the specified file so that it is no longer available for reading or writing.  

***  

[_lopen](libraries/kernel32/_lopen.md)  
Opens an existing file and sets the file pointer to the beginning of the file.  

***  

</details>
<a name="ktmw32" />

# ![](images/fox1.png) Library: ktmw32
<details>

***  

[CommitTransaction](libraries/ktmw32/CommitTransaction.md)  
Requests that the specified transaction be committed.  

***  

[CreateTransaction](libraries/ktmw32/CreateTransaction.md)  
Creates a new file system transaction object.  

***  

[RollbackTransaction](libraries/ktmw32/RollbackTransaction.md)  
Requests that the specified transaction be rolled back. This function is synchronous.  

***  

</details>
<a name="mapi32" />

# ![](images/fox1.png) Library: mapi32
<details>

***  

[MAPIAddress](libraries/mapi32/MAPIAddress.md)  
The MAPIAddress function creates or modifies a set of address list entries.  

***  

[MAPIFindNext](libraries/mapi32/MAPIFindNext.md)  
The MAPIFindNext function retrieves the next (or first) message identifier of a specified type of incoming message.   

***  

[MAPIFreeBuffer](libraries/mapi32/MAPIFreeBuffer.md)  
The MAPIFreeBuffer function frees memory allocated by the messaging system.  

***  

[MAPILogoff](libraries/mapi32/MAPILogoff.md)  
The MAPILogoff function ends a session with the messaging system.  

***  

[MAPILogon](libraries/mapi32/MAPILogon.md)  
The MAPILogon function begins a Simple MAPI session, loading the default message store and address book providers.  

***  

[MAPIReadMail](libraries/mapi32/MAPIReadMail.md)  
The MAPIReadMail function retrieves a message for reading.   

***  

[MAPIResolveName](libraries/mapi32/MAPIResolveName.md)  
The MAPIResolveName function transforms a message recipient"s name as entered by a user to an unambiguous address list entry.  

***  

[MAPISendDocuments](libraries/mapi32/MAPISendDocuments.md)  
The MAPISendDocuments function sends a standard message with one or more attached files and a cover note.   

***  

[MAPISendMail](libraries/mapi32/MAPISendMail.md)  
The MAPISendMail function sends a message.   

***  

</details>
<a name="mpr" />

# ![](images/fox1.png) Library: mpr
<details>

***  

[WNetAddConnection](libraries/mpr/WNetAddConnection.md)  
The WNetAddConnection function enables the calling application to connect a local device to a network resource.   

***  

[WNetAddConnection2](libraries/mpr/WNetAddConnection2.md)  
The WNetAddConnection2 function makes a connection to a network resource. The function can redirect a local device to the network resource.  

***  

[WNetCancelConnection2](libraries/mpr/WNetCancelConnection2.md)  
The WNetCancelConnection2 function cancels an existing network connection. You can also call the function to remove remembered network connections that are not currently connected.  

***  

[WNetCloseEnum](libraries/mpr/WNetCloseEnum.md)  
The WNetCloseEnum function ends a network resource enumeration started by a call to the WNetOpenEnum function.  

***  

[WNetConnectionDialog](libraries/mpr/WNetConnectionDialog.md)  
The WNetConnectionDialog function starts a general browsing dialog box for connecting to network resources. The function requires a handle to the owner window for the dialog box.  

***  

[WNetConnectionDialog1](libraries/mpr/WNetConnectionDialog1.md)  
Brings up a general browsing dialog for connecting to network resources.  

***  

[WNetDisconnectDialog](libraries/mpr/WNetDisconnectDialog.md)  
The WNetDisconnectDialog function starts a general browsing dialog box for disconnecting from network resources. The function requires a handle to the owner window for the dialog box.  

***  

[WNetEnumResource](libraries/mpr/WNetEnumResource.md)  
The WNetEnumResource function continues an enumeration of network resources that was started by a call to the WNetOpenEnum function.   

***  

[WNetGetConnection](libraries/mpr/WNetGetConnection.md)  
The WNetGetConnection function retrieves the name of the network resource associated with a local device.  

***  

[WNetGetNetworkInformation](libraries/mpr/WNetGetNetworkInformation.md)  
The WNetGetNetworkInformation function returns extended information about a specific network provider whose name was returned by a previous network enumeration.  

***  

[WNetGetProviderName](libraries/mpr/WNetGetProviderName.md)  
The WNetGetProviderName function obtains the provider name for a specific type of network.   

***  

[WNetGetUniversalName](libraries/mpr/WNetGetUniversalName.md)  
The WNetGetUniversalName function takes a drive-based path for a network resource and returns an information structure that contains a more universal form of the name.   

***  

[WNetGetUser](libraries/mpr/WNetGetUser.md)  
The WNetGetUser function retrieves the current default user name, or the user name used to establish a network connection.   

***  

[WNetOpenEnum](libraries/mpr/WNetOpenEnum.md)  
The WNetOpenEnum function starts an enumeration of network resources or existing connections. You can continue the enumeration by calling the WNetEnumResource function.  

***  

</details>
<a name="mqrt" />

# ![](images/fox1.png) Library: mqrt
<details>

***  

[MQCloseQueue](libraries/mqrt/MQCloseQueue.md)  
Closes a given queue or subqueue.  

***  

[MQDeleteQueue](libraries/mqrt/MQDeleteQueue.md)  
Deletes a queue from the directory service (in the case of public queues) or from the local computer (in the case of private queues).  

***  

[MQHandleToFormatName](libraries/mqrt/MQHandleToFormatName.md)  
Returns a format name for the queue or subqueue based on its handle.  

***  

[MQOpenQueue](libraries/mqrt/MQOpenQueue.md)  
Opens a queue for sending, peeking at, retrieving, or purging messages.   

***  

[MQPathNameToFormatName](libraries/mqrt/MQPathNameToFormatName.md)  
Returns a format name based on the path name provided.  

***  

[MQPurgeQueue](libraries/mqrt/MQPurgeQueue.md)  
Deletes all of the messages in a queue.  

***  

</details>
<a name="mshtml" />

# ![](images/fox1.png) Library: mshtml
<details>

***  

[ShowHTMLDialog](libraries/mshtml/ShowHTMLDialog.md)  
Creates a modal dialog box that displays HTML.  

***  

</details>
<a name="msimg32" />

# ![](images/fox1.png) Library: msimg32
<details>

***  

[AlphaBlend](libraries/msimg32/AlphaBlend.md)  
The AlphaBlend function displays bitmaps that have transparent or semitransparent pixels.  

***  

[GradientFill](libraries/msimg32/GradientFill.md)  
The GradientFill function fills rectangle and triangle structures.   

***  

</details>
<a name="msvfw32" />

# ![](images/fox1.png) Library: msvfw32
<details>

***  

[DrawDibClose](libraries/msvfw32/DrawDibClose.md)  
The DrawDibClose function closes a DrawDib DC and frees the resources DrawDib allocated for it.  

***  

[DrawDibDraw](libraries/msvfw32/DrawDibDraw.md)  
The DrawDibDraw function draws a DIB to the screen.  

***  

[DrawDibOpen](libraries/msvfw32/DrawDibOpen.md)  
The DrawDibOpen function opens the DrawDib library for use and creates a DrawDib DC for drawing.  

***  

</details>
<a name="netapi32" />

# ![](images/fox1.png) Library: netapi32
<details>

***  

[NetApiBufferFree](libraries/netapi32/NetApiBufferFree.md)  
Frees the memory that the NetApiBufferAllocate function allocates. Call NetApiBufferFree to free the memory that other network management functions return on Windows NT, Windows 2000, and Windows XP.  

***  

[NetApiBufferSize](libraries/netapi32/NetApiBufferSize.md)  
The NetApiBufferSize function returns the size, in bytes, of a buffer allocated by a call to the NetApiBufferAllocate function.  

***  

[NetConnectionEnum](libraries/netapi32/NetConnectionEnum.md)  
Lists all connections made to a shared resource on the server or all connections established from a particular computer.  

***  

[NetFileClose](libraries/netapi32/NetFileClose.md)  
The NetFileClose function forces a resource to close.  

***  

[NetFileEnum](libraries/netapi32/NetFileEnum.md)  
The NetFileEnum function returns information about some or all open files on a server, depending on the parameters specified.  

***  

[NetFileGetInfo](libraries/netapi32/NetFileGetInfo.md)  
The NetFileGetInfo function retrieves information about a particular opening of a server resource.  

***  

[NetGetDCName](libraries/netapi32/NetGetDCName.md)  
Returns the name of the primary domain controller (PDC). It does not return the name of the backup domain controller (BDC) for the specified domain.  

***  

[NetGetJoinInformation](libraries/netapi32/NetGetJoinInformation.md)  
The NetGetJoinInformation function retrieves join status information for the specified computer.  

***  

[NetGroupEnum](libraries/netapi32/NetGroupEnum.md)  
The NetGroupEnum function retrieves information about each global group in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.  

***  

[NetJoinDomain](libraries/netapi32/NetJoinDomain.md)  
The NetJoinDomain function joins a computer to a workgroup or domain.
  

***  

[NetLocalGroupEnum](libraries/netapi32/NetLocalGroupEnum.md)  
The NetLocalGroupEnum function returns information about each local group account on the specified server.  

***  

[NetMessageBufferSend](libraries/netapi32/NetMessageBufferSend.md)  
Sends a buffer of information to a registered message alias.
  

***  

[NetMessageNameAdd](libraries/netapi32/NetMessageNameAdd.md)  
Registers a message alias in the message name table. The function requires that the messenger service be started.
  

***  

[NetMessageNameDel](libraries/netapi32/NetMessageNameDel.md)  
Deletes a message alias in the message name table. The function requires that the messenger service be started.  

***  

[NetMessageNameEnum](libraries/netapi32/NetMessageNameEnum.md)  
Lists the message aliases that receive messages on a specified computer. The function requires that the messenger service be started.
  

***  

[NetScheduleJobAdd](libraries/netapi32/NetScheduleJobAdd.md)  
Submits a job to run at a specified future time and date.
  

***  

[NetScheduleJobDel](libraries/netapi32/NetScheduleJobDel.md)  
The NetScheduleJobDel function deletes a range of jobs queued to run at a computer.  

***  

[NetScheduleJobEnum](libraries/netapi32/NetScheduleJobEnum.md)  
Lists the jobs queued on a specified computer.   

***  

[NetServerEnum](libraries/netapi32/NetServerEnum.md)  
Lists all servers of the specified type that are visible in a domain.  

***  

[NetServerGetInfo](libraries/netapi32/NetServerGetInfo.md)  
The NetServerGetInfo function retrieves current configuration information for the specified server.  

***  

[NetSessionEnum](libraries/netapi32/NetSessionEnum.md)  
Provides information about sessions established on a server.  

***  

[NetShareAdd](libraries/netapi32/NetShareAdd.md)  
Shares a server resource.  

***  

[NetShareDel](libraries/netapi32/NetShareDel.md)  
Deletes a share name from a server"s list of shared resources, disconnecting all connections to the shared resource.  

***  

[NetShareEnum](libraries/netapi32/NetShareEnum.md)  
The NetShareEnum function retrieves information about each shared resource on a server or the local computer.  

***  

[NetShareSetInfo](libraries/netapi32/NetShareSetInfo.md)  
Sets the parameters of a shared resource.  

***  

[NetUnjoinDomain](libraries/netapi32/NetUnjoinDomain.md)  
The NetUnjoinDomain function unjoins a computer from a workgroup or a domain.
  

***  

[NetUserAdd](libraries/netapi32/NetUserAdd.md)  
Adds a user account and assigns a password and privilege level.
  

***  

[NetUserChangePassword](libraries/netapi32/NetUserChangePassword.md)  
Changes user`s password for a specified network server or domain.
  

***  

[NetUserDel](libraries/netapi32/NetUserDel.md)  
Deletes a user account from a server.  

***  

[NetUserEnum](libraries/netapi32/NetUserEnum.md)  
The NetUserEnum function provides information about all user accounts on a server.   

***  

[NetUserGetGroups](libraries/netapi32/NetUserGetGroups.md)  
The NetUserGetGroups function retrieves a list of global groups to which a specified user belongs.  

***  

[NetUserGetInfo](libraries/netapi32/NetUserGetInfo.md)  
Retrieves information about a particular user account on a server.  

***  

[NetUserGetLocalGroups](libraries/netapi32/NetUserGetLocalGroups.md)  
The NetUserGetLocalGroups function retrieves a list of local groups to which a specified user belongs.
  

***  

[NetUserSetInfo](libraries/netapi32/NetUserSetInfo.md)  
Sets the parameters of a user account.
  

***  

[NetWkstaGetInfo](libraries/netapi32/NetWkstaGetInfo.md)  
The NetWkstaGetInfo function returns information about the configuration of a workstation.  

***  

[NetWkstaTransportEnum](libraries/netapi32/NetWkstaTransportEnum.md)  
The NetWkstaTransportEnum function supplies information about transport protocols that are managed by the redirector, which is the software on the client computer that generates file requests to the server computer.  

***  

[NetWkstaUserEnum](libraries/netapi32/NetWkstaUserEnum.md)  
The NetWkstaUserEnum function lists information about all users currently logged on to the workstation. This list includes interactive, service and batch logons.  

***  

[PathFindOnPath](libraries/netapi32/PathFindOnPath.md)  
Searches for a file.  

***  

</details>
<a name="ntdll" />

# ![](images/fox1.png) Library: ntdll
<details>

***  

[RtlCompressBuffer](libraries/ntdll/RtlCompressBuffer.md)  
Compresses a buffer and can be used by a file system driver to facilitate the implementation of file compression.  

***  

[RtlDecompressBuffer](libraries/ntdll/RtlDecompressBuffer.md)  
Decompresses an entire compressed buffer.  

***  

[RtlGetCompressionWorkSpaceSize](libraries/ntdll/RtlGetCompressionWorkSpaceSize.md)  
This function is used to determine the correct size of the WorkSpace buffer for the RtlCompressBuffer and RtlDecompressFragment functions.  

***  

</details>
<a name="odbc32" />

# ![](images/fox1.png) Library: odbc32
<details>

***  

[SQLAllocEnv](libraries/odbc32/SQLAllocEnv.md)  
In ODBC 3.x, the ODBC 2.x function SQLAllocEnv has been replaced by SQLAllocHandle.  

***  

[SQLAllocHandle](libraries/odbc32/SQLAllocHandle.md)  
SQLAllocHandle allocates an environment, connection, statement, or descriptor handle.  

***  

[SQLBindCol](libraries/odbc32/SQLBindCol.md)  
SQLBindCol binds application data buffers to columns in the result set.  

***  

[SQLBrowseConnect](libraries/odbc32/SQLBrowseConnect.md)  
SQLBrowseConnect supports an iterative method of discovering and enumerating the attributes and attribute values required to connect to a data source. Each call to SQLBrowseConnect returns successive levels of attributes and attribute values.  

***  

[SQLConfigDataSource](libraries/odbc32/SQLConfigDataSource.md)  
SQLConfigDataSource adds, modifies, or deletes data sources.  

***  

[SQLConnect](libraries/odbc32/SQLConnect.md)  
SQLConnect establishes connections to a driver and a data source.   

***  

[SQLCreateDataSource](libraries/odbc32/SQLCreateDataSource.md)  
SQLCreateDataSource displays a dialog box with which the user can add a data source.  

***  

[SQLDataSources](libraries/odbc32/SQLDataSources.md)  
SQLDataSources returns information about a data source. This function is implemented solely by the Driver Manager.  

***  

[SQLDisconnect](libraries/odbc32/SQLDisconnect.md)  
SQLDisconnect closes the connection associated with a specific connection handle.  

***  

[SQLDriverConnect](libraries/odbc32/SQLDriverConnect.md)  
SQLDriverConnect is an alternative to SQLConnect. It supports data sources that require more connection information than the three arguments in SQLConnect, dialog boxes to prompt the user for all connection information, and data sources that are not defined in the system information.  

***  

[SQLDrivers](libraries/odbc32/SQLDrivers.md)  
SQLDrivers lists driver descriptions and driver attribute keywords.  

***  

[SQLExecDirect](libraries/odbc32/SQLExecDirect.md)  
SQLExecDirect executes a preparable statement, using the current values of the parameter marker variables if any parameters exist in the statement.  

***  

[SQLFetch](libraries/odbc32/SQLFetch.md)  
SQLFetch fetches the next rowset of data from the result set and returns data for all bound columns.  

***  

[SQLFreeEnv](libraries/odbc32/SQLFreeEnv.md)  
In ODBC 3.x, the ODBC 2.0 function SQLFreeEnv has been replaced by SQLFreeHandle.  

***  

[SQLFreeHandle](libraries/odbc32/SQLFreeHandle.md)  
SQLFreeHandle frees resources associated with a specific environment, connection, statement, or descriptor handle.  

***  

[SQLGetConfigMode](libraries/odbc32/SQLGetConfigMode.md)  
Retrieves the configuration mode that indicates where the Odbc.ini entry listing DSN values is in the system information.
  

***  

[SQLGetConnectAttr](libraries/odbc32/SQLGetConnectAttr.md)  
SQLGetConnectAttr returns the current setting of a connection attribute.  

***  

[SQLGetDiagRec](libraries/odbc32/SQLGetDiagRec.md)  
SQLGetDiagRec returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information.   

***  

[SQLGetEnvAttr](libraries/odbc32/SQLGetEnvAttr.md)  
SQLGetEnvAttr returns the current setting of an environment attribute.  

***  

[SQLGetFunctions](libraries/odbc32/SQLGetFunctions.md)  
SQLGetFunctions returns information about whether a driver supports a specific ODBC function.   

***  

[SQLGetInfo](libraries/odbc32/SQLGetInfo.md)  
SQLGetInfo returns general information about the driver and data source associated with a connection.  

***  

[SQLGetInstalledDrivers](libraries/odbc32/SQLGetInstalledDrivers.md)  
SQLGetInstalledDrivers reads the [ODBC Drivers] section of the system information and returns a list of descriptions of the installed drivers.  

***  

[SQLGetPrivateProfileString](libraries/odbc32/SQLGetPrivateProfileString.md)  
SQLGetPrivateProfileString gets a list of names of values or data corresponding to a value of the system information.  

***  

[SQLManageDataSources](libraries/odbc32/SQLManageDataSources.md)  
SQLManageDataSources displays a dialog box with which users can set up, add, and delete data sources in the system information.  

***  

[SQLNativeSql](libraries/odbc32/SQLNativeSql.md)  
SQLNativeSql returns the SQL string as modified by the driver. SQLNativeSql does not execute the SQL statement.  

***  

[SQLRowCount](libraries/odbc32/SQLRowCount.md)  
SQLRowCount returns the number of rows affected by an UPDATE, INSERT, or DELETE statement.  

***  

[SQLSetConfigMode](libraries/odbc32/SQLSetConfigMode.md)  
Sets the configuration mode that indicates where the Odbc.ini entry listing DSN values is in the system information.
  

***  

[SQLSetEnvAttr](libraries/odbc32/SQLSetEnvAttr.md)  
SQLSetEnvAttr sets attributes that govern aspects of environments.  

***  

[SQLTables](libraries/odbc32/SQLTables.md)  
Returns the list of table, catalog, or schema names, and table types, stored in a specific data source. The driver returns the information as a result set.  

***  

[WNetGetLastError](libraries/odbc32/WNetGetLastError.md)  
The WNetGetLastError function retrieves the most recent extended error code set by a WNet function.   

***  

</details>
<a name="odbccp32" />

# ![](images/fox1.png) Library: odbccp32
<details>

***  

[SQLInstallerError](libraries/odbccp32/SQLInstallerError.md)  
SQLInstallerError returns error or status information for the ODBC installer functions.  

***  

</details>
<a name="ole32" />

# ![](images/fox1.png) Library: ole32
<details>

***  

[CLSIDFromString](libraries/ole32/CLSIDFromString.md)  
Converts a string generated by the StringFromCLSID function back into the original CLSID.  

***  

[CoCreateGuid](libraries/ole32/CoCreateGuid.md)  
Creates a GUID, a unique 128-bit integer used for CLSIDs and interface identifiers.  

***  

[CoTaskMemFree](libraries/ole32/CoTaskMemFree.md)  
Frees a block of task memory previously allocated through a call to the CoTaskMemAlloc or CoTaskMemRealloc function.  

***  

[CreateStreamOnHGlobal](libraries/ole32/CreateStreamOnHGlobal.md)  
The CreateStreamOnHGlobal function creates a stream object stored in global memory.  

***  

[GetHGlobalFromStream](libraries/ole32/GetHGlobalFromStream.md)  
The GetHGlobalFromStream function retrieves the global memory handle to a stream that was created through a call to the CreateStreamOnHGlobal function.  

***  

[StringFromGUID2](libraries/ole32/StringFromGUID2.md)  
Converts a globally unique identifier (GUID) into a string of printable characters.  

***  

</details>
<a name="powrprof" />

# ![](images/fox1.png) Library: powrprof
<details>

***  

[GetPwrCapabilities](libraries/powrprof/GetPwrCapabilities.md)  
The GetPwrCapabilities function retrieves information about the system power capabilities.  

***  

[IsPwrSuspendAllowed](libraries/powrprof/IsPwrSuspendAllowed.md)  
Determines whether the computer supports the sleep states.  

***  

[SetSuspendState](libraries/powrprof/SetSuspendState.md)  
The SetSuspendState function suspends the system by shutting power down. Depending on the Hibernate parameter, the system either enters a suspend (sleep) state or hibernation (S4).  

***  

</details>
<a name="psapi" />

# ![](images/fox1.png) Library: psapi
<details>

***  

[EnumDeviceDrivers](libraries/psapi/EnumDeviceDrivers.md)  
The EnumDeviceDrivers function retrieves the load address for each device driver in the system.  

***  

[EnumProcesses](libraries/psapi/EnumProcesses.md)  
The EnumProcesses function retrieves the process identifier for each process object in the system.  

***  

[EnumProcessModules](libraries/psapi/EnumProcessModules.md)  
The EnumProcessModules function retrieves a handle for each module in the specified process.  

***  

[GetDeviceDriverBaseName](libraries/psapi/GetDeviceDriverBaseName.md)  
The GetDeviceDriverBaseName function retrieves the base name of the specified device driver.  

***  

[GetDeviceDriverFileName](libraries/psapi/GetDeviceDriverFileName.md)  
The GetDeviceDriverFileName function retrieves the fully qualified path for the specified device driver.  

***  

[GetModuleBaseName](libraries/psapi/GetModuleBaseName.md)  
The GetModuleBaseName function retrieves the base name of the specified module.  

***  

[GetModuleFileNameEx](libraries/psapi/GetModuleFileNameEx.md)  
The GetModuleFileNameEx function retrieves the fully qualified path for the specified module.  

***  

[GetPerformanceInfo](libraries/psapi/GetPerformanceInfo.md)  
Retrieves the performance values contained in the PERFORMANCE_INFORMATION structure.  

***  

[GetProcessMemoryInfo](libraries/psapi/GetProcessMemoryInfo.md)  
Retrieves information about the memory usage of the specified process in the PROCESS_MEMORY_COUNTERS structure.  

***  

</details>
<a name="rapi" />

# ![](images/fox1.png) Library: rapi
<details>

***  

[CeCloseHandle](libraries/rapi/CeCloseHandle.md)  
This function closes an open object handle.  

***  

[CeCopyFile](libraries/rapi/CeCopyFile.md)  
This function copies an existing file to a new file.  

***  

[CeCreateDatabase](libraries/rapi/CeCreateDatabase.md)  
This function creates a new database.  

***  

[CeCreateDirectory](libraries/rapi/CeCreateDirectory.md)  
This function creates a new directory.  

***  

[CeCreateFile](libraries/rapi/CeCreateFile.md)  
This function creates, opens, or truncates a file, pipe, communications resource, disk device, or console. It returns a handle that can be used to access the object. It can also open and return a handle to a directory.  

***  

[CeCreateProcess](libraries/rapi/CeCreateProcess.md)  
This function is used to run a new program. It creates a new process and its primary thread. The new process executes the specified executable file.  

***  

[CeDeleteDatabase](libraries/rapi/CeDeleteDatabase.md)  
This function removes a database from the object store.  

***  

[CeDeleteFile](libraries/rapi/CeDeleteFile.md)  
This function deletes an existing file from the object store.  

***  

[CeDeleteRecord](libraries/rapi/CeDeleteRecord.md)  
This function deletes a record from a database.  

***  

[CeEnumDBVolumes](libraries/rapi/CeEnumDBVolumes.md)  
This function enumerates all mounted database volumes and returns the name for each.   

***  

[CeFindAllFiles](libraries/rapi/CeFindAllFiles.md)  
This function retrieves information about all files and directories in the given directory of the Windows CE object store.   

***  

[CeFindFirstDatabaseEx](libraries/rapi/CeFindFirstDatabaseEx.md)  
This function opens an enumeration context for all databases in a database volume.   

***  

[CeFindFirstFile](libraries/rapi/CeFindFirstFile.md)  
This function searches a directory for a file whose name matches the specified filename. CeFindFirstFile examines subdirectory names as well as filenames.  

***  

[CeFindNextDatabaseEx](libraries/rapi/CeFindNextDatabaseEx.md)  
This function retrieves the next database in an enumeration context.  

***  

[CeGetFileSize](libraries/rapi/CeGetFileSize.md)  
This function retrieves the size, in bytes, of the specified file.  

***  

[CeGetLastError](libraries/rapi/CeGetLastError.md)  
This function returns the calling thread"s last-error code value.   

***  

[CeGetSpecialFolderPath](libraries/rapi/CeGetSpecialFolderPath.md)  
This function gets the path to a special shell folder.  

***  

[CeGetStoreInformation](libraries/rapi/CeGetStoreInformation.md)  
This function fills in a STORE_INFORMATION structure with the size of the object store and the amount of free space currently in the object store.   

***  

[CeGetSystemInfo](libraries/rapi/CeGetSystemInfo.md)  
This function returns information about the current system.   

***  

[CeGetSystemPowerStatusEx](libraries/rapi/CeGetSystemPowerStatusEx.md)  
This function retrieves the power status of the system.  

***  

[CeGetTempPath](libraries/rapi/CeGetTempPath.md)  
This function gets the path to the directory designated for temporary files.   

***  

[CeGetVersionEx](libraries/rapi/CeGetVersionEx.md)  
This function obtains extended information about the version of the operating system that is currently running.   

***  

[CeGlobalMemoryStatus](libraries/rapi/CeGlobalMemoryStatus.md)  
This function gets information on the physical and virtual memory of the system.  

***  

[CeMoveFile](libraries/rapi/CeMoveFile.md)  
This function renames an existing file or a directory � including all its children.  

***  

[CeOidGetInfoEx](libraries/rapi/CeOidGetInfoEx.md)  
This function retrieves information about an object in the object store or a mounted database volume.   

***  

[CeOpenDatabase](libraries/rapi/CeOpenDatabase.md)  
This function opens an existing database on any database volume, including mounted databases.   

***  

[CeRapiFreeBuffer](libraries/rapi/CeRapiFreeBuffer.md)  
This function frees the memory on the desktop computer allocated by a call to CeFindAllDatabases, CeFindAllFiles, or CeReadRecordProps.   

***  

[CeRapiGetError](libraries/rapi/CeRapiGetError.md)  
This function reports remote API related failures. CeRapiGetError can be used to determine if a call failed due to a failure in the remote API.   

***  

[CeRapiInit](libraries/rapi/CeRapiInit.md)  
This function attempts to initialize the Windows CE remote application programming interface (RAPI).  

***  

[CeRapiInitEx](libraries/rapi/CeRapiInitEx.md)  
This function attempts to initialize the Windows CE remote application programming interface (RAPI) and initially returns an event handle.  

***  

[CeRapiInvoke](libraries/rapi/CeRapiInvoke.md)  
This function can be used as a general-purpose mechanism to remotely execute a routine on the Windows CE device.  

***  

[CeRapiUninit](libraries/rapi/CeRapiUninit.md)  
This function uninitializes the Windows CE remote application programming interface (RAPI).   

***  

[CeReadFile](libraries/rapi/CeReadFile.md)  
This function reads data from a file, starting at the position indicated by the file pointer.   

***  

[CeReadRecordProps](libraries/rapi/CeReadRecordProps.md)  
This function reads properties from the current record.  

***  

[CeRegCloseKey](libraries/rapi/CeRegCloseKey.md)  
This function releases the handle of the specified key.  

***  

[CeRegCreateKeyEx](libraries/rapi/CeRegCreateKeyEx.md)  
This function creates the specified key. If the key already exists in the registry, the function opens it.   

***  

[CeRegDeleteKey](libraries/rapi/CeRegDeleteKey.md)  
This function deletes a named subkey from the specified registry key. The subkey to be deleted cannot have any subkeys.  

***  

[CeRegDeleteValue](libraries/rapi/CeRegDeleteValue.md)  
This function removes a named value from the specified registry key.   

***  

[CeRegEnumKeyEx](libraries/rapi/CeRegEnumKeyEx.md)  
This function enumerates subkeys of the specified open registry key.   

***  

[CeRegEnumValue](libraries/rapi/CeRegEnumValue.md)  
This function enumerates the values for the specified open registry key. CeRegEnumValue copies one indexed value name and data block for the key each time it is called.  

***  

[CeRegOpenKeyEx](libraries/rapi/CeRegOpenKeyEx.md)  
This function opens the specified key.  

***  

[CeRegQueryInfoKey](libraries/rapi/CeRegQueryInfoKey.md)  
This function retrieves information about a specified registry key.  

***  

[CeRegQueryValueEx](libraries/rapi/CeRegQueryValueEx.md)  
This function retrieves the type and data for a specified value name associated with an open registry key.   

***  

[CeRegSetValueEx](libraries/rapi/CeRegSetValueEx.md)  
This function stores data in the value field of an open registry key. It can also set additional value and type information for the specified key.   

***  

[CeRemoveDirectory](libraries/rapi/CeRemoveDirectory.md)  
This function deletes an existing empty directory.  

***  

[CeSeekDatabase](libraries/rapi/CeSeekDatabase.md)  
This function seeks the specified record in an open database.  

***  

[CeSetFilePointer](libraries/rapi/CeSetFilePointer.md)  
This function moves the file pointer of an open file.  

***  

[CeWriteFile](libraries/rapi/CeWriteFile.md)  
This function writes data to a file on remote Windows CE device.  

***  

[CeWriteRecordProps](libraries/rapi/CeWriteRecordProps.md)  
This function writes a set of properties to a single record, creating the record if necessary.  

***  

</details>
<a name="rasapi32" />

# ![](images/fox1.png) Library: rasapi32
<details>

***  

[RasEnumAutodialAddresses](libraries/rasapi32/RasEnumAutodialAddresses.md)  
The RasEnumAutodialAddresses function returns a list of all addresses in the AutoDial mapping database.  

***  

[RasEnumConnections](libraries/rasapi32/RasEnumConnections.md)  
The RasEnumConnections function lists all active RAS connections. It returns each connection"s handle and phone-book entry name.   

***  

[RasEnumDevices](libraries/rasapi32/RasEnumDevices.md)  
The RasEnumDevices function returns the name and type of all available RAS-capable devices.  

***  

[RasGetCountryInfo](libraries/rasapi32/RasGetCountryInfo.md)  
The RasGetCountryInfo function retrieves country-specific dialing information from the Windows Telephony list of countries.  

***  

</details>
<a name="rasdlg" />

# ![](images/fox1.png) Library: rasdlg
<details>

***  

[RasPhonebookDlg](libraries/rasdlg/RasPhonebookDlg.md)  
The RasPhonebookDlg function displays the main Dial-Up Networking dialog box. From this modal dialog box, the user can dial, edit, or delete a selected phone-book entry, create a new phone-book entry, or specify user preferences. The RasPhonebookDlg function returns when the dialog box closes.  

***  

</details>
<a name="rpcrt4" />

# ![](images/fox1.png) Library: rpcrt4
<details>

***  

[RpcStringFree](libraries/rpcrt4/RpcStringFree.md)  
Frees a character string allocated by the RPC run-time library.  

***  

[UuidCompare](libraries/rpcrt4/UuidCompare.md)  
Compare two UUIDs and determine their order. The returned value gives the order.  

***  

[UuidCreate](libraries/rpcrt4/UuidCreate.md)  
Creates a new UUID.  

***  

[UuidCreateNil](libraries/rpcrt4/UuidCreateNil.md)  
Creates a nil-valued UUID.  

***  

[UuidCreateSequential](libraries/rpcrt4/UuidCreateSequential.md)  
Creates a new UUID.  

***  

[UuidFromString](libraries/rpcrt4/UuidFromString.md)  
Converts a string to a UUID.  

***  

[UuidToString](libraries/rpcrt4/UuidToString.md)  
Converts a UUID to a string.  

***  

</details>
<a name="secur32" />

# ![](images/fox1.png) Library: secur32
<details>

***  

[GetComputerObjectName](libraries/secur32/GetComputerObjectName.md)  
The GetComputerObjectName function retrieves the local computer"s name in a specified format.  

***  

[GetUserNameEx](libraries/secur32/GetUserNameEx.md)  
Retrieves the name of the user or other security principal associated with the calling thread. You can specify the format of the returned name.  

***  

[LsaEnumerateLogonSessions](libraries/secur32/LsaEnumerateLogonSessions.md)  
Retrieves the set of existing logon session identifiers (LUIDs) and the number of sessions.
  

***  

[LsaFreeReturnBuffer](libraries/secur32/LsaFreeReturnBuffer.md)  
Frees the memory used by a buffer previously allocated by the LSA.  

***  

[LsaGetLogonSessionData](libraries/secur32/LsaGetLogonSessionData.md)  
Retrieves information about a specified logon session.  

***  

</details>
<a name="sensapi" />

# ![](images/fox1.png) Library: sensapi
<details>

***  

[IsNetworkAlive](libraries/sensapi/IsNetworkAlive.md)  
The IsNetworkAlive function determines whether the local system is connected to a network and the type of network connection. For example, whether the local system has connectivity to a LAN, WAN, or both networks.  

***  

</details>
<a name="setupapi" />

# ![](images/fox1.png) Library: setupapi
<details>

***  

[AddPort](libraries/setupapi/AddPort.md)  
Adds the name of a port to the list of supported ports. The AddPort function is exported by the port monitor.  

***  

[CM_Request_Device_Eject_Ex](libraries/setupapi/CM_Request_Device_Eject_Ex.md)  
Prepares a local or a remote device instance for safe removal, if the device is removable.  

***  

[SetupCloseInfFile](libraries/setupapi/SetupCloseInfFile.md)  
Closes the INF file opened by a call to SetupOpenInfFile and any INF files appended to it by SetupOpenAppendInfFile.  

***  

[SetupDiDestroyClassImageList](libraries/setupapi/SetupDiDestroyClassImageList.md)  
Destroys a class image list that was built by a call to SetupDiGetClassImageList or SetupDiGetClassImageListEx.
  

***  

[SetupDiGetClassImageIndex](libraries/setupapi/SetupDiGetClassImageIndex.md)  
Retrieves the index within the class image list of a specified class.  

***  

[SetupDiGetClassImageListEx](libraries/setupapi/SetupDiGetClassImageListEx.md)  
Builds an image list of bitmaps for every class installed on a local or remote system.
  

***  

[SetupGetInfFileList](libraries/setupapi/SetupGetInfFileList.md)  
Returns a list of INF files located in a caller-specified directory to a call-supplied buffer.  

***  

[SetupGetInfInformation](libraries/setupapi/SetupGetInfInformation.md)  
Returns the SP_INF_INFORMATION structure for the specified INF file to a caller-supplied buffer.
  

***  

[SetupOpenInfFile](libraries/setupapi/SetupOpenInfFile.md)  
The SetupOpenInfFile function opens an INF file and returns a handle to it.  

***  

</details>
<a name="shell32" />

# ![](images/fox1.png) Library: shell32
<details>

***  

[CommandLineToArgvW](libraries/shell32/CommandLineToArgvW.md)  
Parses a Unicode command-line string, and returns a pointer to a set of Unicode argument strings and a count of arguments, similar to the standard C run-time argv and argc values  

***  

[DllGetVersion](libraries/shell32/DllGetVersion.md)  
Implemented by many of the Microsoft&reg; Windows&reg; Shell dynamic-link libraries (DLLs) to allow applications to obtain DLL-specific version information.  

***  

[DragFinish](libraries/shell32/DragFinish.md)  
Releases memory that the system allocated for use in transferring file names to the application.  

***  

[DragQueryFile](libraries/shell32/DragQueryFile.md)  
Retrieves the names of dropped files that result from a successful drag-and-drop operation.  

***  

[DragQueryPoint](libraries/shell32/DragQueryPoint.md)  
Retrieves the position of the mouse pointer at the time a file was dropped during a drag-and-drop operation.  

***  

[ExtractAssociatedIcon](libraries/shell32/ExtractAssociatedIcon.md)  
The ExtractAssociatedIcon function returns a handle to an indexed icon found in a file or an icon found in an associated executable file.  

***  

[ExtractIcon](libraries/shell32/ExtractIcon.md)  
Retrieves a handle to an icon from the specified executable file, dynamic-link library (DLL), or icon file.  

***  

[FileIconInit](libraries/shell32/FileIconInit.md)  
Reinitializes the system image list.  

***  

[FindExecutable](libraries/shell32/FindExecutable.md)  
Retrieves the name of and handle to the executable (.exe) file associated with the specified file name.  

***  

[GetFileNameFromBrowse](libraries/shell32/GetFileNameFromBrowse.md)  
This function creates an Open dialog box that lets the user specify the drive, directory, and name of a file to open.   

***  

[IsUserAnAdmin](libraries/shell32/IsUserAnAdmin.md)  
Tests whether the current user is a member of the Administrator"s group.  

***  

[PathGetShortPath](libraries/shell32/PathGetShortPath.md)  
Retrieves the short path form of a specified input path.
  

***  

[PathMakeUniqueName](libraries/shell32/PathMakeUniqueName.md)  
Creates a unique path name from a template.  

***  

[PathYetAnotherMakeUniqueName](libraries/shell32/PathYetAnotherMakeUniqueName.md)  
Creates a unique filename based on an existing filename.  

***  

[RealDriveType](libraries/shell32/RealDriveType.md)  
Determines the drive type based on the drive number.  

***  

[RestartDialog](libraries/shell32/RestartDialog.md)  
Displays a dialog box that prompts the user to restart Microsoft&reg; Windows&reg;. When the user clicks the button, the function calls ExitWindowsEx to attempt to restart Windows.  

***  

[SHAddToRecentDocs](libraries/shell32/SHAddToRecentDocs.md)  
Adds a document to the Shell"s list of recently used documents or clears all documents from the list.  

***  

[SHBrowseForFolder](libraries/shell32/SHBrowseForFolder.md)  
Displays a dialog box that enables the user to select a Shell folder.   

***  

[SHCreateDirectory](libraries/shell32/SHCreateDirectory.md)  
Creates a folder.  

***  

[ShellAbout](libraries/shell32/ShellAbout.md)  
Displays a Shell About dialog box  

***  

[ShellExecute](libraries/shell32/ShellExecute.md)  
Performs an operation on a specified file.  

***  

[ShellExecuteEx](libraries/shell32/ShellExecuteEx.md)  
Performs an action on a file.  

***  

[Shell_GetImageLists](libraries/shell32/Shell_GetImageLists.md)  
Retrieves system image lists for large and small icons -- undocumented.  

***  

[Shell_NotifyIcon](libraries/shell32/Shell_NotifyIcon.md)  
Sends a message to the taskbar"s status area.  

***  

[SHEmptyRecycleBin](libraries/shell32/SHEmptyRecycleBin.md)  
Empties the Recycle Bin on the specified drive.   

***  

[SHFileOperation](libraries/shell32/SHFileOperation.md)  
Copies, moves, renames, or deletes a file system object.  

***  

[SHFormatDrive](libraries/shell32/SHFormatDrive.md)  
The SHFormatDrive API provides access to the Shell"s format dialog box. This allows applications that want to format disks to bring up the same dialog box that the Shell uses for disk formatting.
  

***  

[SHGetFileInfo](libraries/shell32/SHGetFileInfo.md)  
Retrieves information about an object in the file system, such as a file, a folder, a directory, or a drive root.
  

***  

[SHGetFolderPath](libraries/shell32/SHGetFolderPath.md)  
Takes the CSIDL of a folder and returns the pathname.  

***  

[SHGetPathFromIDList](libraries/shell32/SHGetPathFromIDList.md)  
Converts an item identifier list to a file system path. 
  

***  

[SHGetSpecialFolderLocation](libraries/shell32/SHGetSpecialFolderLocation.md)  
Retrieves a pointer to the ITEMIDLIST structure of a special folder.  

***  

[SHGetStockIconInfo](libraries/shell32/SHGetStockIconInfo.md)  
Retrieves information about system-defined Shell icons.  

***  

[SHParseDisplayName](libraries/shell32/SHParseDisplayName.md)  
Translates a Shell namespace object"s display name into an item identifier list and returns the attributes of the object. This function is the preferred method to convert a string to a pointer to an item identifier list (PIDL).  

***  

[SHQueryRecycleBin](libraries/shell32/SHQueryRecycleBin.md)  
Retrieves the size of the Recycle Bin, and the number of items in it, on the specified drive.   

***  

[SHSimpleIDListFromPath](libraries/shell32/SHSimpleIDListFromPath.md)  
Returns a pointer to an ITEMIDLIST structure when passed a path.  

***  

</details>
<a name="shlwapi" />

# ![](images/fox1.png) Library: shlwapi
<details>

***  

[AssocQueryString](libraries/shlwapi/AssocQueryString.md)  
Searches for and retrieves a file or protocol association-related string from the registry.  

***  

[ChrCmpI](libraries/shlwapi/ChrCmpI.md)  
Performs a comparison between two characters. The comparison is not case sensitive.  

***  

[DllInstall](libraries/shlwapi/DllInstall.md)  
Handles installation and setup for a dynamic-link library (DLL).   

***  

[HashData](libraries/shlwapi/HashData.md)  
Hashes an array of data.  

***  

[PathBuildRoot](libraries/shlwapi/PathBuildRoot.md)  
Creates a root path from a given drive number.  

***  

[PathCombine](libraries/shlwapi/PathCombine.md)  
Concatenates two strings that represent properly formed paths into one path; also concatenates any relative path elements.  

***  

[PathCompactPathEx](libraries/shlwapi/PathCompactPathEx.md)  
Truncates a path to fit within a certain number of characters by replacing path components with ellipses.  

***  

[PathFileExists](libraries/shlwapi/PathFileExists.md)  
Determines whether a path to a file system object such as a file or directory is valid.  

***  

[PathFindExtension](libraries/shlwapi/PathFindExtension.md)  
Searches a path for an extension.  

***  

[PathFindFileName](libraries/shlwapi/PathFindFileName.md)  
Searches a path for a file name.  

***  

[PathGetDriveNumber](libraries/shlwapi/PathGetDriveNumber.md)  
Searches a path for a drive letter within the range of "A" to "Z" and returns the corresponding drive number.  

***  

[PathIsDirectory](libraries/shlwapi/PathIsDirectory.md)  
Verifies that a path is a valid directory.  

***  

[PathIsNetworkPath](libraries/shlwapi/PathIsNetworkPath.md)  
Determines whether a path string represents a network resource.  

***  

[PathIsRelative](libraries/shlwapi/PathIsRelative.md)  
Searches a path and determines if it is relative.  

***  

[PathIsRoot](libraries/shlwapi/PathIsRoot.md)  
Parses a path to determine if it is a directory root.  

***  

[PathIsURL](libraries/shlwapi/PathIsURL.md)  
Tests a given string to determine if it conforms to a valid URL format.  

***  

[PathRenameExtension](libraries/shlwapi/PathRenameExtension.md)  
Replaces the extension of a file name with a new extension.  

***  

[PathSearchAndQualify](libraries/shlwapi/PathSearchAndQualify.md)  
Determines if a given path is correctly formatted and fully qualified.  

***  

[SHEnumKeyEx](libraries/shlwapi/SHEnumKeyEx.md)  
Enumerates the subkeys of the specified open registry key.  

***  

[SHRegCloseUSKey](libraries/shlwapi/SHRegCloseUSKey.md)  
Closes a handle to a user-specific registry key.  

***  

[SHRegEnumUSKey](libraries/shlwapi/SHRegEnumUSKey.md)  
Enumerates the subkeys of a user-specific key.  

***  

[SHRegOpenUSKey](libraries/shlwapi/SHRegOpenUSKey.md)  
Opens a user-specific registry key.  

***  

[StrCmpC](libraries/shlwapi/StrCmpC.md)  
Compares strings using C run-time (ASCII) collation rules. The comparison is case-sensitive.  

***  

[StrCpy](libraries/shlwapi/StrCpy.md)  
Copies one string to another.  

***  

[StrDup](libraries/shlwapi/StrDup.md)  
Duplicates a string.  

***  

[StrFormatByteSize](libraries/shlwapi/StrFormatByteSize.md)  
Converts a numeric value into a string that represents the number expressed as a size value in bytes, kilobytes, megabytes, or gigabytes, depending on the size.  

***  

[StrFromTimeInterval](libraries/shlwapi/StrFromTimeInterval.md)  
Converts a time interval, specified in milliseconds, to a string.  

***  

[StrToInt](libraries/shlwapi/StrToInt.md)  
Converts a decimal string to an integer. The StrToLong macro differs from this function in name only.  

***  

[StrToIntEx](libraries/shlwapi/StrToIntEx.md)  
Converts a decimal or hexadecimal string to an integer.  

***  

[StrTrim](libraries/shlwapi/StrTrim.md)  
Removes (trims) specified leading and trailing characters from a string.  

***  

[UrlEscape](libraries/shlwapi/UrlEscape.md)  
Converts characters in a URL that might be altered during transport across the Internet ("unsafe" characters) into their corresponding escape sequences.  

***  

[UrlGetPart](libraries/shlwapi/UrlGetPart.md)  
Accepts a URL string and returns a specified part of that URL.  

***  

[UrlHash](libraries/shlwapi/UrlHash.md)  
Hashes a URL string.  

***  

[UrlUnescape](libraries/shlwapi/UrlUnescape.md)  
Converts escape sequences back into ordinary characters.  

***  

[wnsprintf](libraries/shlwapi/wnsprintf.md)  
Takes a variable-length argument list and returns the values of the arguments as a printf-style formatted string.   

***  

</details>
<a name="urlmon" />

# ![](images/fox1.png) Library: urlmon
<details>

***  

[CreateURLMonikerEx](libraries/urlmon/CreateURLMonikerEx.md)  
Creates a URL moniker from a full URL, or from a base context URL moniker and a partial URL.  

***  

[FindMediaType](libraries/urlmon/FindMediaType.md)  
Retrieves the 32-bit value assigned to the specified media type.  

***  

[InetIsOffline](libraries/urlmon/InetIsOffline.md)  
Determines whether or not the system is connected to the Internet.  

***  

[IsValidURL](libraries/urlmon/IsValidURL.md)  
Determines if a specified string is a valid URL.  

***  

[ObtainUserAgentString](libraries/urlmon/ObtainUserAgentString.md)  
Retrieves the user agent string in use.  

***  

[URLDownloadToCacheFile](libraries/urlmon/URLDownloadToCacheFile.md)  
Downloads data into the Internet cache and returns the file name of the cache location for retrieving the bits.  

***  

[URLDownloadToFile](libraries/urlmon/URLDownloadToFile.md)  
Downloads bits from the Internet and saves them to a file.  

***  

[UrlMkGetSessionOption](libraries/urlmon/UrlMkGetSessionOption.md)  
Retrieves options for the current Internet session.  

***  

</details>
<a name="user32" />

# ![](images/fox1.png) Library: user32
<details>

***  

[ActivateKeyboardLayout](libraries/user32/ActivateKeyboardLayout.md)  
The ActivateKeyboardLayout function sets the input locale identifier (formerly called the keyboard layout handle) for the calling thread or the current process. The input locale identifier specifies a locale as well as the physical layout of the keyboard.  

***  

[AddClipboardFormatListener](libraries/user32/AddClipboardFormatListener.md)  
Places the given window in the system-maintained clipboard format listener list.  

***  

[AppendMenu](libraries/user32/AppendMenu.md)  
The AppendMenu function appends a new item to the end of the specified menu bar, drop-down menu, submenu, or shortcut menu.  

***  

[BlockInput](libraries/user32/BlockInput.md)  
Blocks keyboard and mouse input events from reaching applications.  

***  

[BringWindowToTop](libraries/user32/BringWindowToTop.md)  
Brings the specified window to the top of the Z order. If the window is a top-level window, it is activated. If the window is a child window, the top-level parent window associated with the child window is activated.  

***  

[BroadcastSystemMessage](libraries/user32/BroadcastSystemMessage.md)  
Sends a message to the specified recipients. The recipients can be applications, installable drivers, network drivers, system-level device drivers, or any combination of these system components.  

***  

[CallWindowProc](libraries/user32/CallWindowProc.md)  
The CallWindowProc function passes message information to the specified window procedure.  

***  

[ChangeClipboardChain](libraries/user32/ChangeClipboardChain.md)  
Removes a specified window from the chain of clipboard viewers.  

***  

[ChangeDisplaySettings](libraries/user32/ChangeDisplaySettings.md)  
The ChangeDisplaySettings function changes the settings of the default display device to the specified graphics mode.   

***  

[CharLower](libraries/user32/CharLower.md)  
Converts a character string or a single character to lowercase. If the operand is a character string, the function converts the characters in place.  

***  

[CharToOem](libraries/user32/CharToOem.md)  
Translates a string into the OEM-defined character set.
  

***  

[CharUpper](libraries/user32/CharUpper.md)  
Converts a character string or a single character to uppercase. If the operand is a character string, the function converts the characters in place.  

***  

[ClipCursor](libraries/user32/ClipCursor.md)  
Confines the cursor to a rectangular area on the screen.  

***  

[CloseClipboard](libraries/user32/CloseClipboard.md)  
Closes the clipboard.  

***  

[CloseDesktop](libraries/user32/CloseDesktop.md)  
Closes an open handle to a desktop object.  

***  

[CloseWindow](libraries/user32/CloseWindow.md)  
The CloseWindow function minimizes (but does not destroy) the specified window.  

***  

[CopyIcon](libraries/user32/CopyIcon.md)  
Copies the specified icon from another module to the current module.  

***  

[CopyImage](libraries/user32/CopyImage.md)  
Creates a new image (icon, cursor, or bitmap) and copies the attributes of the specified image to the new one. If necessary, the function stretches the bits to fit the desired size of the new image.  

***  

[CountClipboardFormats](libraries/user32/CountClipboardFormats.md)  
The CountClipboardFormats function retrieves the number of different data formats currently on the clipboard  

***  

[CreateDesktop](libraries/user32/CreateDesktop.md)  
Creates a new desktop, associates it with the current window station of the calling process, and assigns it to the calling thread.  

***  

[CreateMenu](libraries/user32/CreateMenu.md)  
The CreateMenu function creates a menu. The menu is initially empty, but it can be filled with menu items by using the InsertMenuItem, AppendMenu, and InsertMenu functions.  

***  

[CreatePopupMenu](libraries/user32/CreatePopupMenu.md)  
The CreatePopupMenu function creates a drop-down menu, submenu, or shortcut menu. 

The menu is initially empty. You can insert or append menu items by using the InsertMenuItem function. You can also use the InsertMenu function to insert menu items and the AppendMenu function to append menu items.  

***  

[CreateWindow](libraries/user32/CreateWindow.md)  
The CreateWindow function creates an overlapped, pop-up, or child window.

To use extended window styles in addition to the styles supported by CreateWindow, use the CreateWindowEx function.  

***  

[CreateWindowEx](libraries/user32/CreateWindowEx.md)  
Creates an overlapped, pop-up, or child window with an extended window style; otherwise, this function is identical to the CreateWindow function  

***  

[DefWindowProc](libraries/user32/DefWindowProc.md)  
The DefWindowProc function calls the default window procedure to provide default processing for any window messages that an application does not process. This function ensures that every message is processed. DefWindowProc is called with the same parameters received by the window procedure.   

***  

[DeleteMenu](libraries/user32/DeleteMenu.md)  
Deletes an item from the specified menu. If the menu item opens a menu or submenu, this function destroys the handle to the menu or submenu and frees the memory used by the menu or submenu.  

***  

[DestroyIcon](libraries/user32/DestroyIcon.md)  
Destroys an icon and frees any memory the icon occupied.  

***  

[DestroyMenu](libraries/user32/DestroyMenu.md)  
The DestroyMenu function destroys the specified menu and frees any memory that the menu occupies.  

***  

[DestroyWindow](libraries/user32/DestroyWindow.md)  
The DestroyWindow function destroys the specified window. The function sends WM_DESTROY and WM_NCDESTROY messages to the window to deactivate it and remove the keyboard focus from it.  

***  

[DragAcceptFiles](libraries/user32/DragAcceptFiles.md)  
Registers whether a window accepts dropped files.  

***  

[DragDetect](libraries/user32/DragDetect.md)  
The DragDetect function captures the mouse and tracks its movement until the user releases the left button, presses the ESC key, or moves the mouse outside the drag rectangle around the specified point.  

***  

[DrawAnimatedRects](libraries/user32/DrawAnimatedRects.md)  
The DrawAnimatedRects function draws a wire-frame rectangle and animates it to indicate the opening of an icon or the minimizing or maximizing of a window.  

***  

[DrawCaption](libraries/user32/DrawCaption.md)  
The DrawCaption function draws a window caption.  

***  

[DrawEdge](libraries/user32/DrawEdge.md)  
The DrawEdge function draws one or more edges of rectangle.  

***  

[DrawFrameControl](libraries/user32/DrawFrameControl.md)  
The DrawFrameControl function draws a frame control of the specified type and style.  

***  

[DrawIcon](libraries/user32/DrawIcon.md)  
Draws an icon or cursor into the specified device context.  

***  

[DrawMenuBar](libraries/user32/DrawMenuBar.md)  
Redraws the menu bar of the specified window. If the menu bar changes after the system has created the window, this function must be called to draw the changed menu bar.  

***  

[DrawText](libraries/user32/DrawText.md)  
The DrawText function draws formatted text in the specified rectangle. It formats the text according to the specified method (expanding tabs, justifying characters, breaking lines, and so forth).   

***  

[EmptyClipboard](libraries/user32/EmptyClipboard.md)  
The EmptyClipboard function empties the clipboard and frees handles to data in the clipboard  

***  

[EnableWindow](libraries/user32/EnableWindow.md)  
Enables or disables mouse and keyboard input to the specified window or control.  

***  

[EndTask](libraries/user32/EndTask.md)  
The EndTask function is called to forcibly close a specified window.  

***  

[EnumClipboardFormats](libraries/user32/EnumClipboardFormats.md)  
The EnumClipboardFormats function lets you enumerate the data formats that are currently available on the clipboard  

***  

[EnumDisplayDevices](libraries/user32/EnumDisplayDevices.md)  
The EnumDisplayDevices function lets you obtain information about the display devices in a system.   

***  

[EnumDisplaySettings](libraries/user32/EnumDisplaySettings.md)  
The EnumDisplaySettings function retrieves information about one of the graphics modes for a display device. To retrieve information for all the graphics modes of a display device, make a series of calls to this function.  

***  

[ExitWindows](libraries/user32/ExitWindows.md)  
Logs the current user off  

***  

[ExitWindowsEx](libraries/user32/ExitWindowsEx.md)  
Either logs off, shuts down, or shuts down and restarts the system  

***  

[FindWindow](libraries/user32/FindWindow.md)  
Retrieves a handle to the top-level window whose class name and window name match the specified strings.  

***  

[FindWindowEx](libraries/user32/FindWindowEx.md)  
Retrieves a handle to a window whose class name and window name match the specified strings. The function searches child windows, beginning with the one following the specified child window.  

***  

[FlashWindow](libraries/user32/FlashWindow.md)  
Flashes the specified window one time. It does not change the active state of the window  

***  

[FlashWindowEx](libraries/user32/FlashWindowEx.md)  
The FlashWindowEx function flashes the specified window. It does not change the active state of the window.  

***  

[GetActiveWindow](libraries/user32/GetActiveWindow.md)  
The GetActiveWindow function retrieves the window handle to the active window attached to the calling thread"s message queue.   

***  

[GetAncestor](libraries/user32/GetAncestor.md)  
The GetAncestor function retrieves the handle to the ancestor of the specified window.  

***  

[GetAsyncKeyState](libraries/user32/GetAsyncKeyState.md)  
The GetAsyncKeyState function determines whether a key is up or down at the time the function is called, and whether the key was pressed after a previous call to GetAsyncKeyState.   

***  

[GetCapture](libraries/user32/GetCapture.md)  
The GetCapture function retrieves a handle to the window (if any) that has captured the mouse. Only one window at a time can capture the mouse; this window receives mouse input whether or not the cursor is within its borders.   

***  

[GetClassInfo](libraries/user32/GetClassInfo.md)  
The GetClassInfo function retrieves information about a window class.   

***  

[GetClassInfoEx](libraries/user32/GetClassInfoEx.md)  
The GetClassInfoEx function retrieves information about a window class, including a handle to the small icon associated with the window class.  

***  

[GetClassLong](libraries/user32/GetClassLong.md)  
Retrieves the specified 32-bit (long) value from the WNDCLASSEX structure associated with the specified window.  

***  

[GetClassName](libraries/user32/GetClassName.md)  
The GetClassName function retrieves the name of the class to which the specified window belongs.  

***  

[GetClientRect](libraries/user32/GetClientRect.md)  
Retrieves the coordinates of a window"s client area.  

***  

[GetClipboardData](libraries/user32/GetClipboardData.md)  
The GetClipboardData function retrieves data from the clipboard in a specified format. The clipboard must have been opened previously.  

***  

[GetClipboardFormatName](libraries/user32/GetClipboardFormatName.md)  
The GetClipboardFormatName function retrieves from the clipboard the name of the specified registered format. The function copies the name to the specified buffer.   

***  

[GetClipboardOwner](libraries/user32/GetClipboardOwner.md)  
The GetClipboardOwner function retrieves the window handle of the current owner of the clipboard  

***  

[GetClipboardSequenceNumber](libraries/user32/GetClipboardSequenceNumber.md)  
Retrieves the clipboard sequence number for the current window station.  

***  

[GetClipboardViewer](libraries/user32/GetClipboardViewer.md)  
The GetClipboardViewer function retrieves the handle of the first window in the clipboard viewer chain  

***  

[GetClipCursor](libraries/user32/GetClipCursor.md)  
Retrieves the screen coordinates of the rectangular area to which the cursor is confined.  

***  

[GetCursorInfo](libraries/user32/GetCursorInfo.md)  
Retrieves information about the global cursor.  

***  

[GetCursorPos](libraries/user32/GetCursorPos.md)  
Retrieves the cursor"s position, in screen coordinates.  

***  

[GetDC](libraries/user32/GetDC.md)  
The GetDC function retrieves a handle of a display device context (DC) for the client area of the specified window  

***  

[GetDesktopWindow](libraries/user32/GetDesktopWindow.md)  
The GetDesktopWindow function returns the handle of the Windows desktop window. The desktop window covers the entire screen. The desktop window is the area on top of which all icons and other windows are painted  

***  

[GetDlgCtrlID](libraries/user32/GetDlgCtrlID.md)  
Retrieves the identifier of the specified control.  

***  

[GetDlgItem](libraries/user32/GetDlgItem.md)  
Retrieves a handle to a control in the specified dialog box.   

***  

[GetDoubleClickTime](libraries/user32/GetDoubleClickTime.md)  
Retrieves the current double-click time for the mouse  

***  

[GetFocus](libraries/user32/GetFocus.md)  
Retrieves the handle to the window that has the keyboard focus, if the window is attached to the calling thread"s message queue.  

***  

[GetForegroundWindow](libraries/user32/GetForegroundWindow.md)  
The GetForegroundWindow function returns a handle to the foreground window (the window with which the user is currently working). The system assigns a slightly higher priority to the thread that creates the foreground window than it does to other threads.  

***  

[GetGUIThreadInfo](libraries/user32/GetGUIThreadInfo.md)  
Retrieves information about the active window or a specified graphical user interface (GUI) thread.   

***  

[GetIconInfo](libraries/user32/GetIconInfo.md)  
The GetIconInfo function retrieves information about the specified icon or cursor.  

***  

[GetKBCodePage](libraries/user32/GetKBCodePage.md)  
Returns the current code page.  

***  

[GetKeyboardLayout](libraries/user32/GetKeyboardLayout.md)  
The GetKeyboardLayout function retrieves the active input locale identifier (formerly called the keyboard layout) for the specified thread. If the idThread parameter is zero, the input locale identifier for the active thread is returned.  

***  

[GetKeyboardLayoutList](libraries/user32/GetKeyboardLayoutList.md)  
The GetKeyboardLayoutList function retrieves the input locale identifiers (formerly called keyboard layout handles) corresponding to the current set of input locales in the system.   

***  

[GetKeyboardLayoutName](libraries/user32/GetKeyboardLayoutName.md)  
The GetKeyboardLayoutName function retrieves the name of the active input locale identifier (formerly called the keyboard layout).   

***  

[GetKeyboardState](libraries/user32/GetKeyboardState.md)  
The GetKeyboardState function copies the status of the 256 virtual keys to the specified buffer.  

***  

[GetKeyboardType](libraries/user32/GetKeyboardType.md)  
Retrieves information about the current keyboard.  

***  

[GetKeyNameText](libraries/user32/GetKeyNameText.md)  
The GetKeyNameText function retrieves a string that represents the name of a key.  

***  

[GetKeyState](libraries/user32/GetKeyState.md)  
The GetKeyState function retrieves the status of the specified virtual key. The status specifies whether the key is up, down, or toggled (on, off�alternating each time the key is pressed).   

***  

[GetMenu](libraries/user32/GetMenu.md)  
The GetMenu function retrieves a handle to the menu assigned to the specified window.   

***  

[GetMenuBarInfo](libraries/user32/GetMenuBarInfo.md)  
Retrieves information about the specified menu bar.  

***  

[GetMenuContextHelpId](libraries/user32/GetMenuContextHelpId.md)  
Retrieves the Help context identifier associated with the specified menu.  

***  

[GetMenuItemCount](libraries/user32/GetMenuItemCount.md)  
The GetMenuItemCount function determines the number of items in the specified menu.   

***  

[GetMenuItemID](libraries/user32/GetMenuItemID.md)  
The GetMenuItemID function retrieves the menu item identifier of a menu item located at the specified position in a menu.  

***  

[GetMenuItemInfo](libraries/user32/GetMenuItemInfo.md)  
The GetMenuItemInfo function retrieves information about a menu item.  

***  

[GetMenuString](libraries/user32/GetMenuString.md)  
The GetMenuString function copies the text string of the specified menu item into the specified buffer.
  

***  

[GetMonitorInfo](libraries/user32/GetMonitorInfo.md)  
The GetMonitorInfo function retrieves information about a display monitor.  

***  

[GetMouseMovePointsEx](libraries/user32/GetMouseMovePointsEx.md)  
Retrieves a history of up to 64 previous coordinates of the mouse or pen.  

***  

[GetOpenClipboardWindow](libraries/user32/GetOpenClipboardWindow.md)  
Retrieves the handle to the window that currently has the clipboard open.  

***  

[GetParent](libraries/user32/GetParent.md)  
The GetParent function retrieves a handle to the specified window"s parent or owner. To retrieve a handle to a specified ancestor, use the GetAncestor function.  

***  

[GetPriorityClipboardFormat](libraries/user32/GetPriorityClipboardFormat.md)  
The GetPriorityClipboardFormat function retrieves the first available clipboard format in the specified list.  

***  

[GetProp](libraries/user32/GetProp.md)  
Retrieves a data handle from the property list of the specified window. The character string identifies the handle to be retrieved. The string and handle must have been added to the property list by a previous call to the SetProp function.  

***  

[GetQueueStatus](libraries/user32/GetQueueStatus.md)  
The GetQueueStatus function indicates the type of messages found in the calling thread"s message queue.  

***  

[GetRawInputData](libraries/user32/GetRawInputData.md)  
Retrieves the raw input from the specified device.  

***  

[GetRawInputDeviceInfo](libraries/user32/GetRawInputDeviceInfo.md)  
Retrieves information about the raw input device.  

***  

[GetRawInputDeviceList](libraries/user32/GetRawInputDeviceList.md)  
Enumerates the raw input devices attached to the system.  

***  

[GetShellWindow](libraries/user32/GetShellWindow.md)  
The GetShellWindow function returns a handle to the Shell"s desktop window.  

***  

[GetSubMenu](libraries/user32/GetSubMenu.md)  
Retrieves a handle to the drop-down menu or submenu activated by the specified menu item.  

***  

[GetSysColor](libraries/user32/GetSysColor.md)  
Retrieves the current color of the specified display element. Display elements are the parts of a window and the Windows display that appear on the system display screen  

***  

[GetSysColorBrush](libraries/user32/GetSysColorBrush.md)  
Retrieves a handle identifying a logical brush that corresponds to the specified color index.  

***  

[GetSystemMenu](libraries/user32/GetSystemMenu.md)  
The GetSystemMenu function allows the application to access the window menu (also known as the system menu or the control menu) for copying and modifying.   

***  

[GetSystemMetrics](libraries/user32/GetSystemMetrics.md)  
Retrieves various system metrics (widths and heights of display elements) and system configuration settings. 
  

***  

[GetThreadDesktop](libraries/user32/GetThreadDesktop.md)  
The GetThreadDesktop function retrieves a handle to the desktop associated with a specified thread.  

***  

[GetUpdatedClipboardFormats](libraries/user32/GetUpdatedClipboardFormats.md)  
Retrieves the currently supported clipboard formats.  

***  

[GetUserObjectInformation](libraries/user32/GetUserObjectInformation.md)  
The GetUserObjectInformation function retrieves information about a window station or desktop object.  

***  

[GetWindow](libraries/user32/GetWindow.md)  
The GetWindow function retrieves the handle of a window that has the specified relationship to the specified window.  

***  

[GetWindowContextHelpId](libraries/user32/GetWindowContextHelpId.md)  
The GetWindowContextHelpId function retrieves the help context identifier, if any, associated with the specified window.

Windows NT only  

***  

[GetWindowDC](libraries/user32/GetWindowDC.md)  
The GetWindowDC function retrieves the device context (DC) for the entire window, including title bar, menus, and scroll bars  

***  

[GetWindowInfo](libraries/user32/GetWindowInfo.md)  
The GetWindowInfo function retrieves information about the specified window.  

***  

[GetWindowLong](libraries/user32/GetWindowLong.md)  
Retrieves information about the specified window. The function also retrieves the 32-bit (long) value at the specified offset into the extra window memory.  

***  

[GetWindowPlacement](libraries/user32/GetWindowPlacement.md)  
The GetWindowPlacement function retrieves the show state and the restored, minimized, and maximized positions of the specified window.   

***  

[GetWindowRect](libraries/user32/GetWindowRect.md)  
Retrieves the dimensions of the bounding rectangle of the specified window.
  

***  

[GetWindowRgnBox](libraries/user32/GetWindowRgnBox.md)  
Retrieves the dimensions of the tightest bounding rectangle for the window region of a window.   

***  

[GetWindowText](libraries/user32/GetWindowText.md)  
The GetWindowText function copies the text of the specified window"s title bar (if it has one) into a buffer  

***  

[GetWindowTextLength](libraries/user32/GetWindowTextLength.md)  
The GetWindowTextLength function retrieves the length, in characters, of the specified window"s title bar text  

***  

[GetWindowThreadProcessId](libraries/user32/GetWindowThreadProcessId.md)  
Retrieves the identifier of the thread that created the specified window and, optionally, the identifier of the process that created the window.  

***  

[InsertMenuItem](libraries/user32/InsertMenuItem.md)  
The InsertMenuItem function inserts a new menu item at the specified position in a menu.  

***  

[InternalGetWindowText](libraries/user32/InternalGetWindowText.md)  
This function is similar to the GetWindowText function. However, it obtains the window text directly from the window structure associated with the specified window"s handle and then always provides the text as a unicode string.   

***  

[IsChild](libraries/user32/IsChild.md)  
The IsChild function tests whether a window is a child window or descendant window of a specified parent window  

***  

[IsClipboardFormatAvailable](libraries/user32/IsClipboardFormatAvailable.md)  
The IsClipboardFormatAvailable function determines whether the clipboard contains data in the specified format  

***  

[IsIconic](libraries/user32/IsIconic.md)  
The IsIconic function determines whether the specified window is minimized (iconic).  

***  

[IsMenu](libraries/user32/IsMenu.md)  
The IsMenu function determines whether a handle is a menu handle.   

***  

[IsWindow](libraries/user32/IsWindow.md)  
The IsWindow function determines whether the specified window handle identifies an existing window  

***  

[IsWindowEnabled](libraries/user32/IsWindowEnabled.md)  
The IsWindowEnabled function determines whether the specified window is enabled for mouse and keyboard input.   

***  

[IsWindowVisible](libraries/user32/IsWindowVisible.md)  
The IsWindowVisible function retrieves the visibility state of the specified window  

***  

[IsZoomed](libraries/user32/IsZoomed.md)  
The IsZoomed function determines whether a window is maximized.   

***  

[keybd_event](libraries/user32/keybd_event.md)  
Synthesizes a keystroke. 
  

***  

[LoadBitmap](libraries/user32/LoadBitmap.md)  
The LoadBitmap function loads the specified bitmap resource from a module"s executable file. This function has been superseded by the LoadImage function.   

***  

[LoadIcon](libraries/user32/LoadIcon.md)  
Loads the specified icon resource from the executable (.exe) file associated with an application instance.
  

***  

[LoadImage](libraries/user32/LoadImage.md)  
The LoadImage function loads an icon, cursor, animated cursor, or bitmap.  

***  

[LoadString](libraries/user32/LoadString.md)  
Loads a string resource from the executable file associated with a specified module, copies the string into a buffer, and appends a terminating null character.  

***  

[LockWindowUpdate](libraries/user32/LockWindowUpdate.md)  
The LockWindowUpdate function disables or enables drawing in the specified window. Only one window can be locked at a time.  

***  

[LockWorkStation](libraries/user32/LockWorkStation.md)  
The LockWorkStation function locks the workstation"s display, protecting it from unauthorized use.  

***  

[MapVirtualKey](libraries/user32/MapVirtualKey.md)  
Translates (maps) a virtual-key code into a scan code or character value, or translates a scan code into a virtual-key code.  

***  

[MessageBeep](libraries/user32/MessageBeep.md)  
Plays a waveform sound. The waveform sound for each sound type is identified by an entry in the [sounds] section of the registry  

***  

[MessageBox](libraries/user32/MessageBox.md)  
Creates, displays, and operates a message box. The message box contains an application-defined message and title, plus any combination of predefined icons and push buttons  

***  

[MessageBoxIndirect](libraries/user32/MessageBoxIndirect.md)  
Creates, displays, and operates a message box. The message box contains application-defined message text and title, any icon, and any combination of predefined push buttons.
  

***  

[MonitorFromWindow](libraries/user32/MonitorFromWindow.md)  
Retrieves a handle to the display monitor that has the largest area of intersection with the bounding rectangle of a specified window. 
  

***  

[MoveWindow](libraries/user32/MoveWindow.md)  
The MoveWindow function changes the position and dimensions of the specified window.  

***  

[OemToChar](libraries/user32/OemToChar.md)  
Translates a string from the OEM-defined character set into either an ANSI or a wide-character string.
  

***  

[OpenClipboard](libraries/user32/OpenClipboard.md)  
The OpenClipboard function opens the clipboard for examination and prevents other applications from modifying the clipboard content  

***  

[OpenDesktop](libraries/user32/OpenDesktop.md)  
The OpenDesktop function opens the specified desktop object.  

***  

[OpenInputDesktop](libraries/user32/OpenInputDesktop.md)  
Opens the desktop that receives user input.
  

***  

[PaintDesktop](libraries/user32/PaintDesktop.md)  
Fills the clipping region in the specified device context with the desktop pattern or wallpaper.  

***  

[PeekMessage](libraries/user32/PeekMessage.md)  
The PeekMessage function dispatches incoming sent messages, checks the thread message queue for a posted message, and retrieves the message (if any exist).  

***  

[PostMessage](libraries/user32/PostMessage.md)  
Places (posts) a message in the message queue associated with the thread that created the specified window and returns without waiting for the thread to process the message. 
  

***  

[PostQuitMessage](libraries/user32/PostQuitMessage.md)  
Indicates to the system that a thread has made a request to terminate (quit). It is typically used in response to a WM_DESTROY message.  

***  

[RealGetWindowClass](libraries/user32/RealGetWindowClass.md)  
Retrieves a string that specifies the window type  

***  

[RegisterClassEx](libraries/user32/RegisterClassEx.md)  
Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function.  

***  

[RegisterClipboardFormat](libraries/user32/RegisterClipboardFormat.md)  
The RegisterClipboardFormat function registers a new clipboard format. This format can then be used as a valid clipboard format.   

***  

[RegisterHotKey](libraries/user32/RegisterHotKey.md)  
The RegisterHotKey function defines a system-wide hot key.   

***  

[RegisterRawInputDevices](libraries/user32/RegisterRawInputDevices.md)  
Registers the devices that supply the raw input data.  

***  

[ReleaseCapture](libraries/user32/ReleaseCapture.md)  
Releases the mouse capture from a window in the current thread and restores normal mouse input processing. A window that has captured the mouse receives all mouse input, regardless of the position of the cursor, except when a mouse button is clicked while the cursor hot spot is in the window of another thread.  

***  

[ReleaseDC](libraries/user32/ReleaseDC.md)  
The ReleaseDC function releases a device context (DC), freeing it for use by other applications. For memory device contexts use the DeleteDC function.  

***  

[RemoveClipboardFormatListener](libraries/user32/RemoveClipboardFormatListener.md)  
Removes the given window from the system-maintained clipboard format listener list.  

***  

[RemoveProp](libraries/user32/RemoveProp.md)  
The RemoveProp function removes an entry from the property list of the specified window. The specified character string identifies the entry to be removed.   

***  

[ScreenToClient](libraries/user32/ScreenToClient.md)  
The ScreenToClient function converts the screen coordinates of a specified point on the screen to client-area coordinates.  

***  

[SendMessage](libraries/user32/SendMessage.md)  
Sends the specified message to a window or windows. It calls the window procedure for the specified window and does not return until the window procedure has processed the message.   

***  

[SetCapture](libraries/user32/SetCapture.md)  
The SetCapture function sets the mouse capture to the specified window belonging to the current thread.  

***  

[SetClipboardData](libraries/user32/SetClipboardData.md)  
The SetClipboardData function places data on the clipboard in a specified clipboard format  

***  

[SetClipboardViewer](libraries/user32/SetClipboardViewer.md)  
Adds the specified window to the chain of clipboard viewers.   

***  

[SetDlgItemInt](libraries/user32/SetDlgItemInt.md)  
The SetDlgItemInt function sets the text of a control in a dialog box to the string representation of a specified integer value.   

***  

[SetDlgItemText](libraries/user32/SetDlgItemText.md)  
The SetDlgItemText function sets the title or text of a control in a dialog box.   

***  

[SetDoubleClickTime](libraries/user32/SetDoubleClickTime.md)  
Sets the double-click time for the mouse  

***  

[SetFocus](libraries/user32/SetFocus.md)  
Sets the keyboard focus to the specified window. The window must be attached to the calling thread"s message queue  

***  

[SetForegroundWindow](libraries/user32/SetForegroundWindow.md)  
The SetForegroundWindow function puts the thread that created the specified window into the foreground and activates the window. Keyboard input is directed to the window, and various visual cues are changed for the user  

***  

[SetKeyboardState](libraries/user32/SetKeyboardState.md)  
The SetKeyboardState function copies a 256-byte array of keyboard key states into the calling thread"s keyboard input-state table.   

***  

[SetLayeredWindowAttributes](libraries/user32/SetLayeredWindowAttributes.md)  
The SetLayeredWindowAttributes function sets the opacity and transparency color key of a layered window.  

***  

[SetMenu](libraries/user32/SetMenu.md)  
The SetMenu function assigns a new menu to the specified window.  

***  

[SetParent](libraries/user32/SetParent.md)  
The SetParent function changes the parent window of the specified child window.  

***  

[SetProp](libraries/user32/SetProp.md)  
Adds a new entry or changes an existing entry in the property list of the specified window.  

***  

[SetSysColors](libraries/user32/SetSysColors.md)  
Sets the colors for one or more display elements. Display elements are the various parts of a window and the Windows display that appear on the system display screen  

***  

[SetThreadDesktop](libraries/user32/SetThreadDesktop.md)  
Assigns the specified desktop to the calling thread. All subsequent operations on the desktop use the access rights granted to hDesktop.  

***  

[SetWindowLong](libraries/user32/SetWindowLong.md)  
Changes an attribute of the specified window. The function also sets the 32-bit (long) value at the specified offset into the extra window memory.  

***  

[SetWindowPos](libraries/user32/SetWindowPos.md)  
The SetWindowPos function changes the size, position, and Z order of a child, pop-up, or top-level window.  

***  

[SetWindowRgn](libraries/user32/SetWindowRgn.md)  
Sets the window region of a window. The window region determines the area within the window where the system permits drawing. The system does not display any portion of a window that lies outside of the window region  

***  

[SetWindowsHookEx](libraries/user32/SetWindowsHookEx.md)  
Installs an application-defined hook procedure into a hook chain.  

***  

[SetWindowText](libraries/user32/SetWindowText.md)  
Changes the text of the specified window"s title bar (if it has one). If the specified window is a control, the text of the control is changed.  

***  

[ShowCursor](libraries/user32/ShowCursor.md)  
The ShowCursor function displays or hides the cursor.  

***  

[ShowWindow](libraries/user32/ShowWindow.md)  
The ShowWindow function sets the show state for the specified window.  

***  

[SwapMouseButton](libraries/user32/SwapMouseButton.md)  
The SwapMouseButton function reverses or restores the meaning of the left and right mouse buttons  

***  

[SwitchDesktop](libraries/user32/SwitchDesktop.md)  
Makes a desktop visible and activates it. This enables the desktop to receive input from the user.  

***  

[SwitchToThisWindow](libraries/user32/SwitchToThisWindow.md)  
The function is called to switch focus to a specified window and bring it to the foreground.   

***  

[SystemParametersInfo](libraries/user32/SystemParametersInfo.md)  
The SystemParametersInfo function retrieves or sets the value of one of the system-wide parameters. This function can also update the user profile while setting a parameter.  

***  

[ToAscii](libraries/user32/ToAscii.md)  
Translates the specified virtual-key code and keyboard state to the corresponding character or characters.  

***  

[TrackPopupMenuEx](libraries/user32/TrackPopupMenuEx.md)  
The TrackPopupMenuEx function displays a shortcut menu at the specified location and tracks the selection of items on the shortcut menu. The shortcut menu can appear anywhere on the screen.  

***  

[UnhookWindowsHookEx](libraries/user32/UnhookWindowsHookEx.md)  
Removes a hook procedure installed in a hook chain by the SetWindowsHookEx function.   

***  

[UnregisterClass](libraries/user32/UnregisterClass.md)  
Unregisters a window class, freeing the memory required for the class.  

***  

[UnregisterHotKey](libraries/user32/UnregisterHotKey.md)  
The UnregisterHotKey function frees a hot key previously registered by the calling thread.   

***  

[VkKeyScan](libraries/user32/VkKeyScan.md)  
Translates a character to the corresponding virtual-key code and shift state for the current keyboard.  

***  

[WindowFromDC](libraries/user32/WindowFromDC.md)  
Returns a handle to the window associated with the specified display device context (DC).
  

***  

[WinHelp](libraries/user32/WinHelp.md)  
The WinHelp function starts Windows Help (WINHELP.EXE) and passes additional data indicating the nature of the help requested by the application  

***  

</details>
<a name="userenv" />

# ![](images/fox1.png) Library: userenv
<details>

***  

[LoadUserProfile](libraries/userenv/LoadUserProfile.md)  
Loads the specified user"s profile. The profile can be a local user profile or a roaming user profile.  

***  

[UnloadUserProfile](libraries/userenv/UnloadUserProfile.md)  
Unloads a user"s profile that was loaded by the LoadUserProfile function.  

***  

</details>
<a name="version" />

# ![](images/fox1.png) Library: version
<details>

***  

[GetFileVersionInfo](libraries/version/GetFileVersionInfo.md)  
Retrieves version information for the specified file.  

***  

[GetFileVersionInfoSize](libraries/version/GetFileVersionInfoSize.md)  
The GetFileVersionInfoSize function determines whether the operating system can retrieve version information for a specified file.  

***  

</details>
<a name="virtdisk" />

# ![](images/fox1.png) Library: virtdisk
<details>

***  

[AttachVirtualDisk](libraries/virtdisk/AttachVirtualDisk.md)  
Attaches a virtual hard disk (VHD) by locating an appropriate VHD provider to accomplish the attachment.  

***  

[CreateVirtualDisk](libraries/virtdisk/CreateVirtualDisk.md)  
Creates a virtual hard disk (VHD) image file, either using default parameters or using an existing virtual disk or physical disk.  

***  

[DetachVirtualDisk](libraries/virtdisk/DetachVirtualDisk.md)  
Detaches a virtual hard disk (VHD) by locating an appropriate VHD provider to accomplish the operation.  

***  

[OpenVirtualDisk](libraries/virtdisk/OpenVirtualDisk.md)  
Opens a virtual hard disk (VHD) for use.  

***  

</details>
<a name="winhttp" />

# ![](images/fox1.png) Library: winhttp
<details>

***  

[WinHttpAddRequestHeaders](libraries/winhttp/WinHttpAddRequestHeaders.md)  
The WinHttpAddRequestHeaders function adds one or more HTTP request headers to the HTTP request handle.  

***  

[WinHttpCloseHandle](libraries/winhttp/WinHttpCloseHandle.md)  
The WinHttpCloseHandle function closes a single HINTERNET handle.  

***  

[WinHttpConnect](libraries/winhttp/WinHttpConnect.md)  
Specifies the initial target server of an HTTP request and returns an HINTERNET connection handle to an HTTP session for that initial target.  

***  

[WinHttpCrackUrl](libraries/winhttp/WinHttpCrackUrl.md)  
The WinHttpCrackUrl function separates a URL into its component parts such as host name and path.  

***  

[WinHttpOpen](libraries/winhttp/WinHttpOpen.md)  
Initializes an application"s use of the WinHTTP functions and returns a WinHTTP-session handle.  

***  

[WinHttpOpenRequest](libraries/winhttp/WinHttpOpenRequest.md)  
The WinHttpOpenRequest function creates an HTTP request handle.  

***  

[WinHttpQueryDataAvailable](libraries/winhttp/WinHttpQueryDataAvailable.md)  
The WinHttpQueryDataAvailable function returns the number of bytes of data that are immediately available to be read with WinHttpReadData.  

***  

[WinHttpQueryHeaders](libraries/winhttp/WinHttpQueryHeaders.md)  
The WinHttpQueryHeaders function retrieves header information associated with an HTTP request.  

***  

[WinHttpReadData](libraries/winhttp/WinHttpReadData.md)  
The WinHttpReadData function reads data from a handle opened by the WinHttpOpenRequest function.  

***  

[WinHttpReceiveResponse](libraries/winhttp/WinHttpReceiveResponse.md)  
The WinHttpReceiveResponse function waits to receive the response to an HTTP request initiated by WinHttpSendRequest.  

***  

[WinHttpSendRequest](libraries/winhttp/WinHttpSendRequest.md)  
The WinHttpSendRequest function sends the specified request to the HTTP server.  

***  

[WinHttpSetCredentials](libraries/winhttp/WinHttpSetCredentials.md)  
The WinHttpSetCredentials function passes the required authorization credentials to the server.  

***  

</details>
<a name="wininet" />

# ![](images/fox1.png) Library: wininet
<details>

***  

[CreateMD5SSOHash](libraries/wininet/CreateMD5SSOHash.md)  
Obtains the default Microsoft Passport password for a specified account or realm, creates an MD5 hash from it using a specified wide-character challenge string, and returns the result as a string of hexadecimal digit bytes.  

***  

[DeleteUrlCacheEntry](libraries/wininet/DeleteUrlCacheEntry.md)  
Removes the file associated with the source name from the cache, if the file exists.  

***  

[DetectAutoProxyUrl](libraries/wininet/DetectAutoProxyUrl.md)  
Attempts to determine the location of a WPAD autoproxy script.  

***  

[FindCloseUrlCache](libraries/wininet/FindCloseUrlCache.md)  
Closes the specified cache enumeration handle.  

***  

[FindFirstUrlCacheEntry](libraries/wininet/FindFirstUrlCacheEntry.md)  
Begins the enumeration of the Internet cache.  

***  

[FindFirstUrlCacheGroup](libraries/wininet/FindFirstUrlCacheGroup.md)  
Initiates the enumeration of the cache groups in the Internet cache.  

***  

[FindNextUrlCacheEntry](libraries/wininet/FindNextUrlCacheEntry.md)  
Retrieves the next entry in the Internet cache.  

***  

[FindNextUrlCacheGroup](libraries/wininet/FindNextUrlCacheGroup.md)  
Retrieves the next cache group in a cache group enumeration started by FindFirstUrlCacheGroup.  

***  

[FtpCommand](libraries/wininet/FtpCommand.md)  
Sends commands directly to an FTP server.  

***  

[FtpCreateDirectory](libraries/wininet/FtpCreateDirectory.md)  
Creates a new directory on the FTP server  

***  

[FtpDeleteFile](libraries/wininet/FtpDeleteFile.md)  
Deletes a file stored on the FTP server.  

***  

[FtpFindFirstFile](libraries/wininet/FtpFindFirstFile.md)  
Searches the specified directory of the given FTP session  

***  

[FtpGetCurrentDirectory](libraries/wininet/FtpGetCurrentDirectory.md)  
Retrieves the current directory for the specified FTP session  

***  

[FtpGetFile](libraries/wininet/FtpGetFile.md)  
Retrieves a file from the FTP server and stores it under the specified file name, creating a new local file in the process.  

***  

[FtpGetFileSize](libraries/wininet/FtpGetFileSize.md)  
Retrieves the file size of the requested FTP resource.  

***  

[FtpOpenFile](libraries/wininet/FtpOpenFile.md)  
Initiates access to a remote file on an FTP server for reading or writing.
  

***  

[FtpPutFile](libraries/wininet/FtpPutFile.md)  
Stores a file on the FTP server.  

***  

[FtpRemoveDirectory](libraries/wininet/FtpRemoveDirectory.md)  
Removes the specified directory on the FTP server.  

***  

[FtpRenameFile](libraries/wininet/FtpRenameFile.md)  
Renames a file stored on the FTP server.  

***  

[FtpSetCurrentDirectory](libraries/wininet/FtpSetCurrentDirectory.md)  
Changes to a different working directory on the FTP server  

***  

[GetUrlCacheEntryInfo](libraries/wininet/GetUrlCacheEntryInfo.md)  
Retrieves information about a cache entry.  

***  

[HttpOpenRequest](libraries/wininet/HttpOpenRequest.md)  
This function opens an HTTP request handle.  

***  

[HttpQueryInfo](libraries/wininet/HttpQueryInfo.md)  
Retrieves header information associated with an HTTP request.  

***  

[HttpSendRequest](libraries/wininet/HttpSendRequest.md)  
This function sends the specified request to the HTTP server.  

***  

[InternetAttemptConnect](libraries/wininet/InternetAttemptConnect.md)  
Attempts to make a connection to the Internet.  

***  

[InternetAutodial](libraries/wininet/InternetAutodial.md)  
Causes the modem to automatically dial the default Internet connection.  

***  

[InternetAutodialHangup](libraries/wininet/InternetAutodialHangup.md)  
Disconnects an automatic dial-up connection.  

***  

[InternetCanonicalizeUrl](libraries/wininet/InternetCanonicalizeUrl.md)  
Canonicalizes a URL, which includes converting unsafe characters and spaces into escape sequences.  

***  

[InternetCheckConnection](libraries/wininet/InternetCheckConnection.md)  
Allows an application to check if a connection to the Internet can be established.  

***  

[InternetCloseHandle](libraries/wininet/InternetCloseHandle.md)  
Closes a single Internet handle  

***  

[InternetConnect](libraries/wininet/InternetConnect.md)  
Opens an FTP, Gopher, or HTTP session for a given site  

***  

[InternetCrackUrl](libraries/wininet/InternetCrackUrl.md)  
Cracks a URL into its component parts.  

***  

[InternetDial](libraries/wininet/InternetDial.md)  
Initiates a connection to the Internet using a modem.  

***  

[InternetFindNextFile](libraries/wininet/InternetFindNextFile.md)  
Continues a file search started as a result of a previous call to FtpFindFirstFile or GopherFindFirstFile  

***  

[InternetGetConnectedState](libraries/wininet/InternetGetConnectedState.md)  
Retrieves the connected state of the local system.  

***  

[InternetGetConnectedStateEx](libraries/wininet/InternetGetConnectedStateEx.md)  
Retrieves the connected state of the specified Internet connection.  

***  

[InternetGetCookie](libraries/wininet/InternetGetCookie.md)  
This function retrieves the cookie for the specified URL.  

***  

[InternetGetLastResponseInfo](libraries/wininet/InternetGetLastResponseInfo.md)  
Retrieves the last Microsoft&reg; Win32&reg; Internet function error description or server response on the thread calling this function.  

***  

[InternetGoOnline](libraries/wininet/InternetGoOnline.md)  
Prompts the user for permission to initiate connection to a URL.  

***  

[InternetOpen](libraries/wininet/InternetOpen.md)  
Initializes an application"s use of the Microsoft&reg; Win32&reg; Internet functions  

***  

[InternetOpenUrl](libraries/wininet/InternetOpenUrl.md)  
Opens a resource specified by a complete FTP, Gopher, or HTTP URL.  

***  

[InternetQueryDataAvailable](libraries/wininet/InternetQueryDataAvailable.md)  
This function queries the amount of data available.  

***  

[InternetQueryOption](libraries/wininet/InternetQueryOption.md)  
Queries an Internet option on the specified handle  

***  

[InternetReadFile](libraries/wininet/InternetReadFile.md)  
Reads data from a handle opened by the InternetOpenUrl, FtpOpenFile, FtpCommand, GopherOpenFile, or HttpOpenRequest function
  

***  

[InternetSetCookie](libraries/wininet/InternetSetCookie.md)  
This function creates a cookie associated with the specified URL.  

***  

[InternetSetFilePointer](libraries/wininet/InternetSetFilePointer.md)  
Sets a file position for InternetReadFile.   

***  

[InternetTimeFromSystemTime](libraries/wininet/InternetTimeFromSystemTime.md)  
Formats a date and time according to the HTTP version 1.0 specification.  

***  

[InternetTimeToSystemTime](libraries/wininet/InternetTimeToSystemTime.md)  
Converts an HTTP time/date string to a SYSTEMTIME structure.  

***  

[InternetWriteFile](libraries/wininet/InternetWriteFile.md)  
Writes data to an open Internet file.  

***  

</details>
<a name="winmm" />

# ![](images/fox1.png) Library: winmm
<details>

***  

[mciGetDeviceID](libraries/winmm/mciGetDeviceID.md)  
Retrieves the device identifier corresponding to the name of an open device.  

***  

[mciGetErrorString](libraries/winmm/mciGetErrorString.md)  
The mciGetErrorString function retrieves a string that describes the specified MCI error code.   

***  

[mciSendCommand](libraries/winmm/mciSendCommand.md)  
Sends a command message to the specified MCI device.  

***  

[mciSendString](libraries/winmm/mciSendString.md)  
The <b>mciSendString</b> function sends a command string to an MCI device. The device that the command is sent to is specified in the command string.   

***  

[midiOutClose](libraries/winmm/midiOutClose.md)  
Closes the specified MIDI output device.
  

***  

[midiOutGetDevCaps](libraries/winmm/midiOutGetDevCaps.md)  
Queries a specified MIDI output device to determine its capabilities.
  

***  

[midiOutGetNumDevs](libraries/winmm/midiOutGetNumDevs.md)  
Retrieves the number of MIDI output devices present in the system.  

***  

[midiOutOpen](libraries/winmm/midiOutOpen.md)  
Opens a MIDI output device for playback.
  

***  

[midiOutReset](libraries/winmm/midiOutReset.md)  
Turns off all notes on all MIDI channels for the specified MIDI output device.  

***  

[midiOutShortMsg](libraries/winmm/midiOutShortMsg.md)  
Sends a short MIDI message to the specified MIDI output device.  

***  

[mixerClose](libraries/winmm/mixerClose.md)  
The mixerClose function closes the specified mixer device.  

***  

[mixerGetControlDetails](libraries/winmm/mixerGetControlDetails.md)  
Retrieves details about a single control associated with an audio line.  

***  

[mixerGetDevCaps](libraries/winmm/mixerGetDevCaps.md)  
The mixerGetDevCaps function queries a specified mixer device to determine its capabilities.  

***  

[mixerGetID](libraries/winmm/mixerGetID.md)  
Retrieves the device identifier for a mixer device associated with a specified device handle.  

***  

[mixerGetLineControls](libraries/winmm/mixerGetLineControls.md)  
The mixerGetLineControls function retrieves one or more controls associated with an audio line.  

***  

[mixerGetLineInfo](libraries/winmm/mixerGetLineInfo.md)  
The mixerGetLineInfo function retrieves information about a specific line of a mixer device.  

***  

[mixerGetNumDevs](libraries/winmm/mixerGetNumDevs.md)  
The mixerGetNumDevs function retrieves the number of mixer devices present in the system.  

***  

[mixerOpen](libraries/winmm/mixerOpen.md)  
The mixerOpen function opens a specified mixer device and ensures that the device will not be removed until the application closes the handle.  

***  

[mixerSetControlDetails](libraries/winmm/mixerSetControlDetails.md)  
Sets properties of a single control associated with an audio line.  

***  

[mmioAscend](libraries/winmm/mmioAscend.md)  
The mmioAscend function ascends out of a chunk in a RIFF file descended into with the mmioDescend function or created with the mmioCreateChunk function.  

***  

[mmioClose](libraries/winmm/mmioClose.md)  
The mmioClose function closes a file that was opened by using the mmioOpen function.  

***  

[mmioCreateChunk](libraries/winmm/mmioCreateChunk.md)  
The mmioCreateChunk function creates a chunk in a RIFF file that was opened by using the mmioOpen function.  

***  

[mmioDescend](libraries/winmm/mmioDescend.md)  
The mmioDescend function descends into a chunk of a RIFF file that was opened by using the mmioOpen function. It can also search for a given chunk.  

***  

[mmioFlush](libraries/winmm/mmioFlush.md)  
The mmioFlush function writes the I/O buffer of a file to disk if the buffer has been written to.  

***  

[mmioOpen](libraries/winmm/mmioOpen.md)  
The mmioOpen function opens a file for unbuffered or buffered I/O. The file can be a standard file, a memory file, or an element of a custom storage system.  

***  

[mmioRead](libraries/winmm/mmioRead.md)  
The mmioRead function reads a specified number of bytes from a file opened by using the mmioOpen function.  

***  

[mmioSeek](libraries/winmm/mmioSeek.md)  
Changes the current file position in a file opened by using the mmioOpen function.   

***  

[mmioWrite](libraries/winmm/mmioWrite.md)  
Writes a specified number of bytes to a file opened by using the mmioOpen function.
  

***  

[PlaySound](libraries/winmm/PlaySound.md)  
Plays a sound specified by the given file name, resource, or system event.  

***  

[sndPlaySound](libraries/winmm/sndPlaySound.md)  
The sndPlaySound function plays a waveform sound specified either by a filename or by an entry in the registry or the WIN.INI file.   

***  

[timeGetDevCaps](libraries/winmm/timeGetDevCaps.md)  
Queries the timer device to determine its resolution.  

***  

[waveInAddBuffer](libraries/winmm/waveInAddBuffer.md)  
The waveInAddBuffer function sends an input buffer to the given waveform-audio input device. When the buffer is filled, the application is notified.  

***  

[waveInClose](libraries/winmm/waveInClose.md)  
The waveInClose function closes the given waveform-audio input device.  

***  

[waveInGetDevCaps](libraries/winmm/waveInGetDevCaps.md)  
The waveInGetDevCaps function retrieves the capabilities of a given waveform-audio input device.  

***  

[waveInGetErrorText](libraries/winmm/waveInGetErrorText.md)  
The waveInGetErrorText function retrieves a textual description of the error identified by the given error number.  

***  

[waveInGetNumDevs](libraries/winmm/waveInGetNumDevs.md)  
The waveInGetNumDevs function returns the number of waveform-audio input devices present in the system.  

***  

[waveInGetPosition](libraries/winmm/waveInGetPosition.md)  
The waveInGetPosition function retrieves the current input position of the given waveform-audio input device.  

***  

[waveInOpen](libraries/winmm/waveInOpen.md)  
The waveInOpen function opens the given waveform-audio input device for recording.  

***  

[waveInPrepareHeader](libraries/winmm/waveInPrepareHeader.md)  
The waveInPrepareHeader function prepares a buffer for waveform-audio input.  

***  

[waveInReset](libraries/winmm/waveInReset.md)  
The waveInReset function stops input on the given waveform-audio input device and resets the current position to zero. All pending buffers are marked as done and returned to the application.  

***  

[waveInStart](libraries/winmm/waveInStart.md)  
The waveInStart function starts input on the given waveform-audio input device.  

***  

[waveInStop](libraries/winmm/waveInStop.md)  
The waveInStop function stops waveform-audio input.  

***  

[waveInUnprepareHeader](libraries/winmm/waveInUnprepareHeader.md)  
The waveInUnprepareHeader function cleans up the preparation performed by the waveInPrepareHeader function. This function must be called after the device driver fills a buffer and returns it to the application. You must call this function before freeing the buffer.  

***  

[waveOutClose](libraries/winmm/waveOutClose.md)  
The waveOutClose function closes the given waveform-audio output device.  

***  

[waveOutGetDevCaps](libraries/winmm/waveOutGetDevCaps.md)  
Retrieves the capabilities of a given waveform-audio output device.  

***  

[waveOutGetErrorText](libraries/winmm/waveOutGetErrorText.md)  
Retrieves a textual description of the error identified by the given error number.  

***  

[waveOutGetNumDevs](libraries/winmm/waveOutGetNumDevs.md)  
Retrieves the number of waveform-audio output devices present in the system.  

***  

[waveOutGetPosition](libraries/winmm/waveOutGetPosition.md)  
The waveOutGetPosition function retrieves the current playback position of the given waveform-audio output device.
  

***  

[waveOutGetVolume](libraries/winmm/waveOutGetVolume.md)  
The waveOutGetVolume function retrieves the current volume level of the specified waveform-audio output device.  

***  

[waveOutOpen](libraries/winmm/waveOutOpen.md)  
The waveOutOpen function opens the given waveform-audio output device for playback.  

***  

[waveOutPrepareHeader](libraries/winmm/waveOutPrepareHeader.md)  
The waveOutPrepareHeader function prepares a waveform-audio data block for playback with waveOutWrite function.  

***  

[waveOutReset](libraries/winmm/waveOutReset.md)  
The waveOutReset function stops playback on the given waveform-audio output device and resets the current position to zero. All pending playback buffers are marked as done and returned to the application.  

***  

[waveOutSetVolume](libraries/winmm/waveOutSetVolume.md)  
The waveOutSetVolume function sets the volume level of the specified waveform-audio output device.  

***  

[waveOutUnprepareHeader](libraries/winmm/waveOutUnprepareHeader.md)  
The waveOutUnprepareHeader function cleans up the preparation performed by the waveOutPrepareHeader function. This function must be called after the device driver is finished with a data block. You must call this function before freeing the buffer.  

***  

[waveOutWrite](libraries/winmm/waveOutWrite.md)  
The waveOutWrite function sends a data block to the given waveform-audio output device.  

***  

</details>
<a name="winscard" />

# ![](images/fox1.png) Library: winscard
<details>

***  

[SCardConnect](libraries/winscard/SCardConnect.md)  
Establishes a connection (using a specific resource manager context) between the calling application and a smart card contained by a specific reader.
  

***  

[SCardControl](libraries/winscard/SCardControl.md)  
The SCardControl function gives you direct control of the reader by sending specific control codes optionally accompanied with supporting input data.  

***  

[SCardDisconnect](libraries/winscard/SCardDisconnect.md)  
Terminates a connection previously opened between the calling application and a smart card in the target reader.  

***  

[SCardEstablishContext](libraries/winscard/SCardEstablishContext.md)  
Establishes the resource manager context (the scope) within which database operations are performed.  

***  

[SCardGetAttrib](libraries/winscard/SCardGetAttrib.md)  
Gets the current reader attributes for the given handle. It does not affect the state of the reader, driver, or card.
  

***  

[SCardGetProviderId](libraries/winscard/SCardGetProviderId.md)  
Returns the identifier (GUID) of the primary service provider for a given card.  

***  

[SCardIsValidContext](libraries/winscard/SCardIsValidContext.md)  
Determines whether a smart card context handle is valid.
  

***  

[SCardListCards](libraries/winscard/SCardListCards.md)  
Searches the smart card database and provides a list of named cards previously introduced to the system by the user.  

***  

[SCardListInterfaces](libraries/winscard/SCardListInterfaces.md)  
Provides a list of interfaces supplied by a given card.  

***  

[SCardListReaderGroups](libraries/winscard/SCardListReaderGroups.md)  
Provides the list of reader groups that have previously been introduced to the system.
  

***  

[SCardListReaders](libraries/winscard/SCardListReaders.md)  
Provides the list of readers within a set of named reader groups.  

***  

[SCardReleaseContext](libraries/winscard/SCardReleaseContext.md)  
Closes an established resource manager context, freeing any resources allocated under that context, including SCARDHANDLE objects and memory allocated using the SCARD_AUTOALLOCATE length designator.
  

***  

[SCardStatus](libraries/winscard/SCardStatus.md)  
Provides the current status of a smart card in a reader.  

***  

[SCardTransmit](libraries/winscard/SCardTransmit.md)  
Sends a service request to the smart card and expects to receive data back from the card.  

***  

</details>
<a name="winspool.drv" />

# ![](images/fox1.png) Library: winspool.drv
<details>

***  

[AddPrinter](libraries/winspool.drv/AddPrinter.md)  
The AddPrinter function adds a printer to the list of supported printers for a specified server.   

***  

[ClosePrinter](libraries/winspool.drv/ClosePrinter.md)  
The ClosePrinter function closes the specified printer object.   

***  

[ConfigurePort](libraries/winspool.drv/ConfigurePort.md)  
The ConfigurePort function displays the port-configuration dialog box for a port on the specified server.   

***  

[ConnectToPrinterDlg](libraries/winspool.drv/ConnectToPrinterDlg.md)  
The ConnectToPrinterDlg function displays a dialog box that lets users browse and connect to printers on a network. If the user selects a printer, the function attempts to create a connection to it; if a suitable driver is not installed on the server, the user is given the option of creating a printer locally.   

***  

[DeletePort](libraries/winspool.drv/DeletePort.md)  
Displays a dialog box that allows the user to delete a port name.  

***  

[DeviceCapabilities](libraries/winspool.drv/DeviceCapabilities.md)  
The DeviceCapabilities function retrieves the capabilities of a printer device driver.  

***  

[DocumentProperties](libraries/winspool.drv/DocumentProperties.md)  
The DocumentProperties function retrieves or modifies printer initialization information or displays a printer-configuration property sheet for the specified printer.   

***  

[EnumForms](libraries/winspool.drv/EnumForms.md)  
The EnumForms function enumerates the forms supported by the specified printer.  

***  

[EnumJobs](libraries/winspool.drv/EnumJobs.md)  
The EnumJobs function retrieves information about a specified set of print jobs for a specified printer.   

***  

[EnumPorts](libraries/winspool.drv/EnumPorts.md)  
The EnumPorts function enumerates the ports that are available for printing on a specified server.  

***  

[EnumPrinterData](libraries/winspool.drv/EnumPrinterData.md)  
The EnumPrinterData function enumerates configuration data for a specified printer.   

***  

[EnumPrinterDrivers](libraries/winspool.drv/EnumPrinterDrivers.md)  
Enumerates the printer drivers installed on a specified printer server.  

***  

[EnumPrinters](libraries/winspool.drv/EnumPrinters.md)  
The EnumPrinters function enumerates available printers, print servers, domains, or print providers.  

***  

[EnumPrintProcessorDatatypes](libraries/winspool.drv/EnumPrintProcessorDatatypes.md)  
The EnumPrintProcessorDatatypes function enumerates the data types that a specified print processor supports.  

***  

[EnumPrintProcessors](libraries/winspool.drv/EnumPrintProcessors.md)  
The EnumPrintProcessors function enumerates the print processors installed on the specified server.  

***  

[FindClosePrinterChangeNotification](libraries/winspool.drv/FindClosePrinterChangeNotification.md)  
Closes a change notification object created by calling the FindFirstPrinterChangeNotification function.  

***  

[FindFirstPrinterChangeNotification](libraries/winspool.drv/FindFirstPrinterChangeNotification.md)  
Creates a change notification object and returns a handle to the object. You can then use this handle in a call to one of the wait functions to monitor changes to the printer or print server. 
  

***  

[FindNextPrinterChangeNotification](libraries/winspool.drv/FindNextPrinterChangeNotification.md)  
Retrieves information about the most recent change notification for a change notification object associated with a printer or print server. Call this function when a wait operation on the change notification object is satisfied.  

***  

[FreePrinterNotifyInfo](libraries/winspool.drv/FreePrinterNotifyInfo.md)  
Frees a system-allocated buffer created by the FindNextPrinterChangeNotification function.
  

***  

[GetDefaultPrinter](libraries/winspool.drv/GetDefaultPrinter.md)  
The GetDefaultPrinter function retrieves the printer name of the default printer for the current user on the local computer.  

***  

[GetPrinter](libraries/winspool.drv/GetPrinter.md)  
The GetPrinter function retrieves information about a specified printer.   

***  

[GetPrinterData](libraries/winspool.drv/GetPrinterData.md)  
The GetPrinterData function retrieves configuration data for the specified printer or print server.   

***  

[GetPrinterDriverDirectory](libraries/winspool.drv/GetPrinterDriverDirectory.md)  
The GetPrinterDriverDirectory function retrieves the path of the printer-driver directory.   

***  

[GetPrintProcessorDirectory](libraries/winspool.drv/GetPrintProcessorDirectory.md)  
The GetPrintProcessorDirectory function retrieves the path for the print processor on the specified server.   

***  

[OpenPrinter](libraries/winspool.drv/OpenPrinter.md)  
The OpenPrinter function retrieves a handle to the specified printer or print server or other types of handles in the print subsystem.  

***  

[PrinterProperties](libraries/winspool.drv/PrinterProperties.md)  
The PrinterProperties function displays a printer-properties property sheet for the specified printer.   

***  

[SetDefaultPrinter](libraries/winspool.drv/SetDefaultPrinter.md)  
Sets the printer name of the default printer for the current user on the local computer.  

***  

[SetJob](libraries/winspool.drv/SetJob.md)  
The SetJob function pauses, resumes, cancels, or restarts a print job on a specified printer. You can also use the SetJob function to set print job parameters, such as the print job priority and the document name.   

***  

[SetPrinter](libraries/winspool.drv/SetPrinter.md)  
The SetPrinter function sets the data for a specified printer or sets the state of the specified printer by pausing printing, resuming printing, or clearing all print jobs.   

***  

</details>
<a name="wintrust" />

# ![](images/fox1.png) Library: wintrust
<details>

***  

[WinVerifyTrust](libraries/wintrust/WinVerifyTrust.md)  
Performs a trust verification action on a specified object. The function passes the inquiry to a trust provider that supports the action identifier, if one exists.  

***  

</details>
<a name="ws2_32" />

# ![](images/fox1.png) Library: ws2_32
<details>

***  

[accept](libraries/ws2_32/accept.md)  
The accept function permits an incoming connection attempt on a socket.  

***  

[bind](libraries/ws2_32/bind.md)  
The bind function associates a local address (IP address and port) with a socket.  

***  

[closesocket](libraries/ws2_32/closesocket.md)  
The closesocket function closes an existing socket.  

***  

[gethostbyaddr](libraries/ws2_32/gethostbyaddr.md)  
The gethostbyaddr function retrieves the host information corresponding to a network address.  

***  

[gethostbyname](libraries/ws2_32/gethostbyname.md)  
The gethostbyname function retrieves host information corresponding to a host name from a host database.  

***  

[gethostname](libraries/ws2_32/gethostname.md)  
The gethostname function retrieves the standard host name for the local computer.  

***  

[getnameinfo](libraries/ws2_32/getnameinfo.md)  
Provides protocol-independent name resolution from an address to an ANSI host name and from a port number to the ANSI service name.  

***  

[getprotobynumber](libraries/ws2_32/getprotobynumber.md)  
The getprotobynumber function retrieves protocol information corresponding to a protocol number.  

***  

[getservbyname](libraries/ws2_32/getservbyname.md)  
The getservbyname function retrieves service information corresponding to a service name and protocol.  

***  

[getservbyport](libraries/ws2_32/getservbyport.md)  
The getservbyport function retrieves service information corresponding to a port and protocol.  

***  

[getsockopt](libraries/ws2_32/getsockopt.md)  
The getsockopt function retrieves a socket option.  

***  

[htonl](libraries/ws2_32/htonl.md)  
The htonl function converts a u_long from host to TCP/IP network byte order (which is big endian).  

***  

[htons](libraries/ws2_32/htons.md)  
The htons function converts a u_short from host to TCP/IP network byte order (which is big-endian).  

***  

[inet_addr](libraries/ws2_32/inet_addr.md)  
The inet_addr function converts a string containing an (Ipv4) Internet Protocol dotted address into a proper address for the IN_ADDR structure.  

***  

[inet_ntoa](libraries/ws2_32/inet_ntoa.md)  
The inet_ntoa function converts an (Ipv4) Internet network address into a string in Internet standard dotted format.  

***  

[listen](libraries/ws2_32/listen.md)  
The listen function places a socket in a state in which it is listening for an incoming connection.  

***  

[ntohl](libraries/ws2_32/ntohl.md)  
The ntohl function converts a u_long from TCP/IP network order to host byte order (which is little-endian on Intel processors).  

***  

[ntohs](libraries/ws2_32/ntohs.md)  
The ntohs function converts a u_short from TCP/IP network byte order to host byte order (which is little-endian on Intel processors).  

***  

[recv](libraries/ws2_32/recv.md)  
The <Strong>recv</Strong> function receives data from a connected or bound socket.  

***  

[recvfrom](libraries/ws2_32/recvfrom.md)  
Receives a datagram and stores the source address.  

***  

[send](libraries/ws2_32/send.md)  
The <Strong>send</Strong> function sends data on a connected socket.
  

***  

[sendto](libraries/ws2_32/sendto.md)  
Sends data to a specific destination.  

***  

[setsockopt](libraries/ws2_32/setsockopt.md)  
The setsockopt function sets a socket option.  

***  

[socket](libraries/ws2_32/socket.md)  
The <B>socket</B> function creates a socket that is bound to a specific service provider.  

***  

[WSACleanup](libraries/ws2_32/WSACleanup.md)  
The WSACleanup function terminates use of the Ws2_32.dll.  

***  

[WSACloseEvent](libraries/ws2_32/WSACloseEvent.md)  
The WSACloseEvent function closes an open event object handle.  

***  

[WSAConnect](libraries/ws2_32/WSAConnect.md)  
Establishes a connection to another socket application, exchanges connect data, and specifies required quality of service based on the specified FLOWSPEC structure.
  

***  

[WSACreateEvent](libraries/ws2_32/WSACreateEvent.md)  
The WSACreateEvent function creates a new event object.  

***  

[WSAEventSelect](libraries/ws2_32/WSAEventSelect.md)  
The WSAEventSelect function specifies an event object to be associated with the specified set of FD_XXX network events.  

***  

[WSAGetLastError](libraries/ws2_32/WSAGetLastError.md)  
The WSAGetLastError function returns the error status for the last operation that failed.  

***  

[WSARecv](libraries/ws2_32/WSARecv.md)  
Receives data from a connected socket.  

***  

[WSASend](libraries/ws2_32/WSASend.md)  
Sends data on a connected socket.  

***  

[WSAStartup](libraries/ws2_32/WSAStartup.md)  
The WSAStartup function initiates use of Ws2_32.dll by a process.  

***  

[WSAWaitForMultipleEvents](libraries/ws2_32/WSAWaitForMultipleEvents.md)  
The WSAWaitForMultipleEvents function returns either when one or all of the specified event objects are in the signaled state, or when the time-out interval expires.  

***  

[ws_connect](libraries/ws2_32/ws_connect.md)  
The <Strong>connect</Strong> function establishes a connection to a specified socket.
  

***  

[ws_select](libraries/ws2_32/ws_select.md)  
The <Strong>select</Strong> function determines the status of one or more sockets, waiting if necessary, to perform synchronous I/O.
  

***  

</details>
<a name="wtsapi32" />

# ![](images/fox1.png) Library: wtsapi32
<details>

***  

[WTSCloseServer](libraries/wtsapi32/WTSCloseServer.md)  
Closes an open handle to a terminal server.  

***  

[WTSEnumerateProcesses](libraries/wtsapi32/WTSEnumerateProcesses.md)  
Retrieves information about the active processes on a specified terminal server.  

***  

[WTSEnumerateServers](libraries/wtsapi32/WTSEnumerateServers.md)  
Returns a list of all terminal servers within the specified Windows NT domain.
  

***  

[WTSEnumerateSessions](libraries/wtsapi32/WTSEnumerateSessions.md)  
Retrieves a list of sessions on a specified terminal server.  

***  

[WTSFreeMemory](libraries/wtsapi32/WTSFreeMemory.md)  
Frees memory allocated by a Terminal Services function.
  

***  

[WTSOpenServer](libraries/wtsapi32/WTSOpenServer.md)  
Opens a handle to the specified terminal server.
  

***  

[WTSQuerySessionInformation](libraries/wtsapi32/WTSQuerySessionInformation.md)  
Retrieves session information for the specified session on the specified terminal server. It can be used to query session information on local and remote terminal servers.
  

***  

[WTSRegisterSessionNotification](libraries/wtsapi32/WTSRegisterSessionNotification.md)  
Registers the specified window to receive session change notifications.
  

***  

[WTSSendMessage](libraries/wtsapi32/WTSSendMessage.md)  
Displays a message box on the client desktop of a specified Terminal Services session.  

***  

[WTSUnRegisterSessionNotification](libraries/wtsapi32/WTSUnRegisterSessionNotification.md)  
Unregisters the specified window so that it receives no further session change notifications.  

***  

</details>

[<img src="images/home.png"> Home ](https://github.com/VFPX/Win32API)  
