# Nonograms

Deklarační část
--------------------------------------
* Deklarace důležitých konstant
* deklarace globálních proměnných - zadání a samotná křížkovka
* Vše vedeno v souboru (deklarace.cpp)

Načítací část
---------------------------------------
* Kontrola vstupu, zda je ve správném tvaru (kontrola.cpp)
* Obrácení zadání, abychom mohli křížovku řešit z různých stran (obraceni.cpp)
* Načtení zadání: zvolenou oriencaci zadání si načteme do paměti Zadani_bok, Zadani_vrch (nacti_zadani.cpp)
* Nagenerování všech možností pro všechny řádky a jejich přepsání do řetězců nul a jedniček
* Překopírování posledního řádku do nové složky, kde se budou sestrojovat řešení

Řešící část - vhodné možnosti
---------------------------------------
* Z nagenerovaných možností se postupně skládají řešení křížovky. Začne se posledním řádkem a postupuje se směrem nahoru. Když máme hotovou nějakou k-tici řádků a chceme přidat (k+1). řádek, zkontrolujeme nejprve, zda k té k-tici, skutečně pasuje. Tj. když domalujeme podle zadání pokračování toho, co už jsme namalovali ve směru sloupců, tak se nestane, že by mová možnost měla bílé místo někde, kde doplnění káže černou a podobně. 
* Ke kontrole se používajá metoda "Iterace na sloupce", která doplní řešení ve sloupcích zespodu nahoru, tak aby výsledek odpovídal zadání.
* Pak zkoumáme, co přesně to doplnění provedlo a rozebíráme možnosti, zda skutečně ta nová možnost k hotové k-tici pasuje. Toto se provádí v metodách "Nový řádek pasuje ke k-tici" a "Nový řádek pasuje k doplnění".
* Jestli řádek projde těmito kontrolami, tak novou (k+1)-tici zapíšeme do souboru s novými možnostmi. Tento proces pak iterujeme, dokud neprojdeme všechny řádky.

Řešení pomocí logiky - jen někdy
---------------------------------------
* Je přepsáno, ale zatím nen funkční.

Vytvoření obrázků
---------------------------------------
* Jestli půjde
