/*...........................................................................................................

// ��������� � ������������ ������.
AllocString,FreeString,AllocPString,FreePString,AllocBYTE,FreeBYTE,AllocSHRT,FreeSHRT,AllocFloat,FreeFloat,
AllocComplex,FreeComplex,

// ������ � ������� � ������������.
IsFileDirExists,IsFileExist,IsFileExist_,Process,

// ������ � ������������ *.dll.
LoadLib,

// ���������.
DrawLine_,
CrSelPen,CrSelPen_,UnSelDelPen,CrSelBrush,UnSelDelBrush,
DrawRect_,ImgRectC,ImgWinC,

// ������ �� ��������.
IsOKStr,StrCopy,StrCat,DupString,StrSybmConv,GetString,ReadString,GetName,

// ������ � ����.
SetStMenuItem_,

// ������ �� ��������.
GetFont,SetFont,

// ������ � ������.
CloseWin_,DestroyWin_,ShowWin,SizeMovWin,EnableChWin,SetPosWindow,SetPosWindowCenter,SetPosWindowCenter_,
SetMinSizeWin,CheckWindowSize,

// ������ � ���������������� ��������.
SetSizeCombo,GetSelCombo,

// ������ � ������� �������� ����������� ������.
InitProgress,SetColProgr,ShowProgress,

// ��������� ����� ����� �� ������ �����.
GetBYTE,GetUSHRT_Test,GetUSHRT_Test,GetUSHRT_Test,GetUINT_Test,

// ���������.
ErrMessage,Message,Message_,

// ������.
SetBit,IsOKRect,ProcMess,SoundBlock

...........................................................................................................*/

#include "stdafx.h"

#include "VC_con.h"
#include "cmplx.h"
#include "resource.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������.

BYTE AllocPString(char ***pStr,BYTE n); // ��������� ������ ��� ������� ���������� �� char.
void FreePString(char ***pStr); // ������������ ������ ��� ������� ���������� �� char.
BYTE IsOKStr(char *str); // �������� ������.
BYTE GetString(char **String,char **Items,BYTE n); // ������ ������ �� ���������� �����.
BYTE StrCopy(char *Dst,size_t lnDst,char *Src); // ����������� �����.
BYTE StrCat(char *Dst,size_t lnDst,char *Src); // ����������� �����.
void ErrMessage(void); // ������ ��������� �� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� ����������.

extern HINSTANCE hInst; // ������������� ����������.
extern LRESULT LRes; // ��������������� ����������.

// ������� ������ ����������.
extern HCURSOR cur_wait;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������.

extern char TxtStr[strL_Txt],TxtMem[strL_Txt]; // ��������������� ������.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� � ������������ ������.

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������.

BYTE AllocString(char **Str,size_t ln)
{
void FreeString(char **Str); // ������������ ������ ��� ������.

if(Str==NULL) return 1; FreeString(Str);
*Str=new char[ln+1]; if(*Str==NULL) return messNoMem; *(*Str+ln)='\0'; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ ��� ������.

void FreeString(char **Str)
{
if(Str==NULL) return; SAFE_DELETE_ARR(*Str);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������� ���������� �� char.

BYTE AllocPString(char ***pStr,BYTE n)
{
void FreePString(char ***pStr); // ������������ ������ ��� ������� ���������� �� char.

BYTE i;

if(pStr==NULL) return 1; if(n==0) return 2; FreePString(pStr);
*pStr=new typPntChar[n]; if(*pStr==NULL) return messNoMem;
for(i=0;i<n;i++) (*pStr)[i]=NULL; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ ��� ������� ���������� �� char.

void FreePString(char ***pStr)
{
if(pStr==NULL) return; SAFE_DELETE_ARR(*pStr);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������� 'BYTE'.

BYTE AllocBYTE(BYTE **bpp,size_t ln)
{
void FreeBYTE(BYTE **bpp); // ������������ ������ ��� ������� 'BYTE'.

if(bpp==NULL) return 1; if(ln==0) return 2; FreeBYTE(bpp);
*bpp=new BYTE[ln]; if(*bpp==NULL) return messNoMem; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ ��� ������� 'BYTE'.

void FreeBYTE(BYTE **bpp)
{
if(bpp==NULL) return; SAFE_DELETE_ARR(*bpp);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������� 'SHRT'.

BYTE AllocSHRT(SHRT **shipp,size_t ln)
{
void FreeSHRT(SHRT **shipp); // ������������ ������ ��� ������� 'SHRT'.

if(shipp==NULL) return 1; if(ln==0) return 2; FreeSHRT(shipp);
*shipp=new SHRT[ln]; if(*shipp==NULL) return messNoMem; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ ��� ������� 'SHRT'.

void FreeSHRT(SHRT **shipp)
{
if(shipp==NULL) return; SAFE_DELETE_ARR(*shipp);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������� 'float'.

BYTE AllocFloat(float **fpp,size_t ln)
{
void FreeFloat(float **fpp); // ������������ ������ ��� ������� 'float'.

if(fpp==NULL) return 1; if(ln==0) return 2; FreeFloat(fpp);
*fpp=new float[ln]; if(*fpp==NULL) return messNoMem; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ ��� ������� 'float'.

void FreeFloat(float **fpp)
{
if(fpp==NULL) return; SAFE_DELETE_ARR(*fpp);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������� 'complex'.

BYTE AllocComplex(complex **cpp,size_t ln)
{
void FreeComplex(complex **cpp); // ������������ ������ ��� ������� 'complex'.

if(cpp==NULL) return 1; if(ln==0) return 2; FreeComplex(cpp);
*cpp=new complex[ln]; if(*cpp==NULL) return messNoMem; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ ��� ������� 'complex'.

void FreeComplex(complex **cpp)
{
if(cpp==NULL) return; SAFE_DELETE_ARR(*cpp);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������ � ������� � ������������.

//-----------------------------------------------------------------------------------------------------------
// �������� ������������� ����� ��� ����������.

BYTE IsFileDirExists(char *PathName,BYTE flDir)
{
BYTE ber; DWORD Fl; WIN32_FIND_DATA *FileData;

if(IsOKStr(PathName)!=0) return 1; FileData=NULL; ber=0;
FileData=new WIN32_FIND_DATA; if(FileData==NULL) { ber=2; goto end;}
if(FindFirstFile((LPCTSTR)PathName,FileData)==INVALID_HANDLE_VALUE) { ber=3; goto end;}
Fl=FileData->dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY;
if(flDir==0&&Fl!=0L||flDir!=0&&Fl==0L) { ber=4; goto end;}
end: SAFE_DELETE(FileData); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������������� �����.

BYTE IsFileExist(char *Name,char *PathDir,char *dir,char *ext)
{
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // ��������� ����� ����� ������� ����.
BYTE IsFileDirExists(char *PathName,BYTE flDir); // �������� ������������� ����� ��� ����������.
void FreeString(char **Str); // ������������ ������ ��� ������.

BYTE ber; char *nam;

if(IsOKStr(Name)!=0) return 1; nam=NULL; ber=0;
if(GetName(&nam,PathDir,dir,Name,ext)!=0) { ber=2; goto end;}
if(IsFileDirExists(nam,0)!=0) { ber=3; goto end;}
end: FreeString(&nam); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������������� �����.

BYTE IsFileExist_(char *PathName)
{
BYTE IsFileDirExists(char *PathName,BYTE flDir); // �������� ������������� ����� ��� ����������.

return IsFileDirExists(PathName,0);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define nStrAppPath 3 // ����� ����� ��� ��������� ���� � ���������.

//-----------------------------------------------------------------------------------------------------------
// ������ ������ ���������.

BYTE Process(char *Path,char *Dir,char *Name,char *ComStr,char *CurrDir,BYTE show,BYTE wait)
{
void ErrMessage(void); // ������ ��������� �� ������.

BYTE ber; char *AppPath,**Items; WORD *pw; PROCESS_INFORMATION *PrInf; STARTUPINFO *StUpInfo; HCURSOR cur;

AppPath=NULL; Items=NULL; PrInf=NULL; StUpInfo=NULL; cur=NULL; ber=0;
PrInf=new PROCESS_INFORMATION; if(PrInf==NULL) { ber=1; goto end;}
StUpInfo=new STARTUPINFO; if(StUpInfo==NULL) { ber=2; goto end;}
if(AllocPString(&Items,nStrAppPath)!=0) { ber=3; goto end;}
Items[0]=Path; Items[1]=Dir; Items[2]=Name;
if(GetString(&AppPath,Items,nStrAppPath)!=0) { ber=4; goto end;}

SET_ZERO(PrInf);
SET_ZERO(StUpInfo); StUpInfo->cb=sizeof(STARTUPINFO);
GetStartupInfo(StUpInfo);
pw=&StUpInfo->wShowWindow; if(show!=0) *pw=SW_SHOWNORMAL; else *pw=SW_HIDE;

if(wait!=0&&cur_wait!=NULL) cur=SetCursor(cur_wait);
if(CreateProcess(AppPath,ComStr,NULL,NULL,TRUE,CREATE_NEW_CONSOLE,NULL,CurrDir,StUpInfo,PrInf)==FALSE) {
ErrMessage(); ber=5; goto end;}
if(wait!=0) WaitForSingleObject(PrInf->hProcess,INFINITE);
SAFE_CLOSE_FILE(PrInf->hProcess);
SAFE_CLOSE_FILE(PrInf->hThread);

end: if(cur!=NULL) SetCursor(cur); SAFE_DELETE(PrInf); SAFE_DELETE(StUpInfo);
FreeString(&AppPath); FreePString(&Items); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������ � ������������ *.dll.

//-----------------------------------------------------------------------------------------------------------
// �������� ���������� '*.dll'.

BYTE LoadLib(char *nameLib,char *Path,char *dir,HMODULE *hLib)
{
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // ��������� ����� ����� ������� ����.
BYTE IsFileExist(char *Name,char *PathDir,char *dir,char *ext); // �������� ������������� �����.
void Message_(HWND hwnd,UINT StrID,char *txt,UINT typ); // ����� ���������.

BYTE ber; char *cp,*ext,*extDLL=".dll";

if(IsOKStr(nameLib)!=0) return 1; if(hLib==NULL) return 2;
ber=0; cp=NULL;
if(strchr(nameLib,'.')==NULL) ext=extDLL; else ext=NULL;
if(GetName(&cp,Path,dir,nameLib,ext)!=0) { ber=3; goto end;}
if(IsFileExist(nameLib,Path,dir,ext)!=0) { Message_(NULL,IDS_Err_NoFileDLL,cp,MB_ST); ber=4; goto end;}
*hLib=LoadLibrary((LPCTSTR)cp);
if(*hLib==NULL) { ErrMessage(); Message_(NULL,IDS_Err_LoadDLL,cp,MB_EX); ber=5; goto end;}
end: FreeString(&cp); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ���������.

//-----------------------------------------------------------------------------------------------------------
// ��������� �����.

void DrawLine_(HDC hdc,int xI,int yI,int xF,int yF)
{
if(hdc==NULL) return; MoveToEx(hdc,xI,yI,NULL); LineTo(hdc,xF,yF);
}

//-----------------------------------------------------------------------------------------------------------
// �������� � ����� ����.

BYTE CrSelPen(HDC hdc,HPEN *hPen,HPEN *hPenP,BYTE Wid,DWORD Col)
{
BYTE CrSelPen_(HDC hdc,HPEN *hPen,HPEN *hPenP,int penStyle,BYTE Wid,DWORD Col); // �������� � ����� ����.

return CrSelPen_(hdc,hPen,hPenP,PS_SOLID,Wid,Col);
}

//-----------------------------------------------------------------------------------------------------------
// �������� � ����� ����.

BYTE CrSelPen_(HDC hdc,HPEN *hPen,HPEN *hPenP,int penStyle,BYTE Wid,DWORD Col)
{
BYTE fl;

if(hdc==NULL) return 1;
if(hPen==NULL) return 2; if(*hPen!=NULL) return 3;
if(hPenP==NULL) return 4; if(*hPenP!=NULL) return 5;
if(Wid==0) fl=1; else {
*hPen=CreatePen(penStyle,(int)Wid,(COLORREF)Col);
if(*hPen!=NULL) { fl=0; *hPenP=(HPEN)SelectObject(hdc,*hPen);} else fl=2;}
if(fl!=0) *hPenP=(HPEN)SelectObject(hdc,GetStockObject(NULL_PEN));
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ � �������� ����.

void UnSelDelPen(HDC hdc,HPEN *hPen,HPEN *hPenP)
{
if(hPenP!=NULL) { if(*hPenP!=NULL&&hdc!=NULL) SelectObject(hdc,*hPenP); *hPenP=NULL;}
if(hPen!=NULL) SAFE_DELETE_OBJECT(*hPen);
}

//-----------------------------------------------------------------------------------------------------------
// �������� � ����� �����.

BYTE CrSelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP,DWORD Col)
{
if(hdc==NULL) return 1;
if(hBrush==NULL) return 2; if(*hBrush!=NULL) return 3;
if(hBrushP==NULL) return 4; if(*hBrushP!=NULL) return 5;
*hBrush=CreateSolidBrush((COLORREF)Col);
if(*hBrush!=NULL) *hBrushP=(HBRUSH)SelectObject(hdc,*hBrush);
else *hBrushP=(HBRUSH)SelectObject(hdc,GetStockObject(NULL_BRUSH));
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ � �������� �����.

void UnSelDelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP)
{
if(hBrushP!=NULL) { if(*hBrushP!=NULL&&hdc!=NULL) SelectObject(hdc,*hBrushP); *hBrushP=NULL;}
if(hBrush!=NULL) SAFE_DELETE_OBJECT(*hBrush);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������������.

BYTE DrawRect_(HDC hdc,RECT *rc)
{
if(hdc==NULL) return 1; if(rc==NULL) return 2;
if(Rectangle(hdc,(int)rc->left,(int)rc->top,(int)rc->right,(int)rc->bottom)==FALSE) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ��������������.

void ImgRectC(HDC hdc,RECT *rc,DWORD ColP,DWORD ColB,BYTE Wid)
{
HBRUSH hBrush,hBrushP; HPEN hPen,hPenP;

if(hdc==NULL||rc==NULL) return;
hBrush=hBrushP=NULL; hPen=hPenP=NULL;
CrSelBrush(hdc,&hBrush,&hBrushP,ColB);
CrSelPen(hdc,&hPen,&hPenP,Wid,ColP);
DrawRect_(hdc,rc);
UnSelDelBrush(hdc,&hBrush,&hBrushP);
UnSelDelPen(hdc,&hPen,&hPenP);
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ����.

void ImgWinC(HWND hwnd,DWORD ColP,DWORD ColB)
{
void ImgRectC(HDC hdc,RECT *rc,DWORD ColP,DWORD ColB,BYTE Wid); // ������������ ��������������.

HDC hdc; RECT rc; PAINTSTRUCT ps;

if(hwnd==NULL) return;
hdc=BeginPaint(hwnd,&ps); if(hdc==NULL) goto end; if(GetClientRect(hwnd,&rc)==FALSE) goto end;
SetMapMode(hdc,MM_TEXT); SetROP2(hdc,R2_COPYPEN); SetBkMode(hdc,TRANSPARENT);
ImgRectC(hdc,&rc,ColP,ColB,1);
end: EndPaint(hwnd,&ps);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������ �� ��������.

//-----------------------------------------------------------------------------------------------------------
// �������� ������.

BYTE IsOKStr(char *str)
{
if(str==NULL) return 1; if(strlen(str)==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� �����.

BYTE StrCopy(char *Dst,size_t lnDst,char *Src)
{
size_t i,lnS;

if(Dst==NULL) return 1; if(lnDst==0) return 2; if(Src==NULL) return 3; lnS=strlen(Src); if(lnS>=lnDst) return 4;
if(lnS>0) for(i=0;i<lnS;i++) Dst[i]=Src[i]; Dst[lnS]='\0'; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� �����.

BYTE StrCat(char *Dst,size_t lnDst,char *Src)
{
size_t i,lnD,lnS;

if(Dst==NULL) return 1; if(lnDst==0) return 2; if(Src==NULL) return 0;
lnS=strlen(Src); if(lnS==0) return 0; lnD=strlen(Dst); if(lnS+lnD>=lnDst) return 3;
for(i=0;i<lnS;i++) Dst[i+lnD]=Src[i]; Dst[lnS+lnD]='\0'; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������ � �����������.

BYTE DupString(char **Str,char *Src)
{
size_t ln;

if(Str==NULL) return 1; FreeString(Str); if(Src==NULL) return 2; ln=strlen(Src); if(ln==0) return 3;
if(AllocString(Str,ln)!=0) return 4; strcpy(*Str,Src); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������������� �������� ������ � ������� ��� ������ �������.

BYTE StrSybmConv(char *StrI,char *StrC,size_t szStrC,BYTE flag)
{
char sh,*c,*cC; SCHAR s; size_t i,sz;

if(StrI==NULL) return 1; sz=strlen(StrI); if(sz==0) return 2; if(StrC==NULL) return 3;
if(szStrC==0) return 4; if(sz+1>szStrC) return 5;
sh='A'-'a';
for(i=0;i<sz;i++) { c=StrI+i; cC=StrC+i; s=0;
if(flag!=0) { if(*c>='a'&&*c<='z') s=1;} else { if(*c>='A'&&*c<='Z') s=-1;}
*cC=*c; if(s!=0) *cC=char((SHRT)*cC+(SHRT)sh*(SHRT)s);}
StrC[sz]='\0'; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ������ �� ���������� �����.

BYTE GetString(char **String,char **Items,BYTE n)
{
BYTE i; size_t ln,lns;

if(String==NULL) return 1; if(Items==NULL) return 2; if(n==0) return 3; lns=0;
for(i=0;i<n;i++) { if(Items[i]==NULL) continue; ln=strlen(Items[i]); if(szMemMax-ln<lns) return 4; lns+=ln;}
if(AllocString(String,lns)!=0) return 5; lns++; if(StrCopy(*String,lns,"")!=0) return 6;
for(i=0;i<n;i++) { if(Items[i]==NULL) continue; if(StrCat(*String,lns,Items[i])!=0) return 7;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ������ �� ���������� �����.

BYTE ReadString(FILE *file,char *str,size_t strLen)
{
int e; size_t i; char c;

if(str==NULL) return 1; if(strLen==0) return 2; if(file==NULL) { *str='\0'; return 3;}
i=0; c=0; e=0;
while(TRUE) { e=fscanf(file,"%c",&c); if(e==EOF) break; if(c==' '&&i==0) continue; if(c=='\n'||c=='\r') break;
if(i<strLen-1) { *(str+i)=c; i++;}} *(str+i)='\0'; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����� ����� ������� ����.

BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext)
{
BYTE ber; char **Items;

Items=NULL; ber=0;
if(AllocPString(&Items,4)!=0) { ber=1; goto end;}
Items[0]=path; Items[1]=dir; Items[2]=name; Items[3]=ext;
if(GetString(Name,Items,4)!=0) { ber=2; goto end;}
end: FreePString(&Items); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������ � ����.

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� ������ ����.

void SetStMenuItem_(HMENU hMenu,UINT id,SCHAR En,SCHAR Ch)
{
UINT ui;

if(hMenu==NULL) return; if(id==0) return;
if(En>=0) { if(En==0) ui=MF_GR; else ui=MF_EN; EnableMenuItem(hMenu,id,ui);}
if(Ch>=0) { if(Ch==0) ui=MF_UNCH; else ui=MF_CH; CheckMenuItem(hMenu,id,ui);}
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������ �� ��������.

//-----------------------------------------------------------------------------------------------------------
// �������� ������.

HFONT GetFont(char *nameFont,SHRT Wid,SHRT Hei)
{
if(nameFont==NULL) return NULL;
return CreateFont((int)Hei,(int)Wid,0,0,FW_THIN|FW_NORMAL,0,0,0,DEFAULT_CHARSET,OUT_RASTER_PRECIS,
CLIP_DEFAULT_PRECIS,PROOF_QUALITY,DEFAULT_PITCH|FF_ROMAN,nameFont);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��� ��������� ������ � ����.

BYTE SetFont(HWND hwnd,HFONT hFont)
{
if(hwnd==NULL) return 1; if(hFont==NULL) return 2;
SendMessage(hwnd,WM_SETFONT,(WPARAM)hFont,(LPARAM)MAKELONG((WORD)TRUE,0)); return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������ � ������.

//-----------------------------------------------------------------------------------------------------------
// �������� ����.

void CloseWin_(HWND *hwnd)
{
if(hwnd==NULL) return; if(*hwnd==NULL) return; SendMessage(*hwnd,WM_CLOSE,0,0L); *hwnd=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ���� � ���������� 'hwnd'.

void DestroyWin_(HWND *hwnd)
{
if(hwnd==NULL) return; if(*hwnd==NULL) return; DestroyWindow(*hwnd); *hwnd=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ��� ������� ����.

void ShowWin(HWND hwnd,BYTE flVis)
{
if(hwnd==NULL) return; if(flVis!=0) { ShowWindow(hwnd,SW_SHOWNORMAL); UpdateWindow(hwnd);} else ShowWindow(hwnd,SW_HIDE);
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ���� � ��������� ��� ��������.

BYTE SizeMovWin(HWND hwnd,int shX,int shY,int dX,int dY,BYTE flChild)
{
int dx,dy; RECT rc; POINT pt; HWND hwndP;

if(hwnd==NULL) return 1; if(flChild!=0) { hwndP=GetParent(hwnd); if(hwndP==NULL) return 2;}
if(GetWindowRect(hwnd,&rc)==FALSE) return 3;
pt.x=rc.left; pt.y=rc.top; if(flChild!=0) { if(ScreenToClient(hwndP,&pt)==FALSE) return 4;}
if(dX>0) dx=dX; else dx=(int)(rc.right-rc.left);
if(dY>0) dy=dY; else dy=(int)(rc.bottom-rc.top);
if(MoveWindow(hwnd,(int)pt.x+shX,(int)pt.y+shY,dx,dy,TRUE)==FALSE) return 5; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� � ������ ���������� ��������� ����.

void EnableChWin(HWND hDlg,int id,BYTE flag)
{
BOOL b; HWND hwnd;

if(hDlg==NULL||id<=0) return; hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return;
if(flag!=0) b=TRUE; else b=FALSE; EnableWindow(hwnd,b);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������������ ����.

BYTE SetPosWindow(HWND hwnd,RECT *rc)
{
int dx,dy;

if(hwnd==NULL) return 1; if(rc==NULL) return 2;
dx=(int)(rc->right-rc->left);
dy=(int)(rc->bottom-rc->top);
if(MoveWindow(hwnd,(int)rc->left,(int)rc->top,dx,dy,TRUE)==FALSE) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���� � ����� ������� ���� ��� ������.

void SetPosWindowCenter(HWND hDlg)
{
BYTE SetPosWindowCenter_(HWND hDlg,HWND hwnd); // ��������� ���� 'hDlg' � ����� ���� 'hwnd'.

HWND hwnd;

if(hDlg==NULL) return; hwnd=GetWindow(hDlg,GW_OWNER); if(hwnd==NULL) hwnd=GetDesktopWindow();
SetPosWindowCenter_(hDlg,hwnd);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���� 'hDlg' � ����� ���� 'hwnd'.

BYTE SetPosWindowCenter_(HWND hDlg,HWND hwnd)
{
long d,dW,xi,yi,*lp; RECT rc,rcW,rcD;

if(hDlg==NULL) return 1; if(hwnd==NULL) return 2;
if(GetWindowRect(hDlg,&rcW)==FALSE) return 3;
if(GetWindowRect(hwnd,&rc)==FALSE) return 4;
if(GetWindowRect(GetDesktopWindow(),&rcD)==FALSE) return 5;
lp=&xi; dW=rcW.right-rcW.left; d=rc.right-rc.left; *lp=(d-dW)/2; *lp+=rc.left;
d=rcD.right-rcD.left; if(d>dW) { if(*lp<0) *lp=0; else if(*lp+dW>d) *lp=d-dW;}
lp=&yi; dW=rcW.bottom-rcW.top; d=rc.bottom-rc.top; *lp=(d-dW)/2; *lp+=rc.top;
d=rcD.bottom-rcD.top; if(d>dW) { if(*lp<0) *lp=0; else if(*lp+dW>d) *lp=d-dW;}
if(SetWindowPos(hDlg,NULL,(int)xi,(int)yi,0,0,SWP_NOZORDER|SWP_NOSIZE)==FALSE) return 6; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������������ ������� ����.

BYTE SetMinSizeWin(HWND hwnd,LPMINMAXINFO lpMinMax,int dxm,int dym)
{
long dx,dy; POINT *pt; RECT rc; 

pt=&lpMinMax->ptMinTrackSize;
if(hwnd==NULL) dx=dy=0; else { 
if(GetClientRect(hwnd,&rc)==FALSE) return 1; dx=rc.right-rc.left; dy=rc.bottom-rc.top;
if(GetWindowRect(hwnd,&rc)==FALSE) return 2; dx=rc.right-rc.left-dx; dy=rc.bottom-rc.top-dy;}
if(dxm>0) pt->x=(long)dxm+dx; if(dym>0) pt->y=(long)dym+dy; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������������ ������� ����.

BYTE CheckWindowSize(HWND hwnd,int dxm,int dym)
{
long dx,dy,dxc,dyc; RECT rc;

if(hwnd==NULL) return 1; if(dxm<=0||dym<=0) return 2;
if(GetClientRect(hwnd,&rc)==FALSE) return 3; dxc=rc.right-rc.left; dyc=rc.bottom-rc.top;
if(GetWindowRect(hwnd,&rc)==FALSE) return 4; dx=rc.right-rc.left; dy=rc.bottom-rc.top;
if(dxc>=(long)dxm&&dyc>=(long)dym) return 0; 

if(dxc<(long)dxm) dx+=(long)dxm-dxc;
if(dyc<(long)dym) dy+=(long)dym-dyc; 
SetWindowPos(hwnd,HWND_TOP,0,0,dx,dy,SWP_SHOWWINDOW|SWP_NOMOVE); return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������ � ���������������� ��������.

//-----------------------------------------------------------------------------------------------------------
// ��������� ������� ���������������� ������ �� ����� �����.

BYTE SetSizeCombo(HWND hDlg,int id,BYTE num)
{
BYTE SizeMovWin(HWND hwnd,int shX,int shY,int dX,int dY,BYTE flChild); // ����������� ���� � ��������� ��� ��������.

SHRT Hei; HWND hwnd; RECT rc;

if(hDlg==NULL) return 1; if(id<=0) return 2; if(num==0) return 3;
hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return 4;
if(GetWindowRect(hwnd,&rc)==FALSE) return 5;
Hei=(SHRT)(rc.bottom-rc.top);
LRes=SendMessage(hwnd,CB_GETITEMHEIGHT,0,0L); if(LRes!=CB_ERR) Hei+=((SHRT)LRes+1)*(SHRT)num;
if(SizeMovWin(hwnd,0,0,0,(int)Hei,1)!=0) return 6; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��������� ������ � ��������������� ������.

BYTE GetSelCombo(HWND hDlg,UINT id,BYTE *num)
{
HWND hwnd;

if(hDlg==NULL) return 1; if(id==0) return 2; if(num==NULL) return 3;
hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return 4;
LRes=SendMessage(hwnd,CB_GETCURSEL,0,0L); if(LRes==CB_ERR) return 5; if(LRes>UCHAR_MAX) return 6;
*num=(BYTE)LRes; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������ � ������� �������� ����������� ������.

//-----------------------------------------------------------------------------------------------------------
// ������������� ���� ������ �������� ���������� ������.

HWND InitProgress(HWND hDlg,int id)
{
HWND hwnd;

if(hDlg==NULL) return NULL; if(id<=0) return NULL;
hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return NULL;
SendMessage(hwnd,PBM_SETRANGE,0,MAKELPARAM(0,100));
SendMessage(hwnd,PBM_SETSTEP,(WPARAM)1,0L);
return hwnd;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ������������ ������ ������ �������� ���������� ������.

void SetColProgr(HWND hwnd,DWORD BkgCol,DWORD BarCol)
{
if(hwnd==NULL) return;
SendMessage(hwnd,PBM_SETBKCOLOR,0,(LPARAM)BkgCol);
SendMessage(hwnd,PBM_SETBARCOLOR,0,(LPARAM)BarCol);
}

//-----------------------------------------------------------------------------------------------------------
// ����������� �������� �� ��������.

void ShowProgress(HWND hwndProgr,double v,double vMax)
{
BYTE GetBYTE(float v); // ��������� ����� 'BYTE' �� ����� 'float' � ��������� ������ �� ������� 'BYTE'.

BYTE Perc;

if(vMax<=0.) { SendMessage(hwndProgr,PBM_SETPOS,0,0L); return;}
if(v>=vMax) Perc=100; else Perc=GetBYTE((float)v/(float)vMax*100.0F);
if(hwndProgr!=NULL) SendMessage(hwndProgr,PBM_SETPOS,(WPARAM)Perc,0L);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ����� ����� �� ������ �����.

//-----------------------------------------------------------------------------------------------------------
// ��������� ����� 'BYTE' �� ����� 'float' � ��������� ������ �� ������� 'BYTE'.

BYTE GetBYTE(float v)
{
float w;

if(v<=0.0F) return 0; w=v+0.5F; if(w>=(float)UCHAR_MAX) return UCHAR_MAX; return (BYTE)w;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����� 'USHRT' �� ����� 'int' � ��������� ������ �� ������� 'USHRT'.

USHRT GetUSHRT_Test(int iv)
{
if(iv<0) return 0; if(iv>=USHRT_MAX) return USHRT_MAX; return (USHRT)iv;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����� 'USHRT' �� ����� 'float' � ��������� ������ �� ������� 'USHRT'.

USHRT GetUSHRT_Test(float v)
{
float w;

if(v<=0.0F) return 0; w=v+0.5F; if(w>=(float)USHRT_MAX) return USHRT_MAX; return (USHRT)w;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����� 'USHRT' �� ����� 'double' � ��������� ������ �� ������� 'USHRT'.

USHRT GetUSHRT_Test(double d)
{
double w;

if(d<=0.) return 0; w=d+0.5; if(w>=(double)USHRT_MAX) return USHRT_MAX; return (USHRT)w;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����� 'UINT' �� ����� 'float' � ��������� ������ �� ������� 'UINT'.

UINT GetUINT_Test(float v)
{
float w;

if(v<=0.0F) return 0; w=v+0.5F; if(w>=(float)UINT_MAX) return UINT_MAX; return (UINT)w;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ���������.

//-----------------------------------------------------------------------------------------------------------
// ������ ��������� �� ������.

void ErrMessage(void)
{
LPVOID lpMsgBuf;

FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS,
NULL,GetLastError(),MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),(LPTSTR)&lpMsgBuf,0,NULL);
MessageBox(NULL,(LPCTSTR)lpMsgBuf,"Error",MB_IN); LocalFree(lpMsgBuf);
}

//-----------------------------------------------------------------------------------------------------------
// ����� ���������.

void Message(UINT StrID,UINT typ)
{
if(hInst==NULL) return; if(LoadString(hInst,StrID,TxtMem,strL_Txt)==0) return; MessageBox(NULL,TxtMem,"",typ);
}

//-----------------------------------------------------------------------------------------------------------
// ����� ���������.

void Message_(HWND hwnd,UINT StrID,char *txt,UINT typ)
{
if(hInst==NULL) return; if(LoadString(hInst,StrID,TxtMem,strL_Txt)==0) return;
if(txt!=NULL) MessageBox(hwnd,txt,TxtMem,typ); else MessageBox(hwnd,TxtMem,"",typ);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������.

//-----------------------------------------------------------------------------------------------------------
// ��������� ���� � ����� 'BYTE'.

void SetBit(BYTE *bp,BYTE num,BYTE b)
{
BYTE fl;

if(bp==NULL) return; if(num>=8) return; fl=1; fl=fl<<num; if(b!=0) *bp|=fl; else *bp&=~fl;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ��������������.

BYTE IsOKRect(RECT *rc)
{
if(rc==NULL) return 1; if(rc->right<=rc->left) return 2; if(rc->bottom<=rc->top) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ����� ������� ��������� � ��������� ���������.

void ProcMess(void)
{
MSG msg;

while(PeekMessage(&msg,NULL,0U,0U,PM_REMOVE)) { TranslateMessage(&msg); DispatchMessage(&msg);}
}

//-----------------------------------------------------------------------------------------------------------
// ���� ��� ��������������� ��������.

void SoundBlock(void)
{
MessageBeep(MB_ICONHAND);
}
