#include "Struktura.h"
#include "Includes.h"
void runDinaminiaiMasyvai(); 
void WithRandomNumbers();
void GenerateRandomNumbersAndNames();
void WithVectors();
void WithRandomNumbersArrays(int);


int main() {
    int choice1;
    int choice2;
    cout << "Pasirinkite programos veikimo buda: " << endl;
    cout << "1 - Su vektoriais" << endl;
    cout << "2 - Su C masyvais" << endl;
    cin >> choice1;

    switch (choice1) {
case 1: 
cout << "1. Viska rasyti ranka/Nuskaityti is failo" << endl;
cout << "2. Generuoti pazymius" << endl;
cout << "3. Generuoti studentus ir pazymius" << endl;
cout << "4. Baigti darba" << endl;
cin >> choice2;

    switch (choice2) {
                case 1:         
                    WithVectors();
                    break;
                case 2:
                    WithRandomNumbers();
                    break;
                case 3: 
                    GenerateRandomNumbersAndNames();
                    break;
                case 4:
                cout << "Darbas baigiamas" << endl;

                break;
                default:
                    cout << "Blogas Pasirinkimas" << endl;
            }
            break;
case 2:
cout << "1. Viska rasyti ranka" << endl;
cout << "2. Generuoti pazymius" << endl;
cout << "3. Generuoti studentus ir pazymius" << endl;
cout << "4. Baigti darba" << endl;
cin >> choice2;

    switch (choice2) {
                case 1:         
                    runDinaminiaiMasyvai();
                    break;
                case 2:
                    WithRandomNumbersArrays(0);
                    break;
                case 3: 
                    WithRandomNumbersArrays(1);
                    break;
                case 4:
                cout << "Darbas baigiamas" << endl;

                break;
                default:
                    cout << "Blogas Pasirinkimas" << endl;
            }



    }
    return 0;
}
