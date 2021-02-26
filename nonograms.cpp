#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#include "deklarace.cpp"
#include "kontrola.cpp"
#include "obraceni.cpp"
#include "nacti_zadani.cpp"

int main(void){

    cout << "Hello! This is a C++ program.\n" << "\n";
    cout << kontrola_zadani("bok.txt", "vrch.txt") << "\n";
    cout << true << "\n";
    obraceni_zadani("bok.txt", "vrch.txt", "a_bok.txt", "a_vrch.txt");
    nacitani_zadani_krizovky("bok.txt", "vrch.txt");
    return 0;
}
