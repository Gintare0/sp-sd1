# sp-sd1
Mano Pirmoji Programa - šis projektas yra studentų kategorijų kūrimo įrankis, skirtas apdoroti studentų pažymius, suskirstyti juos į dvi grupes („vargšiukai“ ir „kietiakai“) bei išmatuoti skirtingų rūšiavimo ir skirstymo strategijų efektyvumą.

Pagrindinės Savybės: skaito studentų duomenis iš įvesties failų. Apskaičiuoja galutinius pažymius pagal namų darbus ir egzaminų balus. Skirsto studentus į kategorijas („vargšiukai“ ir „kietiakai“). Optimizuotas skirtingų konteinerių (std::vector, std::list, std::deque) našumo matavimui. Atlieka našumo analizę ir palyginimus.

Leidimų Informacija

Leidimas v0.1: Pagrindinis Funkcionalumas.
Data: 2024-10-02.
Santrauka:
Pradinė studentų kategorijų kūrimo įrankio versija.
Skaito studentų informaciją iš įvesties failų (studentai.txt), apskaičiuoja galutinius pažymius ir suskirsto studentus į dvi grupes.
Įgyvendinta paprasta studentų kategorizavimo strategija pagal galutinius pažymius.
Pagrindinės Savybės:
Pagrindinis duomenų nuskaitymo, apdorojimo ir kategorijų kūrimo funkcionalumas.
Kategorizuotų studentų išvedimas į atskirus failus.

Leidimas v0.2: Našumo Testavimas Su Konteineriais.
Data: 2024-10-09.
Santrauka:
Pridėta galimybė matuoti kategorizavimo našumą, naudojant skirtingus konteinerių tipus (std::vector, std::list, std::deque).
Įgyvendintos dvi skirtingos strategijos studentų kategorizavimui:
Strategija 1: Studentai dalinami į du naujus konteinerius, paliekant originalą nepakitusį.
Strategija 2: „Vargšiukai“ perkeliami į naują konteinerį ir pašalinami iš originalaus konteinerio, lieka tik „kietiakai“.
Pagrindinės Pastabos:
std::vector buvo greičiausias konteineris siekiant prieigos prie elementų.
std::list buvo lėtesnis dėl susiejimo sąrašo (linked-list) perėjimo, ypač šalinant elementus.
std::deque buvo vidurinis variantas tarp vector ir list, kai reikėjo prieigos prie elementų ir jų šalinimo.

Leidimas v1.0: Optimizuotos Strategijos ir Galutinė Našumo Analizė.
Data: 2024-10-23.
Santrauka:
Įgyvendintos trys skirtingos kategorizavimo strategijos siekiant geresnio našumo:
Strategija 1: Studentų kopijavimas į du naujus konteinerius („vargšiukai“ ir „kietiakai“).
Strategija 2: „Vargšiukai“ perkeliami į naują konteinerį ir pašalinami iš originalo.
Strategija 3: Optimizuota kategorizacija naudojant STL algoritmus (std::partition, std::remove_if).
Optimizuotas Kategorizavimas:
Naudojant std::partition ir std::remove_if, kategorizavimas atliktas efektyviau.
Rezultatai:
std::partition žymiai pagerino kategorizavimo procesą, sumažinant iteracijų skaičių.
Ši strategija leido taupyti atmintį lyginant su Strategija 1, tuo pačiu buvo greitesnė nei Strategija 2, ypač naudojant didesnius duomenis.

Rezultatų Apžvalga

Palygintas skirtingų konteinerių tipų (vector, list, deque) našumas dviem scenarijais:
Kategorizuojant studentus į du atskirus konteinerius.
Kategorizuojant su pašalinimu iš originalaus konteinerio.
Vector Našumas:
std::vector buvo efektyvesnis ten, kur reikėjo dažnos prieigos prie elementų, bet mažiau efektyvus, kai reikėjo dažnai įterpti ar pašalinti elementus.
List Našumas:
std::list buvo lėtesnis, ypač atliekant dažną šalinimą, dėl susiejimo sąrašo struktūros.
Deque Našumas:
std::deque turėjo geresnį našumą prieigai prie elementų nei list, tačiau šalinimas vis tiek buvo lėtesnis nei vector.
Optimizuota Versija (v1.0):
Naudojant std::partition vienu perėjimu buvo gerokai pagerintas efektyvumas.
Šis metodas leido efektyviau naudoti atmintį lyginant su Strategija 1.

Įdiegimo Instrukcijos

Reikalavimai: C++ Kompiliatorius, palaikantis C++17 (pvz., g++, clang++). CMake arba Makefile (priklausomai nuo sistemos).

Projekto Kompiliavimas

Unix Sistemos (naudojant Makefile):
Klonuokite repozitoriją -> git clone https://github.com/Gintare0/jusu-repozitorija.git
Nueikite į projekto katalogą -> cd jusu-repozitorija
Sukompiliuokite projektą naudodami make -> make

Kryžminė Platforma (naudojant CMake):
Sukurkite katalogą build -> mkdir build
Nueikite į jį -> cd build
Paleiskite CMake -> cmake ..
Sukompiliuokite -> make

Naudojimo Instrukcijos

Paleiskite programą -> ./StudentSort

Įvesties Failai: įdėkite įvesties failus (studentai_1000.txt, studentai_10000.txt) į tą patį katalogą. Programa kategorizuos studentus ir sukurs atskirus failus „vargšiukams“ ir „kietiakams“.

Didelių Testinių Duomenų Generavimas: Galite sugeneruoti savo įvesties failus paleisdami -> ./StudentSort generate 100000

Ši komanda sukurs failą su 100 000 studentų įrašų, skirtą testavimui.

Repozitorijos Struktūra
Šaltinio Failai: sd1.cpp, studentas.cpp, studentas.h, mylib.h.
Kompiliavimo Failai: Makefile arba CMakeLists.txt kompiliavimui. Arba sp-sd1.sln ir sp-sd1.vcxproj (skirta Visual Studio vartotojams).
Dokumentacija: README.md (projekto apžvalga, įdiegimas, naudojimas). LICENSE (projekto licencija).
Pavyzdiniai Duomenys: studentai_1000.txt, studentai_10000.txt, studentai_100000.txt, studentai_1000000.txt, studentai_10000000.txt (pavyzdiniai įvesties failai).

Sekantys Žingsniai
Klonuokite Repozitoriją: Pradėkite klonuodami projektą.
Kompiliuokite ir Testuokite: Sekite instrukcijas, kad sukompiliuotumėte ir paleistumėte programą.
Prisidėkite Prie Projekto: Galite prisidėti prie projekto, jei turite idėjų, kaip jį patobulinti.

