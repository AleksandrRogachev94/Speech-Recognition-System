/*...........................................................................................................

// ����� ������.
class clString {
clString,~clString,Zero,Free,Alloc,IsOK,SetZero},

// ����� ������� 'BYTE'.
class clArrBYTE {
clArrBYTE,~clArrBYTE,Zero,Free,Alloc,IsOK,SetZero},

// ����� ������� 'float'.
class clArrFloat {
clArrFloat,~clArrFloat,Zero,Free,Alloc,IsOK,SetZero},

// ����� ������� 'double'.
class clArrDouble {
clArrDouble,~clArrDouble,Zero,Free,Alloc,IsOK,SetZero},

// ����� ���������� ������� ����� 'float'.
class clArr2Float {
clArr2Float,~clArr2Float,Zero,Free,Clear,Alloc,IsOK,IsOK_,Get},

// ����� ��� ������ ����������� ���� DIB � ���������� ����������� � ������.
class clBmpPict {
clBmpPict,~clBmpPict,Zero,Free,IsOK,ZeroBmp,FreeBmp,Clear,Clear,SetPix,Init,ZeroDC,GetDC,FreeDC,Image,GetImg,
Save},

// ����������� � ������.
class clImgMem {
clImgMem,~clImgMem,Zero,Free,FreeDC,
ZeroBmp,FreeBmp,CreateBmp,
Create,SelectBmp,UnSelectBmp,SetPar,IsOK,IsOKImg,SetBitsTrCol,SetBitsGrayCol},
InitBmpMem_,DeleteBmpMem_,

// �������� � �������� ������.
class clFileT {
clFileT,~clFileT,Close,Open},

// ����� ��� ������ � �������.
class clOFN {
clOFN,~clOFN,Zero,Free,IsOK,Open,GetFilePath},
GetNameFileOpen,

// ����� �����.
class clListString {
clListString,~clListString,Zero,Free,Clear,Alloc,IsOK,Set,Get},

// ����� ������� "*.htm" ����� 'Explorer'.
class clHelpEx {
clHelpEx,~clHelpEx,Zero,Free,
ZeroLS,FreeLS,CreateLS,ReadLS,
Show,Set,ShowContent,ShowTopic},

// ��������� ������� ��������� �������.
struct strSndArr {
strSndArr,~strSndArr,Zero,Free,Create,IsOK},
FillSndArr,FillWavData,

// ��������� �������.
struct strPal { strPal,Zero,FillColor}

...........................................................................................................*/

#include "stdafx.h"
#include "Project_con.h"
#include "Project_cls.h"
#include "Project_snd.h"
#include "resource.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������.

BYTE AllocString(char **Str,size_t ln); // ��������� ������ ��� ������.
void FreeString(char **Str); // ������������ ������ ��� ������.
BYTE AllocBYTE(BYTE **bpp,size_t ln); // ��������� ������ ��� ������� 'BYTE'.
void FreeBYTE(BYTE **bpp); // ������������ ������ ��� ������� 'BYTE'.
BYTE AllocDWORD(DWORD **dwpp,size_t ln); // ��������� ������ ��� ������� 'DWORD'.
void FreeDWORD(DWORD **dwpp); // ������������ ������ ��� ������� 'DWORD'.
BYTE AllocFloat(float **fpp,size_t ln); // ��������� ������ ��� ������� 'float'.
void FreeFloat(float **fpp); // ������������ ������ ��� ������� 'float'.
BYTE AllocDouble(double **dpp,size_t ln); // ��������� ������ ��� ������� 'double'.
void FreeDouble(double **dpp); // ������������ ������ ��� ������� 'double'.
BYTE IsFileExist_(char *PathName); // �������� ������������� �����.
BYTE IsFileExist(char *Name,char *PathDir,char *dir,char *ext); // �������� ������������� �����.
BYTE InitImgBitmap(int dx,int dy,BYTE typBmp,UINT *dxB_,HBITMAP *hBitmap,BYTE **pvBits,DWORD *NCol,SHRT nCol); // �������� 'DIB'.
BYTE CreateInfoBMP(BITMAPINFO **BMInfo,int dx,int dy,BYTE typBmp,DWORD *NCol,SHRT nCol); // ��������� ��������� ���������� ��� �������� �����������.
void DeleteInfoBMP(BITMAPINFO **BMInfo); // �������� ��������� ����� � ������������ 'DIB'.
BYTE DupString(char **Str,char *Src); // ��������� ������ ��� ������ � �����������.
BYTE IsOKStr(char *str); // �������� ������.
BYTE GetString(char **String,char **Items,BYTE n); // ������ ������ �� ���������� �����.
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // ��������� ����� ����� ������� ����.
void Message(UINT StrID,UINT typ); // ����� ���������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� ����������.

extern char TxtStr[strL_Txt]; // ��������������� ������.

extern char *extHTM; // ���������� ������ ������� � ������� '*.htm'.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����� ������.

//-----------------------------------------------------------------------------------------------------------

clString::clString(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clString::~clString(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� � ������������� ����������.

void clString::Zero(void)
{
sz=0; String=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void clString::Free(void)
{
FreeString(&String); sz=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE clString::Alloc(UINT sz_)
{
BYTE ber;

Free(); if(sz_==0) return 1; sz=sz_; ber=0;
if(AllocString(&String,(size_t)sz)!=0) { ber=2; goto end;}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE clString::IsOK(void)
{
if(String==NULL) return 1; if(sz==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� �������.

BYTE clString::SetZero(void)
{
UINT i;

if(IsOK()!=0) return 1; for(i=0;i<=sz;i++) String[i]='\0'; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����� ������� 'BYTE'.

//-----------------------------------------------------------------------------------------------------------

clArrBYTE::clArrBYTE(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clArrBYTE::~clArrBYTE(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� � ������������� ����������.

void clArrBYTE::Zero(void)
{
ln=0; Arr=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void clArrBYTE::Free(void)
{
FreeBYTE(&Arr); ln=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE clArrBYTE::Alloc(UINT ln_)
{
BYTE ber;

Free(); if(ln_==0) return 1; ln=ln_; ber=0;
if(AllocBYTE(&Arr,(size_t)ln)!=0) { ber=2; goto end;}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE clArrBYTE::IsOK(void)
{
if(Arr==NULL) return 1; if(ln==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� �������.

BYTE clArrBYTE::SetZero(void)
{
UINT i;

if(IsOK()!=0) return 1; for(i=0;i<ln;i++) Arr[i]=0; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����� ������� 'float'.

//-----------------------------------------------------------------------------------------------------------

clArrFloat::clArrFloat(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clArrFloat::~clArrFloat(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� � ������������� ����������.

void clArrFloat::Zero(void)
{
ln=0; Arr=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void clArrFloat::Free(void)
{
FreeFloat(&Arr); ln=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE clArrFloat::Alloc(UINT ln_)
{
BYTE ber;

Free(); if(ln_==0) return 1; ln=ln_; ber=0;
if(AllocFloat(&Arr,(size_t)ln)!=0) { ber=2; goto end;}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE clArrFloat::IsOK(void)
{
if(Arr==NULL) return 1; if(ln==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� �������.

BYTE clArrFloat::SetZero(void)
{
UINT i;

if(IsOK()!=0) return 1; for(i=0;i<ln;i++) Arr[i]=0.0F; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����� ������� 'double'.

//-----------------------------------------------------------------------------------------------------------

clArrDouble::clArrDouble(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clArrDouble::~clArrDouble(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� � ������������� ����������.

void clArrDouble::Zero(void)
{
ln=0; Arr=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void clArrDouble::Free(void)
{
FreeDouble(&Arr); ln=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE clArrDouble::Alloc(UINT ln_)
{
BYTE ber;

Free(); if(ln_==0) return 1; ln=ln_; ber=0;
if(AllocDouble(&Arr,(size_t)ln)!=0) { ber=2; goto end;}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE clArrDouble::IsOK(void)
{
if(Arr==NULL) return 1; if(ln==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� �������.

BYTE clArrDouble::SetZero(void)
{
UINT i;

if(IsOK()!=0) return 1; for(i=0;i<ln;i++) Arr[i]=0.; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����� ���������� ������� ����� 'float'.

//-----------------------------------------------------------------------------------------------------------

clArr2Float::clArr2Float(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clArr2Float::~clArr2Float(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� � ������������� ����������.

void clArr2Float::Zero(void)
{
nArr=ln=0; Arr=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void clArr2Float::Free(void)
{
Clear(); SAFE_DELETE_ARR(Arr); nArr=ln=0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� �������� 'float'.

void clArr2Float::Clear(void)
{
UINT i;

if(Arr==NULL||nArr==0) return; for(i=0;i<nArr;i++) SAFE_DELETE(Arr[i]);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE clArr2Float::Alloc(UINT nArr_,UINT ln_)
{
BYTE ber; UINT i;

Free(); if(nArr_==0) return 1; if(ln_==0) return 2; nArr=nArr_; ln=ln_; ber=0;
Arr=new typPntArrFloat[nArr]; if(Arr==NULL) { ber=3; goto end;}
for(i=0;i<nArr;i++) Arr[i]=NULL;
for(i=0;i<nArr;i++) { Arr[i]=new clArrFloat(); if(Arr[i]==NULL) { ber=4; goto end;}
if(Arr[i]->Alloc((UINT)ln)!=0) { ber=5; goto end;}}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE clArr2Float::IsOK(void)
{
if(Arr==NULL) return 1; if(nArr==0) return 2; if(ln==0) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� ������� 'float'.

BYTE clArr2Float::IsOK_(void)
{
UINT i;

if(IsOK()!=0) return 1;
for(i=0;i<nArr;i++) { if(Arr[i]==NULL) return 2; if(Arr[i]->IsOK()!=0) return 3; if(Arr[i]->ln!=ln) return 4;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� �� ����� �������.

clArrFloat *clArr2Float::Get(UINT num)
{
if(IsOK()!=0) return NULL; if(num>=nArr) return NULL; return Arr[num];
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����� ��� ������ ����������� ���� DIB � ���������� ����������� � ������.

//-----------------------------------------------------------------------------------------------------------

clBmpPict::clBmpPict(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clBmpPict::~clBmpPict(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void clBmpPict::Zero(void)
{
ZeroDC(); ZeroBmp(); nCol=0; hFont=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void clBmpPict::Free(void)
{
FreeDC(); FreeBmp(); nCol=0; hFont=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������� ����������� � ����������.

BYTE clBmpPict::IsOK(void)
{
if(hBitmap==NULL) return 1; if(dx<=0||dy<=0) return 2; if(dxB==0) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������� ����������� � ����������.

BYTE clBmpPict::IsOKB(void)
{
if(hBitmap==NULL) return 1; if(dx<=0||dy<=0) return 2; if(dxB==0) return 3; if(pvBits==NULL) return 4;
if(typBmp!=typBmp_24&&typBmp!=typBmp_16&&typBmp!=typBmp_8) return 5; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ���������� ��� �������� �����������.

void clBmpPict::ZeroBmp(void)
{
hBitmap=NULL; pvBits=NULL; dx=dy=0; dxB=0; typBmp=typBmp_24;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ �� �������� �����������.

void clBmpPict::FreeBmp(void)
{
SAFE_DELETE_OBJECT(hBitmap); pvBits=NULL; dx=dy=0; dxB=0; typBmp=typBmp_24;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� �������� ����������� ������� ������.

BYTE clBmpPict::Clear(void)
{
if(IsOKB()!=0) return 1; ZeroMemory((PVOID)pvBits,(DWORD)dxB*(DWORD)dy); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� �������� ����������� �������� ������.

BYTE clBmpPict::Clear(COLORREF Col)
{
BYTE GetColComp(COLORREF Col,BYTE *CC); // ��������� ��������� �����.

BYTE CC[3],Bpp; UINT i,j,dxB_; U_LONG l;

if(IsOKB()!=0) return 1;
switch(typBmp) { default: return 2;
// True Color.
// 16 ���.
case typBmp_24: case typBmp_16: if(GetColComp(Col,CC)!=0) return 3; break;
// 8 ��� (256 ������).
case typBmp_8: if(Col<=255) CC[0]=(BYTE)Col; else CC[0]=255; break;}

for(i=0;i<(UINT)dx;i++) for(j=0;j<(UINT)dy;j++) if(SetPix((int)i,(int)j,CC)!=0) return 4;

switch(typBmp) { default: return 5;
// True Color.
case typBmp_24: Bpp=3; break;
// 16 ���.
case typBmp_16: Bpp=2; break;
// 8 ��� (256 ������).
case typBmp_8: Bpp=1; break;}

dxB_=(UINT)dx*(UINT)Bpp;
if(dxB_<dxB) for(j=0;j<(UINT)dy;j++) { l=(U_LONG)((UINT)dy-1-j)*(U_LONG)dxB;
for(i=dxB_;i<dxB;i++) *(pvBits+(U_LONG)i+l)=0;}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� �������.

BYTE clBmpPict::SetPix(int cx,int cy,BYTE *CC)
{
BYTE SetBitBmp16(BYTE *bt,BYTE *CC); // ��������� ��� ��� ������ � 16-������ ������.

U_LONG l;

if(IsOKB()!=0) return 1;
if(cx<0||cx>=dx) return 2;
if(cy<0||cy>=dy) return 3;
l=(U_LONG)(dy-1-cy)*(U_LONG)dxB;

switch(typBmp) { default: return 4;
// True Color.
case typBmp_24: l+=(U_LONG)cx*3; *(pvBits+l)=CC[2]; *(pvBits+l+1)=CC[1]; *(pvBits+l+2)=CC[0]; break;
// 16 ���.
case typBmp_16: l+=(U_LONG)cx*2; if(SetBitBmp16(pvBits+l,CC)!=0) return 5; break;
// 8 ��� (256 ������).
case typBmp_8: l+=(U_LONG)cx; *(pvBits+l)=CC[0]; break;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ����������.

BYTE clBmpPict::Init(int dx_,int dy_,BYTE typBmp_,DWORD *NCol,SHRT nCol_,HFONT hFont_)
{
BYTE GetBitPerPix(BYTE typ,BYTE *BitCount); // ��������� ����� ��� �� ������.

BYTE BitCount,be,ber; UINT dxB_;

if(dx_<=0||dy_<=0) return 1; if(typBmp_!=typBmp_8&&typBmp_!=typBmp_16&&typBmp_!=typBmp_24) return 2;
if(GetBitPerPix(typBmp_,&BitCount)!=0) return 3; if(BitCount%8!=0) return 4;
if((UINT)dx_>UINT_MAX/(BitCount/8)) return 5;
if(typBmp_==typBmp_8) { if(nCol_<=0) return 6; if(nCol_>256) return 7; if(NCol==NULL) return 8;}
Free(); ber=0;
be=InitImgBitmap(dx_,dy_,typBmp_,&dxB_,&hBitmap,&pvBits,NCol,nCol_);
if(be==messLrgAr||be==messNoMem) { ber=be; goto end;} if(be!=0) { ber=9; goto end;}
if(hBitmap==NULL) { ber=10; goto end;}
dx=dx_; dxB=dxB_; dy=dy_; typBmp=typBmp_; nCol=nCol_; hFont=hFont_;
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� �� ������ ������� ����� � DC.

void clBmpPict::ZeroDC(void)
{
hBitmapOld=NULL; hdc=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// �������� DC � ����� �������� ����������� � ���� DC.

HDC clBmpPict::GetDC(HDC hdc_)
{
BYTE ber;

if(hdc!=NULL) return hdc; if(hdc_==NULL||hBitmap==NULL) return NULL; ber=0;
hdc=CreateCompatibleDC(hdc_); if(hdc==NULL) { ber=1; goto end;}
hBitmapOld=(HBITMAP)SelectObject(hdc,hBitmap); if(hBitmapOld==NULL) { ber=2; goto end;}
SetROP2(hdc,R2_COPYPEN); SetBkMode(hdc,TRANSPARENT); if(hFont!=NULL) SelectObject(hdc,hFont);
SelectObject(hdc,GetStockObject(WHITE_BRUSH));
SelectObject(hdc,GetStockObject(WHITE_PEN));
end: if(ber!=0) { FreeDC(); return NULL;} return hdc;
}

//-----------------------------------------------------------------------------------------------------------
// ����� ������� �������� ����������� � ����������� DC.

void clBmpPict::FreeDC(void)
{
if(hdc==NULL) return; if(hBitmapOld!=NULL) { SelectObject(hdc,hBitmapOld); hBitmapOld=NULL;}
SelectObject(hdc,GetStockObject(SYSTEM_FONT)); DeleteDC(hdc); hdc=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ����� �����������.

BYTE clBmpPict::Image(HDC hdcD,int xiD,int yiD,int dxD,int dyD,int xiS,int yiS,int dxS,int dyS,BYTE stretch)
{
BYTE bNew,ber; int dxS_,dyS_; BOOL b;

if(hdcD==NULL) return 1; if(IsOK()!=0) return 2; if(dxD<=0||dyD<=0) return 3; if(dxS<=0||dyS<=0) return 4;
if(xiS<0||yiS<0) return 5; if(xiS>=dx||yiS>=dy) return 6;
dxS_=dxS; if(xiS+dxS_>dx) dxS_=dx-xiS;
dyS_=dyS; if(yiS+dyS_>dy) dyS_=dy-yiS;
ber=0;
if(hdc==NULL) { if(GetDC(hdcD)==NULL) { ber=7; goto end;} bNew=1;} else bNew=0;
if(stretch==0) b=BitBlt(hdcD,xiD,yiD,MIN(dxD,dxS_),MIN(dyD,dyS_),hdc,xiS,yiS,SRCCOPY);
else b=StretchBlt(hdcD,xiD,yiD,dxD,dyD,hdc,xiS,yiS,dxS_,dyS_,SRCCOPY);
if(b==FALSE) { ber=8; goto end;}
end: if(bNew!=0) FreeDC(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� �����������.

BYTE clBmpPict::GetImg(HDC hdc_,int xi_,int yi_,int dx_,int dy_)
{
BYTE bNew,ber;

if(hdc_==NULL) return 1; if(IsOK()!=0) return 2; if(dx_<=0||dy_<=0) return 3; ber=0;
if(hdc==NULL) { if(GetDC(hdc_)==NULL) { ber=4; goto end;} bNew=1;} else bNew=0;
if(BitBlt(hdc,0,0,MIN(dx_,dx),MIN(dy_,dy),hdc_,xi_,yi_,SRCCOPY)==FALSE) { ber=5; goto end;}
end: if(bNew!=0) FreeDC(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ����������� � ����� '*.bmp'.

BYTE clBmpPict::Save(HANDLE File,DWORD *NCol,SHRT nCol)
{
BYTE GetBitPerPix(BYTE typ,BYTE *BitCount); // ��������� ����� ��� �� ������.
BYTE WriteDIB_FH(HANDLE File,DWORD *szFile,BYTE Bpp,int dx,int dy,BYTE *BytesDIB,DWORD *NCol,SHRT nCol); // ������ ����������� 'DIB' � ����.

BYTE Bpp;

if(File==INVALID_HANDLE_VALUE) return 1; if(IsOKB()!=0) return 2;
if(typBmp==typBmp_8) { if(NCol==NULL) return 3; if(nCol<=0||nCol>256) return 4;}
if(GetBitPerPix(typBmp,&Bpp)!=0) return 5; Bpp/=8;
if(WriteDIB_FH(File,NULL,Bpp,dx,dy,pvBits,NCol,nCol)!=0) return 6; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����������� � ������.

//-----------------------------------------------------------------------------------------------------------

clImgMem::clImgMem(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clImgMem::~clImgMem(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void clImgMem::Zero(void)
{
hdc=NULL; ZeroBmp();
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void clImgMem::Free(void)
{
FreeBmp(); FreeDC();
}

//-----------------------------------------------------------------------------------------------------------
// �������� 'hdc' �� ������.

void clImgMem::FreeDC(void)
{
if(hdc==NULL) return; SelectObject(hdc,GetStockObject(SYSTEM_FONT)); DeleteDC(hdc); hdc=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void clImgMem::ZeroBmp(void)
{
hBitmap=hBitmapOld=NULL; dx=dy=0; dxB=0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������� ����������� 'hBitmap' �� 'hdc' � �� ������.

void clImgMem::FreeBmp(void)
{
if(hBitmap!=NULL) UnSelectBmp(); SAFE_DELETE_OBJECT(hBitmap); dx=dy=0; dxB=0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������� ����������� 'hBitmap'.

BYTE clImgMem::CreateBmp(int dx_,int dy_)
{
BYTE be; UINT dxB_;

if(dx_<=0||dy_<=0) return 1;
be=InitImgBitmap(dx_,dy_,typBmp_24,&dxB_,&hBitmap,NULL,NULL,0);
if(be==messLrgAr||be==messNoMem) return be; if(be!=0) return 2;
dx=dx_; dy=dy_; dxB=dxB_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� 'hdc' � ����� �������� ����������� 'hBitmap' � 'hdc'.

BYTE clImgMem::Create(HDC hdc_,int dx_,int dy_,HFONT hFont,BYTE mess)
{
BYTE be,ber;

Free(); if(hdc_==NULL) return 1; ber=0;
hdc=CreateCompatibleDC(hdc_); if(hdc==NULL) { ber=2; goto end;}
be=CreateBmp(dx_,dy_); if(be!=0) {
if(be==messLrgAr||be==messNoMem) { if(mess!=0) Message(IDS_Err_NoMemBitmap,MB_ST); ber=be;} else ber=3; goto end;}
if(SelectBmp()!=0) { ber=4; goto end;}
if(SetPar(hFont)!=0) { ber=5; goto end;}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ����� �������� ������ 'hBitmap' � 'hdc'.

BYTE clImgMem::SelectBmp(void)
{
if(IsOK()!=0) return 1; if(hBitmapOld!=NULL) return 2;
hBitmapOld=(HBITMAP)SelectObject(hdc,hBitmap); if(hBitmapOld==NULL) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������� ������ 'hBitmap' �� 'hdc'.

void clImgMem::UnSelectBmp(void)
{
if(hBitmapOld!=NULL&&hdc!=NULL) { SelectObject(hdc,hBitmapOld); hBitmapOld=NULL;}
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � 'hdc' � ������������ ������ �� ���������.

BYTE clImgMem::SetPar(HFONT hFont)
{
if(IsOKImg()!=0) return 1; SetROP2(hdc,R2_COPYPEN); SetBkMode(hdc,TRANSPARENT);
if(hFont!=NULL) SelectObject(hdc,hFont); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ����������.

BYTE clImgMem::IsOK(void)
{
if(hBitmap==NULL) return 1; if(hdc==NULL) return 2;
if(dx<=0||dy<=0) return 3; if(dx>SHRT_MAX||dy>SHRT_MAX) return 4;
if(dxB==0) return 5; if(dxB>USHRT_MAX) return 6; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ���������� � ����, ��� ������� ����������� ������� � 'hdc'.

BYTE clImgMem::IsOKImg(void)
{
if(IsOK()!=0) return 1; if(hBitmapOld==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��� � ������� 'True color'.

BYTE clImgMem::SetBitsTrCol(int dx_,int dy_,BYTE *Bits)
{
BYTE ber; BITMAPINFO *BMInfo;

if(dx_<=0||dy_<=0) return 1; if(IsOKImg()!=0) return 2; if(dx_!=dx||dy_!=dy) return 3;
if(Bits==NULL) return 4; BMInfo=NULL; ber=0;
if(CreateInfoBMP(&BMInfo,dx,dy,typBmp_24,NULL,0)!=0) { ber=5; goto end;}
if(SetDIBits(hdc,hBitmap,0,dy,Bits,BMInfo,DIB_RGB_COLORS)==0) { ber=6; goto end;}
end: DeleteInfoBMP(&BMInfo); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��� � ������� �����-����-������ ����������� � 1 ������ �� ������.

BYTE clImgMem::SetBitsGrayCol(int dx_,int dy_,BYTE *Bits)
{
BYTE i,ber; SHRT nCol; DWORD *NCol; BITMAPINFO *BMInfo;

if(dx_<=0||dy_<=0) return 1; if(IsOKImg()!=0) return 2; if(dx_!=dx||dy_!=dy) return 3;
if(Bits==NULL) return 4;
BMInfo=NULL; NCol=NULL; ber=0; nCol=(SHRT)UCHAR_MAX;
if(AllocDWORD(&NCol,(size_t)nCol)!=0) { ber=5; goto end;}
for(i=0;i<nCol;i++) NCol[i]=RGB(i,i,i);
if(CreateInfoBMP(&BMInfo,dx,dy,typBmp_8,NCol,nCol)!=0) { ber=6; goto end;}
if(SetDIBits(hdc,hBitmap,0,dy,Bits,BMInfo,DIB_RGB_COLORS)==0) { ber=7; goto end;}
end: DeleteInfoBMP(&BMInfo); FreeDWORD(&NCol); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� ������ 'clImgMem'.

BYTE InitBmpMem_(HWND hwnd,clImgMem **Bmp,int dx,int dy,BYTE mess)
{
void DeleteBmpMem_(clImgMem **Bmp); // �������� ������� ������ 'clImgMem'.

BYTE be,ber; HDC hdc;

DeleteBmpMem_(Bmp); if(hwnd==NULL) return 1; if(Bmp==NULL) return 2; if(dx<=0||dy<=0) return 3;
hdc=GetDC(hwnd); if(hdc==NULL) return 4; ber=0;
*Bmp=new clImgMem(); if(*Bmp==NULL) { ber=5; goto end;}
be=(*Bmp)->Create(hdc,dx,dy,NULL,mess); if(*Bmp==NULL) { ber=5; goto end;}
if(be!=0) { if(be==messNoMem||be==messLrgAr) ber=messNoMem; else ber=6; goto end;}
end: ReleaseDC(hwnd,hdc); if(ber!=0) DeleteBmpMem_(Bmp); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������� ������ 'clImgMem'.

void DeleteBmpMem_(clImgMem **Bmp)
{
if(Bmp==NULL) return; SAFE_DELETE(*Bmp);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// �������� � �������� ������.

//-----------------------------------------------------------------------------------------------------------

clFileT::clFileT(void)
{
File=-1; file=NULL;
}

//-----------------------------------------------------------------------------------------------------------

clFileT::~clFileT(void)
{
Close();
}

//-----------------------------------------------------------------------------------------------------------
// �������� �����.

void clFileT::Close(void)
{
if(file!=NULL) { fclose(file); file=NULL;} if(File!=-1) { _close(File); File=-1;}
}

//-----------------------------------------------------------------------------------------------------------
// �������� �����.

BYTE clFileT::Open(char *name,BYTE wr)
{
BYTE ber; char *mode;

Close(); if(name==NULL) return 1; ber=0;
if(wr==0) File=_open(name,_O_RDONLY|_O_SEQUENTIAL|_O_TEXT);
else File=_open(name,_O_CREAT|_O_WRONLY|_O_SEQUENTIAL|_O_TEXT|_O_TRUNC,_S_IREAD|_S_IWRITE);
if(File==-1) { ber=2; goto end;}

if(wr==0) mode="rt"; else mode="wt";
file=fdopen(File,mode); if(file==NULL) { ber=3; goto end;}

end: if(ber!=0) Close(); 
return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����� ��� ������ � �������.

//-----------------------------------------------------------------------------------------------------------

clOFN::clOFN(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clOFN::~clOFN(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������.

void clOFN::Zero(void)
{
SET_ZERO(&ofn); ofn.lStructSize=sizeof(OPENFILENAME);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE clOFN::Init(USHRT szFile,USHRT szFileTitle)
{
Free(); if(szFile==0) return 1; if(szFileTitle==0) return 2;
if(AllocString(&ofn.lpstrFile,(size_t)szFile)!=0) return 3; ofn.nMaxFile=(DWORD)szFile;
if(AllocString(&ofn.lpstrFileTitle,(size_t)szFileTitle)!=0) return 4; ofn.nMaxFileTitle=(DWORD)szFileTitle;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������ �� �����.

void clOFN::Free(void)
{
FreeString(&ofn.lpstrFile); ofn.nMaxFile=0;
FreeString(&ofn.lpstrFileTitle); ofn.nMaxFileTitle=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE clOFN::IsOK(void)
{
if(ofn.lpstrFile==NULL) return 1; if(ofn.nMaxFile==0) return 2;
if(ofn.lpstrFileTitle==NULL) return 3; if(ofn.nMaxFileTitle==0) return 4;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����� ����� ��� �������� ��� ����������.

BYTE clOFN::Open(BYTE flSave,char *Filter,char *ExtIni,char *ExtDef,char *PathToDir,char *FileNameIni,
HWND hwndOwner,UINT IDS_Header,BYTE flExtDiff,BYTE flCase)
{
BYTE GetFilter(char *Filter); // ������ ������� - ����������� �� ���� � ������ � �������� ��� �������� ������.
BYTE GetExtPnt(char **ExtPnt,char *Ext); // ��������� ���������� � ������.
BYTE FindNumFilter(char *Filter,char *Ext,BYTE *num,BYTE flCase); // ���������� ������ ���� ����� �� ������ ������� � ������ ����������.
BYTE LoadDupString(char **Str,UINT StrID,char *Def); // �������� ������.
BYTE CheckExtListFilt(char *Str,char *Filter,BYTE nIndex,BYTE flCase,BYTE *flag); // �������� ������������ ������ ���������� ����� ������ ���������� � ������ �������.
BYTE MessQuestFileOverWrite(char *fName); // ������ � ���������� ��� ������� ����� � ������ ������.
BYTE CompareStr_(char *strA,char *strB,BYTE flCase); // ��������� ����� (� ������ ����� ����� � ���� ���� � ���������� ��������� � �������� ����).

BYTE nIndex,n,fl,be,ber; BOOL bl; DWORD dw;
char *Filt,*FileName,*FileNameIni_,*ExtIni_,*ExtI,*ExtPnt,*Header,*cp;

if(IsOK()!=0) return 1; if(IsOKStr(Filter)!=0) return 2;

ofn.lpstrInitialDir=PathToDir;
if(ExtDef!=NULL) { cp=strchr(ExtDef,'.'); if(cp!=NULL) cp++; else cp=ExtDef;} else cp=NULL; ofn.lpstrDefExt=cp;
ofn.hwndOwner=hwndOwner; ofn.lpstrFilter=NULL; strcpy(ofn.lpstrFileTitle,"");

Filt=FileName=FileNameIni_=ExtIni_=ExtPnt=Header=NULL; ber=0;

if(DupString(&Filt,Filter)!=0) { ber=3; goto end;}
if(GetFilter(Filt)!=0) { ber=4; goto end;}
ofn.lpstrFilter=Filt;

// ��������� ���������� ����� �����.
if(flSave!=0) {	if(DupString(&FileNameIni_,FileNameIni)==0) { cp=strchr(FileNameIni_,'.'); if(cp!=NULL) *cp='\0';}}

// ��������� ���������� ����������.
ExtI=ExtIni; if(flSave!=0&&IsOKStr(ExtI)!=0) { cp=strchr(FileNameIni,'.'); if(cp!=NULL) ExtI=cp;}

// ��������� ���������� � ������.
GetExtPnt(&ExtPnt,ExtI);

// ���������� ������ ���������� � ������.
if(FindNumFilter(Filter,ExtPnt,&nIndex,flCase)!=0) nIndex=0; ofn.nFilterIndex=(DWORD)nIndex+1;

// ���������� ������ � ������ ����� ������� ����.
if(flSave!=0&&FileNameIni_!=NULL) {
if(GetName(&FileName,PathToDir,NULL,FileNameIni_,NULL)!=0) { ber=5; goto end;}
if(strlen(FileName)>ofn.nMaxFile) { Message(IDS_Err_LongFilePathName,MB_ST); ber=6; goto end;}
strcpy(ofn.lpstrFile,FileName);}
else strcpy(ofn.lpstrFile,"");

// ��������� ��������� ����������� ����.
if(IDS_Header!=0) { if(LoadDupString(&Header,IDS_Header,NULL)==0) ofn.lpstrTitle=Header;}

rep:
// ��������� ������.
if(flSave==0) dw=OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST; // ����� ������.
else dw=OFN_CREATEPROMPT|OFN_OVERWRITEPROMPT; // ����� ����������.
dw|=OFN_HIDEREADONLY; if(flExtDiff!=0) dw|=OFN_EXTENSIONDIFFERENT; ofn.Flags=dw;

if(flSave==0) bl=GetOpenFileName(&ofn); // �������� ������������� �����.
else bl=GetSaveFileName(&ofn); // ��������� ����� ������ ����� ��� ����������.

if(bl==FALSE) { dw=CommDlgExtendedError();
if(dw==FNERR_BUFFERTOOSMALL) Message(IDS_Err_LongFilePathName,MB_ST);
if(dw!=0) { ber=7; goto end;} ber=messRet; goto end;}

// ������ ����������.
cp=strchr(ofn.lpstrFileTitle,'.');

// �������� �������� ������������ ���������� ����� ���������.
if(flExtDiff!=0) { if(cp!=NULL&&ExtPnt!=NULL) {
if(CompareStr_(cp,ExtPnt,flCase)!=0) { Message(IDS_Err_WrongExtFile,MB_EX); ber=messRet; goto end;}}}

// �������� ������������ ������ ���������� ����� ������ ���������� � ������ �������.
dw=ofn.nFilterIndex; if(dw>UCHAR_MAX) { ber=8; goto end;}
n=(BYTE)dw; if(n==0) { ber=9; goto end;} n--;
if(CheckExtListFilt(cp,Filter,n,flCase,&fl)!=0) fl=flFiltStr_Error;

if(fl==flFiltStr_List) { Message(IDS_Err_AmbigChoiceExt,MB_IN); goto rep;}
if(fl==flFiltStr_Error||fl==flFiltStr_NotFound) { ofn.nFilterIndex=0; Message(IDS_Mess_WarningWrongExt,MB_IN);}

// �������� ������������� ����� � ������ � ����������.
if(flSave!=0) { cp=ofn.lpstrFile;
if(IsFileExist_(cp)==0) { be=MessQuestFileOverWrite(cp);
if(be!=0&&be!=messRet) { ber=10; goto end;} if(be==0) { ber=messRet; goto end;}}}

end: FreeString(&Filt); FreeString(&FileName); FreeString(&FileNameIni_); FreeString(&ExtIni_);
FreeString(&ExtPnt); FreeString(&Header); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����� ����� � ���� � �����.

BYTE clOFN::GetFilePath(char *FileName,USHRT szFileName,char *PathToDir,USHRT szPathToDir,char *Exten,
USHRT szExten,BYTE cutExt,USHRT *nFiltInd)
{
char *cp; DWORD *dwp;

if(FileName==NULL) return 1; if(szFileName==0) return 2;
if(PathToDir==NULL) return 3; if(szPathToDir==0) return 4;
if(IsOK()!=0) return 5;
if((size_t)szFileName<=strlen(ofn.lpstrFileTitle)) return 6; strcpy(FileName,ofn.lpstrFileTitle); 
if((size_t)szPathToDir<=strlen(ofn.lpstrFile)) return 7; strcpy(PathToDir,ofn.lpstrFile);
cp=strstr(PathToDir,FileName); if(cp==NULL) return 8; *cp='\0';

cp=strchr(FileName,'.'); if(cp!=NULL) {
if(Exten!=NULL) { if(strlen(cp)>=(size_t)szExten) return 9; strcpy(Exten,cp);}
if(cutExt!=0) *cp='\0';}
else if(Exten!=NULL&&szExten>1) strcpy(Exten,".");
if(strlen(FileName)==0) return 10;

if(nFiltInd!=NULL) { dwp=&ofn.nFilterIndex; if(*dwp>USHRT_MAX) return 11; *nFiltInd=(USHRT)*dwp;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������� ����������� ������ ��� ������� ����� ����� � �������� ��� ����� � ����������.

BYTE GetNameFileOpen(HWND hwnd,BYTE flSave,char *StrFilt,UINT IDS_Filt,USHRT *nFilterIndex,char *PathToDir,
char *FileNameIni,char *Ext,char *PathToDirN,USHRT szPathToDirN,char *FileNameN,USHRT szFileNameN,char *ExtN,
USHRT szExtN,BYTE cutExt,BYTE flChExt,UINT IDS_Header)
{
BYTE LoadDupString(char **Str,UINT StrID,char *Def); // �������� ������.

BYTE be,ber; char *Filt; clOFN *OFN;

if(PathToDir==NULL) return 1; if(PathToDirN==NULL) return 2; if(szPathToDirN==0) return 3;
if(FileNameN==NULL) return 4; if(szFileNameN==0) return 5;
if(ExtN==NULL) return 6; if(szExtN==0) return 7;
if(IDS_Filt<=0&&StrFilt==NULL||IDS_Filt>0&&StrFilt!=NULL) return 8;

Filt=NULL; OFN=NULL; ber=0;
OFN=new clOFN(); if(OFN==NULL) { ber=9; goto end;}

if(OFN->Init(szPathToDirN,szFileNameN)!=0) { ber=10; goto end;}

// ��������� ������ � ��������.
if(StrFilt==NULL) { if(LoadDupString(&Filt,IDS_Filt,NULL)!=0) { ber=11; goto end;}}
else { if(DupString(&Filt,StrFilt)!=0) { ber=12; goto end;}}

be=OFN->Open(flSave,Filt,Ext,Ext,PathToDir,FileNameIni,hwnd,IDS_Header,flChExt,0);
if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=13; goto end;}
if(OFN->GetFilePath(FileNameN,szFileNameN,PathToDirN,szPathToDirN,ExtN,szExtN,cutExt,nFilterIndex)!=0) { ber=14; goto end;}

end: SAFE_DELETE(OFN); FreeString(&Filt); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����� �����.

//-----------------------------------------------------------------------------------------------------------

clListString::clListString(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clListString::~clListString(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� � ������������� ����������.

void clListString::Zero(void)
{
nList=0; List=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void clListString::Free(void)
{
Clear(); SAFE_DELETE_ARR(List); nList=0;
}

//-----------------------------------------------------------------------------------------------------------
// �������� �����.

void clListString::Clear(void)
{
USHRT i;

if(IsOK()!=0) return; for(i=0;i<nList;i++) SAFE_DELETE(List[i]);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

BYTE clListString::Alloc(USHRT nList_)
{
BYTE ber; USHRT i;

Free(); if(nList_==0) return 1; nList=nList_; ber=0;
List=new char *[nList]; if(List==NULL) { ber=2; goto end;}
for(i=0;i<nList;i++) List[i]=NULL;
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE clListString::IsOK(void)
{
if(List==NULL) return 1; if(nList==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������ � ������.

BYTE clListString::Set(USHRT num,char *txt)
{
if(IsOK()!=0) return 1; if(num>=nList) return 2; if(DupString(List+num,txt)!=0) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ������.

char *clListString::Get(USHRT num)
{
if(IsOK()!=0) return NULL; if(num>=nList) return NULL; return List[num];
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ����� ������� "*.htm" ����� 'Explorer'.

//-----------------------------------------------------------------------------------------------------------

clHelpEx::clHelpEx(void)
{
Zero(); CreateLS();
}

//-----------------------------------------------------------------------------------------------------------

clHelpEx::~clHelpEx(void)
{
Free(); FreeLS();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � ������������� ����������.

void clHelpEx::Zero(void)
{
Name=CurrDir=NULL; ZeroLS();
}

//-----------------------------------------------------------------------------------------------------------
// �������� �������.

void clHelpEx::Free(void)
{
FreeString(&Name); FreeString(&CurrDir);
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ��������� �� ����� ������ �����.

void clHelpEx::ZeroLS(void)
{
LS=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������ ������ �����.

void clHelpEx::FreeLS(void)
{
SAFE_DELETE(LS);
}

//-----------------------------------------------------------------------------------------------------------
// �������� ������ �����.

BYTE clHelpEx::CreateLS(void)
{
FreeLS(); LS=new clListString(); if(LS==NULL) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ������ ������ �����.

BYTE clHelpEx::ReadLS(void)
{
BYTE ber; int iv; char *NameInf; clFileT *FT;

if(LS==NULL) return 1; LS->Free(); if(IsOKStr(CurrDir)!=0) return 2;
NameInf=NULL; FT=NULL; ber=0;
if(GetName(&NameInf,CurrDir,NULL,"Topics",".inf")!=0) { ber=3; goto end;}
if(IsFileExist_(NameInf)!=0) { ber=messRet; goto end;} // �������� ������������� �����.
FT=new clFileT(); if(FT==NULL) { ber=4; goto end;}
if(FT->Open(NameInf,0)!=0) { ber=5; goto end;}
if(fscanf(FT->file,"%d\n",&iv)==EOF) { ber=6; goto end;} if(iv<0||iv>USHRT_MAX) { ber=7; goto end;}
if(iv==0) goto end;
if(LS->Alloc((USHRT)iv)!=0) { ber=8; goto end;}

while(1) {
if(fscanf(FT->file,"%d%s",&iv,TxtStr)==EOF) break; if(iv<=0||iv>USHRT_MAX) { ber=9; goto end;}
if(iv>=LS->nList) continue;
if(LS->Set(iv-1,TxtStr)!=0) { ber=10; goto end;}
if(fscanf(FT->file,"\n")==EOF) break;}

end: SAFE_DELETE(FT); FreeString(&NameInf); if(ber!=0) LS->Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ����� �������.

BYTE clHelpEx::Show(char *Topic)
{
BYTE Process(char *Path,char *Dir,char *Name,char *ComStr,char *CurrDir,BYTE show,BYTE wait); // ������ ������ ���������.

BYTE n,ber; char *ComStr,*PathSys,*Path,*Items[5],*cp;

if(IsOKStr(Name)!=0) return 1;
PathSys=Path=ComStr=NULL; ber=0;

if(AllocString(&PathSys,(size_t)MAX_PATH)!=0) { ber=2; goto end;}
if(GetSystemDirectory((LPTSTR)PathSys,MAX_PATH)==0) { ber=3; goto end;}
cp=strchr(PathSys,':'); if(cp==NULL) { ber=4; goto end;} *cp='\0';
Items[0]=PathSys; Items[1]=":\\Program Files\\Internet Explorer\\";
if(GetString(&Path,Items,2)!=0) { ber=5; goto end;}

Items[0]="-nohome "; Items[1]=CurrDir; Items[2]=Name; n=3;
if(IsOKStr(Topic)==0) { Items[3]="#"; Items[4]=Topic; n+=2;}
if(GetString(&ComStr,Items,n)!=0) { ber=6; goto end;}

if(Process(Path,NULL,"iexplore.exe",ComStr,CurrDir,1,0)!=0) { ber=7; goto end;}

end: FreeString(&PathSys); FreeString(&Path); FreeString(&ComStr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ���������� � �������� ������� �����.

BYTE clHelpEx::Set(char *Path,char *Dir,char *DirFile,char *Name_)
{
BYTE ber;

Free(); if(IsOKStr(Name_)!=0) return 1; ber=0;
if(GetName(&CurrDir,Path,Dir,DirFile,"\\")!=0) { ber=2; goto end;}
if(GetName(&Name,NULL,NULL,Name_,extHTM)!=0) { ber=3; goto end;}
if(IsFileExist(Name,CurrDir,NULL,NULL)!=0) { ber=4; goto end;}
ReadLS(); // ������ ������ �����.
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// ����� ���������� ����� �������.

void clHelpEx::ShowContent(void)
{
Show(NULL);
}

//-----------------------------------------------------------------------------------------------------------
// ����� ������� �� �������� ����.

BYTE clHelpEx::ShowTopic(DWORD Topic)
{
char *cp;

if(Topic>USHRT_MAX) return 1; if(Topic==0) return 2; if(LS==NULL) return 3;
cp=LS->Get((USHRT)Topic-1); if(cp==NULL) return 4; if(Show(cp)!=0) return 5; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� ������� ��������� �������.

//-----------------------------------------------------------------------------------------------------------

strSndArr::strSndArr(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

strSndArr::~strSndArr(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� ����������.

void strSndArr::Zero(void)
{
ln=0; Snd=NULL; dt=0.;
}

//-----------------------------------------------------------------------------------------------------------
// ������������ ������.

void strSndArr::Free(void)
{
SAFE_DELETE_ARR(Snd); ln=0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE strSndArr::Create(UINT ln_)
{
Free(); if(ln_==0) return 1; ln=ln_; Snd=new float[ln]; if(Snd==NULL) { ln=0; return 2;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ��������.

BYTE strSndArr::IsOK(void)
{
if(ln==0) return 1; if(Snd==NULL) return 2; if(dt<=0.) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ��������� �����.

BYTE FillSndArr(clWavData *WAV,strSndArr *Snd)
{
UINT i;

if(WAV==NULL) return 1; if(WAV->IsOKSnd()!=0) return 2; if(Snd==NULL) return 3; Snd->Free();
if(Snd->Create(WAV->ln)!=0) return 4;
// ���� ������ - ������ ��������.
if(WAV->ch==1) {
if(WAV->nBS==1) for(i=0;i<WAV->ln;i++) Snd->Snd[i]=(float)((SHRT)*(WAV->bSnd[0]+i)-128);
else for(i=0;i<WAV->ln;i++) Snd->Snd[i]=(float)*(WAV->sSnd[0]+i);
}
// ������ ������ - ��������� �������.
else {
if(WAV->nBS==1) for(i=0;i<WAV->ln;i++) Snd->Snd[i]=(float)((SHRT)*(WAV->bSnd[0]+i)+(SHRT)*(WAV->bSnd[1]+i)-256)*0.5F;
else for(i=0;i<WAV->ln;i++) Snd->Snd[i]=(float)(*(WAV->sSnd[0]+i)+*(WAV->sSnd[1]+i))*0.5F;
}

Snd->dt=1./(double)WAV->pwf->nSamplesPerSec;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������� � ������� "WAV".

BYTE FillWavData(strSndArr *Snd,clWavData *WAV)
{
UINT GetUINT_Test(double d); // ��������� ����� 'UINT' �� ����� 'double' � ��������� ������ �� ������� 'UINT'.
SHRT GetSHRT_Test(float v); // ��������� ����� 'SHRT' �� ����� 'float' � ��������� ������ �� ������� 'SHRT'.

UINT i;

if(Snd==NULL) return 1; if(Snd->IsOK()!=0) return 2; if(WAV==NULL) return 3; WAV->FreeSnd();
WAV->Init_Header(1,2,(DWORD)GetUINT_Test(1./Snd->dt)); if(WAV->AllocSnd(Snd->ln,1,2)!=0) return 4;
for(i=0;i<Snd->ln;i++) *(WAV->sSnd[0]+i)=GetSHRT_Test(Snd->Snd[i]); return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� �������.

//-----------------------------------------------------------------------------------------------------------
// �����������.

strPal::strPal(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// ��������� �������.

void strPal::Zero(void)
{
BYTE k,i;

for(i=0;i<nColSmoothPal;i++) for(k=0;k<3;k++) MasRGB[i][k]=0;
}

//-----------------------------------------------------------------------------------------------------------
// ���������� ������ ���������� �������.

BYTE strPal::FillColor(DWORD *ColBase)
{ 
BYTE i,k,j,cI,cF; USHRT p; DWORD ColI,ColF; 

if(ColBase==NULL) return 1;
for(j=0;j<nColB-1;j++) { ColI=ColBase[j]; ColF=ColBase[j+1];
for(k=0;k<nPalStep;k++) { p=nPalStep*j+k;
for(i=0;i<3;i++) {
switch(i) { default:
case 0: cI=GetRValue(ColI); cF=GetRValue(ColF); break;
case 1: cI=GetGValue(ColI); cF=GetGValue(ColF); break;
case 2: cI=GetBValue(ColI); cF=GetBValue(ColF); break;
}
MasRGB[p][i]=(BYTE)(((float)(cF-cI)/(float)nPalStep)*(float)k+(float)cI);}}}
j=nColB-1; p=nPalStep*j; ColI=ColBase[j];
for(i=0;i<3;i++) {
switch(i) { default:
case 0: cI=GetRValue(ColI); break;
case 1: cI=GetGValue(ColI); break;
case 2: cI=GetBValue(ColI); break;}
MasRGB[p][i]=cI;}
return 0;
}
