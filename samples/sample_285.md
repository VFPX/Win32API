[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating ODBC drivers available on the local computer

## Code:
```foxpro  
PUBLIC objForm
objForm = CreateObject("Tform")
objForm.Visible = .T.

DEFINE CLASS Tform As Form
	Width=600
	Height=300
	Autocenter=.T.
	Caption="Local ODBC Environment"
	hEnv=0
	
	ADD OBJECT Label1 As Tlabel WITH;
	Top=3, Left=10, Caption="Drivers:"

	ADD OBJECT List1 As ListBox WITH;
	Left=5, Top=24, Width=230, Height=250

	ADD OBJECT Label2 As Tlabel WITH;
	Top=3, Left=250, Caption="Attributes:"
	
	ADD OBJECT List2 As ListBox WITH;
	Left=245, Top=24, Width=350, Height=250

PROCEDURE Init
	DECLARE SHORT SQLAllocEnv IN odbc32 INTEGER @env
	LOCAL hEnv
	hEnv=0

	* allocating an environment
	= SQLAllocEnv(@hEnv)

	IF hEnv = 0
		RETURN .F.
	ENDIF
	THIS.hEnv = hEnv

	THIS.RetrieveData
	THIS.DisplayDrivers
RETURN .T.

PROCEDURE Destroy
	DECLARE SHORT SQLFreeEnv IN odbc32 INTEGER env
	= SQLFreeEnv(THIS.hEnv)

PROCEDURE List1.InteractiveChange
	ThisForm.DisplayAttributes
RETURN

PROCEDURE DisplayDrivers
	WITH THIS.List1
		.RowSourcetype=2
		.RowSource="csDrivers"
		.BoundTo=.T.
		.BoundColumn=2
		.ColumnCount=1
		.ListIndex=1
		.InteractiveChange
	ENDWITH
RETURN

PROCEDURE DisplayAttributes
	SELECT attrname, attrvalue FROM csAttributes;
	WHERE driverno = VAL(THIS.List1.Value);
	INTO CURSOR csAttrSelected

	WITH THIS.List2
		.RowSourcetype=0
		.Clear
		.RowSourcetype=2
		.RowSource="csAttrSelected"
		.ColumnCount=2
		.ColumnWidths="150,350"
		.ListIndex=1
	ENDWITH
RETURN

PROCEDURE RetrieveData
#DEFINE SQL_FETCH_NEXT       1
#DEFINE SQL_FETCH_FIRST      2
#DEFINE SQL_ERROR           -1
#DEFINE SQL_INVALID_HANDLE  -2
#DEFINE SQL_NO_DATA        100
#DEFINE STRING_BUF_SIZE   4096

	DECLARE SHORT SQLDrivers IN odbc32;
		INTEGER EnvironmentHandle, INTEGER Direction,;
		STRING @DriverDescription, INTEGER BufferLength1,;
		INTEGER @DescriptionLengthPtr, STRING @DriverAttributes,;
		INTEGER BufferLength2, INTEGER @AttributesLengthPtr

	CREATE CURSOR csDrivers (drivername C(100), driverno I)
	CREATE CURSOR csAttributes (driverno I, attrname C(30), attrvalue C(100))
	LOCAL lcDescrBuffer, lcAttrBuffer, lnDescrSize, lnAttrSize,;
		lnResult, lnDrvIndex

	STORE Repli(Chr(0), STRING_BUF_SIZE) TO lcDescrBuffer, lcAttrBuffer
	STORE 0 TO lnDescrSize, lnAttrSize, lnDrvIndex
	
	lnResult = SQLDrivers(THIS.hEnv, SQL_FETCH_FIRST,;
		@lcDescrBuffer, STRING_BUF_SIZE, @lnDescrSize,;
		@lcAttrBuffer, STRING_BUF_SIZE, @lnAttrSize)

	DO WHILE Not INLIST(lnResult, SQL_NO_DATA, SQL_ERROR, SQL_INVALID_HANDLE)
		lcDescrBuffer = SUBSTR(lcDescrBuffer, 1, AT(Chr(0),lcDescrBuffer)-1)
		lcAttrBuffer = SUBSTR(lcAttrBuffer, 1,lnAttrSize)

		lnDrvIndex = lnDrvIndex + 1
		INSERT INTO csDrivers VALUES (lcDescrBuffer, lnDrvIndex)
		THIS.SaveAttributes(lnDrvIndex, lcAttrBuffer)
		
		STORE Repli(Chr(0), STRING_BUF_SIZE) TO lcDescrBuffer, lcAttrBuffer
		STORE 0 TO lnDescrSize, lnAttrSize

		lnResult = SQLDrivers(THIS.hEnv, SQL_FETCH_NEXT,;
			@lcDescrBuffer, STRING_BUF_SIZE, @lnDescrSize,;
			@lcAttrBuffer, STRING_BUF_SIZE, @lnAttrSize)
	ENDDO
RETURN

PROCEDURE SaveAttributes (lnDrvIndex, lcBuffer)
	LOCAL lnCount, lnPos1, lnPos2, lcAttr, lcAttrName, lcAttrValue
	
	lnCount = 1
	lnPos1 = 0
	DO WHILE .T.
		lnPos2 = AT(Chr(0), lcBuffer, lnCount)
		IF lnPos2 = 0
			EXIT
		ENDIF
		
		lcAttr = SUBSTR(lcBuffer, lnPos1+1, lnPos2-lnPos1-1)
		lcAttrName = SUBSTR(lcAttr, 1, AT("=",lcAttr)-1)
		lcAttrValue = SUBSTR(lcAttr, AT("=",lcAttr)+1)

		INSERT INTO csAttributes;
		VALUES (lnDrvIndex, lcAttrName, lcAttrValue)

		lnCount = lnCount + 1
		lnPos1 = lnPos2
	ENDDO
RETURN
ENDDEFINE

DEFINE CLASS Tlabel As Label
	Fontname="Arial"
	Fontsize=10
	FontBold=.F.
	Autosize=.T.
ENDDEFINE  
```  
***  


## Listed functions:
[SQLAllocEnv](../libraries/odbc32/SQLAllocEnv.md)  
[SQLDrivers](../libraries/odbc32/SQLDrivers.md)  
[SQLFreeEnv](../libraries/odbc32/SQLFreeEnv.md)  
