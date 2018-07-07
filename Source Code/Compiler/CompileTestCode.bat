preprocessor TestCode.code
copy C:\cmpl\Final.code Final.code > nul
pause
Compiler.exe < C:\cmpl\Final.code
pause
copy C:\cmpl\AssemblyData.asm + C:\cmpl\AssemblyCode.asm AssemblyFinal.asm > nul
nasm -f win32 AssemblyFinal.asm -o C:\cmpl\AssemblyFinal.obj
gcc -m32 -o FinalExe.exe C:\cmpl\AssemblyFinal.obj
del C:\cmpl\AssemblyData.asm
del C:\cmpl\AssemblyCode.asm
del C:\cmpl\AssemblyFinal.obj
del C:\cmpl\Final.code
FinalExe.exe
pause