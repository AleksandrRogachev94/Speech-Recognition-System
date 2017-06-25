/*...........................................................................................................

clWavData,strSndBuf,clSndCapArr,clSndCapData,clDLLObjSoundCap,clLoadDLLSndCap,clDlgSndCap

...........................................................................................................*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ��������� �������, ������������ �� ����� *.wav.

class clWavData {

void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
void ZeroSnd(void); // ��������� ���������� � ������������� ���������� ��� �������� �����.
BYTE IsOK_Header(void); // �������� ��������� ���������.
BYTE Read_(HANDLE File); // ������ �� �����.
BYTE ReadData(HANDLE File); // ������ ������ �� �����.
BYTE Write_(HANDLE File); // ������ � ����.
BYTE WriteData(HANDLE File); // ������ ������ � ����.

public:

BYTE ch,nBS; UINT ln; BYTE *bSnd[2]; SHRT *sSnd[2]; PCMWAVEFORMAT WF; WAVEFORMAT *pwf;

clWavData(void);
~clWavData(void);
void FreeSnd(void); // ������������ ������ ��� �������� �����.
BYTE AllocSnd(UINT ln_,BYTE chan_,BYTE nBS_); // ��������� ������ ��� �������� �����.
BYTE IsOKSnd(void); // �������� �������� �����.
void Init_Header(BYTE ch_,BYTE nBS_,DWORD sps); // ������������� ��������� ���������.
BYTE Read(char *fName); // ������ �� �����.
BYTE Write(char *fName); // ������ � ����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ������� ��������� �������.

struct strSndBuf {

UINT ln; SHRT *Snd;

strSndBuf(void);
~strSndBuf(void);
void Zero(void); // ��������� ����������.
void Free(void); // ������������ ������.
BYTE Create(UINT ln_); // ��������.
BYTE IsOK(void); // ��������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��� - ��������� �� ����� ������� ��������� �������.

typedef strSndBuf *typPntSndBuf;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ������ 'clSndCapArr'.

#define nSA_Step 50 // ������ ������������� ����������� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� �������� �����, ���������� ��� ������.

class clSndCapArr {

UINT nM; typPntSndBuf *Arr;

void Zero(void); // ��������� ���������� � ������������� ����������.
void Clear(void); // �������� �������� 'strSndBuf'.
BYTE ReAlloc(UINT nM_); // ����������������� ������.

public:

UINT nI;

clSndCapArr(void); // �����������.
~clSndCapArr(void); // ����������.
void Free(void); // ������������ ������.
BYTE Alloc(UINT nM_); // ��������� ������.
BYTE CheckSize(UINT nM_); // �������� ������� ������� � ��� ������������� ��������� ������.
BYTE IsOK(void); // ��������.
BYTE Create(UINT num); // �������� ������� ������� ��������� �������.
strSndBuf *Get(UINT num); // ��������� ������� ��������� �������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� ������ ������ ������� �����.

#define szSndCapDataCycle 128 // ����� ��������� ������������ ������ ��� ������� ����� ��� �������������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� �����, ����������� ��� ������ � ���� ��������� ��������.

class clSndCapData {

void Zero(void); // ��������� ����������.
void FreeSCA(void); // ������������ ������.
BYTE CreateSCA(void); // �������� ������ ������ �������� �����.

public:

UINT nSPS,nCnt; clSndCapArr *SCA;

clSndCapData(void);
~clSndCapData(void);
void Free(void); // �������� �������� �����.
BYTE Add(UINT szSnd,SHRT *pSnd); // ���������� ������� ��������� �������.
BYTE IsOK(void); // �������� ������ �������� �����.
strSndBuf *Get(UINT num); // ��������� ������� ��������� �������.
BYTE CreateCycle(UINT nM_); // �������� ������������ ������.
BYTE AddCycle(UINT szSnd,SHRT *pSnd); // ���������� ������� ��������� ������� � ����.
BYTE GetCycle(UINT szSnd,SHRT *pSnd,UINT Shift); // ��������� ������� ��������� ������� �� �����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� ������ ������ ������� �����.

#define szNotifySndCap 2048

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� � ��������� �������� �����.

#define nSndForm 5 // ����� �������� �� �������� � �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ������� ��� ������ 'clDLLObjSoundCap'.

typedef void (*funSndCap_CallBack)(PNT_DATA Pnt,DWORD szBuf,void *Buf); // ��� ������� ��������� ������ ��� �������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ������� ��� ������� ����� (���������).

class clDLLObjSoundCap {

void Zero_(void); // ������������� ����������.
void ZeroPntFunc(void); // ��������� ��������� �� ����� � ��������� �� ������� ��������� ������.

protected:

BYTE *pFlStop; // ��������� �� ���� ��������� ������� �����.
PNT_DATA Pnt; // ��������� �� ���������� �����.
funSndCap_CallBack funCB; // ������� ��������� ������ ��� �������� ������.

public:

BYTE numDevice; // ����� ���������� ��� ������ �����.
BYTE numFormat; // ����� ������� �����.

clDLLObjSoundCap(void);
~clDLLObjSoundCap(void);
void SetPntFunc(PNT_DATA Pnt_,funSndCap_CallBack funCB_,BYTE *pFlStop_); // ��������� ����������.
virtual BYTE _stdcall FillInfDevices(void); // �������� ���������� �� ��������� ����������� ����� �����.
virtual BYTE _stdcall InitDirectSound(void); // ������������� 'Direct Sound'.
virtual void _stdcall UnInitDirectSound(void); // ��������������� 'Direct Sound'.
virtual BYTE _stdcall Open(void); // �������� ����������.
virtual void _stdcall Close(void); // �������� ����������.
virtual BYTE _stdcall StartCapture(void); // ������ ������� �����.
virtual void _stdcall StopCapture(void); // ��������� ������� �����.
virtual BYTE _stdcall CheckMessage(void); // ����� ��������� ��� ������� �����.
virtual void _stdcall GetParSnd(UINT *nSPS,BYTE *nChan,BYTE *nbPS); // ��������� ���������� ������� �����.
virtual BYTE _stdcall FillCB_Devices(HWND hDlg,UINT id); // ���������� ������ ���������� ������������ ������ �����.
virtual BYTE _stdcall FillCB_Formats(HWND hDlg,UINT id); // ���������� ������ ���������� ��� ���������� ���������� ��������� �����.
virtual void _stdcall SetNotifySize(UINT szNotify_); // ��������� ������� ������ ���������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� �������, ������������ � ������ ��� ������ � ����������� ������� �����.

typedef BYTE (_stdcall *pDll_SndCap_CreateObj)(clDLLObjSoundCap **Obj); // �������� �������.
typedef void (_stdcall *pDll_SndCap_DeleteObj)(clDLLObjSoundCap **Obj); // �������� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ��� ������ � ����������� ������� �����.

class clLoadDLLSndCap {

HMODULE hLib; // ����������.

pDll_SndCap_CreateObj funCreateObj; // �������� �������.
pDll_SndCap_DeleteObj funDeleteObj; // �������� �������.

void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
void FreeLibr(void); // ������������ ������ ��� ����������.
BYTE LoadLibr(char *nameDir,char *nameDLL); // �������� ����������.
void ZeroFunLib(void); // ��������� ���������� �� ������� ����������.
BYTE LoadFunLib(void); // �������� ������� ����������.
void ZeroDLLObj(void); // ��������� ���������� �� ������ ����������.
BYTE FreeDLLObj(void); // �������� ������� ����������.
BYTE LoadDLLObj(void); // �������� ������� ����������.

public:

clDLLObjSoundCap *Obj; // ����� ������� ��� ������� �����.

clLoadDLLSndCap(void);
~clLoadDLLSndCap(void);
BYTE Load(char *nameDir,char *nameDLL); // �������� ���������� � �������.
BYTE StartCapture(void); // ������ ������� �����.
void StopCapture(void); // ��������� ������� �����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ����������� ���� ��������� ������� �����.

class clDlgSndCap {

BYTE numDev,numForm,flCh; HWND hDlg; clDLLObjSoundCap *ObjSC;

void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
BYTE SelDevice(BYTE num); // ����� ���������� ��� ������� �����.
BYTE SelFormat(BYTE num); // ����� ������� �����.
void ChBntSave(void); // ��������� ��������� ������ ���������� ����������� ������ ���������� � ������� �����.
BYTE Command(WPARAM wParam); // ������� �� ���� � ������� ����������.

public:

clDlgSndCap(void);
~clDlgSndCap(void);
BYTE Dialog(HWND hWndOwner,clDLLObjSoundCap *ObjSC_,BYTE *flRet); // �������� ����������� ����.
BYTE Create(HWND hDlg_); // �������� ���� ��������� �������.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ������� ��������� ����.
};
