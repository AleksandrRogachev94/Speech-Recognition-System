/*...........................................................................................................

strParSpProc,
strNeuron,strLay,strInpLay,strParFreqCorrSpectr,strPropNNW,strNNW,
strParAnSnd,strAnSnd,strAnSndArr,strAnalyseSound,
strRecSymb,strAnalyseData,
strWordDict,strDictionary,strRecognWord,strRecognAllWords

...........................................................................................................*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������� ������� ������ ������.

#define methDecSnd_Inst  0 // ���������� ������, ���������� �� ���������� ��������.
#define methDecSnd_Store 1 // ����� � ����������� ����������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ���������� ������� ������ ������.

#define errSoundResNNW 0.4F // ���������� ������ ��� ������������� ����� � ������� ������ �������� �������.
#define LevSoundDecStore 0.5F // ������� �������� ������� ��� ������������� ����� � ������ � ������ ������������ ����������.

// ����� ���������� (c) ��� ������.
#define tStVowel 0.5F // ����� ���������� (c) ��� ������� ������.
#define tStSonor 0.3F // ����� ���������� (c) ��� �������� ������.
#define tStPulse 0.1F // ����� ���������� (c) ��� ���������� ��������� ������.
#define tStTurb  0.3F // ����� ���������� (c) ��� ������������ ��������� ������.
#define tStHiss  0.3F // ����� ���������� (c) ��� ������� ��������� ������.
#define tStHTone 0.3F // ����� ���������� (c) ��� ������-������� ��������� ������.
#define tStSilence 1.0F // ����� ���������� (c) ��� ���������� ��������.

// ���� ������������ � �������� ���������� ������������� ��� �������� ������� � ��������� ������������� �������.
#define weiStoreVowel 1.0F // ��� ������� ������.
#define weiInstVowel  1.0F // ��� ������� ������.

#define weiStoreSonor 1.0F // ��� �������� ������.
#define weiInstSonor  1.0F // ��� �������� ������.

#define weiStorePulse 1.0F // ��� ���������� ��������� ������.
#define weiInstPulse  1.0F // ��� ���������� ��������� ������.

#define weiStoreTurb 1.0F // ��� ������������ ��������� ������.
#define weiInstTurb  1.0F // ��� ������������ ��������� ������.

#define weiStoreHiss 1.0F // ��� ������� ��������� ������.
#define weiInstHiss  1.0F // ��� ������� ��������� ������.

#define weiStoreTone 1.0F // ��� ������-������� ��������� ������.
#define weiInstTone  1.0F // ��� ������-������� ��������� ������.

// ����� ���������� ��� ������������� ������� � ����� ��� �������.
#define nCntSymbVowel   8 // ����� ���������� ����� ��� ������� ������.
#define nCntSymbSonor   5 // ����� ���������� ����� ��� �������� ������.
#define nCntSymbPulse   2 // ����� ���������� ����� ��� ���������� ��������� ������.
#define nCntSymbTurb    5 // ����� ���������� ����� ��� ������������ ��������� ������.
#define nCntSymbHiss    5 // ����� ���������� ����� ��� ������� ��������� ������.
#define nCntSymbTone    5 // ����� ���������� ����� ��� ������-������� ��������� ������.
#define nCntSymbSilence 10 // ����� ���������� ����� ��� ��������.

#define nCntNoSymbVowel 3 // ����� ���������� ���������� ������ ��� ������������� ����� ��� ������� ������.
#define nCntNoSymbSonor 3 // ����� ���������� ���������� ������ ��� ������������� ����� ��� �������� ������.
#define nCntNoSymbPulse 1 // ����� ���������� ���������� ������ ��� ������������� ����� ��� ���������� ��������� ������.
#define nCntNoSymbTurb  3 // ����� ���������� ���������� ������ ��� ������������� ����� ��� ������������ ��������� ������.
#define nCntNoSymbHiss  2 // ����� ���������� ���������� ������ ��� ������������� ����� ��� ������� ��������� ������.
#define nCntNoSymbTone  2 // ����� ���������� ���������� ������ ��� ������������� ����� ��� ������-������� ��������� ������.
#define nCntNoSymbSilence 3 // ����� ���������� ���������� ������ ��� ������������� ����� ��� ������-������� ��������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ��������� ������� � ������ ������.

#define TimePauseComm 2.0F // ����� (�) ����� ��������� ��� ������ ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������.

#define Time_Width_Spectr_Stand 0.085F // ������������ ���������� ���� (�) (c���������� ��������).
#define Time_Step_Spectr_Stand 0.005F // ��� ����������� ���������� ���� (�) (c���������� ��������).
#define nWinWid_Min 64 // ����������� ������ ���������� ���� � ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ��� ������������� �������������� � ���������� ����.

#define nTypMovWinSpectr 14 // ����� ����� ����.

#define methSpFour_Cos        0 // ���������������� ����������� (���� �����) � ���������� 0.5.
#define methSpFour_Hann       1 // ���������������� ����������� � ���������� 0. (������� �����).
#define methSpFour_Hamming    2 // ���� ��������.
#define methSpFour_Blackman   3 // ���� ��������.
#define methSpFour_BlHarr     4 // ���� ��������-�������.
#define methSpFour_KaisBess   5 // ���� �������-�������.
#define methSpFour_Natall     6 // ���� �������.
#define methSpFour_BlNatall   7 // ���� ��������-�������.
#define methSpFour_FlatTop    8 // ���� � ������� ��������.
#define methSpFour_Barlett    9 // ���� ��������.
#define methSpFour_BarHann   10 // ���� ��������-�����.
#define methSpFour_Lanczos   11 // ���� ��������.
#define methSpFour_Gauss     12 // ������� ������.
#define methSpFour_NoWin     13 // ��� �����������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������������ ������� �������.

#define coeWinCos 0.5F // ����������� ���� � ���������������� ������������.
#define coeWinKaisBess 4.54F // ����������� ���� �������-�������.
#define coeWinGauss 0.3F // ����������� ���� ������.
#define coeWinDolphCheb 30.0F // ����������� ���� ������-�������� (���������� ��������� ��).

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ������������ ���������.

struct strParSpProc {

float Time_Width; // ������ ���������� ����.
float Time_Step; // ��� ����������� ���������� ����.
BYTE methSpFour; // ����� ����������� ��������� �����.

strParSpProc(void); // �����������.
BYTE IsOK(void); // ��������.
};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� � ������ ��� ��������� ������� ��������� �����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� ����� �������.

typedef double (*pFunAct)(double S); // ������� ��������� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ������� ���������.

#define nTypFunAct 5 // ����� ����� �������.

#define TypFunAct_Sigm   0 // ���������� ������.
#define TypFunAct_BiSigm 1 // ���������� c��������� ������.
#define TypFunAct_HypTan 2 // ��������������� �������.
#define TypFunAct_Log    3 // ���������������.
#define TypFunAct_Lin    4 // ��������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� �������.

struct strNeuron {

BYTE flTUse,flSmart; USHRT nWeights; double Val,T,*Weights,*Shifts;

strNeuron(void); // �����������.
~strNeuron(void); // ����������.
void Zero(void); // ��������� ��������������� � ����������.
void ZeroPar(void); // ��������� ���������������.
void Free(void); // �������� ������� ����� �� ������.
BYTE Alloc(USHRT nWeights_); // ��������� ������ ��� ������� �����.
BYTE IsOK(void); // �������� ������� �����.
BYTE Read(FILE *file); // ������ �� �����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���� ��������.

struct strLay {

BYTE TypFunAct,flTUse,flSmart; // ����� ��������, ������� ��������� � ���� ������������� ������� � ��������.
USHRT n; // ����� ��������.
struct strNeuron *Neurons; // ������ �������� ��������.

strLay(void); // �����������.
~strLay(void); // ����������.
void Zero(void); // ��������� ��������������� � ����������.
void InitPar(void); // ������������� ��� ��������� ���������������.
void Free(void); // �������� �������� �� ������.
BYTE Alloc(USHRT n_); // ��������� ������ ��� ������� �������� ��������.
BYTE IsOK(void); // ��������.
strNeuron *Get(USHRT num); // ��������� ��������� �� ��������� �������.
BYTE Read(FILE *file); // ������ �� �����.
BYTE AllocWeights(USHRT nNeurPrev); // ��������� ������ ��� �������� ������� ������������� ��� ������� �������. 
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� �������� ���� ��������.

struct strInpLay {

USHRT n; double *Values;

strInpLay(void); // �����������.
~strInpLay(void); // ����������.
void Zero(void); // ��������� ��������������� � ����������.
void Free(void); // �������� �������� �� ������.
BYTE Alloc(USHRT n_); // ��������� ������ ��� ������� �������� ��������.
BYTE IsOK(void); // ��������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������.

#define CorrDBFrCorr_Stand 20.0F // �������� ��������� ��������� (��).
#define FreqIniFrCorr_Stand 1500.0F // ������� (��), ��� ���������� ��������� ��������� - ����������� ��������.
#define FreqFinFrCorr_Stand 2500.0F // ������� (��), ��� ��������� ��������� ��������� - ����������� ��������.
#define AmpThr_Noice 2.0F // ��������� ��� ��������� ���������� ����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��������� ��������� �������.

struct strParFreqCorrSpectr {

float FrIni,FrFin; // ������ � ����� ��������� ��������� (��).
float CorrDB; // �������� ��������� ��������� � ��.

strParFreqCorrSpectr(void); // �����������.
void Init(void); // ������������� ����������.
BYTE IsOK(void); // ��������.
USHRT Check(void); // �������� � ���������.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Write(FILE *file); // ������ � ����.
void SetDlg(HWND hDlg); // ��������� � ���������� ����.
BYTE GetDlg(HWND hDlg); // ��������� �� ����������� ����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ������� � ���������� ��������� ����.

struct strPropNNW {

BYTE flType; // ��� ��������� ����: (�������, ���������, ����� �� - ������).
BYTE flTypInpData; // ��� ������ ������ �� ���� ��������� ����.
BYTE flFrCorr,typFrCorr; // ���� � ��� ��������� ���������.
BYTE flFrCompr,typFrCompr; // ���� � ��� ���������� ������.
BYTE nPCons; // ����� �������� ��� ������������ ����� ��������� ������.
float dFr; // ������� ������������� ���������� (��).
float dFrTri; // ������� ������������� ���������� �� ����������� �������� (��).
float FreqMin; // ����������� ������� ������������ ������������� ��������� (��).
float FreqMax; // ������������ ������� ������������ ������������� ��������� (��).
struct strParFreqCorrSpectr FreqCorrSpectr; // ��������� ��������� ��������� �������.

strPropNNW(void); // �����������.
void Init(void); // ������������� ����������.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Write(FILE *file); // ������ � ����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ��������� �����.

#define typNNW_Spectr 2 // ���������� ��������� ����� ����� ��� ����� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ����������� ������.

#define typDataNNW_SpectrRow 3 // ��������������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���� ��������� ����.

struct strNNW {

BYTE typ; // ��� ��������� ���� - ��� ������� ��� ���������.
BYTE nLay; // ����� ���� ��������.
struct strInpLay InpLay; // ������� ���� ��������� ����.
struct strLay *Layers; // ������ �������� ���� ��������.
struct strPropNNW Par; // ��������� ������� � ���������� ��������� ����.
BYTE flOK; // ���� ������� ���������� ������� ������������� � �������.

strNNW(void); // �����������.
~strNNW(void); // ����������.
void Zero(void); // ��������� ��������������� � ����������.
void Free(void); // �������� �������� �� ������.
BYTE Alloc(BYTE nLay_); // ��������� ������ ��� ������� �������� ���� ��������.
BYTE IsOK(void); // ��������.
BYTE IsOK_Lay(void); // �������� ������� ����.
strLay *Get(BYTE num); // ��������� ��������� �� ��������� ����.
strLay *GetOutLay(void); // ��������� ��������� �� ��������� ��������� ����.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Read_(char *fName); // ������ �� �����.
BYTE Read(char *Path,char *fName,char *ext); // ������ �� �����.
BYTE Compute(strInpLay *InpLay_); // ��������� �������� ���� � ������.
BYTE Compute_(BYTE layIn); // ������ ������� �� ���� 'layIn'.
BYTE FreqCorrect(void); // ��������� ��������� �������� �������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� ����� ������� ��� ��������� �������������.

typedef BYTE (*pFunDecSnd)(PNT_DATA Pnt,strLay *pLay,BYTE *numSnd); // ������� �������� ������� ��� ������������� �����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ��� ������� ������ ������ ��� �����.

struct strParAnSnd {

char Symb; // ������.
BYTE type; // ��� �������.
float tStore; // ����� ���������� �������.
float weiStore; // ����������� ����� ������������ �������.
float weiInst; // ����������� ����� �������� �������.
BYTE nCntSymb; // ����� ���������� �����.
BYTE nCntNoSymb; // ����� ���������� ���������� ������ ��� ������������� �����.

BYTE IsOK(void); // ��������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ������� ������ ������ ��� �����.

struct strAnSnd {

USHRT nBuf,cnt; float *Buf,weiStore,weiInst,coeWei; double sum;

strAnSnd(void); // �����������.
~strAnSnd(void); // ����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
BYTE Init(strParAnSnd *PAS,float tStep); // �������������.
BYTE IsOK(void); // ��������.
BYTE Start(void); // ������ ������.
BYTE Step(float Val,float *pRes); // ��� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ������� ������ ������ ��� ���������� ������.

struct strAnSndArr {

BYTE nArr; struct strAnSnd *pArr;

strAnSndArr(void); // �����������.
~strAnSndArr(void); // ����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
void Clear(void); // ������������ ������ � ����������.
BYTE Create(BYTE nArr_); // �������� �������.
BYTE IsOK(void); // �������� ������� ��������.
BYTE Init(strParAnSnd *PAS,BYTE nPAS,float tStep,BYTE flNew); // �������������.
BYTE Start(void); // ������ ������.
BYTE Step(float *pVal,float *pRes,BYTE nVal); // ��� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ������� ������ ������.

struct strAnalyseSound {

float Res[nVoices]; // ������� ��� �������� ����������� �������������.
struct strAnSndArr AnSnd; // ��������� ��� ������� ������ ������.

BYTE Init(float tStep,BYTE flNew); // �������������.
BYTE Start(void); // ������ ������.
BYTE Step(float *pVal,BYTE nVal,BYTE *numSnd); // ��� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ������������� ������ �������.

struct strRecSymb {

USHRT cntSymp,cntNotSymb,N_CntSymb,N_CntNoSymb;

strRecSymb(void); // �����������.
void Zero(void); // ������������� ����������.
void Init(USHRT NCntSymb,USHRT NCntNoSymb); // �������������.
void IncCntSymb(BYTE flag); // ���������� �������� ������� ��� ��������� �������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ������� ������ ������.

struct strAnalyseData {

struct strRecSymb SymbArr[nVoices],NoSymb;

strAnalyseData(void); // �����������.
void Zero(void); // ��������� ����������.
void Init(void); // �������������.
void Reset(void); // ����� ���������.
BYTE GetSymb(BYTE numSnd,BYTE flClear); // ��������� ������� �� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ����� � �������.

struct strWordDict {

BYTE nTranscr; char *Word,**Transcr;

strWordDict(void); // �����������.
~strWordDict(void); // ����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
void FreeTranscr(void); // ������������ ������ �� ������������.
void ClearTranscr(void); // �������� ����� �� ������.
BYTE AllocTranscr(BYTE nTranscr_); // ��������� ������ ��� ������������.
BYTE IsOK_Transcr(void); // �������� ������� ������������.
char *Get(UINT num); // ��������� ������ ������������.
BYTE Read(FILE *file); // ������ �� �����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� �������.

struct strDictionary {

UINT nWords; struct strWordDict *Words;

strDictionary(void); // �����������.
~strDictionary(void); // ����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
BYTE Alloc(UINT nWords_); // ��������� ������.
BYTE IsOK(void); // �������� �������.
strWordDict *Get(UINT num); // ��������� ��������� �����.
char *GetWord(UINT num); // ��������� ������ ������������� �����.
BYTE Read(char *Path,char *fName,char *ext); // ������ �� �����.
BYTE Read_(char *fName); // ������ �� �����.
BYTE Read(FILE *file); // ������ �� �����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������.

#define PercWrongRecWord 0.2F // ����������� ���������� ���� ����������� ������������ ������ � �����.
#define cntNSWord_Max 1 // ���������� ����� ������������ �������� � �����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ������������� ������������ �����.

struct strRecognTranscr {

BYTE ln,cnt,cntNS,cntErr,cntErrM; char *pTr;

strRecognTranscr(void); // �����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
BYTE Init(char *pTr_); // �������������.
void Start(void); // ������ ������.
BYTE Step(char Symb); // ��� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ������������� �����.

struct strRecognWord {

BYTE nRecTr; struct strRecognTranscr *RecTr; struct strWordDict *pWD;

strRecognWord(void); // �����������.
~strRecognWord(void); // ����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void ZeroRT(void); // ��������� ���������� � ������������� ����������.
void FreeRT(void); // ������������ ������.
BYTE AllocRT(UINT nWords_); // ��������� ������.
BYTE IsOK_RT(void); // �������� �������.
BYTE Init(strWordDict *pWD_); // �������������.
BYTE Start(void); // ������ ������.
BYTE Step(char Symb); // ��� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ������������� ����.

struct strRecognAllWords {

UINT nWords; struct strRecognWord *RecWords;

strRecognAllWords(void); // �����������.
~strRecognAllWords(void); // ����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
BYTE Alloc(UINT nWords_); // ��������� ������.
BYTE IsOK(void); // �������� �������.
BYTE Init(strDictionary *pDict); // �������������.
BYTE Start(void); // ������ ������.
BYTE Step(BYTE numSnd,UINT *numRec); // ��� ������.
};
