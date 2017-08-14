#include "StdInc.h"

char *GC_PicFiles[PIC_MAX]; // NULL == �摜�̊��蓖�ĂȂ�
int GC_PicList[PIC_MAX]; // �����[�h���́ADc->PicDummy �Ƃ���B

void GC_ProcInitReset(void) // �E�B���h�E���[�h�ύX���ɂ�����B
{
	for(int i = 0; i < PIC_MAX; i++)
	{
		GC_PicList[i] = Dc->PicDummy;
	}
}
void GC_ProcInit(void)
{
	int i = 0;

	GC_PicFiles[i++] = NULL;

	GC_PicFiles[i++] = NULL;
	GC_PicFiles[i++] = "�V�i���I\\System\\���b�Z�[�W�E�B���h�E.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\Save.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\Save��.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\Load.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\Load��.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\Auto.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\Auto��.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\Skip.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\Skip��.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\Menu.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\Menu��.png";
	GC_PicFiles[i++] = NULL;

	GC_PicFiles[i++] = NULL;
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�ǂ̃��[�g��.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\���J��.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\���J�ʌ�.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�h�C�c���{.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�h�C�c���{��.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�C�^���A�v���C�Z��.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�C�^���A�v���C�Z����.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�h�C�c�v���C�Z��.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�h�C�c�v���C�Z����.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�C�^���A���{.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�C�^���A���{��.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�h�C�c�C�^���A.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�h�C�c�C�^���A��.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�v���C�Z�����{.png";
	GC_PicFiles[i++] = "�V�i���I\\�I����\\�v���C�Z�����{��.png";
	GC_PicFiles[i++] = NULL;

	GC_PicFiles[i++] = NULL;
	GC_PicFiles[i++] = "�V�i���I\\System\\�Z�[�u���.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\���[�h���.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\�߂�.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\�߂��.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\SaveLoad\\�Z�[�u���܂����H.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\SaveLoad\\���[�h���܂����H.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\SaveLoad\\����.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\SaveLoad\\�����.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\SaveLoad\\���Ȃ�.png";
	GC_PicFiles[i++] = "�V�i���I\\System\\SaveLoad\\���Ȃ���.png";
	GC_PicFiles[i++] = NULL;

	GC_PicFiles[i++] = NULL;
	GC_PicFiles[i++] = "Puzzle\\�K�E\\�K�E��.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\�K�E�E.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\�ᑬ��.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\�ᑬ�E.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\������.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\�����E.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\���B��.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\�I�B��.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\���B��.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\�Ɠ��B��.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\�p���B��.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\�ĉp�B��.png";
	GC_PicFiles[i++] = "Puzzle\\�K�E\\�I���B��.png";
	GC_PicFiles[i++] = NULL;

	GC_PicFiles[i++] = NULL;

	errorCase(i != PIC_MAX);

	GC_ProcInitReset();
	GC_NmBgmLoadAll();
}
void GC_ProcFnlz(void)
{
	// noop
}

void GC_Load(int index)
{
	errorCase(index < 0 || PIC_MAX <= index);

	if(GC_PicList[index] == Dc->PicDummy && GC_PicFiles[index] != NULL)
	{
		GC_PicList[index] = LoadPicture(ResourcePath(GC_PicFiles[index]));
	}
}
void GC_Unload(int index)
{
	errorCase(index < 0 || PIC_MAX <= index);

	if(GC_PicList[index] != Dc->PicDummy)
	{
		UnloadPicture(GC_PicList[index]);
		GC_PicList[index] = Dc->PicDummy;
	}
}
void GC_LoadRange(int minidx, int maxidx)
{
	for(int index = minidx; index <= maxidx; index++)
	{
		GC_Load(index);
	}
}
void GC_UnloadRange(int minidx, int maxidx)
{
	for(int index = minidx; index <= maxidx; index++)
	{
		GC_Unload(index);
	}
}
void GC_UnloadAll(void)
{
	GC_UnloadRange(PIC_Start, PIC_End);
}

int GC_Pic(int index)
{
	errorCase(index < 0 || PIC_MAX <= index);
	return GC_PicList[index];
}
int GC_LPic(int index)
{
	GC_Load(index);
	return GC_Pic(index);
}

static char *NmPicResrc(char *name)
{
	char *relFile = xcout("�V�i���I\\�摜\\%s.png", name);
	char *file;

	file = ResourcePath(relFile);
	memFree(relFile);
	return file;
}
static char *NmBgmResrc(char *name)
{
	char *relFile = xcout("�V�i���I\\��\\%s.mp3", name);
	char *file;

	file = ResourcePath(relFile);
	memFree(relFile);
	return file;
}

char *GC_NmPicNames[GC_NMPIC_MAX];
char *GC_NmPicFiles[GC_NMPIC_MAX];
int GC_NmPicList[GC_NMPIC_MAX];
int GC_NmPicIndex;

void GC_NmPicLoad(char *name)
{
	name = strx(name);
	char *file = strx(NmPicResrc(name));
	int pic = LoadPicture(file);

	errorCase(GC_NMPIC_MAX <= GC_NmPicIndex);

	GC_NmPicNames[GC_NmPicIndex] = name;
	GC_NmPicFiles[GC_NmPicIndex] = file;
	GC_NmPicList[GC_NmPicIndex] = pic;
	GC_NmPicIndex++;
}
int GC_IsNmPicLoaded(char *name)
{
	for(int index = 0; index < GC_NmPicIndex; index++)
	{
		if(_stricmp(name, GC_NmPicNames[index]) == 0) // ? found
		{
			return 1;
		}
	}
	return 0;
}
void GC_NmPicUnloadAll(void)
{
	while(GC_NmPicIndex)
	{
		GC_NmPicIndex--;

		memFree(GC_NmPicNames[GC_NmPicIndex]);
		memFree(GC_NmPicFiles[GC_NmPicIndex]);
		UnloadPicture(GC_NmPicList[GC_NmPicIndex]);
	}
}
int GC_NmPic(char *name)
{
	for(int index = 0; index < GC_NmPicIndex; index++)
	{
		if(_stricmp(name, GC_NmPicNames[index]) == 0) // ? found
		{
			return GC_NmPicList[index];
		}
	}
	error();
	return 0; // dummy
}

char *GC_NmBgmNames[GC_NMBGM_MAX];
int GC_NmBgmList[GC_NMBGM_MAX];
int GC_NmBgmCount;

void GC_NmBgmLoadAll(void)
{
	int fp = DFOpen(ResourcePath("�V�i���I_��.txt"));

	for(; ; )
	{
		char *line = DFReadLine(fp);

		if(line[0] == '\0')
		{
			break;
		}
		char *name = line;

		// -- �g���q���� --
		char *p = strchr(name, '.');

		errorCase(!p);
		p[0] = '\0';
		// ----

		name = strx(name);

		int bgm;

		// -- Add --
		errorCase(GC_NMBGM_MAX <= GC_NmBgmCount);

		GC_NmBgmNames[GC_NmBgmCount] = name;
		GC_NmBgmList[GC_NmBgmCount] = bgm = LoadSoundMem(NmBgmResrc(line)); // �g���q�����
		GC_NmBgmCount++;
		// ----

		errorCase(bgm == -1);
	}
	DFClose(fp);
}
int GC_NmBgm(char *name)
{
	for(int index = 0; index < GC_NmBgmCount; index++)
	{
		if(strcmp(name, GC_NmBgmNames[index]) == 0) // ? found
		{
			return GC_NmBgmList[index];
		}
	}

printfDx("���y�f�[�^��������܂���: %s\n", name);

	error();
	return 0; // dummy
}
