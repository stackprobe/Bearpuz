#include "StdInc.h"

ExtraErrorInfo_t ExtraErrorInfo;

void termination(int errorLevel)
{
	SaveSettings();

	DxLib_End();
	ProcMutexUnlock();
	exit(errorLevel);
}
void error2(char *source, int lineno, char *function)
{
	static int callcnt;

	if(callcnt)
	{
		exit(2);
	}
	callcnt++;

//	ClearDrawScreen();
	DrawBox( 0, 0, 800, 600, GetColor(32, 0, 64), 1);

	printfDx("\n");
	printfDx("�@�v���I�ȃG���[�������������߁A�����𒆒f���܂����B\n");
	printfDx("�@�G�X�P�[�v�L�[�������ăA�v���P�[�V�������I�����ĉ������B\n");
	printfDx("\n");
	printfDx("�@�ꏊ: %s (%d) %s\n", source, lineno, function);
	printfDx("�@���: %d, %d\n"
		,ExtraErrorInfo.ScenarioLineCnt
		,ExtraErrorInfo.RetVal
		);
//	printfDx("\n");
//	printfDx("�@�ꏊ�Ə��́A�G���[�̌�������肵����d�v�ȏ��ł��B\n");
//	printfDx("�@�G���[�������̏󋵂ƕ����Ă��A������������ƍK���ł��B\n");
	printfDx("\n");

//	SwapFrame(); // FrameTask�Ƃ��������Ⴄ�̂ŁA�A
	ScreenFlip();

	for(; ; )
	{
		if(CheckHitKey(KEY_INPUT_ESCAPE) || ProcessMessage() == -1)
		{
			termination(0);
		}
	}
	termination(1);
}

void *memAlloc(int size)
{
	void *block = malloc(size);

	errorCase(block == NULL);
	return block;
}
void *memCalloc(int size)
{
	void *block = memAlloc(size);

	memset(block, 0x00, size);
	return block;
}
void memFree(void *block)
{
	free(block);
}

char *xcout(char *format, ...)
{
	char *buffer;
	int size;
	va_list marker;

	va_start(marker, format);

	for(size = strlen(format) + 128; ; size *= 2)
	{
		int retval;

		buffer = (char *)memAlloc(size + 30);
		retval = _vsnprintf_s(buffer, size + 20, size + 10, format, marker);
		buffer[size + 10] = '\0'; // �����I�ɕ���B

		if(0 <= retval && retval <= size)
		{
			break;
		}
		memFree(buffer);

		if(128000000 < size) // Anti-overflow
		{
			error();
		}
	}
	va_end(marker);

	return buffer;
}
char *strx(char *line)
{
	return xcout("%s", line);
}
char *addLine(char *line, char *lineAdd)
{
	char *retLine = xcout("%s%s", line, lineAdd);

	memFree(line);
	return retLine;
}
char *addChar(char *line, int chrAdd)
{
	char lineAdd[2];

	lineAdd[0] = chrAdd;
	lineAdd[1] = '\0';

	return addLine(line, lineAdd);
}

void Init_Rnd(int seed)
{
	SRand(seed);

	for(int c = 0; c < 1000000; c++) // mt�̃o�[�W�������s���Ȃ̂ŁA�ǂݎ̂�
	{
		Get_Rnd(BORDER_OF_NUMERIC);
	}
}
int Get_Rnd(int maxval)
{
	errorCase(maxval < 0 || BORDER_OF_NUMERIC < maxval);
	return GetRand(maxval);
}
double krnd(void)
{
	double r = (double)Get_Rnd(BORDER_OF_NUMERIC - 1) * (1.0 / BORDER_OF_NUMERIC);

	errorCase(r < 0.0 || 1.0 <= r);
	return r;
}
double rnd(void)
{
	double r = (double)Get_Rnd(BORDER_OF_NUMERIC) * (1.0 / BORDER_OF_NUMERIC);

	errorCase(r < 0.0 || 1.0 < r);
	return r;
}
double rndpm(void)
{
	return rnd() * 2.0 - 1.0;
}
int rndbnd(int minval, int maxval)
{
	return minval + Get_Rnd(maxval - minval);
}
int rndp1m1(void)
{
	return rnd() < 0.5 ? -1 : 1;
}

int DFOpen(char *file)
{
	int fp = FileRead_open(file);

if(!fp) printfDx("%s\n", file);

	errorCase(!fp);
	return fp;
}
void DFClose(int fp)
{
	if(FileRead_close(fp) == -1)
	{
		error();
	}
}
int DFRead(int fp)
{
	if(FileRead_eof(fp))
	{
		return EOF;
	}
	int chr = FileRead_getc(fp);

	errorCase(chr == -1);
	return chr;
}

#define DF_LINE_LENMAX 1024

char *DFReadLine(int fp)
{
	static char line[DF_LINE_LENMAX + 1];
	int index;

	for(index = 0; index < DF_LINE_LENMAX; index++)
	{
		int chr = DFRead(fp);

		if(chr == EOF)
		{
			break;
		}
		if(chr == '\r') // CR
		{
			if(DFRead(fp) != '\n') // LF
			{
				error();
			}
			break;
		}
		if(chr == '\n') // LF
		{
			break;
		}
		line[index] = chr;
	}
	line[index] = '\0';

	return line;
}

char *GetJStamp(time_t t)
{
	static char *month_list[] =
	{
		"Jan", "Feb", "Mar", "Apr",
		"May", "Jun", "Jul", "Aug",
		"Sep", "Oct", "Nov", "Dec",
	};
	static char jStamp[128];
	char *stamp = ctime(&t);

	if(!stamp)
		stamp = "Sun Jan 00 00:00:00 0000\n";
	//           0----v----x----v----x--3

	stamp = strx(stamp);

	char *lm = stamp + 4;
	lm[3] = '\0';
	int m = -1;
	int mi;
	for(mi = 0; mi < 12; mi++)
	{
		if(!strcmp(lm, month_list[mi]))
		{
			m = mi + 1;
			break;
		}
	}
	if(mi == 12)
	{
		error();
	}
	char *ltmp;

	jStamp[0] = '\0';

	stamp[24] = '\0';
	strcat(jStamp, stamp + 20);
	strcat(jStamp, "/");
	strcat(jStamp, ltmp = xcout("%02d", m)); memFree(ltmp);
	strcat(jStamp, "/");
	stamp[19] = '\0';
	strcat(jStamp, stamp + 8);

	memFree(stamp);
	return jStamp;
}
void noop(void)
{
	// noop
}

char *ZenInt(int value)
{
	static char lBuff[23];
	char *line = xcout("%d", value);
	char *p;

	lBuff[0] = '\0';

	for(p = line; *p; p++)
	{
		if(*p == '-')
		{
			strcat(lBuff, "�|");
		}
		else
		{
			errorCase(*p < '0' || '9' < *p);

			strcat(lBuff, "�O");
			strchr(lBuff, '\0')[-1] += *p - '0';
		}
	}
	memFree(line);

	return lBuff;
}

void line2domain(char *line)
{
	char *p;

	for(p = line; *p; p++)
	{
		int chr = *p;

		if(
			('0' <= chr && chr <= '9') ||
			('A' <= chr && chr <= 'Z') ||
			('a' <= chr && chr <= 'z') ||
			chr == '.'
			)
		{}
		else
		{
			*p = '-';
//			*p = '?'; // printfDx() �� "?" ��\���o���Ȃ����ۂ��B
		}
	}
}
void line2domain_len(char *line, int lenmax)
{
	line[lenmax] = '\0';
	line2domain(line);
}

#define STRFILE_LOG "C:\\etc\\tmp\\Hetapuz.log"

void LogWrite(char *line, int value)
{
	FILE *fp = fopen(STRFILE_LOG, "at");

	if(fp)
	{
		fprintf(fp, "%s: %d\n", line, value);
		fclose(fp);
	}
}
char *GetClipLine(void)
{
	HANDLE h;
	char *line = NULL;

	OpenClipboard(NULL);

	h = GetClipboardData(CF_TEXT);
	if(h)
	{
		line = (char *)GlobalLock(h);
		if(line)
		{
			line = strx(line);
			GlobalUnlock(h);
		}
	}
	CloseClipboard();

	return line;
}

#define MYLINE_MAX 40

static char *MyText[MYLINE_MAX];

void MyCls(void)
{
	clsDx(); // 2bs?

	for(int c = 0; c < MYLINE_MAX; c++)
	{
		memFree(MyText[c]);
		MyText[c] = NULL;
	}

	// font
	{
		SetFontSize(16);
		SetFontThickness(5);
		ChangeFont("�l�r �S�V�b�N");
		ChangeFontType(DX_FONTTYPE_NORMAL);
	}
}
void MyPrint(char *line)
{
	for(int c = 0; c < MYLINE_MAX; c++)
	{
		if(!MyText[c])
		{
			MyText[c] = strx(line);
			break;
		}
	}
}
void MyPrint_x(char *line)
{
	MyPrint(line);
	memFree(line);
}
void ExecMyPrint(void)
{
	for(int c = 0; c < MYLINE_MAX; c++)
	{
		if(MyText[c])
		{
			DrawString(0, c * 16, MyText[c], GetColor(255, 255, 255));
		}
	}
}
