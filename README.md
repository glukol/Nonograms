# Nonograms

Implementace dvou způsobů řešení malovaných křížovek (nonograms). První metoda založena na brute force s ořezáváním, která funguje univerzálně. Druhá metoda implementuje klasické techniky řešení pomocí reprezentace křížovky v jazyce matematické logiky, nelze pomocí ní najít řešení obecné křížovky - je schopna vyřešit jen některé speciální případy. 

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

Řešení takovýmito metodami je ovšej jedno z nejlepších možných. Řešení křížovky je totiž ekvivalentní hledání splňujícího ohodnocení pro nějakou speciální výrokovou formuly, která odpovídá konjunkci splnění řádků a sloupců, kde řadek/sloupec je splněn právě tehdy, když ohodnocení křížovky odpovídá nějak možnosti řádku. Řešení se pak provádí vhodnou aplikací de-Morganových pravidel. Celková délka výrokové formule se tedy v každém kroku zkracuje, což je veledůležitá vlastnost. Hloupý brute-force tady nefunguje právě proto, že když se snažíme zkombinovat všechny možnosti na řádky, tak pomocí de-Morganových pravidel roznásobujeme konjunkce, což způsobuje prodlužování výroku.

Nejlepším způsobem řešení bude nějaká kombinace brute-force a deduktivní metody.

Teorie k počtu křížovek a zadání
---------------------------------------
Pro křížovku s pevně zvolenými rozměry n krát m je zajímavé uvažovat faktorprostor všech řešení (tj. černo-bílých obrázků) podle ekvivalence E(obr1,obr2) = "Obrázky, obr1 a obr2 jsou řešením stejného zadání". Je jasné, že obrázků je 2^(n* m) (když nepožadujeme neprázdnost žádků a sloupců, kdybychom to požadovali, dá se počet spočítat pomocí principu inkluze a exkluze). Netriviální ovšem je, kolik existuje různých zadání, které mají řešení. Tahle otázka dává smysl právě díky tomu, že některé křížovky mají více řešení. Některé křížovky mají dokonce hodně řešení. Když například uvažujeme čtvercovou křížovku, která má v zadání v každém sloupci a řádku právě jednu jedničku, je vidět, že taková křížovka má n! řešení. Ještě hůře jsou na tom křížovky, které mají v každém řádku a sloupci právě k jedniček (maximalizujeme přes k). Tohle jsou ty nejhorší případy na počet možností na řádek. Kombinatorickými úvahami (tenisáková metoda) se spočte, že v takovém případě existuje Binomial[k + n - 1, k] možností obarvení řádku (řádek dlouhý n).

Když chceme zezdola odhadnout počet zadání, které mají řešení, triviální úvahou je vzít počet polovin zadání (zrčíme zadají jen pro řádky). Protože když něco předepíšeme jen v jednom směru, rozhodně bude existovat obarvení, které to bude splňovat. Tudíž dolním odhadem je například (počet zadání řádku)^n, kde počet zadání řádku se dá spočíst takto: fixujeme počet obarvených políček na řádku a fixujeme počet souvislých částí, mezi které je rozdělíme, pak aplikujeme tenisákovou metodu. Tohle přesčítáme přes počet obarvených políček a počet souvislých obarvených oblastí.

Vzorec pro dolní odhad počtu zadání (na řádek)
P[n_] := Sum[Sum[Binomial[k + i - 1, k], {k, 0, n - 2* i + 1}], {i, 1, Ceiling[n/2]}]
a hodnoty pro n od 1 do 50
{1, 2, 4, 7, 12, 20, 33, 54, 88, 143, 232, 376, 609, 986, 1596, 2583, 4180, 6764, 10945, 17710, 28656, 46367, 75024, 121392, 196417,  317810, 514228, 832039, 1346268, 2178308, 3524577, 5702886, 9227464, 14930351, 24157816, 39088168, 63245985, 102334154, 165580140,  267914295, 433494436, 701408732, 1134903169, 1836311902, 2971215072, 4807526975, 7778742048, 12586269024, 20365011073, 32951280098}

Když tyto čísla umocníme na příslošný počet řádků, dostaneme odhad na počet zadání. Pro přehlednost jsou hodnoty zlogaritmovány desítkovým logaritmem.
{0., 0.60206, 1.80618, 3.38039, 5.39591, 7.80618, 10.6296, 13.8592, 17.5003, 21.5534, 26.0204, 30.9023, 36.2, 41.9143, 48.0455, 54.594, 61.56, 68.9437, 76.7451, 84.9644, 93.6015, 102.657, 112.13, 122.021, 132.329, 143.056, 154.201, 165.764, 177.745, 190.144, 202.96, 216.195, 229.848, 243.918, 258.407, 273.314, 288.638, 304.381, 320.541, 337.12, 354.116, 371.531, 389.363, 407.614, 426.282, 445.368, 464.873, 484.795, 505.135, 525.894}

Vidíme tedy, že faktorizaci prostoru rozhodně nejsme schopni provést pro křížovky vetší než 7*7.

Vytvoření obrázků
---------------------------------------
* Jestli půjde
