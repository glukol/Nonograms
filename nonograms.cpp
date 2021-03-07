#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#include "deklarace.cpp"
#include "zpracuj_zadani.cpp"

/*#include "kontrola.cpp"
#include "obraceni.cpp"
#include "nacti_zadani.cpp"
#include "generace_moznosti.cpp"
#include "file_handling.cpp"
#include "dalsi_radek.cpp"*/

int main(void){

    string jmeno_vstupu_bok = "bok.txt";
    string jmeno_vstupu_vrch = "vrch.txt";
    zpracuj_zadani(jmeno_vstupu_bok, jmeno_vstupu_vrch, "", a, b, c, p_z_b,
        p_z_v, s_m_l, p_m_r, s_p_l, p_p_r, s_h_l, p_h, v_p);

    //cout << "Hello! This is a C++ program." << "\n";
    //cout << kontrola_zadani("bok.txt", "vrch.txt") << "\n";
    //obraceni_zadani("bok.txt", "vrch.txt", "a_bok.txt", "a_vrch.txt");
    //nacitani_zadani_krizovky("bok.txt", "vrch.txt");
    //nageneruj_vsechny_moznosti_radku("moznosti", "_moznost.txt");
    //prepis_radka_na_0_1("moznosti", "_moznost.txt", "prepis", "_prepis.txt");
    //cout << pocet_radku_krizovky;

    //for (int radek = 2; radek <= pocet_radku_krizovky; radek++){
    //    pridej_k_aktualnemu_reseni_dalsi_radek(radek, "radky", "_radek.txt", "prepis", "_prepis.txt");
    //}

    return 0;
}
