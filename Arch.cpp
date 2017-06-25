//mmm
sprintf(TxtStr,"be: %d",be); MessageBox(NULL,TxtStr,"",MB_EX);

//-----------------------------------------------------------------------------
// ��������� � ������� ����. 

BYTE OnPaint(HDC hdc,HWND hwnd)
{
BYTE CrSelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP,DWORD Col); // �������� � ����� �����.
void UnSelDelBrush(HDC hdc,HBRUSH hBrush,HBRUSH hBrushP); // ������������ � �������� �����.
void DrawLine_(HDC hdc,int xI,int yI,int xF,int yF); // ��������� �����.

HBRUSH hBrush,hBrushP; RECT rc;

if(hdc==NULL) return 1; if(hwnd==NULL) return 2;
if(GetClientRect(hwnd,&rc)==FALSE) return 3;
hBrush=hBrushP=NULL;
if(CrSelBrush(hdc,&hBrush,&hBrushP,RGB(255,0,0))!=0) return 4; // �������� � ����� �����.
DrawLine_(hdc,(int)rc.left,(int)rc.top,(int)rc.right,(int)rc.bottom);
Ellipse(hdc,100,100,500,400);
UnSelDelBrush(hdc,hBrush,hBrushP); // ������������ � �������� �����.
return 0;
}



//-------------------------------------------------
// ������ �� �����.

BYTE strParam::Read(char *fName)
{
BYTE err; FILE *file;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
file=NULL; err=0;
file=fopen(fName,"rt");
if(file=0) { err=3; goto end;}
if(fscanf(file,"%f",&Time_Width)==EOF) { err=4; goto end;}
end: if(file!=NULL) fclose(file); return err;
}

//-------------------------------------------------
// ���������� � �����.

BYTE strParam::Write(char *fName)
{
BYTE err; FILE *file;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
file=NULL; err=0;
file=fopen(fName,"wt");
if(file=0) { err=3; goto end;}
if(fprintf(file,"%f\n",Time_Width)<0) { err=4; goto end;}
end: if(file!=NULL) fclose(file); return err;
}

//-----------------------------------------------------------------------------
// ������ ���������.

BYTE clMain::ComputeDiag(void)
{
int i,j;

if(sz_Time==0||sz_Freq==0) return 1;
if(sz_Time>szTimeMax||sz_Freq>szFreqMax) return 2;
for(i=0;i<sz_Time;i++) for(j=0;j<sz_Freq;j++) Diag[i][j]=0.0F;

/*for(i=0; i<=20; i=i+1) for(j=0; j<sz_Freq; j=j+1)   Diag[i][j]=150; 

for(i=20; i<=40; i=i+1) for(j=0; j<sz_Freq; j=j+1)  Diag[i][j]=300; 

for(i=40; i<=60; i=i+1) for(j=0; j<sz_Freq; j=j+1)  Diag[i][j]=200; 

for(i=61; i<sz_Time; i=i+1) for(j=20; j<40; j=j+1)  Diag[i][j]=25;*/
for(i=0; i<sz_Time; ++i) for(j=0; j<sz_Freq; ++j) Diag[i][j]=(BYTE)rand(); 
return 0;
}

sz_Time=1000; sz_Freq=512;

//BmpDiag->Image(hdc,0,0,dx,dy,0,0,BmpDiag->dx,BmpDiag->dy,1); // ����� �����������.

if(be!=0) {
//mmm
sprintf(TxtStr,"be: %d pScDiagH,pScDiagV,BmpDiag->dy,dy,: %d %d %d %d %d",be,pScDiagH,pScDiagV,BmpDiag->dy,dy,BmpDiag->dy-dy-pScDiagV);
DrawText(hdc,TxtStr,strlen(TxtStr),&rc,DT_SINGLELINE|DT_VCENTER|DT_CENTER);
}

// WM_LBUTTONDOWN ...........................................................................................
case WM_LBUTTONDOWN: { *flag=1;
	break;}

// WM_RBUTTONDOWN ...........................................................................................
case WM_RBUTTONDOWN: *flag=1; break;

// ��������� ������� ��� ������ ����� � ����������� ������� �������.
if(flPlaySound!=0&&sz_Time>0&&Snd.dt>0.0F) {
x=KoordTime=GetIntTest((float)Snd.dt/Param.Time_Step*(float)PosCurSnd);

hd=GetDC(hwndGraphSpectr);
OnPaintGraphSpectr(hd);
ReleaseDC(hwndGraphSpectr,hd);
UpdateWindow(hwndGraphSpectr);

if(x<pScDiagH||x>=pScDiagH+dx) goto endCurSnd; x-=pScDiagH;
hPen=hPenP=NULL;
CrSelPen(hdc,&hPen,&hPenP,1,COL_LT_GRAY);
MoveToEx(hdc,x,0,NULL); LineTo(hdc,x,dyW);
UnSelDelPen(hdc,&hPen,&hPenP);
hd=GetDC(hwndGraphSpectr);
OnPaintGraphSpectr(hd);
ReleaseDC(hwndGraphSpectr,hd);
UpdateWindow(hwndGraphSpectr);
endCurSnd:;}

/*//xxx
//-----------------------------------------------------------------------------------------------------------
//��������� ��������� ���������� ���� ���������� � �������������� ���������� ��������� ���� ������.

BYTE strDBSArr::MsgCommandDBT(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
int num; HWND hwnd;

if(flag==NULL) return 0L; *flag=0; if(hDlg==NULL) return 0L; if(msg==WM_INITDIALOG) return 0L;

switch(msg) { default: break;

// WM_COMMAND ...............................................................................................
case WM_COMMAND:

switch(LOWORD(wParam)) {

// IDC_DBS ..................................................................................................
case IDC_DBS: if(HIWORD(wParam)!=LBN_SELCHANGE) break;
hwnd=GetDlgItem(hDlg,IDC_DBS); if(hwnd==NULL) break;
num=SendMessage(hwnd,LB_GETCURSEL,0,0); if(num==LB_ERR) break;
if(IsOK()!=0) break; if(num>=n) break;

break;
}

break;
}

return 0L;
}*/

//-----------------------------------------------------------------------------------------------------------
// ������������� ���� ��������� �� �����������.

BYTE clMain::HScrollDiag(WPARAM wParam)
{
int p;

if(hwndDiag==NULL) return 1;
//xxx
(int)LOWORD(wParam)
BYTE ScrollFun32(HWND hwnd,int nScroll,BYTE Dir,BYTE Cntrl,int *p,int nScrl,int nScrlP); // ��������� ��������� �� ������ ���������.

p=pScDiagH; if(ScrollFunS(wParam,&p,0,pMScDiagH,VelScrlPos,AccScrlPos)!=0) return 2; if(p==pScDiagH) return 3;
pScDiagH=p; SetScrollPos(hwndDiag,SB_HORZ,pScDiagH,TRUE); ProcMess(); UpdateWindow_(hwndDiag); ProcMess(); return 0;
}

//yyy
//if(BmpDiag->Image(hdc,0,0,dxW,dyW,0,0,BmpDiag->dx,BmpDiag->dy,1)!=0) return 8; // ����� �����������.

//��������� �������� ������� �������.

case IDC_PGRIGHT: *flag=1;
GetClientRect(hwndGraph,&rc);
dy=rc.right-rc.left;
ShGr=ShGr+dy;
UpdateWindow_(hwndGraph); break;

case IDC_PGLEFT: *flag=1;
GetClientRect(hwndGraph,&rc);
dy=rc.right-rc.left;
ShGr=ShGr-dy;
UpdateWindow_(hwndGraph); break;

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ������������� ������� ��������� �����.

void clMain::PrintResNNW(void)
{
BYTE i;

//yyy
sprintf(TxtStr,"%d",ResNNW[KoordTime]);
MessageBox(NULL,TxtStr,"Number of Peaks",MB_IN);

strcpy(TxtMem,"");
for(i=0;i<nNeuronsInp;i++) {
sprintf(TxtStr,"i,Val: %d %f  ",i,InpLay[KoordTime][i]); strcat(TxtMem,TxtStr);
if((i+1)%5==0) { MessageBox(NULL,TxtMem,"InputLayer",MB_IN); strcpy(TxtMem,"");}
}

}

// ��������� ������� ��� ������ ����� � ����������� ������� �������.
if(flPlaySound!=0&&sz_Time>0&&Snd.dt>0.0F) {
//xxx
x=KoordTime=GetIntTest((float)Snd.dt/Param.Time_Step*(float)PosCurSnd);

hd=GetDC(hwndGraphSpectr);
OnPaintGraphSpectr(hd);
ReleaseDC(hwndGraphSpectr,hd);
UpdateWindow(hwndGraphSpectr);

if(x<pScDiagH||x>=pScDiagH+dx) goto endCurSnd; x-=pScDiagH;
hPen=hPenP=NULL;
/*CrSelPen(hdc,&hPen,&hPenP,1,COL_LT_GRAY);
MoveToEx(hdc,x,0,NULL); LineTo(hdc,x,dyW);
UnSelDelPen(hdc,&hPen,&hPenP); */
hd=GetDC(hwndGraphSpectr);
OnPaintGraphSpectr(hd);
ReleaseDC(hwndGraphSpectr,hd);
UpdateWindow(hwndGraphSpectr);
endCurSnd:;}

//xxx GetFlEdt(hDlg,IDC_AMPL3,&(MW->AmpSpect));

//-----------------------------------------------------------------------------------------------------------
// ��������� � ������� ����. 

BYTE clMain::OnPaint(HDC hdc)
{
BYTE CrSelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP,DWORD Col); // �������� � ����� �����.
void UnSelDelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP); // ������������ � �������� �����.
void DrawLine_(HDC hdc,int xI,int yI,int xF,int yF); // ��������� �����.

HBRUSH hBrush,hBrushP;

if(hdc==NULL) return 1; if(hwnd==NULL) return 2;
if(GetClientRect(hwnd,&rc)==FALSE) return 3;
hBrush=hBrushP=NULL;
if(CrSelBrush(hdc,&hBrush,&hBrushP,RGB(255,0,0))!=0) return 4; // �������� � ����� �����.
UnSelDelBrush(hdc,&hBrush,&hBrushP); // ������������ � �������� �����. 
return 0;
}
WS_OVERLAPPEDWINDOW

//xxx yyy
// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK .....................................................................................................
case IDOK: EndDialog(hDlg,1); if(DBFA!=NULL) DBFA->OnCloseDlg(); return (INT_PTR)TRUE;

// IDCANCEL .................................................................................................
case IDCANCEL: EndDialog(hDlg,0); if(DBFA!=NULL) DBFA->OnCloseDlg(); return (INT_PTR)TRUE;
}
break;

int id; HDC hdc;

// WM_CTLCOLORSTATIC ........................................................................................
case WM_CTLCOLORSTATIC: hdc=(HDC)wParam; id=GetDlgCtrlID((HWND)lParam); if(id<=0) break; *flag=1;
SetBkColor(hdc,GetSysColor(COLOR_WINDOW)); SetTextColor(hdc,GetSysColor(COLOR_BTNTEXT));
SetBkMode(hdc,TRANSPARENT);
//xxx
return (LRESULT)hBrushDial;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ����.

#define nNeurons_1 10 // ����� �������� � ������ ������� ����.

struct strParLay ParLayers[nLayersNNW]={ 
{nNeurons_1,TypFunAct_Sigm},
{nVoices,TypFunAct_Sigm}};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ��������� ����.

struct strParNNW ParNNW={ nLayersNNW,ParLayers};

srand(RandSeq); for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();

ErrMin=LrgCnst12; NRand=0;
for(i=0;i<nStepsRand;i++) { NR=NumRandArr[i];
if(InitRandom(NR,CoeWei,CoeTe)!=0) { ber=7; goto end;}

CheckRadioButton(hDlg,IDC_RADIO_AMP,IDC_RADIO_SIN,IDC_RADIO_AMP+(int)typResSpectr);

// IDC_RADIO_AMP IDC_RADIO_COS IDC_RADIO_SIN ................................................................
case IDC_RADIO_AMP: case IDC_RADIO_COS: case IDC_RADIO_SIN: SelectTypResDiag(id); break;

//-----------------------------------------------------------------------------------------------------------
// ����� ���� ���������� ���������� � ���� ���������.

void clMain::SelectTypResDiag(int id)
{
BYTE typ;

switch(id) { default: return;
case IDC_RADIO_AMP: typ=typResSpectr_Amp; break;
case IDC_RADIO_COS: typ=typResSpectr_AmpCos; break;
case IDC_RADIO_SIN: typ=typResSpectr_AmpSin; break;}
if(typ==typResSpectr) return; typResSpectr=typ; DrawDiag(); UpdateWinDiag(); UpdateWindow_(hwndGraphSpectr);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ��������� ����������� ������������ ��������� � ���� ���������.

#define typResSpectr_Amp    0 // ��������� �������.
#define typResSpectr_AmpCos 1 // ��������� �������, ���������� �� ������� ����.
#define typResSpectr_AmpSin 2 // ��������� �������, ���������� �� ����� ����.

// ����� ���� ���������� ���������� � ���� ���������.
switch(typResSpectr) { default:
case typResSpectr_Amp: pSpArr=&SpectrAmp; break; // ��������� �������.
case typResSpectr_AmpCos: pSpArr=&SpectrReal; break; // ��������� �������, ���������� �� ������� ����.
case typResSpectr_AmpSin: pSpArr=&SpectrImag; break; // ��������� �������, ���������� �� ����� ����.
}

pSpArr=&SpectrAmp;
// ����� ���� �������.
if(typResSpectr==typResSpectr_Amp) pPal=&PalPos; else pPal=&PalSign;

if(typResSpectr==typResSpectr_Amp) {
if(v>=1.0F) nC=nColSmoothPal-1; else if(v<=0.0F) nC=0; else nC=(BYTE)((float)(nColSmoothPal-1)*v);}
else { nCv=(nColSmoothPal-1)/2;
if(v>=1.0F) nC=nColSmoothPal-1; else if(v<=-1.0F) nC=0; else nC=GetBYTE((float)nCv*v+(float)nCv);}

// ����� ���� ���������� ����������.
switch(typResSpectr) { default:
case typResSpectr_Amp: pRes=SpectrAmp[KoordTime]; break; // ��������� �������.
case typResSpectr_AmpCos: pRes=SpectrReal[KoordTime]; break; // ��������� �������, ���������� �� ������� ����.
case typResSpectr_AmpSin: pRes=SpectrImag[KoordTime]; break; // ��������� �������, ���������� �� ����� ����.
}
SpectrReal[szTimeMax][szFreqMax],SpectrImag[szTimeMax][szFreqMax],
for(n=0;n<nPh;n++) SpectrReal[i][n]=(float)real(B[n]);
for(n=0;n<nPh;n++) SpectrImag[i][n]=(float)imag(B[n]);

/*// IDC_ADAPTIVE_STEP ........................................................................................
case IDC_ADAPTIVE_STEP: GetChBox(hDlg,IDC_FILE_TRAIN,&flC);
if(flC==1) { EnableChWin(hDlg,IDC_STEP_TRAIN,1); EnableChWin(hDlg,IDC_ASTEP_MAX,0);}
else { EnableChWin(hDlg,IDC_STEP_TRAIN,0); EnableChWin(hDlg,IDC_ASTEP_MAX,1);}*/



//vvv xxx mmm
cntTrain++;
//vvv mmm xxx
//mmm

if(cntTrain%1000==0) {
sprintf(TxtStr,"i,j,Wei %d %d %e",i,j,pNeur->Weight[i]);
//mmm
MessageBox(NULL,TxtStr,"",MB_EX);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ���������� ��������� ������������ �����.

#define coeSmPeaks_Stand 0.1F // ������� ����� �����, ������� �������������.
#define coePeaks_Stand 0.5F // �������, �� �������� ��� �������������� ����� �����.
#define FreqMin_Stand 60.0F // ����������� ������� �������� ��������� (��).
#define FreqMax_Stand 5000.0F // ������������ �������, �� ������� ���������� ������ (��).
#define ErrFreq_Stand 0.15F // ������������ ������ ��� ���������� ����� �� �������.
#define widPeaks_Stand 30.0F // ���������� ����� (��).
#define LevPowPeak_Stand 0.3F // ����������� ������� ��������, ������� ������ ����������� � �����.
#define coePeaksCorrFreq_Stand 0.3F // ��������� �����, �� ������� ���������� ��������� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ���������� ������������ �����.

struct strParGetPeaks {

BYTE flCorrFreq; float coeSmPeaks,coePeaks,FreqMin,FreqMax,ErrFreq,widPeaks,LevPowPeak,coePeaksCorrFreq;

strParGetPeaks(void); // �����������.
void Init(void); // �������������.
BYTE IsOK(void); // ��������.
USHRT Check(void); // �������� � ���������.
BYTE Read_(FILE *file); // ������ �� �����.
BYTE Read(char *Path,char *fName); // ������ �� �����.
BYTE Write_(FILE *file); // ������ � ����.
BYTE Write(char *Path,char *fName); // ������ � ����.
BYTE SetDlg(HWND hDlg); // ��������� � ���������� ����.
BYTE GetDlg(HWND hDlg); // ��������� �� ����������� ����.
void OnCreateDlg(HWND hDlg); // �������� ��� �������� ����������� ����.
};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ���������� ���������� ������������ �����.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strParGetPeaks::strParGetPeaks(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// �������������.

void strParGetPeaks::Init(void)
{
coeSmPeaks=coeSmPeaks_Stand; coePeaks=coePeaks_Stand; FreqMin=FreqMin_Stand; FreqMax=FreqMax_Stand;
ErrFreq=ErrFreq_Stand; widPeaks=widPeaks_Stand; LevPowPeak=LevPowPeak_Stand;
coePeaksCorrFreq=coePeaksCorrFreq_Stand; flCorrFreq=1;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE strParGetPeaks::IsOK(void)
{
if(coeSmPeaks<=0.0F) return 1; if(coePeaks<=0.0F) return 2;
if(FreqMin<=0.0F) return 3; if(FreqMax<=0.0F) return 4; if(FreqMin>=FreqMax) return 5;
if(ErrFreq<=0.0F) return 6; if(widPeaks<=0.0F) return 7; if(LevPowPeak<=0.0F) return 8;
if(coePeaksCorrFreq<=0.0F) return 9; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� � ���������.

USHRT strParGetPeaks::Check(void)
{
USHRT fl; float *fp;

fl=0;
fp=&coeSmPeaks; if(*fp<=0.0F) { *fp=coeSmPeaks_Stand; fl+=1<<0;}
fp=&coePeaks; if(coePeaks<=0.0F) { *fp=coePeaks_Stand; fl+=1<<1;}
fp=&FreqMin; if(*fp<=0.0F) { FreqMin=FreqMin_Stand; fl+=1<<2;}
fp=&FreqMax; if(*fp<=0.0F) { FreqMax=FreqMax_Stand; fl+=1<<3;}
if(FreqMin>=FreqMax) { FreqMin=FreqMin_Stand; FreqMax=FreqMax_Stand; fl+=1<<4;}
fp=&ErrFreq; if(*fp<=0.0F) { *fp=ErrFreq_Stand; fl+=1<<5;}
fp=&widPeaks; if(*fp<=0.0F) { *fp=widPeaks_Stand; fl+=1<<6;}
fp=&LevPowPeak; if(*fp<=0.0F) { *fp=LevPowPeak_Stand; fl+=1<<7;}
fp=&coePeaksCorrFreq; if(*fp<=0.0F) { *fp=coePeaksCorrFreq_Stand; fl+=1<<8;}
return fl;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strParGetPeaks::Read_(FILE *file)
{
int iv;

if(file==NULL) return 1;
if(fscanf(file,"%f%f%f%f%f%f%f%d%f",&coeSmPeaks,&coePeaks,&FreqMin,&FreqMax,&ErrFreq,&widPeaks,&LevPowPeak,
&iv,&coePeaksCorrFreq)==EOF) return 2;
if(iv==0) flCorrFreq=0; else flCorrFreq=1;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strParGetPeaks::Read(char *Path,char *fName)
{
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // ��������� ����� ����� ������� ����.

BYTE err; char *name; clFileT *FT;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
FT=NULL; name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,NULL)!=0) { err=3; goto end;}
FT=new clFileT(); if(FT==NULL) { err=4; goto end;}
if(FT->Open(name,0)!=0) { err=5; goto end;} 
if(Read_(FT->file)!=0) { err=6; goto end;}
Check(); // �������� � ���������.
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// ������ � ����.

BYTE strParGetPeaks::Write_(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%f %f %f %f %f %f %f %d %f\n",coeSmPeaks,coePeaks,FreqMin,FreqMax,ErrFreq,widPeaks,
LevPowPeak,(int)flCorrFreq,coePeaksCorrFreq)<0) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� � �����.

BYTE strParGetPeaks::Write(char *Path,char *fName)
{
BYTE err; char *name; clFileT *FT;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
FT=NULL; name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,NULL)!=0) { err=3; goto end;}
FT=new clFileT(); if(FT==NULL) { err=4; goto end;}
if(FT->Open(name,1)!=0) { err=5; goto end;}
if(Write_(FT->file)!=0) { err=6; goto end;}
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� � ���������� ����.

BYTE strParGetPeaks::SetDlg(HWND hDlg)
{
BYTE i; int id; float *fp; char *Form;

if(hDlg==NULL) return 1;
for(i=0;i<8;i++) {
switch(i) { default: continue;
case 0: fp=&coeSmPeaks;       id=IDC_COE_SMALL_PEAKS; Form=FormCoeff; break;
case 1: fp=&coePeaks;         id=IDC_COE_PEAKS;       Form=FormCoeff; break;
case 2: fp=&FreqMin;          id=IDC_FREQ_MIN;        Form=FormFreq; break;
case 3: fp=&FreqMax;          id=IDC_FREQ_MAX;        Form=FormFreq; break;
case 4: fp=&ErrFreq;          id=IDC_ERR_FREQ;        Form=FormCoeff; break;
case 5: fp=&widPeaks;         id=IDC_WID_PEAKS;       Form=FormFreq; break;
case 6: fp=&LevPowPeak;       id=IDC_LEV_POW_PEAKS;   Form=FormCoeff; break;
case 7: fp=&coePeaksCorrFreq; id=IDC_AMP_CORR_FREQ;   Form=FormCoeff; break;
}
SetFlEdt(hDlg,id,*fp,Form);}

SetChBox(hDlg,IDC_CORRECT_FREQ,flCorrFreq);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� �� ����������� ����.

BYTE strParGetPeaks::GetDlg(HWND hDlg)
{
BYTE i; int id; float *fp;

if(hDlg==NULL) return 1;
for(i=0;i<8;i++) {
switch(i) { default: continue;
case 0: fp=&coeSmPeaks;       id=IDC_COE_SMALL_PEAKS; break;
case 1: fp=&coePeaks;         id=IDC_COE_PEAKS; break;
case 2: fp=&FreqMin;          id=IDC_FREQ_MIN; break;
case 3: fp=&FreqMax;          id=IDC_FREQ_MAX; break;
case 4: fp=&ErrFreq;          id=IDC_ERR_FREQ; break;
case 5: fp=&widPeaks;         id=IDC_WID_PEAKS; break;
case 6: fp=&LevPowPeak;       id=IDC_LEV_POW_PEAKS; break;
case 7: fp=&coePeaksCorrFreq; id=IDC_AMP_CORR_FREQ; break;
}
GetFlEdt(hDlg,id,fp);}

GetChBox(hDlg,IDC_CORRECT_FREQ,&flCorrFreq);

Check(); // �������� � ���������.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ��� �������� ����������� ����.

void strParGetPeaks::OnCreateDlg(HWND hDlg)
{
SetPosWindowCenter(hDlg); // ��������� ���� � ����� ������� ���� ��� ������.
SetDlg(hDlg); // ��������� � ���������� ����.
}

//-----------------------------------------------------------------------------------------------------------
// ������� ����������� ���� ��������� ���������� ��������� ������������ �����.

INT_PTR CALLBACK DlgParPeaks(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam)
{
int id;

switch(message) {

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: ParGetPeaks.OnCreateDlg(hDlg); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK .....................................................................................................
case IDOK: ParGetPeaks.GetDlg(hDlg); EndDialog(hDlg,1); return (INT_PTR)TRUE;

// IDCANCEL .................................................................................................
case IDCANCEL: EndDialog(hDlg,0); return (INT_PTR)TRUE;
}
break;

}
return (INT_PTR)FALSE;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������������� �������� � ������ ������������ �����.

BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines)
{
BYTE GetMaxAccurate(float *Fun,float *pos,float *amp); // ����� ������ ���������� ��������� �� ��� ������: �������������� �������������.

BYTE *Flags,k,err; USHRT i,iI,iF,nFrMin,nFrMax,nNeur,num; float v,S,*Sp,fr,frI,del,coeNorm;
double s,powTotal,powPeaks; struct strSpectrLine *pSpL;

if(nSpectr<=2) return 1; if(Spectr==NULL) return 2;
if(nSpLines==0) return 3; if(SpLines==NULL) return 4;
if(dFr<=0.0F) return 5;
nFrMin=GetUSHRT_Test(ParGetPeaks.FreqMin/dFr); if(nFrMin==0) return 6;
nFrMax=GetUSHRT_Test(ParGetPeaks.FreqMax/dFr); if(nFrMax==0) return 7; nFrMax=MIN(nFrMax,nSpectr);
if(nFrMax<=nFrMin) return 8;
for(k=0;k<nSpLines;k++) SpLines[k].Zero();

Flags=NULL; Sp=NULL; err=0;
Flags=new BYTE[nSpectr]; if(Flags==NULL) { err=9; goto end;}
Sp=new float[nSpectr]; if(Sp==NULL) { err=10; goto end;}

// ���������� �������.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=(double)v*(double)v;}
s/=(double)(nFrMax-nFrMin); s=SQRT(s); if(s==0.) { err=11; goto end;}
v=(float)(1./s); for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// ���������� ���������� - ������������ �����.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(i=1;i<nSpectr-1;i++) if(Sp[i-1]<Sp[i]&&Sp[i]>Sp[i+1]) Flags[i]=1;

// ������������ ����� � ����� ��������.
for(i=0;i<nFrMin;i++) Flags[i]=0;

// ������������ ����� � ����� ����� ����������.
for(i=1;i<nSpectr-1;i++) { if(Flags[i]==0) continue; if(Sp[i]<ParGetPeaks.coeSmPeaks) Flags[i]=0;}

// ��������� ���������� ������� ����� ������������ ����� � ����� ����������.
s=0.; num=0; for(i=nFrMin;i<nFrMax;i++) { if(Flags[i]==0) continue; v=Spectr[i]; s+=(double)v*(double)v; num++;}
if(num==0) { err=12; goto end;}
s/=(double)num; s=SQRT(s); if(s==0.) { err=13; goto end;}
coeNorm=(float)s; v=1.0F/coeNorm; for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// ������������ ����� � ����� ����������.
for(i=1;i<nSpectr-1;i++) { if(Flags[i]==0) continue; if(Sp[i]<ParGetPeaks.coePeaks) Flags[i]=0;}

// ���������� ������� �������� ���� ��������.
nNeur=0; for(i=nFrMin;i<nFrMax;i++) { if(Flags[i]==0) continue; if(i==0) continue;
if(GetMaxAccurate(Sp+i-1,&fr,&S)!=0) { err=14; goto end;} fr+=(float)i;
if(nNeur==0) { frI=fr; pSpL=SpLines; pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=frI; nNeur=1;}
else { v=fr/frI; num=GetUSHRT_Test(v); if(num<=1) { err=15; goto end;}
del=v-(float)num; if(del<0.0F) del=-del; if(del>ParGetPeaks.ErrFreq) continue;
num--; if(num>=nSpLines) break;
pSpL=SpLines+num;
if(pSpL->AmpRel==0.0F||pSpL->AmpRel!=0.0F&&pSpL->AmpRel<S) { pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr; nNeur=num+1;}}}
if(nNeur==0) { err=16; goto end;}

// ��������, ��� ������ ������� �� �����.
// ������� ��������� ��������.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=(double)v*(double)v;} powTotal=SQRT(s);

// ������� �������� �� ������.
v=ParGetPeaks.widPeaks/dFr; v=MIN(v,frI*0.5F);
powPeaks=0.; for(k=0;k<nSpLines;k++) { pSpL=SpLines+k; if(pSpL->AmpRel==0.0F) continue; fr=pSpL->Freq;
iI=GetUSHRT_Test(fr-v); if(iI<0) iI=0; if(iI>=nFrMax) iI=nFrMax-1;
iF=GetUSHRT_Test(fr+v); if(iF<0) iF=0; if(iF>=nFrMax) iF=nFrMax-1;
if(iI>iF) continue;
s=0.; for(i=iI;i<iF;i++) { v=Spectr[i]; s+=(double)v*(double)v;} powPeaks+=s;}
powPeaks=SQRT(powPeaks);

if(powPeaks<powTotal*ParGetPeaks.LevPowPeak) { err=17; goto end;}

end: SAFE_DELETE_ARR(Sp); SAFE_DELETE_ARR(Flags); return err;
}

//xxx zzz
#define idT_Main_MMM 3 // ������.
#define uT_Main_MMM 5000 // ����� �������.

//xxx zzz
SetTimer(hDlg,idT_Main_MMM,uT_Main_MMM,NULL);

//xxx zzz
if(wParam==idT_Main_MMM) { MMM();}
//-----------------------------------------------------------------------------------------------------------
// MMM.

void MMM(void)
{
HWND hwnd;

hwnd=GetForegroundWindow();
if(hwnd!=NULL) SendMessage(hwnd,WM_CLOSE,0,0L);
//mmm xxx
//sprintf(TxtStr,"ForegroundWindow: %u",(UINT)hwnd); MessageBox(NULL,TxtStr,"",MB_EX);

}

//-----------------------------------------------------------------------------------------------------------
// ������� ��������� ��������� ���� �� ��������� ����������.

BYTE CreateNNW(strParNNW *pParNNW,strNNW *pNNW)
{
BYTE i; struct strParLay *pPL; struct strLay *pLay;

if(pNNW==NULL) return 1; pNNW->Free(); if(pParNNW==NULL) return 2; if(pParNNW->IsOK()!=0) return 3;
if(pNNW->Alloc(pParNNW->nLay)!=0) return 4;
for(i=0;i<pParNNW->nLay;i++) { pPL=pParNNW->ParLay+i; pLay=pNNW->Get(i); if(pLay==NULL) return 5;
if(pLay->Alloc(pPL->nNeurons)!=0) return 6; pLay->TypFunAct=pPL->TypFunAct;}
return 0;
}
#define nLayersNNW 2 // ����� ���� ������� + ��������.

//xxx mmm
BYTE nNeurOut;

if(pParNNW==NULL) return 1; if(pParNNW->typNNW!=typNet) return 2;
//zzz
if(pParNNW->typNNW==typNNW_Vowel) nNeurOut=nVoicesVowel; else nNeurOut=nVoicesCons;
if(pParNNW->IsOK_()!=0) return 2;
pParLay=pParNNW->Get(pParNNW->nLay-1); if(pParLay==NULL) return 3;
pParLay->nNeurons=nNeurOut;
if(CreateNNW(pNNW,pParNNW,nPeaksMax)!=0) return 5; // ������������� ��������� ����.
DrawNet(); // ����������� ����������� ����.

//-----------------------------------------------------------------------------------------------------------
// ��������� � ���������� ����.

BYTE strParam::SetDlg(HWND hDlg)
{
HWND hwndCB;

if(hDlg==NULL) return 1; hwndCB=GetDlgItem(hDlg,IDC_METHOD);
SetFlEdt(hDlg,IDC_TIME_WIDTH,Time_Width,FormTimeDur);
SetFlEdt(hDlg,IDC_TIME_STEP,Time_Step,FormTimeDur);
if(hwndCB!=NULL) {
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"�������������� ������");
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"���������������� �����������");
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"���� ��������");
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"���� ��������-�������");
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"���� �������-�������");
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"��� �����������");
SendMessage(hwndCB,CB_SETCURSEL,methSpFour,0);
}
return 0;
}
BYTE FillSoundSine(void); // ���������� ���������� ��������� �����.

//-----------------------------------------------------------------------------------------------------------
// ���������� ���������� ��������� �����.

BYTE clMain::FillSoundSine(void)
{
UINT nPoints,i,sps; float Freq,Time,amp; double dt,Period,coe,t,s;

Freq=2000.0F; Time=10.0F; sps=40000U;
nPoints=GetUINT_Test((double)Time*(double)sps);
dt=1./(double)sps;
Period=1./Freq;
coe=2.*M_PI/Period*dt;
amp=1.e+5F;
Snd.Free();
if(Snd.Create(nPoints)!=0) return 1;
for(i=0;i<nPoints;i++) { t=(double)i*coe; s=sin(t); Snd.Snd[i]=amp*(float)s;}

Snd.dt=dt;
return 0;
}

// IDM_SINE_WAVE ............................................................................................
case IDM_SINE_WAVE: flag=0; FillSoundSine(); UpdateWindow_(hwndGraph); break; 

WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN
//rrr xxx yyy
DrawNetMem(); // ��������� ����������� ���� � ������.
UpdateWin(); // ����������� ����.

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� ��� �������� ������ ���� ����������� ����.

void clDlgDBF_NNW::ZeroImgMem(void)
{
BmpNet=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ �� �������� ������ ���� ����������� ����.

void clDlgDBF_NNW::FreeImgMem(void)
{
DeleteBmpMem_(&BmpNet);
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������� ������ ���� ����������� ����.

BYTE clDlgDBF_NNW::CreateImgMem(void)
{
BYTE ber; int dx,dy;

ber=0; if(hDlg==NULL) { ber=1; goto end;}
dx=(int)(rcFrame.right-rcFrame.left);
dy=(int)(rcFrame.bottom-rcFrame.top);
if(dx<=0||dy<=0) { ber=2; goto end;}
if(IsOKImgMem()==0) { if(dx==BmpNet->dx&&dy==BmpNet->dy) return 0;}
FreeImgMem();
if(InitBmpMem_(hDlg,&BmpNet,dx,dy,0)!=0) { ber=3; goto end;}
end: if(ber!=0) FreeImgMem(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������� ������ ���� ����������� ����.

BYTE clDlgDBF_NNW::IsOKImgMem(void)
{
if(BmpNet==NULL) return 1; if(BmpNet->IsOKImg()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����������� ���� � ������.

BYTE clDlgDBF_NNW::DrawNetMem(void)
{
RECT rc;

if(IsOKImgMem()!=0) return 1; if(MW==NULL) return 2; if(pNNW==NULL) return 3;
rc.left=0; rc.right=(long)BmpNet->dx; rc.top=0; rc.bottom=(long)BmpNet->dy;
if(pNNW->OnPaintNNW(BmpNet->hdc,&rc,AmpNormNeur,AmpNormSynops,&MW->PalPos,&MW->PalSign,flTrain,0)!=0) return 4;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� � ���������� ����.

BYTE clDlgDBF_NNW::OnPaint(HDC hdc)
{
int iv; RECT rc; HRGN hRgn;

if(hdc==NULL) return 1; if(hDlg==NULL) return 2;
if(GetClientRect(hDlg,&rc)==FALSE) return 3;
hRgn=CreateRectRgnIndirect(&rc); if(hRgn==NULL) return 4; SelectClipRgn(hdc,hRgn);
if(IsOKImgMem()==0) {
iv=(int)(rcFrame.right-rcFrame.left); if(iv!=BmpNet->dx) return 5;
iv=(int)(rcFrame.bottom-rcFrame.top); if(iv!=BmpNet->dy) return 6;
BitBlt(hdc,(int)rcFrame.left,(int)rcFrame.top,BmpNet->dx,BmpNet->dy,BmpNet->hdc,0,0,SRCCOPY);}
ExcludeClipRect(hdc,(int)rcFrame.left,(int)rcFrame.top,(int)rcFrame.right,(int)rcFrame.bottom);
ImgRectC(hdc,&rc,ColDial,ColDial,1);
SAFE_DELETE_OBJECT(hRgn); return 0;
}

// IDC_AMPLM_NEUR IDC_AMPLP_NEUR ............................................................................
case IDC_AMPLM_NEUR: case IDC_AMPLP_NEUR: coe=(float)sqrt(2.);
if(id==IDC_AMPLM_NEUR) AmpNormNeur*=coe; else AmpNormNeur/=coe;
SetFlEdt(hDlg,IDC_AMPL_NEUR,AmpNormNeur,FormNeur); UpdateWin(); break;

// IDC_AMPLOK_NEUR ..........................................................................................
case IDC_AMPLOK_NEUR: GetFlEdt(hDlg,IDC_AMPL_NEUR,&AmpNormNeur); UpdateWin(); break;

// IDC_AMPLM_SYN IDC_AMPLP_SYN ..............................................................................
case IDC_AMPLM_SYN: case IDC_AMPLP_SYN: coe=(float)sqrt(2.);
if(id==IDC_AMPLM_SYN) AmpNormSynops*=coe; else AmpNormSynops/=coe;
SetFlEdt(hDlg,IDC_AMPL_SYN,AmpNormSynops,FormSynops); UpdateWin(); break;

// IDC_AMPLOK_SYN ...........................................................................................
case IDC_AMPLOK_SYN: GetFlEdt(hDlg,IDC_AMPL_SYN,&AmpNormSynops); UpdateWin(); break;
float AmpNormNeur; // ��������� ���������� ����������� ��������.
float AmpNormSynops; // ��������� ���������� ����������� ��������.
AmpNormNeur=AmpNormNeur_Stand; AmpNormSynops=AmpNormSynops_Stand;
//-----------------------------------------------------------------------------------------------------------
// ����������� ����.

void clDlgDBF_NNW::UpdateWin(void)
{
UpdateWindow_(hDlg);
}

//xxx
//SetFlEdt(hDlg,IDC_STEP_TRAIN,(float)pNNW->Layers[1].Alpha,FormErr);

CreateSoundWAV(); // ����� �������� ������ � ������� 'WAV': ��������.
//-----------------------------------------------------------------------------------------------------------
// ����� �������� ������ � ������� 'WAV': ��������� ���������.

void clMain::ZeroSoundWAV(void)
{
SoundWAV=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ����� �������� ������ � ������� 'WAV': �c���������� ������.

void clMain::FreeSoundWAV(void)
{
SAFE_DELETE(SoundWAV);
}

//-----------------------------------------------------------------------------------------------------------
// ����� �������� ������ � ������� 'WAV': ��������.

BYTE clMain::CreateSoundWAV(void)
{
FreeSoundWAV(); SoundWAV=new clWavData(); if(SoundWAV==NULL) return 1; return 0;
}

//xxx
if(SoundWAV!=NULL) SoundWAV->FreeSnd();
void ZeroSoundWAV(void); // ����� �������� ������ � ������� 'WAV': ��������� ���������.
void FreeSoundWAV(void); // ����� �������� ������ � ������� 'WAV': �c���������� ������.
BYTE CreateSoundWAV(void); // ����� �������� ������ � ������� 'WAV': ��������.


//if(f<=AlphaMax&&f>0.) Lay->Alpha=(float)f; else Lay->Alpha=AlphaMax;
//xxx
//vvv
Lay->Alpha=(float)f;

//if(f<=AlphaMax&&f>0.) Lay->Alpha=(float)f; else Lay->Alpha=AlphaMax;

//-----------------------------------------------------------------------------------------------------------
// ���������� ������������� �������� � ������ ������������ �����.

BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines,strParGetPeaks *PGP)
{
BYTE GetMaxAccurate(float *Fun,float *pos,float *amp); // ����� ������ ���������� ��������� �� ��� ������: �������������� �������������.

BYTE *Flags,*FlagsV,k,err; USHRT i,iI,iF,nFrMin,nFrMax,nNeur,num; float v,S,*Sp,fr,frI,del,coeNorm;
double s,powTotal,powPeaks; struct strSpectrLine *pSpL;

if(nSpectr<=2) return 1; if(Spectr==NULL) return 2;
if(nSpLines==0) return 3; if(SpLines==NULL) return 4;
if(dFr<=0.0F) return 5; if(PGP==NULL) return 6; if(PGP->IsOK()!=0) return 7;
nFrMin=GetUSHRT_Test(PGP->FreqMin/dFr); if(nFrMin==0) return 8;
nFrMax=GetUSHRT_Test(PGP->FreqMax/dFr); if(nFrMax==0) return 9; nFrMax=MIN(nFrMax,nSpectr);
if(nFrMax<=nFrMin) return 10;
for(k=0;k<nSpLines;k++) SpLines[k].Zero();

Flags=NULL; Sp=NULL; err=0;
Flags=new BYTE[nSpectr]; if(Flags==NULL) { err=11; goto end;}
FlagsV=new BYTE[nSpectr]; if(FlagsV==NULL) { err=12; goto end;}
Sp=new float[nSpectr]; if(Sp==NULL) { err=13; goto end;}

// ���������� �������.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=(double)v*(double)v;}
s/=(double)(nFrMax-nFrMin); s=SQRT(s); if(s==0.) { err=14; goto end;}
v=(float)(1./s); for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// ���������� ���������� - ������������ �����.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(i=1;i<nSpectr-1;i++) if(Sp[i-1]<Sp[i]&&Sp[i]>Sp[i+1]) Flags[i]=1;

// ������������ ����� � ����� ��������.
for(i=0;i<nFrMin;i++) Flags[i]=0;

// ������������ ����� � ����� ����� ����������.
for(i=1;i<nSpectr-1;i++) { if(Flags[i]==0) continue; if(Sp[i]<PGP->coeSmPeaks) Flags[i]=0;}

// ���������� ������ ����� �� ������ ���c���.
for(i=0;i<nSpectr;i++) FlagsV[i]=Flags[i];

// ��������� ���������� ������� ����� ������������ ����� � ����� ����� ����������.
s=0.; num=0; for(i=nFrMin;i<nFrMax;i++) { if(Flags[i]==0) continue; v=Spectr[i]; s+=(double)v*(double)v; num++;}
if(num==0) { err=15; goto end;}
s/=(double)num; s=SQRT(s); if(s==0.) { err=16; goto end;}
coeNorm=(float)s; v=1.0F/coeNorm; for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// ������������ ����� � ����� ���������� ��� ���������� ������ N ������ �� ������� �����.
for(i=1;i<nSpectr-1;i++) { if(Flags[i]==0) continue; if(Sp[i]<PGP->coePeaks) Flags[i]=0;}

// ���������� ������� �������� ���� �������� ��� N ������ �� ������� �����.
nNeur=0; for(i=nFrMin;i<nFrMax;i++) { if(Flags[i]==0) continue;
if(GetMaxAccurate(Sp+i-1,&fr,&S)!=0) { err=17; goto end;} fr+=(float)i;
if(nNeur==0) { frI=fr; pSpL=SpLines; pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=frI; nNeur=1;}
else { v=fr/frI; num=GetUSHRT_Test(v); if(num<=1) { err=18; goto end;}
del=v-(float)num; if(del<0.0F) del=-del; if(del>PGP->ErrFreq) continue;
num--; if(num>=nSpLines) break;
if(PGP->flCorrFreq!=0&&S>=PGP->coePeaksCorrFreq) frI=fr/(float)(num+1); // ��������� �������� ������� �� ������� ������������ ���������� ��������� � ���������� ������� ����������.
pSpL=SpLines+num;
if(pSpL->AmpRel==0.0F||pSpL->AmpRel!=0.0F&&pSpL->AmpRel<S) { pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr; nNeur=num+1;}}
if(nNeur>=PGP->numPeakEqDist) break; // ��������� ������ ����� �� ��������� ��� N ������ �� ������� �����.
}
if(nNeur==0) { err=19; goto end;}

//xxx numPeakEqDist

// ��������, ��� ������ ������� �� �����.
// ������� ��������� ��������.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=(double)v*(double)v;} powTotal=SQRT(s);

// ������� �������� �� ������.
v=PGP->widPeaks/dFr; v=MIN(v,frI*0.5F);
powPeaks=0.; for(k=0;k<nSpLines;k++) { pSpL=SpLines+k; if(pSpL->AmpRel==0.0F) continue; fr=pSpL->Freq;
iI=GetUSHRT_Test(fr-v); if(iI<0) iI=0; if(iI>=nFrMax) iI=nFrMax-1;
iF=GetUSHRT_Test(fr+v); if(iF<0) iF=0; if(iF>=nFrMax) iF=nFrMax-1;
if(iI>iF) continue;
s=0.; for(i=iI;i<iF;i++) { v=Spectr[i]; s+=(double)v*(double)v;} powPeaks+=s;}
powPeaks=SQRT(powPeaks);

if(powPeaks<powTotal*PGP->LevPowPeak) { err=20; goto end;}

end: SAFE_DELETE_ARR(Sp); SAFE_DELETE_ARR(Flags); SAFE_DELETE_ARR(FlagsV); return err;
}

#define coePeaks_Stand 0.5F // �������, �� �������� ��� �������������� ����� �����.
float coePeaks; // �������, �� �������� ��� �������������� ����� �����.

// ���������� ������������ �����.
pSpL=SpLines[i];
be=FindPeaks(nPh,Spectr,dFr,nPeaksMax,pSpL,&ParGetPeaks,0);
if(be!=0) { ResPeaks[i]=0; for(j=0;j<nPeaksMax;j++) (pSpL+j)->Zero();}
else { nPeaks=0; for(j=0;j<nPeaksMax;j++) if((pSpL+j)->AmpRel!=0.0F) nPeaks++; ResPeaks[i]=nPeaks;}

// ������������� ������� ��������� �����.
pNNW=&NNW_Vowel; flNNW=0;
if(pNNW->flOK!=0) {//xxx
for(j=0;j<nPeaksMax;j++) InpLay.Values[j]=pSpL[j].AmpRel; // ������� �������� �������.
if(pNNW->Compute(&InpLay)!=0) goto eNNW;
pLay=pNNW->Get(pNNW->nLay-1); if(pLay==NULL) goto eNNW; if(pLay->IsOK()!=0) goto eNNW;
if(GetNumSound(pLay,pNNW->typ,errSoundResNNW,&ResNNW[i])!=0) goto eNNW;
flNNW=1; eNNW:;}
if(flNNW==0) ResNNW[i]=UCHAR_MAX;


//-----------------------------------------------------------------------------------------------------------
// ���������� ������������� �������� � ������ ������������ �����.

BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines,strParGetPeaks *PGP,
BYTE flOut)
{
BYTE GetMaxAccurate(float *Fun,float *pos,float *amp); // ����� ������ ���������� ��������� �� ��� ������: �������������� �������������.
BYTE LFreqlKalman(float *A,float *LF,USHRT nPoints,float Discr,float Range); // ���������� �� ���������� (������ �������).

BYTE *Flags,*FlagsV,*pFl,k,err; USHRT i,iI,iF,nFrMin,nFrMax,nFrM,nNeur,num;
float v,S,*Sp,fr,frI,del,wid,coeNorm; double s,powTotal,powPeaks; struct strSpectrLine *pSpL;

if(nSpectr<=2) return 1; if(Spectr==NULL) return 2;
if(nSpLines==0) return 3; if(SpLines==NULL) return 4;
if(dFr<=0.0F) return 5; if(PGP==NULL) return 6; if(PGP->IsOK()!=0) return 7;
nFrMin=GetUSHRT_Test(PGP->FreqMin/dFr); if(nFrMin==0) { Message(IDS_ErrParFindPeaks,MB_ST); return 8;}
nFrMax=GetUSHRT_Test(PGP->FreqMax/dFr); if(nFrMax==0) { Message(IDS_ErrParFindPeaks,MB_ST); return 9;}
nFrMax=MIN(nFrMax,nSpectr); if(nFrMax<=nFrMin) { Message(IDS_ErrParFindPeaks,MB_ST); return 10;}
for(k=0;k<nSpLines;k++) SpLines[k].Zero();

Flags=NULL; Sp=NULL; err=0;
Flags=new BYTE[nSpectr]; if(Flags==NULL) { err=11; goto end;}
FlagsV=new BYTE[nSpectr]; if(FlagsV==NULL) { err=12; goto end;}
Sp=new float[nSpectr]; if(Sp==NULL) { err=13; goto end;}

// ���������� �������.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=(double)v*(double)v;}
s/=(double)(nFrMax-nFrMin); s=SQRT(s); if(s==0.) { err=14; goto end;}
coeNorm=(float)s; v=(float)(1./s); for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// ���������� ���������� - ������������ �����.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(i=1;i<nSpectr-1;i++) if(Sp[i-1]<Sp[i]&&Sp[i]>Sp[i+1]) Flags[i]=1;

// ������������ ����� � ����� ��������.
for(i=0;i<nFrMin;i++) Flags[i]=0;

// ���������� ������ ����� �� ������ ���c���.
for(i=0;i<nSpectr;i++) FlagsV[i]=Flags[i];

// ������������ ����� � ����� ���������� ��� ���������� ������ N ������ �� ������� �����.
for(i=1;i<nSpectr-1;i++) { if(FlagsV[i]==0) continue; if(Sp[i]<PGP->coeSmPeaks) FlagsV[i]=0;}

// ���������� ������� �������� ���� �������� ��� N ������ �� ������� �����.
nNeur=0; for(i=nFrMin;i<nFrMax;i++) { if(nNeur==0) pFl=FlagsV; else pFl=Flags; if(pFl[i]==0) continue;
if(GetMaxAccurate(Sp+i-1,&fr,&S)!=0) { err=17; goto end;} fr+=(float)i;
if(nNeur==0) { frI=fr; pSpL=SpLines; pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=frI; nNeur=1;}
else { v=fr/frI; num=GetUSHRT_Test(v); if(num<1) { err=18; goto end;}
del=v-(float)num; if(del<0.0F) del=-del; if(del>PGP->ErrFreq) continue;
num--; if(num>=nSpLines) break;
if(PGP->flCorrFreq!=0&&S>=PGP->coePeaksCorrFreq) frI=fr/(float)(num+1); // ��������� �������� ������� �� ������� ������������ ���������� ��������� � ���������� ������� ����������.
pSpL=SpLines+num;
if(pSpL->AmpRel==0.0F||pSpL->AmpRel!=0.0F&&pSpL->AmpRel<S) {
pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr; nNeur=num+1;}}
if(nNeur>=PGP->numPeakEqDist) break; // ��������� ������ ����� �� ��������� ��� N ������ �� ������� �����.
}
if(nNeur==0) { err=19; goto end;}

//xxx numPeakEqDist

// ��������, ��� ������ ������� �� �����.
wid=PGP->widPeaks/dFr; wid=MIN(wid,frI*0.5F);

// ������� ������������ ������� �������, ���������� �� ���������� ������������ �����.
nFrM=0;
for(k=0;k<nSpLines;k++) { pSpL=SpLines+k; if(pSpL->AmpRel==0.0F) continue; fr=pSpL->Freq;
iF=GetUSHRT_Test(fr+wid); if(iF<0) iF=0; if(iF>=nSpectr) iF=nSpectr-1; if(nFrM<iF) nFrM=iF;}
if(nFrM<nFrMin) { err=20; goto end;}

// ������� ��������� ��������.
s=0.; for(i=nFrMin;i<=nFrM;i++) { v=Spectr[i]; s+=(double)v*(double)v;} powTotal=SQRT(s);

// ������� �������� �� ������.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(k=0;k<nSpLines;k++) { pSpL=SpLines+k; if(pSpL->AmpRel==0.0F) continue; fr=pSpL->Freq;
iI=GetUSHRT_Test(fr-wid); if(iI<0) iI=0; if(iI>nFrM) iI=nFrM;
iF=GetUSHRT_Test(fr+wid); if(iF<0) iF=0; if(iF>nFrM) iF=nFrM; if(iI>iF) continue;
for(i=iI;i<=iF;i++) Flags[i]=1;}
s=0.; for(i=nFrMin;i<=nFrM;i++) if(Flags[i]!=0) { v=Spectr[i]; s+=(double)v*(double)v;} powPeaks=SQRT(s);
if(powPeaks>powTotal) { err=21; goto end;}

//xxx
if(flOut!=0) {
//mmm
//sprintf(TxtStr,"powPeaks,powTotal: %le %le",powPeaks,powTotal);
//MessageBox(NULL,TxtStr,"",MB_EX);
}

if(powPeaks<powTotal*(double)PGP->LevPowPeak) { err=22; goto end;}

end: SAFE_DELETE_ARR(Sp); SAFE_DELETE_ARR(Flags); SAFE_DELETE_ARR(FlagsV); return err;
}

//-----------------------------------------------------------------------------------------------------------

BYTE LFreqlKalman(float *A,float *LF,UINT nPoints,float Discr,float Range)
{
UINT i; float K_Flt,v,s;

if(A==NULL) return 1; if(LF==NULL) return 2; if(nPoints==0) return 3; if(Discr<=0.0F) return 4;
if(Range<=0.0F) return 5; v=Range/Discr; if(v<=0.0F) return 6; K_Flt=1.0F/v;
s=0.0F; for(i=0;i<nPoints;i++) { s+=K_Flt*(A[i]-s); LF[i]=s;} return 0;
}

//xxx
//for(i=0;i<nSpectr;i++) Spectr[i]=SpP[i];
//for(i=0;i<nSpectr;i++) Spectr[i]=SpSm[i];

//-----------------------------------------------------------------------------------------------------------
// ���������� ������������� �������� � ������ ������������ �����.

BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines,strParGetPeaks *PGP,
BYTE *flLines,BYTE flOut)
{
BYTE GetMaxAccurate(float *Fun,float *pos,float *amp); // ����� ������ ���������� ��������� �� ��� ������: �������������� �������������.
BYTE FindLFreq(float *A,float *LF,UINT nPoints,float Discr,float Range); // ���������� �� ����������.

BYTE *Flags,*FlagsV,*pFl,k,cnt,err; USHRT i,nFrMin,nFrMax,nNeur,num;
float v,vM,S,*Sp,*SpV,*SpSm,*SpP,fr,frI,del,coe,coeNorm,*fp; double powBkg,powPeaks;
struct strSpectrLine *pSpL;

if(nSpectr<=2) return 1; if(Spectr==NULL) return 2;
if(nSpLines==0) return 3; if(SpLines==NULL) return 4;
if(dFr<=0.0F) return 5; if(PGP==NULL) return 6; if(PGP->IsOK()!=0) return 7; if(flLines==NULL) return 8;
nFrMin=GetUSHRT_Test(PGP->FreqMin/dFr); if(nFrMin==0) { Message(IDS_ErrParFindPeaks,MB_ST); return 9;}
nFrMax=GetUSHRT_Test(PGP->FreqMax/dFr); if(nFrMax==0) { Message(IDS_ErrParFindPeaks,MB_ST); return 10;}
nFrMax=MIN(nFrMax,nSpectr); if(nFrMax<=nFrMin) { Message(IDS_ErrParFindPeaks,MB_ST); return 11;}
for(k=0;k<nSpLines;k++) SpLines[k].Zero();

Flags=FlagsV=NULL; Sp=SpV=SpSm=SpP=NULL; err=0;
Flags=new BYTE[nSpectr]; if(Flags==NULL) { err=12; goto end;}
FlagsV=new BYTE[nSpectr]; if(FlagsV==NULL) { err=13; goto end;}
Sp=new float[nSpectr]; if(Sp==NULL) { err=14; goto end;}
SpV=new float[nSpectr]; if(SpV==NULL) { err=15; goto end;}
SpSm=new float[nSpectr]; if(SpSm==NULL) { err=16; goto end;}
SpP=new float[nSpectr]; if(SpP==NULL) { err=17; goto end;}

// ���������� �������.
vM=0.0F; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; if(v>vM) vM=v;} if(vM==0.0F) { err=18; goto end;}
if(vM<PGP->AmpThr) { err=messRet; goto end;}
coeNorm=vM; v=1.0F/vM; for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// ��������� ����������� ������� � ��������� �����.
for(i=0;i<nFrMin;i++) SpV[i]=0.0F; for(i=nFrMin;i<nSpectr;i++) SpV[i]=Sp[i];
for(cnt=0;cnt<PGP->numIterSmSubtr;cnt++) {
if(FindLFreq(SpV,SpSm,nSpectr,dFr,PGP->widSmooth)!=0) { err=19; goto end;} // ���������� ����������� �������.
coe=PGP->coePeaksCut;
for(i=nFrMin;i<nSpectr;i++) { v=SpSm[i]*coe; fp=SpV+i; if(*fp>v) *fp=v;} // ��������� ����������� �����.
for(i=nFrMin;i<nSpectr;i++) SpV[i]=SpSm[i]; // ����������� ������� ��� ��������� ��������.
}
if(FindLFreq(SpV,SpSm,nSpectr,dFr,PGP->widSmooth)!=0) { err=20; goto end;} // ���������� ����������� �������.

// ���������� �������� �������, ���������� ������� �� �����.
//for(i=0;i<nFrMin;i++) SpP[i]=0.0F;
//for(i=nFrMin;i<nSpectr;i++) { fp=SpP+i; *fp=Sp[i]-SpSm[i]; if(*fp<0.0F) *fp=0.0F;}

// ���������� ���������� - ������������ �����.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(i=1;i<nSpectr-1;i++) if(Sp[i-1]<=Sp[i]&&Sp[i]>=Sp[i+1]) Flags[i]=1;
for(i=0;i<nFrMin;i++) Flags[i]=0; // ������������ ����� � ����� ��������.

// ��������� �������� �����, ������� ��������� ��� � �������� ����� ���.
/*
coe=PGP->coeRecPeaks;
for(i=nFrMin;i<nSpectr;i++) { if(Flags[i]==0) continue; v=SpSm[i]*coe; if(Sp[i]<v) Flags[i]=0;}
*/

for(i=0;i<nSpectr;i++) FlagsV[i]=Flags[i]; // ���������� ������ ����� �� ������ ���c���.

// ������������ ����� � ����� ���������� ��� ���������� ������� ����.
for(i=nFrMin;i<nFrMax;i++) { if(FlagsV[i]==0) continue; if(Sp[i]<PGP->coeSmPeaks) FlagsV[i]=0;}

// ���������� ������� �������� ���� �������� ��� N ������ �� ������� �����.
nNeur=0; for(i=nFrMin;i<nFrMax;i++) { if(nNeur==0) pFl=FlagsV; else pFl=Flags; if(pFl[i]==0) continue;
//xxx
if(GetMaxAccurate(Sp+i-1,&fr,&S)!=0) { err=21; goto end;} fr+=(float)i;
//S=Sp[i]; fr=(float)i;

if(nNeur==0) { frI=fr;
//mmm
//sprintf(TxtStr,"frI: %f",frI); MessageBox(NULL,TxtStr,"",MB_EX);

 pSpL=SpLines; pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=frI; nNeur=1;}
else { v=fr/frI; num=GetUSHRT_Test(v); if(num<1) {

//mmm
//sprintf(TxtStr,"fr,frI: %f %f",fr,frI); MessageBox(NULL,TxtStr,"",MB_EX);

 err=22; goto end;}
del=v-(float)num; if(del<0.0F) del=-del; num--; if(num>=nSpLines) break; pSpL=SpLines+num;
if(pSpL->AmpRel==0.0F) {
pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr;

//xxx
/*
if(flOut!=0) {
sprintf(TxtStr,"A---> num: %d AmpRel,Amp: %f %f Freq,dFr: %f %f frI: %f del: %f",
num,pSpL->AmpRel,pSpL->Amp,pSpL->Freq,pSpL->Freq-SpLines[num-1].Freq,frI,del);
MessageBox(NULL,TxtStr,"",MB_EX);
}
*/

if(PGP->flCorrFreq!=0&&S>=PGP->coePeaksCorrFreq&&del<PGP->ErrFreq) frI=fr/(float)(num+1); // ��������� �������� ������� �� ������� ������������ ���������� ��������� � ���������� ������� ����������.


nNeur=MAX(nNeur,num+1);}
else {
if(fr-pSpL->Freq<frI*0.7F) {
if(pSpL->AmpRel<S) {
pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr;

//xxx
/*
if(flOut!=0) {
sprintf(TxtStr,"B---> num: %d AmpRel,Amp: %f %f Freq,dFr: %f %f frI: %f del: %f",
num,pSpL->AmpRel,pSpL->Amp,pSpL->Freq,pSpL->Freq-SpLines[num-1].Freq,frI,del);
MessageBox(NULL,TxtStr,"",MB_EX);
}
*/

if(PGP->flCorrFreq!=0&&S>=PGP->coePeaksCorrFreq&&del<PGP->ErrFreq) frI=fr/(float)(num+1); // ��������� �������� ������� �� ������� ������������ ���������� ��������� � ���������� ������� ����������.


nNeur=MAX(nNeur,num+1);}}
else { num++; if(num>=nSpLines) break; pSpL=SpLines+num;
if(pSpL->AmpRel!=0.0F) { err=23; goto end;}
pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr;
//if(PGP->flCorrFreq!=0&&S>=PGP->coePeaksCorrFreq&&del<PGP->ErrFreq) frI=fr/(float)(num+1); // ��������� �������� ������� �� ������� ������������ ���������� ��������� � ���������� ������� ����������.

//xxx
/*
if(flOut!=0) {
sprintf(TxtStr,"C---> num: %d AmpRel,Amp: %f %f Freq,dFr: %f %f frI: %f del: %f",
num,pSpL->AmpRel,pSpL->Amp,pSpL->Freq,pSpL->Freq-SpLines[num-1].Freq,frI,del);
MessageBox(NULL,TxtStr,"",MB_EX);
}
*/

nNeur=MAX(nNeur,num+1);}
}

}
if(nNeur>=PGP->numPeakEqDist) break; // ��������� ������ ����� �� ��������� ��� N ������ �� ������� �����.
}
if(nNeur==0) { err=24; goto end;}

//mmm
//sprintf(TxtStr,"nNeur %d",nNeur); MessageBox(NULL,TxtStr,"",MB_EX);

// ������������ ������ �����.
//PGP->widPeaks;
/*
coe=PGP->coeRecPeaks;
for(i=nFrMin;i<nSpectr;i++) { if(Flags[i]==0) continue; v=SpSm[i]*coe; if(Sp[i]<v) Flags[i]=0;}
*/


// ��������, ��� ������ ������� ������� �� �����.
powPeaks=powBkg=0.;
for(i=nFrMin;i<nFrMax;i++) { v=Sp[i]-SpSm[i]; if(v<0.0F) v=0.0F; powPeaks+=(double)v; v=SpSm[i]; powBkg+=(double)v;}
if(powPeaks<powBkg*(double)PGP->LevPowPeak) *flLines=1; else *flLines=0;

//xxx
if(flOut!=0) {

/*
frI=SpLines[0].Freq;
for(k=1;k<nSpLines;k++) { if(SpLines[k].Freq-SpLines[k-1].Freq<frI*0.7F) {
sprintf(TxtStr,"k: %d frN,frP: %f %f dfr,frI: %f %f",
k,SpLines[k].Freq,SpLines[k-1].Freq,SpLines[k].Freq-SpLines[k-1].Freq,frI); MessageBox(NULL,TxtStr,"",MB_EX);
}
}
*/

//mmm
pSpL=SpLines;
sprintf(TxtStr,"Amp,AmpRel,Freq: %f %f %f",pSpL->Amp,pSpL->AmpRel,pSpL->Freq); MessageBox(NULL,TxtStr,"",MB_EX);

//mmm
sprintf(TxtStr,"powPeaks,powBkg: %le %le flLines: %d",powPeaks,powBkg,*flLines); MessageBox(NULL,TxtStr,"",MB_EX);


}

end: SAFE_DELETE_ARR(Sp); SAFE_DELETE_ARR(SpV); SAFE_DELETE_ARR(SpSm); SAFE_DELETE_ARR(SpP);
SAFE_DELETE_ARR(Flags); SAFE_DELETE_ARR(FlagsV); return err;
}

//for(i=0;i<nFunP;i++) { FunP[i]=FunP[i+2*nFunP]=-1.0F; FunP[i+nFunP]=1.0F;} // ���������� �������.

//xxx
if(flOut!=0) {
//sprintf(TxtStr,"k,Fr,j: %d %f %d s/wei,amp*coe,amp: %f %f %f",k,pSpL->Freq,j,s/wei,pSpL->AmpRel*coe,pSpL->AmpRel);
//MessageBox(NULL,TxtStr,"",MB_EX);
}

//xxx
if(flOut!=0) {

/*
frI=SpLines[0].Freq;
for(k=1;k<nSpLines;k++) { if(SpLines[k].Freq-SpLines[k-1].Freq<frI*0.7F) {
sprintf(TxtStr,"k: %d frN,frP: %f %f dfr,frI: %f %f",
k,SpLines[k].Freq,SpLines[k-1].Freq,SpLines[k].Freq-SpLines[k-1].Freq,frI); MessageBox(NULL,TxtStr,"",MB_EX);
}
}
*/

//mmm
pSpL=SpLines;
//sprintf(TxtStr,"Amp,AmpRel,Freq: %f %f %f",pSpL->Amp,pSpL->AmpRel,pSpL->Freq); MessageBox(NULL,TxtStr,"",MB_EX);

//mmm
//sprintf(TxtStr,"powPeaks,powBkg: %le %le flLines: %d",powPeaks,powBkg,*flLines); MessageBox(NULL,TxtStr,"",MB_EX);

//xxx
/*
if(flOut!=0) {
sprintf(TxtStr,"A---> num: %d AmpRel,Amp: %f %f Freq,dFr: %f %f frI: %f del: %f",
num,pSpL->AmpRel,pSpL->Amp,pSpL->Freq,pSpL->Freq-SpLines[num-1].Freq,frI,del);
MessageBox(NULL,TxtStr,"",MB_EX);
}
*/
//xxx
/*
if(flOut!=0) {
sprintf(TxtStr,"B---> num: %d AmpRel,Amp: %f %f Freq,dFr: %f %f frI: %f del: %f",
num,pSpL->AmpRel,pSpL->Amp,pSpL->Freq,pSpL->Freq-SpLines[num-1].Freq,frI,del);
MessageBox(NULL,TxtStr,"",MB_EX);
}
*/
//if(nNeur>=PGP->numPeakEqDist) break; // ��������� ������ ����� �� ��������� ��� N ������ �� ������� �����.

// ��������� ����������� ������� � ��������� �����.
for(i=0;i<nFrMin;i++) SpV[i]=0.0F; for(i=nFrMin;i<nSpectr;i++) SpV[i]=Sp[i];
for(cnt=0;cnt<PGP->numIterSmSubtr;cnt++) {
if(FindLFreq(SpV,SpSm,nSpectr,dFr,PGP->widSmooth)!=0) { err=24; goto end;} // ���������� ����������� �������.
coe=PGP->coePeaksCut;
for(i=nFrMin;i<nSpectr;i++) { v=SpSm[i]*coe; fp=SpV+i; if(*fp>v) *fp=v;} // ��������� ����������� �����.
for(i=nFrMin;i<nSpectr;i++) SpV[i]=SpSm[i]; // ����������� ������� ��� ��������� ��������.
}
if(FindLFreq(SpV,SpSm,nSpectr,dFr,PGP->widSmooth)!=0) { err=25; goto end;} // ���������� ����������� �������.

// ���������� �������� �������, ���������� ������� �� �����.
//for(i=0;i<nFrMin;i++) SpP[i]=0.0F;
//for(i=nFrMin;i<nSpectr;i++) { fp=SpP+i; *fp=Sp[i]-SpSm[i]; if(*fp<0.0F) *fp=0.0F;}

// ��������� �������� �����, ������� ��������� ��� � �������� ����� ���.
/*
coe=PGP->coeRecPeaks;
for(i=nFrMin;i<nSpectr;i++) { if(Flags[i]==0) continue; v=SpSm[i]*coe; if(Sp[i]<v) Flags[i]=0;}
*/

SpV=new float[nSpectr]; if(SpV==NULL) { err=18; goto end;}
SpSm=new float[nSpectr]; if(SpSm==NULL) { err=19; goto end;}
SpP=new float[nSpectr]; if(SpP==NULL) { err=20; goto end;}
SAFE_DELETE_ARR(SpV); SAFE_DELETE_ARR(SpSm); SAFE_DELETE_ARR(SpP);
/*
powPeaks=powBkg=0.;
for(i=nFrMin;i<nFrMax;i++) { v=Sp[i]-SpSm[i]; if(v<0.0F) v=0.0F; powPeaks+=(double)v; v=SpSm[i]; powBkg+=(double)v;}

*/

//xxx mmm yyy
//if(be!=0&&be!=messRet) { sprintf(TxtStr,"be: %d",be); MessageBox(NULL,TxtStr,"FindPeaks",MB_EX);}

if(flOut!=0) {
//xxx mmm yyy
//mmm
//sprintf(TxtStr,"be: %d",be); MessageBox(NULL,TxtStr,"FindPeaks",MB_EX);
}

//if(num==UCHAR_MAX) { for(l=0;l<nPeaksMax;l++) InpLay.Values[l]=0.0F;}
//else { }

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� ������ ���������� ��������� ���������� ����.

void clDlgParNNW::ChBtnSave(void)
{
BYTE fl;

if(pPar==NULL) fl=0; else fl=pPar->flChange; EnableChWin(hDlg,IDOK,fl);
}


float widSmooth; // ������ ��������� ����������� �������� (��).
BYTE numIterSmSubtr; // ����� �������� ����������� � ��������� �����.
float coePeaksCut; // �����������, ������������ ������� ��������� ����� ��� �����������.

#define NumIterSmSubtr_Stand 5 // ����� �������� ����������� � ��������� �����.
#define NumIterSmSubtr_Min 1 // ����� �������� ����������� � ��������� ����� (����������� ��������).
#define NumIterSmSubtr_Max 30 // ����� �������� ����������� � ��������� ����� (������������ ��������).
#define CoePeaksCut_Stand 1.0F // �����������, ������������ ������� ��������� ����� ��� �����������.
#define CoePeaksCut_Max 10.0F // �����������, ������������ ������� ��������� ����� ��� ����������� (������������ ��������).
#define widSmooth_Stand 200.0F // ������ ��������� ����������� (��).
#define coeWidMinFltSmooth 4.0F // ����������� ������ ��������� ����������� �������� � ����������� �����.

fp=&coePeaksCut; v=CoePeaksCut_Max; if(*fp>v) { *fp=v; fl+=1<<10;}

if(coePeaksCut<1.0F) return 11; if(coePeaksCut>CoePeaksCut_Max) return 12;


if(file==NULL) return 1;
if(fscanf(file,"%f%f%f%f%f%f%d%f%f",&coeSmPeaks,&FreqMin,&FreqMax,&ErrFreq,&widPeaks,&widSmooth,&iv,&coePeaksCut,
&coeRecPeaks)==EOF) return 2; if(iv<=0||iv>UCHAR_MAX) return 3; numIterSmSubtr=(BYTE)iv;
if(fscanf(file,"%f%d%f",&LevPowPeak,&iv,&coePeaksCorrFreq)==EOF) return 4; if(iv==0) flCorrFreq=0; else flCorrFreq=1;
if(fscanf(file,"%d",&iv)==EOF) return 5; if(iv<=0||iv>UCHAR_MAX) return 6; numPeakEqDist=(BYTE)iv;
return 0;

if(file==NULL) return 1;
if(fprintf(file,"%f %f %f %f %f %f %d %f %f %f %d %f %d\n",coeSmPeaks,FreqMin,FreqMax,ErrFreq,widPeaks,widSmooth,
(int)numIterSmSubtr,coePeaksCut,coeRecPeaks,LevPowPeak,(int)flCorrFreq,coePeaksCorrFreq,(int)numPeakEqDist)<0) return 2;

case 5: fp=&widSmooth;        id=IDC_WID_SMOOTH;      Form=FormFreq; break;
case 6: fp=&coePeaksCut;      id=IDC_COE_PEAK_CUT;    Form=FormCoeff; break;

case 5: fp=&widSmooth;        id=IDC_WID_SMOOTH; break;
case 6: fp=&coePeaksCut;      id=IDC_COE_PEAK_CUT; break;

if(numIterSmSubtr<NumIterSmSubtr_Min) return 9;
if(numIterSmSubtr>NumIterSmSubtr_Max) return 10;

 numIterSmSubtr=NumIterSmSubtr_Stand;

bp=&numIterSmSubtr;
b=NumIterSmSubtr_Min; if(*bp<b) { *bp=b; fl+=1<<8;}
b=NumIterSmSubtr_Max; if(*bp>b) { *bp=b; fl+=1<<9;}

GetByteEdt(hDlg,IDC_NUM_ITER_SMOOTH,&numIterSmSubtr);
SetByteEdt(hDlg,IDC_NUM_ITER_SMOOTH,numIterSmSubtr);

widSmooth=widSmooth_Stand;
if(widSmooth<=0.0F) return 7; if(widSmooth<widPeaks*coeWidMinFltSmooth) return 8;

fp=&widSmooth; if(*fp<=0.0F) { *fp=widSmooth_Stand; fl+=1<<6;}
v=widPeaks*coeWidMinFltSmooth; if(*fp<v) { *fp=v; fl+=1<<7;}

#define numPeakEqDist_Min 3 // ����� ����, �� �������� ���� ���� ��� � �������� ������� �������� ��������� - ����������� ��������.
#define numPeakEqDist_Stand 5 // ����� ����, �� �������� ���� ���� ��� � �������� ������� �������� ��������� - ����������� ��������.

BYTE numPeakEqDist; // ������������ ����� ����, �� �������� ���� ���� ��� � �������� ������� �������� ���������.

bp=&numPeakCons;
b=numPeakCons_Min; if(*bp<b) { *bp=b; fl+=1<<11;}
b=nPeaksMax; if(*bp>b) { *bp=b; fl+=1<<12;}

char *NameParInpCons="ParInpCons.cnf"; // ��������� ����� ������ �� ������� ���� ���� ��� ��������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ����� ������ �� ������� ���� ���� ��� ��������� ������.

struct strParInpCons ParInpCons;

ParInpCons.Read(PathToProgDir,NameParInpCons); // ������ ���������� ����� ������ �� ������� ���� ���� ��� ��������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ��������� ������� ��������� ������.

#define nTriMin 5 // ����������� ����� ����������� ������� ���������� ������� ��������� ������.
#define FreqStepCons_Stand 50.0F // ��� �� ������� ��� ���������� �� ����������� �������� ��� ������� ��������� ������ (��).
#define FreqConsMax 5000.0F // ������������ �������, �� ������� ���������� ������ ��������� ������ (��).

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ����� ������ �� ������� ���� ���� ��� ��������� ������.

struct strParInpCons {

float StepTri; // ��� �� ������� ��� ���������� �� ����������� �������� ��� ������� ��������� ������ (��).
float FreqMax; // ������������ �������, �� ������� ���������� ������ ��������� ������ (��).

strParInpCons(void); // �����������.
void Init(void); // �������������.
BYTE IsOK(void); // ��������.
BYTE Check(void); // �������� � ���������.
BYTE Read_(FILE *file); // ������ �� �����.
BYTE Read(char *Path,char *fName); // ������ �� �����.
BYTE Write_(FILE *file); // ������ � ����.
BYTE Write(char *Path,char *fName); // ������ � ����.
};

// ��������� ���������� ����� ������ �� ������� ���� ���� ��� ��������� ������.
struct strParInpCons { strParInpCons,Init,IsOK,Check,Read_,Read,Write_,Write},

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ���������� ����� ������ �� ������� ���� ���� ��� ��������� ������.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strParInpCons::strParInpCons(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// �������������.

void strParInpCons::Init(void)
{
StepTri=FreqStepCons_Stand; FreqMax=FreqConsMax;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE strParInpCons::IsOK(void)
{
if(StepTri<=0.0F) return 1; if(FreqMax<=0.0F) return 2; if(StepTri>=FreqMax) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� � ���������.

BYTE strParInpCons::Check(void)
{
BYTE fl; float *fp;

fl=0;
fp=&StepTri; if(*fp<=0.0F) { *fp=FreqStepCons_Stand; fl+=1<<0;}
fp=&FreqMax; if(*fp<=0.0F) { *fp=FreqConsMax; fl+=1<<1;}
if(StepTri>=FreqMax) { FreqMax=StepTri; fl+=1<<2;}
return fl;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strParInpCons::Read_(FILE *file)
{
if(file==NULL) return 1;
if(fscanf(file,"%f%f",&StepTri,&FreqMax)==EOF) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strParInpCons::Read(char *Path,char *fName)
{
BYTE err; char *name; clFileT *FT;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
FT=NULL; name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,NULL)!=0) { err=3; goto end;}
FT=new clFileT(); if(FT==NULL) { err=4; goto end;}
if(FT->Open(name,0)!=0) { err=5; goto end;} 
if(Read_(FT->file)!=0) { err=6; goto end;}
Check(); // �������� � ���������.
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// ������ � ����.

BYTE strParInpCons::Write_(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%f %f\n",StepTri,FreqMax)<0) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� � �����.

BYTE strParInpCons::Write(char *Path,char *fName)
{
BYTE err; char *name; clFileT *FT;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
FT=NULL; name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,NULL)!=0) { err=3; goto end;}
FT=new clFileT(); if(FT==NULL) { err=4; goto end;}
if(FT->Open(name,1)!=0) { err=5; goto end;}
if(Write_(FT->file)!=0) { err=6; goto end;}
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

/*
//mmm xxx
UINT cntTrain=0;
cntTrain++; if(cntTrain%1000==0) {
for(i=0;i<nLay;i++) {
sprintf(TxtStr,"Layer: %d Alpha: %e",i,Layers[i].Alpha);
//mmm
MessageBox(NULL,TxtStr,"",MB_EX);

if(Layers[i].Alpha>AlphaMax||Layers[i].Alpha<0.) Layers[i].Alpha=AlphaMax;
}
}
//xxx
*/
 if(flInpLay!=0) {
//xxx
 if(nWei!=InpLay.n) goto endInpAxons;}
if(dir==0) {
pP=pPoints; pP->x=rc->left; pP->y=(rc->top+rc->bottom)/2;
pP=pPoints+1; pP->x=rc->right; pP->y=rc->top;
pP=pPoints+2; pP->x=rc->right; pP->y=rc->bottom;}
else {
pP=pPoints; pP->x=rc->right; pP->y=(rc->top+rc->bottom)/2;
pP=pPoints+1; pP->x=rc->left; pP->y=rc->top;
pP=pPoints+2; pP->x=rc->left; pP->y=rc->bottom;}
}

switch(typNet) { default: return 7;
// ��� ������� ������.
case typNNW_Vowel: nNeur=nPeaksMax; break;
// ��� ��������� ������.
//xxx
case typNNW_Cons: if(ParInpCons.IsOK()!=0) return 8;
nNeur=GetBYTE(ParInpCons.FreqMax/ParInpCons.StepTri); nNeur=MAX(nNeur,nTriMin); break;
}

s=0.; for(i=1;i<nFunP;i++) s+=FunP[i]; s*=2.; s+=FunP[0]; weiFunP=1.0F/(float)s; // ������������� �����������.

// ���������� �������� �����.
for(k=0;k<(BYTE)nNeur;k++) FlPeaks[k]=1;
if((BYTE)nNeur<nSpLines) for(k=(BYTE)nNeur;k<nSpLines;k++) FlPeaks[k]=0;

coe=PGP->coeRecPeaks;
for(k=0;k<nNeur;k++) { pSpL=SpLines+k; j=GetUSHRT_Test(pSpL->Freq);
iI=(int)j-(int)nFunA+1; iF=(int)j+(int)nFunA;
s=0.; for(iv=iI;iv<iF;iv++) { if(iv<0||iv>=nSpectr) continue; ia=iv-j; if(ia<0) ia=-ia;
if(ia>=nFunA) { err=25; goto end;} s+=Sp[iv]*FunP[ia];}
if((float)s*weiFunP<pSpL->AmpRel*coe) FlPeaks[k]=0;}

//-----------------------------------------------------------------------------------------------------------
// ���������� �� ����������.

BYTE FindLFreq(float *A,float *LF,UINT nPoints,float Discr,float Range)
{
BYTE ber; UINT i,j; USHRT nBuf,nBh,k,cnt; float *Buf,*fp,v; double s;

if(A==NULL) return 1; if(LF==NULL) return 2; if(nPoints==0) return 3; if(Discr<=0.0F) return 4;
if(Range<=0.0F) return 5; nBuf=GetUSHRT_Test(Range/Discr); if(nBuf<=1) return 6; nBh=nBuf/2;
if(nPoints>UINT_MAX-(UINT)nBh) return 7;
Buf=NULL; ber=0;
Buf=new float[nBuf]; if(Buf==NULL) { ber=8; goto end;}
for(k=0;k<nBuf;k++) Buf[k]=0.0F;
cnt=0; s=0.0F;
for(i=0;i<nPoints+(UINT)nBh;i++) { fp=Buf+cnt; s-=(double)*fp; if(i<nPoints) { v=A[i]; *fp=v; s+=(double)v;}
cnt++; if(cnt==nBuf) cnt=0; if(i<nBh) continue; j=i-(UINT)nBh; LF[j]=(float)s;}
v=1.0F/(float)nBuf; for(i=0;i<nPoints;i++) LF[i]*=v;
end: SAFE_DELETE(Buf); return ber;
}


//xxx yyy mmm
if(flOut!=0) {
//mmm
sprintf(TxtStr,"powPeaks,powTotal: %le %le typNet: %d",powPeaks,powTotal,*typNet); MessageBox(NULL,TxtStr,"",MB_EX);
}

BYTE flRecPeaksVowel; // ���� �������� �� ������ �������� �� ���� �����, � ������� � ������ 'nPeaksCons'.
#define LevPowPeakVowel_Stand 0.3F // ����������� ������� ��������, ������� ������ ����������� � ����� ������� � ������ 'nPeaksCons'.
float LevPowPeakVowel; // ����������� ������� ��������, ������� ������ ����������� � ����� ������� � ������ 'nPeaksCons'.

#define MinSzNotify 1024 // ����������� ������ ������ ��� ���������.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������.

extern char *FormTimeDur; // �������� ���������� ������� (�).
//-----------------------------------------------------------------------------------------------------------
// ��������� ������������ ��������� ������� �����.

BYTE clDlgSndCap::SetTimeBuf(void)
{
float v;

if(hDlg==NULL) return 1; if(GetFlEdt(hDlg,IDC_TIME_WIN,&v)!=0) return 2;
//xxx IDC_TIME_WIN

return 0;
}

// ���������� ������� ������� ����.
switch(meth) { default: break;
case methSpFour_CosWin: WinCoe=0.5F; break; // ������� �������������� ����� � ���������������� ������������ � ����.
case methSpFour_Gabor: WinCoe=coeWinWidGabor; break; // �������������� ������.
case methSpFour_Kaiser: WinCoe=4.54F; break; // ���� �������-�������.
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE clSndCapData::Alloc(UINT nM_)
{
if(SCA==NULL) return 1; if(SCA->Alloc(nM_)!=0) return 2; return 0;
}


//xxx
Txt[1]='\0'; Txt[0]='a';
if(WinText.hwnd!=NULL) { be=WinText.PasteText(Txt); // ����� ������� ����� � ���� ������.
if(be!=0) {
//mmm
sprintf(TxtStr,"WinText.PasteText be: %d",be); WinText.SetText(TxtStr);
}

}
if(be!=messRet&&be!=0) {
//mmm xxx
sprintf(TxtStr,"be: %d",be); MessageBox(NULL,TxtStr,"ProcRecRealTime",MB_EX);
}

//mmm xxx
if(flErr!=NULL) {
sprintf(TxtStr,"SpLines->Freq: %f PGP->coeWidPeaks: %f dFr: %f",SpLines->Freq,PGP->coeWidPeaks,dFr);
MessageBox(NULL,TxtStr,"",MB_EX);}

if(be!=0) {
sprintf(TxtStr,"\nRecognSoundNNW be: %d\n",be);
if(WinText.hwnd!=NULL) WinText.PasteText(TxtStr);
//xxx

 GETTEXTLENGTHEX TLI;
TLI.flags=GTL_NUMCHARS; TLI.codepage=CP_ACP;
lRes=SendMessage(hwndEdt,EM_GETTEXTLENGTHEX,(WPARAM)&TLI,0L);
if(lRes!=E_INVALIDARG) { if(lRes==MaxSizeEdt) SendMessage(hwndEdt,WM_SETTEXT,0,(LPARAM)"");}

//xxx SendMessage(hwndEdt,EM_SETREADONLY,(WPARAM)FALSE,0L);
//xxx SendMessage(hwndEdt,EM_SETREADONLY,(WPARAM)TRUE,0L);

WS_VSCROLL

if(WinText.hwnd!=NULL) {
if(nRecChar==MaxSizeEdt) { nRecChar=0; WinText.ClearWin();}
WinText.PasteText(Txt); nRecChar++;} // ���������� ������������ �������� � ����.

//RowText[szTimeMax+1];

}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������ � ����.

BYTE clWinText::PasteText(char *Text)
{
BYTE ber; size_t sz; LPSTR cp; HGLOBAL hGlb;

if(hwndEdt==NULL) return 1; if(IsOKStr(Text)!=0) return 0;
if(hwnd==NULL) return 2; if(OpenClipboard(hwnd)==FALSE) return 3;
EmptyClipboard();
hGlb=NULL; ber=0;
sz=(strlen(Text)+1)*sizeof(char);
hGlb=GlobalAlloc(GMEM_MOVEABLE,sz);
if(hGlb==NULL) { ber=4; goto end;}
cp=(char *)GlobalLock(hGlb); if(cp==NULL) { ber=5; goto end;}
memcpy(cp,Text,sz); 
GlobalUnlock(hGlb); 
if(SetClipboardData(CF_TEXT,hGlb)==NULL) { ber=6; goto end;}
CloseClipboard();
SendMessage(hwndEdt,WM_PASTE,0,0L);
end: if(hGlb!=NULL) GlobalFree(hGlb); return ber;
}

BYTE PasteText(char *Text); // ���������� ������ � ����.

if(be!=0) {
//mmm xxx
sprintf(TxtStr,"\nbe: %d k: %u TimeRecBuf,TimeRecProc: %u %u nPoints: %d i,nTime: %d %d nStep: %d\n",
be,k,TimeRecBuf,TimeRecProc,nPoints,i,nTime,nStep);
if(WinText.hwnd!=NULL) WinText.SetText(TxtStr);
}

//xxx
char const StrClose[]="�������"; // �������� ��� ������ "��������".
char const StrWinTxt[]="���� ������"; // �������� ������ �������� ���� ������.

//xxx
char const StrStop[]="����������"; // �������� ������ ���������.
char const StrSound[]="����"; // �������� ������ ������ �����.
char const StrSndCap[]="������"; // �������� ������ ������ �����.
char const StrSndRec[]="�������������"; // �������� ������ ������������� �����.
//xxx
SetDlgItemText(hDlg,IDC_PLAY_SND,StrSound);
//xxx
SetDlgItemText(hDlg,IDC_PLAY_SND,StrStop);

//xxx
SetFlEdt(hDlg,IDC_ERR_TRAIN,0.0F,FormErr);
SetFlEdt(hDlg,IDC_ERR_CONTR,0.0F,FormErr);


/*
if(CheckPeak(nSpectr,Sp,SpLines,&k,(BYTE)nFunP,FunP,PGP->coeRecPeaks)==0) {
//mmm
sprintf(TxtStr,"First Peak: %d",k);
MessageBox(NULL,TxtStr,"",MB_EX);}
*/

//xxx
//-----------------------------------------------------------------------------------------------------------
// �������� ����.

BYTE CheckPeak(USHRT nSpectr,float *Spectr,strSpectrLine *pSpL,BYTE *flPeak,BYTE nFunP,float *FunP,float coePeaks)
{
BYTE k,nFunA; USHRT j; int iv,ia,iI,iF; float weiFunP; double s;

if(nSpectr==0) return 1; if(Spectr==NULL) return 2; if(pSpL==NULL) return 3; if(flPeak==NULL) return 4;
if(nFunP==0) return 5; if(FunP==NULL) return 6;
if((USHRT)nFunP*3>UCHAR_MAX) return 7; nFunA=nFunP*3; if(coePeaks<=0.0F) return 8;

s=0.; for(k=1;k<nFunP;k++) s+=FunP[k]; s*=2.; s+=FunP[0]; weiFunP=1.0F/(float)s; // ������������� �����������.

j=GetUSHRT_Test(pSpL->Freq); iI=(int)j-(int)nFunA+1; iF=(int)j+(int)nFunA;
s=0.; for(iv=iI;iv<iF;iv++) { if(iv<0||iv>=nSpectr) continue; ia=iv-j; if(ia<0) ia=-ia;
if(ia>=nFunA) return 9; s+=(double)Spectr[iv]*(double)FunP[ia];}
if((float)s*weiFunP<pSpL->AmpRel*coePeaks) *flPeak=0; else *flPeak=1;

//mmm
sprintf(TxtStr,"pSpL->Freq: %f j,iI,iF: %d %d %d s,weiFunP,pSpL->AmpRel,coePeaks: %lf %f %f %f",
pSpL->Freq,j,iI,iF,s,weiFunP,pSpL->AmpRel,coePeaks);
MessageBox(NULL,TxtStr,"",MB_EX);

return 0;
}
if(flOut!=0) {
//mmm
sprintf(TxtStr,"k,amp,fr: %d %f %f iI,iF: %d %d",k,pSpL->AmpRel,fr,iI,iF);
MessageBox(NULL,TxtStr,"",MB_EX);
}
//xxx
else { 
	
if(flOut!=0) {
//mmm
//sprintf(TxtStr,"powPeaks,powTotal,PGP->LevPowPeak: %lf %lf %lf",powPeaks,powTotal,PGP->LevPowPeak);
//MessageBox(NULL,TxtStr,"",MB_EX);

}
	err=100; goto end;}

//xxx
if(flOut!=0) {
sprintf(TxtStr,"FindPeaks be: %d typNet,flErr: %d %d Amp,Freq: %f %f",be,typNet,flErr,pSpL->Amp,pSpL->Freq);
MessageBox(NULL,TxtStr,"",MB_EX);}

DrawNet(); // ����������� ����������� ����.


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ���������� ��������� ���� ��������� ������� ������.
//struct strParNNWSearch { BYTE nStRepM; float coeStI,coeSt,coeChSt;};
struct strParNNWSearch ParNNWSearch={ 60, 0.05F,0.2F,0.15F};

//-----------------------------------------------------------------------------------------------------------
// ���������� ��������� ���� ��������� ������� ������.

BYTE clDlgDBF_NNW::TrainNNW_Search(void)
{
BYTE GetNumInput(strNNW *pNNW,BYTE *nInp); // ��������� ����� �������� ������� ������������������ ����.
BYTE GetParNNW(strNNW *pNNW,strParNNW *pParNNW); // ��������� ���������� �� ��������� ��������� ����.
BYTE GetNumVectParNNW(strParNNW *pParNNW,BYTE nNeurInp,USHRT *nVect);// ��������� ������� ����� ������������� � �������� �� ��������� ��������� ����.
BYTE AbsValue(double *V,USHRT N,double *av); // ����� �������.

BYTE ind,nPeaksInp,be,ber; USHRT i,j,k,nStepsRand,nCycle,nV,nStRep; UINT *NumRandArr;
double stN,stNw,stPr,er,erN,erC,a,c,av,avN,ac,acN,acS,d,wei,weiN,weiC,coeSt,v,Err,ErrMin,ErrCntrl;
struct strArrTrSearch ATS; struct strParNNW Par;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) { Message(IDS_Mess_ErrConfNNW,MB_ST); return 2;}
if(ParNNWSearch.IsOK()!=0) return 3;
flBlk|=1<<numBlkDBF_Train; flTrain=1; flStopTrain=0; OnChFlagTrain();
if(GetNumInput(pNNW,&nPeaksInp)!=0) return 4; if(nPeaksInp==0) return 5;

NumRandArr=NULL; ber=0;

// ���������� � ������.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Fourier");
be=ProcSpectr(&flStopTrain); if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=6; goto end;}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // ����������� �������� ���������� ������.

// ���� ������ ���������� ���������� ����������� ��� ��������� ������������� ������������� ��������� ����.
nStepsRand=ParTrain.nStRand;
if(pNNW->flOK==0&&nStepsRand!=0) {
pNNW->ZeroInit(); ErrMin=LrgCnst32_d; j=USHRT_MAX;
ClearWinErrTrain(); // ������� ���� ������ ��� ���������� ����.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Random");

NumRandArr=new UINT[nStepsRand]; if(NumRandArr==NULL) { ber=7; goto end;}
srand(ParTrain.RandSeq); for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();
for(i=0;i<nStepsRand;i++) { if(flStopTrain!=0) goto end;
if(pNNW->RandInit(NumRandArr[i],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=8; goto end;}
be=StepRand(&Err); if(be!=0&&be!=messRet) { ber=9; goto end;}
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(Err<ErrMin) { ErrMin=Err; j=i; SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)ErrMin,FormErr);}
ShowProgress(hwndProgr,NULL,(UINT)i+1,(UINT)nStepsRand); ProcMess(); // ����������� �������� ���������� ������.
if(flStopTrain!=0) { ber=messRet; goto end;}
}
if(j>=nStepsRand) { ber=10; goto end;}
if(pNNW->RandInit(NumRandArr[j],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=11; goto end;}
}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // ����������� �������� ���������� ������.

// �������� ���������� ������.
if(GetParNNW(pNNW,&Par)!=0) { ber=12; goto end;} // ��������� ���������� �� ��������� ��������� ����.
if(GetNumVectParNNW(&Par,nPeaksInp,&nV)!=0) { ber=13; goto end;} // ��������� ������� ����� ������������� � �������� �� ��������� ��������� ����.
if(ATS.Create(nV)!=0) { ber=14; goto end;} // �������� ��������.
if(pNNW->AllocVect()!=0) { ber=15; goto end;} // ��������� ������ ��� ��������.

be=FindVectSearch(&er,&wei,NULL,NULL); if(be!=0&&be!=messRet) { ber=16; goto end;}
if(be==messRet&&ParTrain.flRandSampl==0) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(pNNW->GetSetArrSearch(ATS.Vect,nV,0,1)!=0) { ber=17; goto end;} // ��������� ��������.
if(AbsValue(ATS.Vect,nV,&av)!=0) { ber=18; goto end;}
if(pNNW->GetSetArrSearch(ATS.Coe,nV,0,0)!=0) { ber=19; goto end;} // ��������� �������������.
if(AbsValue(ATS.Coe,nV,&ac)!=0) { ber=20; goto end;}

ind=0; stN=ac;

// ����� ���������� ��������� ������� ������.
nCycle=0;
rep: SetUSHRT_Edt(hDlg,IDC_NUM_CYCLE,nCycle);
for(k=0;k<ParTrain.nStTrain;k++) { nStRep=0;
repSt: if(av<SmCnst24_d) goto end; if(flStopTrain!=0) { ber=messRet; goto end;}
if(ind==0) coeSt=ParNNWSearch.coeStI; else coeSt=ParNNWSearch.coeSt;
stPr=stN*coeSt; v=stPr/av; for(i=0;i<nV;i++) ATS.CoeN[i]=ATS.Coe[i]+ATS.Vect[i]*v;

if(pNNW->GetSetArrSearch(ATS.CoeN,nV,1,0)!=0) { ber=21; goto end;} // ��������� �������������.
if(FindVectSearch(&erN,&weiN,&erC,&weiC)!=0) { ber=22; goto end;}
if(pNNW->GetSetArrSearch(ATS.VectN,nV,0,1)!=0) { ber=23; goto end;} // ��������� ��������.
if(AbsValue(ATS.VectN,nV,&avN)!=0) { ber=24; goto end;}
if(erN>er) { stN*=ParNNWSearch.coeChSt; if(nStRep>ParNNWSearch.nStRepM) goto end; nStRep++;
ProcMess(); goto repSt;}

if(AbsValue(ATS.CoeN,nV,&acN)!=0) { ber=25; goto end;}
v=er-erN; if(v<SmCnst24_d) goto end; stN=erN/v*stPr; for(i=0;i<nV;i++) ATS.CoeS[i]=ATS.Coe[i]+ATS.CoeN[i];
if(AbsValue(ATS.CoeS,nV,&acS)!=0) { ber=26; goto end;}
v=stPr*acS; if(v<SmCnst24_d) goto end; a=(er-erN)/v; c=((er+erN)-a*(ac*ac+acN*acN))*0.5; if(c<0.) c=0.;
if(a<SmCnst24_d) goto end; d=(erN-c)/a; stNw=SQRT(d);
stN=MIN(stN,stNw); er=erN; ac=acN; av=avN;
for(i=0;i<nV;i++) { ATS.Coe[i]=ATS.CoeN[i]; ATS.Vect[i]=ATS.VectN[i];}

// ����� ���������� � ���� ����������.
if(weiN<SmCnst24_d) { ber=27; goto end;} Err=erN/weiN; Err=SQRT(Err);
if(weiC<SmCnst24_d) ErrCntrl=0.; else ErrCntrl=erC/weiC; ErrCntrl=SQRT(Err);
SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)Err,FormErr);
SetFlEdt(hDlg,IDC_ERR_CONTR,(float)ErrCntrl,FormErr);
ind=1; pNNW->flOK=1;
ShowProgress(hwndProgr,NULL,(UINT)k+1,(UINT)ParTrain.nStTrain); ProcMess(); // ����������� �������� ���������� ������.
}
if(nCycle==USHRT_MAX) goto end; nCycle++; goto rep;

end: flBlk&=~(1<<numBlkDBF_Train); flTrain=0; flStopTrain=1; OnChFlagTrain();
SAFE_DELETE_ARR(NumRandArr); pNNW->FreeVect(); // ������������ ������.
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // ����������� �������� ���������� ������.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
return ber;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ���������� ��������� ���� ��������� ������� ������.
//struct strParNNWSearch { BYTE nStRepM; float coeSt,coeChSt;};
struct strParNNWSearch ParNNWSearch={ 60, 0.1F,0.15F};



//-----------------------------------------------------------------------------------------------------------
// ���������� ��������� ���� ��������� ������� ������.

BYTE clDlgDBF_NNW::TrainNNW_Search(void)
{
BYTE GetNumInput(strNNW *pNNW,BYTE *nInp); // ��������� ����� �������� ������� ������������������ ����.
BYTE GetParNNW(strNNW *pNNW,strParNNW *pParNNW); // ��������� ���������� �� ��������� ��������� ����.
BYTE GetNumVectParNNW(strParNNW *pParNNW,BYTE nNeurInp,USHRT *nVect);// ��������� ������� ����� ������������� � �������� �� ��������� ��������� ����.
BYTE AbsValue(double *V,USHRT N,double *av); // ����� �������.
BYTE Randomize(double *Vect,double *VectR,USHRT nVect,UINT nRand,float coe); // ������� ���������� ��������� �������.

BYTE nPeaksInp,be,ber; USHRT i,j,k,nStepsRand,nCycle,nV; UINT *NumRandArr,numRand; float coeVect;
double stPr,er,erN,erC,erM,av,ac,acN,wei,weiN,weiC,v,Err,ErrMin,ErrCntrl;
struct strArrTrSearch ATS; struct strParNNW Par;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) { Message(IDS_Mess_ErrConfNNW,MB_ST); return 2;}
if(ParNNWSearch.IsOK()!=0) return 3;
flBlk|=1<<numBlkDBF_Train; flTrain=1; flStopTrain=0; OnChFlagTrain();
if(GetNumInput(pNNW,&nPeaksInp)!=0) return 4; if(nPeaksInp==0) return 5;
nStepsRand=ParTrain.nStRand; if(nStepsRand==0) return 6;

NumRandArr=NULL; ber=0;
NumRandArr=new UINT[nStepsRand]; if(NumRandArr==NULL) { ber=7; goto end;}

// ���������� � ������.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Fourier");
be=ProcSpectr(&flStopTrain); if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=6; goto end;}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // ����������� �������� ���������� ������.

// ���� ������ ���������� ���������� ����������� �� ��������� �������������� ������������� ��������� ����.
if(pNNW->flOK==0&&nStepsRand!=0) {
pNNW->ZeroInit(); ErrMin=LrgCnst32_d; j=USHRT_MAX;
ClearWinErrTrain(); // ������� ���� ������ ��� ���������� ����.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Random");
srand(ParTrain.RandSeq); for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();
for(i=0;i<nStepsRand;i++) { if(flStopTrain!=0) goto end;
if(pNNW->RandInit(NumRandArr[i],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=8; goto end;}
be=StepRand(&Err); if(be!=0&&be!=messRet) { ber=9; goto end;}
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(Err<ErrMin) { ErrMin=Err; j=i; SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)ErrMin,FormErr);}
ShowProgress(hwndProgr,NULL,(UINT)i+1,(UINT)nStepsRand); ProcMess(); // ����������� �������� ���������� ������.
if(flStopTrain!=0) { ber=messRet; goto end;}
}
if(j>=nStepsRand) { ber=10; goto end;}
if(pNNW->RandInit(NumRandArr[j],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=11; goto end;}
}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // ����������� �������� ���������� ������.

// �������� ���������� ������.
if(GetParNNW(pNNW,&Par)!=0) { ber=12; goto end;} // ��������� ���������� �� ��������� ��������� ����.
if(GetNumVectParNNW(&Par,nPeaksInp,&nV)!=0) { ber=13; goto end;} // ��������� ������� ����� ������������� � �������� �� ��������� ��������� ����.
if(ATS.Create(nV)!=0) { ber=14; goto end;} // �������� ��������.
if(pNNW->AllocVect()!=0) { ber=15; goto end;} // ��������� ������ ��� ��������.

be=FindVectSearch(&er,&wei,NULL,NULL); if(be!=0&&be!=messRet) { ber=16; goto end;}
if(be==messRet&&ParTrain.flRandSampl==0) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(pNNW->GetSetArrSearch(ATS.Vect,nV,0,1)!=0) { ber=17; goto end;} // ��������� ��������.
if(AbsValue(ATS.Vect,nV,&av)!=0) { ber=18; goto end;}
if(pNNW->GetSetArrSearch(ATS.Coe,nV,0,0)!=0) { ber=19; goto end;} // ��������� �������������.
if(AbsValue(ATS.Coe,nV,&ac)!=0) { ber=20; goto end;}

// ����� ���������� ��������� ������� ������.
nCycle=0;
rep: SetUSHRT_Edt(hDlg,IDC_NUM_CYCLE,nCycle);
for(k=0;k<ParTrain.nStTrain;k++) {

if(av<SmCnst24_d) goto end; if(flStopTrain!=0) { ber=messRet; goto end;}
stPr=ac*ParNNWSearch.coeSt; v=stPr/av; for(i=0;i<nV;i++) ATS.CoeN[i]=ATS.Coe[i]+ATS.Vect[i]*v;

if(pNNW->GetSetArrSearch(ATS.CoeN,nV,1,0)!=0) { ber=21; goto end;} // ��������� �������������.
if(AbsValue(ATS.CoeN,nV,&acN)!=0) { ber=24; goto end;}
if(FindVectSearch(&erN,&weiN,&erC,&weiC)!=0) { ber=22; goto end;}
if(pNNW->GetSetArrSearch(ATS.Vect,nV,0,1)!=0) { ber=23; goto end;} // ��������� ��������.
if(AbsValue(ATS.Vect,nV,&av)!=0) { ber=24; goto end;}

// ���� ���������� ������. 
if(erN>er) {
erM=er; j=USHRT_MAX;
coeVect=ParTrain.coeVect; numRand=ParTrain.RandSeq;

repSearch: srand(numRand); for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();
for(i=0;i<nStepsRand;i++) { if(flStopTrain!=0) goto end; ProcMess();
if(Randomize(ATS.Coe,ATS.CoeN,nV,NumRandArr[i],coeVect)!=0) { ber=24; goto end;}
if(pNNW->GetSetArrSearch(ATS.CoeN,nV,1,0)!=0) { ber=21; goto end;} // ��������� �������������.
if(FindVectSearch(&erN,&weiN,NULL,NULL)!=0) { ber=22; goto end;} ProcMess();

//mmm xxx
//sprintf(TxtStr,"Random coeVect: %f  i,err: %d %lf",coeVect,i,erN); MessageBox(NULL,TxtStr,"",MB_EX);

if(erN<erM) { erM=erN; j=i;}}

//mmm xxx
//sprintf(TxtStr,"j: %d",j); MessageBox(NULL,TxtStr,"",MB_EX);

if(j==USHRT_MAX) { coeVect*=2.0F; numRand++;
//xxx
if(coeVect>100.) { ber=100; goto end;}

 goto repSearch;}

if(Randomize(ATS.Coe,ATS.CoeN,nV,NumRandArr[j],ParTrain.coeVect)!=0) { ber=24; goto end;}
if(pNNW->GetSetArrSearch(ATS.CoeN,nV,1,0)!=0) { ber=21; goto end;} // ��������� �������������.
if(AbsValue(ATS.CoeN,nV,&acN)!=0) { ber=24; goto end;}
if(FindVectSearch(&erN,&weiN,&erC,&weiC)!=0) { ber=22; goto end;}
if(pNNW->GetSetArrSearch(ATS.Vect,nV,0,1)!=0) { ber=23; goto end;} // ��������� ��������.
if(AbsValue(ATS.Vect,nV,&av)!=0) { ber=24; goto end;}
}

//mmm xxx
//sprintf(TxtStr,"Continue k: %d",k); MessageBox(NULL,TxtStr,"",MB_EX);

// ������ ����� ������������� � ���������� ��� ����������� �����.
er=erN; ac=acN; for(i=0;i<nV;i++) ATS.Coe[i]=ATS.CoeN[i];

// ����� ���������� � ���� ����������.
if(weiN<SmCnst24_d) { ber=27; goto end;} Err=erN/weiN; Err=SQRT(Err);
if(weiC<SmCnst24_d) ErrCntrl=0.; else ErrCntrl=erC/weiC; ErrCntrl=SQRT(Err);
SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)Err,FormErr);
SetFlEdt(hDlg,IDC_ERR_CONTR,(float)ErrCntrl,FormErr);
pNNW->flOK=1;
ShowProgress(hwndProgr,NULL,(UINT)k+1,(UINT)ParTrain.nStTrain); ProcMess(); // ����������� �������� ���������� ������.

//mmm xxx
//sprintf(TxtStr,"--->OK k: %d",k); MessageBox(NULL,TxtStr,"",MB_EX);

}
if(nCycle==USHRT_MAX) goto end; nCycle++; goto rep;

end: flBlk&=~(1<<numBlkDBF_Train); flTrain=0; flStopTrain=1; OnChFlagTrain();
SAFE_DELETE_ARR(NumRandArr); pNNW->FreeVect(); // ������������ ������.
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // ����������� �������� ���������� ������.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ���������� ��������� �������.

BYTE Randomize(double *Vect,double *VectR,USHRT nVect,UINT nRand,float coe)
{
USHRT i; double vr,Coe;

if(Vect==NULL) return 1; if(VectR==NULL) return 2; if(nVect==0) return 3;
srand(nRand); vr=1./(double)RAND_MAX; Coe=coe*2.;
for(i=0;i<nVect;i++) VectR[i]=Vect[i]*(1.+((double)rand()*vr-0.5)*Coe); return 0;
}

// ���������� �������.
vM=0.0F; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; if(v>vM) vM=v;} if(vM==0.0F) { err=19; goto end;}
if(vM<PGP->AmpThr) { err=messRet; goto end;}
coeNorm=vM; v=1.0F/vM; for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

y=pNeur->Val;
//xxx
switch(Lay->TypFunAct) { default: return 6;
case TypFunAct_Sigm:   f=y*(1.-y); break;     // ���������� ������.
case TypFunAct_BiSigm: f=0.5*(1.-y*y); break; // ���������� c��������� ������.
case TypFunAct_HypTan: f=1.-y*y; break;       // ��������������� �������.
}

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ���� ��� ������ ����.

BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
USHRT i,j; double f1,f2,f3,f,y,Gamma;

if(LayPrev==NULL) return 1; if(LayPrev->Neurons->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->Neurons->IsOK()!=0) return 4;
if(AlphaMin<0.0F) return 5; if(AlphaMax<=0.0F) return 6; if(AlphaMax<AlphaMin) return 7;
f=f1=f2=f3=0.; 

switch(Lay->TypFunAct) { default: return 8;

case TypFunAct_Sigm: // ���������� ������.
for(j=0;j<Lay->n;j++) { y=(double)Lay->Neurons[j].Val; Gamma=(double)Lay->Neurons[j].Err;
f1+=pow(Gamma,2)*y*(1.-y); f3+=pow(Gamma,2)*pow(y,2)*pow(1.0-y,2);}
for(i=0;i<LayPrev->n;i++) f2+=pow((double)LayPrev->Neurons[j].Val,2);
f=4.*f1/((1.+f2)*f3); break; 

case TypFunAct_BiSigm: // ���������� ���������� �������.
for(j=0;j<Lay->n;j++) { y=Lay->Neurons[j].Val; Gamma=Lay->Neurons[j].Err;
f1+=pow(Gamma,2)*(1.-pow(y,2)); f3+=pow(Gamma,2)*pow(1-pow(y,2),2);}
for(i=0;i<LayPrev->n;i++) f2+=pow(LayPrev->Neurons[j].Val,2);
f=4.*f1/((1.+f2)*f3); break;

case TypFunAct_HypTan: // ��������������� �������.
for(j=0;j<Lay->n;j++) { y=Lay->Neurons[j].Val; Gamma=Lay->Neurons[j].Err;
f1+=(float)(pow(Gamma,2)*(1.-pow(y,2))); f3+=(float)(pow(Gamma,2)*pow(1-pow(y,2),2));}
for(i=0;i<LayPrev->n;i++) f2+=pow(LayPrev->Neurons[i].Val,2);
f=f1/((1.+f2)*f3); break;
}
f=MIN(f,AlphaMax); f=MAX(f,AlphaMin); Lay->Alpha=(float)f; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ���� ��� ����, ���������� �� ��������.

BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
USHRT i,j; double f1,f2,f3,f,y,Gamma;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->Neurons->IsOK()!=0) return 4;
if(AlphaMin<0.0F) return 5; if(AlphaMax<=0.0F) return 6; if(AlphaMax<AlphaMin) return 7;
f=f1=f2=f3=0.; 

switch(Lay->TypFunAct) { default: return 8;

case TypFunAct_Sigm: // ���������� ������.
for(j=0;j<Lay->n;j++) { y=Lay->Neurons[j].Val; Gamma=Lay->Neurons[j].Err;
f1+=pow(Gamma,2)*y*(1.-y); f3+=pow(Gamma,2)*pow(y,2)*pow(1.-y,2);}
for(i=0;i<LayPrev->n;i++) f2+=pow(LayPrev->Values[i],2);
if(f3<=0.) return 9; f=4.*f1/((1.+f2)*f3); break; 

case TypFunAct_BiSigm: // ���������� ���������� �������.
for(j=0;j<Lay->n;j++) { y=Lay->Neurons[j].Val; Gamma=Lay->Neurons[j].Err;
f1+=pow(Gamma,2)*(1.-pow(y,2)); f3+=pow(Gamma,2)*pow(1.-pow(y,2),2);}
for(i=0;i<LayPrev->n;i++) f2+=pow(LayPrev->Values[i],2);
if(f3<=0.) return 10; f=4.*f1/((1.+f2)*f3); break;

case TypFunAct_HypTan: // ��������������� �������.
for(j=0;j<Lay->n;j++) { y=Lay->Neurons[j].Val; Gamma=Lay->Neurons[j].Err;
f1+=pow(Gamma,2)*(1.-pow(y,2)); f3+=pow(Gamma,2)*pow(1.-pow(y,2),2);}
for(i=0;i<LayPrev->n;i++) f2+=pow(LayPrev->Values[i],2);
if(f3<=0.) return 11; f=f1/((1.+f2)*f3); break;
}
f=MIN(f,AlphaMax); f=MAX(f,AlphaMin); Lay->Alpha=(float)f; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ���� ������ ��� ���������� ����.

void clDlgDBF_NNW::ClearWinErrTrain(void)
{
if(hDlg==NULL) return;
SetDlgItemText(hDlg,IDC_ERR_TRAIN,"");
SetDlgItemText(hDlg,IDC_ERR_CONTR,"");
}


//-----------------------------------------------------------------------------------------------------------
// ��������� �������� ���� � ������.

BYTE strNNW::Compute(strInpLay *InpLay_)
{
BYTE CopyInpLay(strInpLay *Dst,strInpLay *Src); // ����������� ��������� �������� ���� ����.
BYTE ComputeLayer(strLay *LayPrev,strLay *Lay); // ������ �������� �������� � ���� "Lay".
BYTE ComputeLayerFirst(strInpLay *LayPrev,strLay *Lay); // ������ �������� �������� � ���� "Lay" - ������ ������� ����.

BYTE i;

if(IsOK()!=0) return 1; if(CopyInpLay(&InpLay,InpLay_)!=0) return 2;
if(ComputeLayerFirst(&InpLay,&Layers[0])!=0) return 3;
for(i=1;i<nLay;i++) if(ComputeLayer(&Layers[i-1],&Layers[i])!=0) return 4; return 0;
}

nStepsRand=ParTrain.nStRand;
if(pNNW->flOK==0&&nStepsRand!=0) {
pNNW->ZeroInit(); ErrMin=LrgCnst32_d; j=USHRT_MAX;
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Random");

NumRandArr=new UINT[nStepsRand]; if(NumRandArr==NULL) { ber=4; goto end;}
srand(ParTrain.RandSeq); for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();
for(i=0;i<nStepsRand;i++) { if(flStopTrain!=0) goto end;
if(pNNW->RandInit(NumRandArr[i],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=5; goto end;}
be=StepRand(&Err); if(be!=0&&be!=messRet) { ber=6; goto end;}
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(Err<ErrMin) { ErrMin=Err; j=i; SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)ErrMin,FormErr);}
ShowProgress(hwndProgr,NULL,(UINT)i+1,(UINT)nStepsRand); ProcMess(); // ����������� �������� ���������� ������.
if(flStopTrain!=0) { ber=messRet; goto end;}
}
if(j>=nStepsRand) { ber=7; goto end;}
if(pNNW->RandInit(NumRandArr[j],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=8; goto end;}
}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // ����������� �������� ���������� ������.

//-----------------------------------------------------------------------------------------------------------
// �������� ��� �������� ����������� ����.

BYTE clDlgDBF_NNW::OnOpenDlg(HWND hDlg_)
{
BYTE fl;

if(hDlg_==NULL) return 1; hDlg=hDlg_;
if(CreateBrushes()!=0) return 2; // �������� ������ ��� ������������ ����.
SetPosWindowCenter(hDlg); // ��������� ���� � ����� ������� ���� ��� ������.
//zzz
FillLBFiles(); // ���������� ������ ������ ���� ������.
UnSelFile(); // �������� ��� ������ ������� �����.
if(pDataBase==NULL) fl=0; else fl=pDataBase->flChange; EnableChWin(hDlg,IDC_SAVE,fl);
hwndProgr=InitProgress(hDlg,IDC_PROGR); // ������������� ���� ������ �������� ���������� ������.
SetColProgr(hwndProgr,COL_WHITE,COL_BLUE);

SetTxtBtnPreProc(); // ��������� ������ � ������ ��������������� ���������.
SetTxtBtnTrain(); // ��������� ������ � ������ ���������� ����.
SetTxtBtnPlaySound(); // ��������� ������ � ������ ��������������� �����.
SetTxtBtnBlockSetTime(); // ��������� ������ � ������ ���������� ��������� ������� � ���� ������.

ParTrain.Read(PathToProgDir,NameParTrain); // ������ ���������� ���������� ����.
SetHeaderWinAlpha(); // ��������� ��������� ���� ����.

InitParNNW(); // ������������� �������� ���������� ��������� �����.
SetPntNNW(); // ��������� ���������� �� ��������� ��������� ���� � ���������� ��������� ����.

// ��������� ���� ��������������.
CheckRadioButton(hDlg,IDC_RADIO_VOWEL,IDC_RADIO_CONS,IDC_RADIO_VOWEL+(int)typNet); // ��������� ���� ����.
SetNameNNW(typNNW_Vowel); SetNameNNW(typNNW_Cons); // ��������� ��� ������ ��������� �����.
ClearWinParFile(); // ������� ���� ���������� ����� ���� ������ � �����.
ClearWinParSound(); // ������� ���� ���������� ������� ����� ���� ������ � �����.
ShowHideWinStepTrain(); // ������������ ��� ������� ���� ����������� ����.

return 0;
}

if(num==numSnd) nTrue++; // ������������ ���� ������ � �������� (��� ������ ���������� ��� ������).
if(numSnd!=UCHAR_MAX) {
if(num!=UCHAR_MAX&&num!=numSnd) nFalse++; // �������� ���� �� ������, ����������� ������ ����.
if(num==UCHAR_MAX) nNoRec++; // �������� ���� �� ������, ���� �� ���������.
}
if(numSnd==UCHAR_MAX) { if(num!=UCHAR_MAX) nFalse++;} // �������� ���� - ������, �� ��������� ��� ���� ����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������.

#define nNod_HidLay 15 // ����� �������� � ������� ����.

if(MW==NULL) return 7; Wid=MW->Param.Time_Width; if(Wid<=0.0F) return 8;

if(frI>PGP->MaxFreqFirst) goto TriCons; 
MaxFreqFirst=MaxFreqFirst_Stand; 
#define MaxFreqFirst_Stand 400.0F // ������������ �������, ��� ����� ���������� ������ ������������ ���.
float MaxFreqFirst; // ������������ �������, ��� ����� ���������� ������ ������������ ���.

for(i=0;i<nSpectr;i++) FlagsV[i]=Flags[i]; // ���������� ������ ����� �� ������ ���c���.
// ������������ ����� � ����� ���������� ��� ���������� ������� ����.
for(i=nFrMin;i<nFrMax;i++) { if(FlagsV[i]==0) continue; v=Sp[i];
if(v<PGP->ampSmPeaksMS||v*coeNorm<ampMax*PGP->ampSmPeaksAbs) FlagsV[i]=0;}

//xxx zzz
//mmm
sprintf(TxtStr,"nFrI>=nFrIMax: %d %d",nFrI,nFrIMax); MessageBox(NULL,TxtStr,"",MB_EX);

//xxx zzz
//mmm
if(flRep!=0&&flOut!=0) {
sprintf(TxtStr,"num,frI,nFrI: %d %f %d",num,frI,nFrI); MessageBox(NULL,TxtStr,"",MB_EX);
}
//xxx zzz
//mmm
if(fl==0&&flOut!=0) {
sprintf(TxtStr,"num,nFrI: %d %d",num,nFrI); MessageBox(NULL,TxtStr,"After CheckPeak",MB_EX);
}
//xxx
flRep=1;

//xxx zzz
//mmm
if(err!=0&&flOut!=0) {
sprintf(TxtStr,"err: %d",err); MessageBox(NULL,TxtStr,"FindPeaks",MB_EX);
}
GetChBox(hDlg,IDC_CHECK_CH_PHASE,&flPhase);

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������.

strAnSnd *strAnSndArr::Get(BYTE num)
{
if(IsOK()!=0) return NULL; if(num>=nArr) return NULL; return pArr+num;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �����.

BYTE Synthesis(float *Wave,UINT nPoints,float Amp,USHRT nStep,clInpLayArr *pPeaks,BYTE nPM,double dt,
float Freq)
{
BYTE SumCos(UINT i,double *Peaks,BYTE nPeaks,double dt,float Freq,float *Res); // ������ �������� ����� ��� ������� �����.

BYTE nPeaks,ber; USHRT ia; int iw; UINT i,j,k,kI; float v,*FunWin; double coe; struct strInpLay *pIL;

if(Wave==NULL) return 1; if(nPoints==0) return 2; if(nStep==0) return 3;
if(pPeaks==NULL) return 4; if(pPeaks->IsOK()!=0) return 5;
if(pPeaks->nData>UINT_MAX-2) return 6; if(pPeaks->nData+2>UINT_MAX/nStep) return 7;
if(dt<=0.) return 8; if(Freq<=0.0F) return 9;

FunWin=NULL; ber=0;
FunWin=new float[nStep]; if(FunWin==NULL) { ber=10; goto end;}
coe=M_PI/(double)nStep; for(ia=0;ia<nStep;ia++) { v=(float)(1.+cos(coe*(double)ia)); FunWin[ia]=v*0.5F;} // ���������� ������� �����������.

pIL=pPeaks->Get(pPeaks->nData/2); if(pIL==NULL) { ber=11; goto end;} if(pIL->IsOK()!=0) { ber=12; goto end;}
if(nPM==0) nPeaks=pIL->n; else nPeaks=MIN(pIL->n,nPM);
for(k=0;k<nPoints;k++) {
if(SumCos(k,pIL->Values,nPeaks,dt,Freq,&v)!=0) { ber=14; goto end;}
Wave[k]=v*Amp;
}

/* xxx zzz
for(k=0;k<nPoints;k++) Wave[k]=0.0F;
for(i=0;i<pPeaks->nData;i++) { kI=i*(UINT)nStep;
pIL=pPeaks->Get(i); if(pIL==NULL) { ber=11; goto end;} if(pIL->IsOK()!=0) { ber=12; goto end;}

for(j=0;j<(UINT)nStep*2-1;j++) { k=kI+j; if(k>=nPoints) break;
iw=(int)j-(int)nStep+1; if(iw>=0) ia=(USHRT)iw; else ia=(USHRT)(-iw); if(ia>=nStep) { ber=13; goto end;}
if(nPM==0) nPeaks=pIL->n; else nPeaks=MIN(pIL->n,nPM);
if(SumCos(k,pIL->Values,nPeaks,dt,Freq,&v)!=0) { ber=14; goto end;}
Wave[k]+=v*Amp*FunWin[ia];}}
*/

end: SAFE_DELETE_ARR(FunWin); return ber;
}

#define FreqLF_Stand 100.0F // ������� �������, �������������� ������ ������� (��) - ����������� ��������.
float FreqLF; // ������� �������, �������������� ������ ������� (��).

//-----------------------------------------------------------------------------------------------------------
// ������ �����.

BYTE Synthesis(float *Wave,UINT nPoints,float Amp,USHRT nStep,clInpLayArr *pPeaks,BYTE nPM,double dt,float Freq)
{
BYTE SumCos(UINT x,double *Peaks,BYTE nPeaks,double dt,float Freq,float *Res); // ������ �������� ����� ��� ������� �����.
BYTE SumCosCorr(UINT x,double *Peaks,BYTE nPeaks,double dt,float Freq,float *Res); // ������ �������� ����� ��� ������� ����� � ���������� ������.

BYTE nPeaks,flIncHigh,ber; USHRT ia; int iw; UINT i,j,k,kI; float v,*FunWin; double coe; struct strInpLay *pIL;

if(Wave==NULL) return 1; if(nPoints==0) return 2; if(nStep==0) return 3;
if(pPeaks==NULL) return 4; if(pPeaks->IsOK()!=0) return 5;
if(pPeaks->nData>UINT_MAX-2) return 6; if(pPeaks->nData+2>UINT_MAX/nStep) return 7;
if(dt<=0.) return 8; if(Freq<=0.0F) return 9;
flIncHigh=flagIncHighSynth;
for(k=0;k<nPoints;k++) Wave[k]=0.0F;

FunWin=NULL; ber=0;
FunWin=new float[nStep]; if(FunWin==NULL) { ber=10; goto end;}
coe=M_PI/(double)nStep; for(ia=0;ia<nStep;ia++) { v=(float)(1.+cos(coe*(double)ia)); FunWin[ia]=v*0.5F;} // ���������� ������� �����������.

for(i=0;i<pPeaks->nData;i++) { kI=i*(UINT)nStep;
pIL=pPeaks->Get(i); if(pIL==NULL) { ber=11; goto end;} if(pIL->IsOK()!=0) { ber=12; goto end;}

for(j=0;j<(UINT)nStep*2-1;j++) { k=kI+j; if(k>=nPoints) break;
iw=(int)j-(int)nStep+1; if(iw>=0) ia=(USHRT)iw; else ia=(USHRT)(-iw); if(ia>=nStep) { ber=13; goto end;}
if(nPM==0) nPeaks=pIL->n; else nPeaks=MIN(pIL->n,nPM);
if(flIncHigh==0) { if(SumCos(k,pIL->Values,nPeaks,dt,Freq,&v)!=0) { ber=14; goto end;}}
else { if(SumCosCorr(k,pIL->Values,nPeaks,dt,Freq,&v)!=0) { ber=15; goto end;}}
Wave[k]+=v*Amp*FunWin[ia];}}

end: SAFE_DELETE_ARR(FunWin); return ber;
}

flIncHigh=flagIncHighSynth;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ��������� ������� ����� �� ����������.

#define flagIncHighSynth 1 // ���� ���������� �������� ������� �������� ��� ������� �����.

//xxx
if(flOut!=0&&(be!=0||flErr!=0||typNet>=nTypNNW)) {
sprintf(TxtStr,"be,flErr,typNet: %d %d %d",be,flErr,typNet);
MessageBox(NULL,TxtStr,"FindPeaks",MB_EX);}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������� ������� ����.

BYTE GetWinCoe(BYTE meth,float *pWinCoe)
{
if(pWinCoe==NULL) return 1;
switch(meth) { default: *pWinCoe=1; break;
case methSpFour_CosHann: *pWinCoe=0.5F; break; // ������� ����� (���������������� �����������).
case methSpFour_Gauss: *pWinCoe=coeWinWidGauss; break; // ������� ������.
case methSpFour_KaisBess: *pWinCoe=4.54F; break; // ���� �������-�������.
}
return 0;
}

if(GetWinCoe(Param.methSpFour,&WinCoe)!=0) { ber=11; goto end;}

SpectrAmp[szTimeMax][szFreqMax]

sz_Time=sz_Freq=0; st_Time=st_Freq=0.;

USHRT sz_Time,sz_Freq; 
double st_Time,st_Freq;

//-----------------------------------------------------------------------------------------------------------
// ������ ���������.

BYTE clMain::ComputeDiag(void)
{
BYTE GetN_(USHRT nPoints,USHRT *Np,USHRT NpM,BYTE *Mp); // ��� ����������� ����� 'Np', ���������� 2 � ����� �������, ������� ��������� 'nPoints'.
BYTE GetWeightWinSTFT(BYTE meth,float *Weight,USHRT nP,float Wid); // ���������� ������� ������� ���� ��� ������������ ����������.
BYTE FastFT(complex *A,complex *B,BYTE M,SCHAR dir,BYTE prcMess); // ������� �������������� �����.
BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines,strParGetPeaks *PGP,
  BYTE *typNet,BYTE *flErr); // ���������� ������������� �������� � ������ ������������ �����.
BYTE RecognSoundNNW(float *Spectr,UINT nSpectr,float dFr,strNNW *NNW_Vowel,strNNW *NNW_Cons,pFunDecSnd DecSnd,
  PNT_DATA Pnt,BYTE *numSnd,BYTE *typSnd,BYTE flOut); // ������������� ������ ������� ��������� �����.
BYTE DecSnd_Instant(PNT_DATA Pnt,strLay *pLay,BYTE typ,BYTE *typSnd,BYTE *numSnd); // ������� �������� ������� ��� ������������� ����� - ���������� ��������� �������������, ���������� �� ������� ���������.
BYTE GetSymbSound(BYTE num,BYTE typ,char *pSymb); // ��������� ������� �����.

BYTE M,j,numSnd,typSnd,typNet,nPeaks,be,ber; SHRT iv,nv; USHRT nWinWid,nPoints,nPh,n; UINT i,k,nTime;
__int64 l; float v,*Weight,dFr; double d,WinStep; complex *A,*B; char Symb; struct strSpectrLine *pSpL;

FreeDiag(); // ������������ ������ ��� ���������.
if(Snd.IsOK()!=0) { Message(IDS_Mess_FileNotOpen,MB_ST); return 1;}
if(Param.IsOK()!=0) return 2;

v=Param.Time_Width; if(Param.methSpFour==methSpFour_Gauss) v*=coeWinWidGauss;
nWinWid=GetUSHRT_Test((double)v/Snd.dt); if(nWinWid<nWinWid_Min) nWinWid=nWinWid_Min;
be=GetN_(nWinWid,&nPoints,0,&M); if(be==messRet) { Message(IDS_Mess_LargeTimeWin,MB_ST); return 3;} if(be!=0) return 4;
nPh=nPoints/2; if(nPh>szFreqMax) { Message(IDS_Mess_LargeFreqArr,MB_ST); return 5;}

d=(double)(Snd.ln-1)*Snd.dt; nTime=GetUINT_Test(d/(double)Param.Time_Step); if(nTime==0) return 6;
if(nTime>szTimeMax) { Message(IDS_Mess_LargeTimeArr,MB_ST); return 7;}
dFr=(float)(1./(Snd.dt*(double)nPoints));

if(nTime>1) WinStep=d/(float)(nTime-1); else WinStep=0.0;

//aaa
if(SpectrAmp.Alloc(UINT nArr_,UINT ln_);

A=B=NULL; Weight=NULL; ber=0;
if(AllocComplex(&A,(size_t)nPoints)!=0) { ber=8; goto end;}
if(AllocComplex(&B,(size_t)nPoints)!=0) { ber=9; goto end;}
if(AllocFloat(&Weight,(size_t)nPh)!=0) { ber=10; goto end;}

// ���������� ������� ������� ����.
//aaa
if(Param.methSpFour!=methSpFour_NoWin) { v=Param.Time_Width*0.5F/(float)Snd.dt;
if(GetWeightWinSTFT(Param.methSpFour,Weight,nPh,v)!=0) { ber=11; goto end;}}

// ���� �� ��������� ������.
for(i=0;i<nTime;i++) { k=GetUINT_Test((double)i*WinStep/Snd.dt);
for(n=0;n<nPoints;n++) { iv=(SHRT)((int)n-(int)nPh); if(iv>=0) nv=iv; else nv=-iv;
l=(__int64)k+(__int64)iv; if(l<0||l>=Snd.ln) v=0.0F; else v=Snd.Snd[l];
if(Param.methSpFour!=methSpFour_NoWin) { if(nv<nPh) v*=Weight[nv]; else v=0.0F;}
A[n]=complex((double)v,0.);}

if(FastFT(A,B,M,1,1)!=0) { ber=12; goto end;}

for(n=0;n<nPh;n++) SpectrAmp[i][n]=(float)abs(B[n]);

// ���������� ������������ �����.
typNet=UCHAR_MAX; pSpL=SpLines[i];
be=FindPeaks(nPh,SpectrAmp[i],dFr,nPeaksMax,pSpL,&ParGetPeaks,&typNet,NULL);
if(be!=0||typNet!=typNNW_Vowel) { if(be!=0) nPeaks=0; else nPeaks=nPeaksCons;
for(j=nPeaks;j<nPeaksMax;j++) (pSpL+j)->Zero();}
nPeaks=0; for(j=0;j<nPeaksMax;j++) if((pSpL+j)->AmpRel!=0.0F) nPeaks++; ResPeaks[i]=nPeaks; // ������� ����� �����.

// ������������� ������� ��������� �����.
typSnd=0; numSnd=UCHAR_MAX;
if(DlgDBFNNW.IsDoTrain()==0)
be=RecognSoundNNW(SpectrAmp[i],nPh,dFr,&NNW_Vowel,&NNW_Cons,DecSnd_Instant,NULL,&numSnd,&typSnd,0); else be=messRet;
if(be!=0) numSnd=UCHAR_MAX; ResNNW[i]=numSnd;
//aaa
if(GetSymbSound(numSnd,typSnd,&Symb)!=0) Symb=' '; RowText[i]=Symb;
if(WinViewNNW.hwnd!=NULL) WinViewNNW.DrawNet(); // ����������� ����������� ����.

ShowProgress(hwndProgr,hwndPerc,i+1,nTime); ProcMess(); // ����������� �������� ���������� ������.
}

ShowProgress(hwndProgr,hwndPerc,0,0); ProcMess();

sz_Time=nTime; // ������ ��������� �� �������.
sz_Freq=nPh; // ������ ��������� �� �������.
st_Time=WinStep; // ��� �� ������� ��� ������������ ��������������.
st_Freq=dFr; // ��� �� ������� ��� ������������ ��������������.

end: FreeComplex(&A); FreeComplex(&B); FreeFloat(&Weight); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ������ � ����.

void clMain::ImageRowText(void)
{
char *cp;


//aaa
cp=""; if(SpectrAmp.nArr==0) goto end;

//if(sz_Time==0) goto end; if(sz_Time>=szTimeMax) goto end; 
RowText[sz_Time]='\0'; cp=RowText;
end: if(WinText.hwnd!=NULL) WinText.SetText(cp);
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� � ��������.

BYTE clSpLinesArr::Create(UINT nArr_,BYTE nSpL_)
{
UINT i;

Free(); if(nArr_==0) return 1; if(nSpL_==0) return 2; if(Create(nArr_)!=0) return 3;


return 0;
}

strSpectrLine SpLines[szTimeMax][nPeaksMax]
#define szTimeMax 20000 // ������������ ������ ������� ��������� �� �������.
#define szFreqMax 4096 // ������������ ������ ������� ��������� �� �������.

#define flOutRes_Peaks 0 // ����� ������������ �����.
#define flOutRes_Sound 1 // ����� ��������.

//#define flOutRes flOutRes_Peaks // ����� ������������ �����.
#define flOutRes flOutRes_Sound // ����� ��������.

// ����� ������������ �����.
//aaa
if(fl==flOutRes_Peaks) {
Res=ResPeaks[i];
if(Res==0) R=G=B=0; else {
numCol=(Res-1)/4; if(numCol>=6) numCol=5;
numInt=Res-1-numCol*4;
switch(numCol) { default:
case 0: R=1; G=B=0; break; // �������.
case 1: R=G=1; B=0; break; // Ƹ����.
case 2: R=0; G=1; B=0; break; // ������.
case 3: R=G=0; B=1; break; // �����.
case 4: R=0; G=B=1; break; // �������.
case 5: R=B=1; G=0; break; // ����������.
}
numInt=(BYTE)MIN(64*((USHRT)numInt+1),255);
R*=numInt; G*=numInt; B*=numInt;}
}

nPeaks=0; for(j=0;j<nPeaksMax;j++) if((pSpL+j)->AmpRel!=0.0F) nPeaks++; ResPeaks[i]=nPeaks; // ������� ����� �����.

ResPeaks[szTimeMax]

//if(WinViewNNW.hwnd!=NULL) WinViewNNW.DrawNet(); // ����������� ����������� ����.

//-----------------------------------------------------------------------------------------------------------
// ����������� ������ � ����.

BYTE clMain::SetWinText(char *Text)
{
char *cp;

//aaa
cp=""; if(SpectrAmp.nArr==0) goto end; RowText[]='\0'; cp=RowText;
end: if(WinText.hwnd!=NULL) WinText.SetText(Text);

char RowText[szTimeMax+1];

//-----------------------------------------------------------------------------------------------------------
// ������������� ������ ������� ��������� �����.

BYTE RecognSoundNNW(float *Spectr,UINT nSpectr,float dFr,strNNW *NNW_Vowel,strNNW *NNW_Cons,
pFunDecSnd DecSnd,PNT_DATA Pnt,BYTE *numSnd,BYTE *typSnd,BYTE flOut)
{
BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines,strParGetPeaks *PGP,
  BYTE *typNet,BYTE *flErr); // ���������� ������������� �������� � ������ ������������ �����.

BYTE j,nSpLMax,nPeaks,flNNW,num,typNet,flErr,typ,be,ber; struct strNNW *pNNW; struct strInpLay InpLay;
struct strLay *pLay; struct strSpectrLine *pSpL;

if(Spectr==NULL) return 1; if(nSpectr==0) return 2; if(dFr<=0.0F) return 3;
if(NNW_Vowel==NULL) return 4; if(NNW_Cons==NULL) return 5; if(DecSnd==NULL) return 6;
if(numSnd==NULL) return 7; if(typSnd==NULL) return 8;
nSpLMax=nPeaksMax; if(nSpLMax==0) return 9;

pSpL=NULL; ber=0;
if(InpLay.Alloc(nSpLMax)!=0) { ber=10; goto end;}
pSpL=new strSpectrLine[nSpLMax]; if(pSpL==NULL) { ber=11; goto end;}

// ���������� ������������ �����.
typNet=UCHAR_MAX;
be=FindPeaks(nSpectr,Spectr,dFr,nSpLMax,pSpL,&ParGetPeaks,&typNet,&flErr);
if(flOut!=0&&flErr!=0) { Message(IDS_ErrParFindPeaks,MB_ST);
sprintf(TxtStr,"Error: %d",flErr); MessageBox(NULL,TxtStr,"",MB_EX);}
if(be!=0||typNet>=nTypNNW) { nPeaks=0; for(j=0;j<nSpLMax;j++) (pSpL+j)->Zero();}
else { nPeaks=0; for(j=0;j<nSpLMax;j++) if((pSpL+j)->AmpRel!=0.0F) nPeaks++;}

// ������������� ������� ��������� �����.
flNNW=0; if(typNet>=nTypNNW) goto eNNW;
if(typNet==typNNW_Vowel) pNNW=NNW_Vowel; else pNNW=NNW_Cons; if(typNet!=pNNW->typ) goto eNNW;
if(pNNW==NULL) goto eNNW; if(pNNW->flOK==0) goto eNNW;
for(j=0;j<nSpLMax;j++) InpLay.Values[j]=pSpL[j].AmpRel; // ������� �������� �������.
if(pNNW->Compute(&InpLay)!=0) goto eNNW;
pLay=pNNW->Get(pNNW->nLay-1); if(pLay==NULL) goto eNNW; if(pLay->IsOK()!=0) goto eNNW;
if((*DecSnd)(Pnt,pLay,pNNW->typ,&typ,&num)!=0) goto eNNW;
flNNW=1;
eNNW: if(flNNW==0) *numSnd=*typSnd=UCHAR_MAX; else { *numSnd=num; *typSnd=typ;}

end: InpLay.Free(); SAFE_DELETE_ARR(pSpL); return ber;
}

#define FltAR_WidTime_Stand 0.085F // ������ ���������� ���� (�������), ����������� ��������.
#define FltAR_WidTime_Min 1.e-2F // ����������� ������ ���������� ���� (�������).
#define FltAR_StepTime_Stand 0.02F // ��� �� ������� (�������), ����������� ��������.
#define FltAR_StepTime_Min 1.e-2F // ��� �� ������� (�������), ����������� ��������.

Wid=FltAR_WidTime_Stand; Step=FltAR_StepTime_Stand; 

//aaa xxx
BYTE ProcAutoRegr(float *Signal,UINT nPoints,double dt,clSpDiag *Diag,float tWidth,float tStep,
  strParProcAR *ParAR,PNT_DATA Pnt,pFunShowProgr FSP,BYTE *flStop); // ��������� ����������������� �������.
be=ProcAutoRegr(Snd.Snd,Snd.ln,Snd.dt,&SpectrAmp,ParSpectr.Time_Width,ParSpectr.Time_Step,&ParProcAR,
(PNT_DATA)this,ShowProgrMain,&flStopProc); // ��������� ����������������� �������.

// ��������� ������� �� ��������� �������.
if(DlgDBFNNW.selDBS==NULL||DlgDBFNNW.flLoadFile==0||DlgDBFNNW.flBlkTime!=0) {
hPen=hPenP=NULL;
CrSelPen(hdc,&hPen,&hPenP,1,ColCursorDiag);
x=CoordTime-pScDiagH; MoveToEx(hdc,x,0,NULL); LineTo(hdc,x,dyW);
UnSelDelPen(hdc,&hPen,&hPenP);
}

if(ber!=0&&ber!=messRet) {
//mmm xxx
sprintf(TxtStr,"ber: %d",ber); MessageBox(NULL,TxtStr,"TrainNNW_Group",MB_EX);
}

if(be!=0) {
//mmm
sprintf(TxtStr,"StepFindAdaptStepGroup be: %d",be); MessageBox(NULL,TxtStr,"",MB_EX);
}

// xxx mmm
/*
if(pLay->Denom<SmCnst24_d) {
sprintf(TxtStr,"i,pLay->Denom,Wei: %d %lf %lf",i,pLay->Denom,Wei);
MessageBox(NULL,TxtStr,"strNNW::FindAdaptStepGroup",MB_EX);
}
*/

// xxx mmm
/*
if(Den==0.) {
sprintf(TxtStr,"Num,Den,Wei: %lf %lf %lf",Num,Den,Wei); MessageBox(NULL,TxtStr,"strLay::AddNumDenomAdaptStep",MB_EX);
}
*/
//xxx
/*
if(flAlpha!=0&&fabs(v)<SmCnst24_d) {
//mmm
sprintf(TxtStr,"j,Lay->n: %d %d Err,pNeur->Val,f: %lf %lf %lf",j,Lay->n,pNeur->Err,pNeur->Val,f);
MessageBox(NULL,TxtStr,"AddVectors: v<SmCnst24_d",MB_EX);
}
*/

//mmm aaa xxx
sprintf(TxtStr,"i: %d Denom: %lf",i,d); MessageBox(NULL,TxtStr,"strNNW::FindAlphaGroup d<SmCnst24_d",MB_EX);
#define coeWinWidGauss 2.0F // �����������, ��������������� ����� ���������� ���� ��� ������� ������.
v=; if(ParSpectr.methSpFour==methSpFour_Gauss) v*=coeWinWidGauss;

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ���� ��� ������ ����.

BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double *ValNeurPrev,BYTE nValNeurPrev,strLay *Lay,double *Alpha); // ������ ����������� ����.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // ������������� ����������� ����.

BYTE i,ber; double *Arr,Alpha; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->Neurons->IsOK()!=0) return 2;
Arr=NULL; ber=0;
Arr=new double[LayPrev->n]; if(Arr==NULL) { ber=3; goto end;}
for(i=0;i<LayPrev->n;i++) { pNeur=LayPrev->Get(i); if(pNeur==NULL) { ber=4; goto end;}
Arr[i]=pNeur->Val;}
if(ComputeAdaptStep_(Arr,LayPrev->n,Lay,&Alpha)!=0) { ber=5; goto end;}
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) { ber=6; goto end;}
end: SAFE_DELETE(Arr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ���� ��� ����, ���������� �� ��������.

BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double *ValNeurPrev,BYTE nValNeurPrev,strLay *Lay,double *Alpha); // ������ ����������� ����.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // ������������� ����������� ����.

double Alpha;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(ComputeAdaptStep_(LayPrev->Values,LayPrev->n,Lay,&Alpha)!=0) return 3;
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) return 4; return 0;
}

void ZeroVect(void); // ��������� ��������������� � ���������� ��� ��������.
void ZeroParVect(void); // ��������� ��������������� ��� ��������.
void FreeVect(void); // �������� ������� �������� �� ������.
BYTE AllocVect(BYTE nWeight_); // ��������� ������ ��� ������� ��������.
BYTE IsOK_Vect(void); // �������� ������� ��������.
BYTE SetZeroVect(void); // ��������� ����� � ������ ��������.

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������������� � ���������� ��� ��������.

void strNeuron::ZeroVect(void)
{
nWeightV=0; WeightV=NULL; ZeroParVect();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������������� ��� ��������.

void strNeuron::ZeroParVect(void)
{
TV=AlphaV=0.;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� �������� �� ������.

void strNeuron::FreeVect(void)
{
SAFE_DELETE_ARR(WeightV); nWeightV=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������� ��������.

BYTE strNeuron::AllocVect(BYTE nWeightV_)
{
FreeVect(); if(nWeightV_==0) return 1;
WeightV=new double[nWeightV_]; if(WeightV==NULL) return 2; nWeightV=nWeightV_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� ��������.

BYTE strNeuron::IsOK_Vect(void)
{
if(Vect.IsOK()!=0) return 1; if(nWeightV!=nWeight) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����� � ������ ��������.

BYTE strNeuron::SetZeroVect(void)
{
BYTE i;

TV=AlphaV=0.; if(IsOK_Vect()!=0) return 1; for(i=0;i<nWeightV;i++) WeightV[i]=0.; return 0;
}


//-----------------------------------------------------------------------------------------------------------
// ���� �������� ������� ���������� �������� ��� ���������� ����.

BYTE strNNW::TrainStepSequentLayOut(BYTE numNeurOut,strInpLay *InpLay_,float AlphaConst,
float AlphaMin,float AlphaMax,BYTE flAdaptSt)
{
BYTE CopyInpLay(strInpLay *Dst,strInpLay *Src); // ����������� ��������� �������� ���� ����.
BYTE SetErrLayEtal(BYTE numNeurOut,strLay *Lay); // ��������� ������ ������������ ��������� �������� ��� ���� ��������� ����.
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // ������ ����������� ���� ��� ������� �������� ���� 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // ������ ����������� ���� ��� ���� 'Lay'.
BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha); // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������ ��� ������� �������� ����.
BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha); // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������.
BYTE ComputeErr(strLay *LayPrev,strLay *Lay); // ������ ������ ������� ��������� ��������������� ������.
BYTE ComputeAdaptStepY(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,double *Alpha); // ������ ����������� ���� ��� ������� ��������� �������� ����.
BYTE CorrectY(BYTE numNeurOut,strLay *Lay,double Alpha); // ��������� �������� �������� �������� ����.

double Alpha;

if(InpLay_==NULL) return 1; if(InpLay_->IsOK()!=0) return 2; if(IsOK()!=0) return 3;
if(AlphaConst<=0.0F) return 4; if(AlphaMin<=0.0F) return 5; if(AlphaMax<=0.0F) return 6;
if(AlphaMax<AlphaMin) return 7;
if(CopyInpLay(&InpLay,InpLay_)!=0) return 8; // ��������� �������� ����.
if(ComputeTo(nLay-1)!=0) return 9; // ������ �� ���������� ����.
if(SetErrLayEtal(numNeurOut,Layers+nLay-1)!=0) return 10; // ��������� ������ ������������ ��������� �������� ��� ���� ��������� ����.

// ���������� � ��������� ����������� ���� ��� ������� ����� � �������.
if(flAdaptSt!=0) {
if(nLay==1) { if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax)!=0) return 11;}
else { if(ComputeAdaptStep(Layers+nLay-2,Layers+nLay-1,AlphaMin,AlphaMax)!=0) return 12;}}
if(flAdaptSt==0) Alpha=(double)AlphaConst; else Alpha=Layers[nLay-1].Alpha; // ��������� ����������� ����.

if(nLay==1) { if(CorrectWeightsFirst(&InpLay,Layers,Alpha)!=0) return 13;} // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������ ��� ������� �������� ����.
else { if(CorrectWeights(Layers+nLay-2,Layers+nLay-1,Alpha)!=0) return 14;} // ��������� ����� � ������� ��������� ����.

if(numLay==0) return 0;
if(ComputeErr(Layers+nLay-2,Layers+nLay-1)!=0) return 15; // ������ ������ ����������� ���� ������� ��������� ��������������� ������.

// ���������� � ��������� ����������� ���� ��� ������� ��������� ��������.
if(flAdaptSt==0) Alpha=(double)AlphaConst; // ��������� ����������� ����������� ����.
else { if(ComputeAdaptStepY(Layers+nLay-2,Layers+nLay-1,AlphaMin,AlphaMax,&Alpha)!=0) return 16;} // ������ ����������� ���� ��� ������� ��������� �������� ����.

if(CorrectY(numNeurOut,Layers+nLay-2,Alpha)!=0) return 17; // ��������� �������� �������� ���������� �������� ����.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� �������� ������� ���������� �������� ��� ������� ����.

BYTE strNNW::TrainStepSequentLay(BYTE numNeurOut,BYTE numLay,strInpLay *InpLay_,float AlphaConst,
float AlphaMin,float AlphaMax,BYTE flAdaptSt)
{
BYTE CopyInpLay(strInpLay *Dst,strInpLay *Src); // ����������� ��������� �������� ���� ����.
BYTE SetErrLayEtal(BYTE numNeurOut,strLay *Lay); // ��������� ������ ������������ ��������� �������� ��� ���� ��������� ����.
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // ������ ����������� ���� ��� ������� �������� ���� 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // ������ ����������� ���� ��� ���� 'Lay'.
BYTE ComputeErr(strLay *LayPrev,strLay *Lay); // ������ ������ ������� ��������� ��������������� ������.
BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha); // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������ ��� ������� �������� ����.
BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha); // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������.
BYTE ComputeAdaptStepY(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,double *Alpha); // ������ ����������� ���� ��� ������� ��������� �������� ����.
BYTE CorrectY(BYTE numNeurOut,strLay *Lay,double Alpha); // ��������� �������� �������� �������� ����.

double Alpha;

if(InpLay_==NULL) return 1; if(InpLay_->IsOK()!=0) return 2; if(IsOK()!=0) return 3;
if(numLay>=nLay-1) return 4;
if(AlphaConst<=0.0F) return 5; if(AlphaMin<=0.0F) return 6; if(AlphaMax<=0.0F) return 7;
if(AlphaMax<AlphaMin) return 8;
if(CopyInpLay(&InpLay,InpLay_)!=0) return 9; // ��������� �������� ����.
if(ComputeTo(numLay)!=0) return 10; // ������ �� ���� 'numLay'.
if(SetErrLayEtal(numNeurOut,Layers+numLay)!=0) return 11; // ��������� ������ ������������ ��������� �������� ��� ���� ��������� ����.

// ���������� � ��������� ����������� ���� ��� ������� ����� � �������.
if(flAdaptSt!=0) {
if(numLay==0) { if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax)!=0) return 12;}
else { if(ComputeAdaptStep(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax)!=0) return 13;}}
if(flAdaptSt==0) Alpha=(double)AlphaConst; else Alpha=Layers[numLay].Alpha; // ��������� ����������� ����.

if(numLay==0) { if(CorrectWeightsFirst(&InpLay,Layers,Alpha)!=0) return 14;} // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������ ��� ������� �������� ����.
else { if(CorrectWeights(Layers+numLay-1,Layers+numLay,Alpha)!=0) return 15;} // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������.

if(numLay==0) return 0;
if(ComputeErr(Layers+numLay-1,Layers+numLay)!=0) return 16; // ������ ������ ����������� ���� ������� ��������� ��������������� ������.

// ���������� � ��������� ����������� ���� ��� ������� ��������� ��������.
if(flAdaptSt==0) Alpha=(double)AlphaConst; // ��������� ����������� ����������� ����.
else { if(ComputeAdaptStepY(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax,&Alpha)!=0) return 17;} // ������ ����������� ���� ��� ������� ��������� �������� ����.

if(CorrectY(numNeurOut,Layers+numLay-1,Alpha)!=0) return 18; // ��������� �������� �������� ����������� �������� ����.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ��������� ������� �������� ��� ���� 'numLay' � ��������� ������� ������������� ��� ���������� ���� � ������ ���������� ��������.

BYTE strNNW::TrainStepSequentLayCorrect(BYTE numLay)
{
//xxx aaa
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� ������ ����������������� ���������� ��������.

BYTE strNNW::TrainStepSequentLay(BYTE numNeurOut,BYTE numLay,strInpLay *InpLay_,float AlphaConst,
float AlphaMin,float AlphaMax,USHRT nSteps,BYTE flAdaptSt)
{
BYTE ComputeLayer(strLay *LayPrev,strLay *Lay); // ������ �������� �������� � ���� "Lay".
BYTE SetErrLayEtal(BYTE numNeurOut,strLay *Lay); // ��������� ������ ������������ ��������� �������� ��� ���� ��������� ����.
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // ������ ����������� ���� ��� ������� �������� ���� 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // ������ ����������� ���� ��� ���� 'Lay'.
BYTE ComputeErr(strLay *LayPrev,strLay *Lay); // ������ ������ ������� ��������� ��������������� ������.
BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha); // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������ ��� ������� �������� ����.
BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha); // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������.
BYTE ComputeAdaptStepY(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,double *Alpha); // ������ ����������� ���� ��� ������� ��������� �������� ����.
BYTE CorrectY(BYTE numNeurOut,strLay *Lay,double Alpha); // ��������� �������� �������� �������� ����.

USHRT iStep; double Alpha; struct strLay *pLay,*pLayPrev;

if(InpLay_==NULL) return 1; if(InpLay_->IsOK()!=0) return 2; if(IsOK()!=0) return 3;
if(numLay>=nLay-1) return 4;
if(AlphaConst<=0.0F) return 5; if(AlphaMin<=0.0F) return 6; if(AlphaMax<=0.0F) return 7;
if(AlphaMax<AlphaMin) return 8; if(nSteps==0) return 9;
if(ComputeTo(numLay)!=0) return 10; // ������ �� ���� 'numLay'.
if(SetErrLayEtal(numNeurOut,Layers+numLay)!=0) return 11; // ��������� ������ ������������ ��������� �������� ��� ���� ��������� ����.
pLay=Get(numLay); if(pLay==NULL) return 12;
pLayPrev=Get(numLay-1); if(pLayPrev==NULL) return 13;

iStep=0;
rep:
if(iStep!=0&&numLay>0) {
// ������ �������� � ��������� ���� ������ �� ����������������� ��������� �������� ����������� ����.
if(pLayPrev->SetValEqualEtal(numNeurOut)!=0) return 14; // ��������� �������� ��������, ������ ��������� ��������� � ��������� ��������.
if(ComputeLayer(pLayPrev,pLay)!=0) return 15; // ������ �������� �������� � ���� "Lay".
}

//aaa xxx


// ���������� � ��������� ����������� ���� ��� ������� ����� � �������.
if(flAdaptSt!=0) {
if(numLay==0) { if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax)!=0) return 12;}
else { if(ComputeAdaptStep(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax)!=0) return 13;}}
if(flAdaptSt==0) Alpha=(double)AlphaConst; else Alpha=Layers[numLay].Alpha; // ��������� ����������� ����.

if(numLay==0) { if(CorrectWeightsFirst(&InpLay,Layers,Alpha)!=0) return 14;} // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������ ��� ������� �������� ����.
else { if(CorrectWeights(Layers+numLay-1,Layers+numLay,Alpha)!=0) return 15;} // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������.

if(numLay==0) return 0;
if(ComputeErr(Layers+numLay-1,Layers+numLay)!=0) return 16; // ������ ������ ����������� ���� ������� ��������� ��������������� ������.

// ���������� � ��������� ����������� ���� ��� ������� ��������� ��������.
if(flAdaptSt==0) Alpha=(double)AlphaConst; // ��������� ����������� ����������� ����.
else { if(ComputeAdaptStepY(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax,&Alpha)!=0) return 17;} // ������ ����������� ���� ��� ������� ��������� �������� ����.

if(CorrectY(numNeurOut,Layers+numLay-1,Alpha)!=0) return 18; // ��������� �������� �������� ����������� �������� ����.
iStep++; if(iStep<nSteps) goto rep;
return 0;
}


//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ��������� ���� ��������� ����.

BYTE SetErrOutLay(BYTE numNeurOut,strLay *Lay)
{
BYTE i; double tr; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2;
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(i==numNeurOut) tr=1.; else tr=0.; pNeur->Err=pNeur->Val-tr;}
return 0;
}
//-----------------------------------------------------------------------------------------------------------
// ���������� ������ ��������� ���� ��������.

BYTE FindErrOutLay(BYTE numNeurOut,strLay *Lay,double *pErr)
{
BYTE i; double v,sum,tr; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2; if(pErr==NULL) return 3;
sum=0.; for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(i==numNeurOut) tr=1.; else tr=0.;
v=pNeur->Val-tr; sum+=v*v;}
*pErr=sum/(double)Lay->n; return 0;
}

USHRT numOutLay; // ����� ������� ��������� ����.
pDT->numOutLay=(USHRT)num;

//-----------------------------------------------------------------------------------------------------------
// ��� ����� ������ ����������������� ���������� �������� - ������������� ����� � ������� ��� ���� 'numLay'.

BYTE strNNW::TrainStepSequentLayWeights(UINT numSample,BYTE numLay,float AlphaConst,float AlphaMin,float AlphaMax,
BYTE flAdaptSt)
{
BYTE SetErrLayEtal(UINT numSample,strLay *Lay); // ��������� ������ ������������ ��������� �������� ��� ���� ��������� ����.
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // ������ ����������� ���� ��� ������� �������� ���� 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // ������ ����������� ���� ��� ���� 'Lay'.
BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha); // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������ ��� ������� �������� ����.
BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha); // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������.

double Alpha;

if(IsOK()!=0) return 1; if(numLay>nLay-1) return 2;
if(AlphaConst<=0.0F) return 3; if(AlphaMin<=0.0F) return 4; if(AlphaMax<=0.0F) return 5;
if(AlphaMax<AlphaMin) return 6;

if(SetErrLayEtal(numSample,Layers+numLay)!=0) return 7; // ��������� ������ ������������ ��������� �������� ��� ���� ��������� ����.
//xxx aaa
// ���������� � ��������� ����������� ���� ��� ������� ����� � �������.
if(flAdaptSt!=0) {
if(numLay==0) { if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax)!=0) return 8;}
else { if(ComputeAdaptStep(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax)!=0) return 9;}}
if(flAdaptSt==0) Alpha=(double)AlphaConst; else Alpha=Layers[numLay].Alpha; // ��������� ����������� ����.

// ������������� ������� ������������� � �������.
if(numLay==0) { if(CorrectWeightsFirst(&InpLay,Layers,Alpha)!=0) return 10;} // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������ ��� ������� �������� ����.
else { if(CorrectWeights(Layers+numLay-1,Layers+numLay,Alpha)!=0) return 11;} // ������������� ������� ������������� � ������� ������� ��������� ��������������� ������.

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��� ����� ������ ����������������� ���������� �������� - ������������� ��������� �������� ��� ���� 'numLay-1'.

BYTE strNNW::TrainStepSequentLayEtal(UINT numSample,BYTE numLay,float AlphaConst,float AlphaMin,float AlphaMax,
BYTE flAdaptSt)
{
BYTE SetErrLayEtal(UINT numSample,strLay *Lay); // ��������� ������ ������������ ��������� �������� ��� ���� ��������� ����.
BYTE ComputeErr(strLay *LayPrev,strLay *Lay); // ������ ������ ������� ��������� ��������������� ������.
BYTE ComputeAdaptStepY(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,double *Alpha); // ������ ����������� ���� ��� ������� ��������� �������� ����.
BYTE CorrectY(UINT numSample,strLay *Lay,double Alpha); // ��������� �������� �������� �������� ����.

double Alpha;

if(IsOK()!=0) return 1; if(numLay>nLay-1) return 2; if(numLay==0) return 3;
if(AlphaConst<=0.0F) return 4; if(AlphaMin<=0.0F) return 5; if(AlphaMax<=0.0F) return 6;
if(AlphaMax<AlphaMin) return 7;

if(ComputeTo(numLay)!=0) return 8; // ������ �� ���� 'numLay'.
if(SetErrLayEtal(numSample,Layers+numLay)!=0) return 9; // ��������� ������ ������������ ��������� �������� ��� ���� ��������� ����.
if(ComputeErr(Layers+numLay-1,Layers+numLay)!=0) return 10; // ������ ������ ����������� ���� ������� ��������� ��������������� ������.

// ���������� � ��������� ����������� ���� ��� ������� ��������� ��������.
if(flAdaptSt==0) Alpha=(double)AlphaConst; // ��������� ����������� ����������� ����.
else { if(ComputeAdaptStepY(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax,&Alpha)!=0) return 11;} // ������ ����������� ���� ��� ������� ��������� �������� ����.

if(CorrectY(numSample,Layers+numLay-1,Alpha)!=0) return 12; // ��������� �������� �������� ����������� �������� ����.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��� ��������� ������� ����� � �������� ��� �������� ����� � ��������.

BYTE strNeuron::GetSetArrSearch(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet,BYTE flArr)
{
if(flArr==0) { if(GetSetArrWeight(Arr,szArr,nFill,flSet)!=0) return 1;}
else { if(GetSetArrVect(Arr,szArr,nFill,flSet)!=0) return 2;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��� ��������� ������� ����� � ��������.

BYTE strNeuron::GetSetArrWeight(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet)
{
USHRT i,nV;

if(Arr==NULL) return 1; if(szArr==0) return 2; if(nFill==NULL) return 3; if(IsOK()!=0) return 4;
nV=(USHRT)nWeights;
if(flSmart!=0) { if(nV>USHRT_MAX-(USHRT)nWeights) return 5; nV+=(USHRT)nWeights;}
if(flTUse!=0) { if(nV==USHRT_MAX) return 6; nV++;}
if(szArr<nV) return 7;

// ��������� ����� � ��������.
if(flSet==0) {
for(i=0;i<nWeights;i++) Arr[i]=Weights[i];
if(flSmart!=0) for(i=0;i<nWeights;i++) Arr[i+nWeights]=Shifts[i];
if(flTUse!=0) Arr[nV-1]=T;}

// ��������� ����� � ��������.
else {
for(i=0;i<nWeights;i++) Weights[i]=Arr[i];
if(flSmart!=0) for(i=0;i<nWeights;i++) Shifts[i]=Arr[i+nWeights];
if(flTUse!=0) T=Arr[nV-1];}

*nFill=nV; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��� ��������� ������� �������� ����� � ��������.

BYTE strNeuron::GetSetArrVect(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet)
{
USHRT i,nV;

//xxx aaa ���� - ���� ��������� ��� ����� � ��������.
if(Arr==NULL) return 1; if(szArr==0) return 2; if(nFill==NULL) return 3; if(IsOK_Vect()!=0) return 4;
nV=(USHRT)Vect.nWeights;
if(flSmart!=0) { if(nV>USHRT_MAX-(USHRT)nWeights) return 5; nV+=(USHRT)nWeights;}
if(flTUse!=0) { if(nV==USHRT_MAX) return 6; nV++;}
if(szArr<nV) return 7;

// ��������� ��������.
if(flSet==0) {
for(i=0;i<Vect.nWeights;i++) Arr[i]=Vect.Weights[i];
if(flSmart!=0) for(i=0;i<Vect.nWeights;i++) Arr[i+Vect.nWeights]=Vect.Shifts[i];
if(flTUse!=0) Arr[nV-1]=Vect.T;}

// ��������� ��������.
else {
for(i=0;i<Vect.nWeights;i++) Vect.Weights[i]=Arr[i];
if(flSmart!=0) for(i=0;i<Vect.nWeights;i++) Vect.Shifts[i]=Arr[i+Vect.nWeights];
if(flTUse!=0) Vect.T=Arr[nV-1];}

*nFill=nV; return 0;
}

BYTE GetSetArrWeight(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet); // ��������� ��� ��������� ������� ����� � ��������.
BYTE GetSetArrVect(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet); // ��������� ��� ��������� ������� �������� ����� � ��������.

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ���� ��� ���� 'Lay'.

BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double SumPrevLay,strLay *Lay,double *Alpha); // ������ ����������� ����.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // ������������� ����������� ����.

USHRT i; double Alpha,v,sum; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->Neurons->IsOK()!=0) return 2;
sum=0.; for(i=0;i<LayPrev->n;i++) { pNeur=LayPrev->Neurons+i; v=pNeur->Val; sum+=v*v;}
if(ComputeAdaptStep_(sum,Lay,&Alpha)!=0) return 3;
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ���� ��� ������� �������� ���� 'Lay'.

BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double SumPrevLay,strLay *Lay,double *Alpha); // ������ ����������� ����.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // ������������� ����������� ����.

USHRT i; double Alpha,v,sum;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
sum=0.; for(i=0;i<LayPrev->n;i++) { v=LayPrev->Values[i]; sum+=v*v;}
if(ComputeAdaptStep_(sum,Lay,&Alpha)!=0) return 3;
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ����.

BYTE ComputeAdaptStep_(double SumPrevLay,strLay *Lay,double *pAlpha)
{
BYTE typ,coe; USHRT i; double f1,f2,y,Gamma,Gam2,v; struct strNeuron *pNeur;

if(SumPrevLay<0.) return 1; if(Lay==NULL) return 2; if(Lay->IsOK()!=0) return 3; if(pAlpha==NULL) return 4;
typ=Lay->TypFunAct;

f1=f2=0.;
switch(typ) { default: return 5;
case TypFunAct_Sigm: // ���������� �������.
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur==NULL) return 6;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=y*(1.-y); f1+=Gam2*v; f2+=Gam2*v*v;}
coe=4; break;

case TypFunAct_BiSigm: // ���������� ���������� �������.
case TypFunAct_HypTan: // ��������������� �������.
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur==NULL) return 8;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=1.-y*y; f1+=Gam2*v; f2+=Gam2*v*v;}
if(typ==TypFunAct_BiSigm) coe=4; else coe=1; break;

case TypFunAct_Log: // ���������������.
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur==NULL) return 9;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=exp(y); v=2.*v/(1.+v*v); f1+=Gam2*v; f2+=Gam2*v*v;}
coe=1; break;

case TypFunAct_Lin: f1=f2=1.; coe=1; break; // ��������.
}

if(f2<=0.) return 10; *pAlpha=(double)coe*f1/((1.+SumPrevLay)*f2); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ���� ��� ���� 'Lay'.

BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double *ValNeurPrev,USHRT nValNeurPrev,strLay *Lay,double *Alpha); // ������ ����������� ����.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // ������������� ����������� ����.

BYTE ber; USHRT i; double Alpha,*Arr; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->Neurons->IsOK()!=0) return 2;
Arr=NULL; ber=0;
Arr=new double[LayPrev->n]; if(Arr==NULL) { ber=3; goto end;}
for(i=0;i<LayPrev->n;i++) { pNeur=LayPrev->Neurons+i; Arr[i]=pNeur->Val;}
if(ComputeAdaptStep_(Arr,LayPrev->n,Lay,&Alpha)!=0) { ber=4; goto end;}
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) { ber=5; goto end;}
end: SAFE_DELETE(Arr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ���� ��� ������� �������� ���� 'Lay'.

BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double *ValNeurPrev,USHRT nValNeurPrev,strLay *Lay,double *Alpha); // ������ ����������� ����.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // ������������� ����������� ����.

BYTE ber; USHRT i; double Alpha,*Arr;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
Arr=NULL; ber=0;
Arr=new double[LayPrev->n]; if(Arr==NULL) { ber=3; goto end;}
for(i=0;i<LayPrev->n;i++) Arr[i]=LayPrev->Values[i];
if(ComputeAdaptStep_(Arr,LayPrev->n,Lay,&Alpha)!=0) { ber=4; goto end;}
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) { ber=5; goto end;}
end: SAFE_DELETE(Arr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ����.

BYTE ComputeAdaptStep_(double *ValNeurPrev,USHRT nValNeurPrev,strLay *Lay,double *pAlpha)
{
BYTE typ,coe; USHRT i,j; double f1,f2,f3,y,Gamma,Gam2,v; struct strNeuron *pNeur;

if(ValNeurPrev==NULL) return 1; if(nValNeurPrev==0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4; if(pAlpha==NULL) return 5;
typ=Lay->TypFunAct;

f1=f2=f3=0.;
switch(typ) { default: return 6;
case TypFunAct_Sigm: // ���������� �������.
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur==NULL) return 7;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=y*(1.-y); f1+=Gam2*v; f2+=Gam2*v*v;}
coe=4; break;

case TypFunAct_BiSigm: // ���������� ���������� �������.
case TypFunAct_HypTan: // ��������������� �������.
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur==NULL) return 8;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=1.-y*y; f1+=Gam2*v; f2+=Gam2*v*v;}
if(typ==TypFunAct_BiSigm) coe=4; else coe=1; break;

case TypFunAct_Log: // ���������������.
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur==NULL) return 9;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=exp(y); v=2.*v/(1.+v*v); f1+=Gam2*v; f2+=Gam2*v*v;}
coe=1; break;

case TypFunAct_Lin: f1=f2=1.; coe=1; break; // ��������.
}

//xxx aaa
if(f2<=0.) return 10; *pAlpha=(double)coe*f1/((1.+SumPrevLay)*f2); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ������� ��������� ���������� ���������. ���������������.

double FunDerAct_Log(double y)
{
double aM,v;

aM=IPE_MAX; if(y>=-aM&&y<=aM) { v=exp(y); v=(v-1./v)*0.5; v=1./sqrt(v*v+1.);} else v=0.; return v;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ����.

BYTE ComputeAdaptStep_(double SumPrevLay,strLay *Lay,double *pAlpha)
{
BYTE GetCoeDeriv(BYTE typ,double *coe); // ��������� ������������ ��� ���������� ����������� � ������ ���������.

BYTE typ,coe; USHRT j; double f1,f2,f,Gamma,Gam2; pFunDerAct FunDerAct; struct strNeuron *pNeur;

if(SumPrevLay<0.) return 1; if(Lay==NULL) return 2; if(Lay->IsOK()!=0) return 3; if(pAlpha==NULL) return 4;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 5;
if(GetCoeDeriv(Lay->TypFunAct,&coe)!=0) return 6;
f1=f2=0.;
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; f=FunDerAct(pNeur->Val); Gamma=pNeur->Err; Gam2=Gamma*Gamma;
f1+=Gam2*f; f2+=Gam2*f*f;}
if(f2<=0.) return 7; *pAlpha=(double)coe*f1/((1.+SumPrevLay)*f2); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������� �������� ��� �������� ���� ��� ��������� ��������.

BYTE AddVectors(strLay *LayPrev,strLay *Lay,double Wei,BYTE flAlpha)
{
USHRT i,j; double f,v,coeA,*pw,*ps; pFunDerAct FunDerAct; struct strNeuron *pNeur,*pNeurPr;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 5;

if(flAlpha!=0) { coeA=0.;
//xxx aaa
for(i=0;i<LayPrev->n;i++) { pNeurPr=LayPrev->Neurons+i; v=pNeurPr->Val; coeA+=v*v;} coeA+=1.;}

// ���� �� "j" - ���������� ��� ������� ������� ���� "Lay".
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur->IsOK_Vect()!=0) return 6;
if(pNeur->Vect.nWeights!=LayPrev->n) return 7;
f=FunDerAct(pNeur->Val); v=pNeur->Err*f*Wei; if(pNeur->flTUse!=0) pNeur->Vect.T+=v;
if(flAlpha!=0) pNeur->Vect.Alpha+=v*coeA;

// ���� �� "i" - ���������� ������� ����������� ���� "LayPrev".
if(pNeur->flSmart==0)
// ������������ � ������ �������� ��� �����.
for(i=0;i<LayPrev->n;i++) { pNeurPr=LayPrev->Neurons+i; pNeur->Vect.Weights[i]-=pNeurPr->Val*v;}
else
// ������������ � ������� �������� ��� ����� � ��������.
for(i=0;i<LayPrev->n;i++) { pNeurPr=LayPrev->Neurons+i;
pNeur->Vect.Weights[i]-=(pNeurPr->Val-pNeur->Shifts[i])*v;
pNeur->Vect.Shifts[i]+=pNeur->Weights[i]*v;}
}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������� �������� ��� �������� ������� �������� ���� ��� ��������� ��������.

BYTE AddVectorsFirst(strInpLay *LayPrev,strLay *Lay,double Wei,BYTE flAlpha)
{
USHRT i,j; double f,v,coeA,*pw,*ps; pFunDerAct FunDerAct; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 5;

//xxx aaa
if(flAlpha!=0) { coeA=0.; for(i=0;i<LayPrev->n;i++) { v=LayPrev->Values[i]; coeA+=v*v;} coeA+=1.;}

// ���� �� "j" - ���������� ��� ������� ������� ���� "Lay".
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur->IsOK_Vect()!=0) return 6;
if(pNeur->Vect.nWeights!=LayPrev->n) return 7;
f=FunDerAct(pNeur->Val); v=pNeur->Err*f*Wei; if(pNeur->flTUse!=0) pNeur->Vect.T+=v;
if(flAlpha!=0) pNeur->Vect.Alpha+=v*coeA;

// ���� �� "i" - ���������� ������� ����������� ���� "LayPrev".
// ���������� ������� �������� ��� �����.
if(pNeur->flSmart==0) for(i=0;i<LayPrev->n;i++) pNeur->Vect.Weights[i]-=LayPrev->Values[i]*v;
else
// ���������� ������� �������� ��� ����� � ��������.
for(i=0;i<LayPrev->n;i++) { pw=pNeur->Vect.Weights+i; ps=pNeur->Vect.Shifts+i;
pNeur->Vect.Weights[i]-=(LayPrev->Values[i]-pNeur->Shifts[i])*v;
pNeur->Vect.Shifts[i]+=pNeur->Weights[i]*v;}
}
return 0;
}

#define flagStrFormAdaptGroup 1 // ������ ������� ��� ������� ����������� ���� ��� ��������� ������� ��������.

//xxx aaa
//-----------------------------------------------------------------------------------------------------------
// ��� ���������� ���� ��� ���������� ����������� ���� ��� �������� ��������� �������.

BYTE strLay::AddNumDenomAdaptStep(double Wei)
{
USHRT i; double Num,Den,f,v; pFunDerAct FunDerAct; struct strNeuron *pNeur;

if(IsOK()!=0) return 1; FunDerAct=GetFunDerAct(TypFunAct); if(FunDerAct==NULL) return 2;
Num=Den=0.; for(i=0;i<n;i++) { pNeur=Get(i); if(pNeur==NULL) return 3;
f=FunDerAct(pNeur->Val); v=pNeur->Vect.Alpha*f; Num+=pNeur->Err*v; Den+=v*v;}
Numer+=Num*Wei; Denom+=Den*Wei; return 0;
}

BYTE ComputeAdaptStepFrom(BYTE layIni,float AlphaMin,float AlphaMax); // ������ ������� ����������� ���� ������� �� ���� 'layIni'.

//-----------------------------------------------------------------------------------------------------------
// ������ ����������� ���� ������� �� ���� 'layIni'.

BYTE strNNW::ComputeAdaptStepFrom(BYTE layIni,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // ������ ����������� ���� ��� ������� �������� ���� 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // ������ ����������� ���� ��� ���� 'Lay'.

BYTE i,in;

if(AlphaMin<0.0F) return 1; if(AlphaMax<=0.0F) return 2; if(AlphaMax<AlphaMin) return 3;
if(Layers->IsOK()!=0) return 4; if(InpLay.IsOK()!=0) return 5; if(layIni>nLay-1) return 6;
if(layIni==0) { in=1; if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax)!=0) return 7;} else in=layIni;
if(in<nLay) for(i=in;i<nLay;i++) { if(ComputeAdaptStep(Layers+i-1,Layers+i,AlphaMin,AlphaMax)!=0) return 8;}
return 0;
}
//aaa xxx yyy 
for(i=0;i<nPoints;i++) Signal[i]-=SigAR[i];

// IDC_AXONS ................................................................................................
case IDC_AXONS: SetFlagAxons(1-flAmpAxons); break;

//xxx aaa
//xxx aaa
SetTxtBtnAmpAxons(); // ��������� ������ � ������ ����������� ��������� ����������� �������.

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ � ������ ����������� ��������� ����������� �������.

void clWinViewNNW::SetTxtBtnAmpAxons(void)
{
int idS; char *cp;

if(hDlg==NULL) return; if(hInst==NULL) return;
if(flAmpAxons==0) idS=IDS_BtnNNWAxons_Excit; else idS=IDS_BtnNNWAxons_Amp;
if(LoadString(hInst,idS,TxtStr,strL_Txt)!=0) cp=TxtStr; else cp="-";
SetDlgItemText(hDlg,IDC_AXONS,TxtStr);
}


//-----------------------------------------------------------------------------------------------------------
// ��������� ����� ����������� ����������� �������.

void clWinViewNNW::SetFlagAxons(BYTE flAmpAxons_)
{
if(flAmpAxons==flAmpAxons_) return; flAmpAxons=flAmpAxons_; SetTxtBtnAmpAxons(); DrawNet();
}


//xxx aaa
v=(float)pNeur->Weights[i]; if(flExcit!=0&&flInpLay!=0) { if(i<InpLay.n) v*=(float)InpLay.Values[i]; else v=0.0F;}

void SetFlagAxons(BYTE flAmpAxons_); // ��������� ����� ����������� ����������� �������.

//xxx aaa
if(ns!=szArr) {
//mmm
sprintf(TxtStr,"ns,szArr: %d %d",ns,szArr); MessageBox(NULL,TxtStr,"",MB_EX);

}

//xxx aaa mmm
//mmm
sprintf(TxtStr,"i,nN,nP: %d %d %d nA,n: %d %d",i,nN,nP,nA,n); MessageBox(NULL,TxtStr,"GetNumVectParNNW",MB_EX);

//-----------------------------------------------------------------------------------------------------------
// ������ �� ���� 'layFin'.

BYTE strNNW::ComputeTo(BYTE layFin)
{
BYTE ComputeLayerFirst(strInpLay *LayPrev,strLay *Lay); // ������ �������� �������� � ���� "Lay" - ������ ������� ����.
BYTE ComputeLayer(strLay *LayPrev,strLay *Lay); // ������ �������� �������� � ���� "Lay".

BYTE i;

if(IsOK()!=0) return 1; if(layFin>nLay-1) return 2;
if(ComputeLayerFirst(&InpLay,Layers)!=0) return 3; if(layFin==0) return 0;
for(i=1;i<=layFin;i++) if(ComputeLayer(Layers+i-1,Layers+i)!=0) return 4; return 0;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ��������� �����.

#define nTypNNW 2 // ����� ����� ��������� �����.

#define typNNW_Vowel 0 // ��� ������� � �������� ������.
#define typNNW_Cons  1 // ��� ��������� �������� � ������� ������.

//mmm xxx aaa
sprintf(TxtStr,"i,numSnd,typSnd: %d %d %d",i,numSnd,typSnd);
MessageBox(NULL,TxtStr,"clMain::RecognNNW_All",MB_EX);

hr=SHGetFolderPath(NULL,CSIDL_SYSTEM,NULL,0,Path);
//mmm aaa xxx
sprintf(TxtStr,"%s",Path); MessageBox(NULL,TxtStr,"clMain::OpenProgFiles",MB_IN);

if(FAILED(hr)) { ber=3; goto end;}

dxMin=GetUSHRT_Test((int)(rc.right-rc.left)+GetSystemMetrics(SM_CXDLGFRAME)*2);
dyMin=GetUSHRT_Test((int)(rc.bottom-rc.top)+GetSystemMetrics(SM_CYDLGFRAME)*2+GetSystemMetrics(SM_CYCAPTION));

//-----------------------------------------------------------------------------------------------------------
// ����������� �������� ���������� ������.

void ShowProgress(HWND hwndProgr,UINT p,UINT pMax)
{
BYTE GetBYTE(float v); // ��������� ����� 'BYTE' �� ����� 'float' � ��������� ������ �� ������� 'BYTE'.

BYTE Perc;

if(pMax==0) { SendMessage(hwndProgr,PBM_SETPOS,0,0L); return;}
if(p>=pMax) Perc=100; else Perc=GetBYTE((float)p/(float)pMax*100.0F);
if(hwndProgr!=NULL) SendMessage(hwndProgr,PBM_SETPOS,(WPARAM)Perc,0L);
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ������.

#define flagTurnOffComp 1 // ���� ���������� ����������.

#if flagTurnOffComp==0
ExitWindowsEx(EWX_LOGOFF,0);
#else
SendMessage(NULL,WM_CLOSE,0,0L);
#endif
break;

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� �������� �������.

BYTE CorrFreq(strParFreqCorr *PFC,BYTE typNNW,strInpLay *InpLay)
{
USHRT i,j; double coe,amp,ampF;

if(PFC==NULL) return 1; if(PFC->IsOK()!=0) return 2;
if(InpLay==NULL) return 3; if(InpLay->IsOK()!=0) return 4;

switch(typNNW) { default: break;
// ������� � �������� �����.
case typNNW_Vowel:
coe=PFC->CorrDB/(double)(PFC->numFin-PFC->numIni)/20.; ampF=pow(10.,PFC->CorrDB/20.);
for(i=0;i<InpLay->n;i++) { if(i<=PFC->numIni) continue;
if(i>=PFC->numFin) amp=ampF; else amp=pow(10.,coe*(double)(i-PFC->numIni)); InpLay->Values[i]*=amp;}
break;
// ��������� ���������� � ������� �����.
case typNNW_Cons: if(InpLay->n<=nPeaksCons) return 5;
coe=PFC->CorrDB/(double)(PFC->numFin-PFC->numIni)/20.; ampF=pow(10.,PFC->CorrDB/20.);
for(j=nPeaksCons;j<InpLay->n;j++) { i=j-nPeaksCons; if(i<=PFC->numIni) continue;
if(i>=PFC->numFin) amp=ampF; else amp=pow(10.,coe*(double)(i-PFC->numIni)); InpLay->Values[j]*=amp;}
break;
// ���������� ��������� ����� ����� ��� ����� �������.
case typNNW_Spectr: return messRet; break;
}
return 0;
}

����������
256701

// IDC_FREQ_CORR ............................................................................................
case IDC_FREQ_CORR: 
//xxx aaa
break;

// IDC_NUM_INI ..............................................................................................
case IDC_NUM_INI: break;

// IDC_NUM_FIN ..............................................................................................
case IDC_NUM_FIN: break;

// IDC_FR_CORR_DB ...........................................................................................
case IDC_FR_CORR_DB: break;

//xxx aaa if(pPar!=NULL) pPar->FreqCorrPeaks.SetDlg(hDlg);
//xxx aaa if(pPar!=NULL) pPar->FreqCorrPeaks.GetDlg(hDlg);
//xxx aaa
#define StepTriFunSpectr 200.0F 

if(FreqCorrect()!=0) return 3; // ��������� ��������� �������� �������.

/* xxx aaa
//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� �������� �������.

BYTE strNNW::FreqCorrect(float dFr)
{
if(Par.flFrCorr==0) return 0;

// ��������� ��������� ������� ������ �� ������������ ������.
if(Par.flTypInpData==typDataNNW_Peaks) {
if(Par.FreqCorrPeaks.Correct(typ,Par.nPCons,&InpLay)!=0) return 1;}
// ��������� ��������� ������� ������ �� �������.
else { if(Par.FreqCorrSpectr.Correct(InpLay->n,InpLay->Values,dFr)!=0) return 2;}
return 0;
}
*/

BYTE Correct(BYTE typNNW,BYTE nPCons,strInpLay *InpLay); // ��������� ���������.
BYTE Correct(USHRT nSpectr,double *Spectr,float dFr); // ��������� ���������.

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������.

BYTE strParFreqCorrPeaks::Correct(BYTE typNNW,BYTE nPCons,strInpLay *InpLay)
{
USHRT i,j; double coe,amp,ampF;

if(IsOK()!=0) return 1; if(InpLay==NULL) return 2; if(InpLay->IsOK()!=0) return 3;
coe=CorrDB/(double)(numFin-numIni)/20.; ampF=pow(10.,CorrDB/20.);

switch(typNNW) { default: return 4;
// ������� � �������� �����.
case typNNW_Vowel:
for(i=0;i<InpLay->n;i++) { if(i<=numIni) continue;
if(i>=numFin) amp=ampF; else amp=pow(10.,coe*(double)(i-numIni)); InpLay->Values[i]*=amp;}
break;
// ��������� ���������� � ������� �����.
case typNNW_Cons: if(InpLay->n<=nPCons) return 5;
for(j=nPCons;j<InpLay->n;j++) { i=j-nPCons; if(i<=numIni) continue;
if(i>=numFin) amp=ampF; else amp=pow(10.,coe*(double)(i-numIni)); InpLay->Values[j]*=amp;}
break;
}
return 0;
}
//-----------------------------------------------------------------------------------------------------------
// ��������� ���������.

BYTE strParFreqCorrSpectr::Correct(USHRT nSpectr,double *Spectr,float dFr)
{
USHRT i,nFrMin,nFrMax; double coe,amp,ampF;

if(nSpectr==0) return 1; if(Spectr==NULL) return 2; if(dFr<=0.0F) return 3; if(CorrDB==0.0F) return 0;
nFrMin=GetUSHRT_Test(FrIni/dFr); if(nFrMin>=nSpectr) return 0;
nFrMax=GetUSHRT_Test(FrFin/dFr); nFrMax=MAX(nFrMax,nFrMin); nFrMax=MIN(nFrMax,nSpectr);
if(nFrMax>nFrMin) coe=CorrDB/(double)(nFrMax-nFrMin)/20.; else coe=0.; ampF=pow(10.,CorrDB/20.);
for(i=0;i<nSpectr;i++) { if(i<=nFrMin) continue;
if(i>=nFrMax) { amp=ampF; goto e;} if(coe>0.) amp=pow(10.,coe*(double)(i-nFrMin)); else continue;
e: Spectr[i]*=amp;}
return 0;
}

//mmm zzz xxx aaa
sprintf(TxtStr,"RecognSoundNNW: numSnd,typSnd,be: %d %d %d",numSnd,typSnd,be);
MessageBox(NULL,TxtStr,"clMain::RecognNNW",MB_EX);

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE clInpLayArr::Alloc(UINT nData_,USHRT n_)
{
BYTE ber; UINT i;

Free(); if(nData_==0) return 1; if(n_==0) return 2; ber=0; nData=nData_; n=n_;
Data=new strInpLay[nData]; if(Data==NULL) { ber=3; goto end;}
for(i=0;i<nData;i++) if(Data[i].Alloc(n)!=0) { ber=4; goto end;}
end: if(ber!=0) Free(); return ber;
}

//for(k=0;k<nInp;k++) pIL->Values[k]=(double)SpL[k].AmpRel;

//xxx aaa mmm
/*
if(ResTriFun((USHRT)pFlArr->ln,pFlArr->Arr,(float)Diag.stLn,ParInpSp.FreqDiscrTri,ParInpSp.FreqMin,
ParInpSp.FreqMax,ParInpSp.AmpThr,pIL)!=0) { ber=100; goto end;} // ���������� ������� �� ����������� ��������.
*/

//xxx aaa
nFrMin=GetUSHRT_Test(ParInpSp.FreqMin/(float)Diag.stLn); if(nFrMin==0||nFrMin>nInp) { ber=100; goto end;}
if(pFlArr->ln!=nInp) { ber=101; goto end;}
s=0.; for(j=nFrMin;j<nInp;j++) { v=pFlArr->Arr[j]; s+=POW2D(v);} s/=(double)(nInp-nFrMin); s=SQRT(s);
if((float)s<ParInpSp.AmpThr) { for(j=0;j<nInp;j++) pIL->Values[j]=0.; goto eInpSp;}
v=1.0F/(float)s;
for(j=0;j<nFrMin;j++) pIL->Values[j]=0.;
for(j=nFrMin;j<nInp;j++) pIL->Values[j]=(double)(pFlArr->Arr[j]*v);
eInpSp:;

// ��������� ����� ������� �������� ����.
if(GetNInpDataNet(typInp,typ,pParNNW->Par.FreqMax,dFr,pParNNW->Par.dFrTri,nPeaksCons,&nInp)!=0) return 6;

if(id==IDC_SAVE_AS_NNW_VOWEL) fl=typNNW_Vowel; else fl=typNNW_Cons; 
//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strWordDict::Read(FILE *file)
{
BYTE i; int iv;

//xxx aaa
if(file==NULL) return 1; FreeTranscr();
if(ReadString(file,TxtStr,strL_Txt)!=0) return 2;
if(DupString(&Word,TxtStr)!=0) return 3;
if(fscanf(file,"%d",&iv)==EOF) return 4; if(iv<=0) return 5; if(iv>UCHAR_MAX) return 6;
if(AllocTranscr((BYTE)iv)!=0) return 7;
for(i=0;i<nTranscr;i++) if(ReadString(file,TxtStr,strL_Txt)!=0) return 8;
if(DupString(Transcr+i,TxtStr)!=0) return 9;}
return 0;
}

flLevTrueFalse=0; levTrue=levTrue_Stand; levFalse=levFalse_Stand;
if(levTrue>1.0F) return 8; if(levFalse<0.0F) return 9; if(levTrue<=levFalse) return 10; 
fp=&levTrue;
v=1.0F; if(*fp>v) { *fp=v; fl+=1<<9;}
v=levTrue_Min; if(*fp<v) { *fp=v; fl+=1<<10;}
fp=&levFalse;
if(*fp<0.0F) { *fp=0.0F; fl+=1<<11;}
v=levFalse_Max; if(*fp>v) { *fp=v; fl+=1<<12;}

if(fscanf(file,"%d%f%f",&iv,&levTrue,&levFalse)==EOF) return 12; bp=&flLevTrueFalse; if(iv==0) *bp=0; else *bp=1;
(int)flLevTrueFalse,levTrue,levFalse
SetChBox(hDlg,IDC_TRUE_FALSE_LEV,flLevTrueFalse);
SetFlEdt(hDlg,IDC_LEV_TRUE,levTrue,FormCoeff);
SetFlEdt(hDlg,IDC_LEV_FALSE,levFalse,FormCoeff);
GetChBox(hDlg,IDC_TRUE_FALSE_LEV,&flLevTrueFalse);
GetFlEdt(hDlg,IDC_LEV_TRUE,&levTrue);
GetFlEdt(hDlg,IDC_LEV_FALSE,&levFalse);
#define levTrue_Stand 0.95F // ������� ��� ���������� �������� - ����������� ��������.
#define levTrue_Min 0.9F // ������� ��� ���������� �������� - ����������� ��������.
#define levFalse_Stand 0.05F // ������� ��� ������������ �������� - ����������� ��������.
#define levFalse_Max 0.1F // ������� ��� ������������ �������� - ����������� ��������.
BYTE flLevTrueFalse; // ���� ������������ �������� �������� ��� ���������� � ������������ ��������.
float levTrue; // ������� ��� ���������� ��������.
float levFalse; // ������� ��� ������������ ��������.
double levT,levF;
if(ParTrain.flLevTrueFalse==0) { levT=1.; levF=0.;}
else { levT=(float)ParTrain.levTrue; levF=(float)ParTrain.levFalse;}
