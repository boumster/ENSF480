@echo off
setlocal
set CURRENT_DIR=%CD%
set CYGWIN_DIR=%CURRENT_DIR:\=/%
echo Compiling...
C:\cygwin64\bin\bash.exe -l -c "cd \"/cygdrive/c/%CYGWIN_DIR:~2%\" && g++ -Wall -o my_program *.cpp"
if %errorlevel% neq 0 (
    echo Compilation failed.
    pause
    exit /b %errorlevel%
)
echo Done.
echo Running...
C:\cygwin64\bin\bash.exe -l -c "cd \"/cygdrive/c/%CYGWIN_DIR:~2%\" && ./my_program"
echo Done.
pause
endlocal