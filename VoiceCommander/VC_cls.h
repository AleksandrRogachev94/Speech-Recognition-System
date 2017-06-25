/*...........................................................................................................

clFileT,clString,clListString,clHelpEx

...........................................................................................................*/

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
