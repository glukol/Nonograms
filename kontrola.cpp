#include <iostream>
#include <fstream>
using namespace std;

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
        bool vystup = true;

        ifstream soubor;
        soubor.open(jmeno);

        while(getline(soubor, radek)){
            for (int pocitadlo_i = 2; pocitadlo_i <= radek.length() - 1; pocitadlo_i++){
                if (!spravny_znak(radek[pocitadlo_i])){return false;}
                if (je_mezera(radek[pocitadlo_i]) && (je_mezera(radek[pocitadlo_i - 1]) || je_mezera(radek[pocitadlo_i + 1]))){return false;}
                if ((!je_cislo(radek[1])) || (!je_cislo(radek[radek.length()]))){return false;}
                if (dlouhe_cislo(radek, pocitadlo_i)){return false;}
                if (!vystup){break;}
            }
            if (!vystup){break;}
        }

        soubor.close();
        return vystup;
    }

bool kontrola_zadani(string z_bok, string z_vrch){

    bool korektnost = true;

    korektnost = korektnost && kontrola(z_bok);
    korektnost = korektnost && kontrola(z_vrch);
    return korektnost;
}
