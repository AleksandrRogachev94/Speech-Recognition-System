//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ������� � ������ ��������.

typedef unsigned char BYTE;
typedef signed char SCHAR;
typedef short int SHRT;
typedef unsigned short int USHRT;
typedef unsigned long U_LONG;

typedef unsigned long PNT_DATA; // ��� ��� �������� ����������.

typedef char *typPntChar; // ��� - ��������� �� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������.

#define strL_Txt 256 // ����� ��������������� ������.
#define strL_FileName 128 // ����� ������ ����� �����.
#define strL_Path 512 // ����� ������ ���� �����.
#define szExt 6 // ����� ������ ���������� �����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������, �������� ��������� ����� ��� ������� ���������.

#define SmCnst4 1.e-4F
#define SmCnst10_d 1.e-10
#define SmCnst24_d 1.e-24
#define SmCnst32_d 1.e-32

#define LrgCnst32_d 1.e+32

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������.

#define SAFE_DELETE(Obj) { if(Obj!=NULL) { delete Obj; Obj=NULL;}} // ���������� ��������.
#define SAFE_DELETE_ARR(Arr) { if(Arr!=NULL) { delete[] Arr; Arr=NULL;}} // ���������� �������� �������.
#define SAFE_DELETE_OBJECT(Obj) { if(Obj!=NULL) { DeleteObject(Obj); Obj=NULL;}} // ���������� �������� �������.
#define SAFE_FREE(Obj) { if(Obj!=NULL) { free((void *)Obj); Obj=NULL;}} // ���������� ������������ ������.
#define SET_ZERO(Obj) { if(Obj!=NULL) ZeroMemory((PVOID)Obj,sizeof(*Obj));} // ��������� ������.
#define SAFE_CLOSE_FILE(Handle) { if(Handle!=INVALID_HANDLE_VALUE) { CloseHandle(Handle); Handle=INVALID_HANDLE_VALUE;}} // �������� �����.
#define COPY(Dst,Src) { if(Dst!=NULL&&Src!=NULL) memcpy((void *)Dst,(void *)Src,sizeof(*Src));} // ����������� ��������.
#define SAFE_FREE_LIB(hLib) { if(hLib!=NULL) { FreeLibrary(hLib); hLib=NULL;}} // ���������� �������� ����������.
#define MIN(x,y) (x<y?x:y) // ���������� ��������.
#define MAX(x,y) (x>y?x:y) // ���������� ���������.
#define ABS(x) (x>=0.?x:-x) // ���������� ������.
#define CHECK_LIM(x,xMin,xMax) (x<xMin?xMin:(x>xMax?xMax:x)) // �������� � ��������� �� ���������� �������� � ���������.
#define SQRT(v) (v<SmCnst32_d?0.:sqrt(v)) // ���������� ����������� �����.
#define POW2D(x) ((double)(x)*(double)(x)) // �������.
#define LOG2(x) (float)(log((double)(x))/log(2.)) // �������� �� ��������� 2.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������.

#define M_PI 3.1415926535897932384626433832795 // ����� "��".

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ���������.

#define messRet   255 // �������.
#define messNoMem 254 // ������������ ������.
#define messLrgAr 253 // ������� ������ �������.
#define messStop  252 // ���������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� �����.

#define COL_BLACK    RGB(0,0,0)
#define COL_WHITE    RGB(255,255,255)
#define COL_GRAY     RGB(128,128,128)
#define COL_DK_GRAY  RGB(64,64,64)
#define COL_LT_GRAY  RGB(192,192,192)

#define COL_RED      RGB(255,0,0)
#define COL_GREEN    RGB(0,255,0)
#define COL_BLUE     RGB(0,0,255)

#define COL_DK_RED   RGB(128,0,0)
#define COL_DK_GREEN RGB(0,128,0)
#define COL_DK_BLUE  RGB(0,0,128)

#define COL_VDK_RED   RGB(64,0,0)
#define COL_VDK_GREEN RGB(0,64,0)
#define COL_VDK_BLUE  RGB(0,0,64)

#define COL_YELLOW   RGB(255,255,0)
#define COL_SKY_BLUE RGB(0,255,255)
#define COL_VIOLET   RGB(255,0,255)
#define COL_BRICK    RGB(255,128,0)

#define COL_DK_YELLOW   RGB(128,128,0)
#define COL_DK_SKY_BLUE RGB(0,128,128)
#define COL_DK_VIOLET   RGB(128,0,128)
#define COL_DK_BRICK    RGB(128,64,0)

#define COL_VDK_YELLOW   RGB(64,64,0)
#define COL_VDK_SKY_BLUE RGB(0,64,64)
#define COL_VDK_VIOLET   RGB(64,0,64)

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ��������� � ���� 'MessageBox'.

#define MB_ST (MB_OK|MB_ICONSTOP|MB_APPLMODAL|MB_TOPMOST)        // ����.
#define MB_IN (MB_OK|MB_ICONINFORMATION|MB_APPLMODAL|MB_TOPMOST) // ����������.
#define MB_EX (MB_OK|MB_ICONEXCLAMATION|MB_APPLMODAL|MB_TOPMOST) // �����������.
#define MB_QU (MB_YESNO|MB_ICONQUESTION|MB_APPLMODAL|MB_TOPMOST) // ������ (��/���).
#define MB_QU_YNC (MB_YESNOCANCEL|MB_ICONQUESTION|MB_APPLMODAL|MB_TOPMOST) // ������ (��/���/������).

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ������� ����.

#define MF_GR (MF_BYCOMMAND|MF_GRAYED)
#define MF_EN (MF_BYCOMMAND|MF_ENABLED)
#define MF_CH (MF_BYCOMMAND|MF_CHECKED)
#define MF_UNCH (MF_BYCOMMAND|MF_UNCHECKED)

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ����������� DIB.

#define typBmp_24 0 // True Color.
#define typBmp_16 1 // 16 bits.
#define typBmp_8  2 // 8 bits (256 colors).
#define typBmp_4  3 // 4 bits (16 colors).
#define typBmp_1  4 // 1 bits (monochrome image).
#define typBmp_32 5 // 32 bits.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ���������� �������� �����������.

#define typDrawBMP_Stretch 0 // ��������������� ����������� ���������� ����� �� �������� ��������������.
#define typDrawBMP_Size    1 // ��������������� ����������� ���������� ���, ����� ����������� ���������, � ����������� ���������� � �������������.
#define typDrawBMP_Exact   2 // ������� ����������� �������� �����������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������������ ����� �������� ������������ �������������� (�� ����������� � ���������).

#define posH_Left 0
#define posH_Center 1
#define posH_Right 2

#define posV_Top 0
#define posV_Center 1
#define posV_Bottom 2

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������.

#define szMemMax 0xFFFFFFFF // ������������ ������ �������.

#define CH_FILT '|' // ������-����������� � ������ �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ������������ ������ ���������� ����� ������ ���������� � �������.

#define flFiltStr_Error    0 // ������ � ������ ��� �������.
#define flFiltStr_Exact    1 // ������ ����������� ���������� �������.
#define flFiltStr_List     2 // ������������ ������, �� �� ������� �������.
#define flFiltStr_NotFound 3 // �� ������� � ������.
#define flFiltStr_Any      4 // ������, ����� ����� �������� ��� �����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� ��� ������� ������.

#define nColB 9 // ����� �������� ������.
#define nPalStep 10 // ����� ������ ����� ��������� �������.
#define nColSmoothPal ((nColB-1)*nPalStep+1) // ����� ������ ���������� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������.

#define VelScrlPos 5 // ����������� �������� �������������.
#define AccScrlPos 100 // ����������� ����������� �������������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� �������.

#define IPE_MAX log(DBL_MAX) // ������������ ����������, ������ �������� �� ���� ����������.
#define MaxSizeEdt SHRT_MAX // ������������ ������ ������ ��������� � ����������� (����).
#define nRecCharMax 1024 // ����� ��������� �������� ��� ������������� � �������� �������.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ���������.

#define AmpNormSpectr_Stand 300.0F // ��������� ���������� ������� �� ���������.
#define AmpNormSig_Stand 10000.0F // ��������� ���������� ������� �� ���������.

#define szWinResDiag 18 // ������ ���� ������ ����������� ����������� �� ��������� �������.

#define AmpNormNeur_Stand 1.0F // ��������� ���������� ����������� ��������.
#define AmpNormInp_Stand 0.7F // ��������� ���������� ����������� ������ ��������.
#define AmpNormSynops_Stand 100.0F // ��������� ���������� ����������� ��������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ����������� ����.

#define FreqSynthesis_Stand 150.0F // ������� ����������� ���� �� ���������.
#define FreqSynthesis_Min 50.0F // ������� ����������� ���� �����������.
#define FreqSynthesis_Max 400.0F // ������� ����������� ���� ������������.
#define AmpSynthesis_Stand 500.0F // ��������� ����������� ���� �� ���������.
#define AmpSynthesis_Min 50.0F // ��������� ����������� ���� �����������.
#define AmpSynthesis_Max 3000.0F // ��������� ����������� ���� ������������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �����.

// ���� ��������� �������.
#define ColBkgDiag COL_WHITE // ���� ���� � ���� ���������.
#define ColCursorDiag COL_BLACK // ���� ������� � ���� ���������.
#define ColDiagLineSep COL_WHITE // ���� �����-����������� � ���� ���������.
#define ColDiagLineSymbBkg COL_BLACK // ���� ���� � ����� ������ �������� � ���� ���������.
#define ColDiagLineSndNoShow COL_WHITE // ���� ��� ���� �����, ������� �� ������ ������������ � ����� ������ �������� ���������.
#define ColCursorDiagLimDB_Ini COL_GREEN // ���� ������� ��������� ����� ��������� ����� � ���� ������.
#define ColCursorDiagLimDB_Fin COL_RED // ���� ������� �������� ����� ��������� ����� � ���� ������.

// ���� ������� �������.
#define ColBkgWinGraphSign COL_WHITE // ���� ���� � ���� ������� �������.
#define ColGraphSign COL_BLACK // ���� ������� �������.
#define ColCursorGraphSign COL_BLUE // ���� ������� � ���� ������� �������.

// ���� ������� �������.
#define ColBkgWinGraphSpectr COL_WHITE // ���� ���� � ���� ������� �������.
#define ColGraphSpectr COL_BLACK // ���� ������� �������.
#define ColPeaksGrSpectr COL_DK_RED // ���� ����� � ���� ������� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �����.

#define nVoicesVowel 15 // ����� ������� � �������� ������.
#define nVoicesCons 16 // ����� �������� � ������� ��������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ���������� ������� ������ ������.

#define errSoundResNNW 0.3F // ���������� ������ ��� ������������� ����� � ������� ������ �������� �������.
#define LevSoundDecStore 0.6F // ������� �������� ������� ��� ������������� ����� � ������ � ������ ������������ ����������.

#define tStVowel 1.0F // ����� ���������� (c) ��� ������� ������.
#define tStSonor 0.3F // ����� ���������� (c) ��� �������� ������.
#define tStPulse 0.1F // ����� ���������� (c) ��� ���������� ��������� ������.
#define tStTurb  0.3F // ����� ���������� (c) ��� ������������ ��������� ������.
#define tStHiss  0.3F // ����� ���������� (c) ��� ������� ��������� ������.
#define tStHTone 0.3F // ����� ���������� (c) ��� ������-������� ��������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������� ������� ������ ������.

#define methDecSnd_Inst  0 // ���������� ������, ���������� �� ���������� ��������.
#define methDecSnd_Store 1 // ����� � ����������� ����������.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������� ���������� ��������� �����.

#define nNeurons_Stand 10 // ����� �������� � ������� ���� �� ���������.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������� ����.

#define coeSzWinDiag 0.7F // ������������� ������ ���� ��������� �������.
#define coeSzWinSig 0.3F // ������������� ������ ���� �������.

// ���� ��������� ��������� ����.
#define dxViewNNW_Min 200
#define dyViewNNW_Min 200
#define dxViewNNW_Stand 800
#define dyViewNNW_Stand 600

// ���� ������.
#define dxWinText_Min 600
#define dyWinText_Min 600
#define dxWinText_Stand 900
#define dyWinText_Stand 600

// ��������� ����.
#define HeiFontText 20 // ������ ������ � ���� ������.
