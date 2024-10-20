@echo off

:: Šis failas kompiliuoja projektą Windows operacinėje sistemoje, naudojant g++

set SRC_FILES=sd1.cpp studentas.cpp
set OUTPUT_FILE=StudentuRusiavimas.exe

:: Kompiliuoti failus, naudojant g++
g++ -std=c++17 -Wall %SRC_FILES% -o %OUTPUT_FILE%

if %ERRORLEVEL% equ 0 (
    echo Kompiliacija sėkminga. Sukurtas vykdomasis failas: %OUTPUT_FILE%
) else (
    echo Kompiliacija nepavyko. Patikrinkite klaidas.
)

pause
