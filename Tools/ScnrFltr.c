/*
	ScnrFltr.exe /d <dir>   -- dir�����`�F�b�N
	ScnrFltr.exe /d         -- �h���b�v����dir�����`�F�b�N
	ScnrFltr.exe            -- �h���b�v�����t�@�C�����`�F�b�N
*/

#include "C:\Factory\Common\all.h"

#define CHARANAME_LKAKKO "�y"
#define CHARANAME_RKAKKO "�z"

#define STRFILE_GRAPH_FILES "..\\Resource\\�V�i���I_�摜.txt"
#define STRFILE_SOUND_FILES "..\\Resource\\�V�i���I_��.txt"

#define STRFILE_RESULT "C:\\tmp\\����.txt"

static int IsZenLine(char *line)
{
	char *p;

	if(strlen(line) % 2 != 0)
	{
		return 0;
	}
	for(p = line; *p; p += 2)
	{
		if(!_ismbblead(p[0]) || !_ismbbtrail(p[1]))
		{
			return 0;
		}
	}
	return 1;
}

static int IsExistResource(char *name, char *listFile, char *ext)
{
	autoList_t *lines;
	char *line;
	uint index;
	int retval;

	if(!*name) return 0;
//	if(!IsZenLine(name)) return 0;

	lines = readLines(listFile);

	name = addExt(strx(name), ext);
	retval = findJLineICase(lines, name) < getCount(lines);
	memFree(name);

	releaseDim(lines, 1);
	return retval;
}
static int IsExistGraph(char *name)
{
	return IsExistResource(name, STRFILE_GRAPH_FILES, "png");
}
static int IsExistSound(char *name)
{
	return IsExistResource(name, STRFILE_SOUND_FILES, "mp3");
}

typedef struct Line_st
{
	uint Row;
	char *Line;
}
Line_t;
static Line_t *Lines;
static uint LineCount;

static FILE *OutFp;
static void Warning(uint row, char *message)
{
	fprintf(OutFp, "�x��(�s�ԍ�: %u): %s\n", row, message);
}
static void ScnrFltrEx(char *scnrFile)
{
	autoList_t *lines = readLines(scnrFile);
	char *line;
	uint index;
	Line_t *i;

	errorCase(!OutFp);
	fprintf(OutFp, "�V�i���I \"%s\" �`�F�b�N����\n", scnrFile);

	LineCount = getCount(lines);
	Lines = (Line_t *)memAlloc(LineCount * sizeof(Line_t));

	foreach(lines, line, index)
	{
		i = Lines + index;
		i->Row = index + 1;
		i->Line = line;
	}
	releaseAutoList(lines);

restart:
	for(index = 0; index < LineCount; index++) // �R�����g�����O
	{
		i = Lines + index;
		if(i->Line[0] == ';')
		{
			LineCount--;
			copyBlock(i, Lines + index + 1, (LineCount - index) * sizeof(Line_t)); // g
			goto restart;
		}
	}
	for(index = 0; index < LineCount; index++)
	{
		i = Lines + index;
		line = i->Line;

		if(line[0] == '@') // ? ����
		{
			autoList_t *tokens = tokenize(line, ' ');

			if(getCount(tokens) == 1)
			{
				char *cmd = refLine(tokens, 0);

				     if(!strcmp(cmd, "@--")) {} // �t�F�[�h�A�E�g����
				else if(!strcmp(cmd, "@++")) {} // �z���C�g�A�E�g����
				else if(!strcmp(cmd, "@RS")) {} // ���[�g�I��
				else
				{
					Warning(i->Row, "�F���ł��Ȃ����߂ł��B������Ɍ��͂���܂��񂩁A�󔒂����Y��Ă��܂��񂩁B(tkn=1)");
				}
			}
			else if(getCount(tokens) == 2)
			{
				char *cmd = refLine(tokens, 0);
				char *option = refLine(tokens, 1);

				if(!strcmp(cmd, "@BG")) // �w�i�ύX
				{
					if(!IsExistGraph(option) && _stricmp(option, "off"))
					{
						Warning(i->Row, "�摜��������܂���B�摜�̖��O���m�F���ĉ������A�摜���X�g���ŐV�ł��邩�m�F���ĉ������B");
					}
				}
				else if(!strcmp(cmd, "@BGM")) // �ȕύX
				{
					if(!IsExistSound(option) && _stricmp(option, "off"))
					{
						Warning(i->Row, "�T�E���h��������܂���B�T�E���h�̖��O���m�F���ĉ������A�T�E���h���X�g���ŐV�ł��邩�m�F���ĉ������B");
					}
				}
				else if(!strcmp(cmd, "@SE")) // ���ʉ�
				{
					if(!IsExistSound(option))
					{
						Warning(i->Row, "���ʉ���������܂���B���ʉ��̖��O���m�F���ĉ������A���ʉ����X�g���ŐV�ł��邩�m�F���ĉ������B");
					}
				}
				else
				{
					Warning(i->Row, "�F���ł��Ȃ����߂ł��B������Ɍ��͂���܂��񂩁A�󔒂����Y��Ă��܂��񂩁B(tkn=2)");
				}
			}
			else if(getCount(tokens) == 3)
			{
				char *cmd = refLine(tokens, 0);
				char *option1 = refLine(tokens, 1);
				char *option2 = refLine(tokens, 2);

				     if(!strcmp(option1, "1")) {}
				else if(!strcmp(option1, "2")) {}
				else if(!strcmp(option1, "3")) {}
				else if(!strcmp(option1, "4")) {}
				else                           Warning(i->Row, "�����ʒu�̔ԍ����s���ł��B(1�`4)");

				if(!strcmp(cmd, "@DISP")) // �L�����\��
				{
					if(!IsExistGraph(option2) && _stricmp(option2, "off"))
					{
						Warning(i->Row, "�摜��������܂���B�摜�̖��O���m�F���ĉ������A�摜���X�g���ŐV�ł��邩�m�F���ĉ������B");
					}
				}
				else if(!strcmp(cmd, "@EFFE")) // �L�����G�t�F�N�g
				{
					if(!strcmp(option2, "�h���")) {}
					else
					{
						Warning(i->Row, "�F���ł��Ȃ��G�t�F�N�g�ł��B������Ɍ��͂���܂��񂩁B");
					}
				}
				else
				{
					Warning(i->Row, "�F���ł��Ȃ����߂ł��B������Ɍ��͂���܂��񂩁A�󔒂����Y��Ă��܂��񂩁B(tkn=3)");
				}
			}
			else
			{
				Warning(i->Row, "���߂̒P�ꐔ���������邩���Ȃ����܂��B�s�p�ȋ󔒂͂���܂��񂩁B");
			}
			releaseDim(tokens, 1);
		}
		// ? �L������
		else if(
			line[0] == CHARANAME_LKAKKO[0] &&
			line[1] == CHARANAME_LKAKKO[1]
			)
		{
			uint len = strlen(line);

			if(!IsZenLine(line))
			{
				Warning(i->Row, "�L�������ɕs���ȕ���������܂��B���p�Ƃ����߂�B");
			}
			else if(
				line[len - 2] != CHARANAME_RKAKKO[0] ||
				line[len - 1] != CHARANAME_RKAKKO[1]
				)
			{
				Warning(i->Row, "�L�������������Ă��܂���B�y�z������");
			}
		}
		else if(line[0]) // ? ���b�Z�[�W
		{
			if(!IsZenLine(line))
			{
				Warning(i->Row, "���b�Z�[�W�ɕs���ȕ���������܂��B���p�Ƃ����߂�B");
			}
		}
		else // ? ��s
		{}
	}
	if(LineCount == 0)
	{
		Warning(0, "���̃V�i���I�t�@�C���͋󂩁A�R�����g��������܂���B��̃V�i���I�͏����ł��܂���B");
	}
	else // ��ł͂Ȃ��A�A�A
	{
		if(Lines[0].Line[0] == '\0') // ? �ŏ��̗L���ȍs����s
		{
			Warning(0, "�ŏ��̃��b�Z�[�W�▽�߂̑O�ɋ�s������܂��B�����Ɛ����������ł��܂���B");
		}
	}
	for(index = 1; index < LineCount; index++)
	{
		Line_t *i1 = Lines + index - 1;
		Line_t *i2 = Lines + index - 0;

		if(i1->Line[0] == '\0' && i2->Line[0] == '\0')
		{
			Warning(i2->Row, "�A�������s������܂��B�V�i���I�̏I�[�ƌ��Ȃ����ꍇ������܂��B");
		}
	}

	for(index = 0; index < LineCount; index++)
	{
		i = Lines + index;
		if(i->Line[0])
		{
			goto foundEntity;
		}
	}
	Warning(0, "�L���ȃ��b�Z�[�W�▽�߂��������܂���B�V�i���I�͏��Ȃ��Ƃ���̓��b�Z�[�W�▽�߂��Ȃ���΂Ȃ�܂���B");
foundEntity:

	1; // Lines: g!
}
static void ScnrFltr(char *scnrFile)
{
	OutFp = fileOpen(STRFILE_RESULT, "wt");

	ScnrFltrEx(scnrFile);

	fileClose(OutFp);
	OutFp = NULL;
	execute_x(xcout("START %s", STRFILE_RESULT)); // NB
}
int main(int argc, char **argv)
{
	if(argIs("/D")) // Dir mode
	{
		autoList_t *files;
		char *file;
		uint index;

		cout("DIR mode\n");
		files = lsFiles(hasArgs(1) ? nextArg() : dropDir());

		OutFp = fileOpen(STRFILE_RESULT, "wt");

		foreach(files, file, index)
		{
			cout("%s\n", file);
			ScnrFltrEx(file);
		}
		fileClose(OutFp);
		OutFp = NULL;
		execute_x(xcout("START %s", STRFILE_RESULT)); // NB

		return;
	}

	for(; ; )
	{
		ScnrFltr(dropFile());
	}
}
