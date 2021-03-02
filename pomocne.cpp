
    int cislo(char znak){
        return int(znak) - 48;
    }

    bool nacti_hotovou_k_tici_radku(ifstream &Soubor, int poradi_noveho_radka){

        char znak;

        for (int pocitadlo_k = 1; pocitadlo_k <= poradi_noveho_radka - 1; pocitadlo_k++){
            for (int pocitadlo_i = 1; pocitadlo_i <= pocet_sloupcu_krizovky; pocitadlo_i++){
                if (!(Soubor >> znak)){return false;}
                else{
                    Krizovka.pixels[pocet_radku_krizovky - poradi_noveho_radka + 1 + pocitadlo_k + rozmery][pocitadlo_i] = znak;
                }
            }
            //Soubor >> znak;     // zakomentuj pro binarni soubory
        }
        return true;
    }

    void okopiruj_posledni_radek_do_(string &Zaloha_stinu_noveho_radku, int poradi_noveho_radka){

        Zaloha_stinu_noveho_radku = "";
        for (int pocitadlo_i = 1; pocitadlo_i <= pocet_sloupcu_krizovky; pocitadlo_i++){
                Zaloha_stinu_noveho_radku += Krizovka.pixels[pocet_radku_krizovky - poradi_noveho_radka + 1 + rozmery][pocitadlo_i];
            }
    }

    void vyjednotkuj_prvni_radek(){

        for (int pocitadlo_i = 1; pocitadlo_i <= pocet_sloupcu_krizovky; pocitadlo_i++){
            Krizovka.pixels[1 + rozmery][pocitadlo_i] = vybarvene;
        }
    }

    void prilep_novy_radek_do_krizovky(string radek, int poradi_noveho_radka){

        for (int pocitadlo_i = 1; pocitadlo_i <= pocet_sloupcu_krizovky; pocitadlo_i++){
            Krizovka.pixels[pocet_radku_krizovky - poradi_noveho_radka + 1 + rozmery][pocitadlo_i] = radek[pocitadlo_i];
        }

    }

    void vypis_k_plus_jedna_tice_do_noveho_souboru(ofstream &Soubor, string radek, int poradi_noveho_radka){

        int pocitadlo_i, pocitadlo_k;

        Soubor << radek << '\n';            // zakomentuj pro binarni soubory

        for (int pocitadlo_i = pocet_radku_krizovky - poradi_noveho_radka + 2; pocitadlo_i <= pocet_radku_krizovky; pocitadlo_i++){

            for (int pocitadlo_k = 1; pocitadlo_k <= pocet_sloupcu_krizovky; pocitadlo_k++){
                Soubor << Krizovka.pixels[pocitadlo_i + rozmery][pocitadlo_k];
            }

            Soubor << '\n';            // zakomentuj pro binarni soubory

        }
    }

    bool novy_radek_pasuje_ke_k_tici(string radek, string zaloha, int poradi_noveho_radka){

        for (int sloupec = 1; sloupec <= pocet_sloupcu_krizovky; sloupec++){

            if ((zaloha[sloupec] == vybarvene) && (radek[sloupec] != vybarvene)){
                return false; // radek nepasuje
                // protože doplnění je jiné než řádek - v obarvených políčkách
                // první možnost je, že máme rozmalovanou nějakou k-tici a tu jsme prodloužili
                // druhá je, že máme v tom sloupci ještě namalovat další k-tici, nová k-tice není
                // začatá, ale kdyby se nezačínala na dalším políčku, tak už by se ten zbytek nevešel
                // do křížovky, také dostaneme doplněním.
            }

            if ((zaloha[sloupec] != vybarvene) && (radek[sloupec] == vybarvene) &&
                (Krizovka.pixels[pocet_radku_krizovky - poradi_noveho_radka + 2 + rozmery][sloupec] == vybarvene)){
                return false; // opět řádek nepasuje
                // načetli jsme hotovou k-tici, pak jsme provedli doplnění, tak jak by to dělal člověk,
                // to dolpnění jsme si uložili, do "zaloha", pak jsme načetli novou možnost, která se teď
                // nachází v "radek". Koukáme se na doplňovaný řádek a na předešlý v křížovce. Pokud pak
                // doplňující metoda nedoplnila obarvené políčku v novém řádku, tak tam musí být mezera,
                // protože vybarvená k-tice skončila.
            }

            if  ((radek[sloupec] == vybarvene) && (zaloha[sloupec] == konec)){
                return false; // řádek opět nepasuje
                // Stane se, že doplnění už vyplnilo všechny obarnevé k-tice do křížovky a už zbývají jen
                // nezery, takovéto mezery nejsou značeny jako "nevybarvene", ale jako "konec". Proto, když
                // se stane, že nový řádek je vybarvený, tak je to špatně.
            }
        }

        // Když nenastane žádná z těchto možností, tak necháme řádek projít touto kontrolou.
        // Ale pouze, když projde na všech políčkách.
        return true;
    }

    bool novy_radek_pasuje_k_doplneni(string radek, int poradi_noveho_radka){

        for (int sloupec = 1; sloupec <= pocet_sloupcu_krizovky; sloupec++){
            if ((Krizovka.pixels[pocet_radku_krizovky - poradi_noveho_radka + 1 + rozmery][sloupec] != vybarvene) &&
                (radek[sloupec] == vybarvene)){
                return false;
                // radek z možností jsme nalepili do křížovky a spustili jsme znova metodu doplnění, kontrolujeme
                // jestli se v tom řádku nic nezměnilo. Ale co se mohlo změnit? Bílá na černou se změnit nemůže,
                // protože to se může stát jen v případě, že se prodlužuje k-tice, nebo, že se ten zbytek barevných
                // nevleze už jinak do křížovky. Ale může se stát, že se černá přebarví na bílou, když to má být
                // konec nějaké k-tice, ptrotože tuto situaci jsme zatím nekontrolovali. Kontrolovali jsme už, že
                // se tam v takovém případě nic nedoplnilo, ale nikoliv, zda když tam řádek přidal černou, zda tam
                // skutečně pasuje.

                // Asi bychom nepotřebovali, pokud by sme tam měli správně napsané ty konce.
                }
        }

        return true;
    }

    void vynuluj_radek(int poradi_noveho_radka){
        for (int pocitadlo_i = 1; pocitadlo_i <= pocet_sloupcu_krizovky; pocitadlo_i++){
            Krizovka.pixels[pocet_radku_krizovky - poradi_noveho_radka + 1 + rozmery][pocitadlo_i] = nevybarvene;
        }
    }
