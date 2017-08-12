#include "StdInc.h"

__int64 PzThink_CT_SleepEndFrm;

static void RequestColor(int color1, int color2)
{
	if(color2 == -1) color2 = rndbnd(1, PUYO_COLOR_NUM - 1);

	errorCase(color1 < 1 || PUYO_COLOR_NUM <= color1);
	errorCase(color2 < 1 || PUYO_COLOR_NUM <= color2);

	Map_t *m   = Pzdc.MapList + 1;
	Map_t *mos = Pzdc.MapList + 0;

	if(m->ColorStreamIndex < mos->ColorStreamIndex) // ? ����̕�����s���Ă���B-> �V�[�P���X���A���炩�Ɉ���Ă��܂��B
	{
		return;
	}
	if(COLOR_STREAM_LEN - 2 < m->ColorStreamIndex) // ? �������ރX�y�[�X�s��
	{
		return;
	}
	if(Pzdc.TokushuButtle.ColorMax != 0) // ? ���F���[�h
	{
		return;
	}

	// �A���h�~
	{
		if(Pzdc.FrameCnt < PzThink_CT_SleepEndFrm)
		{
			return;
		}
		PzThink_CT_SleepEndFrm = Pzdc.FrameCnt + 60 * 2;
	}

	if(krnd() < 0.5)
	{
		int swap = color1;

		color1 = color2;
		color2 = swap;
	}
	Pzdc.ColorStream[m->ColorStreamIndex + 0] = color1;
	Pzdc.ColorStream[m->ColorStreamIndex + 1] = color2;
}

static double CT_CheckJoudanTsumiJoutai(PzABST_Case_t *i) // ret : < 0.0 == �A���s��
{
	double h = 0.0;
	int reach = 0;

	for(int x = 1; x < MAP_X_BOUND - 1; x++)
	{
		int uc = PzAI_CaseTable[x - 1][13];
		int cs[3];

		cs[0] = PzAI_CaseTable[x][10];
		cs[1] = PzAI_CaseTable[x][ 9];
		cs[2] = PzAI_CaseTable[x][ 8];

		if(uc == -1) // ? ���������
		{
			if(cs[0] == 0 && cs[1] == 0 && cs[2] == 0) return -1.0; // �E�オ�S�����ז��Ŗ��܂��Ă���B
		}
		else // ? �����A�ς�ł���B
		{
			if(uc == cs[0] || uc == cs[1] || uc == cs[2]) // ? �����Ɠ����F������B
			{
				h += 100.0;
				reach++;
			}
			else if(cs[2] != -1) // ? �����ƈႤ�F�Ŗ��܂��Ă���B
			{
				return -1.0;
			}
			else if(cs[1] != -1) // ? �����ƈႤ�F�Ŗ��܂肻���B
			{
				RequestColor(uc, -1);
			}
		}
	}
	int jr = reach == MAP_X_BOUND - 2; // ? �ナ�[�`
	int ur;

	{
		int x;

		for(x = 0; x < MAP_X_BOUND; x++)
		{
			if(PzAI_CaseTable[x][11] == -1) // ? ���
			{
				break;
			}
		}
		ur = x == MAP_X_BOUND; // ? �����[�`
	}

	{
		int cs[2];
		int ks[2];

		cs[0] = PzAI_CaseTable[MAP_X_BOUND - 1][10];
		cs[1] = PzAI_CaseTable[MAP_X_BOUND - 1][ 9];

		ks[0] = PzAI_CaseTable[MAP_X_BOUND - 1][11];
		ks[1] = PzAI_CaseTable[MAP_X_BOUND - 2][11];

		if(jr && ur) // ? ���[�`
		{
			h += 0.01; // ���[�`�t���O�I��

			if(cs[0] == ks[0] && cs[1] == ks[1]) // ? �N��
			{
				return 990000.0;
			}
			if(cs[0] == -1) // ? �N���҂�
			{
				RequestColor(ks[0], ks[1]);
			}
		}
		if(cs[0] != -1) // ? �N�������܂��Ă���B
		{
			return -1.0;
		}
	}
	if(1 <= i->RensaCount) // ? ����������Ă�B
	{
		return -1.0;
	}
	return h;
}
static double CT_CheckTsumiJoutai(PzABST_Case_t *i) // ret : < 0.0 == �A���s��
{
	double h = 0.0;
	double jh;
	double kh;
	double mh;

	PzAI_MakeCaseTable(i);

	for(int x = 0; x < MAP_X_BOUND; x++)
	{
		int cs[3];

		cs[0] = PzAI_CaseTable[x][13];
		cs[1] = PzAI_CaseTable[x][12];
		cs[2] = PzAI_CaseTable[x][11];

		if(cs[0] == 0) return -1.0; // ���ז�
		if(cs[1] == 0) return -1.0; // ���ז�
		if(cs[2] == 0) return -1.0; // ���ז�

		if(cs[0] != -1) // 1�i�ڂ͐ς�ł���B
		{
			if(cs[1] != -1 && cs[0] != cs[1]) return -1.0; // 2�i�ڂɈႤ�F��ς�ł���B
			if(cs[2] != -1 && cs[0] != cs[2]) return -1.0; // 3�i�ڂɈႤ�F��ς�ł���B
		}

		if(cs[0] != -1) h += 300.0;
		if(cs[1] != -1) h += 600.1;
		if(cs[2] != -1) h += 900.3;
	}
	for(int x = 0; x < MAP_X_BOUND - 1; x++)
	{
		int cs[2];

		cs[0] = PzAI_CaseTable[x + 0][13];
		cs[1] = PzAI_CaseTable[x + 1][13];

		if(cs[0] != -1 && cs[1] != -1) // ? �����ς�ł���B
		{
			if(cs[0] == cs[1]) // ? �ד��m�����F��ς�ł���B
			{
				return -1.0;
			}
		}
	}
	// ���̎x��
	{
		for(int x = 0; x < MAP_X_BOUND - 1; x++)
		{
			int cn[2];
			int cp[2];

			cn[0] = PzAI_CaseTable[x + 0][13];
			cn[1] = PzAI_CaseTable[x + 1][13];
			cp[0] = PzAI_CaseTable[x + 0][12];
			cp[1] = PzAI_CaseTable[x + 1][12];

			if(cn[0] != -1 && cn[1] != -1 && cp[0] == -1 && cp[1] == -1 && krnd() < 0.05)
			{
				RequestColor(cn[0], cn[1]);
			}
		}
		for(int x = 0; x < MAP_X_BOUND; x++)
		{
			int cs[3];
			int ss[2];

			cs[0] = PzAI_CaseTable[x][13];
			cs[1] = PzAI_CaseTable[x][12];
			cs[2] = PzAI_CaseTable[x][11];
			ss[0] = 1;
			ss[1] = 1;

			if(0 < x)               ss[0] = PzAI_CaseTable[x - 1][11];
			if(x < MAP_X_BOUND - 1) ss[1] = PzAI_CaseTable[x + 1][11];

			if(ss[0] != -1 && ss[1] != -1 && cs[0] != -1 && cs[2] == -1 && krnd() < 0.05) // �J
			{
				if(cs[1] == -1)
				{
					RequestColor(cs[0], cs[0]);
				}
				else
				{
					RequestColor(cs[0], -1);
				}
			}
		}
	}
	jh = CT_CheckJoudanTsumiJoutai(i);

	PzAI_LRTurnCaseTable();

	kh = CT_CheckJoudanTsumiJoutai(i);
	mh = m_max(jh, kh);

	if(mh < 0.0)
	{
		return -1.0;
	}
	return h + mh;
}
static double CT_Hyouka;

static double ClockTower(PzABST_Case_t *i)
{
	double h = CT_CheckTsumiJoutai(i);

	CT_Hyouka = m_max(CT_Hyouka, h);

	if(h < 0.0) // ? �A���s��
	{
		h = PzThink_Lv4_Hyouka(i);
	}
	else
	{
		h += 990000.0 + PzThink_Lv4_Hyouka(i);
	}
	return h;
}
void PzThink_ClockTower(void)
{
	CT_Hyouka = -2.0;
	PzAI_Abstracter(ClockTower);
	PzAI.q.ClockTower.LastHyouka = CT_Hyouka;
}
