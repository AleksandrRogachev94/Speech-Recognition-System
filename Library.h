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
