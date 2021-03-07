//#include <iostream>
//#include <sstream>
//#include <fstream>
//using namespace std;
//#include "deklarace.cpp"

//    int cislo(char znak){
//        return int(znak) - 48;
//    }

	void spracovani_bok(int hranice_1, int hranice_2, string jmeno){

		ofstream textak;
		textak.open(jmeno);

		for (int pocitadlo_i = hranice_1; pocitadlo_i <= hranice_2; pocitadlo_i++){
			for (int pocitadlo_k = 1; pocitadlo_k <= cislo(Zadani_bok.pixels[pocitadlo_i][0]); pocitadlo_k++){
				textak << Zadani_bok.pixels[pocitadlo_i, pocitadlo_k];
				if (pocitadlo_k < Zadani_bok.pixels[pocitadlo_i][0]){
					textak << ' ';
				}
			}
			if (pocitadlo_i != hranice_2){
				textak << '\n';
			}
		}

		textak.close();
	}

	void spracovani_vrch(int hranice_1, int hranice_2, string jmeno){

		int delka_useku;
		string pomocny_string;
		ofstream textak;
		textak.open(jmeno);

		for (int pocitadlo_i = 1; pocitadlo_i <= pocet_sloupcu_krizovky; pocitadlo_i++){

			pomocny_string = "";
			delka_useku = 0;

			for (int pocitadlo_k = hranice_1; pocitadlo_k <= hranice_2; pocitadlo_k++){
				if (Krizovka.pixels[pocitadlo_k][pocitadlo_i] = vybarvene){
					delka_useku++;
				}
				else if (delka_useku != 0){
					pomocny_string = pomocny_string + to_string(delka_useku) + ' ';
					delka_useku = 0;
				}
			}

			if (delka_useku != 0){
				pomocny_string = pomocny_string + to_string(delka_useku) + ' ';
				delka_useku = 0;
			}

			for (int i = 0; i < pomocny_string.length(); i++){
				textak << pomocny_string[i];
				//textak << LeftStr(pomocny_string,length(pomocny_string)-1));
			}

			if (pocitadlo_i != pocet_sloupcu_krizovky){
				textak << '\n';
			}
		}

		textak.close();
	}

void rozrezani_zadani(string jmeno_noveho_zadani_bok_a, string jmeno_noveho_zadani_vrch_a, string jmeno_noveho_zadani_bok_b,
	string jmeno_noveho_zadani_vrch_b, int poradi_posledniho_radka){

	int maximum = pocet_radku_krizovky - poradi_posledniho_radka;

	spracovani_bok(1, maximum, jmeno_noveho_zadani_bok_b);
	spracovani_bok(maximum + 1, pocet_radku_krizovky, jmeno_noveho_zadani_bok_a);

	iterace_na_sloupce();

	spracovani_vrch(1, maximum, jmeno_noveho_zadani_vrch_b);
	spracovani_vrch(maximum + 1, pocet_radku_krizovky, jmeno_noveho_zadani_vrch_a);
}

void kontrola_rezani_zadani(int poradi_noveho_radka, string meno_souboru_s_moznostmi){

	char ch;
	int pocitadlo_moznosti;
	int pocitadlo_radku, pocitadlo_sloupcu;
	ifstream soubor_s_moznostmi;
	soubor_s_moznostmi.open(meno_souboru_s_moznostmi);

	// kontrola poctu moznosti - spočteme kolik tam těch možností vlastně je

	pocitadlo_moznosti = 0;
	while (soubor_s_moznostmi >> ch){

		pocitadlo_moznosti++;

		for (pocitadlo_radku = 1; pocitadlo_radku <= pocet_radku_krizovky; pocitadlo_radku++){
			for (pocitadlo_sloupcu = 1; pocitadlo_sloupcu <= pocet_sloupcu_krizovky; pocitadlo_sloupcu++){
				soubor_s_moznostmi >> ch;
			}
			//readln(soubor_s_moznostmi);  // zakomentuj pro binarni soubory
		}
	}
	soubor_s_moznostmi.close();

	// znovunacteni zadani

	soubor_s_moznostmi.open(meno_souboru_s_moznostmi);
	while (soubor_s_moznostmi >> ch){

		for (pocitadlo_radku = 1; pocitadlo_radku <= poradi_noveho_radka; pocitadlo_radku++){
			for (pocitadlo_sloupcu = 1; pocitadlo_sloupcu <= pocet_sloupcu_krizovky; pocitadlo_sloupcu++){
				Krizovka.pixels[pocet_radku_krizovky-poradi_noveho_radka + pocitadlo_radku][pocitadlo_sloupcu] = ch;
				soubor_s_moznostmi >> ch;
			}
			//soubor_s_moznostmi >> ch;  // zakomentuj pro binarni soubory
		}
	}
	soubor_s_moznostmi.close();

	// spravne by sme jeste mely nacist toto reseni aby sme prepsali
	// pripadny balast ktery se muze nachazet v krizovce programu

	if (pocitadlo_moznosti == 1){
		rozrezani_zadani("Novy_bok_a.txt", "Novy_vrch_a.txt", "Novy_bok_b.txt", "Novy_vrch_b.txt",
			poradi_noveho_radka);

	}
}