typedef struct PzABST_Case_st
{
	int Enable; // X, Dir ���L�蓾�邩
	int PurX;
	int PurDir;

	int SecchiX[2];
	int SecchiY[2];
	int SecchiTakasa[2];
	int SecchiColor[2];

	int Takasa;      // 1 �` MAP_Y_BOUND   �ڒn�����u���b�N�̍������̍���
	int RelateCount; // 2 �`               �ڒn���ɉ��Ȃ��邩�A�ň����ꂼ��Ǘ����� 1 + 1 -> 2
	int RensaCount;  // 0 �`               �A����
	int EraseCount;  // 0 �`               ������u���b�N�� (�ז����܂�)
	int JEraseCount; // 0 �`               ������ז��̐�

	struct
	{
		int RoCount;      // 0 �` PUYO_COLOR_NUM   �I�o����F�̐�
		int RelSecchi[2]; // 0 �`                  �ڒn���̌q����̐�, 0 == �ז��E��, 1 == �Ǘ� (�A���������͓��ĂɂȂ�Ȃ�)

		int TateRelCnt;
		int YokoRelCnt;
	}
	ExtraData;

	double Hyouka;
}
PzABST_Case_t;

typedef struct PzABST_Result_st
{
	int Table[MAP_X_BOUND][MAP_Y_BOUND]; // (-1) �` (PUYO_COLOR_NUM - 1) == (-1: ��, 0 - PUYO_COLOR_NUM: �e�F (0 == �ז�))
	int RakkaColors[2]; // 1 �` (PUYO_COLOR_NUM - 1)
	int PuyoCount; // Jama ����
	int JamaCount;

	PzABST_Case_t CaseTable[MAP_X_BOUND][10]; // [X][Dir]

	int TakasaList[MAP_X_BOUND];
	int TakasaMin;
	int TakasaMax;

	// -- PzGetMaxHyouka() Results --
	int PurX;
	int PurDir;
	// ----
}
PzABST_Result_t;

extern PzABST_Result_t PzABST_Result;

void PzAbstracter(int mapIndex);
void PzAllHyouka(double (*funcHyouka)(PzABST_Case_t *));
void PzGetMaxHyouka(void);
