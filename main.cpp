#include <iostream>
#include "Includes.h"
#include <random>
#include <iomanip>
#include <algorithm>

int generateRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
};

void runDinaminiaiMasyvai(); 
void WithRandomNumbers();


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
        //code 
        case 4:
        cout << "Darbas baigiamas" << endl;
        
        break;
        default:
            std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
