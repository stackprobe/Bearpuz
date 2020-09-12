/*
	AI �͉�ʉE���AmapIndex == 1 �Œ�
*/

/*
	PzAI_Init();   �Q�[���J�n���O�Ɏ��s

	�������� PzAI �� Params ��ݒ�

	LOOP 0�`
	{
		PzAI_Reset();   �����J�n���Ɏ��s

		LOOP 0�`
		{
			PzAI_Think();   �t���[�����̑���̂��߂Ɏ��s

			�������� PzAI �� Results ���擾�A���̃t���[���ł̑���ɔ��f
		}
	}
	PzAI_Fnlz();   �Q�[���I������Ɏ��s
*/

#include "StdInc.h"

PzAI_t PzAI;

void PzAI_DefThink(void)
{
	int x;
	int dir;

	for(; ; )
	{
		x = rndbnd(0, MAP_X_BOUND - 1);
		dir = rndbnd(1, 4) * 2;

		if(x == 0 && dir == 4) continue;
		if(x == 5 && dir == 6) continue;

		break;
	}

	PzAI.i.PurX = x;
	PzAI.i.PurDir = dir;
}

void PzAI_Init(void)
{
	memset(&PzAI, 0x00, sizeof(PzAI_t));

	// Params (Default)
	{
		PzAI.RndMovRotMax = 3;
		PzAI.MovRotMax = 10;
		PzAI.MovRotSleep = 30;

		PzAI.MovRotPct = 0.1;
		PzAI.HiSpeedPct = 0.1;

		PzAI.HissPct[0] = 0.01;
		PzAI.HissJouSenyuu[0] = 0.5;
		PzAI.HissJouTakasa[0] = 10;

		PzAI.HissPct[1] = 0.8;
		PzAI.HissJouSenyuu[1] = 0.0;
		PzAI.HissJouTakasa[1] = 3;

		PzAI.Think = PzAI_DefThink;
	}

	PzThink_CT_SleepEndFrm = 0;
}
void PzAI_Fnlz(void)
{
	// noop
}
void PzAI_Reset(void)
{
	memset(&PzAI.i, 0x00, sizeof(PzAI.i));
}
static void SetPurpose(void)
{
	PzAI_t *i = &PzAI;

	PzAbstracter(1);
	i->Think();

	errorCase(i->i.PurX < 0 || MAP_X_BOUND <= i->i.PurX);
	errorCase(
		i->i.PurDir != 2 &&
		i->i.PurDir != 4 &&
		i->i.PurDir != 6 &&
		i->i.PurDir != 8
		);
	errorCase(i->i.PurX == 0 && i->i.PurDir == 4);
	errorCase(i->i.PurX == 5 && i->i.PurDir == 6);
}
void PzAI_Think(void)
{
	PzAI_t *i = &PzAI;
	Map_t *m = Pzdc.MapList + 1; // AI ��
	Map_t *pm = Pzdc.MapList; // �v���C���[��

	// init ret
	i->MovDir = 0;
	i->RotDir = 0;
	i->HiSpeed = 0;
	i->Hissatsu = 0;

	if(m->NeedInitRakka) // �����u���b�N���p�ӂ���Ă��Ȃ� -> ����s��
	{
		return;
	}
	if(i->i.HiSpeedChuu)
	{
		i->HiSpeed = 1;
		return;
	}

	if(!i->i.Inited) // ? ��������
	{
		i->i.Inited = 1;

		i->i.MovRotCount = rndbnd(0, i->RndMovRotMax);
		SetPurpose();

		int hGap = m->HissUsedCount < pm->HissUsedCount ? 1 : 0; // 1 == �ł��Ԃ���, 0 == ���펞

		if(krnd() < i->HissPct[hGap])
		{
			double pjSenyuu = (double)(PzABST_Result.PuyoCount + PzABST_Result.JamaCount) / (MAP_X_BOUND * MAP_Y_BOUND);

			if( i->HissJouSenyuu[hGap] <= pjSenyuu &&
				i->HissJouTakasa[hGap] <= PzABST_Result.TakasaMax)
			{
				i->Hissatsu = 1;
			}
		}

		// ��ֈړ�����?
		if(12 <= PzABST_Result.TakasaMin) // ? ������Ƃ���͑S���ςݏオ�����B-> �������񂾕����ǂ�
		{
			i->i.HiSpeedChuu = 1; // ����
			return;
		}

		if(10 <= PzABST_Result.TakasaList[2]) // ? �s���`
		{
			i->i.Pinch = 1;
		}
	}

	i->i.MovRotElaps++;

	if((m->RakkaX == i->i.PurX && m->RakkaDir == i->i.PurDir) || i->MovRotMax < i->i.MovRotCount)
	{
		goto touchaku;
	}
	if(i->i.Pinch)
	{
		double mrpTmp = m_max(i->MovRotPct, 0.2);

		if(mrpTmp <= krnd())
		{
			return;
		}
	}
	else
	{
		if(i->i.MovRotElaps < i->MovRotSleep)
		{
			return;
		}
		if(i->MovRotPct <= krnd())
		{
			return;
		}
		if(30 < m->SecchiTimer) // �����ڒn����Ƃ���œ����ƌ��ꂵ���B-> ������
		{
			return;
		}
	}

	// ���̎��_�ŁA�ړ��E��]���s�����Ƃ͊m��

	i->i.MovRotElaps = 0;

	if(i->i.MovRotCount < i->RndMovRotMax) // rnd �ړ��E��]
	{
		if(krnd() < 0.5)
		{
			i->MovDir = krnd() < 0.5 ? -1 : 1;
		}
		else
		{
			i->RotDir = krnd() < 0.5 ? -1 : 1;
		}
		goto movRotDone;
	}

	if(krnd() < 0.825 && m->RakkaX != i->i.PurX) // �ړ�
	{
		if(m->RakkaX < i->i.PurX)
		{
			i->MovDir = 1;
		}
		else
		{
			i->MovDir = -1;
		}
	}
	else // ��]
	{
		if(DirRotClock(m->RakkaDir) == i->i.PurDir)
		{
			i->RotDir = 1;
		}
		else if(DirRotHanClock(m->RakkaDir) == i->i.PurDir)
		{
			i->RotDir = -1;
		}
		else
		{
			i->RotDir = krnd() < 0.5 ? -1 : 1;
		}
	}
movRotDone:
	i->i.MovRotCount++;
	return;

touchaku:
	if(krnd() < i->HiSpeedPct)
	{
		i->i.HiSpeedChuu = 1;
	}
	return;
}

// -- DEBUG --
int PzAI_DBG_SpeedLv;
char *PzAI_DBG_Think;
/*
double PzAI_DBG_hr;
int    PzAI_DBG_ht;
double PzAI_DBG_hs;
double PzAI_DBG_ur;
int    PzAI_DBG_ut;
double PzAI_DBG_us;
*/
// ----

void PzAI_SetStdParams(int speedLevel, void (*funcThink)(void), double hr, int ht, double hs, double ur, int ut, double us)
{
	// Set PzAI_DBG_*
	{
		char *think = "�s��";

		if(funcThink == PzThink_Lv1) think = "Lv1";
		if(funcThink == PzThink_Lv2) think = "Lv2";
		if(funcThink == PzThink_Lv3) think = "Lv3";
		if(funcThink == PzThink_Lv4) think = "Lv4";

		PzAI_DBG_SpeedLv = speedLevel;
		PzAI_DBG_Think = think;
		/*
		PzAI_DBG_hr = hr;
		PzAI_DBG_ht = ht;
		PzAI_DBG_hs = hs;
		PzAI_DBG_ur = ur;
		PzAI_DBG_ut = ut;
		PzAI_DBG_us = us;
		*/
	}


	errorCase(!funcThink);

	errorCase(hr < 0.0 || 1.0 < hr);
	errorCase(ht < 0   || MAP_Y_BOUND < ht);
	errorCase(hs < 0.0 || 1.0 < hs);

	errorCase(ur < 0.0 || 1.0 < ur);
	errorCase(ut < 0   || MAP_Y_BOUND < ut);
	errorCase(us < 0.0 || 1.0 < us);

	PzAI_t *i = &PzAI;

	switch(speedLevel)
	{
	case 1: // �̌��ł̎ア���x
		{
			i->RndMovRotMax = 5;
			i->MovRotMax   = 15;
			i->MovRotSleep = 45;

			i->MovRotPct  = 0.12;
			i->HiSpeedPct = 0.01;
		}
		break;

	case 2: // �̌��ł̕��ʒ��x
		{
			i->RndMovRotMax = 4;
			i->MovRotMax   = 15;
			i->MovRotSleep = 35;

			i->MovRotPct  = 0.25;
			i->HiSpeedPct = 0.15;
		}
		break;

	case 3: // �̌��ł̋������኱�ア(�x��)���x
		{
			i->RndMovRotMax = 3;
			i->MovRotMax   = 20;
			i->MovRotSleep = 25;

			i->MovRotPct  = 0.5;
			i->HiSpeedPct = 0.4;
		}
		break;

	case 4: // �̌��ł̋������x
		{
			i->RndMovRotMax = 2;
			i->MovRotMax   = 20;
			i->MovRotSleep = 15;

			i->MovRotPct  = 0.666;
			i->HiSpeedPct = 0.5;
		}
		break;

	case 5: // �̌��ł̋������኱����(����)���x
		{
			i->RndMovRotMax = 0;
			i->MovRotMax   = 20;
			i->MovRotSleep =  0;

			i->MovRotPct  = 0.9;
			i->HiSpeedPct = 0.9;
		}
		break;

	default:
		error();
	}

	PzAI.Think = funcThink;

	PzAI.HissPct[0] = hr;
	PzAI.HissJouSenyuu[0] = hs;
	PzAI.HissJouTakasa[0] = ht;

	PzAI.HissPct[1] = ur;
	PzAI.HissJouSenyuu[1] = us;
	PzAI.HissJouTakasa[1] = ut;
}

// **************************
// �ȉ��APzAI.Think() �p util
// **************************

void PzAI_Abstracter(double (*funcHyouka)(PzABST_Case_t *))
{
	PzAI_t *i = &PzAI;

//	PzAbstracter(0); // �����Ă�ł�͂��B
	PzAllHyouka(funcHyouka);
	PzGetMaxHyouka();

	i->i.PurX   = PzABST_Result.PurX;
	i->i.PurDir = PzABST_Result.PurDir;
}

int PzAI_IsAnzen(void)
{
	return PzABST_Result.TakasaMax < 4;
}
int PzAI_IsDanger(void)
{
	return 8 < PzABST_Result.TakasaMax;
}
double PzAI_BestOfNext(PzABST_Case_t *i)
{
	double h = rnd();

	if(i->RensaCount == 0)
	{
		// �ǂ����댯
		if(i->SecchiY[0] < 4) h -= 9990000.0;
		if(i->SecchiY[1] < 4) h -= 9990000.0;

		// ���S����댯
		if(i->SecchiY[0] < 2) h -= 9990000.0;
		if(i->SecchiY[1] < 2) h -= 9990000.0;
	}

	h += i->RensaCount  * 10000.0;
	h += i->EraseCount  *   100.0;
	h += i->RelateCount *    10.0;
	h -= i->Takasa      *     1.1;

//	h += i->ExtraData.RoCount * 300.1;
	h += i->ExtraData.RoCount * 30.1;
//	h += i->ExtraData.RoCount * 3.1;

	return h;
}
double PzAI_WorstOfNext(PzABST_Case_t *i)
{
	double h = rnd();

	// �ǂ����댯
	if(i->SecchiY[0] < 4) h -= 9990000.0;
	if(i->SecchiY[1] < 4) h -= 9990000.0;

	// ���S����댯
	if(i->SecchiY[0] < 2) h -= 9990000.0;
	if(i->SecchiY[1] < 2) h -= 9990000.0;

	h -= i->RensaCount  * 10000.0;
	h -= i->RelateCount *   100.0;
	h -= i->Takasa      *     1.1;

	return h;
}

int PzAI_CaseTable[MAP_X_BOUND][MAP_Y_BOUND];

void PzAI_MakeCaseTable(PzABST_Case_t *i)
{
	PzABST_Result_t *resu = &PzABST_Result;

	memcpy(PzAI_CaseTable, resu->Table, MAP_X_BOUND * MAP_Y_BOUND * sizeof(int));

	int x1 = i->SecchiX[0];
	int y1 = i->SecchiY[0];
	int c1 = i->SecchiColor[0];
	int x2 = i->SecchiX[1];
	int y2 = i->SecchiY[1];
	int c2 = i->SecchiColor[1];

	// Check
	{
		for(int x = 0; x < MAP_X_BOUND; x++)
		for(int y = 0; y < MAP_Y_BOUND; y++)
		{
			int color = PzAI_CaseTable[x][y];

			errorCase(color < -1 || PUYO_COLOR_NUM <= color);

			/*
			FILE *fp = fopen("C:\\tmp\\1.txt", "at");
			if(fp) {
				fprintf(fp, "%d\n", color);
				fclose(fp);
			}
			*/
		}

		errorCase(x1 < 0 || MAP_X_BOUND <= x1);
		errorCase(y1 < 0 || MAP_Y_BOUND <= y1);
		errorCase(c1 < 1 || PUYO_COLOR_NUM <= c1);
		errorCase(x2 < 0 || MAP_X_BOUND <= x2);
		errorCase(y2 < 0 || MAP_Y_BOUND <= y2);
		errorCase(c2 < 1 || PUYO_COLOR_NUM <= c2);

		int tmax = resu->TakasaMax;

		errorCase(tmax < 0 || MAP_Y_BOUND < tmax);

		if(tmax <= MAP_Y_BOUND - 2) // ? ���2�i�]�T���� -> ����ɐڒn�ł���͂��B
		{
			errorCase(x1 == x2 && y1 == y2);

			errorCase(PzAI_CaseTable[x1][y1] != -1);
			errorCase(PzAI_CaseTable[x2][y2] != -1);
		}
	}

	PzAI_CaseTable[x1][y1] = c1;
	PzAI_CaseTable[x2][y2] = c2;
}
void PzAI_LRTurnCaseTable(void)
{
	for(int y = 0; y < MAP_Y_BOUND; y++)
	{
		int row[MAP_X_BOUND];

		for(int x = 0; x < MAP_X_BOUND; x++)
		{
			row[x] = PzAI_CaseTable[x][y];
		}
		for(int x = 0; x < MAP_X_BOUND; x++)
		{
			PzAI_CaseTable[x][y] = row[MAP_X_BOUND - 1 - x];
		}
	}
}
