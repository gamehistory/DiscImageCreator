/*
 * This code is released under the Microsoft Public License (MS-PL). See License.txt, below.
 */
#pragma once
#include "forwardDeclaration.h"

#define BOOLEAN_TO_STRING_TRUE_FALSE_W(_b_)		((_b_) ? _T("True") : _T("False"))
#define BOOLEAN_TO_STRING_TRUE_FALSE_A(_b_)		((_b_) ? "True" : "False")
#define BOOLEAN_TO_STRING_YES_NO_W(_b_)			((_b_) ? _T("Yes") : _T("No"))
#define BOOLEAN_TO_STRING_YES_NO_A(_b_)			((_b_) ? "Yes" : "No")

#define STR_DOUBLE_HYPHEN_B		"========== "
#define STR_DOUBLE_HYPHEN_E		" ==========\n"
#define STR_LBA					"LBA[%06d, %#07x], "
#define STR_SUBCH				"SubCh[%02x], "
#define STR_TRACK				"Track[%02u]: "
#define STR_SUB					"Sub"
#define STR_NO_SUPPORT			" doesn't support on this drive\n"

#define OUTPUT_DHYPHEN_PLUS_STR(str)				STR_DOUBLE_HYPHEN_B #str STR_DOUBLE_HYPHEN_E
#define OUTPUT_DHYPHEN_PLUS_STR_WITH_LBA_F(str)		STR_DOUBLE_HYPHEN_B STR_LBA #str STR_DOUBLE_HYPHEN_E
#define OUTPUT_DHYPHEN_PLUS_STR_WITH_SUBCH_F(str)	STR_DOUBLE_HYPHEN_B STR_SUBCH #str STR_DOUBLE_HYPHEN_E
#define OUTPUT_DHYPHEN_PLUS_STR_WITH_TRACK_F(str)	STR_DOUBLE_HYPHEN_B STR_TRACK #str STR_DOUBLE_HYPHEN_E
#define OUTPUT_DHYPHEN_PLUS_STR_WITH_LBA			STR_DOUBLE_HYPHEN_B STR_LBA "%s" STR_DOUBLE_HYPHEN_E
#define OUTPUT_DHYPHEN_PLUS_STR_WITH_SUBCH			STR_DOUBLE_HYPHEN_B STR_SUBCH "%s" STR_DOUBLE_HYPHEN_E
#define OUTPUT_DHYPHEN_PLUS_STR_WITH_TRACK			STR_DOUBLE_HYPHEN_B STR_TRACK "%s" STR_DOUBLE_HYPHEN_E
#define OUTPUT_STR_NO_SUPPORT(str)					#str STR_NO_SUPPORT

#define OutputStringW(str, ...)		_tprintf(str, __VA_ARGS__);
#define OutputStringA(str, ...)		printf(str, __VA_ARGS__);

#ifdef _DEBUG
#define FlushLog()

extern WCHAR logBufferW[DISC_RAW_READ_SIZE];
extern CHAR logBufferA[DISC_RAW_READ_SIZE];
#define OutputDebugStringExW(str, ...) \
{ \
	_snwprintf(logBufferW, DISC_RAW_READ_SIZE, str, __VA_ARGS__); \
	logBufferW[2047] = 0; \
	OutputDebugStringW(logBufferW); \
}
#define OutputDebugStringExA(str, ...) \
{ \
	_snprintf(logBufferA, DISC_RAW_READ_SIZE, str, __VA_ARGS__); \
	logBufferA[2047] = 0; \
	OutputDebugStringA(logBufferA); \
}
#define OutputDebugStringWithLBAExA(str, nLBA, track, ...) \
{ \
	_snprintf(logBufferA, DISC_RAW_READ_SIZE, str, nLBA, nLBA, track, __VA_ARGS__); \
	logBufferA[2047] = 0; \
	OutputDebugStringA(logBufferA); \
}
#define OutputDebugStringWithLBAEx2A(str, nLBA, ...) \
{ \
	_snprintf(logBufferA, DISC_RAW_READ_SIZE, str, nLBA, nLBA, __VA_ARGS__); \
	logBufferA[2047] = 0; \
	OutputDebugStringA(logBufferA); \
}

#define OutputErrorStringW(str, ...)	OutputDebugStringExW(str, __VA_ARGS__)
#define OutputErrorStringA(str, ...)	OutputDebugStringExA(str, __VA_ARGS__)
#define OutputDiscLogW(str, ...)		OutputDebugStringExW(str, __VA_ARGS__)
#define OutputDiscLogA(str, ...)		OutputDebugStringExA(str, __VA_ARGS__)
#define OutputDiscWithLBALogA(str1, str2, nLBA, ...) \
	OutputDebugStringWithLBAExA(OUTPUT_DHYPHEN_PLUS_STR_WITH_LBA_F(str1) str2, nLBA, __VA_ARGS__);

#define OutputVolDescLogW(str, ...)		OutputDebugStringExW(str, __VA_ARGS__)
#define OutputVolDescLogA(str, ...)		OutputDebugStringExA(str, __VA_ARGS__)
#define OutputVolDescWithLBALogA(str1, str2, nLBA, ...) \
	OutputDebugStringWithLBAExA(OUTPUT_DHYPHEN_PLUS_STR_WITH_LBA_F(str1) str2, nLBA, __VA_ARGS__);

#define OutputDriveLogW(str, ...)		OutputDebugStringExW(str, __VA_ARGS__)
#define OutputDriveLogA(str, ...)		OutputDebugStringExA(str, __VA_ARGS__)
#define OutputDriveNoSupportLogA(str, ...) \
	OutputDebugStringExA(OUTPUT_STR_NO_SUPPORT(str), __VA_ARGS__);

#define OutputMainInfoLogW(str, ...)	OutputDebugStringExW(str, __VA_ARGS__)
#define OutputMainInfoLogA(str, ...)	OutputDebugStringExA(str, __VA_ARGS__)
#define OutputMainInfoWithLBALogA(str, nLBA, track, ...) \
	OutputDebugStringWithLBAExA(STR_LBA STR_TRACK str, nLBA, track, __VA_ARGS__)

#define OutputMainErrorLogW(str, ...)	OutputDebugStringExW(str, __VA_ARGS__)
#define OutputMainErrorLogA(str, ...)	OutputDebugStringExA(str, __VA_ARGS__)
#define OutputMainErrorWithLBALogA(str, nLBA, track, ...) \
	OutputDebugStringWithLBAExA(STR_LBA STR_TRACK str, nLBA, track, __VA_ARGS__)

#define OutputSubInfoLogW(str, ...)		OutputDebugStringExW(str, __VA_ARGS__)
#define OutputSubInfoLogA(str, ...)		OutputDebugStringExA(str, __VA_ARGS__)
#define OutputSubInfoWithLBALogA(str, nLBA, track, ...) \
	OutputDebugStringWithLBAExA(STR_LBA STR_TRACK str, nLBA, track, __VA_ARGS__)

#define OutputSubErrorLogW(str, ...)	OutputDebugStringExW(str, __VA_ARGS__)
#define OutputSubErrorLogA(str, ...)	OutputDebugStringExA(str, __VA_ARGS__)
#define OutputSubErrorWithLBALogA(str, nLBA, track, ...) \
	OutputDebugStringWithLBAExA(STR_LBA STR_TRACK STR_SUB str, nLBA, track, __VA_ARGS__)

#define OutputC2ErrorLogW(str, ...)		OutputDebugStringExW(str, __VA_ARGS__)
#define OutputC2ErrorLogA(str, ...)		OutputDebugStringExA(str, __VA_ARGS__)
#define OutputC2ErrorWithLBALogA(str, nLBA, ...) \
	OutputDebugStringWithLBAEx2A(STR_LBA str, nLBA, __VA_ARGS__);

#define OutputLogW(type, str, ...)		OutputDebugStringExW(str, __VA_ARGS__)
#define OutputLogA(type, str, ...)		OutputDebugStringExA(str, __VA_ARGS__)
#else
// If it uses g_LogFile, call InitLogFile()
extern _LOG_FILE g_LogFile;
#define FlushLog() \
{ \
	fflush(g_LogFile.fpDisc); \
	fflush(g_LogFile.fpVolDesc); \
	fflush(g_LogFile.fpDrive); \
	fflush(g_LogFile.fpMainInfo); \
	fflush(g_LogFile.fpMainError); \
	fflush(g_LogFile.fpSubInfo); \
	fflush(g_LogFile.fpSubError); \
	fflush(g_LogFile.fpC2Error); \
}

#define OutputErrorStringW(str, ...)	fwprintf(stderr, str, __VA_ARGS__);
#define OutputErrorStringA(str, ...)	fprintf(stderr, str, __VA_ARGS__);

#define OutputDiscLogW(str, ...)		fwprintf(g_LogFile.fpDisc, str, __VA_ARGS__);
#define OutputDiscLogA(str, ...)		fprintf(g_LogFile.fpDisc, str, __VA_ARGS__);
#define OutputDiscWithLBALogA(str1, str2, nLBA, ...) \
	fprintf(g_LogFile.fpDisc, OUTPUT_DHYPHEN_PLUS_STR_WITH_LBA_F(str1) str2, nLBA, nLBA, __VA_ARGS__);

#define OutputVolDescLogW(str, ...)		fwprintf(g_LogFile.fpVolDesc, str, __VA_ARGS__);
#define OutputVolDescLogA(str, ...)		fprintf(g_LogFile.fpVolDesc, str, __VA_ARGS__);
#define OutputVolDescWithLBALogA(str1, str2, nLBA, ...) \
	fprintf(g_LogFile.fpVolDesc, OUTPUT_DHYPHEN_PLUS_STR_WITH_LBA_F(str1) str2, nLBA, nLBA, __VA_ARGS__);

#define OutputDriveLogW(str, ...)		fwprintf(g_LogFile.fpDrive, str, __VA_ARGS__);
#define OutputDriveLogA(str, ...)		fprintf(g_LogFile.fpDrive, str, __VA_ARGS__);
#define OutputDriveNoSupportLogA(str, ...) \
	fprintf(g_LogFile.fpDrive, OUTPUT_STR_NO_SUPPORT(str), __VA_ARGS__);

#define OutputMainInfoLogW(str, ...)	fwprintf(g_LogFile.fpMainInfo, str, __VA_ARGS__);
#define OutputMainInfoLogA(str, ...)	fprintf(g_LogFile.fpMainInfo, str, __VA_ARGS__);
#define OutputMainInfoWithLBALogA(str, nLBA, track, ...) \
	fprintf(g_LogFile.fpMainInfo, STR_LBA STR_TRACK str, nLBA, nLBA, track, __VA_ARGS__);

#define OutputMainErrorLogW(str, ...)	fwprintf(g_LogFile.fpMainError, str, __VA_ARGS__);
#define OutputMainErrorLogA(str, ...)	fprintf(g_LogFile.fpMainError, str, __VA_ARGS__);
#define OutputMainErrorWithLBALogA(str, nLBA, track, ...) \
	fprintf(g_LogFile.fpMainError, STR_LBA STR_TRACK str, nLBA, nLBA, track, __VA_ARGS__);

#define OutputSubInfoLogW(str, ...)		fwprintf(g_LogFile.fpSubInfo, str, __VA_ARGS__);
#define OutputSubInfoLogA(str, ...)		fprintf(g_LogFile.fpSubInfo, str, __VA_ARGS__);
#define OutputSubInfoWithLBALogA(str, nLBA, track, ...) \
	fprintf(g_LogFile.fpSubInfo, STR_LBA STR_TRACK str, nLBA, nLBA, track, __VA_ARGS__);

#define OutputSubErrorLogW(str, ...)	fwprintf(g_LogFile.fpSubError, str, __VA_ARGS__);
#define OutputSubErrorWithLBALogA(str, nLBA, track, ...) \
	fprintf(g_LogFile.fpSubError, STR_LBA STR_TRACK STR_SUB str, nLBA, nLBA, track, __VA_ARGS__);
#define OutputSubErrorLogA(str, ...)	fprintf(g_LogFile.fpSubError, str, __VA_ARGS__);

#define OutputC2ErrorLogW(str, ...)		fwprintf(g_LogFile.fpC2Error, str, __VA_ARGS__);
#define OutputC2ErrorLogA(str, ...)		fprintf(g_LogFile.fpC2Error, str, __VA_ARGS__);
#define OutputC2ErrorWithLBALogA(str, nLBA, ...) \
	fprintf(g_LogFile.fpC2Error, STR_LBA str, nLBA, nLBA, __VA_ARGS__);

#define OutputLogW(type, str, ...) \
{ \
	INT t = type; \
	if ((t & standardOut) == standardOut) { \
		OutputStringW(str, __VA_ARGS__); \
	} \
	if ((t & standardErr) == standardErr) { \
		OutputErrorStringW(str, __VA_ARGS__); \
	} \
	if ((t & fileDisc) == fileDisc) { \
		OutputDiscLogW(str, __VA_ARGS__); \
	} \
	if ((t & fileVolDesc) == fileVolDesc) { \
		OutputVolDescLogW(str, __VA_ARGS__); \
	} \
	if ((t & fileDrive) == fileDrive) { \
		OutputDriveLogW(str, __VA_ARGS__); \
	} \
	if ((t & fileMainInfo) == fileMainInfo) { \
		OutputMainInfoLogW(str, __VA_ARGS__); \
	} \
	if ((t & fileMainError) == fileMainError) { \
		OutputMainErrorLogW(str, __VA_ARGS__); \
	} \
	if ((t & fileSubInfo) == fileSubInfo) { \
		OutputSubInfoLogW(str, __VA_ARGS__); \
	} \
	if ((t & fileSubError) == fileSubError) { \
		OutputSubErrorLogW(str, __VA_ARGS__); \
	} \
	if ((t & fileC2Error) == fileC2Error) { \
		OutputC2ErrorLogW(str, __VA_ARGS__); \
	} \
}
#define OutputLogA(type, str, ...) \
{ \
	INT t = type; \
	if ((t & standardOut) == standardOut) { \
		OutputStringA(str, __VA_ARGS__); \
	} \
	if ((t & standardErr) == standardErr) { \
		OutputErrorStringA(str, __VA_ARGS__); \
	} \
	if ((t & fileDisc) == fileDisc) { \
		OutputDiscLogA(str, __VA_ARGS__); \
	} \
	if ((t & fileVolDesc) == fileVolDesc) { \
		OutputVolDescLogA(str, __VA_ARGS__); \
	} \
	if ((t & fileDrive) == fileDrive) { \
		OutputDriveLogA(str, __VA_ARGS__); \
	} \
	if ((t & fileMainInfo) == fileMainInfo) { \
		OutputMainInfoLogA(str, __VA_ARGS__); \
	} \
	if ((t & fileMainError) == fileMainError) { \
		OutputMainErrorLogA(str, __VA_ARGS__); \
	} \
	if ((t & fileSubInfo) == fileSubInfo) { \
		OutputSubInfoLogA(str, __VA_ARGS__); \
	} \
	if ((t & fileSubError) == fileSubError) { \
		OutputSubErrorLogA(str, __VA_ARGS__); \
	} \
	if ((t & fileC2Error) == fileC2Error) { \
		OutputC2ErrorLogA(str, __VA_ARGS__); \
	} \
}
#endif

#ifdef UNICODE
#define WFLAG "w, ccs=UTF-8"
#define AFLAG "a, ccs=UTF-8"
#define BOOLEAN_TO_STRING_TRUE_FALSE	BOOLEAN_TO_STRING_TRUE_FALSE_W
#define BOOLEAN_TO_STRING_YES_NO		BOOLEAN_TO_STRING_YES_NO_W
#define OutputString		OutputStringW
#define OutputErrorString	OutputErrorStringW
#define OutputDiscLog		OutputDiscLogW
#define OutputVolDescLog	OutputVolDescLogW
#define OutputDriveLog		OutputDriveLogW
#define OutputMainInfoLog	OutputMainInfoLogW
#define OutputMainErrorLog	OutputMainErrorLogW
#define OutputSubInfoLog	OutputSubInfoLogW
#define OutputSubErrorLog	OutputSubErrorLogW
#define OutputC2ErrorLog	OutputC2ErrorLogW
#define OutputLog			OutputLogW
#else
#define WFLAG "w"
#define AFLAG "a"
#define BOOLEAN_TO_STRING_TRUE_FALSE	BOOLEAN_TO_STRING_TRUE_FALSE_A
#define BOOLEAN_TO_STRING_YES_NO		BOOLEAN_TO_STRING_YES_NO_A
#define OutputString		OutputStringA
#define OutputErrorString	OutputErrorStringA
#define OutputDiscLog		OutputDiscLogA
#define OutputVolDescLog	OutputVolDescLogA
#define OutputDriveLog		OutputDriveLogA
#define OutputMainInfoLog	OutputMainInfoLogA
#define OutputMainErrorLog	OutputMainErrorLogA
#define OutputSubInfoLog	OutputSubInfoLogA
#define OutputSubErrorLog	OutputSubErrorLogA
#define OutputC2ErrorLog	OutputC2ErrorLogA
#define OutputLog			OutputLogA
#endif

#define FcloseAndNull(fp) \
{ \
	if (fp) { \
		fclose(fp); \
		fp = NULL; \
	} \
}

#define FreeAndNull(lpBuf) \
{ \
	if (lpBuf) { \
		free(lpBuf); \
		lpBuf = NULL; \
	} \
}

FILE* CreateOrOpenFile(
	LPCTSTR pszPath,
	LPCTSTR pszPlusFname,
	LPTSTR pszOutPath,
	LPTSTR pszFname,
	LPTSTR pszFnameAndExt,
	LPCTSTR pszExt,
	LPCTSTR pszMode,
	BYTE byTrackNum,
	BYTE byMaxTrackNum
	);

FILE* CreateOrOpenFileW(
	LPCWSTR pszPath,
	LPCWSTR pszPlusFname,
	LPWSTR pszOutPath,
	LPWSTR pszFname,
	LPWSTR pszFnameAndExt,
	LPCWSTR pszExt,
	LPCWSTR pszMode,
	BYTE byTrackNum,
	BYTE byMaxTrackNum
	);

FILE* CreateOrOpenFileA(
	LPCSTR pszPath,
	LPCSTR pszPlusFname,
	LPSTR pszOutPath,
	LPSTR pszFname,
	LPSTR pszFnameAndExt,
	LPCSTR pszExt,
	LPCSTR pszMode,
	BYTE byTrackNum,
	BYTE byMaxTrackNum
	);

FILE* OpenProgrammabledFile(
	LPCTSTR pszFname,
	LPCTSTR pszMode
	);

FILE* OpenProgrammabledFileW(
	LPCWSTR pszFname,
	LPCWSTR pszMode
	);

VOID WriteCcdForDisc(
	WORD wTocEntries,
	BYTE LastCompleteSession,
	FILE* fpCcd
	);

VOID WriteCcdForDiscCDTextLength(
	WORD wCDTextLength,
	FILE* fpCcd
	);

VOID WriteCcdForDiscCatalog(
	PDISC pDisc,
	FILE* fpCcd
	);

VOID WriteCcdForCDText(
	WORD dwTocTextEntries,
	FILE* fpCcd
	);

VOID WriteCcdForCDTextEntry(
	PCDROM_TOC_CD_TEXT_DATA_BLOCK pDesc,
	WORD dwTocTextEntries,
	FILE* fpCcd
	);

VOID WriteCcdForSession(
	BYTE SessionNumber,
	BYTE byMode,
	FILE* fpCcd
	);

VOID WriteCcdForEntry(
	PCDROM_TOC_FULL_TOC_DATA_BLOCK toc,
	UINT a,
	FILE* fpCcd
	);

VOID WriteMainChannel(
	PEXT_ARG pExtArg,
	PDISC pDisc,
	LPBYTE lpBuf,
	INT nLBA,
	FILE* fpImg
	);

VOID WriteC2(
	PEXT_ARG pExtArg,
	PDISC pDisc,
	LPBYTE lpBuf,
	INT nLBA,
	FILE* fpC2
	);

VOID WriteSubChannel(
	PDISC pDisc,
	LPBYTE lpSubcodeRaw,
	LPBYTE lpSubcode,
	INT nLBA,
	BYTE byCurrentTrackNum,
	FILE* fpSub,
	FILE* fpParse
	);

VOID WriteErrorBuffer(
	PEXEC_TYPE pExecType,
	PEXT_ARG pExtArg,
	PDEVICE pDevice,
	PDISC pDisc,
	PDISC_PER_SECTOR pDiscPerSector,
	LPBYTE lpScrambledBuf,
	INT nLBA,
	FILE* fpImg,
	FILE* fpSub,
	FILE* fpC2
	);

BOOL WriteParsingSubfile(
	LPCTSTR pszSubfile
	);

BOOL DescrambleMainChannelForGD(
	LPCTSTR pszPath
	);

BOOL SplitFileForGD(
	LPCTSTR pszPath
	);

VOID DescrambleMainChannel(
	PEXT_ARG pExtArg,
	PDISC pDisc,
	LPBYTE lpScrambledBuf,
	FILE* fpImg
	);

BOOL CreateBinCueCcd(
	PEXT_ARG pExtArg,
	PDISC pDisc,
	LPCTSTR pszPath,
	LPCTSTR pszImgName,
	BOOL bCanCDText,
	FILE* fpImg,
	FILE* fpCue,
	FILE* fpCueForImg,
	FILE* fpCcd
	);

VOID OutputHashData(
	FILE* fpHash,
	LPCTSTR filename,
	UINT64 ui64FileSize,
	DWORD crc32,
	LPBYTE digest,
	LPBYTE Message_Digest
	);

VOID OutputLastErrorNumAndString(
	LPCTSTR pszFuncName,
	LONG lLineNum
	);

BOOL OutputWindowsVer(
	);
