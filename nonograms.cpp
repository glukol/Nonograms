#include "iostream"
#include <fstream>
#include "kontrola.cpp"

using namespace std;


int main(void){

    cout << "Hello! This is a C++ program.\n" << "\n";
    cout << kontrola_zadani("bok.txt", "vrch.txt") << "\n";
    cout << true << "\n";
    return 0;
}