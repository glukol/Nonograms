#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

// Soubor s deklarací globálních proměnných
#include "deklarace.cpp"

// Soubory s pomocnými metodami, společnými pro obě verze řešení
#include "kontrola.cpp"
#include "nacti_zadani.cpp"
#include "generace_moznosti.cpp"

// Soubory se samotnými metodami řešení
#include "zpracuj_zadani.cpp"
#include "dedukce.cpp"


int main(void){

    string jmeno_vstupu_bok = "bok.txt";
    string jmeno_vstupu_vrch = "vrch.txt";

    zpracuj_zadani(jmeno_vstupu_bok, jmeno_vstupu_vrch, "", a, b, c, p_z_b,
        p_z_v, s_m_l, p_m_r, s_p_l, p_p_r, s_h_l, p_h, v_p, soub);
    //cout << '\n';

    reseni_pomoci_dedukce("Soubory/" + jmeno_vstupu_bok, "Soubory/" + jmeno_vstupu_vrch, s_m_r, p_m_r, s_p_r,
        p_p_r, s_m_s, p_m_s, s_p_s, p_p_s, "Dedukce/");

    return 0;
}
