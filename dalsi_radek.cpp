#include <iostream> //iostream
#include <sstream>
#include <fstream>
using namespace std;

#include "pomocne.cpp"
#include "iterace.cpp"
//#include "deklarace.cpp"
#include "rezani.cpp"

// iterace na sloupce a posun momentálně šahají mimo pole, proto to nefunguje

    void pridej_k_aktualnemu_reseni_dalsi_radek(int poradi_noveho_radka, string slozka_pracovna, string pripona_pracovna, string slozka_moznosti_radka, string pripona_moznosti, string slozka){
        //typ_zalohy = array[1..rozmery] of barveni;

        ifstream Soubor_s_hotovymi_k_ticemi;
        ifstream Moznosti_noveho_radka;
        ofstream Soubor_s_hotovymi_k_plus_jedna_ticemi;
        string Zaloha_stinu_noveho_radku;
        string radek;
        int pocitadlo_zavirani_souboru;
        int pocitadlo_i;

        string jmeno_k = slozka_pracovna  + '/' + to_string(poradi_noveho_radka - 1) + pripona_pracovna;
        string jmeno_kpj = slozka_pracovna + '/' + to_string(poradi_noveho_radka) + pripona_pracovna;
        string jmeno_nove = slozka_moznosti_radka + '/' + to_string(pocet_radku_krizovky - poradi_noveho_radka + 1) + pripona_moznosti;

        Soubor_s_hotovymi_k_ticemi.open(jmeno_k);
        Soubor_s_hotovymi_k_plus_jedna_ticemi.open(jmeno_kpj);

        Soubor_s_hotovymi_k_plus_jedna_ticemi.close();
        //Soubor_s_hotovymi_k_plus_jedna_ticemi.open(jmeno_kpj, std::ios_base::app);;

        pocitadlo_zavirani_souboru = 0;
        while (nacti_hotovou_k_tici_radku(Soubor_s_hotovymi_k_ticemi, poradi_noveho_radka)){
            if (pocitadlo_zavirani_souboru == 0){
                Soubor_s_hotovymi_k_plus_jedna_ticemi.open(jmeno_kpj, std::ios_base::app);
            }

            Moznosti_noveho_radka.open(jmeno_nove);
            vynuluj_radek(poradi_noveho_radka);
            vyjednotkuj_prvni_radek();
            iterace_na_sloupce();
            okopiruj_posledni_radek_do_(Zaloha_stinu_noveho_radku, poradi_noveho_radka);

            char temp;
            radek = "";
            while (Moznosti_noveho_radka >> temp){
                radek += temp;

                vyjednotkuj_prvni_radek();
                for (int pocitadlo_i = 2; pocitadlo_i <= pocet_sloupcu_krizovky; pocitadlo_i++){
                    Moznosti_noveho_radka >> temp;
                    radek += temp;
                }
                //readln(Moznosti_noveho_radka);  // zakomentuj pro binarni soubory

                if (novy_radek_pasuje_ke_k_tici(radek, Zaloha_stinu_noveho_radku, poradi_noveho_radka)){

                    prilep_novy_radek_do_krizovky(radek, poradi_noveho_radka);
                    iterace_na_sloupce();


                    if (novy_radek_pasuje_k_doplneni(radek, poradi_noveho_radka)){
                        vypis_k_plus_jedna_tice_do_noveho_souboru(Soubor_s_hotovymi_k_plus_jedna_ticemi, radek, poradi_noveho_radka);
                    }
                }

                radek = "";
            }

            Moznosti_noveho_radka.close();

            if (pocitadlo_zavirani_souboru == zavirani_souboru){
                Soubor_s_hotovymi_k_plus_jedna_ticemi.close();
                pocitadlo_zavirani_souboru = 0;
            }
            else{
                pocitadlo_zavirani_souboru++;
            }
        }

        Soubor_s_hotovymi_k_ticemi.close();
        Soubor_s_hotovymi_k_plus_jedna_ticemi.close();

        //if (!(pocitadlo_zavirani_souboru == 0)){
        //    Soubor_s_hotovymi_k_plus_jedna_ticemi.close();
        //}
        // wata fuck ???

        kontrola_rezani_zadani(poradi_noveho_radka, slozka_pracovna + to_string(poradi_noveho_radka) + pripona_pracovna, slozka);

    }

