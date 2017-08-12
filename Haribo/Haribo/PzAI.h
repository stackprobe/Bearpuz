typedef struct PzAI_st
{
	// -- Params --
	int RndMovRotMax; // 0�` == RndMovRotMax < i.MovRotCount ����ڕW�ʒu��ڎw���B
	int MovRotMax;    // 0�` == MovRotMax < i.MovRotCount ����ڕW�ʒu����߂�B
	int MovRotSleep;  // 0�` == �Ō�̈ړ��E��]���牽�����Ȃ��ł���t���[����

	double MovRotPct;  // 0.0�`1.0
	double HiSpeedPct; // 0.0�`1.0

	// [�ʏ펞, �ł��Ԃ���]
	double HissPct[2];       // 0.0�`1.0
	double HissJouSenyuu[2]; // 0.0�`1.0       == �K�E�����ɕK�v�ȃt�B�[���h��L��
	int HissJouTakasa[2];    // 0�`MAP_Y_BOUND == �K�E�����ɕK�v�ȍő�̍���

	/*
		�����ʒu����̂��߂Ɏ��s����B
		���s���O�� PzAbstracter() �����s����B
	*/
	void (*Think)(void);
	// ----

	// -- PzAI_Think() Results --
	int MovDir; // -1�`1 == ������, �ړ��Ȃ�, �E����
	int RotDir; // -1�`1 == �����v, �ړ��Ȃ�, ���v
	int HiSpeed;
	int Hissatsu;
	// ----

	// PzAI_Reset() ���ɏ�����
	struct
	{
		int HiSpeedChuu;
		int MovRotCount;
		int MovRotElaps;

		/*
		struct
		{
			int Inited;
			int MovDir;
			int MovRemain;
		}
		QuickEscape;
		*/

		int Inited;
		int Pinch;

		// -- PzAI.Think() Results --
		int PurX;
		int PurDir;
		// ----
	}
	i;

	// �v�l���[�`���ʗ̈�
	union {
		struct {
			int DangerMode;
		}
		Lv4;
		struct {
			double LastHyouka;
		}
		ClockTower;
	}
	q;
}
PzAI_t;

extern PzAI_t PzAI;

void PzAI_DefThink(void);

void PzAI_Init(void);
void PzAI_Fnlz(void);
void PzAI_Reset(void);
void PzAI_Think(void);

// -- DEBUG --
extern int PzAI_DBG_SpeedLv;
extern char *PzAI_DBG_Think;
/*
extern double PzAI_DBG_hr;
extern int    PzAI_DBG_ht;
extern double PzAI_DBG_hs;
extern double PzAI_DBG_ur;
extern int    PzAI_DBG_ut;
extern double PzAI_DBG_us;
*/
// ----

void PzAI_SetStdParams(int speedLevel, void (*funcThink)(void), double hr, int ht, double hs, double ur, int ut, double us);

// �ȉ��APzAI.Think() �p util

void PzAI_Abstracter(double (*funcHyouka)(PzABST_Case_t *));

int PzAI_IsAnzen(void);
int PzAI_IsDanger(void);
double PzAI_BestOfNext(PzABST_Case_t *i);
double PzAI_WorstOfNext(PzABST_Case_t *i);

extern int PzAI_CaseTable[MAP_X_BOUND][MAP_Y_BOUND];

void PzAI_MakeCaseTable(PzABST_Case_t *i);
void PzAI_LRTurnCaseTable(void);
