/*...........................................................................................................

strResRec,strDBS,strDBSArr,strDBF,strDBFArr,strDataTrain,strDataTrainArr,strStatSnd,strStatSndAll,
clDlgDBF_NNW,clWinViewNNW,strParAnSnd,strAnSnd,strAnSndArr,strAnalyseSound,clWinText,clMain

...........................................................................................................*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C�������� ���������� �������������.

struct strResRec {

UINT nSamp; // ����� ��������, �� ������� ���������� �������.
float prcTrue,prcFalse,prcNo; // �������� ������������� - �����������, ������ ����, ������������.
float Err; // ������������������ ������.

strResRec(void); // �����������.
void Zero(void); // ��������� � ������������� ����������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C�������� ���������� ������� (�����) ������ �����.

struct strDBS {

BYTE flUse; // ���� �������������.
BYTE flTrain; // ���� ����������.
BYTE nRep; // ����� ����������.
char cSnd; // ����������� �����.
BYTE typSnd; // ��� �����.
BYTE numSnd; // ����� ����� � ������.
float tI,tF; // ��������� � �������� ����� ��������� �����.
struct strResRec Res; // ��������� ������������� �����.
clSpDiag Diag; // ��������� ������������ ���������.
clInpLayArr Peaks; // ������������ �����.
clInpLayArr InpData; // ������� ������ ��� ����.
BYTE typInpData; // ��� ������� ������ ��� ����.

strDBS(void); // �����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void ZeroRes(void); // ��������� ����������� �������������.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Write(FILE *file); // ������ � ����.
void Print(void); // ������ � ������.
BYTE ProcSpectr(strSndArr *Snd,strParSpProc *Param,BYTE *flStop); // ���������� � ������.
BYTE GetPeaks(BYTE *flStop); // ���������� ������������ �����.
BYTE GetInpData(BYTE typNet,BYTE typID,BYTE *flStop); // ���������� ������� ������.
BYTE GetInpDataVC(BYTE typID,BYTE *flStop); // ���������� ������� ������ ��� ���������� ���� ��� ������� ��� ���������.
BYTE GetInpDataSp(BYTE *flStop); // ���������� ������� ������ ��� ����� ���� ��� ����� �������.
BYTE GetResult(strNNW *pNNW); // ��������� ���������� �������������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C�������� ���� ������ �� ������ ������ �����.

struct strDBSArr {

BYTE nDBS; // ����� ������� (������) � �����.
struct strDBS *DBS; // ������ �������� ������� (������).
struct strSndArr Snd; // ������ ��������� �����.
BYTE flChange; // ���� ��������� ���� ������.

strDBSArr(void); // �����������.
~strDBSArr(void); // ����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
BYTE Alloc(BYTE nDBS_); // ��������� ������.
BYTE IsOK(void); // �������� ������� ��������.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Write(FILE *file); // ������ � ����.
BYTE Read_(char *fName); // ������ �� �����.
BYTE Write_(char *fName); // ������ � ����.
BYTE ReadSound(char *fName); // ������ ��������� �����.
BYTE FillLBParam(HWND hDlg); // ���������� ������ ��������� ���� ������.
strDBS *Get(BYTE num); // ��� ��������� �� ��������� ������� (�����) ������ �����.
BYTE ProcSpectr(strParSpProc *Param,BYTE *flStop); // ���������� � ������.
BYTE SoundSel(void); // ����������� ���������� ���������.
BYTE GetPeaks(BYTE *flStop); // ���������� ������������ �����.
BYTE GetInpData(BYTE typNet,BYTE typInpData,BYTE *flStop); // ���������� ������� ������.
void SetResZero(void); // ��������� ����������� �������������.
BYTE GetResult(strNNW *pNNW,BYTE flAll); // ��������� ���������� �������������.
BYTE CalcResult(strResRec *pRes); // ������� ����������� �� ������������� ��� ���� ������ ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C�������� �������� ���������� �����, ������������� ��� ���������� �����.

struct strDBF {

char *FName; // ��� �����.
char *NamePeople; // ��� ��������, ������������� ����.
BYTE Gender; // ��� ��������, ������������� ����.
BYTE flUse; // ���� �������������.
BYTE flTrain; // ���� ����������.
struct strDBSArr DBS; // ���� ������ �� ������ ������ �����.
struct strResRec Res; // ��������� ������������� ��� ���� ������ ���� ������.

strDBF(void); // �����������.
~strDBF(void); // ����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Write(FILE *file); // ������ � ����.
BYTE ReadDBS(char *Path,char *Dir); // ������ ��� ������ �� ������ ������ �����.
BYTE WriteDBS(char *Path,char *Dir); // ������ ��� ������ �� ������ ������ �����.
void Print(void); // ������ � ������.
BYTE ProcSpectr(strParSpProc *Param,BYTE *flStop); // ���������� � ������.
BYTE GetPeaks(BYTE *flStop); // ���������� ������������ �����.
BYTE GetInpData(BYTE typNet,BYTE typInpData,BYTE *flStop); // ���������� ������� ������.
void SetResZero(void); // ��������� ����������� �������������.
BYTE GetResult(strNNW *pNNW,BYTE flAll); // ��������� ���������� �������������.
BYTE CalcResult(void); // ������� ����������� �� ������������� ��� ����� �����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C�������� ���� ������ �� ���� ������ ��� ���������� ��������� ����.

struct strDBFArr {

BYTE n; // ����� ������.
struct strDBF *DBF; // ������ ��������.
char *PathDir; // ����������, ��� �������� ����� ���� ������.
char *NameFile; // ��� ����� ���� ������.
BYTE flChange; // ���� ��������� ���� ������.

strDBFArr(void); // �����������.
~strDBFArr(void); // ����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
void FreeDBF(void); // ������������ ������ �� ������� ��������.
BYTE AllocDBF(BYTE n_); // ��������� ������.
BYTE IsOK_DBF(void); // �������� ������� ��������.
strDBF *Get(BYTE num); // ��� ��������� �� ��������� ���� ������ �����.
BYTE Read(FILE *file); // ������ �� �����.
BYTE Write(FILE *file); // ������ � ����.
BYTE Read_(char *Path,char *Name); // ������ �� �����.
BYTE Write_(char *Path,char *Name); // ������ � ����.
BYTE Write_(void); // ������ � ����.
BYTE ReadDBS(char *Path); // ������ ��� ������ �� ������ ������ �����.
BYTE WriteDBS(char *Path); // ������ ��� ������ �� ������ ������ �����.
BYTE SetFlagChange(BYTE num,BYTE flag); // ��������� ����� ���������.
void SetResZero(void); // ��������� ����������� �������������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C�������� ������ ������ ��� ���������� ��������� ����.

struct strDataTrain {

BYTE *pFlUseFile; // ��������� �� ���� ������������� ��� �����.
BYTE *pFlTrainFile; // ��������� �� ���� ���������� ��� �����.
BYTE *pFlUseSnd; // ��������� �� ���� ������������� ��� ����� � �����������.
BYTE *pFlTrainSnd; // ��������� �� ���� ���������� ��� ����� � �����������.
BYTE flUse; // ���� �������������.
BYTE flTrain; // ���� ����������.
struct strInpLay *InpLay; // ��������� �� ������ �������� ���� ����.
struct strInpLay *TrueOut; // ��������� �� ������ ����������� ��������� ����.
BYTE nRep; // ����� �������� (��� �������������� ������).

strDataTrain(void); // �����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
BYTE IsOK(void); // �������� ������� ��������.
void SetFlags(void); // ��������� ������ ������������� � ����������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C�������� ������� ������ ��� ���������� ��������� ����.

struct strDataTrainArr {

UINT nDT; // ����� ��������� ������.
struct strDataTrain *DT; // ������ �������� ������ ��� ���������� ��������� ����.

strDataTrainArr(void); // �����������.
~strDataTrainArr(void); // ����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
BYTE Alloc(UINT nDT_); // ��������� ������.
BYTE IsOK(void); // �������� ������� ��������.
strDataTrain *Get(UINT num); // ��������� ��������� �� ��������� ������.
BYTE SetFlags(void); // ��������� ������ ������������� � ����������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C�������� ���������� ��� �����.

struct strStatSnd {

char c; // ����������� �����.
USHRT nIntTrain,nIntCntrl; // ����� ���������� ��� ���������� � ��������.
UINT nSampTrain,nSampCntrl; // ����� �������� (�� ��������� ��������� ������� � ������ ��������) ��� ���������� � ��������.

strStatSnd(void); // �����������.
void Zero(void); // ��������� ����������.
void Print(void); // ������ � ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C�������� ���������� ��� ������ ������.

struct strStatSndAll {

BYTE nSnd; // ����� ������.
struct strStatSnd *StatSnd; // ������ �������� ���������� ��� ������.

strStatSndAll(void); // �����������.
~strStatSndAll(void); // ����������.
void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
BYTE Alloc(BYTE nSnd_); // ��������� ������.
BYTE IsOK(void); // ��������.
BYTE FillLB(HWND hDlg,int id); // ���������� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ����� ����� ���������� ������ �� ����������� ���� ���� ������.

#define numBlkDBF_PreProc 0 // ������������� (�����, ������������ �����).
#define numBlkDBF_InpData 1 // ���������� �������� ������� ������ ����.
#define numBlkDBF_Train   2 // ���������� ��������� ����.
#define numBlkDBF_Sound   3 // ������������� �����.
#define numBlkDBF_TestDBS 4 // ���� ��������� ���� �� ���� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ��� �������������� ���� ������ � ���������� ��������� ����.

class clDlgDBF_NNW {

HWND hDlg; // ������������� ����������� ����.
HWND hwndProgr; // ������������� ������ ���������.
HWND hDlgAdjNNW; // ������������� ����������� ���� ������� ���������� ��������� ����.
struct strDBFArr *pDataBase; // ��������� �� ��������� ���� ������ �� ������.
struct strNNW *pNNW; // ��������� �� ��������� ��������� ����.
struct strNNW *pNNW_Vowel; // ��������� �� ��������� ��������� ���� ��� �������.
struct strNNW *pNNW_Cons; // ��������� �� ��������� ��������� ���� ��� ���������.
struct strNNW *pNNW_Spectr; // ��������� �� ��������� ��������� ���� ��� ����� �������.
struct strDBF *selDBF; // ��������� �� ��������� ���������� �����.
BYTE numSel; // ����� ��������� ������.
BYTE numFileLoad; // ����� ������������ �����.
BYTE numSelSound; // ����� ��������� ������ � ������ ������.
BYTE flPlaySound; // ���� ������ �����.
BYTE flStopSound; // ���� ��������� ������ �����.
BYTE typPlaySound; // ��� ������ ����� - 0 - �������� ����, !=0 - ���������������.
BYTE flPreProc; // ���� ���������� ��������������� ��������� (�������������� �����, ��������� ������������ �����, ���������� �������������� �������).
BYTE flStopPreProc; // ���� ��������� ��������������� ���������.
BYTE flPreProcDone; // ����, ������������, ��� ��������������� ��������� ���������.
BYTE flSetData; // ���� ���������� ���������� ������� ������� ������.
BYTE flStopSetData; // ���� ��������� ��������� ������� ������.
BYTE flSetDataDone; // ����, ������������, ��� ��������� ������� ������ ���� ���������.
BYTE flTypInpData; // ��� ������������� ������� ������.
BYTE flTrain; // ���� ����������.
BYTE flStopTrain; // ���� ��������� ����������.
BYTE flBlk; // ���� ���������� ������.
BYTE typNet; // ��� ���� - �������/���������/������.
HWAVEOUT hwo; // ��������� ��� ������ �����.
clDlgParNNW DlgParNNW; // ������ ������ ����������� ���� ��� �������������� ���������� ��������� ����.
struct strParNNW *pParNNW; // ��������� �� ��������� ���������� ��������� ����.
struct strParNNW ParNNW_Vowel; // ��������� ���������� ��������� ���� ��� ������� ������.
struct strParNNW ParNNW_Cons; // ��������� ���������� ��������� ���� ��� ��������� ������.
struct strParNNW ParNNW_Spectr; // ��������� ���������� ��������� ���� ��� ���������� �� ����� �������.
struct strParTrainNNW ParTrain; // ��������� ���������� ���������� ����.
struct strDataTrainArr DataTrain; // C�������� ������� ������ ��� ���������� ��������� ����.
clInpLayArr TrueOutSnd; // ������ ���������� ������� ��������� ���� ��� ���� ������.
HBRUSH hBrushBkg,hBrushDial; // ����� ��� ������������ ����.
float *pWaveSynth; // ��������� �� ������ ��� ������ ���������������� �����.

void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
void ZeroBrushes(void); // ��������� ������ ��� ������������ ����.
void FreeBrushes(void); // �������� ������ ��� ������������ ����.
BYTE CreateBrushes(void); // �������� ������ ��� ������������ ����.
void ZeroWaveSynth(void); // ��������� ��������� �� ������ ��� ������ ���������������� �����.
void FreeWaveSynth(void); // �������� ������� ��� ������ ���������������� �����.
BYTE CreateWaveSynth(UINT nWaveSynth); // ��������� ������ ��� ������� ��� ������ ���������������� �����.
BYTE SaveFileDBF(void); // ���������� ��������� � ���� ���� ������.
void UnSelFile(void); // �������� ��� ������ ������� �����.
BYTE OnSelChangeFile(void); // �������� ��� ������ ������ ������ � ������ ������.
BYTE SetWinParFile(void); // ��������� ���������� ����� ���� ������ � �����.
void ClearWinParFile(void); // ������� ���� ���������� ����� ���� ������ � �����.
void UnSelSound(void); // �������� ��� ������ ������� �����.
BYTE OnSelChangeSound(void); // �������� ��� ������ ������ ������ � ������ ������.
BYTE FindSoundDiag(void); // ���������� ����������� ����� �� ���������.
BYTE SetWinParSound(void); // ��������� ���������� ������� ����� ���� ������ � �����.
void ClearWinParSound(void); // ������� ���� ���������� ������� ����� ���� ������ � �����.
BYTE LoadFile(void); // �������� ����� � ���������� ���������.
BYTE OnChangeStrFile(void); // �������� ��� ��������� ��������� ������ �����.
BYTE OnChangeStrSound(void); // �������� ��� ��������� ��������� ������ �����.
void SetHeaderWinAlpha(void); // ��������� ��������� ���� ����.
void SetFlagChange(BYTE num,BYTE flag); // ��������� ����� ���������.
BYTE ReadNNW(BYTE typ); // ������ ����� ��������� ����.
BYTE SaveNNW(BYTE typ); // ���������� ����� ��������� ����.
BYTE SaveAsNNW(BYTE typ); // ���������� ����� ��������� ���� ��� ������ ������.
BYTE ReadParNNW(void); // ������ ����� ���������� ��������� ����.
BYTE SaveParNNW(void); // ���������� ����� ���������� ��������� ����.
BYTE SaveAsParNNW(void); // ���������� ����� ���������� ��������� ���� ��� ������ ������.
BYTE AdjustParNNW(void); // ��������� ���������� ��������� ����.
BYTE InitNNW(void); // ������������� ����� ��������� ���� �� �������� ����������.
BYTE GetParFromNNW(void); // ���������� ��������� ���������� ���� �� ��������� ����.
BYTE AdjParTrain(void); // �������������� ���������� ���������� ����.
BYTE ProcSpectr(BYTE *flStop,BYTE flAll); // ���������� � ������.
BYTE GetPeaks(BYTE *flStop); // ���������� ������������ �����.
BYTE GetInpData(BYTE typInpData,BYTE *flStop); // ���������� ������� ������.
BYTE ProcSpectrPeaks(void); // �������������: �������������� �����, ���������� ������������ �����.
BYTE ProcSetInpData(void); // �������������: ���������� ������� �������� ����.
BYTE FillTrainData(void); // ���������� �������������� �������.
BYTE FillTrueOut(void); // ���������� �������� ���������� �������� ��������� ���� ����.
void CmndTrainNNW(void); // ������� �� ���������� ����.
BYTE TrainNNW(void); // ���������� ��������� ����.
BYTE TrainNNW_Seq(void); // ���������� ��������� ���� ���������������� �������.
BYTE TrainNNW_SeqRep(void); // ���������� ��������� ���� ���������������� ������� � ������������ ���������������� ������.
BYTE TrainNNW_SeqLay(void); // ���������� ��������� ���� ���������������� ��������� �������.
BYTE TrainNNW_Group(void); // ���������� ��������� ���� ��������� �������, � ��� ����� � ���������� �����.
BYTE TrainNNW_GroupSearch(void); // ���������� ��������� ���� ��������� ������� ������.
BYTE TrainNNW_MonteCarlo(void); // ���������� ��������� ���� ������� ���������� ������ (�����-�����).
BYTE TrainSearchIniRandom(void); // ���� ������ ���������� ����������� ��� ���������� ��������� ����.
BYTE StepTrainErr(double *pErr,double *pErrCntrl); // ��� ������������ �������� � ����������� ������.
BYTE StepTrainSequent(double *pErr,double *pErrCntrl); // ��� ������������ �������� ��� ���������������� ���������� ���� ������� ��������� ��������������� ������.
BYTE StepTrainSequentRep(double *pErr,double *pErrCntrl); // ��� ������������ �������� ��� ���������������� ���������� ���� ������� ���������� ��������� ��������������� ������.
BYTE StepTrainSequentLay(void); // ��� ���������� ��������� ���� ���������������� ��������� �������.
BYTE InitSequentLay(UINT nNumSampl,UINT *pNumSampl); // ������������� ��������� �������� � �������� �������� ��������� ���� ��� ���������� ��������� ���� ���������������� ��������� �������.
BYTE StepSequentLay(BYTE numLay,UINT nNumSampl,UINT *pNumSampl); // ��� ������������ �������� ��� ���������� ��������� ���� ���������������� ��������� �������.
BYTE FindVectGroup(double *pErr,double *pWei,double *pErrCntrl,double *pWeiCntrl); // ��� ������������ �������� ��� ���������� ���� ��������� ������� ��������� ��������������� ������.
BYTE StepFindAdaptStepGroup(void); // ��� ������������ �������� ��� ���������� ����������� ���� ��� ���������� ���� ��������� ������� ��������� ��������������� ������.
void SetErrWin(double Err,double ErrCntrl); // ��������� ������ � �����.
void ClearErrWin(void); // ��������� ������ � �����.
void GetStepTrain(void); // ��������� ���� ����������.
void SetStepTrain(void); // ��������� ���� ����������.
void ShowHideWinStepTrain(void); // ������������ � ������� ����, ����������� � ��������� ���� ��� ����������� ����.
void SetNameTrainMeth(void); // ��������� �������� ������ ����������.
void ShowProgr(UINT i,UINT n); // ������ ���������.
BYTE Command(WPARAM wParam); // �������.
void OnSelectTypNet(int id); // ����� ���� ����.
void SetPntNNW(void); // ��������� ���������� �� ��������� ��������� ���� � ���������� ��������� ����.
void DrawNet(void); // ����������� ����������� ����.
void SetFocusWin(void); // ��������� ������ �����.
BYTE FillLBFiles(void); // ���������� ������ ������ ���� ������.
BYTE StartPlaySound(void); // ����� �����.
BYTE StartPlaySoundPeaks(void); // ����� ���������������� �����.
void OnStopSound(void); // �������� ��� ��������� ������������ �����.
void OnChFlagPreProc(void); // �������� ��� ��������� ����� ���������� ��������������� ���������.
void OnChFlagSetInpData(void); // �������� ��� ��������� ����� ���������� ���������� ������� ������� ������.
void OnChFlagTrain(void); // �������� ��� ��������� ����� ���������� ����.
void SetStateRadioTypNet(BYTE En); // ���������� � ��������������� �������������� ������ ���� ��������� ����.
void InitParNNW(void); // ������������� �������� ���������� ��������� �����.
void SetTxtBtnPreProc(void); // ��������� ������ � ������ ��������������� ���������.
void SetTxtBtnSetData(void); // ��������� ������ � ������ ���������� ������� ������.
void SetTxtBtnTrain(void); // ��������� ������ � ������ ���������� ����.
void SetTxtBtnPlaySound(BYTE typ); // ��������� ������ � ������ ��������������� �����.
void SetTxtBtnBlockSetTime(void); // ��������� ������ � ������ ���������� ��������� ������� � ���� ������.
BYTE ShowStatistics(void); // ����� ���������� �� ������ ��� ������.
void FindShowResults(void); // ������ � ����������� ����������� �� �������� ������������� ������ ��� ���� ������.
BYTE DoTest(BYTE flAll); // ������ ����������� �� �������� ������������� ������ ��� ���� ������.
BYTE AcceptDBF(void); // �������� ��������� ���������� ����� ���� ������.
BYTE DelDBF(void); // �������� �� ������ ����� ���� ������.
BYTE InsDBF(void); // ������� ����� ���� ������.
BYTE AddDBF(void); // ���������� ����� ���� ������.
BYTE AcceptDBS(void); // �������� ��������� ���������� ������� ����� ���� ������.
BYTE DelDBS(void); // �������� �� ������ ������� ����� ���� ������.
BYTE InsDBS(void); // ������� ������� ����� � ������.
BYTE AddDBS(void); // ���������� ������� ����� � ������.
BYTE BrowseFileDBF(void); // ���������� � ������� ����� ���� ������.
void OnChangeGendDBF(BYTE Gender); // �������� ��� ��������� ���������� � ���� ��������.

public:

BYTE flBlkTime; // ���� ���������� ��������� ������� �� ���� ���������.
BYTE flLoadFile; // ���� �������� � ������� ��������� �����, ���������� � ���� ������.
struct strDBS *selDBS; // ��������� �� ��������� ���������� ����� � ��������� �����.

clDlgDBF_NNW(void); // �����������.
~clDlgDBF_NNW(void); // ����������.
void SetPntDataBase(strDBFArr *pDataBase_); // ��������� ��������� �� ��������� ���� ������ �� ������.
void SetPntNeurNet(strNNW *pNNW_Vowel_,strNNW *pNNW_Cons_,strNNW *pNNW_Spectr_); // ��������� ���������� �� ��������� ��������� ����� ��� ������� � ��������� � ����� �������.
BYTE IsOK_DBF(void); // �������� ������� �������� ���� ������.
BYTE OnOpenDlg(HWND hDlg_); // �������� ��� �������� ����������� ����.
void OnCloseDlg(void); // �������� ��� �������� ����������� ����.
void OnChDataBase(void); // �������� ��� �������� ��� �������� ���� ������.
void SetTimeSound(float time,BYTE fl); // ��������� �������� ������� � ��������� ���� ������ �� �����.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ��������� ����������� ���� ��������� � �������������� ���� ������.
BYTE SetNameNNW(BYTE typ); // ��������� ����� ����� ��������� ����.
BYTE SetFlagLoadFile(void); // ��������� ����� �������� �����.
BYTE IsTrain(BYTE typ); // �������� ���������� ���� ��� ��������� ���� ����.
BYTE IsDoTrain(void); // ��������, ��� �� ���������� ����.
BYTE IsDoPreProc(void); // ��������, ��� �� ��������������� ���������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ��� ���� ������������ ��������� ����.

class clWinViewNNW {

HWND hDlg; // ������������� ����������� ����.
HWND hwndOwner; // ������������� ������������� ����.
RECT *rcWin; // ������������� ����.
USHRT dxMin,dyMin; // ����������� ������� ����.
USHRT dxCntrl,dyCntrl; // ������� ���� ����������.
RECT rcFrame; // ������������� ���� � ������������ ����.
float AmpNormNeur; // ��������� ���������� ����������� ��������.
float AmpNormInp; // ��������� ���������� ����������� �������� �������� ���� ��������.
float AmpNormSynops; // ��������� ���������� ����������� ��������.
BYTE typNet; // ��� ���� - �������/���������.
BYTE flWork; // ���� ����������� ���� � ������.
BYTE flAxons; // ��� ��������� �������� ��� �������.
struct strNNW *pNNW; // ��������� �� ��������� ��������� ����.
struct strNNW *pNNW_Vowel; // ��������� �� ��������� ��������� ���� ��� �������.
struct strNNW *pNNW_Cons; // ��������� �� ��������� ��������� ���� ��� ���������.
struct strNNW *pNNW_Spectr; // ��������� �� ��������� ��������� ���� ��� ����� �������.
clImgMem *BmpNet; // ����������� ��������� ����.
RECT rc; // ��������������� ��������� ��������������.

void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
void CloseFree(void); // �������� ���� � ������������ ������.
void OnCloseWin(void); // �������� ��� �������� ����.
void GetMinSizeWin(void); // ��������� ������������ ������� ����.
void SetMinSize(LPMINMAXINFO lpMinMax); // ��������� ������������ ������� ����.
BYTE CreateDlgCntrl(void); // �������� ����������� ������������ ����.
void CloseDlgCntrl(void); // �������� ����������� ������������ ����.
BYTE OnPaint(HDC hdc); // ��������� � ����.
void UpdateWin(void); // ����������� ����.
void ZeroImgMem(void); // ��������� ��������� ��� �������� ������ ���� ����������� ����.
void FreeImgMem(void); // ������������ ������ �� �������� ������ ���� ����������� ����.
BYTE CreateImgMem(void); // �������� �������� ������ ���� ����������� ����.
BYTE IsOKImgMem(void); // �������� �������� ������ ���� ����������� ����.
BYTE DrawNetMem(void); // ��������� ����������� ���� � ������.
void ChPosSizeChWin(void); // ��������� ������������ �������� ����.
BYTE SetPosSizeChWin(void); // ��������� ������������ �������� ����.
void OnSelectTypNet(int id); // ����� ���� ����.
void SetNet_(BYTE typ); // ��������� ���� ��������� ����.
void SetTxtBtnWork(void); // ��������� ������ � ������ ����������� ���� � ������.
void clWinViewNNW::OnSelectTypShowAxons(int id); // ��������� ���� ����������� ��� �������.
BYTE Command(WPARAM wParam); // �������.

public:

HWND hwnd; // ������������� ����.

clWinViewNNW(void);
~clWinViewNNW(void);
void SetParPnt(HWND hwndOwner_,RECT *rcWin_); // ��������� ���������� � ����������.
void SetPntNeurNet(strNNW *pNNW_Vowel_,strNNW *pNNW_Cons_,strNNW *pNNW_Spectr_); // ��������� ���������� �� ��������� ��������� ����� ��� ������� � ���������.
BYTE CreateWin(void); // �������� ����.
void CloseWin(void); // �������� ����.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ��������� ����.
LRESULT MsgCommandCntrl(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ������� ��������� ���� ����������.
void DrawNet(void); // ����������� ����������� ����.
void SetNet(BYTE typ); // ��������� ���� ��������� ����.
void SetFlagWork(BYTE flWork_); // ��������� ����� ����������� ���� � ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ���������� ��� ������� ������ ������ ��� �����.

struct strParAnSnd {

float tStore; // ����� ���������� �������.
float weiStore; // ����������� ����� ������������ �������.
float weiInst; // ����������� ����� �������� �������.

BYTE IsOK(void); // ��������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ��� ������� ������ ������ ��� �����.

struct strAnSnd {

USHRT nBuf,cnt; float *Buf,weiStore,weiInst; double sum;

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

float ResVowel[nVoicesVowel],ResCons[nVoicesCons]; // ������� ��� �������� ����������� �������������.
struct strAnSndArr AnSndVowel,AnSndCons; // ��������� ��� ������� ������ ������.

BYTE Init(float tStep,BYTE flNew); // �������������.
BYTE Start(void); // ������ ������.
BYTE Step(float *pVal,BYTE nVal,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // ��� ������.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������������� �������� ����.

#define id_Win_Edit 1 // ���� ��������� ������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ��� ���� ������ �������������.

class clWinText {

HWND hwndEdt; // ������������� ���� ��������������.
HWND hwndOwner; // ������������� ������������� ����.
RECT *rcWin; // ������������� ����.
RECT rcEdt; // ������������� ���� ��������� ������.
USHRT dxMin,dyMin; // ����������� ������� ����.
HBRUSH hBrushBkg,hBrushDial; // ����� ��� ������������ ����.
HFONT hFontText; // ����� ��� ������ ������.

void Zero(void); // ��������� ���������� � ������������� ����������.
void Free(void); // ������������ ������.
void ZeroBrushes(void); // ��������� ������ ��� ������������ ����.
void FreeBrushes(void); // �������� ������ ��� ������������ ����.
BYTE CreateBrushes(void); // �������� ������ ��� ������������ ����.
void ZeroFont(void); // ��������� ��������� ��� ������.
void FreeFont(void); // �������� ������.
BYTE LoadFont(void); // �������� ������.
void OnCloseWin(void); // �������� ��� �������� ����.
void GetMinSizeWin(void); // ��������� ������������ ������� ����.
void SetMinSize(LPMINMAXINFO lpMinMax); // ��������� ������������ ������� ����.
BYTE CreateEdt(void); // �������� ���� ��������������.
void CloseEdt(void); // �������� ���� ��������������.
void ChPosSizeChWin(void); // ��������� ������������ �������� ����.
BYTE SetPosSizeChWin(void); // ��������� ������������ �������� ����.

public:

HWND hwnd; // ������������� ����.

clWinText(void);
~clWinText(void);
void SetParPnt(HWND hwndOwner_,RECT *rcWin_); // ��������� ���������� � ����������.
BYTE CreateWin(void); // �������� ����.
void CloseWin(void); // �������� ����.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ��������� ����.
BYTE SetText(char *Text); // ��������� ������ � ����.
void ClearWin(void); // ������� ����.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������������� �������� ����.

#define idMain_SpDiag   1 // ������������� ��������� ���� ������������ ���������.
#define idMain_GrSig    2 // ������������� ��������� ���� ������� �������.
#define idMain_GrSpectr 3 // ������������� ��������� ���� ������� �������.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ����� ����� ���������� ������ �� ���������.

#define numBlkMain_Proc   0 // ���������.
#define numBlkMain_Sound  1 // ����� �����.
#define numBlkMain_SndCap 2 // ������ �����.
#define numBlkMain_DlgDBS 3 // ������� ���������� ���� ���� ������ � ���������� ����.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� �������� ����.

class clMain {

BYTE flTi,flFr,flAm,flStopSound,flPlaySound,flEnCaptSound,flCaptSound,flStopCaptSound,flRegCapt,
flProc,flStopProc,flDBS,flDlgDBS,flBlk,methDecSound,flCurGrSig,typShowLineDiag,typUseNNWRec;
int pScDiagH,pMScDiagH,pScDiagV,pMScDiagV,pScGrSp,pMScGrSp,pScGrSig,pMScGrSig,CoordTimeDiag,CoordTimeSig;
UINT PosCurSnd,TimeRecBuf,TimeRecProc,nRecChar; float AmpSig,AmpNorm,AmpSpect,TimeCur,FreqCur;
RECT rc,rcDiag,rcSig,rcSpect,rcCntrl,rcViewNNW,rcText; HWND hwndProgr,hwndPerc; HBRUSH hBrushBkg,hBrushDial;
HMENU hMenu; HWAVEOUT hwo;

clHelpEx *Help; // ����� �������.
clLoadDLLSndCap *SndCap; // ����� ��� ������ � ����������� �� ������� �����.
struct strSndArr Snd; // ����� �������.
clSndCapData *SndCapData; // ����� �����, ����������� ��� ������ � ���� ��������� ��������.
clBmpPict *BmpDiag; // ������� ����������� ���������.
clSpDiag SpectrAmp; // ��������� ������ ���������.
clSpLinesArr SpLines; // ����� ������� ������������ �����.
clArrBYTE ResNNW; // ������ ������� ��������.
clString RecNNW; // ������ ������� ��������, �������������� � �������� �������.
struct strDBFArr DataBase; // ����� ���� ������.
struct strNNW NNW_Vowel,NNW_Cons,NNW_Spectr; // ������ ��������� �����.
struct strPal PalDiag; // ��������� ������� ��� ����������� ���������.
struct strAnalyseSound AnSound; // ��������� ��� ������� ������ ��������.
clDlgDBF_NNW DlgDBFNNW; // ����� ����������� ���� ���� ������ � ���������� ��������� ����.
clWinViewNNW WinViewNNW; // ����� ���� ��������� ������ ��������� ����.
clWinText WinText; // ����� ���� ������ - ���������� �������������.

void Zero(void); // ��������� ��������������� � ����������.
void Free(void); // �������� �������� �� ������.
void ZeroBrushes(void); // ��������� ������ ��� ������������ ����.
void FreeBrushes(void); // �������� ������ ��� ������������ ����.
BYTE CreateBrushes(void); // �������� ������ ��� ������������ ����.
void ZeroHelp(void); // ��������� ��������� ��� ������ ��� ������ ����� �������.
void FreeHelp(void); // ����������� ������ ��� ������ ����� �������.
BYTE CreateHelp(void); // �������� ������ ��� ������ ����� �������.
void ChMenuHelp(void); // ��������� ��������� ������ ���� �������.
void ZeroBmpDiag(void); // ��������� ��������� �� ����� ��� ������ ����������� ���������.
void FreeBmpDiag(void); // �������� ������ ��� ������ ����������� ���������.
BYTE CreateBmpDiag(void); // �������� ������ ��� ������ ����������� ���������.
void OnBegin(void); // �������� ��� �������� ������� ������ �������� ����.
BYTE CreateDlgCntrl(void); // �������� ����������� ������������ ����.
BYTE CreateWinDiag(void); // �������� ��������� ���� ���������.
void OnChSizeWinDiag(void); // �������� ��� ��������� �������� ���� ���������.
BYTE SetScrollDiagH(void); // ��������� ���������� ��������� ���� ��������� �� �����������.
BYTE SetScrollDiagV(void); // ��������� ���������� ��������� ���� ��������� �� ���������.
BYTE HScrollDiag(WPARAM wParam); // ������������� ���� ��������� �� �����������.
BYTE VScrollDiag(WPARAM wParam); // ������������� ���� ��������� �� ���������.
BYTE OnMouseMoveDiag(LPARAM lParam); // �������� ��� ����������� ������� ���� � ���� ���������.
BYTE CreateWinGraph(void); // �������� ��������� ���� ������� �������.
BYTE OnMouseMoveGraphSig(LPARAM lParam); // �������� ��� ����������� ������� ���� � ���� ������� �������.
void OnChSizeWinGraphSig(void); // �������� ��� ��������� �������� ���� ������� �������.
BYTE SetScrollGrSig(void); // ��������� ���������� ��������� ���� ������� �������.
BYTE HScrollGrSig(WPARAM wParam); // ������������� ���� ������� �������.
BYTE CreateWinGraphSpectr(void); // �������� ��������� ���� ������� �������.
BYTE OnMouseMoveGraphSpectr(LPARAM lParam); // �������� ��� ����������� ������� ���� � ���� ������� �������.
void OnChSizeWinGraphSpectr(void); // �������� ��� ��������� �������� ���� ������� �������.
BYTE SetScrollGrSpectr(void); // ��������� ���������� ��������� ���� ������� �������.
BYTE HScrollGrSpectr(WPARAM wParam); // ������������� ���� ������� �������.
BYTE Command(WPARAM wParam); // �������.
void FreeDiagRes(void); // ������������ ������ ��� ��������� � ������ �����������.
BYTE ComputeDiag(void); // ������ ���������.
BYTE ComputeSpLines(void); // ���������� ������������ ����� ��� ����� �����.
BYTE RecognNNW_All(void); // ������������� ������� ��������� ����� ��� ����� �����.
BYTE OutTextRecogn_All(void); // ����� ������ ������������� ����� ��������� � ���� ������.
BYTE DrawDiag(void); // ���������� ������������ ���������.
BYTE OnPaintDiag(HDC hdc); // ��������� � ���� ������������ ���������.
BYTE DrawCursorsDiag(HDC hdc); // ��������� �������� � ���� ������������ ���������.
BYTE OnPaintDiagDef(HDC hdc); // ������������ ���� ������������ ���������.
BYTE OnPaintGraphSig(HDC hdc); // ��������� � ���� ������� �������.
BYTE DrawCursorGraphSig(HDC hdc); // ��������� ������� � ���� �������.
BYTE OnPaintGraphSigDef(HDC hdc); // ������������ ���� ������� �������.
BYTE OnPaintGraphSpectr(HDC hdc); // ��������� � ���� ������� �������.
BYTE OnPaintGraphSpectrDef(HDC hdc); // ������������ ���� ������� �������.
BYTE DrawPeaksGraphSpectr(HDC hdc); // ��������� ������������ ����� � ���� ������� �������.
BYTE RecognNNW(void); // ������������� ������ ������� ��������� �����.
BYTE ProcRecRealTime(void); // ��������� � ������������� � �������� �������.
void FindCoordChildWin(void); // ���������� ��������� ������� ����.
void MoveChWin(void); // ����������� ���� ������� � ���������.
void OnChSizeWin(void); // ����������� �������� ���� �������, ��������� � ������� �������.
void CloseFileSound(void); // �������� ��������� �����.
BYTE OpenFileSound(void); // �������� ��������� �����.
BYTE SaveFileSound(void); // ���������� ��������� �����.
void ZeroSndCap(void); // ��������� ��������� �� ������ ������ ���������� ������� �����.
void FreeSndCap(void); // �������� ������� ������ ���������� ������� �����.
BYTE CreateSndCap(void); // �������� ������� ������ ���������� ������� �����.
BYTE StartCaptureSound(BYTE flag); // ��������� ������ �����.
void StopCaptureSound(BYTE flag); // ��������� ������ �����.
void StopCaptureSound_(void); // ��������� ������ �����.
void SetTxtBtnCaptSound(void); // ��������� ������ � ������ ������ �����.
void SetTxtBtnRecSound(void); // ��������� ������ � ������ ������������� �����.
BYTE SaveSndCapData(void); // ���������� ����������� ������� �����.
BYTE DlgAdjSound(void); // ��������� ������� �����.
void ZeroSndCapData(void); // ����� �������� ������ ��� ������ �����: ��������� ���������.
void FreeSndCapData(void); // ����� �������� ������ ��� ������ �����: �c���������� ������.
BYTE CreateSndCapData(void); // ����� �������� ������ ��� ������ �����: ��������.
void AdjParSpectr(void); // �������������� ���������� ������������� ����������.
void AdjParPeaks(void); // �������������� ���������� ��������� ������������ �����.
void CloseDataBase(void); // �������� ���� ������.
BYTE OpenDataBase(void); // �������� ����� ���� ������.
void OpenDlgDBS_NNW(void); // �������� ����������� ���� ���� ������ � ���������� ����.
void ChBtnMenuOpenDlgDBS_NNW(void); // ��������� ��������� ������ � ������ ���� �������� ����������� ���� ���� ������ � ���������� ����.
void ChBtnCaptSound(void); // ��������� ��������� ������ ������� �����.
void SetPntWinViewNNW(void); // ��������� ���������� � ���������� ��� ���� ������������ ��������� ����.
BYTE GetSizeWinViewNNW(void); // ��������� �������� ���� ������������ ��������� ����.
void OpenWinViewNNW(void); // �������� ���� ������������ ��������� ����.
void SetPntWinText(void); // ��������� ���������� � ���������� ��� ���� ������.
BYTE GetSizeWinText(void); // ��������� �������� ���� ������.
void OpenWinText(void); // �������� ���� ������.
void ClearWinText(void); // ������� ���� ������.
void SetWinText(char *Text); // ����������� ������ � ����.
BYTE StartPlaySound(void); // ����� �����.
void OnStopSound(void); // �������� ��� ��������� ������������ �����.
void SetTxtBtnPlaySound(void); // ��������� ������ � ������ ��������������� �����.
BYTE DrawCurSound(void); // ����������� ������� ��� ������������ �����.
void OnChCurTime(void); // �������� ��� ��������� ��������� ������� �� �������.
void OnChCurTimeGraphSig(void); // �������� ��� ��������� ��������� ������� �� ������� � ���� ������� �������.
void OnSetCurTimeDiag(int x,BYTE fl); // ��������� ������� �� ������� � ���� ���������.
void OnSetCurTimeGraphSig(int x); // ��������� ������� �� ������� � ���� ������� �������.
void SetTimeDBF(BYTE fl); // �������� �������� ������� � ���� ������.
void ChMenuProcOutput(void); // ��������� ��������� ������ ���� ��������� ��������� ������ ��������.
BYTE CommandCntrl(WPARAM wParam); // ��������� ������ ���� ����������.
void SetFocusWin(void); // ��������� ������ �����.
void CheckCurPos(void); //�������� �������������� �������.
BYTE LoadFile(char *Path,char *Dir,char *FileName); // �������� �����, ���������� ������� �������.
BYTE SaveFile(char *Path,char *Dir,char *FileName); // ���������� ����� � ������� "WAV".
void ComputeDrawDiag(void); // ������ � ���������� ���������.
void SetBtnMenuProc(void); // ��������� ������ � ������ ��������� � ��������� ������ ����.
void OnDrawDiag(void); // �������� ����� ��������� ���������.
BYTE LoadNNW(BYTE typ); // �������� ��������� �����.
BYTE SaveNNW(BYTE typ); // ���������� ��������� �����.
BYTE SaveAsNNW(BYTE typ); // ���������� ��������� ����� ��� ������ ������.
BYTE CheckSaveNNW(void); // �������� ������������ ����� � ���������� ��� �������������.
void OnSelTypViewSndLineDiag(int id); // �������� ��� ������ ���� ������������ ������ � ����� �������� �� ���������.
void SetTypRecNNW(int id); // ��������� ���� ����� ��� �������������.
void SetMenuTypNNWRec(void); // ��������� ���� ��� ���� ����� ��� �������������.
void OnCloseWin(void); // �������� ��� �������� ����.

public:

HWND hwnd,hDlg,hwndDiag,hwndGraphSig,hwndGraphSpectr,hDlgDB;

char *FileNameWAV; // ��� ��������� ��������� �����.
struct strParSpProc ParSpectr; // ��������� ������������ ���������.
struct strPal PalPos,PalSign; // ��������� ������ ��� ����������� ������ ������������� �������� � ������� �����.

clMain(HWND hwnd_); // �����������.
~clMain(void); // ����������.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ������� ��������� ����.
LRESULT MsgCommandCntrl(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ������� ��������� ���� ����������.
LRESULT MsgCommandDiag(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ������� ���� ������������ ���������.
LRESULT MsgCommandGraphSig(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ������� ���� ������� �������.
LRESULT MsgCommandGraphSpectr(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // ��������� ������� ���� ������� �������.
BYTE SaveBufSound(DWORD szBuf,void *pBuf); // ���������� ��� ������ �����.
BYTE LoadProcFile(char *Path,char *Dir,char *FileName); // �������� �����, ���������� ���������, ���������� ������� �������.
void OnCloseDlgDBS_NNW(void); // �������� ��� �������� ����������� ���� ���� ������ � ���������� ����.
void UpdateWinDiag(void); // ����������� ���� ���������.
BYTE SetTimeDiag(float Time); // ��������� ������������� ��������� �� �������� �����.
void DrawNet(void); // ����������� ����������� ����.
void ChBtnMenuWinViewNNW(void); // ��������� ��������� ������ � ������ ���� �������� ���� ������������ ��������� ����.
void ChBtnMenuWinText(void); // ��������� ��������� ������ � ������ ���� �������� ���� ������.
BYTE IsCaptSound(); // ��������, ��� �� ������ �����.
BYTE GetNumSndRecogn(strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // ��������� ������ ����� ��� ������������� ������ ����.
void ShowProgr(UINT i,UINT n); // ������ ���������.
};
