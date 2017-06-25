/*...........................................................................................................

// ������������ ���������.
FastFT,GetN,GetN_,
GetWeightWinSTFT,
GetWeightWinCosHann,GetWeightGauss,GetWeightHamming,GetWeightBlackman,GetWeightBlackmanHarris,GetWeightNatall,
GetWeightBlackmanNatall,GetWeightFlatTop,GetWeightBarlett,GetWeightBarlettHann,GetWeightLanczos,
GetWeightKaiserBess,GetBesselI0,

// ��������� ���������� ������������ ���������.
struct strParSpProc { strParSpProc,IsOK},

// ��������� �������.
struct strNeuron {
strNeuron,~strNeuron,
Zero,ZeroPar,Free,Alloc,IsOK,
Read,Write},

// ��������� ���� ��������.
struct strLay {
strLay,~strLay,Zero,InitPar,Free,Alloc,IsOK,Get,Read,AllocWeights},

// ��������� �������� ���� ��������.
struct strInpLay {
strInpLay,~strInpLay,Zero,Free,Alloc,IsOK,Get},
CopyInpLay,

// ��������� ��������� ��������� �������.
struct strParFreqCorrSpectr { strParFreqCorrSpectr,Init,IsOK,Check,Read},
FreqCorrSpectr,

// ��������� ������� � ���������� ��������� ����.
struct strPropNNW { strPropNNW,Init,Read},

// ��������� ���� ��������� ����.
struct strNNW {
strNNW,~strNNW,Zero,Free,Alloc,IsOK,IsOK_Lay,Get,GetOutLay,Read,Read_,Read,Compute,Compute_,FreqCorrect},

// ������� ��� �������� ������� ������������� ��������� �����.
ComputeLayer,ComputeLayerFirst,
GetFunAct,FunAct_Sigm,FunAct_BiSigm,FunAct_HypTang,FunAct_Log,FunAct_Lin,

// ������� ��� ������������ ������� �������� � �������������.
RecognSoundNNW_Sp,InputDataNetSp,InpSpectrRow,
DecSnd_Instant,

// ��������� ���������� ��� ������� ������ ������ ��� �����.
struct strParAnSnd { IsOK},

// ��������� ��� ������� ������ ������ ��� �����.
struct strAnSnd {
strAnSnd,~strAnSnd,Zero,Free,Init,IsOK,Start,Step},

// ��������� ��� ������� ������ ������ ��� ���������� ������.
struct strAnSndArr {
strAnSndArr,~strAnSndArr,Zero,Free,Clear,Create,IsOK,Init,Start,Step},

// ��������� ��� ������� ������ ������.
struct strAnalyseSound { Init,Start,Step},

// ��������� ��� ������������� ������ �������.
struct strRecSymb { strRecSymb,Zero,Init,IncCntSymb},

// ��������� ��� ������� ������ ������.
struct strAnalyseData { strAnalyseData,Init,Reset,GetSymb},

// ��������������� ���������.
GetNumSound,GetSymbSound,GetOutArr,

// ��������� ����� � �������.
struct strWordDict {
strWordDict,~strWordDict,Zero,Free,
ZeroTranscr,FreeTranscr,ClearTranscr,AllocTranscr,IsOK_Transcr,
Get,Read};

// ��������� �������.
struct strDictionary {
strDictionary,~strDictionary,Zero,Free,Alloc,IsOK,Get,GetWord,Read,Read_,Read};

// ��������� ��� ������������� ������������ �����.
struct strRecognTranscr { strRecognTranscr,Zero,Init,Start,Step},

// ��������� ��� ������������� �����.
struct strRecognWord {
strRecognWord,~strRecognWord,Zero,ZeroRT,FreeRT,AllocRT,IsOK_RT,Init,Start,Step},

// ��������� ��� ������������� ����.
struct strRecognAllWords {
strRecognAllWords,~strRecognAllWords,Zero,Free,Alloc,IsOK,Init,Start,Step}

...........................................................................................................*/

#include "stdafx.h"

#include "VC_con.h"
#include "cmplx.h"
#include "VC_pro.h"
#include "VC_cls.h"
#include "resource.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������.

BYTE AllocString(char **Str,size_t ln); // ��������� ������ ��� ������.
void FreeString(char **Str); // ������������ ������ ��� ������.
BYTE AllocPString(char ***pStr,BYTE n); // ��������� ������ ��� ������� ���������� �� char.
BYTE IsOKStr(char *str); // �������� ������.
BYTE DupString(char **Str,char *Src); // ��������� ������ ��� ������ � �����������.
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // ��������� ����� ����� ������� ����.
BYTE GetBYTE(float v); // ��������� ����� 'BYTE' �� ����� 'float' � ��������� ������ �� ������� 'BYTE'.
USHRT GetUSHRT_Test(float v); // ��������� ����� 'USHRT' �� ����� 'float' � ��������� ������ �� ������� 'USHRT'.
USHRT GetUSHRT_Test(double d); // ��������� ����� 'USHRT' �� ����� 'double' � ��������� ������ �� ������� 'USHRT'.
pFunAct GetFunAct(BYTE Typ); // ������� ������ ������� ��������� ��������� ���������.
void Message(UINT StrID,UINT typ); // ����� ���������.
void ProcMess(void); // ����� ������� ��������� � ��������� ���������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� ������ � ���������.

extern struct strParAnSnd ParAnSnd[nVoices]; // ��������� ���������� ��� ������� ������ ������ ��� �����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� ����������.

extern HINSTANCE hInst; // ������������� ����������.

extern char TxtStr[strL_Txt],TxtMem[strL_Txt]; // ��������������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������.

extern char *dirParNNW; // ���������� � ������� ���������� ��������� �����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� ������.

extern char *extParNNW_Vowel,*extParNNW_Cons,*extParNNW_Spectr; // ���������� ������ ���������� ��������� �����.
extern char *extNNW_Vowel,*extNNW_Cons,*extNNW_Spectr; // ���������� ������ ��������� �����.

//-----------------------------------------------------------------------------------------------------------
// ������� �������������� �����.

BYTE FastFT(complex *A,complex *B,BYTE M,SCHAR dir,BYTE prcMess)
{
BYTE l; int i,j,k,n,le,leW,ip,N; double d,vd; complex U,W,T;

if(A==NULL) return 1; if(B==NULL) return 2; if(M==0) return 3; if(M>=31) return 4;
N=1<<M; n=N/2;
if(dir>=0) { d=1./(double)N; for(i=0;i<N;i++) *(B+i)=*(A+i)*complex(d,0.);}
else for(i=0;i<N;i++) *(B+i)=*(A+i);

j=1; for(i=0;i<N-1;i++) { if(i<j-1) { T=*(B+j-1); *(B+j-1)=*(B+i); *(B+i)=T;}
k=n; b: if(k>=j) goto a; j-=k; k=k/2; goto b; a: j+=k;}
for(l=0;l<M;l++) { if(prcMess!=0) ProcMess(); le=1<<(l+1); leW=le/2;
U=complex(1.,0.); vd=M_PI/(double)leW; d=sin(vd); if(dir<0) d=-d; W=complex(cos(vd),d);
for(j=0;j<leW;j++) { for(i=j;i<N;i+=le) { ip=i+leW; T=*(B+ip)*U; *(B+ip)=*(B+i)-T; *(B+i)+=T;} U*=W;}}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� 'N' - 2 � ������� 'M'.

BYTE GetN(BYTE M,USHRT *N)
{
if(N==NULL) return 1; if(M==0||M>=16) return 2; *N=1<<M; if(*N<2) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��� ����������� ����� 'Np', ���������� 2 � ����� �������, ������� ��������� 'nPoints'.
// ����� 'Np' �� ������ ��������� 'NpM' (���� NpM>0).

BYTE GetN_(USHRT nPoints,USHRT *Np,USHRT NpM,BYTE *Mp)
{
BYTE GetN(BYTE M,USHRT *N); // ���������� 'N' - 2 � ������� 'M'.

USHRT M,N;

if(Np==NULL) return 1; if(nPoints<=1) return 2;
M=GetUSHRT_Test(LOG2(nPoints)); if(M>UCHAR_MAX) return messRet;
if(GetN((BYTE)M,&N)!=0) return 3; if(N<nPoints) { if(N>SHRT_MAX/2) return messRet; N*=2; M++;}
if(NpM>0&&N>NpM) return messRet; *Np=N; if(Mp!=NULL) *Mp=(BYTE)M; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������� ������� ���� ��� ������������ ����������.

BYTE GetWeightWinSTFT(BYTE meth,float *Weight,USHRT nP,float Wid)
{
BYTE GetWeightWinCosHann(float *Weight,USHRT nPoints,float Wid,float CoeWin); // ���������������� �����������.
BYTE GetWeightHamming(float *Weight,USHRT nPoints,float Wid); // ���� ��������.
BYTE GetWeightBlackman(float *Weight,USHRT nPoints,float Wid); // ���� ��������.
BYTE GetWeightBlackmanHarris(float *Weight,USHRT nPoints,float Wid); // ���� ��������-�������.
BYTE GetWeightKaiserBess(float *Weight,USHRT nPoints,float Wid,float CoeWin); // ���� �������-�������.
BYTE GetWeightNatall(float *Weight,USHRT nPoints,float Wid); // ���� �������.
BYTE GetWeightBlackmanNatall(float *Weight,USHRT nPoints,float Wid); // ���� ��������-�������.
BYTE GetWeightFlatTop(float *Weight,USHRT nPoints,float Wid); // ���� � ������� ��������.
BYTE GetWeightBarlett(float *Weight,USHRT nPoints,float Wid); // ���� �������� (�����������).
BYTE GetWeightBarlettHann(float *Weight,USHRT nPoints,float Wid); // ���� ��������-�����.
BYTE GetWeightLanczos(float *Weight,USHRT nPoints,float Wid); // ���� ��������.
BYTE GetWeightGauss(float *Weight,USHRT nPoints,float Wid,float CoeWin); // ���� ������.

BYTE be;

if(Weight==NULL) return 1; if(nP==0) return 2; if(Wid<=0.0F) return 3;
switch(meth) { default: return 4;
case methSpFour_Cos: be=GetWeightWinCosHann(Weight,nP,Wid,coeWinCos); break; // ���������������� �����������.
case methSpFour_Hann: be=GetWeightWinCosHann(Weight,nP,Wid,0.0F); break; // ���������������� ����������� � ���������� 0. (������� �����).
case methSpFour_Hamming: be=GetWeightHamming(Weight,nP,Wid); break; // ���� ��������.
case methSpFour_Blackman: be=GetWeightBlackman(Weight,nP,Wid); break; // ���� ��������.
case methSpFour_BlHarr: be=GetWeightBlackmanHarris(Weight,nP,Wid); break; // ���� ��������-�������.
case methSpFour_KaisBess: be=GetWeightKaiserBess(Weight,nP,Wid,coeWinKaisBess); break; // ���� �������-�������.
case methSpFour_Natall: be=GetWeightNatall(Weight,nP,Wid); break; // ���� �������.
case methSpFour_BlNatall: be=GetWeightBlackmanNatall(Weight,nP,Wid); break; // ���� ��������-�������.
case methSpFour_FlatTop: be=GetWeightFlatTop(Weight,nP,Wid); break; // ���� � ������� ��������.
case methSpFour_Barlett: be=GetWeightBarlett(Weight,nP,Wid); break; // ���� �������� (�����������).
case methSpFour_BarHann: be=GetWeightBarlettHann(Weight,nP,Wid); break; // ���� ��������-�����.
case methSpFour_Lanczos: be=GetWeightLanczos(Weight,nP,Wid); break; // ���� ��������.
case methSpFour_Gauss: be=GetWeightGauss(Weight,nP,Wid,coeWinGauss); break; // ���� ������.
}
if(be!=0) return 5; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������������� �����������.

BYTE GetWeightWinCosHann(float *Weight,USHRT nPoints,float Wid,float CoeWin)
{
USHRT i; float t,w,wb,c,*fp; double x;

if(Weight==NULL) return 1; if(nPoints==0) return 2;
c=CoeWin; fp=&c; if(*fp<0.0F) *fp=0.0F; if(*fp>1.0F) *fp=1.0F;
w=Wid*c; wb=Wid*(1.0F-c); if(wb<SmCnst4) return 3;

for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;} if(t<w) { *fp=1.0F; continue;}
x=(double)(Wid-t)/(double)wb; *fp=(float)(0.5*(1.-cos(x*M_PI)));}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� ������.

BYTE GetWeightGauss(float *Weight,USHRT nPoints,float Wid,float CoeWin)
{
USHRT i; float v,coe;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; if(CoeWin<SmCnst4) return 4;
coe=1.0F/(Wid*CoeWin);
for(i=0;i<nPoints;i++) { v=(float)i*coe; Weight[i]=(float)exp(-0.5*(double)(v*v));} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� ��������.

BYTE GetWeightHamming(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; *fp=(float)(0.54+0.46*cos(x));}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� ��������.

BYTE GetWeightBlackman(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; *fp=(float)(0.42+0.5*cos(x)+0.08*cos(2.*x));}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� ��������-�������.

BYTE GetWeightBlackmanHarris(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x,v;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; v=0.35875+0.48829*cos(x)+0.14128*cos(2.*x)+0.01168*cos(3.*x); *fp=(float)v;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� �������.

BYTE GetWeightNatall(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x,v;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; v=0.355768+0.487396*cos(x)+0.144232*cos(2.*x)+0.012604*cos(3.*x); *fp=(float)v;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� ��������-�������.

BYTE GetWeightBlackmanNatall(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x,v;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; v=0.3635819+0.4891775*cos(x)+0.1365995*cos(2.*x)+0.0106411*cos(3.*x); *fp=(float)v;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� � ������� ��������.

BYTE GetWeightFlatTop(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x,v;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; v=1.+1.93*cos(x)+1.29*cos(2.*x)+0.388*cos(3.*x)+0.032*cos(4.*x); *fp=(float)(v/4.64);}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� �������� (�����������).

BYTE GetWeightBarlett(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) *fp=0.0F; else *fp=(Wid-t)*coe;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� ��������-�����.

BYTE GetWeightBarlettHann(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,*fp; double x;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(Wid-t)/(double)Wid; *fp=(float)(0.62-0.24*(1.-x)-0.38*cos(x*M_PI));} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� ��������.

BYTE GetWeightLanczos(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; if(x<SmCnst4) *fp=1.0F; else *fp=(float)(sin(x)/x);} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���� �������-�������.

BYTE GetWeightKaiserBess(float *Weight,USHRT nPoints,float Wid,float CoeWin)
{
double GetBesselI0(double x); // ������ ���������������� ������� ������� 'I0'.

USHRT i; float t,coe,*fp; double x,v,coeF,alp;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; if(CoeWin<=0.0F) return 4;
coe=1.0F/Wid; alp=M_PI*(double)CoeWin; v=GetBesselI0(alp); if(v<SmCnst10_d) return 5; coeF=1./v;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe); v=1.-x*x; v=SQRT(v); v*=alp; v=GetBesselI0(v)*coeF; *fp=(float)v;}
return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define nSumBessI0 36 // ����� ������ � ����� ��� ���������� ���� ��� ���������� ���������������� ������� ������� I0.

//-----------------------------------------------------------------------------------------------------------
// ������ ���������������� ������� ������� 'I0'.

double GetBesselI0(double x)
{
BYTE i; double s,xh,p;

xh=x*0.5; s=1.; p=1.; for(i=1;i<nSumBessI0;i++) { p*=xh/(double)i; s+=p*p;} return s;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ���������� ������������ ���������.

//-----------------------------------------------------------------------------------------------------------

strParSpProc::strParSpProc(void)
{
Time_Width=Time_Width_Spectr_Stand; Time_Step=Time_Step_Spectr_Stand; methSpFour=methSpFour_KaisBess;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE strParSpProc::IsOK(void)
{
if(Time_Width<=0.0F) return 1; if(Time_Step<=0.0F) return 2; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� �������.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strNeuron::strNeuron(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ����������.

strNeuron::~strNeuron(void) 
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������������� � ����������.

void strNeuron::Zero(void)
{
nWeights=0; Weights=Shifts=NULL; ZeroPar();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������������.

void strNeuron::ZeroPar(void)
{
Val=T=0.; flTUse=1; flSmart=0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� ����� �� ������.

void strNeuron::Free(void)
{
SAFE_DELETE_ARR(Weights); SAFE_DELETE_ARR(Shifts); nWeights=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������� �����.

BYTE strNeuron::Alloc(USHRT nWeights_)
{
BYTE ber; USHRT i;

Free(); if(nWeights_==0) return 1; ber=0; nWeights=nWeights_;
Weights=new double[nWeights]; if(Weights==NULL) { ber=2; goto end;}
for(i=0;i<nWeights;i++) Weights[i]=0.;
if(flSmart!=0) {
Shifts=new double[nWeights]; if(Shifts==NULL) { ber=3; goto end;}
for(i=0;i<nWeights;i++) Shifts[i]=0.;}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������

BYTE strNeuron::IsOK(void)
{
if(nWeights==0) return 1; if(Weights==NULL) return 2; if(flSmart!=0) { if(Shifts==NULL) return 3;} return 0;
} 

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strNeuron::Read(FILE *file)
{
USHRT i,n; int iv;

if(file==NULL) return 1; Free();
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<0) return 3; if(iv>USHRT_MAX) return 4; n=(USHRT)iv;
if(fscanf(file,"%d",&iv)==EOF) return 5; if(iv==0) flTUse=0; else flTUse=1;
if(fscanf(file,"%d",&iv)==EOF) return 6; if(iv==0) flSmart=0; else flSmart=1;
if(fscanf(file,"%le",&T)==EOF) return 7;
if(n==0) return 0; if(Alloc(n)!=0) return 8;
for(i=0;i<nWeights;i++) if(fscanf(file,"%le",Weights+i)==EOF) return 9;
if(flSmart!=0) for(i=0;i<nWeights;i++) if(fscanf(file,"%le",Shifts+i)==EOF) return 10;
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ���� ��������.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strLay::strLay(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ����������.

strLay::~strLay(void) 
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������������� � ����������.

void strLay::Zero(void)
{
n=0; Neurons=NULL; InitPar();
}

//-----------------------------------------------------------------------------------------------------------
// ������������� ��� ��������� ���������������.

void strLay::InitPar(void)
{
TypFunAct=TypFunAct_Sigm; flTUse=1; flSmart=0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� �������� �� ������.

void strLay::Free(void)
{
SAFE_DELETE_ARR(Neurons); n=0;
}

//-----------------------------------------------------------------------------------------------------------
//��������� ������ ��� ������� ��������.

BYTE strLay::Alloc(USHRT n_)
{
Free(); if(n_==0) return 1; Neurons=new strNeuron[n_]; if(Neurons==NULL) return 2; n=n_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������

BYTE strLay::IsOK(void)
{
if(n==0) return 1; if(Neurons==NULL) return 2; return 0;
} 

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� �� ��������� �������.

strNeuron *strLay::Get(USHRT num)
{
if(IsOK()!=0) return NULL; if(num>=n) return NULL; return Neurons+num;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strLay::Read(FILE *file)
{
USHRT i,n_; int iv;

if(file==NULL) return 1; Free();
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<0) return 3; if(iv>USHRT_MAX) return 4; n_=(USHRT)iv;
if(fscanf(file,"%d",&iv)==EOF) return 5; if(iv==0) flTUse=0; else flTUse=1;
if(fscanf(file,"%d",&iv)==EOF) return 6; if(iv==0) flSmart=0; else flSmart=1;
if(fscanf(file,"%d",&iv)==EOF) return 7; if(iv<0) iv=0; if(iv>=nTypFunAct) iv=nTypFunAct-1; TypFunAct=(BYTE)iv;
if(n_==0) return 0; if(Alloc(n_)!=0) return 8;
for(i=0;i<n;i++) if(Neurons[i].Read(file)!=0) return 9;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� �������� ������� ������������� ��� ������� �������. 

BYTE strLay::AllocWeights(USHRT nNeurPrev)
{
USHRT i;

if(nNeurPrev==0) return 1; if(IsOK()!=0) return 2;
for(i=0;i<n;i++) if(Neurons[i].Alloc(nNeurPrev)!=0) return 3; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� �������� ���� ��������.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strInpLay::strInpLay(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ����������.

strInpLay::~strInpLay(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������������� � ����������.

void strInpLay::Zero(void)
{
n=0; Values=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �� ������.

void strInpLay::Free(void)
{
SAFE_DELETE_ARR(Values); n=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE strInpLay::Alloc(USHRT n_)
{
USHRT i;

Free(); if(n_==0) return 1; Values=new double[n_]; if(Values==NULL) return 2; n=n_;
for(i=0;i<n;i++) Values[i]=0.0F; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE strInpLay::IsOK(void)
{
if(n==0) return 1; if(Values==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ��������� �������� ���� ����.

BYTE CopyInpLay(strInpLay *Dst,strInpLay *Src)
{
USHRT i;

if(Dst==NULL) return 1; Dst->Free(); if(Src==NULL) return 2; if(Src->IsOK()!=0) return 3;
if(Dst->Alloc(Src->n)!=0) return 4; for(i=0;i<Src->n;i++) Dst->Values[i]=Src->Values[i]; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ��������� ��������� �������.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strParFreqCorrSpectr::strParFreqCorrSpectr(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// ������������� ����������.

void strParFreqCorrSpectr::Init(void)
{
FrIni=FreqIniFrCorr_Stand; FrFin=FreqFinFrCorr_Stand; CorrDB=CorrDBFrCorr_Stand;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE strParFreqCorrSpectr::IsOK(void)
{
if(FrFin<FrIni) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� � ���������.

USHRT strParFreqCorrSpectr::Check(void)
{
USHRT fl; float *fp;

fl=0;
fp=&CorrDB; if(*fp<0.0F) { *fp=0.0F; fl+=1<<0;}
fp=&FrIni; if(*fp<0.0F) { *fp=0.0F; fl+=1<<1;}
fp=&FrFin; if(*fp<0.0F) { *fp=0.0F; fl+=1<<2;}
if(FrFin<FrIni) { FrFin=FrIni; fl+=1<<4;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strParFreqCorrSpectr::Read(FILE *file)
{
if(file==NULL) return 1;
if(fscanf(file,"%f%f%f",&FrIni,&FrFin,&CorrDB)==EOF) return 2;
Check(); // �������� � ���������.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� �������� �������.

BYTE FreqCorrSpectr(strParFreqCorrSpectr *PFC,float dFr,strInpLay *InpLay)
{
USHRT i; float fr; double coe,amp,ampF;

if(PFC==NULL) return 1; if(PFC->IsOK()!=0) return 2; if(dFr<=0.0F) return 3;
if(InpLay==NULL) return 4; if(InpLay->IsOK()!=0) return 5;
coe=PFC->CorrDB/(double)(PFC->FrFin-PFC->FrIni)/20.; ampF=pow(10.,PFC->CorrDB/20.);
for(i=0;i<InpLay->n;i++) { fr=dFr*(float)i; if(fr<=PFC->FrIni) continue;
if(fr>=PFC->FrFin) amp=ampF; else amp=pow(10.,coe*(double)(fr-PFC->FrIni)); InpLay->Values[i]*=amp;}
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ������� � ���������� ��������� ����.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strPropNNW::strPropNNW(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// ������������� ����������.

void strPropNNW::Init(void)
{
flType=typNNW_Spectr; flTypInpData=typDataNNW_SpectrRow;
flFrCorr=1; typFrCorr=0; flFrCompr=typFrCompr=0; FreqCorrSpectr.Init();
dFr=0.0F; dFrTri=0.0F; FreqMin=FreqMax=0.0F;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strPropNNW::Read(FILE *file)
{
BYTE *bp; int iv;

if(file==NULL) return 1;
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<0||iv>=UCHAR_MAX) return 3; flType=(BYTE)iv;
if(flType!=typNNW_Spectr) return 4;
if(fscanf(file,"%d",&iv)==EOF) return 5; if(iv<0||iv>=UCHAR_MAX) return 6; flTypInpData=(BYTE)iv;
if(flTypInpData!=typDataNNW_SpectrRow) return 7;
if(fscanf(file,"%d",&iv)==EOF) return 8; bp=&flFrCorr; if(iv==0) *bp=0; else *bp=1;
if(fscanf(file,"%d",&iv)==EOF) return 9; bp=&flFrCompr; if(iv==0) *bp=0; else *bp=1;
if(fscanf(file,"%d",&iv)==EOF) return 10;
if(fscanf(file,"%f%f%f%f",&dFr,&dFrTri,&FreqMin,&FreqMax)==EOF) return 11;

// ������ ���������� ��������� ��������.
if(flFrCorr!=0) {
if(fscanf(file,"%d",&iv)==EOF) return 12; bp=&typFrCorr; if(iv==0) *bp=0; else *bp=1;
if(FreqCorrSpectr.Read(file)!=0) return 13;
}
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ���� ��������� ����.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strNNW::strNNW(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ����������.

strNNW::~strNNW(void) 
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������������� � ����������.

void strNNW::Zero(void)
{
nLay=0; Layers=NULL; typ=typNNW_Spectr; flOK=0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� �������� �� ������.

void strNNW::Free(void)
{
SAFE_DELETE_ARR(Layers); nLay=0; flOK=0; InpLay.Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������� ��������.

BYTE strNNW::Alloc(BYTE nLay_)
{
Free(); if(nLay_<=1) return 1; Layers=new strLay[nLay_]; if(Layers==NULL) return 2; nLay=nLay_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE strNNW::IsOK(void)
{
if(nLay<=1) return 1; if(Layers==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� ����.

BYTE strNNW::IsOK_Lay(void)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nLay;i++) if(Layers[i].IsOK()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� �� ��������� ����.

strLay *strNNW::Get(BYTE num)
{
if(IsOK()!=0) return NULL; if(num>=nLay) return NULL; return Layers+num;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� �� ��������� ��������� ����.

strLay *strNNW::GetOutLay(void)
{
if(IsOK()!=0) return NULL; return Layers+nLay-1;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strNNW::Read(FILE *file)
{
BYTE i; int iv;

if(file==NULL) return 1; Free(); Par.Init();
if(Par.Read(file)!=0) return 2; typ=Par.flType;
if(fscanf(file,"%d",&iv)==EOF) return 3; if(iv<0) return 4; if(iv>UCHAR_MAX) return 5; if(iv==0) return 0;
if(Alloc((BYTE)iv)!=0) return 6;
for(i=0;i<nLay;i++) if(Layers[i].Read(file)!=0) return 7; flOK=1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strNNW::Read_(char *fName)
{ 
BYTE err; clFileT *FT;

if(IsOKStr(fName)!=0) return 1;
FT=NULL; err=0;
FT=new clFileT(); if(FT==NULL) { err=2; goto end;}
if(FT->Open(fName,0)!=0) { err=3; goto end;} 
if(Read(FT->file)!=0) { err=4; goto end;}
end: SAFE_DELETE(FT); return err;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strNNW::Read(char *Path,char *fName,char *ext)
{
BYTE err; char *name;

if(IsOKStr(fName)!=0) return 1; if(IsOKStr(ext)!=0) return 2;
name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,ext)!=0) { err=3; goto end;}
if(Read_(name)!=0) { err=4; goto end;}
end: FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� �������� ���� � ������.

BYTE strNNW::Compute(strInpLay *InpLay_)
{
BYTE CopyInpLay(strInpLay *Dst,strInpLay *Src); // ����������� ��������� �������� ���� ����.

if(IsOK()!=0) return 1; if(CopyInpLay(&InpLay,InpLay_)!=0) return 2;
if(Par.flFrCorr!=0) { if(FreqCorrect()!=0) return 3;} // ��������� ��������� �������� �������.
if(Compute_(0)!=0) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ������� �� ���� 'layIn'.

BYTE strNNW::Compute_(BYTE layIn)
{
BYTE ComputeLayer(strLay *LayPrev,strLay *Lay); // ������ �������� �������� � ���� "Lay".
BYTE ComputeLayerFirst(strInpLay *LayPrev,strLay *Lay); // ������ �������� �������� � ���� "Lay" - ������ ������� ����.

BYTE i,in;

if(IsOK()!=0) return 1; if(layIn>nLay-1) return 2;
if(layIn==0) { in=1; if(ComputeLayerFirst(&InpLay,Layers)!=0) return 3;} else in=layIn;
for(i=in;i<nLay;i++) if(ComputeLayer(Layers+i-1,Layers+i)!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� �������� �������.

BYTE strNNW::FreqCorrect(void)
{
BYTE FreqCorrSpectr(strParFreqCorrSpectr *PFC,float dFr,strInpLay *InpLay); // ��������� ��������� �������� �������.

float dFr;

if(typ!=typNNW_Spectr) return 1;
if(Par.flTypInpData==typDataNNW_SpectrRow) dFr=Par.dFr; else dFr=Par.dFrTri;
if(FreqCorrSpectr(&Par.FreqCorrSpectr,dFr,&InpLay)!=0) return 2; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������� ��� �������� ������� ������������� ��������� �����.

//-----------------------------------------------------------------------------------------------------------
// ������ �������� �������� � ���� "Lay".

BYTE ComputeLayer(strLay *LayPrev,strLay *Lay)
{
USHRT i,j; double Sum,v; pFunAct FunAct; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2;
if(LayPrev==NULL) return 3; if(LayPrev->IsOK()!=0) return 4;
FunAct=GetFunAct(Lay->TypFunAct); if(FunAct==NULL) return 5;

// ���� �� "i" - ���������� ��� ������� ���� "Lay", ��� ����� ����� �� ��������.
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur->nWeights!=LayPrev->n) return 6;
// ���� �� "j" - ���������� ������� ����������� ����.
Sum=0.;
if(pNeur->flSmart==0) for(j=0;j<LayPrev->n;j++) Sum+=pNeur->Weights[j]*LayPrev->Neurons[j].Val;
else for(j=0;j<LayPrev->n;j++) { v=LayPrev->Neurons[j].Val-pNeur->Shifts[j]; Sum+=pNeur->Weights[j]*v;}
if(pNeur->flTUse!=0) Sum-=pNeur->T; pNeur->Val=(*FunAct)(Sum);}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �������� �������� � ���� "Lay" - ������ ������� ����.

BYTE ComputeLayerFirst(strInpLay *LayPrev,strLay *Lay)
{
USHRT i,j,nWei; double Sum,v; pFunAct FunAct; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2;
if(LayPrev==NULL) return 3; if(LayPrev->IsOK()!=0) return 4;
FunAct=GetFunAct(Lay->TypFunAct); if(FunAct==NULL) return 5;

// ���� �� "i" - ���������� ��� ������� ���� "Lay", ��� ����� ����� �� ��������.
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; nWei=MIN(pNeur->nWeights,LayPrev->n);
// ���� �� "j" - ���������� ������� ����������� ����.
Sum=0.;
if(pNeur->flSmart==0) for(j=0;j<nWei;j++) Sum+=pNeur->Weights[j]*LayPrev->Values[j];
else for(j=0;j<nWei;j++) { v=LayPrev->Values[j]-pNeur->Shifts[j]; Sum+=pNeur->Weights[j]*v;}
if(pNeur->flTUse!=0) Sum-=pNeur->T; pNeur->Val=(*FunAct)(Sum);
}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ������ ������� ��������� ��������� ���������.

pFunAct GetFunAct(BYTE Typ)
{
double FunAct_Sigm(double Sum); // ������� ��������� ���������� ���������. ���������� �������.
double FunAct_BiSigm(double Sum); // ������� ��������� ���������� ���������. ���������� c��������� �������.
double FunAct_HypTang(double Sum); // ������� ��������� ���������� ���������. ��������������� �������.
double FunAct_Log(double Sum); // ������� ��������� ���������� ���������. ���������������.
double FunAct_Lin(double Sum); // ������� ��������� ���������� ���������. ��������.

pFunAct FunAct;

switch(Typ) { default: FunAct=NULL; break;
case TypFunAct_Sigm:   FunAct=FunAct_Sigm; break;      //���������� ������.
case TypFunAct_BiSigm: FunAct=FunAct_BiSigm; break;   // ���������� c��������� ������.
case TypFunAct_HypTan: FunAct=FunAct_HypTang; break; // ��������������� �������.
case TypFunAct_Log:    FunAct=FunAct_Log; break; // ���������������.
case TypFunAct_Lin:    FunAct=FunAct_Lin; break; // ��������.
}
return FunAct;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ��������� ���������� ���������. ���������� �������.

double FunAct_Sigm(double Sum)
{
double y;

y=1./(1.+exp(-Sum)); return y;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ��������� ���������� ���������. ���������� c��������� �������.

double FunAct_BiSigm(double Sum)
{
double y;

y=2./(1.+exp(-Sum))-1.; return y;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ��������� ���������� ���������. ��������������� �������.

double FunAct_HypTang(double Sum)
{
double y,e,er;

e=exp(Sum); er=1./e; y=(e-er)/(e+er); return y;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ��������� ���������� ���������. ���������������.

double FunAct_Log(double Sum)
{
double v;

if(Sum>=0.) v=Sum; else v=-Sum; v=log(v+sqrt(v*v+1.)); if(Sum<0.) v=-v; return v;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ��������� ���������� ���������. ��������.

double FunAct_Lin(double Sum)
{
return Sum;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ������� ��� ������������ ������� �������� � �������������.

//-----------------------------------------------------------------------------------------------------------
// ������������� ������ ������� ��������� �����.

BYTE RecognSoundNNW_Sp(float *Spectr,USHRT nSpectr,float dFr,strNNW *pNNW,pFunDecSnd DecSnd,PNT_DATA Pnt,
BYTE *numSnd)
{
BYTE InputDataNetSp(float FreqMin,float FreqMax,float dFr,float AmpThr,float *Spectr,USHRT nSpectr,strInpLay *InpLay); // ���������� ������� ������ ��� ��������� ����.

BYTE num,err; float FreqMin,FreqMax; struct strInpLay InpLay; struct strLay *pLay;

if(Spectr==NULL) return 1; if(nSpectr==0) return 2; if(dFr<=0.0F) return 3;
if(pNNW==NULL) return 4; if(pNNW->typ!=typNNW_Spectr) return 5;
if(pNNW->IsOK()!=0) return 6; if(pNNW->flOK==0) return 7; if(dFr!=pNNW->Par.dFr) return 8;
if(DecSnd==NULL) return 9; if(numSnd==NULL) return 10;
err=0;

// ���� ������ � ��������� ����.
FreqMin=pNNW->Par.FreqMin;
FreqMax=pNNW->Par.FreqMax;
if(InputDataNetSp(FreqMin,FreqMax,dFr,AmpThr_Noice,Spectr,nSpectr,&InpLay)!=0) { err=1; goto eNNW;}

// ������������� ������� ��������� �����.
if(pNNW->Compute(&InpLay)!=0) { err=2; goto eNNW;}
pLay=pNNW->GetOutLay(); if(pLay==NULL) { err=3; goto eNNW;} if(pLay->IsOK()!=0) { err=4; goto eNNW;}
if((*DecSnd)(Pnt,pLay,&num)!=0) { err=5; goto eNNW;}
eNNW: if(err!=0) *numSnd=UCHAR_MAX; else *numSnd=num;

InpLay.Free(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������� ������ ��� ��������� ����.

BYTE InputDataNetSp(float FreqMin,float FreqMax,float dFr,float AmpThr,float *Spectr,USHRT nSpectr,strInpLay *InpLay)
{
BYTE InpSpectrRow(USHRT nSpectr,float *Spectr,float dFr,float FreqMin,float FreqMax,float AmpThr,
  strInpLay *InpLay); // ����������� ��������������� �������.

BYTE be; USHRT nFrMax;

if(InpLay==NULL) return 1; if(FreqMin<=0.0F) return 2; if(FreqMax<=0.0F) return 3; if(FreqMin>=FreqMax) return 4;
if(Spectr==NULL) return 5; if(nSpectr==0) return 6; if(dFr<=0.0F) return 7;
nFrMax=GetUSHRT_Test(FreqMax/dFr); if(nFrMax==0) return 8;
nFrMax=MIN(nFrMax,nSpectr); if(InpLay->Alloc(nFrMax)!=0) return 9;
be=InpSpectrRow(nSpectr,Spectr,dFr,FreqMin,FreqMax,AmpThr,InpLay);
if(be!=messRet&&be!=0) return 10; if(be==messRet) return messRet; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ����������� ��������������� �������.

BYTE InpSpectrRow(USHRT nSpectr,float *Spectr,float dFr,float FreqMin,float FreqMax,float AmpThr,
strInpLay *InpLay)
{
USHRT j,nFrMin,nInp,nMax; float v; double s;

if(nSpectr==0) return 1; if(Spectr==NULL) return 2; if(dFr<=0.0F) return 3;
if(FreqMin<=0.0F) return 4; if(FreqMax<=0.0F) return 5; if(FreqMax<=FreqMin) return 6;
if(AmpThr<0.0F) return 7; if(InpLay==NULL) return 8; if(InpLay->IsOK()!=0) return 9;
nInp=InpLay->n; nMax=MIN(nSpectr,nInp);
nFrMin=GetUSHRT_Test(FreqMin/dFr); if(nFrMin>=nMax) return 10;

s=0.; for(j=nFrMin;j<nMax;j++) { v=Spectr[j]; s+=POW2D(v);} s/=(double)(nMax-nFrMin); s=SQRT(s);
if((float)s<AmpThr) return messRet;
v=1.0F/(float)s;
for(j=0;j<nFrMin;j++) InpLay->Values[j]=0.;
for(j=nFrMin;j<nMax;j++) InpLay->Values[j]=(double)(Spectr[j]*v);
if(nMax<nInp) for(j=nMax;j<nInp;j++) InpLay->Values[j]=0.;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������� �������� ������� ��� ������������� ����� - ���������� ��������� �������������, ���������� �� ������� ���������.

BYTE DecSnd_Instant(PNT_DATA Pnt,strLay *pLay,BYTE *numSnd)
{
BYTE GetNumSound(strLay *pLay,float Err,BYTE *numSnd); // ���������� ������ �����, �������� ������������� ������������ �������� � �������� ������� ��������.

if(pLay==NULL) return 1; if(numSnd==NULL) return 2;
if(GetNumSound(pLay,errSoundResNNW,numSnd)!=0) return 3; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ���������� ��� ������� ������ ������ ��� �����.

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE strParAnSnd::IsOK(void)
{
if(tStore<=0.0F) return 1; if(weiStore<=0.0F) return 2; if(weiInst<=0.0F) return 3; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ��� ������� ������ ������ ��� �����.

//-----------------------------------------------------------------------------------------------------------

strAnSnd::strAnSnd(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

strAnSnd::~strAnSnd(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void strAnSnd::Zero(void)
{
nBuf=0; Buf=NULL; weiStore=weiInst=coeWei=0.0F; cnt=0; sum=0.;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void strAnSnd::Free(void)
{
SAFE_DELETE_ARR(Buf); nBuf=0;
}

//-----------------------------------------------------------------------------------------------------------
// �������������.

BYTE strAnSnd::Init(strParAnSnd *PAS,float tStep)
{
if(PAS==NULL) return 1; if(PAS->IsOK()!=0) return 2; if(tStep<=0.0F) return 3; Free();
weiStore=PAS->weiStore; weiInst=PAS->weiInst;
coeWei=weiStore+weiInst; if(coeWei<=0.0F) return 4; coeWei=1.0F/coeWei;
nBuf=GetUSHRT_Test(PAS->tStore/tStep); if(nBuf<=1) nBuf=2;
Buf=new float[nBuf]; if(Buf==NULL) { nBuf=0; return 4;}
if(Start()!=0) return 5; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE strAnSnd::IsOK(void)
{
if(Buf==NULL) return 1; if(nBuf==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ������.

BYTE strAnSnd::Start(void)
{
USHRT i;

cnt=0; sum=0.; if(IsOK()!=0) return 1; for(i=0;i<nBuf;i++) Buf[i]=0.0F; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��� ������.

BYTE strAnSnd::Step(float Val,float *pRes)
{
float v,*fp;

if(IsOK()!=0) return 1; if(cnt>=nBuf) return 2;
fp=Buf+cnt; sum-=(double)*fp; *fp=Val; sum+=(double)*fp; cnt++; if(cnt>=nBuf) cnt=0; 
if(pRes==NULL) return 0; v=(float)(sum/(double)nBuf); *pRes=(v*weiStore+Val*weiInst)*coeWei; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ��� ������� ������ ������ ��� ���������� ������.

//-----------------------------------------------------------------------------------------------------------

strAnSndArr::strAnSndArr(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

strAnSndArr::~strAnSndArr(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void strAnSndArr::Zero(void)
{
pArr=NULL; nArr=0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void strAnSndArr::Free(void)
{
Clear(); SAFE_DELETE_ARR(pArr); nArr=0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ � ����������.

void strAnSndArr::Clear(void)
{
BYTE i;

if(IsOK()!=0) return; for(i=0;i<nArr;i++) pArr[i].Free();
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������.

BYTE strAnSndArr::Create(BYTE nArr_)
{
Free(); if(nArr_==0) return 1; pArr=new strAnSnd[nArr_]; if(pArr==NULL) return 2; nArr=nArr_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� ��������.

BYTE strAnSndArr::IsOK(void)
{
if(pArr==NULL) return 1; if(nArr==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������������.

BYTE strAnSndArr::Init(strParAnSnd *PAS,BYTE nPAS,float tStep,BYTE flNew)
{
BYTE i;

if(PAS==NULL) return 1; if(nPAS==0) return 2; if(tStep<=0.0F) return 3;
if(flNew==0) { if(IsOK()!=0) return 4; if(nPAS!=nArr) return 5; Clear();}
else { if(Create(nPAS)!=0) return 6;}
if(nPAS!=nArr) return 7; for(i=0;i<nArr;i++) { if(pArr[i].Init(PAS+i,tStep)!=0) return 8;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ������.

BYTE strAnSndArr::Start(void)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nArr;i++) if(pArr[i].Start()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��� ������.

BYTE strAnSndArr::Step(float *pVal,float *pRes,BYTE nVal)
{
BYTE i; float v,*fp;

if(nVal==0) return 1; if(IsOK()!=0) return 2; if(nVal!=nArr) return 3;
for(i=0;i<nArr;i++) { if(pVal!=NULL) v=pVal[i]; else v=0.0F; if(pRes==NULL) fp=NULL; else fp=pRes+i;
if(pArr[i].Step(v,fp)!=0) return 4;}
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ��� ������� ������ ������.

//-----------------------------------------------------------------------------------------------------------
// �������������.

BYTE strAnalyseSound::Init(float tStep,BYTE flNew)
{
if(tStep<=0.0F) return 1; if(AnSnd.Init(ParAnSnd,nVoices,tStep,flNew)!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ������.

BYTE strAnalyseSound::Start(void)
{
if(AnSnd.Start()!=0) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��� ������.

BYTE strAnalyseSound::Step(float *pVal,BYTE nVal,BYTE *numSnd)
{
BYTE i,n; float vM,v;

if(pVal==NULL) return 1; if(nVal==0) return 2; if(numSnd==NULL) return 3;
if(AnSnd.Step(pVal,Res,nVoices)!=0) return 4;

n=UCHAR_MAX; vM=0.0F;
for(i=0;i<nVoices;i++) { v=Res[i]; if(v>vM) { vM=v; n=i;}}
if(vM==0.0F||n==UCHAR_MAX) { *numSnd=UCHAR_MAX; return 0;}
if(vM<LevSoundDecStore) *numSnd=UCHAR_MAX; else *numSnd=n; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ��� ������������� ������ �������.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strRecSymb::strRecSymb(void)
{
Zero(); N_CntSymb=N_CntNoSymb=0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������� ����������.

void strRecSymb::Zero(void)
{
cntSymp=cntNotSymb=0;
}

//-----------------------------------------------------------------------------------------------------------
// �������������.

void strRecSymb::Init(USHRT NCntSymb,USHRT NCntNoSymb)
{
N_CntSymb=NCntSymb; N_CntNoSymb=NCntNoSymb;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� �������� ������� ��� ��������� �������.

void strRecSymb::IncCntSymb(BYTE flag)
{
if(flag!=0) { if(cntSymp==USHRT_MAX) return; cntSymp++; cntNotSymb=0;}
else { if(cntNotSymb==USHRT_MAX) { cntSymp=0; return;} cntNotSymb++; if(cntNotSymb>=N_CntNoSymb) cntSymp=0;}
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ��� ������� ������ ������.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strAnalyseData::strAnalyseData(void)
{
Reset();
}

//-----------------------------------------------------------------------------------------------------------
// �������������.

void strAnalyseData::Init(void)
{
BYTE i; struct strParAnSnd *pPAS;

for(i=0;i<nVoices;i++) { pPAS=ParAnSnd+i; SymbArr[i].Init(pPAS->nCntSymb,pPAS->nCntNoSymb);}
pPAS=ParAnSnd+nVoices; NoSymb.Init(pPAS->nCntSymb,pPAS->nCntNoSymb);
}

//-----------------------------------------------------------------------------------------------------------
// ����� ���������.

void strAnalyseData::Reset(void)
{
BYTE i;

for(i=0;i<nVoices;i++) SymbArr[i].Zero(); NoSymb.Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������� �� ������.

BYTE strAnalyseData::GetSymb(BYTE numSnd,BYTE flClear)
{
BYTE i,fl,flV,flN; struct strRecSymb *pRS;

flV=flN=0; if(numSnd<nVoices) flV=1; else flN=1;
for(i=0;i<nVoices;i++) { fl=0; if(flV!=0&&i==numSnd) fl=1; SymbArr[i].IncCntSymb(fl);}
NoSymb.IncCntSymb(flN);
if(numSnd>=nVoices) return 1; pRS=SymbArr+numSnd;
if(pRS->cntSymp>=pRS->N_CntSymb) { pRS->Zero(); return messRet;} return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������������� ���������.

//-----------------------------------------------------------------------------------------------------------
// ���������� ������ �����, �������� ������������� ������������ �������� � �������� ������� ��������.

BYTE GetNumSound(strLay *pLay,float Err,BYTE *numSnd)
{
USHRT i,j; double v,vm; struct strNeuron *pNeur;

if(pLay==0) return 1; if(pLay->IsOK()!=0) return 2; if(numSnd==NULL) return 3; *numSnd=UCHAR_MAX;
if(Err<=0.0F||Err>=1.0F) return 4;
j=USHRT_MAX; vm=(float)LrgCnst32_d;
for(i=0;i<pLay->n;i++) { pNeur=pLay->Get(i); if(pNeur==NULL) return 5;
v=1.-pNeur->Val; if(v<0.) v=-v; if(v<vm) { vm=v; j=i;}}
if(j>UCHAR_MAX) j=UCHAR_MAX; if(vm>Err) return messRet; *numSnd=(BYTE)j; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������� �����.

BYTE GetSymbSound(BYTE num,char *pSymb)
{
if(pSymb==NULL) return 1; if(num>=nVoices) return 2; *pSymb=ParAnSnd[num].Symb; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������� ������� ��������� ���������.

BYTE GetOutArr(strLay *pLay,float *pArr,BYTE nArr)
{
USHRT i; struct strNeuron *pNeur;

if(pLay==NULL) return 1; if(pLay->IsOK()!=0) return 2; if(pArr==NULL) return 3; if(nArr==0) return 4;
if((USHRT)nArr!=pLay->n) return 5;
for(i=0;i<pLay->n;i++) { pNeur=pLay->Get(i); if(pNeur==NULL) return 6; pArr[i]=(float)pNeur->Val;} return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ����� � �������.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strWordDict::strWordDict(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ����������.

strWordDict::~strWordDict(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void strWordDict::Zero(void)
{
nTranscr=0; Word=NULL; Transcr=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void strWordDict::Free(void)
{
FreeString(&Word); FreeTranscr();
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ �� ������������.

void strWordDict::FreeTranscr(void)
{
ClearTranscr(); SAFE_DELETE_ARR(Transcr); nTranscr=0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ����� �� ������.

void strWordDict::ClearTranscr(void)
{
BYTE i;

if(IsOK_Transcr()!=0) return; for(i=0;i<nTranscr;i++) FreeString(Transcr+i);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ��� ������������.

BYTE strWordDict::AllocTranscr(BYTE nTranscr_)
{
FreeTranscr(); if(nTranscr_==0) return 1;
if(AllocPString(&Transcr,nTranscr_)!=0) return 2;
nTranscr=nTranscr_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� ������������.

BYTE strWordDict::IsOK_Transcr(void)
{
if(Transcr==NULL) return 1; if(nTranscr==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ������������.

char *strWordDict::Get(UINT num)
{
if(IsOK_Transcr()!=0) return NULL; if(num>=nTranscr) return NULL; return Transcr[num];
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strWordDict::Read(FILE *file)
{
BYTE i; int iv;

if(file==NULL) return 1; FreeTranscr();
if(fscanf(file,"%s",TxtStr)==EOF) return 2; if(DupString(&Word,TxtStr)!=0) return 3;
if(fscanf(file,"%d",&iv)==EOF) return 4; if(iv<=0) return 5; if(iv>UCHAR_MAX) return 6;
if(AllocTranscr((BYTE)iv)!=0) return 7;
for(i=0;i<nTranscr;i++) { if(fscanf(file,"%s",TxtStr)==EOF) return 8; if(DupString(Transcr+i,TxtStr)!=0) return 9;}
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� �������.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strDictionary::strDictionary(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ����������.

strDictionary::~strDictionary(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void strDictionary::Zero(void)
{
Words=NULL; nWords=0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void strDictionary::Free(void)
{
SAFE_DELETE_ARR(Words); nWords=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE strDictionary::Alloc(UINT nWords_)
{
Free(); if(nWords_==0) return 1;
Words=new strWordDict[nWords_]; if(Words==NULL) return 2;
nWords=nWords_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������.

BYTE strDictionary::IsOK(void)
{
if(nWords==0) return 1; if(Words==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� �����.

strWordDict *strDictionary::Get(UINT num)
{
if(IsOK()!=0) return NULL; if(num>=nWords) return NULL; return Words+num;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ ������������� �����.

char *strDictionary::GetWord(UINT num)
{
if(IsOK()!=0) return NULL; if(num>=nWords) return NULL; return Words[num].Word;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strDictionary::Read(char *Path,char *fName,char *ext)
{
BYTE err; char *name;

if(IsOKStr(fName)!=0) return 1; if(IsOKStr(ext)!=0) return 2;
name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,ext)!=0) { err=3; goto end;}
if(Read_(name)!=0) { err=4; goto end;}
end: FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strDictionary::Read_(char *fName)
{ 
BYTE err; clFileT *FT;

if(IsOKStr(fName)!=0) return 1;
FT=NULL; err=0;
FT=new clFileT(); if(FT==NULL) { err=2; goto end;}
if(FT->Open(fName,0)!=0) { err=3; goto end;} 
if(Read(FT->file)!=0) { err=4; goto end;}
end: SAFE_DELETE(FT); return err;
}

//-----------------------------------------------------------------------------------------------------------
// ������ �� �����.

BYTE strDictionary::Read(FILE *file)
{
BYTE ber; int iv; UINT i;

if(file==NULL) return 1; Free();
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<=0) return 3;
if(Alloc((UINT)iv)!=0) return 4;
ber=0;
for(i=0;i<nWords;i++) if(Words[i].Read(file)!=0) { ber=5; goto end;}
end: if(ber!=0) Free(); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ��� ������������� ������������ �����.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strRecognTranscr::strRecognTranscr(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void strRecognTranscr::Zero(void)
{
pTr=NULL; ln=cnt=cntNS=cntErr=cntErrM=0;
}

//-----------------------------------------------------------------------------------------------------------
// �������������.

BYTE strRecognTranscr::Init(char *pTr_)
{
size_t l;

Zero(); if(pTr_==NULL) return 1; l=strlen(pTr_); if(l==0) return 2; if(l>UCHAR_MAX) return 3;
pTr=pTr_; ln=(BYTE)l; cntErrM=GetBYTE((float)ln*PercWrongRecWord); if(cntErrM==0) cntErrM=1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ������.

void strRecognTranscr::Start(void)
{
cnt=cntNS=cntErr=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��� ������.

BYTE strRecognTranscr::Step(char Symb)
{
if(pTr==NULL||ln==0) return 1; if(cnt>=ln) { start: Start(); return 0;}
if(Symb==pTr[cnt]) { cnt++; goto cont;} // �������� ��������� ������ �����.
if(cnt<ln-1) { if(Symb==pTr[cnt+1]) { cntErr++; if(cntErr>cntErrM) goto start; cnt+=2; goto cont;}} // ���������� ������������� ����� � ��������� ����� �����.
if(cnt>0) { cntNS++; if(cntNS>cntNSWord_Max) goto start;} return 0;
cont: if(cnt>=ln) { Start(); return messRet;} return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ��� ������������� �����.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strRecognWord::strRecognWord(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ����������.

strRecognWord::~strRecognWord(void)
{
FreeRT();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void strRecognWord::Zero(void)
{
pWD=NULL; ZeroRT();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void strRecognWord::ZeroRT(void)
{
RecTr=NULL; nRecTr=0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void strRecognWord::FreeRT(void)
{
SAFE_DELETE_ARR(RecTr); nRecTr=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE strRecognWord::AllocRT(UINT nRecTr_)
{
FreeRT(); if(nRecTr_==0) return 1;
RecTr=new strRecognTranscr[nRecTr_]; if(RecTr==NULL) return 2;
nRecTr=nRecTr_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������.

BYTE strRecognWord::IsOK_RT(void)
{
if(nRecTr==0) return 1; if(RecTr==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������������.

BYTE strRecognWord::Init(strWordDict *pWD_)
{
BYTE i;

FreeRT(); if(pWD_==NULL) return 1; if(pWD_->IsOK_Transcr()!=0) return 2;
if(AllocRT(pWD_->nTranscr)!=0) return 3;
for(i=0;i<nRecTr;i++) if(RecTr[i].Init(pWD_->Get(i))!=0) return 4; pWD=pWD_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ������.

BYTE strRecognWord::Start(void)
{
BYTE i;

if(IsOK_RT()!=0) return 1; for(i=0;i<nRecTr;i++) RecTr[i].Start(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��� ������.

BYTE strRecognWord::Step(char Symb)
{
BYTE i,fl,nRec;

if(IsOK_RT()!=0) return 1; nRec=0;
for(i=0;i<nRecTr;i++) { fl=RecTr[i].Step(Symb); if(fl==messRet) nRec++;}
if(nRec>0) return messRet; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ��� ������������� ����.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strRecognAllWords::strRecognAllWords(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ����������.

strRecognAllWords::~strRecognAllWords(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void strRecognAllWords::Zero(void)
{
RecWords=NULL; nWords=0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void strRecognAllWords::Free(void)
{
SAFE_DELETE_ARR(RecWords); nWords=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE strRecognAllWords::Alloc(UINT nWords_)
{
Free(); if(nWords_==0) return 1;
RecWords=new strRecognWord[nWords_]; if(RecWords==NULL) return 2;
nWords=nWords_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������.

BYTE strRecognAllWords::IsOK(void)
{
if(nWords==0) return 1; if(RecWords==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������������.

BYTE strRecognAllWords::Init(strDictionary *pDict)
{
UINT i;

Free(); if(pDict==NULL) return 1; if(pDict->IsOK()!=0) return 2; if(Alloc(pDict->nWords)!=0) return 3;
for(i=0;i<nWords;i++) if(RecWords[i].Init(pDict->Get(i))!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ������.

BYTE strRecognAllWords::Start(void)
{
UINT i;

if(IsOK()!=0) return 1; for(i=0;i<nWords;i++) RecWords[i].Start(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��� ������.

BYTE strRecognAllWords::Step(BYTE numSnd,UINT *numRec)
{
UINT i,j; char Symb;

if(IsOK()!=0) return 1; if(numSnd>=nVoices) return 2; Symb=ParAnSnd[numSnd].Symb;
j=UINT_MAX; for(i=0;i<nWords;i++) if(RecWords[i].Step(Symb)==messRet) { j=i; break;}
if(j>=nWords) return 0; if(numRec==NULL) return 3; *numRec=j; return messRet;
}
