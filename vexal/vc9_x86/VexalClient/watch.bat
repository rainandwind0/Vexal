:: Turn off echoing
@echo off

:: Start label
:start

:: Clear the screen
cls

:: Get the number of lines in the file
set LINES=0
for /f "delims==" %%I in (vexal.log) do (
    set /a LINES=LINES+1
)

:: Check if there are less than 15 lines
if %LINES% LSS %1 GOTO :ltfif

:: Print the last %1 lines
set /a LINES=LINES-%1
more +%LINES% < vexal.log
:: Go to wait
goto wait

:: Less than 15 lines...
:ltfif
type vexal.log

:: Wait label
:wait

:: Wait for a bit
ping 1.1.1.1 -n 1 -w 10 > NUL

:: Do it all again!
goto start