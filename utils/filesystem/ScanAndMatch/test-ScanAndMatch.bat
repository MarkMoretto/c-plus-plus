@ECHO OFF
:: Testing FileScanner with command-line args.

SET PROMPT=

SETLOCAL EnableDelayedExpansion
SET MINGW64_HOME=
:: Need to update with local msys install if compiling or running
SET "msys64_pth=C:\Users\MMorett1\AppData\Local\Programs\msys64\mingw32"
SET "PATH=%msys64_pth%;%msys64_pth%\bin;%PATH%"


SET "test_dir=S:\\OFP\\Analytics\\Population Management\\Queries\\Matt"
SET keyword=Admission
SET file_extension=sql

ECHO Running FileScanner test. Searching for %keyword% in %test_dir%...
FileScanner.exe "%test_dir%" %keyword% %file_extension%
ECHO Done!
PING 127.0.0.1 -n 2 > nul


