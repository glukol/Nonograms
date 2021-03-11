
#include "obraceni.cpp"
#include "file_handling.cpp"
#include "dalsi_radek.cpp"

bool zpracuj_zadani(string meno_vstupu_bok, string meno_vstupu_vrch,
    string kvantifikator_jedinecnosti, string a, string b, string c, string prip_bok, string prip_vrch,
    string slozka_moznosti, string pripona_moznosti, string slozka_prepis, string pripona_prepis,
    string slozka_hotove, string pripona_hotove, string pripona_vystup, string soubory){

    int spracovavam_radek;
    char pocitadlo_ch;
    char minim;

    if (kontrola_zadani(soubory + meno_vstupu_bok,soubory + meno_vstupu_vrch)){
        cout << "Vstup nevyhovuje pozadavkam normy!" << '\n';
        return true;
    }

    obraceni_zadani(soubory + meno_vstupu_bok, soubory + meno_vstupu_vrch, soubory + a + prip_bok, soubory + a + prip_vrch);
    obraceni_zadani(soubory + a + prip_bok, soubory + a + prip_vrch, soubory + b + prip_bok, soubory + b + prip_vrch);
    obraceni_zadani(soubory + b + prip_bok, soubory + b + prip_vrch, soubory + c + prip_bok, soubory + c + prip_vrch);

    //nacitani_zadani_krizovky(soubory + meno_vstupu_bok, soubory + meno_vstupu_vrch);
    nacitani_zadani_krizovky(soubory + b + prip_bok, soubory + b + prip_vrch);

    nageneruj_vsechny_moznosti_radku(slozka_moznosti, pripona_moznosti);
    prepis_radka_na_0_1(slozka_moznosti, pripona_moznosti, slozka_prepis, pripona_prepis);
    okupiruj_subor(slozka_prepis + to_string(pocet_radku_krizovky) + pripona_prepis, slozka_hotove + '1' +
        pripona_hotove);

    for (int spracovavam_radek = 2; spracovavam_radek <= pocet_radku_krizovky; spracovavam_radek++){
        cout << spracovavam_radek << "  " << '\n';
        pridej_k_aktualnemu_reseni_dalsi_radek(spracovavam_radek, slozka_hotove, pripona_hotove, slozka_prepis,
            pripona_prepis, soub);
    }

    prepis_vysledku(soubory + kvantifikator_jedinecnosti + pripona_vystup + ".txt", slozka_hotove, pripona_hotove);

    return false;
    //Obrazek(kvantifikator_jedinecnosti + pripona_vystup);
}