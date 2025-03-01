#include "Includes.h"
#include <random>
#include <iomanip>
#include <algorithm>



void GenerateRandomNumbersAndNames()


{

    
#include "Struktura.h"
    vector<Studentas> studentai;
    int StudentuKiekis;

    cout << "Iveskite studentu skaiciu "; cin >> StudentuKiekis;
    cout << "st " << StudentuKiekis << endl;

   for (int o =0; o < StudentuKiekis; o++){

        Studentas studentas;
            studentas.vardas = generateRandomName();
            studentas.pavarde = generateRandomSurname();

            int pazymiuKiekis = generateRandomNumber(3, 10);
         
            for (int i = 0; i < pazymiuKiekis; i++) {
                int pazymis = generateRandomNumber(1, 10);
              
                studentas.pazymiai.push_back(pazymis);

            }
        

        studentas.egzaminoPazimys = generateRandomNumber(1, 10);
        studentai.push_back(studentas);
      
        };
  

    cout << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (const auto& studentas : studentai) {
        double Vidurkis = 0;
        double Mediana = 0;

        if (!studentas.pazymiai.empty()) {
            for (int pazymys : studentas.pazymiai) {
                Vidurkis += pazymys;
            }
            Vidurkis /= studentas.pazymiai.size();

            vector<int> sortedGrades = studentas.pazymiai;
            sort(sortedGrades.begin(), sortedGrades.end());

            if (sortedGrades.size() % 2 == 0) {
                Mediana = (sortedGrades[sortedGrades.size() / 2 - 1] + sortedGrades[sortedGrades.size() / 2]) / 2.0;
            } else {
                Mediana = sortedGrades[sortedGrades.size() / 2];
            }
        }

        double GalutinisBalasVidurkis = 0.4 * Vidurkis + 0.6 * studentas.egzaminoPazimys;
        double GalutinisBalasMediana = 0.4 * Mediana + 0.6 * studentas.egzaminoPazimys;

        cout << left << setw(20) << studentas.vardas  << left << setw(20) << studentas.pavarde  << left << setw(18) << fixed << setprecision(2) << GalutinisBalasVidurkis <<  left << setw(18) << fixed << setprecision(2) << GalutinisBalasMediana << endl;
    }


}
