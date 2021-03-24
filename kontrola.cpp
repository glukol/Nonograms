
        bool je_cislo(char znak){
            return (int(znak) - 48 >= 0) && (int(znak) - 48 <= 9);
        }
        bool  je_mezera(char znak){
            return znak == ' ';
        }

        bool spravny_znak(char znak){
            return je_cislo(znak) ||  je_mezera(znak);
        }

        bool dlouhe_cislo(string radek, int pozice){
            if (pozice < 3){return false;}
            else {return je_cislo(radek[pozice]) && je_cislo(radek[pozice - 1]) && je_cislo(radek[pozice - 2]);}
        }

    bool kontrola(string jmeno){

        //int pocitadlo_i;
        string radek;
        int cislo_radka = 0;
        //bool vystup = true;

        ifstream soubor;
        soubor.open(jmeno);

        while(getline(soubor, radek)){
            cislo_radka++;
            //cout << radek.length() << '\n';
            for (int pocitadlo_i = 2; pocitadlo_i <= radek.length() - 1; pocitadlo_i++){
                if (!spravny_znak(radek[pocitadlo_i])){
                    cout << "A " << jmeno << ", radek " << to_string(cislo_radka) << ", znak = \"" << radek[pocitadlo_i] << "\"" << '\n';
                    return true;
                }
                else if (je_mezera(radek[pocitadlo_i]) && (je_mezera(radek[pocitadlo_i - 1]) || je_mezera(radek[pocitadlo_i + 1]))){
                    cout << "B " << jmeno << ", radek " << to_string(cislo_radka) << ", znak = \"" << radek[pocitadlo_i] << "\"" << '\n';
                    return true;
                }
                else if ((!je_cislo(radek[0])) || (!je_cislo(radek[radek.length() - 1]))){
                    cout << "C " << jmeno << ", radek " << to_string(cislo_radka) << ", znak = \"" << radek[radek.length() - 2] << "\"" << '\n';
                    //cout << radek << '\n';
                    //cout << radek.length() << '\n';
                    return true;
                }
                else if (dlouhe_cislo(radek, pocitadlo_i)){
                    cout << "D " << jmeno << ", radek " << to_string(cislo_radka) << ", znak = \"" << radek[pocitadlo_i] << "\"" << '\n';
                    return true;
                }
                //else if (!vystup){break;}
            }
            //if (!vystup){break;}
            radek = "";
        }

        soubor.close();
        return false;
    }

bool kontrola_zadani(string z_bok, string z_vrch){

    bool korektnost = true;

    korektnost = korektnost && kontrola(z_bok);
    korektnost = korektnost && kontrola(z_vrch);
    return korektnost;
}
