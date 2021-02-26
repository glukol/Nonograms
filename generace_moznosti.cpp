
const int vybarvene = 1;
const int nevybarvene = 0;

    void Rozdel_mezery(int zbyvajicich_useku, int zbyvajicich_mezer, int useku, string Prefix, ofstream &Soubor){

        int pocitadlo_i;
        string pridavana_mezera;
        int kolik_useku_sme_uz_vyrobili;
        int dolni_mez;

        kolik_useku_sme_uz_vyrobili = (useku + 1) - zbyvajicich_useku + 1;
        if (kolik_useku_sme_uz_vyrobili < useku + 1){

            // Jeslize jsme na zacatku nebo na koci radku povoluji se mezery s nulovou delkou,
            // jinak museji byt alespon delky jedna jinak by totiz neoddelovali vybarvene useky.

            if (zbyvajicich_useku == useku){
                dolni_mez = 0;
                }
            else{
                dolni_mez = 1;
                }

            for (int pocitadlo_i = dolni_mez; pocitadlo_i <= zbyvajicich_mezer; pocitadlo_i++){

                pridavana_mezera = to_string(pocitadlo_i); // str(pocitadlo_i, pridavana_mezera);
                Rozdel_mezery(zbyvajicich_useku - 1, zbyvajicich_mezer - pocitadlo_i, useku, Prefix + ' ' + pridavana_mezera, Soubor);
            }
        }
        else{
            Soubor << Prefix << ' ' << to_string(zbyvajicich_mezer) << '\n';
        }
    }


void nageneruj_vsechny_moznosti_radku(string Slozka, string pripona){

    ofstream Soubor_s_rozdelenimi;
    int pocet_useku_v_radku;

    int pocitadlo_i, pocitadlo_k;
    int Pocet_vybarvenych_useku_v_danem_radku;
    int Pocet_mezer_v_danem_radku;

    for (int pocitadlo_i = 1; pocitadlo_i <= pocet_radku_krizovky; pocitadlo_i ++){

        Pocet_vybarvenych_useku_v_danem_radku = Zadani_bok.pixels[pocitadlo_i][0];
        Pocet_mezer_v_danem_radku = pocet_sloupcu_krizovky;
        for (int pocitadlo_k = 1; pocitadlo_k <= Pocet_vybarvenych_useku_v_danem_radku; pocitadlo_k++){
            Pocet_mezer_v_danem_radku = Pocet_mezer_v_danem_radku - Zadani_bok.pixels[pocitadlo_i][pocitadlo_k];
        }

        Soubor_s_rozdelenimi.open(Slozka + '/' + to_string(pocitadlo_i) + pripona);

        Soubor_s_rozdelenimi << to_string(Pocet_vybarvenych_useku_v_danem_radku + 1) << '\n';

        pocet_useku_v_radku = Pocet_vybarvenych_useku_v_danem_radku + 1;
        Rozdel_mezery(Pocet_vybarvenych_useku_v_danem_radku + 1, Pocet_mezer_v_danem_radku, pocet_useku_v_radku, "", Soubor_s_rozdelenimi);

        Soubor_s_rozdelenimi.close();
    }

}


void prepis_radka_na_0_1(string slozka_vstup, string pripona_vstup, string slozka_vystup, string pripona_vystup){

    int pocitadlo_i, pocitadlo_k, pocitadlo_l;
    ifstream Citaci_soubor;
    ofstream Vypisovaci_soubor;
    int pocet_moznosti_radku;
    int delka_mezery;

    for (int pocitadlo_i = 1; pocitadlo_i <= pocet_radku_krizovky; pocitadlo_i++){

        Citaci_soubor.open(slozka_vstup +'/'+ to_string(pocitadlo_i) + pripona_vstup);
        Vypisovaci_soubor.open(slozka_vystup +'/'+ to_string(pocitadlo_i) + pripona_vystup);

        Citaci_soubor >> pocet_moznosti_radku;
        while (Citaci_soubor >> delka_mezery){

            for (int pocitadlo_k = 1; pocitadlo_k <= pocet_moznosti_radku; pocitadlo_k++){
                for (int pocitadlo_l = 1; pocitadlo_l <= delka_mezery; pocitadlo_l++){
                    Vypisovaci_soubor << nevybarvene;
                }
                if (pocitadlo_k != pocet_moznosti_radku){
                    for (int pocitadlo_l = 1; pocitadlo_l <= Zadani_bok.pixels[pocitadlo_i][pocitadlo_k]; pocitadlo_l++){
                        Vypisovaci_soubor << vybarvene;
                    }
                }
                if (pocitadlo_k < pocet_moznosti_radku){
                    Citaci_soubor >> delka_mezery;
                    }
            }

            Vypisovaci_soubor << '\n';    // zakomentuj pro binarni soubory
        }

        Vypisovaci_soubor.close();
        Citaci_soubor.close();
    }
}
