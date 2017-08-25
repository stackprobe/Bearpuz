C:\Factory\Tools\RDMD.exe /RC out

MD out\bin
MD out\bin\bin

COPY /B Bearpuz\Release\Bearpuz.exe out\bin\bin\.
COPY /B 添付\* out

C:\Factory\Tools\xcp.exe /C Resource out\Resource

DIR > out\■これは開発用リリースです。

REN out\bin\bin 更にこの中
REN out\bin 実行ファイルはこの中

C:\Factory\SubTools\zip.exe /O out Bearpuz

PAUSE
