/*...........................................................................................................

clString,clArrBYTE,clArrFloat,clArrDouble,clArr2Float,
clBmpPict,clImgMem,clFileT,clOFN,strSndArr,strPal,clListString,clHelpEx

...........................................................................................................*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ������.

class clString {

void Zero(void); // ��������� ��������� � ������������� ����������.

public:

UINT sz; char *String;

clString(void);
~clString(void);
void Free(void); // ������������ ������.
BYTE Alloc(UINT sz_); // ��������� ������.
BYTE IsOK(void); // ��������.
BYTE SetZero(void); // ��������� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ������� 'BYTE'.

class clArrBYTE {

void Zero(void); // ��������� ��������� � ������������� ����������.

public:

UINT ln; BYTE *Arr;

clArrBYTE(void);
~clArrBYTE(void);
void Free(void); // ������������ ������.
BYTE Alloc(UINT ln_); // ��������� ������.
BYTE IsOK(void); // ��������.
BYTE SetZero(void); // ��������� �������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ������� 'float'.

class clArrFloat {

void Zero(void); // ��������� ��������� � ������������� ����������.

public:

UINT ln; float *Arr;

clArrFloat(void);
~clArrFloat(void);
void Free(void); // ������������ ������.
BYTE Alloc(UINT ln_); // ��������� ������.
BYTE IsOK(void); // ��������.
BYTE SetZero(void); // ��������� �������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��� - ��������� �� ����� ������� 'float'.

typedef clArrFloat *typPntArrFloat;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ������� 'double'.

class clArrDouble {

void Zero(void); // ��������� ��������� � ������������� ����������.
void Free(void); // ������������ ������.

public:

UINT ln; double *Arr;

clArrDouble(void);
~clArrDouble(void);
BYTE Alloc(UINT ln_); // ��������� ������.
BYTE IsOK(void); // ��������.
BYTE SetZero(void); // ��������� �������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ���������� ������� ����� 'float'.

class clArr2Float {

typPntArrFloat *Arr;

void Zero(void); // ��������� ��������� � ������������� ����������.
void Clear(void); // �������� ������� �������� 'float'.

public:

UINT nArr,ln;

clArr2Float(void);
~clArr2Float(void);
void Free(void); // ������������ ������.
BYTE Alloc(UINT nArr_,UINT ln_); // ��������� ������.
BYTE IsOK(void); // ��������.
BYTE IsOK_(void); // �������� ������� ������� 'float'.
clArrFloat *Get(UINT num); // ��������� ��������� �� ����� �������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ��� ������ ����������� ���� DIB � ���������� ����������� � ������.

class clBmpPict {

HDC hdc; HBITMAP hBitmap,hBitmapOld; HFONT hFont;

void Zero(void); // ��������� ���������� � ������������� ����������.
void ZeroDC(void); // ��������� ���������� �� ������ ������� ����� � DC.
void ZeroBmp(void); // ��������� ���������� � ������������� ���������� ��� �������� �����������.
void FreeBmp(void); // ������������ ������ �� �������� �����������.
BYTE SetPix(int cx,int cy,BYTE *CC); // ��������� �������.

public:

BYTE typBmp,*pvBits; SHRT nCol; int dx,dy; UINT dxB;

clBmpPict(void);
~clBmpPict(void);
BYTE IsOK(void); // �������� �������� ����������� � ����������.
BYTE IsOKB(void); // �������� �������� ����������� � ����������.
BYTE Clear(void); // ���������� �������� ����������� ������� ������.
BYTE Clear(COLORREF Col); // ���������� �������� ����������� �������� ������.
HDC GetDC(HDC hdc_); // �������� DC � ����� �������� ����������� � ���� DC.
void FreeDC(void); // ����� ������� �������� ����������� � ����������� DC.
void Free(void); // ������������ ������.
BYTE Init(int dx_,int dy_,BYTE typBmp_,DWORD *NCol,SHRT nCol_,HFONT hFont_); // ������� ����������.
BYTE Image(HDC hdcD,int xiD,int yiD,int dxD,int dyD,int xiS,int yiS,int dxS,int dyS,BYTE stretch); // ����� �����������.
BYTE GetImg(HDC hdc_,int xi_,int yi_,int dx_,int dy_); // ��������� �����������.
BYTE Save(HANDLE File,DWORD *NCol,SHRT nCol); // ���������� ����������� � ����� '*.bmp'.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� � ������.

class clImgMem {

HBITMAP hBitmap,hBitmapOld;

void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
void FreeDC(void); // �������� 'hdc' �� ������.
void ZeroBmp(void); // ��������� ���������� � ������������� ����������.
void FreeBmp(void); // �������� �������� ����������� 'hBitmap' �� 'hdc' � �� ������.
BYTE CreateBmp(int dx_,int dy_); // �������� �������� ����������� 'hBitmap'.
BYTE SelectBmp(void); // ����� �������� ������ 'hBitmap' � 'hdc'.
void UnSelectBmp(void); // �������� �������� ������ 'hBitmap' �� 'hdc'.
BYTE IsOK(void); // �������� ����������.

public:

HDC hdc; int dx,dy; UINT dxB;

clImgMem(void);
~clImgMem(void);
BYTE Create(HDC hdc_,int dx_,int dy_,HFONT hFont,BYTE mess); // �������� 'hdc' � ����� �������� ����������� 'hBitmap' � 'hdc'.
BYTE SetPar(HFONT hFont); // ��������� ���������� � 'hdc' � ������������ ������ �� ���������.
BYTE IsOKImg(void); // �������� ���������� � ����, ��� ������� ����������� ������� � 'hdc'.
BYTE SetBitsTrCol(int dx_,int dy_,BYTE *Bits); // ��������� ��� � ������� 'True color'.
BYTE SetBitsGrayCol(int dx_,int dy_,BYTE *Bits); // ��������� ��� � ������� �����-����-������ ����������� � 1 ������ �� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� � �������� ������.

class clFileT {

int File;

public:

FILE *file;

clFileT(void);
~clFileT(void);
void Close(void); // �������� �����.
BYTE Open(char *name,BYTE wr); // �������� �����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ��� ������ � �������.

class clOFN {

void Zero(void); // ��������� ���������.
void Free(void); // ������������ ������ �� �����.

public:

OPENFILENAME ofn; 

clOFN(void);
~clOFN(void);
BYTE Init(USHRT szFile,USHRT szFileTitle); // ��������� ������.
BYTE IsOK(void); // ��������.
BYTE Open(BYTE flSave,char *Filter,char *ExtIni,char *ExtDef,char *PathToDir,char *FileNameIni,
  HWND hwndOwner,UINT IDS_Header,BYTE flExtDiff,BYTE flCase); // ��������� ����� ����� ��� �������� ��� ����������.
BYTE GetFilePath(char *FileName,USHRT szFileName,char *PathToDir,USHRT szPathToDir,char *Exten,
  USHRT szExten,BYTE cutExt,USHRT *nFiltInd); // ��������� ����� ����� � ���� � �����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ������� ��������� �������.

struct strSndArr {

UINT ln; float *Snd; double dt;

strSndArr(void);
~strSndArr(void);
void Zero(void); // ��������� ����������.
void Free(void); // ������������ ������.
BYTE Create(UINT ln_); // ��������.
BYTE IsOK(void); // ��������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� �������.

struct strPal {

BYTE MasRGB[nColSmoothPal][3];

strPal(void); // �����������.
void Zero(void); // ��������� �������.
BYTE FillColor(DWORD *ColBase); // ���������� ������ ���������� �������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� �����.

class clListString {

void Zero(void); // ��������� ��������� � ������������� ����������.
void Clear(void); // �������� �����.

char **List;

public:

USHRT nList;

clListString(void);
~clListString(void);
void Free(void); // ������������ ������.
BYTE Alloc(USHRT nList_); // ��������� ������.
BYTE IsOK(void); // ��������.
BYTE Set(USHRT num,char *txt); // ��������� ������ � ������.
char *Get(USHRT num); // ��������� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ������� "*.htm" ����� 'Explorer'.

class clHelpEx {

char *Name,*CurrDir; clListString *LS;

void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // �������� �������.
void ZeroLS(void); // ��������� ��������� �� ����� ������ �����.
void FreeLS(void); // �������� ������ ������ �����.
BYTE CreateLS(void); // �������� ������ �����.
BYTE ReadLS(void); // ������ ������ �����.
BYTE Show(char *Topic); // ����� �������.

public:

clHelpEx(void);
~clHelpEx(void);
BYTE Set(char *Path,char *Dir,char *DirFile,char *Name_); // ��������� ���������� � �������� ������� �����.
void ShowContent(void); // ����� ���������� ����� �������.
BYTE ShowTopic(DWORD Topic); // ����� ������� �� �������� ����.
};
