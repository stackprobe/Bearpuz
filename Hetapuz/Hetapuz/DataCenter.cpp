#include "StdInc.h"

Dc_t *Dc;

void DcInit_LoadAllPicture(void)
{
	Dc->PicDummy = LoadPicture(ResourcePath("�⏕\\Dummy.png"));
	Dc->PicBlackWall = LoadPicture(ResourcePath("�⏕\\����.png"));
	Dc->PicWhiteWall = LoadPicture(ResourcePath("�⏕\\����.png"));

	Dc->PicLogo   = LoadPicture(ResourcePath("�摜\\���S���.png"));
	Dc->PicTitle  = LoadPicture(ResourcePath("�摜\\�X�^�[�g���.png"));
	Dc->PicSelect = LoadPicture(ResourcePath("�摜\\�I����.png"));
	Dc->PicExit   = Dc->PicDummy; // LoadPicture(ResourcePath("�摜\\�̌��ŏI��.png"));

	Dc->PicTitleCursor = LoadPicture(ResourcePath("�摜\\���j���[��ʑI���{�^��.png"));

	Dc->PicTitleStartOn      = LoadPicture(ResourcePath("�摜\\�̌��ŃX�^�[�g�{�^���}�E�X�I��.png"));
	Dc->PicTitleStartPress   = LoadPicture(ResourcePath("�摜\\�̌��ŃX�^�[�g�{�^���}�E�X�N���b�N.png"));
	Dc->PicTitleSettingOn    = LoadPicture(ResourcePath("�摜\\�ݒ��������{�^���}�E�X�I��.png"));
	Dc->PicTitleSettingPress = LoadPicture(ResourcePath("�摜\\�ݒ��������{�^���}�E�X�N���b�N.png"));

	Dc->PicCfgWall       = LoadPicture(ResourcePath("System\\Config\\Wall.png"));
	Dc->PicCfgWindow     = LoadPicture(ResourcePath("System\\Config\\�E�B���h�E.png"));
	Dc->PicCfgFullScreen = LoadPicture(ResourcePath("System\\Config\\�t���X�N���[��.png"));
	Dc->PicCfgKidoku     = LoadPicture(ResourcePath("System\\Config\\���ǂ̂�.png"));
	Dc->PicCfgMidoku     = LoadPicture(ResourcePath("System\\Config\\���ǂ��܂�.png"));
	Dc->PicCfgRotL       = LoadPicture(ResourcePath("System\\Config\\����].png"));
	Dc->PicCfgRotR       = LoadPicture(ResourcePath("System\\Config\\�E��].png"));
	Dc->PicCfgDir2       = LoadPicture(ResourcePath("System\\Config\\��.png"));
	Dc->PicCfgDir4       = LoadPicture(ResourcePath("System\\Config\\��.png"));
	Dc->PicCfgDir6       = LoadPicture(ResourcePath("System\\Config\\�E.png"));
	Dc->PicCfgDir8       = LoadPicture(ResourcePath("System\\Config\\��.png"));
	Dc->PicCfgBomb       = LoadPicture(ResourcePath("System\\Config\\�K�E�Z.png"));
	Dc->PicCfgModoru     = LoadPicture(ResourcePath("System\\Config\\�߂�.png"));
	Dc->PicCfgTsumami    = LoadPicture(ResourcePath("System\\Config\\�܂�.png"));
	Dc->PicCfgPressKey   = LoadPicture(ResourcePath("System\\Config\\�L�[�������ĉ�����.png"));

	Dc->PicContinueShinai      = LoadPicture(ResourcePath("�摜\\�R���e�B�j���[���Ȃ�.png"));
	Dc->PicContinueShinaiFocus = LoadPicture(ResourcePath("�摜\\�R���e�B�j���[���Ȃ���.png"));
	Dc->PicContinueSuru        = LoadPicture(ResourcePath("�摜\\�R���e�B�j���[����.png"));
	Dc->PicContinueSuruFocus   = LoadPicture(ResourcePath("�摜\\�R���e�B�j���[�����.png"));

	Dc->PicSelectGI = Dc->PicDummy; // LoadPicture(ResourcePath("�摜\\�h�C�c�C�^���A.png"));
	Dc->PicSelectJP = Dc->PicDummy; // LoadPicture(ResourcePath("�摜\\���{�v���C�Z��.png"));

	Dc->PicCpuWall   = Dc->PicDummy; // LoadPicture(ResourcePath("�摜\\�����I�����.png"));
	Dc->PicCpuCursor = LoadPicture(ResourcePath("�摜\\�J�[�\��.png"));

	Dc->PicReady = LoadPicture(ResourcePath("�摜\\ready.png"));

	Dc->PicWin      = LoadPicture(ResourcePath("�摜\\����.png"));
	Dc->PicWinWall  = LoadPicture(ResourcePath("�摜\\������.png"));
	Dc->PicWin1P    = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ƈɏ���.png"));
	Dc->PicWin2P    = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\��������.png"));
	Dc->PicLose     = LoadPicture(ResourcePath("�摜\\�s�k.png"));
	Dc->PicLoseWall = LoadPicture(ResourcePath("�摜\\�s�k���.png"));
	Dc->PicLose1P   = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ƈɔs�k.png"));
	Dc->PicLose2P   = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�����s�k.png"));

	Dc->PicPauseItem[0][0] = LoadPicture(ResourcePath("System\\Button\\�Q�[���ɖ߂�.png"));
	Dc->PicPauseItem[0][1] = LoadPicture(ResourcePath("System\\Button\\�Q�[���ɖ߂�I��.png"));
	Dc->PicPauseItem[1][0] = LoadPicture(ResourcePath("System\\Button\\�Q�[�����I������.png"));
	Dc->PicPauseItem[1][1] = LoadPicture(ResourcePath("System\\Button\\�Q�[�����I������I��.png"));
	Dc->PicPauseItem[2][0] = LoadPicture(ResourcePath("System\\Button\\�^�C�g���ɖ߂�.png"));
	Dc->PicPauseItem[2][1] = LoadPicture(ResourcePath("System\\Button\\�^�C�g���ɖ߂�I��.png"));
	Dc->PicPauseItem[3][0] = LoadPicture(ResourcePath("System\\Button\\�ݒ�.png"));
	Dc->PicPauseItem[3][1] = LoadPicture(ResourcePath("System\\Button\\�ݒ�I��.png"));

	Dc->PicCIStar  = LoadPicture(ResourcePath("�J�b�g�C��\\Star.png"));
	Dc->PicCI1P1Ren3 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ɎO�A��.png"));
	Dc->PicCI1P2Ren3 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\���O�A��.png"));
	Dc->PicCI2P1Ren3 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ƎO�A��.png"));
	Dc->PicCI2P2Ren3 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\���O�A��.png"));
	Dc->PicCI1P1Ren5 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ɌܘA��.png"));
	Dc->PicCI1P2Ren5 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\���ܘA��.png"));
	Dc->PicCI2P1Ren5 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ƌܘA��.png"));
	Dc->PicCI2P2Ren5 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\���ܘA��.png"));
	Dc->PicCI1P1Ren7 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ɍŏI�A��.png"));
	Dc->PicCI1P2Ren7 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\���ŏI�A��.png"));
	Dc->PicCI2P1Ren7 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ƍŏI�A��.png"));
	Dc->PicCI2P2Ren7 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\���ŏI�A��.png"));

	Dc->PicCI1P1Damage = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ɑŌ�.png"));
	Dc->PicCI1P2Damage = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\���Ō�.png"));
	Dc->PicCI2P1Damage = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ƑŌ�.png"));
	Dc->PicCI2P2Damage = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\���Ō�.png"));

	Dc->PicCIHissStar = LoadPicture(ResourcePath("�J�b�g�C��\\Star�K�E.png"));

	Dc->PicCIHiss1P1 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ƕK�E�Z.png"));
	Dc->PicCIHiss1P2 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\�ɕK�E�Z.png"));
	Dc->PicCIHiss2P1 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\���K�E�Z.png"));
	Dc->PicCIHiss2P2 = Dc->PicDummy; // LoadPicture(ResourcePath("�J�b�g�C��\\���K�E�Z.png"));

	// ���� --->

	for(int i = 0; i < 0x100; i++)
	{
		Dc->PicAscii[i] = Dc->PicDummy;
	}
	Dc->PicAscii['!'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\!.png"));
	Dc->PicAscii['"'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\Dq.png"));
	Dc->PicAscii['#'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\!.png"));
	Dc->PicAscii['$'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\$.png"));
	Dc->PicAscii['%'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\%.png"));
	Dc->PicAscii['&'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\&.png"));
	Dc->PicAscii['\'']= LoadPicture(ResourcePath("�t�B�[���h\\����\\Sq.png"));
	Dc->PicAscii['('] = LoadPicture(ResourcePath("�t�B�[���h\\����\\(.png"));
	Dc->PicAscii[')'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\).png"));
	Dc->PicAscii['*'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\Star.png"));

	Dc->PicAscii['0'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\����_0.png"));
	Dc->PicAscii['1'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\����_1.png"));
	Dc->PicAscii['2'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\����_2.png"));
	Dc->PicAscii['3'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\����_3.png"));
	Dc->PicAscii['4'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\����_4.png"));
	Dc->PicAscii['5'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\����_5.png"));
	Dc->PicAscii['6'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\����_6.png"));
	Dc->PicAscii['7'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\����_7.png"));
	Dc->PicAscii['8'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\����_8.png"));
	Dc->PicAscii['9'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\����_9.png"));

	Dc->PicAscii[';'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\;.png"));
	Dc->PicAscii['<'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\��.png"));
	Dc->PicAscii['>'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\��.png"));
	Dc->PicAscii['?'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\�H.png"));
	Dc->PicAscii['@'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\@.png"));

	Dc->PicAscii['A'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\A.png"));
	Dc->PicAscii['B'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\B.png"));
	Dc->PicAscii['C'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\C.png"));
	Dc->PicAscii['D'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\D.png"));
	Dc->PicAscii['E'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\E.png"));
	Dc->PicAscii['F'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\F.png"));
	Dc->PicAscii['G'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\G.png"));
	Dc->PicAscii['H'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\H.png"));
	Dc->PicAscii['I'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\I.png"));
	Dc->PicAscii['J'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\J.png"));
	Dc->PicAscii['K'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\K.png"));
	Dc->PicAscii['L'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\L.png"));
	Dc->PicAscii['M'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\M.png"));
	Dc->PicAscii['N'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\N.png"));
	Dc->PicAscii['O'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\O.png"));
	Dc->PicAscii['P'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\P.png"));
	Dc->PicAscii['Q'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\Q.png"));
	Dc->PicAscii['R'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\R.png"));
	Dc->PicAscii['S'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\S.png"));
	Dc->PicAscii['T'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\T.png"));
	Dc->PicAscii['U'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\U.png"));
	Dc->PicAscii['V'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\V.png"));
	Dc->PicAscii['W'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\W.png"));
	Dc->PicAscii['X'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\X.png"));
	Dc->PicAscii['Y'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\Y.png"));
	Dc->PicAscii['Z'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\Z.png"));

	for(int aupr = 'A'; aupr <= 'Z'; aupr++)
	{
		int alwr = aupr + 0x20;

		Dc->PicAscii[alwr] = Dc->PicAscii[aupr];
	}
	Dc->PicAscii['['] = LoadPicture(ResourcePath("�t�B�[���h\\����\\[.png"));
	Dc->PicAscii[']'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\].png"));
	Dc->PicAscii['_'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\_.png"));

	Dc->PicAscii['�'] = LoadPicture(ResourcePath("�t�B�[���h\\����\\wo.png"));

	// <--- ����

	for(int i = 0; i < 10; i++)
	{
		Dc->PicDir[i] = Dc->PicDummy;
	}
	Dc->PicDir[2] = LoadPicture(ResourcePath("�t�B�[���h\\����\\��.png"));
	Dc->PicDir[4] = LoadPicture(ResourcePath("�t�B�[���h\\����\\��.png"));
	Dc->PicDir[6] = LoadPicture(ResourcePath("�t�B�[���h\\����\\��.png"));
	Dc->PicDir[8] = LoadPicture(ResourcePath("�t�B�[���h\\����\\��.png"));

	Dc->PicFace[PZPLYR_1P1][0][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�h�C�c����a.png"));
	Dc->PicFace[PZPLYR_1P1][0][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�h�C�c����b.png"));
	Dc->PicFace[PZPLYR_1P1][0][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�h�C�c����c.png"));
	Dc->PicFace[PZPLYR_1P1][1][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�h�C�c�ꂵ��a.png"));
	Dc->PicFace[PZPLYR_1P1][1][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�h�C�c�ꂵ��b.png"));
	Dc->PicFace[PZPLYR_1P1][1][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�h�C�c�ꂵ��c.png"));
	Dc->PicFace[PZPLYR_1P1][2][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�h�C�c�ň�a.png"));
	Dc->PicFace[PZPLYR_1P1][2][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�h�C�c�ň�b.png"));
	Dc->PicFace[PZPLYR_1P1][2][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�h�C�c�ň�c.png"));
	// - - -
	Dc->PicFace[PZPLYR_1P2][0][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�C�^���A����a.png"));
	Dc->PicFace[PZPLYR_1P2][0][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�C�^���A����b.png"));
	Dc->PicFace[PZPLYR_1P2][0][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�C�^���A����c.png"));
	Dc->PicFace[PZPLYR_1P2][1][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�C�^���A�ꂵ��a.png"));
	Dc->PicFace[PZPLYR_1P2][1][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�C�^���A�ꂵ��b.png"));
	Dc->PicFace[PZPLYR_1P2][1][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�C�^���A�ꂵ��c.png"));
	Dc->PicFace[PZPLYR_1P2][2][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�C�^���A�ň�a.png"));
	Dc->PicFace[PZPLYR_1P2][2][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�C�^���A�ň�b.png"));
	Dc->PicFace[PZPLYR_1P2][2][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�C�^���A�ň�c.png"));
	// - - -
	Dc->PicFace[PZPLYR_2P1][0][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\���{����a.png"));
	Dc->PicFace[PZPLYR_2P1][0][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\���{����b.png"));
	Dc->PicFace[PZPLYR_2P1][0][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\���{����c.png"));
	Dc->PicFace[PZPLYR_2P1][1][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\���{�ꂵ��a.png"));
	Dc->PicFace[PZPLYR_2P1][1][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\���{�ꂵ��b.png"));
	Dc->PicFace[PZPLYR_2P1][1][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\���{�ꂵ��c.png"));
	Dc->PicFace[PZPLYR_2P1][2][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\���{�ň�a.png"));
	Dc->PicFace[PZPLYR_2P1][2][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\���{�ň�b.png"));
	Dc->PicFace[PZPLYR_2P1][2][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\���{�ň�c.png"));
	// - - -
	Dc->PicFace[PZPLYR_2P2][0][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�v���C�Z������a.png"));
	Dc->PicFace[PZPLYR_2P2][0][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�v���C�Z������b.png"));
	Dc->PicFace[PZPLYR_2P2][0][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�v���C�Z������c.png"));
	Dc->PicFace[PZPLYR_2P2][1][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�v���C�Z���ꂵ��a.png"));
	Dc->PicFace[PZPLYR_2P2][1][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�v���C�Z���ꂵ��b.png"));
	Dc->PicFace[PZPLYR_2P2][1][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�v���C�Z���ꂵ��c.png"));
	Dc->PicFace[PZPLYR_2P2][2][0] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�v���C�Z���ň�a.png"));
	Dc->PicFace[PZPLYR_2P2][2][1] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�v���C�Z���ň�b.png"));
	Dc->PicFace[PZPLYR_2P2][2][2] = Dc->PicDummy; // LoadPicture(ResourcePath("��O��\\�v���C�Z���ň�c.png"));

	Dc->PicEffeHana   = LoadPicture(ResourcePath("���炫��\\�ԃs���N����.png"));
	Dc->PicEffeHoshi  = LoadPicture(ResourcePath("���炫��\\���鐯.png"));
	Dc->PicEffeKagaya = LoadPicture(ResourcePath("���炫��\\�P��.png"));

	Dc->PicBlocks[0] = LoadPicture(ResourcePath("�u���b�N\\���ז�.png"));
	Dc->PicBlocks[1] = LoadPicture(ResourcePath("�u���b�N\\��.png"));
	Dc->PicBlocks[2] = LoadPicture(ResourcePath("�u���b�N\\��.png"));
	Dc->PicBlocks[3] = LoadPicture(ResourcePath("�u���b�N\\��.png"));
	Dc->PicBlocks[4] = LoadPicture(ResourcePath("�u���b�N\\��.png"));
	Dc->PicBlocks[5] = LoadPicture(ResourcePath("�u���b�N\\��.png"));

	Dc->PicFlowers[0] = LoadPicture(ResourcePath("�u���b�N\\�U�肨�ז�.png"));
	Dc->PicFlowers[1] = LoadPicture(ResourcePath("�u���b�N\\�U�艩.png"));
	Dc->PicFlowers[2] = LoadPicture(ResourcePath("�u���b�N\\�U�莇.png"));
	Dc->PicFlowers[3] = LoadPicture(ResourcePath("�u���b�N\\�U���.png"));
	Dc->PicFlowers[4] = LoadPicture(ResourcePath("�u���b�N\\�U���.png"));
	Dc->PicFlowers[5] = LoadPicture(ResourcePath("�u���b�N\\�U���.png"));
}
void DcInit_LoadAllPictureSafe(void)
{
	// �ςȃn���h����n���Ė������\�������悤�Ƃ��Ă�󂾂���A����ς�}�Y����ˁA�A�A
//	if(DrawGraph(0, 0, Dc->PicBlackWall, 0) != 0) // ? �\���o���Ȃ� -> �J�����ꂽ�B
	{
		DcInit_LoadAllPicture();
	}
}

static void LoadResrcScnrList(void)
{
	int fp = DFOpen(ResourcePath("�V�i���I_Text.txt"));

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

		// -- Add --
		errorCase(RESRC_SCNR_MAX <= Dc->ResrcScnrCount);

		strcpy(Dc->ResrcScnrList[Dc->ResrcScnrCount], name);
		Dc->ResrcScnrCount++;
		// ----
	}
	DFClose(fp);
}
void DcInit(void)
{
	Dc = (Dc_t *)memCalloc(sizeof(Dc_t));

	DcInit_LoadAllPicture();

	Dc->BGM_Title = LoadBGM(ResourcePath("��\\hetaria.mp3"));

	Dc->SeReady    = LoadSound(ResourcePath("��\\ready.wav"));
	Dc->SeStart    = LoadSound(ResourcePath("��\\�X�^�[�g.wav"));
	Dc->SeFlower   = LoadSound(ResourcePath("��\\���m�N���t�����[_����.wav"));
	Dc->SeFlowerLot= LoadSound(ResourcePath("��\\���m�N���t�����[_���.wav"));
	Dc->SeMove     = LoadSound(ResourcePath("��\\���ړ�.wav"));
	Dc->SeRotate   = LoadSound(ResourcePath("��\\��].wav"));
	Dc->SeErase    = LoadSound(ResourcePath("��\\������Ƃ��̉�.wav"));
	Dc->SeDecide   = LoadSound(ResourcePath("��\\���n.wav"));
	Dc->SeBomb     = LoadSound(ResourcePath("��\\�K�E�Z.wav"));

	Dc->SeIkuyo = LoadSound(ResourcePath("��\\��������[.wav"));
	Dc->SeUwa   = LoadSound(ResourcePath("��\\���킠.wav"));
	Dc->SeEi    = LoadSound(ResourcePath("��\\����.wav"));
	Dc->SeSore  = LoadSound(ResourcePath("��\\�����.wav"));
	Dc->SeHa    = LoadSound(ResourcePath("��\\�͂�.wav"));
	Dc->SeGo    = LoadSound(ResourcePath("��\\�S�[.wav"));
	Dc->SeSpCmd = LoadSound(ResourcePath("��\\�X�y�V�����R�}���h.wav"));
	Dc->SeRucca = LoadSound(ResourcePath("��\\���b�J.wav"));
	Dc->SeJReady= LoadSound(ResourcePath("��\\���f�B�[.wav"));
	Dc->SeRen3  = LoadSound(ResourcePath("��\\�O�A��.wav"));
	Dc->SeRen5  = LoadSound(ResourcePath("��\\�ܘA��.wav"));
	Dc->SeRen7  = LoadSound(ResourcePath("��\\�ŏI�A��.wav"));
	Dc->SeWin   = LoadSound(ResourcePath("��\\�����{�C�X.wav"));
	Dc->SeLose  = LoadSound(ResourcePath("��\\�s�k�{�C�X.wav"));
	Dc->SeHissOk= LoadSound(ResourcePath("��\\go.mp3"));

	Dc->SeBellWin  = LoadSound(ResourcePath("��\\�����W���O��.mp3"));
	Dc->SeBellLose = LoadSound(ResourcePath("��\\�s�k�W���O��.mp3"));
	Dc->SeBellHiss = LoadSound(ResourcePath("��\\�X�y�V�����R�}���h�W���O��.mp3"));

	// �������l�ݒ�ʒu�A���݂��̏����l�͖��� -> InitSettings()
	Dc->BGMVolume = 0.45;
	Dc->SeVolume = 0.45;

	LoadResrcScnrList();
}
void DcFnlz(void)
{
	// ���̕ӂ̊J���͖ʓ|�Ȃ̂ł��
	/*
	UnloadPicture(Dc->PicBlackWall);
	memFree(Dc->BGMFile_Game);
	UnloadSound(Dc->SeReady);
	*/

	// memFree(Dc); // �I���ԍۂɂ��ADc �g���悤�ɂȂ��Ă��܂����̂ŁA�J�������Ⴞ��!!
}
