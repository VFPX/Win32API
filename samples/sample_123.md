[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Returning some basic information for the specified INF file

## Code:
```foxpro  
#DEFINE INFINFO_INF_SPEC_IS_HINF        1
#DEFINE INFINFO_INF_NAME_IS_ABSOLUTE    2
#DEFINE INFINFO_DEFAULT_SEARCH          3
#DEFINE INFINFO_REVERSE_DEFAULT_SEARCH  4
#DEFINE INFINFO_INF_PATH_LIST_SEARCH    5

#DEFINE INF_STYLE_NONE     0
#DEFINE INF_STYLE_OLDNT    1
#DEFINE INF_STYLE_WIN4     2

*| typedef struct _SP_INF_INFORMATION {
*|   DWORD InfStyle;     //the style of the INF file
*|   DWORD InfCount;     //number of constituent INF files
*|   BYTE  VersionData[ANYSIZE_ARRAY];
*|                       //array to store the INF information
*| } SP_INF_INFORMATION, *PSP_INF_INFORMATION;


	DECLARE SHORT SetupGetInfInformation IN Setupapi;
		STRING    InfSpec,;
		INTEGER   SearchControl,;
		STRING  @ ReturnBuffer,;
		INTEGER   ReturnBufferSize,;
		INTEGER @ RequiredSize

	* put valid INF file name here
	lcFilename = "c:\a\Homepage.inf"

	ReturnBuffer = SPACE(250)
	RequiredSize = 0

	= SetupGetInfInformation ( lcFilename,;
		INFINFO_INF_NAME_IS_ABSOLUTE,;
		@ReturnBuffer, Len(ReturnBuffer),;
		@RequiredSize)

	ReturnBuffer = LEFT(ReturnBuffer, RequiredSize)

	? "INF Style:",;
		getInfStyle (buf2dword (SUBSTR(ReturnBuffer, 1,4)))
	? "Number of INF files:", buf2dword (SUBSTR(ReturnBuffer, 5,4))
	? "Version Data:", SUBSTR(ReturnBuffer, 9)

* end of main


FUNCTION  getInfStyle (lnStyle)
	DO CASE
	CASE lnStyle = INF_STYLE_NONE
		RETURN "Unrecognized"
	CASE lnStyle = INF_STYLE_OLDNT
		RETURN "Old WinNT"
	CASE lnStyle = INF_STYLE_WIN4
		RETURN "Win4"
	ENDCASE
RETURN "#unknown INF style#"

FUNCTION  buf2dword (lcBuffer)
RETURN;
	Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216  
```  
***  


## Listed functions:
[SetupGetInfInformation](../libraries/setupapi/SetupGetInfInformation.md)  
