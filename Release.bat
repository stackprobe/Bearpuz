C:\Factory\Tools\RDMD.exe /RC out

COPY /B Bearpuz\Release\Bearpuz.exe out\Bearpuz.exe
COPY /B “Y•t\* out

C:\Dat\DxLib\3_18c\Tool\DXArchive\DXAEncode.exe -K:Bearpuz-8493 Resource out\Resource.dxa

C:\Factory\SubTools\zip.exe /O out Bearpuz

PAUSE
