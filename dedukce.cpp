
void prepis(string puvodni_nazev, string novy_nazev){
	ifstream co_prepisuji;
	ofstream kam_prepisuji;
	string radek;

	co_prepisuji.open(puvodni_nazev);
	kam_prepisuji.open(novy_nazev);

	while (getline(co_prepisuji, radek)){
		kam_prepisuji << radek << '\n';
	}

	co_prepisuji.close();
	kam_prepisuji.close();
}

void dedukce_radky(string pripona_moznosti, string Slozka){

	char radek_dedukce[rozmery];
    ifstream soubor_s_moznostmi;
    string moznost;
    ofstream nove_moznosti;
    bool vyhovuje;
    //int k;

    // Předpokládáme, že máme vyřazené řádky z předešlého kroku, které nevyhovují tomu co jsme už vyřešili.

    for (int radek = 1; radek <= pocet_radku_krizovky; radek++){

		// Okopírujeme si i-tý řádek do pomocné proměnné
        for (int sloupec = 1; sloupec <= pocet_sloupcu_krizovky; sloupec++){
			// rádek ma délku početu sloupců křížovky
            radek_dedukce[sloupec] = Krizovka.pixels[radek][sloupec];
		}

		soubor_s_moznostmi.open(Slozka + '/' + to_string(radek) + pripona_moznosti);

		// Budeme kontrolovat, jestli zbývající možnosti na daný řádek jsou kompatibilní s tím,
		// co jsme do křížovky doplnili v kolmékm směru.

        while (getline(soubor_s_moznostmi, moznost)){

            // Musíme zkontrolovat, zda ta možnost odpovídá tomu co už jsem vyřešili v kolmém směru
            // Pokud jsme na místo zatím nic nedoplnili, je tam napsáno "nevime", jestlliže to má být
			// bílé, je tam "nevybarvene", jestli to má být vybarvené, je tam "vybarvene".

            vyhovuje = true;
            for (int sloupec = 1; sloupec <= pocet_sloupcu_krizovky; sloupec++){
                if ((Krizovka.pixels[radek][sloupec] != nevime) && (moznost[sloupec - 1] !=
						Krizovka.pixels[radek][sloupec])){
                    vyhovuje = false;
				}
			}

            // Tady by se rovno mohly zahazovat ty špatné možnosti.

            if (vyhovuje){
                for (int sloupec = 1; sloupec <= pocet_sloupcu_krizovky; sloupec++){
                    if (radek_dedukce[sloupec] == nevime){
                        radek_dedukce[sloupec] = moznost[sloupec - 1];
					}
                    else if (radek_dedukce[sloupec] != moznost[sloupec - 1]){
                        radek_dedukce[sloupec] = nelze_vydedukovat;
					}
				}
			}
		}
        soubor_s_moznostmi.close();

        // Teď máme v radek_dedukce spočteno, jak vypadá dedukce pro daný řádek.

        for (int sloupec = 1; sloupec <= pocet_sloupcu_krizovky; sloupec++){
            if ((radek_dedukce[sloupec] != nelze_vydedukovat) && (radek_dedukce[sloupec] != nevime)){
				// Nemělo by se stát, že by nějaký prvek radek_dedukce byl "nevime".
                Krizovka.pixels[radek][sloupec] = radek_dedukce[sloupec];
			}
		}

		// Přepsali jsme si to co mají společné možnosti do řešení.
        // Teď musíme ještě přemazat možnosti na řádek - ty které neopovídaly tomu, co jsme vydedukovali
		// v kolmém směru.

        nove_moznosti.open(Slozka + '/' + to_string(radek) + "_docasne" + pripona_moznosti);
        soubor_s_moznostmi.open(Slozka + '/' + to_string(radek) + pripona_moznosti);

        while (getline(soubor_s_moznostmi, moznost)){
            vyhovuje = true;
            for (int sloupec = 1; sloupec <= pocet_sloupcu_krizovky; sloupec++){
                if ((Krizovka.pixels[radek][sloupec] != nevime) && (moznost[sloupec - 1] !=
						Krizovka.pixels[radek][sloupec])){
                    vyhovuje = false;
				}
			}
            if (vyhovuje){
                nove_moznosti << moznost << '\n';
			}
		}

        soubor_s_moznostmi.close();
        nove_moznosti.close();

		prepis(Slozka + '/' + to_string(radek) + "_docasne" + pripona_moznosti,
			Slozka + '/' + to_string(radek) + pripona_moznosti);

	}
}

void vypsani_dedukce(string slozka, string jmeno){
  	ofstream vystup;
    vystup.open(slozka + "vystup_" + jmeno + ".txt");

    for (int radek = 1; radek <= pocet_radku_krizovky; radek++){
      	for (int sloupec = 1; sloupec <= pocet_sloupcu_krizovky; sloupec++){
        	if (Krizovka.pixels[radek][sloupec] == nevime){
           		vystup << '?';
			}
        	else if (Krizovka.pixels[radek][sloupec] == nevybarvene){
            	vystup << 'X';
			}
            else if (Krizovka.pixels[radek][sloupec] == vybarvene){
                vystup << 'C';
			}
		}
      	vystup << '\n';
	}
    vystup.close();
}

void vynulovani_krizovky(mrizka_zadani &co_mam_vynulovat, char cim){
    for (int radek = 0; radek < rozmery; radek++){
      	for (int sloupec = 0; sloupec < rozmery; sloupec++){
		    co_mam_vynulovat.pixels[radek][sloupec] = cim;
		}
	}
}

/*void reflexe_zadani(){
	// Prostě stačí přejmenovat vrch.txt na bok.txt a naopak.
    int pomocna = pocet_sloupcu_krizovky;
    pocet_sloupcu_krizovky = pocet_radku_krizovky;
    pocet_radku_krizovky = pomocna;
}*/

void reflexe_reseni(){
	char pomocna;

	if (pocet_radku_krizovky < pocet_sloupcu_krizovky){
     	for (int radek = 1; radek <= pocet_radku_krizovky; radek++){
            for (int sloupec = radek; sloupec <= pocet_sloupcu_krizovky; sloupec++){
                pomocna = Krizovka.pixels[radek][sloupec];
                Krizovka.pixels[radek][sloupec] = Krizovka.pixels[sloupec][radek];
                Krizovka.pixels[sloupec][radek] = pomocna;
			}
		}
	}
    else{
    	for (int sloupec = 1; sloupec <= pocet_sloupcu_krizovky; sloupec++){
            for (int radek = sloupec; radek <= pocet_radku_krizovky; radek++){
                pomocna = Krizovka.pixels[radek][sloupec];
                Krizovka.pixels[radek][sloupec] = Krizovka.pixels[sloupec][radek];
                Krizovka.pixels[sloupec][radek] = pomocna;
			}
		}
	}

    // Pozor na nečtvercové křižovky !

    pomocna = pocet_sloupcu_krizovky;
    pocet_sloupcu_krizovky = pocet_radku_krizovky;
    pocet_radku_krizovky = pomocna;
}

bool reseni_pomoci_dedukce(string meno_vstupu_bok, string meno_vstupu_vrch, string slozka_moznosti_radky,
	string pripona_moznosti_radky, string slozka_prepis_radky, string pripona_prepis_radky,
	string slozka_moznosti_sloupce, string pripona_moznosti_sloupce, string slozka_prepis_sloupce,
	string pripona_prepis_sloupce, string slozka){

    if (kontrola_zadani(meno_vstupu_bok, meno_vstupu_vrch)){
        cout << "Vstup nevyhovuje pozadavkam normy!" << '\n';
        return true;
	}

    vynulovani_krizovky(Krizovka, nevime);

    nacitani_zadani_krizovky(meno_vstupu_bok, meno_vstupu_vrch);
    nageneruj_vsechny_moznosti_radku(slozka_moznosti_radky, pripona_moznosti_radky);
    prepis_radka_na_0_1(slozka_moznosti_radky, pripona_moznosti_radky, slozka_prepis_radky, pripona_prepis_radky);

    nacitani_zadani_krizovky(meno_vstupu_vrch, meno_vstupu_bok);
    nageneruj_vsechny_moznosti_radku(slozka_moznosti_sloupce, pripona_moznosti_sloupce);
    prepis_radka_na_0_1(slozka_moznosti_sloupce, pripona_moznosti_sloupce, slozka_prepis_sloupce, pripona_prepis_sloupce);

    for (int iterace = 1; iterace <= 18;  iterace++){

        //nacitani_zadani_krizovky(meno_vstupu_bok, meno_vstupu_vrch);
        dedukce_radky(pripona_prepis_radky, slozka_prepis_radky);

        vypsani_dedukce(slozka, to_string(2 * iterace - 1));
        //obrazek_dedukce(2 * iterace - 1, to_string(2 * iterace - 1) + "_obr.bmp");
        reflexe_reseni();

        //nacitani_zadani_krizovky(meno_vstupu_vrch, meno_vstupu_bok);
        dedukce_radky(pripona_prepis_sloupce, slozka_prepis_sloupce);
        reflexe_reseni();

        vypsani_dedukce(slozka, to_string(2 * iterace));
        //obrazek_dedukce(2*i,inttostr(2*i)+'_obr.bmp');
	}

	return false;
}