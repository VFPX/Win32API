* Library
************************************************
#INCLUDE apiviewer.h

PROCEDURE WriteSetting(cSetting, vParameter)
	vParameter = TRANSFORM(m.vParameter)

	UPDATE w32_settings;
	SET stvalue=m.vParameter;
	WHERE UPPER(ALLTRIM(stname))==UPPER(ALLTRIM(m.cSetting))
	
	IF _TALLY = 0
		INSERT INTO w32_settings (stname, stvalue);
		VALUES (m.cSetting, m.vParameter)
	ENDIF

PROCEDURE ReadSetting(cSetting)
	LOCAL nSelect, cResult
	nSelect = SELECT()

	SELECT w32_settings
	LOCATE ALL FOR UPPER(ALLTRIM(stname))==UPPER(ALLTRIM(m.cSetting))
	cResult = ALLTRIM(w32_settings.stvalue)
	
	SELECT (nSelect)
RETURN m.cResult

PROCEDURE EraseSetting(cSetting)
	UPDATE w32_settings SET stvalue="" WHERE UPPER(ALLTRIM(stname))==UPPER(ALLTRIM(m.cSetting))

PROCEDURE unuse(cAlias)
	IF USED(m.cAlias)
		USE IN (m.cAlias)
	ENDIF

FUNCTION GetTmpPath
	DECLARE INTEGER GetTempPath IN kernel32;
		INTEGER nBufferLength, STRING @lpBuffer

	DECLARE INTEGER GetLongPathName IN kernel32;
	    STRING lpszShort, STRING @lpszLong, INTEGER cchBuffer

	LOCAL cShort, cLong
	STORE REPLICATE(Chr(0), 512) TO cShort, cLong

	= GetTempPath(Len(cShort), @cShort)

	cShort = STRTRAN(cShort, Chr(0), "")
	= GetLongPathName(cShort, @cLong, LEN(cLong))
RETURN STRTRAN(cLong, Chr(0), "")

FUNCTION HighlightSyntax(cText)
	LOCAL nCount, nIndex, cResult, lFollowComment, lFollowRegular
	nCount = ALINES(arrSyntax, cText, CRLF)
	cResult=""
	
	FOR nIndex=1 TO nCount
		cLine = STRTRAN(STRTRAN(arrSyntax[nIndex], " ", ""), CHR(9),"")
		
		DO CASE
		CASE LEFT(cLine,1)="*"
			IF lFollowRegular
				cResult = cResult + arrSyntax[nIndex] + CRLF
				lFollowRegular = RIGHT(cLine,1)=";"
			ELSE
				cResult = cResult + "<span style='color: #00a000;'>" + arrSyntax[nIndex] + "</span>" + CRLF
				lFollowComment = RIGHT(cLine,1)=";"
			ENDIF

		CASE CHR(38)+CHR(38) $ cLine
			cResult = cResult + STRTRAN(arrSyntax[nIndex], CHR(38)+CHR(38),;
				"<span style='color: #00a000;'>" + CHR(38)+CHR(38), 1, 1) + "</span>" + CRLF

		OTHERWISE
			IF lFollowComment
				cResult = cResult + "<span style='color: #00a000;'>" + arrSyntax[nIndex] + "</span>" + CRLF
				lFollowComment = RIGHT(cLine,1)=";"
			ELSE
				cResult = cResult + arrSyntax[nIndex] + CRLF
				lFollowRegular = RIGHT(cLine,1)=";"
			ENDIF

		ENDCASE

	NEXT
RETURN m.cResult

FUNCTION HtmlSafe
PARAMETERS cInput, lLightMode
#DEFINE CRLF CHR(13)+CHR(10)

	LOCAL cSrc, cOutput, nIndex, ch
	cSrc = m.cInput

	DO WHILE LEFT(cSrc, 2) = CRLF
		cSrc = SUBSTR(cSrc, 3)
	ENDDO

	DO WHILE RIGHT(cSrc, 2) = CRLF
		cSrc = SUBSTR(cSrc, 1, LEN(cSrc)-2)
	ENDDO
 
	IF NOT m.lLightMode
		cSrc = STRTRAN(m.cSrc, "<", "&lt;")
		cSrc = STRTRAN(m.cSrc, ">", "&gt;")
	ENDIF

	cSrc = STRTRAN(m.cSrc, CHR(9), REPLICATE("&nbsp;", 4))
	cSrc = STRTRAN(m.cSrc, CRLF, "<BR>"+CRLF)
 
	cOutput=""
	FOR nIndex=1 TO LEN(cSrc)
		ch = SUBSTR(cSrc, nIndex, 1)
		IF ASC(ch) > 127
			cOutput = m.cOutput + "&#" + LTRIM(STR(ASC(m.ch))) + ";"
		ELSE
			cOutput = m.cOutput + m.ch
		ENDIF
	ENDFOR

RETURN m.cOutput

FUNCTION ExtendShortLinks(cText)
	cText = STRTRAN(cText, [<a href="?example=], [<a href="] + APIVIEWER_PROTOCOL + KEY_EXAMPLE)
	cText = STRTRAN(cText, [<img src="images/], [<img src="] + REFERENCE_URL_BASE + [images/])
RETURN m.cText

FUNCTION FunctionUrlLocal(nId)
RETURN APIVIEWER_PROTOCOL + KEY_FUNCTION + LTRIM(STR(m.nId))

FUNCTION GroupUrlLocal(nId)
RETURN APIVIEWER_PROTOCOL + KEY_GROUP + LTRIM(STR(m.nId))

FUNCTION LibraryUrlLocal(nId)
RETURN APIVIEWER_PROTOCOL + KEY_LIBRARY + LTRIM(STR(m.nId))

FUNCTION ExampleUrlLocal(nId)
RETURN APIVIEWER_PROTOCOL + KEY_EXAMPLE + LTRIM(STR(m.nId))

FUNCTION FunctionUrlRemote(nId)
RETURN REFERENCE_URL_BASE + "?function=" + LTRIM(STR(m.nId))

FUNCTION GroupUrlRemote(nId)
RETURN REFERENCE_URL_BASE + "?group=" + LTRIM(STR(m.nId))

FUNCTION ExampleUrlRemote(nId)
RETURN REFERENCE_URL_BASE + "?example=" + LTRIM(STR(m.nId))

FUNCTION GenerateCssFile
	LOCAL cFilename, cOutput
	cFilename = GetTmpPath() + APIVIEWER_CSS

SET TALK OFF
SET TEXTMERGE ON

TEXT TO m.cOutput NOSHOW
body
{
	padding-right: 0px;
	padding-left: 0px;
	font-size: 10pt;
	background: #ffffff;
	padding-bottom: 0px;
	margin: 0px;
	color: black;
	padding-top: 0px;
	font-family: verdana,arial,helv;
}

.normal
{
	padding-right: 0px;
	padding-left: 0px;
	font-size: 10pt;
	background: #ffffff;
	padding-bottom: 0px;
	margin: 0px;
	color: black;
	padding-top: 0px;
	font-family: verdana,arial,helv;
}

.topic_name
{
	padding-right: 20px;
	padding-left: 7px;
	font-weight: lighter;
	font-size: 14pt;
	margin-bottom: 10px;
	padding-bottom: 10px;
	padding-top: 7px;
	border-bottom: silver 1px solid;
	font-family: verdana,arial,helv;
	background-color: #99ccff;
}

.link_base
{
	padding-right: 10px;
	padding-left: 7px;
	font-size: 8pt;
	font-family: verdana,arial,helv;
}

.topic_description
{
	padding-right: 100px;
	padding-left: 7px;
	padding-bottom: 10px;
	padding-top: 3px;
	font-family: verdana,arial,helv;
	font-size: 11pt;
	margin-top: 10px;
	margin-bottom: 10px;
}

.function_declaration
{
	margin-left: 7px;
	padding-right: 30px;
	padding-left: 20px;
	font-size: 12pt;
	background: #e1ebff;
	margin-bottom: 10px;
	padding-bottom: 10px;
	color: #330066;
	padding-top: 7px;
	font-family: Monospace, Sans-Serif;
}

.function_subheader
{
	padding-right: 30px;
	border-top: silver 1px solid;
	margin-left: 7px;
	font-weight: 800;
	font-size: 11pt;
	margin-bottom: 5px;
	color: #cc6600;
	font-family: verdana,arial,helv;
}

.function_parameters
{
	padding-right: 200px;
	padding-left: 7px;
	font-size: 10pt;
	margin-bottom: 10px;
	padding-bottom: 10px;
	font-family: verdana,arial,helv;
}

.function_retvalue {
	padding-right: 200px;
	padding-left: 7px;
	padding-bottom: 10px;
	font-family: verdana,arial,helv;
	font-size: 10pt;
	margin-bottom: 10px;
}

.function_notes {
	padding-right: 30px;
	padding-left: 7px;
	padding-bottom: 10px;
	font-family: verdana,arial,helv;
	font-size: 10pt;
	margin-bottom: 10px;
}

.link_functionname
{
	padding-left: 20px;
	font-family: verdana,arial,helv;
	font-size: 10pt;
	margin-bottom: 5px;
}

.example_comments
{
	padding-right: 10px;
	padding-left: 10px;
	font-size: 10pt;
	background: #f4f5ff;
	color: #009900;
	padding-top: 7px;
	font-family: Monospace, Sans-Serif;
}

.cmt
{
	font-size: 10pt;
	background: #f4f5ff;
	color: #009900;
	font-family: Monospace, Sans-Serif;
}

.example_code {
	padding-right: 10px;
	padding-left: 10px;
	font-size: 10pt;
	background: #f4f5ff;
	padding-bottom: 20px;
	color: #330066;
	padding-top: 7px;
	font-family: Monospace, Sans-Serif;
}
.precode
{
	padding-left: 20px;
	font-size: 10pt;
	background: #e1ebff;
	padding-bottom: 10px;
	width: 100%;
	color: #330066;
	padding-top: 7px;
	font-family: Monospace, Sans-Serif;
}

.pagebottom
{
	padding-left: 7px;
	font-size: 7pt;
	color: darkgray;
	font-family: verdana,arial,helv;
}

.hl
{
	color: black;
	background-color: #ccff66;
}

ENDTEXT

	SET SAFETY OFF
	= STRTOFILE(m.cOutput, m.cFilename)
	SET SAFETY ON
RETURN m.cFilename
