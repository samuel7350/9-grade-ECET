@echo off

REM Load Visual Studio's build tools
call "%ProgramFiles(x86)%\Microsoft 

Visual Studio 10.0\VC\vcvarsall.bat" 

x86

REM Choose what you want to do, 1 or 2 

by (un)commenting
cd "C:\Users\Dada\Documents\Visual 

Studio 2010\Projects\Cryptography

\Cryptography"
 msbuild.exe Cryptography.vcxproj
 cl.exe
 cl HillCypher.cpp

echo DONE!!
pause


REM  Can Open a normal shell with 

variables loaded
%comspec% /k
