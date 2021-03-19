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
* Nagenerujou se všechny možnosti pro řádky i sloupce - používá už výše zmíněná metoda na generaci možností.
* Křížovka se na začátku vynuluje konstantou "nevíme", která značí, že zatím pro dané políčko nevíme určit, jak bude obarvené.
* Pak se střídavě prochází všechny řádky a sloupce. V dané iteraci se na každém řádku/sloupci program kouká, jestli neumíme něco vydedukovat na základě toho, co už máme namalované v křížovce (podobně jak by to dělal člověk). Počítač se prostě podívá, které možnosti, které zbývají odpovídají tomu, co jsme tam doplnili v předešlých iteracích (které s tím nejsou sporné). Pak projde všechny nesporné možnosti a koukne, jestli nemají něco společného, pokud mají, můžeme to domalovat do křížovky, protože je to právě maximální doplnění, které lze udělat v tomto kroku na základě dedukce.
* Když projdeme jeden rozměr, křížovku obrátíme a začneme provádět to samé z druhé strany. Tím, že něco vydedukuje v jednom směru, nám zruší některé možnosti v druhém a když pak budeme v tom druhém směru něco dedukovat, tak tím zahozením některých možností se v optimálním přídapě zase dostaneme do situace, kdy mají všechny zbylé možnosti něco společné.
* Je zřejmé, že tato metoda nemůže fungovat na všechny křížovky. Triviálním protipříkladem, které táto meotda nevyřeší jsou křížovky s více řešeními. Existují ovšem i křížovky s jednoznačným řešením, které tato metoda nevyřeší. V takových případech se musí při řešení koukat současně na sloupce i řádky, případně něco zkusit doplnit a danou možnost vyspořit. Takže bude zbývat projít pouze ostatní možnosti, což zase může umožnit něco dedukovat atd.


Teorie k počtu křížovek a zadání
---------------------------------------
Pro křížovku s pevně zvolenými rozměry n krát m je zajímavé uvažovat faktorprostor všech řešení (tj. černo-bílých obrázků) podle ekvivalence E(obr1,obr2) = "Obrázky, obr1 a obr2 jsou řešením stejného zadání". Je jasné, že obrázků je 2^(n* m) (když nepožadujeme neprázdnost žádků a sloupců, kdybychom to požadovali, dá se počet spočítat pomocí principu inkluze a exkluze). Netriviální ovšem je, kolik existuje různých zadání, které mají řešení. Tahle otázka dává smysl právě díky tomu, že některé křížovky mají více řešení. Některé křížovky mají dokonce hodně řešení. Když například uvažujeme čtvercovou křížovku, která má v zadání v každém sloupci a řádku právě jednu jedničku, je vidět, že taková křížovka má n! řešení. Ještě hůře jsou na tom křížovky, které mají v každém řádku a sloupci právě k jedniček (maximalizujeme přes k). Tohle jsou i nejhorší případy na počet možností na řádek. Kombinatorickými úvahami (tenisáková metoda) se spočte, že v takovém případě existuje Binomial[k + n - 1, k] možností obarvení řádku (řádek dlouhý n).

Vytvoření obrázků
---------------------------------------
* Jestli půjde
