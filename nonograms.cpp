#include <iostream>
#include <fstream>
using namespace std;


#include "kontrola.cpp"
#include "obraceni.cpp"


int main(void){

    cout << "Hello! This is a C++ program.\n" << "\n";
    cout << kontrola_zadani("bok.txt", "vrch.txt") << "\n";
    cout << true << "\n";
    obraceni_zadani("bok.txt", "vrch.txt", "a_bok.txt", "a_vrch.txt");
    return 0;
}
