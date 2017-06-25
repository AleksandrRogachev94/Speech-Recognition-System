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
#define strL_Path 512 // ����� ������ ���� �����.

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
#define SET_ZERO(Obj) { if(Obj!=NULL) ZeroMemory((PVOID)Obj,sizeof(*Obj));} // ��������� ������.
#define COPY(Dst,Src) { if(Dst!=NULL&&Src!=NULL) memcpy((void *)Dst,(void *)Src,sizeof(*Src));} // ����������� ��������.
#define SAFE_FREE_LIB(hLib) { if(hLib!=NULL) { FreeLibrary(hLib); hLib=NULL;}} // ���������� �������� ����������.
#define SAFE_CLOSE_FILE(Handle) { if(Handle!=INVALID_HANDLE_VALUE) { CloseHandle(Handle); Handle=INVALID_HANDLE_VALUE;}} // �������� �����.
#define SQRT(v) (v<SmCnst32_d?0.:sqrt(v)) // ���������� ����������� �����.
#define POW2D(x) ((double)(x)*(double)(x)) // �������.
#define LOG2(x) (float)(log((double)(x))/log(2.)) // �������� �� ��������� 2.
#define MIN(x,y) (x<y?x:y) // ���������� ��������.
#define MAX(x,y) (x>y?x:y) // ���������� ���������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������.

#define M_PI 3.1415926535897932384626433832795 // ����� "��".

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ���������.

#define messRet   255 // �������.
#define messNoMem 254 // ������������ ������.
#define messLrgAr 253 // ������� ������ �������.

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
// ����������� �����.

#define COL_BLACK    RGB(0,0,0)
#define COL_WHITE    RGB(255,255,255)
#define COL_GRAY     RGB(128,128,128)
#define COL_DK_GRAY  RGB(64,64,64)
#define COL_LT_GRAY  RGB(192,192,192)

#define COL_RED      RGB(255,0,0)
#define COL_GREEN    RGB(0,255,0)
#define COL_BLUE     RGB(0,0,255)

#define COL_YELLOW   RGB(255,255,0)
#define COL_SKY_BLUE RGB(0,255,255)
#define COL_VIOLET   RGB(255,0,255)

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �����.

#define nVoicesVowel 15 // ����� ������� � �������� ������.
#define nVoicesCons 16 // ����� �������� � ������� ��������� ������.
#define nVoices (nVoicesVowel+nVoicesCons) // ������ ����� ������.

// ���� ������.
#define nTypesSnd 7 // ����� ����� ������.
#define typSnd_Vowel     0 // ������� ����.
#define typSnd_Sonor     1 // �������� ����.
#define typSnd_ConsPulse 2 // ���������� ��������� ����.
#define typSnd_ConsTurb  3 // ������������ ��������� ����.
#define typSnd_ConsHiss  4 // ������� ��������� ����.
#define typSnd_ConsTone  5 // ������-������� ��������� ����.
#define typSnd_Silence   6 // ��������.

// ��������� ������� � �������� ������.
#define numSymbA  0
#define numSymbE  1
#define numSymbO  2
#define numSymbU  3
#define numSymbYI 4
#define numSymbYA 5
#define numSymbYE 6
#define numSymbYO 7
#define numSymbYU 8
#define numSymbI  9
#define numSymbL  10
#define numSymbM  11
#define numSymbN  12
#define numSymbR  13
#define numSymbV  14

// ��������� ��������� ���������� � ������� ������.
#define numSymbB  (0+nVoicesVowel)
#define numSymbP  (1+nVoicesVowel)
#define numSymbG  (2+nVoicesVowel)
#define numSymbK  (3+nVoicesVowel)
#define numSymbD  (4+nVoicesVowel)
#define numSymbT  (5+nVoicesVowel)
#define numSymbCH (6+nVoicesVowel)
#define numSymbC  (7+nVoicesVowel)
#define numSymbJ  (8+nVoicesVowel)
#define numSymbZ  (9+nVoicesVowel)
#define numSymbII (10+nVoicesVowel)
#define numSymbS  (11+nVoicesVowel)
#define numSymbF  (12+nVoicesVowel)
#define numSymbH  (13+nVoicesVowel)
#define numSymbSH (14+nVoicesVowel)
#define numSymbSCH (15+nVoicesVowel)

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� �������.

#define szMemMax 0xFFFFFFFF // ������������ ������ �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������.

#define nRecCharMax 512 // ����� ��������� �������� ��� ������������� � �������� �������.
#define nSzRecTextMax 100 // ����� �������� ������������� ������.
#define MaxSizeEdt SHRT_MAX // ������������ ������ ������ ��������� � ����������� (����).
#define AmpNormSound 5.0F // ��������� ���������� ��������� ����� ��� ���������.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������� ����.

// ���� ������.
#define dxWinText_Min 300
#define dyWinText_Min 300
#define dxWinText_Stand 450
#define dyWinText_Stand 300

// ��������� ����.
#define HeiFontText 20 // ������ ������ � ���� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������.

#define nCommands 9 // ����� ������.

#define commShutDownQ   0 // ���������� ���������� - ������.
#define commShutDown    1 // ���������� ���������� - �������������.
#define commCloseWin    2 // �������� ���� ���������.
#define commStopRec     3 // ��������� ������.
#define commShowHelp    4 // �������� ������� �� ���������.
#define commOpenNotepad 5 // ������� �������.
#define commOpenPaint   6 // ������� �������� �����������.
#define commOpenWord    7 // ������� 'WinWord'.
#define commOpenIE      8 // ������� 'Internet Explorer'.
