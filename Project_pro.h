/*...........................................................................................................

clSpDiag,
strParSpProc,
strNeurVect,strEtalVal,strNeuron,strLay,strInpLay,clInpLayArr,strParFreqCorrPeaks,strParFreqCorrSpectr,
strPropNNW,strNNW,
strInfTrSerRand,strParTrainNNWSearch,strArrTrSearch,strParLay,strParNNW,
clDlgParNNW,
strSpectrLine,strSpLines,clSpLinesArr,
strParGetPeaks,strParInpSpectr,strParTrainNNW,
strParIncHighSynth

...........................................................................................................*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� �������.

typedef void (*pFunShowProgr)(PNT_DATA Pnt,UINT i,UINT n); // ������ ���������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ������������ ���������.

class clSpDiag: public clArr2Float {

void Zero_St(void); // ��������� �����.

public:

double stArr,stLn;

clSpDiag(void);
void Free_St(void); // ������������ ������ � ���������� �����.
BYTE IsOK_St(void); // �������� ������� �������� �����.
};

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
// ��������� ���������.

#define Time_Width_Spectr_Stand 0.085F // ������������ ���������� ���� (�) (c���������� ��������).
#define Time_Width_Spectr_Min 1.e-2F // ������������ ���������� ���� (�) (����������� ��������).
#define Time_Width_Spectr_Max 2.0F // ������������ ���������� ���� (�) (������������ ��������).
#define Time_Step_Spectr_Stand 0.02F // ��� ����������� ���������� ���� (�) (c���������� ��������).
#define Time_Step_Spectr_Min 1.e-2F // ��� ����������� ���������� ���� (�) (����������� ��������).
#define Time_Step_Spectr_Max 1.0F // ��� ����������� ���������� ���� (�) (������������ ��������).
#define nWinWid_Min 64 // ����������� ������ ���������� ���� � ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ������������ ���������.

struct strParSpProc {

float Time_Width; // ������ ���������� ����.
float Time_Step; // ��� ����������� ���������� ����.
BYTE methSpFour; // ����� ����������� ��������� �����.

strParSpProc(void); // �����������.
BYTE IsOK(void); // ��������.
BYTE Check(void); // �������� � �����������.
BYTE Read_(FILE *file); // ������ �� �����.
BYTE Write_(FILE *file); // ������ � ����.
BYTE Read(char *Path,char *fName); // ������ �� �����.
BYTE Write(char *Path,char *fName); // ������ � ����.
BYTE SetDlg(HWND hDlg); // ��������� � ���������� ����.
BYTE GetDlg(HWND hDlg); // ��������� �� ����������� ����.
void OnCreateDlg(HWND hDlg); // �������� ��� �������� ����������� ����.
};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ��������� � ������ ��� ��������� ������� ��������� �����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� ����� �������.

typedef double (*pFunAct)(double S); // ������� ��������� �������.
typedef double (*pFunDerAct)(double y); // ����������� ������� ��������� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ������� ���������.

#define nTypFunAct 5 // ����� ����� �������.

#define TypFunAct_Sigm   0 // ���������� �������.
#define TypFunAct_BiSigm 1 // ���������� c��������� �������.
#define TypFunAct_HypTan 2 // ��������������� �������.
#define TypFunAct_Log    3 // ���������������.
#define TypFunAct_Lin    4 // ��������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� �������� � ���������� ��� ���������� ��������� ����.

struct strNeurVect {

BYTE flTUse,flSmart; USHRT nWeights; double T,*Weights,*Shifts;

strNeurVect(void); // �����������.
~strNeurVect(void); // ����������.
void Zero(void); // ��������� ��������������� � ����������.
void ZeroPar(void); // ��������� ��������������� ��� ��������.
void Free(void); // �������� ������� �� ������.
BYTE Alloc(USHRT nWeights_); // ��������� ������.
BYTE IsOK(void); // �������� �������.
BYTE SetZero(void); // ��������� ����� � ������ ��������.
BYTE GetSetWeightsShifts(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet); // ��������� ��� ��������� ������� ����� � ��������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��������� �������� ���� �������.

struct strEtalVal {

UINT nVal; double *pVal;

strEtalVal(void); // �����������.
~strEtalVal(void); // ����������.
void Zero(void); // ��������� ��������������� � ����������.
void Free(void); // �������� ������� �� ������.
BYTE Alloc(UINT nVal_); // ��������� ������.
BYTE IsOK(void); // �������� �������.
BYTE GetMinMax(double *pMin,double *pMax); // ���������� ������������ � ������������� ��������.
BYTE Correct(double coe,double shift); // �������������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� �������.

struct strNeuron {

BYTE flTUse,flSmart; USHRT nWeights; double Val,T,*Weights,*Shifts,Err;

struct strNeurVect Vect; // ��������� �������� � ���������� ��� ���������� ��������� ����.
struct strEtalVal Etal; // ��������� ��������� �������� ���� �������.

strNeuron(void); // �����������.
~strNeuron(void); // ����������.
void Zero(void); // ��������� ��������������� � ����������.
void ZeroPar(void); // ��������� ���������������.
void Free(void); // �������� ������� ����� �� ������.
BYTE Alloc(USHRT nWeights_); // ��������� ������ ��� ������� �����.
BYTE IsOK(void); // �������� ������� �����.
BYTE IsOK_Vect(void); // �������� ������� ��������.
BYTE GetSetArrSearch(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet,BYTE flArr); // ��������� ��� ��������� ������� ����� � �������� ��� �������� ����� � ��������.
BYTE GetSetWeightsShifts(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet); // ��������� ��� ��������� ������� ����� � ��������.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Write(FILE *file); // ������ � ����.
void ZeroInit(void); // ��������� ������� ������������� � ���������� ������.
BYTE RandInit(float CoeWei,float CoeTe); // ���������� ���������� ����������� ������� ������������� � ��������� �������.
BYTE RandChange(float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA); // ��������� ��������� ������� ������������� � ��������� �������.
BYTE AddWeightsShiftsGroup(double Alpha); // ���������� ������� ���������� � ������������� � ��������� ��� ��������� ��������.
BYTE SetValEqualEtal(UINT numSample); // ��������� ��������, ������� ���������� �������� � ��������� ��������.
BYTE SetEtalEqualVal(UINT numSample); // ��������� ���������� ��������, ������� �������� �������� ������� � ��������� ��������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���� ��������.

struct strLay {

BYTE TypFunAct,flTUse,flSmart; // ����� ��������, ������� ��������� � ���� ������������� ������� � ��������.
USHRT n; // ����� ��������.
double Alpha; // ���������� ���.
double Numer,Denom; // ���������� ��� ���������� ����������� ����.
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
BYTE Write(FILE *file); // ������ � ����.
BYTE AllocWeights(USHRT nNeurPrev); // ��������� ������ ��� �������� ������� ������������� ��� ������� �������. 
void FreeVect(void); // �������� �������� �������� �� ������.
BYTE AllocVect(void); // ��������� ������ ��� �������� ��������.
BYTE IsOK_Vect(void); // �������� �������� ��������.
BYTE SetZeroVect(void); // ��������� ����� � ������� ��������.
BYTE GetSetArrSearch(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet,BYTE flArr); // ��������� ��� ��������� ������� ����� � �������� ��� �������� ����� � ��������.
BYTE SetFlagTShUse(void); // ��������� ������ ������������� ������� � �������� �� ��� �������.
void ZeroInit(void); // ��������� ������� ������������� � ��������� ������� ���� ��������.
BYTE RandInit(float CoeWei,float CoeTe); // ���������� ���������� ����������� ������� ������������� � ��������� �������.
BYTE RandChange(float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA); // ��������� ��������� ������� ������������� � ��������� �������.
BYTE AddWeightsShiftsGroup(void); // ���������� ������� ���������� � ������������� � ��������� ��� ��������� ��������.
BYTE FreeEtal(void); // �������� �� ������ �������� ��������� �������� ��������.
BYTE AllocEtal(UINT nSamples); // ��������� ������ ��� �������� ��������� �������� ��������.
BYTE SetValEqualEtal(UINT numSample); // ��������� �������� ��������, ������ ��������� ��������� � ��������� ��������.
BYTE SetEtalEqualVal(UINT numSample); // ��������� ��������� �������� ��������, ������ ������� ��������� �������� � ��������� ��������.
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
// ����� ������� �������� �������� ��� ��������� ���� ��������.

struct clInpLayArr {

struct strInpLay *Data; // ������ �������� �������� ��� ��������� ���� ��������.

public:

UINT nData; // ����� ��������� �������.
USHRT n; // ����� �������� � ������ �������.

clInpLayArr(void); // �����������.
~clInpLayArr(void); // ����������.
void Zero(void); // ��������� ��������������� � ����������.
void Free(void); // �������� �� ������.
BYTE Alloc(UINT nData_,USHRT n_); // ��������� ������.
BYTE IsOK(void); // ��������.
strInpLay *Get(UINT num); // ��������� ��������� �� ��������� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������.

#define CorrDBFrCorr_Stand 20.0F // �������� ��������� ��������� (��).

#define numIniFrCorr_Stand 5 // ��������� ����� ������� ��������, ��� ���������� ��������� �������� - ����������� ��������.
#define numIniFrCorr_Max  15 // ��������� ����� ������� ��������, ��� ���������� ��������� �������� - ������������ ��������.
#define numFinFrCorr_Stand 10 // �������� ����� ������� ��������, ����� ���� �������� ��������� - ����������� ��������.

#define FreqIniFrCorr_Stand 1500.0F // ������� (��), ��� ���������� ��������� ��������� - ����������� ��������.
#define FreqFinFrCorr_Stand 2500.0F // ������� (��), ��� ��������� ��������� ��������� - ����������� ��������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��������� ��������� ������������ �����.

struct strParFreqCorrPeaks {

USHRT numIni,numFin; // ������ � ����� ��������� ��������� � ������� ��������.
float CorrDB; // �������� ��������� ��������� � ��.

strParFreqCorrPeaks(void); // �����������.
void Init(void); // ������������� ����������.
BYTE IsOK(void); // ��������.
USHRT Check(void); // �������� � ���������.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Write(FILE *file); // ������ � ����.
void SetDlg(HWND hDlg); // ��������� � ���������� ����.
BYTE GetDlg(HWND hDlg); // ��������� �� ����������� ����.
};

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
// ���������.

#define ColBkgWinNet COL_GRAY // ���� ���� ���� ����������� ��������� ����.
#define ColNeur COL_RED // ���� �������� ��� ������ ���������.
#define ColAxons COL_GREEN // ���� ������� ��� ������ ���������.
#define ColAxonsSmartNeur COL_BLUE // ���� ������� ��� '�����' �������� (�� ����������) ��� ������ ���������.
#define ColCircleNeur COL_WHITE // ���� ���������� ��������.
#define ColTxtNumNeur COL_WHITE // ���� ������� ��������.
#define ColRectNeurThr COL_WHITE // ���� ����� �������������� �������.
#define szImgNeurMax 15 // ������������ ������ ����������� �������.
#define szImgNeurThrMax 6 // ������������ ������ ����������� �������.
#define coeSzNeur 0.7F // ������������� ������ �������.
#define coeSzNeurThr 0.2F // ������������� ������ �������������� �������.
#define ColRectInpLay COL_WHITE // ���� �������������� ����������� �������� ����.
#define ColInpLay COL_BLUE // ���� ����������� �������� ���� ��� ������ ���������.
#define ColTxtNumInpLay COL_WHITE // ���� ������� �������� ����.
#define szImgLetter 10 // ������ ����������� �����.
#define ColRectLetter COL_WHITE // ���� �������������� ����������� ������� �����.
#define ColImgLetterLt COL_WHITE // ���� ������� ����� (�������).
#define ColImgLetterDk COL_BLACK // ���� ������� ����� (�����).
#define szImgLettFunAct 10 // ������ ������ �������� ������� ���������.
#define ColBkgTextFunAct COL_WHITE // ���� ���� �������� ������� ���������.
#define ColFrameTextFunAct COL_RED // ���� �����.
#define ColTextFunAct COL_BLUE // ���� �������� ������� ���������.
#define LevNoDrawAxons 0.025F // ������������� ������� ���������, ���� �������� �� �������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ��������� �����.

#define nTypesNNW 3 // ����� ����� ��������� �����.
#define typNNW_Vowel  0 // ������� � �������� �����.
#define typNNW_Cons   1 // ��������� ���������� � ������� �����.
#define typNNW_Spectr 2 // ���������� ��������� ����� ����� ��� ����� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ����������� ������.

#define nDiffDataNNW 4 // ����� ����� ����������� ������ ��� ��������� �����.
#define typDataNNW_Peaks        0 // �� �����.
#define typDataNNW_SpectrTri    1 // �� ������� � ����������� �� ����������� ��������.
#define typDataNNW_SpectrTriEnv 2 // �� ������� � ����������� ��������� �� ����������� ��������.
#define typDataNNW_SpectrRow    3 // ��������������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ������������ ��������� �����.

#define nTypesRecNNW 3 // ����� ����� �������������.
#define typNNR_VC 0 // ��� ���������� ���� ��� ������� � ���������.
#define typNNR_Sp 1 // ���� ������������ ���� ������� ��������������� ��� ����� �������.
#define typNNR_Co 2 // ���� ��������.

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
struct strParFreqCorrPeaks FreqCorrPeaks; // ��������� ��������� ��������� ������������ �����.
struct strParFreqCorrSpectr FreqCorrSpectr; // ��������� ��������� ��������� �������.

strPropNNW(void); // �����������.
void Init(void); // ������������� ����������.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Write(FILE *file); // ������ � ����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ������������ ������� ��� �������.

#define nTypesShowAxons 4 // ����� ����� ������������ ������� ��� �������.

#define flAxons_Axons  0 // ������� ������������ 'Wij'.
#define flAxons_Trans  1 // ������������ ��������: 'Yi*Wij'.
#define flAxons_Shifts 2 // �������� 'Sij' ��� "�����" ��������.
#define flAxons_Excit  3 // ����������� - ������������ �������� ����� ��������: '(Yi-Sij)*Wij'.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���� ��������� ����.

struct strNNW {

BYTE typ; // ��� ��������� ���� - ��� ������� ��� ���������.
BYTE nLay; // ����� ���� ��������.
struct strInpLay InpLay; // ������� ���� ��������� ����.
struct strLay *Layers; // ������ �������� ���� ��������.
struct strPropNNW Par; // ��������� ������� � ���������� ��������� ����.
BYTE flOK; // ���� ������� ���������� ������� ������������� � �������.
BYTE flChange; // ���� ��������� ������� ������������� � ������� ��������� ����.
char *PathDir; // ����������, ��� �������� ����� ���� ������.
char *NameFile; // ��� ����� ���� ������.

strNNW(void); // �����������.
~strNNW(void); // ����������.
void Zero(void); // ��������� ��������������� � ����������.
void FreeInit(void); // ������������ ������ � ������������� ����������.
void Free(void); // �������� �������� �� ������.
BYTE Alloc(BYTE nLay_); // ��������� ������ ��� ������� �������� ���� ��������.
BYTE IsOK(void); // ��������.
BYTE IsOK_Lay(void); // �������� ������� ����.
strLay *Get(BYTE num); // ��������� ��������� �� ��������� ����.
strLay *GetOutLay(void); // ��������� ��������� �� ��������� ��������� ����.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Write(FILE *file); // ������ � ����.
BYTE Read_(char *fName); // ������ �� �����.
BYTE Write_(char *fName); // ������ � ����.
BYTE Read(char *Path,char *fName,char *ext); // ������ �� �����.
BYTE Write(char *Path,char *fName,char *ext,BYTE flSetChange); // ���������� � ����.
BYTE Write(void); // ���������� � �����.
BYTE Compute(strInpLay *InpLay_); // ��������� �������� ���� � ������.
BYTE ComputeFrom(BYTE layIni); // ������ ������� �� ���� 'layIni'.
BYTE FreqCorrect(void); // ��������� ��������� �������� �������.
void ZeroInit(void); // ��������� ������� ������������� � ��������� ������� ���� ��������.
BYTE RandInit(UINT RandSeq,float CoeWei,float CoeTe); // ���������� ���������� ����������� ������� ������������� � ��������� �������.
BYTE RandInit_(float CoeWei,float CoeTe); // ���������� ���������� ����������� ������� ������������� � ��������� �������.
BYTE RandChange(UINT RandSeq,float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA); // ��������� ��������� ������� ������������� � ��������� �������.
BYTE RandChange_(float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA); // ��������� ��������� ������� ������������� � ��������� �������.
BYTE ComputeErrBackProp(strInpLay *True); // ���������� ������ ������� ��������� ��������������� ������.
BYTE TrainStepSequent(strInpLay *True,float AlphaConst,float AlphaMin,float AlphaMax,BYTE flAdaptSt,BYTE flEqualAdaptSt,float coeAlpha); // ��� ����� �������� ������� ��������� ��������������� ������.
BYTE TrainStepSequentRep(strInpLay *True,float AlphaConst,float AlphaMin,float AlphaMax,BYTE flAdaptSt,float coeAlpha); // ��� ����� �������� ������� ���������� ��������� ��������������� ������.
BYTE TrainStepSequentLayWeights(UINT numSample,strInpLay *InpLay_,BYTE numLay,float AlphaConst,
  float AlphaMin,float AlphaMax,BYTE flAdaptSt,float coeAlpha); // ��� ����� ������ ����������������� ���������� �������� - ������������� ����� � ������� ��� ���� 'numLay'.
BYTE TrainStepSequentLayEtal(UINT numSample,BYTE numLay,float AlphaConst,float AlphaMin,float AlphaMax,BYTE flAdaptSt,float coeAlpha); // ��� ����� ������ ����������������� ���������� �������� - ������������� ��������� �������� ��� ���� 'numLay'.
BYTE TrainStepSequentLayCorr(BYTE numLay); // ������������� ��������� �������� � ������� �������������.
BYTE ComputeAdaptStepAll(float AlphaMin,float AlphaMax,float coeAlpha); // ������ ����������� ���� ��� ���� ���� ����.
BYTE ComputeAdaptStepLay(BYTE numLay,float AlphaMin,float AlphaMax,float coeAlpha); // ������ ����������� ���� ��� ���� � ������� 'numLay'.
void FreeVect(void); // �������� �������� �������� �� ������.
BYTE AllocVect(void); // ��������� ������ ��� �������� ��������.
BYTE IsOK_Vect(void); // �������� �������� ��������.
BYTE SetZeroVect(void); // ��������� ����� � ������� ��������.
BYTE TrainGroupErrSumVect(strInpLay *True,double Wei); // ���������� ������ � ������������ �������� ��� �������� ��������� �������.
BYTE TrainGroupAdaptStep(strInpLay *True,double Wei); // ���������� ��������� � ��������������� ���������� ��� ���������� ����������� ���� ��� ������������ ������� ������ ��� ��������� ��������.
BYTE ZeroNumDenomAdaptStepGroup(void); // ��������� ��������������� ���������� ��� ������������ ��� ���������� ����������� ���� ��� ������������ ������� ������ ��� ��������� ��������.
BYTE FindAlphaGroup(void); // ���������� ����������� ���� ��� ��������� ��������.
BYTE CorrectAlpha(float AlphaMin,float AlphaMax); // ������������� ����������� ���� ��� ������� ����.
BYTE MultCoeAlpha(float CoeAlpha); // ��������� ����������� ���� �� ����������� �����������.
BYTE SetAlphaConst(double Alpha); // ��������� ����������� ���� �� ��� ����.
BYTE GetEqualAdaptStep(double *pAlpha); // ���������� ������ ����������� ���� ��� ���� ����.
BYTE AddWeightsShiftsGroup(void); // ���������� ������� ���������� � ������������� � ��������� ��� ��������� ��������.
BYTE GetSetArrSearch(double *Arr,USHRT szArr,BYTE flSet,BYTE flArr); // ��������� ��� ��������� ������� ����� � �������� ��� �������� ����� � ��������.
BYTE PaintNNW(HDC hdc,RECT *rc,float AmpNormNeur,float AmpNormAxons,float AmpNormInp,strPal *PalPos,
  strPal *PalPosNeg,BYTE flWork,BYTE flAxons); // ������������ ������ ��������� ����.
BYTE FreeEtal(void); // �������� �� ������ �������� ��������� �������� ��������.
BYTE AllocEtal(UINT nSamples); // ��������� ������ ��� �������� ��������� �������� ��������.
void ZeroNames(void); // ��������� ���������� �� ������ ���������� � ����� �����.
void FreeNames(void); // �������� �� ������ ����� ���������� � ����� �����.
BYTE SetNames(char *Path,char *fName); // ��������� ����� ���������� � ����� �����.
BYTE IsOK_Name(void); // �������� ������ ����� �����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ���������� ��������� ���� ��������� ������� ������.

struct strParTrainNNWSearch {

BYTE nStRepM; float coeStI,coeSt,coeChSt;

BYTE IsOK(void); // ��������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��������������� �������� ��� ���������� ���� ������� ������.

struct strArrTrSearch {

USHRT nV; double *Coe,*CoeN,*CoeS,*Vect,*VectN;

strArrTrSearch(void); // �����������.
~strArrTrSearch(void); // ����������.
void Zero(void); // ��������� ����������.
void Free(void); // ������������ ������.
BYTE Create(USHRT nV_); // �������� ��������.
BYTE IsOK(void); // ��������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ����.

struct strParLay { 

BYTE TypFunAct,flTUse,flSmart; USHRT nNeurons;

strParLay(void); // �����������.
void Init(void); // �������������.
BYTE IsOK(void); // ��������.
void Print(void); // ������ � ������.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Write(FILE *file); // ������ � ����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ��������� ����.

struct strParNNW {

struct strPropNNW Par; // ��������� ������� � ���������� ��������� ����.
BYTE nLay; // ����� ���� ��������� ����.
struct strParLay *ParLay; // ��������� ���� ��������� ����.
BYTE flChange; // ���� ��������� ���������� ��������� ����.
char *PathDir; // ����������, ��� �������� ����� ���� ������.
char *NameFile; // ��� ����� ���� ������.

strParNNW(void); // �����������.
~strParNNW(void); // ����������.
void Zero(void); // ��������� ��������������� � ����������.
void Free(void); // �������� �������� �� ������.
BYTE Alloc(BYTE nLay_); // ��������� ������ ��� ������� �������� ���������� ���� ��������.
BYTE ReAlloc(BYTE nLay_); // ����������������� ������ ��� ������� �������� ���������� ���� ��������.
BYTE IsOK(void); // ��������.
BYTE IsOK_(void); // �������� ������� ��������� ���������� ���� ��������.
strParLay *Get(BYTE num); // ��������� ��������� �� ��������� ����.
BYTE Init(BYTE typNNW); // ������������� ��������� ���������� ��������� ����.
BYTE InsItem(BYTE num); // ������� ����.
BYTE DelItem(BYTE num); // �������� ����.
BYTE Read_(FILE *file); // ������ �� �����.
BYTE Write_(FILE *file); // ������ � ����.
BYTE Read(char *Path,char *fName,char *ext); // ������ �� �����.
BYTE Write(char *Path,char *fName,char *ext); // ���������� � �����.
BYTE Write(void); // ���������� � �����.
void ZeroNames(void); // ��������� ���������� �� ������ ���������� � ����� �����.
void FreeNames(void); // �������� �� ������ ����� ���������� � ����� �����.
BYTE SetNames(char *Path,char *fName); // ��������� ����� ���������� � ����� �����.
BYTE IsOK_Name(void); // �������� ������ ����� �����.
BYTE EdtParFreqCorrPeaks(HWND hDlg); // ��������� ���������� ��������� ��������� ������������ �����.
BYTE EdtParFreqCorrSpectr(HWND hDlg); // ��������� ���������� ��������� ��������� �������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ���� ��������� ����.

#define numParLay_Neurons 0 // ����� ��������.
#define numParLay_FunAct  1 // ������� ���������.
#define numParLay_TUse    2 // ������������� �������.
#define numParLay_Shifts  3 // ������������� �������� ('�����' �������).

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ����������� ���� ��������� ���������� ��������� ����.

struct clDlgParNNW {

struct strParNNW *pPar; // ��������� �� ��������� ���������� ��������� ����.
struct strParLay *selLay; // ��������� ���������� ���� ��������� ����.
HWND hDlg; // ������������� ����������� ����.
BYTE numSel; // ����� ���������� ����.
BYTE flChLay; // ���� ��������� ���������� ���� ��������� ����.
BYTE flLastLay; // ���� ����, ��� ������ ��������� ���� ��������� ����.
BYTE blkChType; // ���� ���������� ��������� ���� ��������� ����.

void Zero(void); // ��������� ��������������� � ����������.
BYTE IsOK(void); // ��������.
void SetDlgWinEdt(void); // ��������� ���������� � ����� ��������������.
BYTE FillLBLayers(void); // ���������� ������ ���� ��������� ����.
void UnSelLayer(void); // ������ ������ ����.
BYTE OnChangeLayer(void); // ��������� ���������� ����.
void SelectLayer_(BYTE num); // ����� ���� � ������������ ���������� � �����.
BYTE SelectLayer(BYTE num); // ����� ����.
void SetWinParLay_(void); // ��������� ���������� ���� ��������� ���� � �����.
BYTE SetWinParLay(void); // ��������� ���������� ���� ��������� ���� � �����.
void UnSetWinParLay(void); // ������� ���� ���������� ���� ��������� ����.
BYTE AcceptChanges(void); // �������� ��������� ���������� ����.
BYTE SetParLaySel(void); // ��������� ���������� ���������� ����.
BYTE AddInsItem(BYTE flAdd); // ������� ����.
BYTE DelItem(void); // �������� ����.
void SelectTypNNW(int id); // ����� ���� ��������� ����.
BYTE ReadParNNW(void); // ������ ��������� ���������� �� �����.
BYTE WriteParNNW(void); // ������ ��������� ���������� � ����.
void ChBtnAccept(void); // ��������� ��������� ������ �������� ���������.
void ChBtnDelAdd(void); // ���������� � ��������������� ������ �������� � ����������.
BYTE OnChangeFlags(int id); // �������� ��� ��������� ������ ����������.
void EnableRadioTypNet(void); // ��������� ��������� ������ ������� ���� ����.
void EnableBtnTypInpData(void); // ��������� ��������� ������ � ����������� �� ���� ������� ������ ��� ����.
void SelectTypInpData(int id); // ����� ���� ������� ������ ��� ����.
BYTE Command(WPARAM wParam); // ��������� ������ ����������� ����.

public:

clDlgParNNW(void); // �����������.
~clDlgParNNW(void); // ����������.
BYTE OnOpenDlg(HWND hDlg_); // �������� ��� �������� ����������� ����.
BYTE MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ��������� ����������� ����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ������������ �����.

struct strSpectrLine {

float Amp,AmpRel,Freq;

strSpectrLine(void); // �����������.
void Zero(void); // ��������� ���������������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ������� ������������ �����.

struct strSpLines {

BYTE nSpL; struct strSpectrLine *pSpL;

strSpLines(void); // �����������.
~strSpLines(void); // ����������.
void Zero(void); // ��������� ���������� � ����������.
void Free(void); // ������������ ������.
BYTE Create(BYTE nSpL_); // �������� �������.
BYTE IsOK(void); // ��������.
strSpectrLine *Get(BYTE num); // ��������� ��������� �� ��������� ������������ �����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��� - ��������� �� ��������� ������� ������������ �����.

typedef strSpLines *typPntSpLines;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ���������� ������� ������������ �����.

class clSpLinesArr {

UINT nArr; typPntSpLines *pArr;

public:

clSpLinesArr(void); // �����������.
~clSpLinesArr(void); // ����������.
void Zero(void); // ��������� ���������� � ����������.
void Free(void); // ������������ ������.
void Clear(void); // �������� �������� ��������.
BYTE Create(UINT nArr_); // �������� �������.
BYTE IsOK(void); // ��������.
strSpLines *Get(UINT num); // ��������� ��������� �� ��������� ������� ������������ �����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ���������� ������� ������� ������ ����.

#define AmpThr_Stand 2.0F // ��������� ��� ��������� ���������� ����.
#define FreqMin_Stand 80.0F // ����������� ������� ���������������� ������� (��).
#define FreqMax_Stand 8200.0F // ������������ ������� ���������������� ������� (��).
#define FreqDiscrTri_Stand 200.0F // ��� ����� ��� ���������� ������� �� ����������� ��������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ���������� ��������� ������������ ����� � ������� ������� ������.

#define nPeaksMax 50 // ������������ ����� ������������ ����� ��� ��������� ������� ������ � ������ ����� ������ ��������.
#define nPeaksCons 10 // ����� ������������ ����� ��� ��������� ������� ������.
#define ampSmPeaksAbs_Stand 0.1F // ������� ����� ����� �� ����������� ��������, ������� ������������� ��� ���������� ������� ����.
#define ampSmPeaksMS_Stand 0.2F // ������� ����� ����� �� ������������������� ����������, ������� ������������� ��� ���������� ������� ����.
#define ampSmPeaksMS_Min 0.05F // ������� ����� ����� �� ������������������� ����������, ������� ������������� ��� ���������� ������� ���� (����������� ��������).
#define ampPeaksBad_Stand 0.05F // ������� �� ������������������� ���������� ������ (���� ������������) �����, ������� �������������.
#define FreqMinPeaks_Stand 100.0F // ����������� ������� ���������������� ������� (��).
#define FreqMinPeaks_Min 80.0F // ����������� ������� ���������������� ������� (��) (����������� ��������).
#define FreqMinPeaks_Max 200.0F // ����������� ������� ���������������� ������� (��) (������������ ��������).
#define FreqBaseMax_Stand 400.0F // ������������ ������� �������� ��������� (��).
#define ErrFreq_Stand 0.35F // ������������ ������ ��� ���������� ����� �� �������.
#define coeWidPeaks_Stand 0.165F // ���������� ����� (�������������).
#define CoeRecPeaksSpectr_Stand 0.35F // ����������� ������������� ����� ��� ������� ����� �������.
#define CoeRecPeaksVowel_Stand 0.1F // ����������� ������������� ����� ��� ��������� � ������ ��� ������� ������.
#define CoeRecPeaksCons_Stand 0.35F // ����������� ������������� ����� ��� ��������� � ������ ��� ��������� ������.
#define CoeRecPeaks_Min 0.0F // ����������� ������������� ����� (����������� ��������).
#define CoeRecPeaks_Max 10.0F // ����������� ������������� ����� (������������ ��������).
#define LevPowPeak_Stand 0.3F // ����������� ������� ��������, ������� ������ ����������� � �����.
#define ampPeaksCorrFreq_Stand 0.3F // ��������� �����, �� ������� ���������� ��������� �������.
#define coeShPeaks_Stand 0.5F // �����������, ������ ����������� ��������� ����� ������� ����� ��� ����������� �����.
#define FreqDiscrCons_Stand 150.0F // ������� �� ������� ��� ���������� �� ����������� �������� ��� ������� � ������ ��������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ���������� ������������ ����� ������� ������ � ���������������� ������������� ������� � ��������� ������.

struct strParGetPeaks {

float AmpThr; // ��������� ��� ��������� ���������� ����.
BYTE flCorrFreq; // ���� ��������� ������� �� ������������ ���������� ���������.
float ampSmPeaksAbs; // ������� ����� ����� �� ����������� ��������, ������� ������������� ��� ���������� ���������� ���� ��� ���������� ������� ����.
float ampSmPeaksMS; // ������� ����� ����� �� ������������������� ����������, ������� ������������� ��� ���������� ���������� ���� ��� ���������� ������� ����.
float ampPeaksBad; // ������� �� ������������������� ���������� ������ (���� ������������) �����, ������� �������������.
float FreqMin; // ����������� ������� ���������������� ��������� ������� (��).
float FreqMax; // ������������ �������, �� ������� ���������� ������ (��).
float FreqBaseMax; // ������������ ������� �������� ��������� (��).
float ErrFreq; // ������������ ������ ��� ���������� ����� �� �������.
float coeWidPeaks; // ���������� ����� ������������ �������� �������.
float coeRecPeaksSpectr; // ����������� ������������� ����� ��� ������� ����� �������.
float coeRecPeaksVowel; // ����������� ������������� ����� ��� ��������� � ������ ��� ������� ������.
float coeRecPeaksCons; // ����������� ������������� ����� ��� ��������� � ������ ��� ��������� ������.
float LevPowPeak; // ����������� ������� ��������, ������� ������ ����������� � �����.
float ampPeaksCorrFreq; // ��������� �����, �� ������� ���������� ��������� �������.
float coeShPeaks; // �����������, ������ ����������� ��������� ����� ������� ����� ��� ����������� �����.
float FreqDiscrCons; // ������� �� ������� ��� ���������� �� ����������� �������� ��� ������� � ������ ��������� ������.

strParGetPeaks(void); // �����������.
void Init(void); // �������������.
BYTE IsOK(void); // ��������.
UINT Check(void); // �������� � ���������.
BYTE Read_(FILE *file); // ������ �� �����.
BYTE Read(char *Path,char *fName); // ������ �� �����.
BYTE Write_(FILE *file); // ������ � ����.
BYTE Write(char *Path,char *fName); // ������ � ����.
BYTE SetDlg(HWND hDlg); // ��������� � ���������� ����.
BYTE GetDlg(HWND hDlg); // ��������� �� ����������� ����.
void OnCreateDlg(HWND hDlg); // �������� ��� �������� ����������� ����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ���������� ������������ ����� ������� ������ � ���������������� ������������� ������� � ��������� ������.

struct strParInpSpectr {

float AmpThr; // ��������� ��� ��������� ���������� ����.
float FreqMin; // ����������� ������� (��).
float FreqMax; // ������������ �������, �� ������� ���������� ������ (��).
float FreqDiscrTri; // ������� �� ������� ��� ���������� �� ����������� ��������.

strParInpSpectr(void); // �����������.
void Init(void); // �������������.
BYTE IsOK(void); // ��������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ���������� ��������� ����.

#define nMethTrain 5 // ����� ������� ���������� ��������� ����.

#define methTrain_Sequent     0 // ���������������� ����� ����������.
#define methTrain_SequentRep  1 // ���������������� ����� ������������� ��������������� ������.
#define methTrain_SequentLay  2 // ���������������� ��������� ����� ����������.
#define methTrain_Group       3 // ��������� �����, � ��� ����� � ���������� �����.
#define methTrain_GroupSearch 4 // ��������� ����� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ���������� ���������� ����.

#define nStRand_Stand 300 // ����� ����� ���������� ������� ������������� - ����������� ��������.
#define nStTrain_Stand 100 // ����� ����� ���������� � ����� - ����������� ��������.
#define RandSeq_Stand 2011 // �����, �������� ��������� ������������������ - ����������� ��������.
#define AlphaTrain_Stand 0.01F // ��� ���������� ���� - ����������� ��������.
#define AlphaMinTrain_Stand 1.e-4F // ����������� ����������� ���� ����� - ��������� ��������.
#define AlphaMaxTrain_Stand 0.4F // ����������� ����������� ���� ������ - ��������� ��������.
#define coeWei_Stand 0.5F // ����������� ��� ����� ��� ��������� ������� ������������� - ����������� ��������.
#define coeTe_Stand 0.5F // ����������� ��� �������� ��� ��������� ������� ������������� - ����������� ��������.
#define coeVect_Stand 1.0F // ����������� ��������� ����� � ������� ��� ��������� ������� - ����������� ��������.
#define nCycleRandSamples 3 // ����� ������ ��������� ����������� ������� ������������ ��������.
#define flCorrAdaptStep 1 // ��� ������������� ����������� ���� (0 - �������, 1 - �� ������������).
#define CoeAdaptStep_Stand 0.8F // ����������� ����������� ��� ����������� ����.
#define CoeAdaptStep_Min 0.1F // ����������� ����������� ��� ����������� ���� - ����������� ��������.
#define nStSeqLay_Stand 20 // ����� ����� � ����� ���������� ���������������� ��������� ������� - ����������� ��������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ���������� ����.

struct strParTrainNNW {

BYTE methTrain; // ����� ���������� ��������� ����.
BYTE flAdaptSt; // ���� ������������ ����������� ���� ��� ����������.
USHRT nStRand; // ����� ����� ���������� ������� �������������.
USHRT nStTrain; // ����� ����� ���������� � �����.
USHRT nStSeqLay; // ����� ����� � ����� ���������� ���������������� ��������� �������.
UINT RandSeq; // �����, �������� ��������� ������������������.
BYTE flRandSampl; // ���� ���������� ������ �������� ��� ����������.
float Alpha; // ���������� ��� ���������� ����.
float AlphaMin; // ����������� ����������� ���� ������.
float AlphaMax; // ����������� ����������� ���� �����.
BYTE flEqualAdaptSt; // ���� ����������� ����������� ���� ��� ���� ����.
float CoeAdaptStep; // ����������� ����������� ��� ����������� ����. 
float coeWei; // ����������� ��� ����� ��� ��������� ������� �������������.
float coeTe; // ����������� ��� �������� ��� ��������� ������� �������������.
float coeVect; // ����������� ��������� ����� � ������� ��� ��������� �������.

strParTrainNNW(void); // �����������.
void Init(void); // �������������.
BYTE IsOK(void); // ��������.
USHRT Check(void); // �������� � ���������.
BYTE Read_(FILE *file); // ������ �� �����.
BYTE Read(char *Path,char *fName); // ������ �� �����.
BYTE Write_(FILE *file); // ������ � ����.
BYTE Write(char *Path,char *fName); // ������ � ����.
void SetDlg(HWND hDlg); // ��������� � ���������� ����.
BYTE GetDlg(HWND hDlg); // ��������� �� ����������� ����.
void OnCreateDlg(HWND hDlg); // �������� ��� �������� ����������� ����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� ����� ������� ��� ��������� �������������.

typedef BYTE (*pFunDecSnd)(PNT_DATA Pnt,strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // ������� �������� ������� ��� ������������� �����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ���������� �������� ������� �������� ��� ������� �����.

struct strParIncHighSynth { BYTE nc; float coeCorr,CorrMax;};
