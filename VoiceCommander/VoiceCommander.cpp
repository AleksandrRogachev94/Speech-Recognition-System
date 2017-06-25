/*...........................................................................................................

WinMain,InitCommonControls_,
RegisterClassAll,RegisterClassMain,RegisterClassText,
InitMain,

// ����� �������� ����.
class clMain {
clMain,~clMain,Zero,Free,
ZeroBrushes,FreeBrushes,CreateBrushes,
ZeroMenu,FreeMenu,CreateMenu,ShowMenu,
ZeroHelp,FreeHelp,CreateHelp,ChMenuHelp,
OnCreate,CreateDlgCntrl,GetMinSizeWin,SetMinSize,MoveWinCorner,
MsgCommand,MsgCommandCntrl,Command,CommandCntrl,OnPaint,
ZeroSndCapData,FreeSndCapData,CreateSndCapData,
ZeroSndCap,FreeSndCap,CreateSndCap,SaveBufSound,StartCaptureSound,StopCaptureSound,StopCaptureSound_,
ChBtnMenuCaptureSound,SetTxtBtnRecSound,DlgAdjSound,ProcRecRealTime,GetNumSndRecogn,ShowProgr,
LoadNNW,LoadDict,
SetPntWinText,GetSizeWinText,OpenWinText,ChMenuWinText,ClearWinText,SetWinText,
RecognTxtCommand,AddSymbTextWin,AddWordTextWin,DoCommand,OpenSysProg,OpenProgFiles,ShowCommand,SetText,
SetWord,SetString,ChMenuDoCommands,ChMenuOutWords,OnCloseWin},
FunSndCap_CallBack,DecSnd_Store,
WndProcMain,DlgProcCntrlMain,

// ����� ��� ���� ������ �������������.
class clWinText {
clWinText,~clWinText,Zero,SetParPnt,
ZeroBrushes,FreeBrushes,CreateBrushes,
CreateWindow,CloseWindow,OnCloseWin,GetMinSizeWin,SetMinSize,
CreateEdt,CloseEdt,ChPosSizeChWin,SetPosSizeChWin,SetText,ClearWin,MsgCommand},
WndViewText,

DlgAbout,GetPath

...........................................................................................................*/

#include "stdafx.h"
#include <shlobj.h>

#include "VC_con.h"
#include "cmplx.h"
#include "VC_cls.h"
#include "VC_pro.h"
#include "VC_snd.h"
#include "VC.h"
#include "resource.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������.

BYTE AllocString(char **Str,size_t ln); // ��������� ������ ��� ������.
void FreeString(char **Str); // ������������ ������ ��� ������.
BYTE AllocSHRT(SHRT **shipp,size_t ln); // ��������� ������ ��� ������� 'SHRT'.
void FreeSHRT(SHRT **shipp); // ������������ ������ ��� ������� 'SHRT'.
BYTE AllocFloat(float **fpp,size_t ln); // ��������� ������ ��� ������� 'float'.
void FreeFloat(float **fpp); // ������������ ������ ��� ������� 'float'.
BYTE AllocComplex(complex **cpp,size_t ln); // ��������� ������ ��� ������� 'complex'.
void FreeComplex(complex **cpp); // ������������ ������ ��� ������� 'complex'.
BYTE IsOKStr(char *str); // �������� ������.
BYTE GetString(char **String,char **Items,BYTE n); // ������ ������ �� ���������� �����.
void ImgWinC(HWND hwnd,DWORD ColP,DWORD ColB); // ������������ ����.
void SetStMenuItem_(HMENU hMenu,UINT id,SCHAR En,SCHAR Ch); // ��������� ��������� ������ ����.
void CloseWin_(HWND *hwnd); // �������� ����.
void DestroyWin_(HWND *hwnd); // ����������� ���� � ���������� 'hwnd'.
void ShowWin(HWND hwnd,BYTE flVis); // ����������� ��� ������� ����.
BYTE SetPosWindow(HWND hwnd,RECT *rc); // ��������� ������������ ����.
void SetPosWindowCenter(HWND hDlg); // ��������� ���� � ����� ������� ���� ��� ������.
BYTE CheckWindowSize(HWND hwnd,int dxm,int dym); // ��������� ������������ ������� ����.
HWND InitProgress(HWND hDlg,int id); // ������������� ���� ������ �������� ���������� ������.
void SetColProgr(HWND hwnd,DWORD BkgCol,DWORD BarCol); // ��������� ������ ������������ ������ ������ �������� ���������� ������.
USHRT GetUSHRT_Test(int iv); // ��������� ����� 'USHRT' �� ����� 'int' � ��������� ������ �� ������� 'USHRT'.
USHRT GetUSHRT_Test(double d); // ��������� ����� 'USHRT' �� ����� 'double' � ��������� ������ �� ������� 'USHRT'.
UINT GetUINT_Test(float v); // ��������� ����� 'UINT' �� ����� 'float' � ��������� ������ �� ������� 'UINT'.
void Message(UINT StrID,UINT typ); // ����� ���������.
void ErrMessage(void); // ������ ��������� �� ������.
void SoundBlock(void); // ���� ��� ��������������� ��������.
void ProcMess(void); // ����� ������� ��������� � ��������� ���������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� ����������.

HINSTANCE hInst; // ������������� ����������.
LRESULT LRes; // ��������������� ����������.

// ������� ������ ����������.
HCURSOR cur_wait;

BYTE methDecSound=methDecSnd_Store; // ����� ��������� ������ ������.

DWORD ColDial; // ���� ���� ��� ����������� ����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������.

// �������������� �������� ������.
int IDA_Commands[nCommands]={IDS_Command_ShutDownQuest,IDS_Command_ShutDown,IDS_Command_CloseWin,
IDS_Command_StopRec,IDS_Command_ShowHelp,IDS_Command_OpenNotepad,IDS_Command_OpenPaint,IDS_Command_OpenWord,
IDS_Command_IntExpl};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ � ���������.

clMain MW;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ��� ������� ������ ������ ��� �����.
//struct strParAnSnd { char Symb; BYTE type; float tStore,weiStore,weiInst; BYTE nCntSymb,nCntNoSymb;};

struct strParAnSnd ParAnSnd[nVoices+1]={
// ������� �����.
{'�',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'�',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'�',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'�',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'�',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'�',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'�',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'�',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'�',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'�',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
// �������� �����.
{'�',typSnd_Sonor,tStSonor,     weiStoreSonor,weiInstSonor, nCntSymbSonor,nCntNoSymbSonor},
{'�',typSnd_Sonor,tStSonor,     weiStoreSonor,weiInstSonor, nCntSymbSonor,nCntNoSymbSonor},
{'�',typSnd_Sonor,tStSonor,     weiStoreSonor,weiInstSonor, nCntSymbSonor,nCntNoSymbSonor},
{'�',typSnd_Sonor,tStSonor,     weiStoreSonor,weiInstSonor, nCntSymbSonor,nCntNoSymbSonor},
{'�',typSnd_Sonor,tStSonor,     weiStoreSonor,weiInstSonor, nCntSymbSonor,nCntNoSymbSonor},
// ���������� ��������� �����.
{'�',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'�',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'�',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'�',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'�',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'�',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'�',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'�',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
// ������������ ��������� �����.
{'�',typSnd_ConsTone,tStHTone,  weiStoreTone,weiInstTone,   nCntSymbTone,nCntNoSymbTone},
{'�',typSnd_ConsTone,tStHTone,  weiStoreTone,weiInstTone,   nCntSymbTone,nCntNoSymbTone},
{'�',typSnd_ConsTone,tStHTone,  weiStoreTone,weiInstTone,   nCntSymbTone,nCntNoSymbTone},
// ������� ��������� �����.
{'�',typSnd_ConsTurb,tStTurb,   weiStoreTurb,weiInstTurb,   nCntSymbTurb,nCntNoSymbTurb},
{'�',typSnd_ConsTurb,tStTurb,   weiStoreTurb,weiInstTurb,   nCntSymbTurb,nCntNoSymbTurb},
{'�',typSnd_ConsTurb,tStTurb,   weiStoreTurb,weiInstTurb,   nCntSymbTurb,nCntNoSymbTurb},
// ������-������� ��������� �����.
{'�',typSnd_ConsHiss,tStHiss,   weiStoreHiss,weiInstHiss,   nCntSymbHiss,nCntNoSymbHiss},
{'�',typSnd_ConsHiss,tStHiss,   weiStoreHiss,weiInstHiss,   nCntSymbHiss,nCntNoSymbHiss},
// ��������.
{' ',typSnd_Silence,tStSilence, 0.0F,0.0F, nCntSymbSilence,nCntNoSymbSilence}
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������.

char TxtStr[strL_Txt],TxtMem[strL_Txt]; // ��������������� ������.
char PathToProgDir[strL_Path]; // ���������� ���������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� �������.

char const NameClassMainWin[]="ClassMainWinVoiceCommander"; // ��� ������ �������� ����.
char const ClassNameText[]="ClassNameText"; // ��� ������ ��� ���� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� ����.

char const TitleVC[]="��������� ���������� �����������"; // �������� ���������.
char const NameWinText[]="��������� �������������"; // ��������� ���� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� ������.

char *extHTM=".htm"; // ���������� ������ ������� � ������� '*.htm'.
char *extNNW_Spectr=".nnws"; // ���������� ����� ��������� ����.
char *extDict=".txt"; // ���������� ����� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������.

char *dirHelp="Help\\"; // ���������� � ������� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ������.

char *NameDLLSoundCap="SoundCap.dll"; // ��� ���������� *.dll ��� ������� �����.
char *nameNNW_Spectr="NeuralNet"; // ��� ����� ��������� ����.
char *nameHlpProg="VC"; // ��� ������� �� ���������.
char *nameDict="Dictionary"; // ��� ����� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������.

char *NameFontWinTest="Times New Roman"; // ����� ��� ���� ������ ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� � ��������� ����������� ����������.

char const *PathToProgFiles="\\Program Files\\";
char const *PathToMOffice="Microsoft Office\\Office10\\";
char const *PathInternExpl="Internet Explorer\\";

//-----------------------------------------------------------------------------------------------------------

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
BYTE InitCommonControls_(void); // �������� ������� ��� ������ � ���� ���������� 'Windows'.
BYTE RegisterClassAll(void); // ����������� ���� �������.
BYTE GetPath(BYTE typ); // ��������� ����� ���������� � ����������.

UNREFERENCED_PARAMETER(hPrevInstance);
UNREFERENCED_PARAMETER(lpCmdLine);

MSG msg; HACCEL hAccelTable; HWND hwnd;

hInst=hInstance;
ColDial=GetSysColor(COLOR_BTNFACE); // ��������� ����� ���� ��� ����������� ����.
cur_wait=LoadCursor(NULL,IDC_WAIT);
if(InitCommonControls_()!=0) return FALSE; // �������� ������� ��� ������ � ���� ���������� 'Windows'.

if(RegisterClassAll()!=0) return FALSE; // ����������� ���� �������.
if(GetPath(0)!=0) return FALSE; // ��������� ����� ���������� � ����������.

// �������� �������� ����.
hwnd=CreateWindow(NameClassMainWin,TitleVC,WS_POPUP|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,0,0,0,0,NULL,NULL,hInst,NULL);
if(hwnd==NULL) { ErrMessage(); return FALSE;}
ShowWin(hwnd,1);

hAccelTable=LoadAccelerators(hInst,MAKEINTRESOURCE(IDA_MAIN));

// ���� ������ ������� ���������.
while(GetMessage(&msg,NULL,0,0)) {
if(!TranslateAccelerator(msg.hwnd,hAccelTable,&msg)) { TranslateMessage(&msg); DispatchMessage(&msg);}
}
return (int) msg.wParam;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� ��� ������ � ���� ���������� 'Windows'.

BYTE InitCommonControls_(void)
{
BYTE ber; INITCOMMONCONTROLSEX *ICC;

ber=0; ICC=new INITCOMMONCONTROLSEX; if(ICC==NULL) { ber=1; goto end;} SET_ZERO(ICC);
ICC->dwSize=sizeof(INITCOMMONCONTROLSEX);
ICC->dwICC=ICC_PROGRESS_CLASS;
if(InitCommonControlsEx((LPINITCOMMONCONTROLSEX)ICC)==FALSE) { ber=2; goto end;}
end: SAFE_DELETE(ICC); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ���� �������.

BYTE RegisterClassAll(void)
{
ATOM RegisterClassMain(void); // ����������� ������ �������� ����.
ATOM RegisterClassText(void); // ����������� ������ ���� ������.

if(!RegisterClassMain()) return 1; // ����������� ������ �������� ����.
if(!RegisterClassText()) return 2; // ����������� ������ ���� ������.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ������ �������� ����.

ATOM RegisterClassMain(void)
{
LRESULT CALLBACK WndProcMain(HWND,UINT,WPARAM,LPARAM); // ������� �������� ����.

WNDCLASSEX wcex;

wcex.cbSize=sizeof(WNDCLASSEX);
wcex.style			= CS_HREDRAW|CS_VREDRAW;
wcex.lpfnWndProc	= WndProcMain;
wcex.cbClsExtra		= 0;
wcex.cbWndExtra		= 0;
wcex.hInstance		= hInst;
wcex.hIcon			= LoadIcon(hInst,MAKEINTRESOURCE(IDI_PROG));
wcex.hCursor		= LoadCursor(NULL,IDC_ARROW);
wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
wcex.lpszMenuName	= NULL;
wcex.lpszClassName	= NameClassMainWin;
wcex.hIconSm		= LoadIcon(hInst,MAKEINTRESOURCE(IDI_PROG));
return RegisterClassEx(&wcex);
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ������ ���� ������.

ATOM RegisterClassText(void)
{
LRESULT CALLBACK WndViewText(HWND,UINT,WPARAM,LPARAM); // ������� ��������� ��������� ���� ������.

WNDCLASSEX wcex;

wcex.cbSize=sizeof(WNDCLASSEX);
wcex.style			=CS_HREDRAW|CS_VREDRAW;
wcex.lpfnWndProc	= WndViewText;
wcex.cbClsExtra		= 0;
wcex.cbWndExtra		= 0;
wcex.hInstance		= hInst;
wcex.hIcon			= LoadIcon(hInst,MAKEINTRESOURCE(IDI_TEXT));
wcex.hCursor		= LoadCursor(NULL,IDC_ARROW);
wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
wcex.lpszMenuName	= NULL;
wcex.lpszClassName	= ClassNameText;
wcex.hIconSm		= LoadIcon(hInst,MAKEINTRESOURCE(IDI_TEXT));
return RegisterClassEx(&wcex);
}

//-----------------------------------------------------------------------------------------------------------
// ������������� ������ �������� ����.

BYTE InitMain(HWND hwnd)
{
if(hwnd==NULL) return 1; if(MW.OnCreate(hwnd)!=0) return 2; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����� �������� ����.

//-----------------------------------------------------------------------------------------------------------
// �����������.

clMain::clMain(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ����������.

clMain::~clMain(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������������� � ����������.

void clMain::Zero(void)
{
hwnd=hDlg=hwndProgr=NULL; ZeroBrushes(); ZeroMenu(); ZeroHelp(); ZeroSndCap(); ZeroSndCapData();
flDoCommands=1;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void clMain::Free(void)
{
FreeBrushes(); FreeMenu(); FreeHelp(); FreeSndCap(); FreeSndCapData();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������������ ����.

void clMain::ZeroBrushes(void)
{
hBrushBkg=hBrushDial=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������ ��� ������������ ����.

void clMain::FreeBrushes(void)
{
SAFE_DELETE_OBJECT(hBrushBkg);
SAFE_DELETE_OBJECT(hBrushDial);
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������ ��� ������������ ����.

BYTE clMain::CreateBrushes(void)
{
FreeBrushes();
hBrushBkg=CreateSolidBrush(COL_WHITE); if(hBrushBkg==NULL) return 1;
hBrushDial=CreateSolidBrush(ColDial); if(hBrushDial==NULL) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� ��� ����.

void clMain::ZeroMenu(void)
{
hMenu=hMenu_=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ �� ����.

void clMain::FreeMenu(void)
{
if(hMenu_!=NULL) { DestroyMenu(hMenu_); hMenu_=NULL;} hMenu=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// �������� � �������� ����.

BYTE clMain::CreateMenu(void)
{
BYTE ber;

FreeMenu(); if(hInst==NULL) return 1;
hMenu_=LoadMenu(hInst,(LPCTSTR)IDM_MAIN); if(hMenu_==NULL) return 2;
ber=0;
hMenu=GetSubMenu(hMenu_,0); if(hMenu==NULL) { ber=3; goto end;}
end: if(ber!=0) FreeMenu(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ���� �� ������.

BYTE clMain::ShowMenu(LPARAM lParam)
{
int cmd; POINT pt;

if(hwnd==NULL) return 1; if(hMenu==NULL) return 2;
pt.x=(long)LOWORD(lParam);
pt.y=(long)HIWORD(lParam);
if(ClientToScreen(hwnd,&pt)==FALSE) return 3;
cmd=(int)TrackPopupMenu(hMenu,TPM_LEFTALIGN|TPM_TOPALIGN|TPM_RETURNCMD|TPM_RIGHTBUTTON,(int)pt.x,(int)pt.y,0,hwnd,NULL);
if(cmd!=0) SendMessage(hwnd,WM_COMMAND,cmd,0L); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� ��� ������ ��� ������ ����� �������.

void clMain::ZeroHelp(void)
{
Help=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ������ ��� ������ ����� �������.

void clMain::FreeHelp(void)
{
SAFE_DELETE(Help); ChMenuHelp();
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������ ��� ������ ����� �������.

BYTE clMain::CreateHelp(void)
{
BYTE ber;

FreeHelp(); if(IsOKStr(nameHlpProg)!=0) return 1; ber=0;
Help=new clHelpEx(); if(Help==NULL) { ber=2; goto end;}
if(Help->Set(PathToProgDir,dirHelp,nameHlpProg,nameHlpProg)!=0) { ber=3; goto end;}
end: if(ber!=0) FreeHelp(); else ChMenuHelp(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� ������ ���� �������.

void clMain::ChMenuHelp(void)
{
BYTE b;

if(Help==NULL) b=0; else b=1; SetStMenuItem_(hMenu,IDM_HELP,(SCHAR)b,0);
}

//-----------------------------------------------------------------------------------------------------------
// �������� � ������ ������ ���������.

BYTE clMain::OnCreate(HWND hwnd_)
{
if(hwnd_==NULL) return 1; hwnd=hwnd_;
if(CreateMenu()!=0) return 2; // �������� � �������� ����.
if(CreateDlgCntrl()!=0) return 3; // �������� ����������� ������������ ����.
MoveWinCorner(); // ����������� ���� � ������ ������ ����.
if(CreateSndCap()!=0) return 4; // �������� ������� ������ ���������� ������� �����.
if(CreateSndCapData()!=0) return 5; // ����� �������� ������ ��� ������ �����: ��������.
if(LoadNNW()!=0) { Message(IDS_NoNNW_Found,MB_EX); return messRet;} // �������� ��������� �����.
if(LoadDict()!=0) Message(IDS_NoDict_Loaded,MB_IN); // �������� �������.
AnStream.Init(); // ������������� ��������� ��� ��������� ������ �������� ������.
SetPntWinText(); // ��������� ���������� � ���������� ��� ���� ������.
GetSizeWinText(); // ��������� �������� ���� ������.
CreateHelp(); // �������� ������ ��� ������ ����� �������.
ChMenuDoCommands(); // ��������� ��������� ������ ���� �������� ������.
ChMenuOutWords(); // ��������� ��������� ������ ���� ������ � ���� ������������ ����.
ChBtnMenuCaptureSound(); // ��������� ������ ���� ������� ����� � ��������� ������.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ����������� ������������ ����.

BYTE clMain::CreateDlgCntrl(void)
{
LRESULT CALLBACK DlgProcCntrlMain(HWND,UINT,WPARAM,LPARAM); // ����������� ���� �������� ����.

if(hwnd==NULL) return 1; if(hInst==NULL) return 2; CloseWin_(&hDlg);
if(CreateBrushes()!=0) return 3; // �������� ������ ��� ������������ ����.
hDlg=CreateDialogParam(hInst,(LPCTSTR)IDD_CNTRL_MAIN,hwnd,(DLGPROC)DlgProcCntrlMain,(LPARAM)this);
if(hDlg==NULL) return 4;
if(GetMinSizeWin()!=0) return 5; // ��������� ������������ ������� ����.
CheckWindowSize(hwnd,(int)dxMin,(int)dyMin); // ��������� ������������ ������� ����.

hwndProgr=InitProgress(hDlg,IDC_PROGRESS_AMP_SOUND); // ������������� ���� ������ �������� ���������� ������.
SetColProgr(hwndProgr,COL_WHITE,COL_RED); // ��������� ������ ������ ���������.

SetTxtBtnRecSound(); // ��������� ������ � ������ ������������� �����.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������������ ������� ����.

BYTE clMain::GetMinSizeWin(void)
{
if(hDlg==NULL) return 1; if(GetClientRect(hDlg,&rc)==FALSE) return 2;
dxMin=GetUSHRT_Test((int)(rc.right-rc.left)+GetSystemMetrics(SM_CXDLGFRAME)*2);
dyMin=GetUSHRT_Test((int)(rc.bottom-rc.top)+GetSystemMetrics(SM_CYDLGFRAME)*2+GetSystemMetrics(SM_CYCAPTION));
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������������ ������� ����.

void clMain::SetMinSize(LPMINMAXINFO lpMinMax)
{
BYTE SetMinSizeWin(HWND hwnd,LPMINMAXINFO lpMinMax,int dxm,int dym); // ��������� ������������ ������� ����.

SetMinSizeWin(hwnd,lpMinMax,(int)dxMin,(int)dyMin);
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ���� � ������ ������ ����.

BYTE clMain::MoveWinCorner(void)
{
BYTE SizeMovWin(HWND hwnd,int shX,int shY,int dX,int dY,BYTE flChild); // ����������� ���� � ��������� ��� ��������.

int dx,dy; POINT pt;

if(hwnd==NULL) return 1; if(GetWindowRect(GetDesktopWindow(),&rc)==FALSE) return 2;
pt.x=rc.right; pt.y=rc.bottom;
if(GetWindowRect(hwnd,&rc)==FALSE) return 3; 
dx=(int)(rc.right-rc.left);
dy=(int)(rc.bottom-rc.top);
if(dx<=0||dy<=0) return 4;
if(SizeMovWin(hwnd,(int)(pt.x-(long)dx-rc.left),(int)(pt.y-(long)dy-rc.top),0,0,0)!=0) return 5;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������� ��������� �������� ����.

LRESULT clMain::MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
if(flag==NULL) return 0L; *flag=0; if(hwnd==NULL) return 0L; if(msg==WM_CREATE) return 0L;

switch(msg) { default: break;

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: *flag=1; break;

// WM_SYSCOMMAND ............................................................................................
case WM_SYSCOMMAND: if(wParam==SC_CLOSE) { *flag=1; OnCloseWin();} break;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: if(Command(wParam)==0) *flag=1; break;

// WM_PAINT .................................................................................................
case WM_PAINT: *flag=1; ImgWinC(hwnd,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: *flag=1; OnCloseWin(); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������� ��������� ���� ����������.

LRESULT clMain::MsgCommandCntrl(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
int id; HDC hdc;

if(flag==NULL) return 0L; *flag=0; if(hDlg==NULL) return 0L; if(msg==WM_INITDIALOG) return 0L;

switch(msg) { default: break;

// WM_CTLCOLORSTATIC ........................................................................................
case WM_CTLCOLORSTATIC: hdc=(HDC)wParam; id=GetDlgCtrlID((HWND)lParam); if(id<=0) break; *flag=1;
SetBkColor(hdc,GetSysColor(COLOR_WINDOW)); SetTextColor(hdc,GetSysColor(COLOR_BTNTEXT));
SetBkMode(hdc,TRANSPARENT); if(id==IDC_TEXT||id==IDC_WORD) return (LRESULT)hBrushBkg; return (LRESULT)hBrushDial;

// WM_RBUTTONDOWN ...........................................................................................
case WM_RBUTTONDOWN: *flag=1; SetFocus(hwnd); ShowMenu(lParam); break;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: if(CommandCntrl(wParam)==0) *flag=1; break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// �������.

BYTE clMain::Command(WPARAM wParam)
{
INT_PTR CALLBACK DlgAbout(HWND,UINT,WPARAM,LPARAM); // ������� ����������� ���� � ���������.

BYTE flag; int wmId;

if(hwnd==NULL) return 1; flag=2; wmId=LOWORD(wParam);

switch(wmId) {

// IDM_SERVICE ..............................................................................................
case IDM_SERVICE: if(flCaptSound==0) StartCaptureSound(); else flStopCaptSound=1; break;

// IDM_DO_COMMANDS ..........................................................................................
case IDM_DO_COMMANDS: flDoCommands=1-flDoCommands; ChMenuDoCommands(); SetText(""); break;

// IDM_OUT_WORDS ............................................................................................
case IDM_OUT_WORDS: flOutWords=1-flOutWords; ChMenuOutWords(); SetText(""); break;

// IDM_WIN_TEXT .............................................................................................
case IDM_WIN_TEXT: OpenWinText(); break;

// IDM_ADJUST_SOUND .........................................................................................
case IDM_ADJUST_SOUND: DlgAdjSound(); break;

// IDM_HELP .................................................................................................
case IDM_HELP: if(Help!=NULL) Help->ShowContent(); break;

// IDM_ABOUT ................................................................................................
case IDM_ABOUT: DialogBox(hInst,(LPCTSTR)IDD_ABOUTBOX,hwnd,(DLGPROC)DlgAbout); break;

// IDM_EXIT .................................................................................................
case IDM_EXIT: OnCloseWin(); break;
}
return flag;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ���� ����������.

BYTE clMain::CommandCntrl(WPARAM wParam)
{
int id;

if(hDlg==NULL) return 1; id=LOWORD(wParam);

switch(id) { default: return 2;

// IDC_ON_OFF ...............................................................................................
case IDC_ON_OFF: if(flCaptSound==0) StartCaptureSound(); else flStopCaptSound=1; break;
}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� � ����.

void clMain::OnPaint(HDC hdc)
{
if(hdc==NULL) return;
}

//-----------------------------------------------------------------------------------------------------------
// ����� �������� ������ ��� ������ �����: ��������� ���������.

void clMain::ZeroSndCapData(void)
{
SndCapData=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ����� �������� ������ ��� ������ �����: �c���������� ������.

void clMain::FreeSndCapData(void)
{
SAFE_DELETE(SndCapData);
}

//-----------------------------------------------------------------------------------------------------------
// ����� �������� ������ ��� ������ �����: ��������.

BYTE clMain::CreateSndCapData(void)
{
FreeSndCapData(); SndCapData=new clSndCapData(); if(SndCapData==NULL) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� �� ������ ������ ���������� ������� �����.

void clMain::ZeroSndCap(void)
{
SndCap=NULL; TimeRecBuf=TimeRecProc=nRecChar=nRecText=0; cntShutDown=0; flCaptSound=0; flStopCaptSound=1;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� ������ ���������� ������� �����.

void clMain::FreeSndCap(void)
{
SAFE_DELETE(SndCap);
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� ������ ���������� ������� �����.

BYTE clMain::CreateSndCap(void)
{
void FunSndCap_CallBack(PNT_DATA Pnt,DWORD szBuf,void *pBuf); // ������� ��������� ������ ��� ������ �����.

BYTE ber;

FreeSndCap(); ber=0;
SndCap=new clLoadDLLSndCap(); if(SndCap==NULL) { ber=1; goto end;}
if(SndCap->Load(NULL,NameDLLSoundCap)!=0) { ber=2; goto end;} // �������� ����������, ������� � �������� �������.
if(SndCap->Obj==NULL) { ber=3; goto end;}
SndCap->Obj->SetPntFunc((PNT_DATA)this,FunSndCap_CallBack,&flStopCaptSound); // ��������� ����������.
SndCap->Obj->SetNotifySize(szNotifySndCap); // ��������� ������� ������ ���������.
end: if(ber!=0) FreeSndCap(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ��� ������ �����.

BYTE clMain::SaveBufSound(DWORD szBuf,void *pBuf)
{
UINT sz;

if(szBuf==0) return 1; if(pBuf==NULL) return 2; if(SndCapData==NULL) return 3; sz=szBuf/sizeof(SHRT);
if(SndCapData->AddCycle(sz,(SHRT *)pBuf)!=0) return 4;
TimeRecBuf+=sz; if(ProcRecRealTime()!=0) return 5; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ �����.

BYTE clMain::StartCaptureSound(void)
{
BYTE nChan,nbPS,ber;

if(SndCap==NULL) return 1; if(SndCap->Obj==NULL) return 2;
if(SndCapData==NULL) return 3; SndCapData->Free();

TimeRecBuf=TimeRecProc=nRecChar=nRecText=cntPause=0; cntShutDown=0;
if(SndCapData->CreateCycle(szSndCapDataCycle)!=0) return 4; // ��������� ������ ��� ����� �������� ������ ��� ������������� �����.
SetText(""); SetWord(""); if(WinText.hwnd!=NULL) WinText.ClearWin();
if(AnSound.Init(ParSpectr.Time_Step,1)!=0) return 5; // ������������� ��������� ��� ��������� ������ �������� ������.
AnStream.Reset(); // ����� ���������.
if(RecNNW.Alloc(nRecCharMax)!=0) return 6;
if(RecText.Alloc(nSzRecTextMax)!=0) return 7;

if(SndCap->StartCapture()!=0) return 8; // ������ ������� �����.
ber=0;
SndCap->Obj->GetParSnd(&SndCapData->nSPS,&nChan,&nbPS);
if(nChan!=1) { ber=9; goto end;} if(nbPS!=16) { ber=10; goto end;}
if(szSndCapDataCycle*szNotifySndCap<SndCapData->nSPS*ParSpectr.Time_Width) { ber=11; goto end;}

flCaptSound=1; flStopCaptSound=0; ChBtnMenuCaptureSound();
while(1) { if(SndCap->Obj->CheckMessage()!=0) break;}

end: StopCaptureSound_(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ �����.

void clMain::StopCaptureSound_(void)
{
flStopCaptSound=1; if(SndCap==NULL) return;
SndCap->StopCapture(); // ��������� ������� �����.
if(SndCapData!=NULL) SndCapData->Free(); // ������������ ������.
flCaptSound=0; ChBtnMenuCaptureSound();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ���� ������� ����� � ��������� ������.

void clMain::ChBtnMenuCaptureSound(void)
{
SetStMenuItem_(hMenu,IDM_SERVICE,1,flCaptSound); SetTxtBtnRecSound();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ � ������ ������������� �����.

void clMain::SetTxtBtnRecSound(void)
{
int id; char *cp;

if(hDlg==NULL) return; if(flCaptSound==0) id=IDS_Btn_Recogn; else id=IDS_Btn_Stop;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_ON_OFF,cp);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������� �����.

BYTE clMain::DlgAdjSound(void)
{
BYTE flRet,ber; clDlgSndCap *DSC;

if(flCaptSound!=0) { SoundBlock(); return messRet;}
if(hwnd==NULL) return 1; if(SndCap==NULL) return 2; if(SndCap->Obj==NULL) return 3;
DSC=NULL; ber=0;
DSC=new clDlgSndCap(); if(DSC==NULL) { ber=4; goto end;}
if(DSC->Dialog(hwnd,SndCap->Obj,&flRet)!=0) { ber=5; goto end;}
end: SAFE_DELETE(DSC); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� � ������������� � �������� �������.

BYTE clMain::ProcRecRealTime(void)
{
BYTE GetN_(USHRT nPoints,USHRT *Np,USHRT NpM,BYTE *Mp); // ��� ����������� ����� 'Np', ���������� 2 � ����� �������, ������� ��������� 'nPoints'.
BYTE GetWeightWinSTFT(BYTE meth,float *Weight,USHRT nP,float Wid); // ���������� ������� ������� ���� ��� ������������ ����������.
BYTE FastFT(complex *A,complex *B,BYTE M,SCHAR dir,BYTE prcMess); // ������� �������������� �����.
BYTE RecognSoundNNW_Sp(float *Spectr,USHRT nSpectr,float dFr,strNNW *pNNW,pFunDecSnd DecSnd,PNT_DATA Pnt,
  BYTE *numSnd); // ������������� ������ ������� ��������� �����.
BYTE DecSnd_Instant(PNT_DATA Pnt,strLay *pLay,BYTE *numSnd); // ������� �������� ������� ��� ������������� ����� - ���������� ��������� �������������, ���������� �� ������� ���������.
BYTE DecSnd_Store(PNT_DATA Pnt,strLay *pLay,BYTE *numSnd); // ������� �������� ������� ��� ������������� ����� - ����� � ����������� ���������� �������������.
BYTE GetSymbSound(BYTE num,char *pSymb); // ��������� ������� �����.

BYTE M,numSnd,flStart,ber; SHRT iv,*Sound; USHRT i,n,nWinWid,nPoints,nPh,nStep,nTI; UINT k,nTime,ui;
float v,*Weight,*Spectr,dFr; double dt,s; complex *A,*B; char Symb; pFunDecSnd pFunDecSnd;

if(SndCapData==NULL) return 1; if(SndCapData->IsOK()!=0) return 2; dt=1./(double)SndCapData->nSPS;
if(RecNNW.IsOK()!=0) return 3; if(ParSpectr.IsOK()!=0) return 4;
nWinWid=GetUSHRT_Test((double)ParSpectr.Time_Width/dt); if(nWinWid<nWinWid_Min) nWinWid=nWinWid_Min;
if(GetN_(nWinWid,&nPoints,0,&M)!=0) return 5; nPh=nPoints/2;
if(TimeRecBuf<(UINT)nPoints) return messRet;
flStart=0; if(TimeRecProc<nPh) { TimeRecProc=nPh; flStart=1;}
if(TimeRecBuf-nPh<TimeRecProc) return messRet;
nStep=GetUSHRT_Test((double)ParSpectr.Time_Step/dt); if(nStep==0) nStep=1;
ui=TimeRecBuf-nPh-TimeRecProc; nTime=(UINT)(ui/nStep);
if(flStart==0) { nTI=1; nTime++;} else nTI=0;
dFr=(float)(1./(dt*(double)nPoints));

A=B=NULL; Sound=NULL; Weight=Spectr=NULL; ber=0;
if(AllocSHRT(&Sound,(size_t)nPoints)!=0) { ber=6; goto end;}
if(AllocFloat(&Spectr,(size_t)nPh)!=0) { ber=7; goto end;}
if(AllocComplex(&A,(size_t)nPoints)!=0) { ber=8; goto end;}
if(AllocComplex(&B,(size_t)nPoints)!=0) { ber=9; goto end;}
if(AllocFloat(&Weight,(size_t)nPh)!=0) { ber=10; goto end;}

// ���������� ������� ������� ����.
if(ParSpectr.methSpFour!=methSpFour_NoWin) { v=ParSpectr.Time_Width*0.5F/(float)dt;
if(GetWeightWinSTFT(ParSpectr.methSpFour,Weight,nPh,v)!=0) { ber=11; goto end;}}

// ���� �� ��������� ������.
for(i=nTI;i<nTime;i++) { k=TimeRecProc+(UINT)i*(UINT)nStep-nPh; if(k>TimeRecBuf) { ber=12; goto end;}
k=TimeRecBuf-k; if(SndCapData->GetCycle((UINT)nPoints,Sound,k)!=0) { ber=13; goto end;}
for(n=0;n<nPoints;n++) { iv=(SHRT)((int)n-(int)nPh); if(iv<0) iv=-iv;
v=(float)Sound[n]; if(ParSpectr.methSpFour!=methSpFour_NoWin) { if(iv<nPh) v*=Weight[iv]; else v=0.0F;}
A[n]=complex((double)v,0.);}

if(FastFT(A,B,M,1,1)!=0) { ber=14; goto end;}

for(n=0;n<nPh;n++) Spectr[n]=(float)abs(B[n]);

// ���������� ��������� �� �������� ��� ��������� ���������.
s=0.0F; for(n=0;n<nPh;n++) { v=Spectr[n]; s+=POW2D(v);} s/=(double)nPh; s=SQRT(s);
ShowProgr(s,(double)AmpNormSound); // ����������� ������ ���������.

// ������������� ������� ��������� �����.
if(methDecSound==methDecSnd_Inst) pFunDecSnd=DecSnd_Instant; else pFunDecSnd=DecSnd_Store; // ��������� ������� �������� ������� �� �����.
numSnd=UCHAR_MAX;
if(RecognSoundNNW_Sp(Spectr,nPh,dFr,&NNW_Spectr,pFunDecSnd,(PNT_DATA)this,&numSnd)!=0) { ber=15; goto end;}
if(numSnd==UCHAR_MAX) Symb='-'; else { if(GetSymbSound(numSnd,&Symb)!=0) Symb='-';} // ��������� ������� �����.

if(nRecChar>=RecNNW.sz) { ber=16; goto end;}
RecNNW.String[nRecChar]=Symb; nRecChar++;
RecognTxtCommand(numSnd,Symb); // ������������� ������ � ������.
// ����� ������ � ������� ����.
if(nRecChar==RecNNW.sz) { RecNNW.String[nRecChar]='\0'; nRecChar=0;
if(WinText.hwnd!=NULL) WinText.SetText(RecNNW.String);}
}
TimeRecProc+=(UINT)(nTime-1)*(UINT)nStep;

end: FreeComplex(&A); FreeComplex(&B); FreeSHRT(&Sound); FreeFloat(&Spectr); FreeFloat(&Weight); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ����� ��� ������������� ������ ����.

BYTE clMain::GetNumSndRecogn(strLay *pLay,BYTE *numSnd)
{
BYTE GetOutArr(strLay *pLay,float *pArr,BYTE nArr); // ���������� ������� ������� ��������� ���������.

BYTE nArr,ber; float *pArr;

if(pLay==NULL) return 1; if(pLay->IsOK()!=0) return 2; if(numSnd==NULL) return 3;
nArr=nVoices; if((USHRT)nArr!=pLay->n) return 6;
pArr=NULL; ber=0;
pArr=new float[nArr]; if(pArr==NULL) { ber=7; goto end;}
if(GetOutArr(pLay,pArr,nArr)!=0) { ber=8; goto end;}
if(AnSound.Step(pArr,nArr,numSnd)!=0) { ber=9; goto end;}
end: SAFE_DELETE_ARR(pArr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ���������.

void clMain::ShowProgr(double v,double vMax)
{
void ShowProgress(HWND hwndProgr,double v,double vMax); // ����������� �������� �� ��������.

ShowProgress(hwndProgr,v,vMax); ProcMess();
}

//-----------------------------------------------------------------------------------------------------------
// �������� ��������� ����.

BYTE clMain::LoadNNW(void)
{
if(NNW_Spectr.Read(PathToProgDir,nameNNW_Spectr,extNNW_Spectr)!=0) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������.

BYTE clMain::LoadDict(void)
{
if(Dict.Read(PathToProgDir,nameDict,extDict)!=0) { Message(IDS_NoDict_Found,MB_IN); return 1;} // ������ ������� �� �����.
if(RecWords.Init(&Dict)!=0) return 2; // ������������� ��������� ��� ������������� ����.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ���������� ��� ���� ������.

void clMain::SetPntWinText(void)
{
WinText.SetParPnt(hwnd,&rcText); // ��������� ���������� � ����������.
}

//-----------------------------------------------------------------------------------------------------------
// ��������� �������� ���� ������.

BYTE clMain::GetSizeWinText(void)
{
USHRT dW; long *lp,d;

if(hwnd==NULL) return 1; if(GetWindowRect(hwnd,&rc)==FALSE) return 2;
lp=&rcText.left; dW=dxWinText_Stand; d=rc.right-rc.left; *lp=(d-(long)dW)/2; *lp+=rc.left; rcText.right=*lp+(long)dW;
lp=&rcText.top; dW=dyWinText_Stand; d=rc.bottom-rc.top; *lp=(d-(long)dW)/2; *lp+=rc.top; rcText.bottom=*lp+(long)dW;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ���� ������.

void clMain::OpenWinText(void)
{
if(WinText.hwnd==NULL) WinText.CreateWin(); else WinText.CloseWin(); ChMenuWinText();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� ������ � ������ ���� �������� ���� ������.

void clMain::ChMenuWinText(void)
{
BYTE Ch;

if(WinText.hwnd==NULL) Ch=0; else Ch=1; SetStMenuItem_(hMenu,IDM_WIN_TEXT,1,Ch);
}

//-----------------------------------------------------------------------------------------------------------
// ������� ���� ������.

void clMain::ClearWinText(void)
{
if(WinText.hwnd!=NULL) WinText.SetText("");
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ������ � ����.

void clMain::SetWinText(char *Text)
{
if(WinText.hwnd!=NULL) WinText.SetText(Text);
}

//-----------------------------------------------------------------------------------------------------------
// ������������� ������ � ������.

void clMain::RecognTxtCommand(BYTE numSnd,char Symb)
{
BYTE comm,flS,fl; UINT numWord; char *cp;

// ����� ��� ��������� ������.
if(flDoCommands!=0) {
if(cntPause!=0) { flS=0; cntPause--; if(cntPause==0) { SetWord(""); if(cntShutDown!=0) cntShutDown--;}} else flS=1;}
else flS=1;

// ������ ������ ��������.
if(AnStream.GetSymb(numSnd,flS)!=messRet) return;

// ������������� ����.
fl=RecWords.Step(numSnd,&numWord);
if(fl==messRet) { cp=Dict.GetWord(numWord);
if(cp!=NULL) { if(flOutWords==0) SetWord(cp); else AddWordTextWin(cp);} return;}

// ����� ������ �������� - ���������� ������������� ������� � ����.
if(flDoCommands==0&&flOutWords==0) { if(numSnd==UCHAR_MAX) return; AddSymbTextWin(Symb); return;}
if(flDoCommands==0) return; if(flS==0) return;

// ���������� ������.
comm=UCHAR_MAX;
switch(numSnd) {
default: break;
case numSymbA: comm=commCloseWin; break; // '�'.
case numSymbV: if(cntShutDown==0) comm=commShutDownQ; else comm=commShutDown; break; // '�'.
case numSymbM: comm=commStopRec; break; // '�'.
case numSymbU: comm=commShowHelp; break; // '�'.
case numSymbE: comm=commOpenNotepad; break; // '�'.
case numSymbR: comm=commOpenPaint; break; // '�'.
case numSymbO: comm=commOpenWord; break; // '�'.
case numSymbI: comm=commOpenIE; break; // '�'.
}
if(comm==UCHAR_MAX) return; if(comm>=nCommands) return;
if(cntShutDown!=0&&comm!=commShutDown) return;

ShowCommand(comm); DoCommand(comm); // ����������� � ������ �������.
if(ParSpectr.Time_Step<=0.0F) return;
cntPause=GetUINT_Test(TimePauseComm/ParSpectr.Time_Step); // ��������� ����� �� ��������� �������.
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������������� ������� � ����.

BYTE clMain::AddSymbTextWin(char Symb)
{
if(RecText.IsOK()!=0) return 1; if(nRecText>=RecText.sz) return 2;
RecText.String[nRecText]=Symb; nRecText++; RecText.String[nRecText]='\0'; SetText(RecText.String);
if(nRecText==RecText.sz) nRecText=0; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������������� ����� � ����.

BYTE clMain::AddWordTextWin(char *Str)
{
BYTE i; USHRT sz; size_t ln; char *cp;

if(RecText.IsOK()!=0) return 1; if(nRecText>=RecText.sz) return 2;
ln=strlen(Str); if(ln>UCHAR_MAX) return 3; sz=(USHRT)ln+1; if(sz>RecText.sz) return 4;
if(nRecText>RecText.sz-(UINT)sz) nRecText=0; cp=RecText.String+nRecText;
for(i=0;i<(BYTE)ln;i++) cp[i]=Str[i]; cp[ln]=' '; cp[ln+1]='\0'; SetText(RecText.String);
nRecText+=(UINT)sz; if(nRecText==RecText.sz) nRecText=0; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������.

void clMain::DoCommand(BYTE comm)
{
HWND hwndV;

switch(comm) { default: return;
// ���������� ���������� - ������ � �������������.
case commShutDown: case commShutDownQ:
if(cntShutDown!=0) { ExitWindowsEx(EWX_LOGOFF,0); cntShutDown=0;} else cntShutDown=3; break;
// �������� ���� ���������.
case commCloseWin: hwndV=GetForegroundWindow(); if(hwndV==hwnd) { SetString(IDS_CanNotCloseProg); break;}
if(hwndV!=NULL) SendMessage(hwndV,WM_CLOSE,0,0L); break;
// ��������� ������.
case commStopRec: flStopCaptSound=1; break;
// �������� ������� �� ���������.
case commShowHelp: if(Help!=NULL) Help->ShowContent(); else Message(IDS_Err_NoHelpFile,MB_IN); break;
// ������� �������.
case commOpenNotepad: OpenSysProg("notepad.exe"); break;
// ������� �������� �����������.
case commOpenPaint: OpenSysProg("mspaint.exe"); break;
// ������� 'WinWord'.
case commOpenWord: OpenProgFiles((char *)PathToMOffice,"winword.exe"); break;
// ������� 'Internet Explorer'.
case commOpenIE: OpenProgFiles((char *)PathInternExpl,"iexplore.exe"); break;
}
}

//-----------------------------------------------------------------------------------------------------------
// �������� ��������� ���������.

BYTE clMain::OpenSysProg(char *NameProg)
{
BYTE Process(char *Path,char *Dir,char *Name,char *ComStr,char *CurrDir,BYTE show,BYTE wait); // ������ ������ ���������.

BYTE ber; UINT ui; char *SysDir;

if(IsOKStr(NameProg)!=0) return 1;
SysDir=NULL; ber=0;
if(AllocString(&SysDir,(size_t)MAX_PATH)!=0) { ber=2; goto end;}
ui=GetSystemDirectory((LPTSTR)SysDir,(UINT)MAX_PATH); if(ui==0||ui>MAX_PATH) { ber=3; goto end;}
if(Process(SysDir,"\\",NameProg,NULL,NULL,1,0)!=0) { ber=3; goto end;}
end: FreeString(&SysDir); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ��������� �� ���������� "Program Files".

BYTE clMain::OpenProgFiles(char *PathProg,char *NameProg)
{
BYTE Process(char *Path,char *Dir,char *Name,char *ComStr,char *CurrDir,BYTE show,BYTE wait); // ������ ������ ���������.

BYTE ber; UINT ui; char *SysDir,*Path,*cp,*Items[2];

if(IsOKStr(NameProg)!=0) return 1;
Path=SysDir=NULL; ber=0;
if(AllocString(&SysDir,(size_t)MAX_PATH)!=0) { ber=2; goto end;}
ui=GetSystemDirectory((LPTSTR)SysDir,(UINT)MAX_PATH); if(ui==0||ui>MAX_PATH) { ber=3; goto end;}
cp=strchr(SysDir,':'); if(cp==NULL) { ber=4; goto end;} *(cp+1)='\0';
Items[0]=SysDir; Items[1]=(char *)PathToProgFiles;
if(GetString(&Path,Items,2)!=0) { ber=5; goto end;}
if(Process(Path,PathProg,NameProg,NULL,NULL,1,0)!=0) { ber=6; goto end;}
end: FreeString(&SysDir); FreeString(&Path); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ������ � ����.

BYTE clMain::ShowCommand(BYTE comm)
{
if(comm>=nCommands) return 1; if(SetString(IDA_Commands[comm])!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ � ����.

void clMain::SetText(char *txt)
{
if(hDlg==NULL) return; if(txt==NULL) SetDlgItemText(hDlg,IDC_TEXT,"");
SetDlgItemText(hDlg,IDC_TEXT,txt);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����� � ����.

void clMain::SetWord(char *txt)
{
if(hDlg==NULL) return; if(txt==NULL) SetDlgItemText(hDlg,IDC_WORD,"");
SetDlgItemText(hDlg,IDC_WORD,txt);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ � ����.

BYTE clMain::SetString(int idS)
{
char *cp;

if(idS<=0) return 1; if(hDlg==NULL) return 2; if(hInst==NULL) return 3;
if(LoadString(hInst,idS,TxtStr,strL_Txt)!=0) cp=TxtStr; else cp=""; SetWord(cp); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� ������ ���� �������� ������.

void clMain::ChMenuDoCommands(void)
{
SetStMenuItem_(hMenu,IDM_DO_COMMANDS,1,flDoCommands);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� ������ ���� ������ � ���� ������������ ����.

void clMain::ChMenuOutWords(void)
{
SetStMenuItem_(hMenu,IDM_OUT_WORDS,1,flOutWords);
}

//-----------------------------------------------------------------------------------------------------------
// �������� ��� �������� ����.

void clMain::OnCloseWin(void)
{
if(flCaptSound!=0) { Message(IDS_Mess_CanNotExit,MB_ST); return;} DestroyWindow(hwnd);
}

//-----------------------------------------------------------------------------------------------------------
// ������� ��������� ������ ��� ������ �����.

void FunSndCap_CallBack(PNT_DATA Pnt,DWORD szBuf,void *pBuf)
{
clMain *MW_;

MW_=(clMain *)Pnt; if(MW_==NULL) return; MW_->SaveBufSound(szBuf,pBuf);
}

//-----------------------------------------------------------------------------------------------------------
// ������� �������� ������� ��� ������������� ����� - ����� � ����������� ���������� �������������.

BYTE DecSnd_Store(PNT_DATA Pnt,strLay *pLay,BYTE *numSnd)
{
clMain *MW_;

MW_=(clMain *)Pnt; if(MW_==NULL) return 1; if(MW_->GetNumSndRecogn(pLay,numSnd)!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������� �������� ����.

LRESULT CALLBACK WndProcMain(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
BYTE InitMain(HWND hwnd); // ������������� ������ �������� ����.

BYTE flag;

if(msg!=WM_CREATE) { LRes=MW.MsgCommand(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}

switch(msg) {

default: return DefWindowProc(hwnd,msg,wParam,lParam);

// WM_CREATE ................................................................................................
case WM_CREATE: if(InitMain(hwnd)!=0) { PostMessage(hwnd,WM_CLOSE,0,0L); return 0L;} break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hwnd); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: PostQuitMessage(0); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ���� �������� ����.

LRESULT CALLBACK DlgProcCntrlMain(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{   
BYTE flag; clMain *MW_;

if(msg!=WM_INITDIALOG) { MW_=(clMain *)GetWindowLong(hDlg,DWL_USER);
if(MW_!=NULL) { LRes=MW_->MsgCommandCntrl(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) { default: break;

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: SetWindowLong(hDlg,DWL_USER,(long)lParam); return (LRESULT)TRUE;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hDlg,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hDlg); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: SetWindowLong(hDlg,DWL_USER,0L); break;
}

return FALSE;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����� ��� ���� ������ �������������.

//-----------------------------------------------------------------------------------------------------------
// �����������.

clWinText::clWinText(void)
{
Zero(); CreateBrushes();
}

//-----------------------------------------------------------------------------------------------------------
// ����������.

clWinText::~clWinText(void)
{
CloseEdt(); CloseWin(); Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void clWinText::Zero(void)
{
hwnd=hwndEdt=hwndOwner=NULL; rcWin=NULL; ZeroBrushes(); ZeroFont(); dxMin=dyMin=0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void clWinText::Free(void)
{
FreeBrushes(); FreeFont();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ����������.

void clWinText::SetParPnt(HWND hwndOwner_,RECT *rcWin_)
{
hwndOwner=hwndOwner_; rcWin=rcWin_;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������������ ����.

void clWinText::ZeroBrushes(void)
{
hBrushBkg=hBrushDial=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������ ��� ������������ ����.

void clWinText::FreeBrushes(void)
{
SAFE_DELETE_OBJECT(hBrushBkg);
SAFE_DELETE_OBJECT(hBrushDial);
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������ ��� ������������ ����.

BYTE clWinText::CreateBrushes(void)
{
FreeBrushes();
hBrushBkg=CreateSolidBrush(COL_WHITE); if(hBrushBkg==NULL) return 1;
hBrushDial=CreateSolidBrush(ColDial); if(hBrushDial==NULL) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� ��� ������.

void clWinText::ZeroFont(void)
{
hFontText=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������.

void clWinText::FreeFont(void)
{
SAFE_DELETE_OBJECT(hFontText);
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������.

BYTE clWinText::LoadFont(void)
{
HFONT GetFont(char *nameFont,SHRT Wid,SHRT Hei); // �������� ������.

FreeFont(); if(IsOKStr(NameFontWinTest)!=0) return 1;
hFontText=GetFont(NameFontWinTest,0,-HeiFontText); if(hFontText==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ����.

BYTE clWinText::CreateWin(void)
{
BYTE IsOKRect(RECT *rc); // �������� ��������������.

int dx,dy; DWORD Style;

CloseWin(); if(hInst==NULL) return 1; if(hwndOwner==NULL) return 2; if(IsOKRect(rcWin)!=0) return 3;
dx=(rcWin->right-rcWin->left);
dy=(rcWin->bottom-rcWin->top);
if(dx<=0||dy<=0) return 4;
if(LoadFont()!=0) return 5; // �������� ������.

Style=WS_POPUP|WS_CAPTION|WS_THICKFRAME|WS_MAXIMIZEBOX|WS_MINIMIZEBOX|WS_SYSMENU|WS_CLIPCHILDREN;
hwnd=CreateWindow(ClassNameText,NameWinText,Style,(int)rcWin->left,(int)rcWin->top,dx,dy,hwndOwner,NULL,
hInst,NULL); if(hwnd==NULL) { ErrMessage(); return 6;}
SetWindowLong(hwnd,GWL_USERDATA,(LONG)this); ShowWin(hwnd,1);

GetMinSizeWin(); // ��������� ������������ ������� ����.
CheckWindowSize(hwnd,(int)dxMin,(int)dyMin); // ��������� ������������ ������� ����.
if(SetPosSizeChWin()!=0) return 7; // ��������� ������������ �������� ����.
if(CreateEdt()!=0) return 8; // �������� ���� ��������������.
SetPosWindowCenter(hwnd); // ��������� ���� � ����� ������� ���� ��� ������.

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ����.

void clWinText::CloseWin(void)
{
CloseWin_(&hwnd);
}

//-----------------------------------------------------------------------------------------------------------
// �������� ��� �������� ����.

void clWinText::OnCloseWin(void)
{
CloseEdt(); CloseWin(); MW.ChMenuWinText();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������������ ������� ����.

void clWinText::GetMinSizeWin(void)
{
dxMin=GetUSHRT_Test((int)dxWinText_Min+GetSystemMetrics(SM_CXFRAME)*2);
dyMin=GetUSHRT_Test((int)dyWinText_Min+GetSystemMetrics(SM_CYFRAME)*2+GetSystemMetrics(SM_CYCAPTION));
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������������ ������� ����.

void clWinText::SetMinSize(LPMINMAXINFO lpMinMax)
{
BYTE SetMinSizeWin(HWND hwnd,LPMINMAXINFO lpMinMax,int dxm,int dym); // ��������� ������������ ������� ����.

SetMinSizeWin(hwnd,lpMinMax,(int)dxMin,(int)dyMin);
}

//-----------------------------------------------------------------------------------------------------------
// �������� ���� ��������������.

BYTE clWinText::CreateEdt(void)
{
BYTE SetFont(HWND hwnd,HFONT hFont); // ��������� ��� ��������� ������ � ����.

int dx,dy; DWORD Style;

if(hwnd==NULL) return 1; if(hInst==NULL) return 2; CloseEdt();
dx=(int)(rcEdt.right-rcEdt.left);
dy=(int)(rcEdt.bottom-rcEdt.top);
if(dx<=0||dy<=0) return 3;
Style=WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT|ES_MULTILINE|ES_AUTOVSCROLL|ES_READONLY;
hwndEdt=CreateWindow("edit","",Style,0,0,dx,dy,hwnd,(HMENU)id_Win_Edit,hInst,NULL);
if(hwndEdt==NULL) return 4;
if(SetFont(hwndEdt,hFontText)!=0) return 5;
SendMessage(hwndEdt,EM_LIMITTEXT,(WPARAM)MaxSizeEdt,0L); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ���� ��������������.

void clWinText::CloseEdt(void)
{
CloseWin_(&hwndEdt);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������������ �������� ����.

void clWinText::ChPosSizeChWin(void)
{
SetPosSizeChWin(); SetPosWindow(hwndEdt,&rcEdt);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������������ �������� ����.

BYTE clWinText::SetPosSizeChWin(void)
{
if(hwnd==NULL) return 1; if(GetClientRect(hwnd,&rcEdt)==FALSE) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ � ����.

BYTE clWinText::SetText(char *Text)
{
if(hwndEdt==NULL) return 1; if(IsOKStr(Text)!=0) SetWindowText(hwndEdt,"");
SetWindowText(hwndEdt,Text); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ����.

void clWinText::ClearWin(void)
{
if(hwndEdt==NULL) return; SetWindowText(hwndEdt,"");
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� ����.

LRESULT clWinText::MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
int id; HDC hdc;

if(flag==NULL) return 0L; *flag=0; if(hwnd==NULL) return 0L; if(msg==WM_CREATE) return 0L;

switch(msg) { default: break;

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: *flag=1; break;

// WM_GETMINMAXINFO .........................................................................................
case WM_GETMINMAXINFO: *flag=1; SetMinSize((LPMINMAXINFO)lParam); break;

// WM_CTLCOLORSTATIC ........................................................................................
case WM_CTLCOLORSTATIC: hdc=(HDC)wParam; id=GetDlgCtrlID((HWND)lParam); if(id<=0) break; *flag=1;
SetBkColor(hdc,GetSysColor(COLOR_WINDOW)); SetTextColor(hdc,GetSysColor(COLOR_BTNTEXT));
SetBkMode(hdc,TRANSPARENT); if(id==id_Win_Edit) return (LRESULT)hBrushBkg; return (LRESULT)hBrushDial;

// WM_SIZE ..................................................................................................
case WM_SIZE: *flag=1; if(wParam==SIZE_MINIMIZED) break; ChPosSizeChWin(); break;

// WM_SYSCOMMAND ............................................................................................
case WM_SYSCOMMAND: if(wParam==SC_CLOSE) OnCloseWin(); break;

// WM_PAINT .................................................................................................
case WM_PAINT: *flag=1; ImgWinC(hwnd,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWin_(&hwnd); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ��������� ��������� ���� ������.

LRESULT CALLBACK WndViewText(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
BYTE flag; clWinText *WinText_;

if(msg!=WM_CREATE) { WinText_=(clWinText *)GetWindowLong(hwnd,GWL_USERDATA);
if(WinText_!=NULL) { LRes=WinText_->MsgCommand(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) {

default: return DefWindowProc(hwnd,msg,wParam,lParam);

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: break;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hwnd,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hwnd); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: SetWindowLong(hwnd,GWL_USERDATA,0L); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ����������� ���� � ���������.

INT_PTR CALLBACK DlgAbout(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
void SetPosWindowCenter(HWND hDlg); // ��������� ���� � ����� ������� ���� ��� ������.

switch (message)
{
// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG:	SetPosWindowCenter(hDlg); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND:
if(LOWORD(wParam)==IDOK||LOWORD(wParam)==IDCANCEL) { EndDialog(hDlg,LOWORD(wParam)); return (INT_PTR)TRUE;}
break;
}
return (INT_PTR)FALSE;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����� ����������.

BYTE GetPath(BYTE typ)
{
BYTE StrSybmConv(char *StrI,char *StrC,size_t szStrC,BYTE flag); // �������������� �������� ������ � ������� ��� ����� �������.

BYTE ber; size_t ln; char *cp,*str,*ext;

if(hInst==NULL) return 1;
if(GetModuleFileName(hInst,PathToProgDir,strL_Path)==0) { ErrMessage(); return 2;}
ln=strlen(PathToProgDir); if(ln==0) return 3;
str=NULL; ber=0;
if(AllocString(&str,ln)!=0) { ber=5; goto end;}
if(StrSybmConv(PathToProgDir,str,ln+1,1)!=0) { ber=6; goto end;}
if(typ==0) ext=".EXE"; else ext=".DLL";
cp=strstr(str,ext); if(cp==NULL) { ber=7; goto end;} *cp='\0';
cp=strrchr(str,'\\'); if(cp==NULL) { ber=8; goto end;} cp++; *cp='\0';
ln=strlen(str); PathToProgDir[ln]='\0';
end: FreeString(&str); return ber;
}
