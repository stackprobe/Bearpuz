DEL ..\opening.ogv

C:\app\ffmpeg-3.2.4-win64-shared\bin\ffmpeg.exe -i ^
	opening.mp4 ^
	-map 0:0 -map 0:1 -codec:v libtheora -qscale:v 7 -codec:a libvorbis -qscale:a 5 -ac 2 ^
	..\opening.ogv

PAUSE
