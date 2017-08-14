#include "StdInc.h"

#define CHARANAME_LKAKKO "�y"
#define CHARANAME_RKAKKO "�z"

void ScLoadScenario(char *file)
{
	int fp = DFOpen(file);
	int lineCnt = 0;

	ScAction_t *a = NULL;
	Scdc->Scenario.ActCnt = 0;

	for(; ; )
	{
		char *line = DFReadLine(fp);
		lineCnt++;

		ExtraErrorInfo.ScenarioLineCnt = lineCnt;

		if(line[0] == ';') // �R�����g
		{
			continue;
		}
		if(line[0] == '\0') // ? ��s x1 -> �u���b�N�I��
		{
			if(a == NULL) // ? ��s x2 -> �V�i���I�I��
			{
				break;
			}
			a = NULL;
			continue;
		}

		if(!a)
		{
			errorCase(SC_ACT_MAX <= Scdc->Scenario.ActCnt);
			a = Scdc->Scenario.ActLst + Scdc->Scenario.ActCnt;
			Scdc->Scenario.ActCnt++;

			// Init a
			a->CmdCnt = 0;
			a->CharaName = strx("");
			a->Message = strx("");
		}

		if(line[0] == '@') // �R�}���h
		{
			errorCase(SC_CMD_MAX <= a->CmdCnt);
			ScCommand_t *c = a->CmdLst + a->CmdCnt;
			a->CmdCnt++;

			// Init c
			c->Command = NULL;
			c->PosNo = -1;
			c->Extra = NULL;

			char *cmd = line + 1;
			char *pn = strchr(cmd, ' ');

			if(pn) pn++[0] = '\0';
			else   pn = "no-pos-no";

			char *xtr = strchr(pn, ' ');

			if(xtr) xtr++[0] = '\0';
			else    xtr = "no-extra-data";

			int cmdno = -1;

			     if(!strcmp(cmd, "BG"))   cmdno = SC_CMD_DISP_WALL;
			else if(!strcmp(cmd, "DISP")) cmdno = SC_CMD_DISP_CHARA;
			else if(!strcmp(cmd, "EFFE")) cmdno = SC_CMD_EFFECT_CHARA;
			else if(!strcmp(cmd, "BGM"))  cmdno = SC_CMD_PLAY_BGM;
			else if(!strcmp(cmd, "SE"))   cmdno = SC_CMD_PLAY_SE;
			else if(!strcmp(cmd, "--"))   cmdno = SC_CMD_INTERVAL;
			else if(!strcmp(cmd, "++"))   cmdno = SC_CMD_WHITEOUT;
			else if(!strcmp(cmd, "RS"))   cmdno = SC_CMD_ROUTE_SENTAKU;
			else                          error();

			switch(cmdno)
			{
			case SC_CMD_DISP_WALL:
			case SC_CMD_PLAY_BGM:
			case SC_CMD_PLAY_SE:
				{
					xtr = pn;
					pn = "";
				}
				break;
			}
			int pno = *pn == '\0' ? 0 : atoi(pn);
			pno--;

			errorCase(cmd[0] == '\0');
			errorCase(pno < -1 || 3 < pno);
			errorCase(xtr[0] == '\0');

			c->LCommand = strx(cmd);
			c->Command = cmdno;
			c->PosNo = pno;
			c->Extra = strx(xtr);
		}
		else
		if( line[0] == CHARANAME_LKAKKO[0] &&
			line[1] == CHARANAME_LKAKKO[1] ) // �y�L�������z
		{
			errorCase(strlen(line) < 4);

			char *rk = line + strlen(line) - 2;
			errorCase(
				rk[0] != CHARANAME_RKAKKO[0] ||
				rk[1] != CHARANAME_RKAKKO[1]
				);

			*rk = '\0';
			memFree(a->CharaName);
			a->CharaName = strx(line + 2);
		}
		else // ���b�Z�[�W
		{
			if(a->Message[0] != '\0')
			{
				a->Message = addChar(a->Message, '\n');
			}
			a->Message = addLine(a->Message, line);
//			a->Message = addChar(a->Message, '\n');
		}
	}
	DFClose(fp);

	errorCase(Scdc->Scenario.ActCnt < 1); // �K����̓A�N�V���������邱�ƁB

	ExtraErrorInfo.ScenarioLineCnt = 0;
}
void ScUnloadScenario(void)
{
	for(int aidx = 0; aidx < Scdc->Scenario.ActCnt; aidx++)
	{
		ScAction_t *a = Scdc->Scenario.ActLst + aidx;

		for(int cidx = 0; cidx < a->CmdCnt; cidx++)
		{
			ScCommand_t *c = a->CmdLst + cidx;

			memFree(c->LCommand);
			memFree(c->Extra);
		}
		memFree(a->CharaName);
		memFree(a->Message);
	}
	Scdc->Scenario.ActCnt = 0; // 2bs
}
