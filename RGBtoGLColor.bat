@echo off
set /p "p1=Enter red: "
set /p "p2=Enter green: "
set /p "p3=Enter blue: "
set /p "p4=Enter alpha: "

for /f %%i in ('powershell -Command "[math]::Round(%p1%/255, 3)"') do set r=%%i
for /f %%i in ('powershell -Command "[math]::Round(%p2%/255, 3)"') do set g=%%i
for /f %%i in ('powershell -Command "[math]::Round(%p3%/255, 3)"') do set b=%%i
for /f %%i in ('powershell -Command "[math]::Round(%p4%/255, 3)"') do set a=%%i

echo Red:   %r%
echo Green: %g%
echo Blue:  %b%
echo Alpha: %a%
pause
