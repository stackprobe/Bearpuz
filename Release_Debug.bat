C:\Factory\Tools\RDMD.exe /RC out

MD out\bin
MD out\bin\bin

COPY /B Bearpuz\Release\Bearpuz.exe out\bin\bin\.
COPY /B �Y�t\* out

C:\Factory\Tools\xcp.exe /C Resource out\Resource

DIR > out\������͊J���p�����[�X�ł��B

REN out\bin\bin �X�ɂ��̒�
REN out\bin ���s�t�@�C���͂��̒�

C:\Factory\SubTools\zip.exe /O out Bearpuz

PAUSE
