#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

// Soubor s deklarací globálních proměnných
#include "deklarace.cpp"

// Soubory s pomocnými metodami, společnými pro obě verze řešení
#include "kontrola.cpp"
#include "nacti_zadani.cpp"
#include "obraceni.cpp"
#include "generace_moznosti.cpp"

// Soubory se samotnými metodami řešení
#include "zpracuj_zadani.cpp"
#include "dedukce.cpp"


int main(void){

    string jmeno_vstupu_bok = "21_bok.txt";
    string jmeno_vstupu_vrch = "21_vrch.txt";

    obraceni_zadani("Soubory/" + jmeno_vstupu_bok, "Soubory/" + jmeno_vstupu_vrch, "Soubory/" + a + p_z_b, "Soubory/" + a + p_z_v);
    obraceni_zadani("Soubory/" + a + p_z_b, "Soubory/" + a + p_z_v, "Soubory/" + b + p_z_b, "Soubory/" + b + p_z_v);
    obraceni_zadani("Soubory/" + b + p_z_b, "Soubory/" + b + p_z_v, "Soubory/" + c + p_z_b, "Soubory/" + c + p_z_v);

    //nacitani_zadani_krizovky("Soubory/" + jmeno_vstupu_bok, "Soubory/" + jmeno_vstupu_vrch);

    jmeno_vstupu_bok = "a_bok.txt";
    jmeno_vstupu_vrch = "a_vrch.txt";

    reseni_pomoci_dedukce("Soubory/" + jmeno_vstupu_bok, "Soubory/" + jmeno_vstupu_vrch, s_m_r, p_m_r, s_p_r,
        p_p_r, s_m_s, p_m_s, s_p_s, p_p_s, "Dedukce/");

    zpracuj_zadani(jmeno_vstupu_bok, jmeno_vstupu_vrch, "", a, b, c, p_z_b,
        p_z_v, s_m_l, p_m_r, s_p_l, p_p_r, s_h_l, p_h, v_p, soub);
    //cout << '\n';

    return 0;
}
