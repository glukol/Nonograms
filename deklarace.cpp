
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


// konstanty
    string s_m_r = "Moznosti_radku";          // slozka_moznosti_radky
    string p_m_r = "_radek.txt";              // pripona_moznosti_radky
    string s_p_r = "Prepis_radku";            // slozka_prepis_radky
    string p_p_r = "_prepis.txt";             // pripona_prepis_radky

    string s_m_s = "Moznosti_sloupce";          // slozka_moznosti_sloupce
    string p_m_s = "_sloupec.txt";              // pripona_moznosti_sloupce
    string s_p_s = "Prepis_sloupce";            // slozka_prepis_sloupce
    string p_p_s = "_prepis.txt";             // pripona_prepis_sloupce

    string s_h = "Skupiny_radku";           // slozka_hotove
    string p_h = "_skupina.txt";            // pripona_hotove
    string v_p = "vystup";                  // pripona_vystup

    string p_z_b = "_bok.txt";              // pripovna_bok
    string p_z_v = "_vrch.txt";             // pripona_vrch

    string s_m_l = s_m_r + "/";
    string s_p_l = s_p_r + "/";
    string s_h_l = s_h + "/";

    string a = "a";                         // pomocne soubor - obraceni
    string b = "b";                         // pocatek nazvu souboru
    string c = "c";