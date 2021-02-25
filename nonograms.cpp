#include "iostream"
#include <fstream>
using namespace std;

        bool cislo(char znak){
            return (int(znak) - 48 >= 0) && (int(znak) - 48 <= 9);
        }
        bool mezera(char znak){
            return znak == ' ';
        }

        bool spravny_znak(char znak){
            bool vystup;

            vystup = (int(znak) - 48 >= 0) && (int(znak) - 48 <= 9);
            vystup = vystup || (znak == ' ');
            return vystup;
        }

        bool dlouhe_cislo(string radek, int pozice){
            if (pozice < 3){return false;}
            else {return cislo(radek[pozice]) && cislo(radek[pozice - 1]) && cislo(radek[pozice - 2]);}
        }

    bool kontrola(string jmeno){

        //int pocitadlo_i;
        string radek;
        bool vystup = true;

        ifstream soubor;
        soubor.open(jmeno);

        while(getline(soubor, radek)){
            for (int pocitadlo_i = 2; pocitadlo_i <= radek.length() - 1; pocitadlo_i++){
                if (not spravny_znak(radek[pocitadlo_i])){return false;}
                if (mezera(radek[pocitadlo_i]) && (mezera(radek[pocitadlo_i - 1]) || mezera(radek[pocitadlo_i + 1]))){return false;}
                if ((not cislo(radek[1])) or (not cislo(radek[radek.length()]))){return false;}
                if (dlouhe_cislo(radek, pocitadlo_i)){return false;}
                if (not vystup){break;}
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


int main(void){

    cout << "Hello! This is a C++ program.\n" << "\n";
    cout << kontrola_zadani("bok.txt", "vrch.txt") << "\n";
    cout << true << "\n";
    return 0;
}