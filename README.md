# v1.0
v0.1 Sukurta programa, kuri nuskaito vartotojų įvedamus reikiamus duomenis, taip pat sukurtas skaičiavimo būdo pasirinkimas (mediana arba vidurkis), bei sukurtas galutinio balo skaičiavimas.

v0.2 Antroje užduotyje, pridėtas nuskaitymas iš .txt failo, taip pat rūšiavimas pagal vardus rezultatuose, bei lygiavimas rezultatuose.

v0.3 Trečioje versijoje, į atskirą failą iškeltos funkcijos ir struktūros, kur tikslinga, pridėtas išimčių valdymas.

v0.4 Ketvirtojoje versijoje sugeneruoti penki atsitiktiniai studentų sąrašų failai, sudaryti iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. Studentai suskirstomi į dvi kategorijas: protingi ir kvaili. Atlikita programos veikimo greičio analizė.

v0.5 Sukurtas programos spartos lyginimas naudojant std::list ir std::vector
Išvada: galime matyti, jog programa veikia greičiau naudojant list. Tačiau net ir analizuojant didelius duomenų kiekius skirtumas nėra didelis.
Kompiuterio parametrai: 2.50GHz procesorius, 8 GB RAM, SSD 476 GB.

v1.0

VECTOR
|| Mano |1|2|
|------|------|------|------|
|1000|0 s|0 s|0 s|
|10 000|0 s|0 s|0 s|
|100 000|0.021 s|0.018 s|0.022 s|
|1 000 000|0.179 s|0.185 s|0.204 s|
|10 000 000|2.085 s|3.66 s|1.898 s|

LIST
|| Mano |1|2|
|------|------|------|------|
|1000|0 s|0 s|0 s|
|10 000|0 s|0 s|0 s|
|100 000|0.02 s|0.018 s|0.02 s|
|1 000 000|0.225 s|0.193 s|0.25 s|
|10 000 000|2.356 s|2.063 s|2.408 s|


