
const int rozmery = 500;
const char vybarvene = '1';
const char nevybarvene = '0';
const char konec = 'K';
const int zavirani_souboru = 1000;

class mrizka_zadani
{
public:
    char pixels[2*rozmery][rozmery];
};

int pocet_sloupcu_krizovky;
int pocet_radku_krizovky;

mrizka_zadani Zadani_bok, Zadani_vrch;
mrizka_zadani Krizovka;