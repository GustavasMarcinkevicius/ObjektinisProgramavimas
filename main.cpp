#include <iostream>
#include "Includes.h"
#include <random>
#include <iomanip>
#include <algorithm>


void runDinaminiaiMasyvai(); 
void WithRandomNumbers();
void GenerateRandomNumbersAndNames();


int main() {
    int choice;
    cout << "Pasirinkite programos veikimo buda: " << endl;
    cout << "1. Viska rasyti ranka" << endl;
    cout << "2. Generuoti pazymius" << endl;
    cout << "3. Generuoti studentus ir pazymius" << endl;
    cout << "4. Baigti darba" << endl;
    cin >> choice;

    switch (choice) {
        case 1:         
            runDinaminiaiMasyvai();
            break;
        case 2:
             WithRandomNumbers();
            break;
        case 3: 
            GenerateRandomNumbersAndNames();
        case 4:
        cout << "Darbas baigiamas" << endl;

        break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
