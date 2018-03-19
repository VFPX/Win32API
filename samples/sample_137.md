[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Writing to INI file

## Before you begin:
See also:

* [Reading from INI file](sample_133.md)  
* [Reading entries from Event logs](sample_524.md)  
* [Writing entries to custom Event Log](sample_564.md)  

  
***  


## Code:
```foxpro  
DO declare

LOCAL lcFilename
lcFilename = "c:\Temp\test.ini"
= CreateFile(lcFilename)

*** Technique 1
* adding empty sections
= WritePrivateProfileSection("General",   "", lcFilename)
= WritePrivateProfileSection("Language",  "", lcFilename)
= WritePrivateProfileSection("Devices",   "", lcFilename)
= WritePrivateProfileSection("Uninstall", "", lcFilename)
= WritePrivateProfileSection("Old Brown Shoe", "", lcFilename)

*** Technique 2
* adding key names and associated values to existing sections

= WritePrivateProfileSection("General",;
	"startdir=C:\"     + Chr(0) +;
	"resolution=high"  + Chr(0) +;
	"delay=500"        + Chr(0) +;
	"security=default" + Chr(0),;
	lcFilename)

= WritePrivateProfileSection("Language",;
	"Active=English" + Chr(0),;
	lcFilename)

= WritePrivateProfileSection("Devices",;
	"Default=Fork"   + Chr(0) +;
	"Active=Spoon"   + Chr(0) +;
	"Emergency=Hand" + Chr(0),;
	lcFilename)

*** Technique 3
* adding new section and a key in one step
= WritePrivateProfileSection("Environment",;
	"Active=Testing" + Chr(0),;
	lcFilename)
	
*** Technique 4
* adding new key to a section which exists
= WritePrivateProfileString("General",;
	"datapath", "C:\App\Data", lcFilename)

*** Technique 5
* replacing existing key
= WritePrivateProfileString("General",;
	"startdir", "C:\App", lcFilename)

*** Technique 6
* adding new key to the section, which does not exist
= WritePrivateProfileString("Very Important Section",;
	"Urgent action", "Do not care", lcFilename)

PROCEDURE CreateFile(lcFilename)
	IF FILE(lcFilename)
		DELETE FILE (lcFilename)
	ENDIF
	
	hFile = FCREATE(lcFilename)
	= FCLOSE(hFile)

PROCEDURE declare
	DECLARE WritePrivateProfileSection IN kernel32;
		STRING lpAppName, STRING lpString,;
		STRING lpFileName

	DECLARE WritePrivateProfileString IN kernel32;
		STRING lpAppName, STRING lpKeyName,;
		STRING lpString, STRING lpFileName  
```  
***  


## Listed functions:
[WritePrivateProfileSection](../libraries/kernel32/WritePrivateProfileSection.md)  
[WritePrivateProfileString](../libraries/kernel32/WritePrivateProfileString.md)  
