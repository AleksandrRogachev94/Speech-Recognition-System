/*...........................................................................................................

clWinText,clMain

...........................................................................................................*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������������� �������� ����.

#define id_Win_Edit 1 // ���� ��������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ��� ���� ������ �������������.

class clWinText {

HWND hwndEdt; // ������������� ���� ��������������.
HWND hwndOwner; // ������������� ������������� ����.
RECT *rcWin; // ������������� ����.
RECT rcEdt; // ������������� ���� ��������� ������.
USHRT dxMin,dyMin; // ����������� ������� ����.
HBRUSH hBrushBkg,hBrushDial; // ����� ��� ������������ ����.
HFONT hFontText; // ����� ��� ������ ������.

void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
void ZeroBrushes(void); // ��������� ������ ��� ������������ ����.
void FreeBrushes(void); // �������� ������ ��� ������������ ����.
BYTE CreateBrushes(void); // �������� ������ ��� ������������ ����.
void ZeroFont(void); // ��������� ��������� ��� ������.
void FreeFont(void); // �������� ������.
BYTE LoadFont(void); // �������� ������.
void OnCloseWin(void); // �������� ��� �������� ����.
void GetMinSizeWin(void); // ��������� ������������ ������� ����.
void SetMinSize(LPMINMAXINFO lpMinMax); // ��������� ������������ ������� ����.
BYTE CreateEdt(void); // �������� ���� ��������������.
void CloseEdt(void); // �������� ���� ��������������.
void ChPosSizeChWin(void); // ��������� ������������ �������� ����.
BYTE SetPosSizeChWin(void); // ��������� ������������ �������� ����.

public:

HWND hwnd; // ������������� ����.

clWinText(void);
~clWinText(void);
void SetParPnt(HWND hwndOwner_,RECT *rcWin_); // ��������� ���������� � ����������.
BYTE CreateWin(void); // �������� ����.
void CloseWin(void); // �������� ����.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ��������� ����.
BYTE SetText(char *Text); // ��������� ������ � ����.
void ClearWin(void); // ������� ����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� �������� ����.

class clMain {

BYTE flCaptSound,flStopCaptSound,flDoCommands,flOutWords,cntShutDown; USHRT dxMin,dyMin;
UINT TimeRecBuf,TimeRecProc,nRecChar,nRecText,cntPause; HWND hwnd,hDlg,hwndProgr; RECT rc,rcText;
HBRUSH hBrushBkg,hBrushDial; HMENU hMenu,hMenu_; clHelpEx *Help;

struct strParSpProc ParSpectr; // ��������� ������������ ���������.
clLoadDLLSndCap *SndCap; // ����� ��� ������ � ����������� �� ������� �����.
clSndCapData *SndCapData; // ����� �����, ����������� ��� ������ � ���� ��������� ��������.
struct strNNW NNW_Spectr; // ����� ��������� ����.
clString RecNNW; // ������� ������, �������������� � ������ � �������� �������.
clString RecText; // ������� ������������� ������.
struct strAnalyseSound AnSound; // ��������� ��� ������� ������ ��������.
struct strAnalyseData AnStream; // ��������� ��� ������� ������ ������.
struct strDictionary Dict; // ��������� �������.
struct strRecognAllWords RecWords; // ��������� ��� ������������� ����.
clWinText WinText; // ����� ���� ������ - ���������� �������������.

void Zero(void); // ��������� ��������������� � ����������.
void Free(void); // ������������ ������.
void ZeroBrushes(void); // ��������� ������ ��� ������������ ����.
void FreeBrushes(void); // �������� ������ ��� ������������ ����.
BYTE CreateBrushes(void); // �������� ������ ��� ������������ ����.
void ZeroMenu(void); // ��������� ���������� ��� ����.
void FreeMenu(void); // ������������ ������ �� ����.
BYTE CreateMenu(void); // �������� � �������� ����.
BYTE ShowMenu(LPARAM lParam); // ���������� ���� �� ������.
void ZeroHelp(void); // ��������� ��������� ��� ������ ��� ������ ����� �������.
void FreeHelp(void); // ����������� ������ ��� ������ ����� �������.
BYTE CreateHelp(void); // �������� ������ ��� ������ ����� �������.
void ChMenuHelp(void); // ��������� ��������� ������ ���� �������.
BYTE CreateDlgCntrl(void); // �������� ����������� ������������ ����.
BYTE GetMinSizeWin(void); // ��������� ������������ ������� ����.
void SetMinSize(LPMINMAXINFO lpMinMax); // ��������� ������������ ������� ����.
BYTE MoveWinCorner(void); // ����������� ���� � ������ ������ ����.
BYTE Command(WPARAM wParam); // �������.
BYTE CommandCntrl(WPARAM wParam); // ��������� ������ ���� ����������.
void OnPaint(HDC hdc); // ��������� � ����.
void ZeroSndCapData(void); // ����� �������� ������ ��� ������ �����: ��������� ���������.
void FreeSndCapData(void); // ����� �������� ������ ��� ������ �����: �c���������� ������.
BYTE CreateSndCapData(void); // ����� �������� ������ ��� ������ �����: ��������.
void ZeroSndCap(void); // ��������� ��������� �� ������ ������ ���������� ������� �����.
void FreeSndCap(void); // �������� ������� ������ ���������� ������� �����.
BYTE CreateSndCap(void); // �������� ������� ������ ���������� ������� �����.
BYTE StartCaptureSound(void); // ��������� ������ �����.
void StopCaptureSound(void); // ��������� ������ �����.
void StopCaptureSound_(void); // ��������� ������ �����.
void ChBtnMenuCaptureSound(void); // ��������� ������ ���� ������� ����� � ��������� ������.
void SetTxtBtnRecSound(void); // ��������� ������ � ������ ������������� �����.
BYTE DlgAdjSound(void); // ��������� ������� �����.
BYTE ProcRecRealTime(void); // ��������� � ������������� � �������� �������.
BYTE AddSymbTextWin(char Symb); // ���������� ������������� ������� � ����.
BYTE AddWordTextWin(char *Str); // ���������� ������������� ����� � ����.
void ShowProgr(double v,double vMax); // ������ ���������.
BYTE LoadNNW(void); // �������� ��������� ����.
BYTE LoadDict(void); // �������� �������.
void SetPntWinText(void); // ��������� ���������� � ���������� ��� ���� ������.
BYTE GetSizeWinText(void); // ��������� �������� ���� ������.
void OpenWinText(void); // �������� ���� ������.
void ClearWinText(void); // ������� ���� ������.
void SetWinText(char *Text); // ����������� ������ � ����.
void RecognTxtCommand(BYTE numSnd,char Symb); // ������������� ������ � ������.
void DoCommand(BYTE comm); // ���������� ������.
BYTE OpenSysProg(char *NameProg); // �������� ��������� ���������.
BYTE OpenProgFiles(char *PathProg,char *NameProg); // �������� ��������� �� ���������� "Program Files".
BYTE ShowCommand(BYTE comm); // ����������� ������ � ����.
void SetText(char *txt); // ��������� ������ � ����.
void SetWord(char *txt); // ��������� ����� � ����.
BYTE SetString(int idS); // ��������� ������ � ����.
void ChMenuDoCommands(void); // ��������� ��������� ������ ���� �������� ������.
void ChMenuOutWords(void); // ��������� ��������� ������ ���� ������ � ���� ������������ ����.
void OnCloseWin(void); // �������� ��� �������� ����.

public:

clMain(void); // �����������.
~clMain(void); // ����������.
BYTE OnCreate(HWND hwnd_); // �������� � ������ ������ ���������.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ������� ��������� ����.
LRESULT MsgCommandCntrl(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ������� ��������� ���� ����������.
BYTE SaveBufSound(DWORD szBuf,void *pBuf); // ���������� ��� ������ �����.
BYTE GetNumSndRecogn(strLay *pLay,BYTE *numSnd); // ��������� ������ ����� ��� ������������� ������ ����.
void ChMenuWinText(void); // ��������� ��������� ������ � ������ ���� �������� ���� ������.
};
