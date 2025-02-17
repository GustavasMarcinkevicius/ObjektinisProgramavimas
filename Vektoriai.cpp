 #include "Includes.h"

 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <iomanip>
 
 struct Studentas {
     std::string vardas;
     std::string pavarde;
     std::vector<int> pazymiai;  // Vector instead of dynamic array
     int egzaminoPazimys;
 
    
 };
 
 int main() {
     vector<Studentas> studentai;  // Vector for students
 
     string choice;
     do {
         Studentas naujasStudentas;
 
         cout << "Iveskite studento varda: ";
         cin >> naujasStudentas.vardas;
         cout << "Iveskite studento pavarde: ";
         cin >> naujasStudentas.pavarde;
 
         string PazymiuIrasymoPasirinkimas = "taip";
         while (PazymiuIrasymoPasirinkimas == "taip") {
             int pazymys;
             cout << "Irasykite pazymi: ";
             cin >> pazymys;
             naujasStudentas.pazymiai.push_back(pazymys);  // Using push_back()
 
             cout << "Ar norite prideti dar viena pazymi? (taip/ne): ";
             cin >> PazymiuIrasymoPasirinkimas;
         }
 
         cout << "Iveskite studento egzamino pazymi: ";
         cin >> naujasStudentas.egzaminoPazimys;
 
         studentai.push_back(naujasStudentas);  // Add student to vector
 
         cout << "Prideti dar viena studenta? (taip/ne): ";
         cin >> choice;
 
     } while (choice == "taip");
 
     cout << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)" << endl;;
     cout << "--------------------------------------------------------------------------" << endl;
 
     for (const auto& studentas : studentai) {
         double Vidurkis = 0, Mediana = 0, GalutinisBalasVidurkis = 0, GalutinisBalasMediana = 0;
 
         for (int pazymys : studentas.pazymiai) {
             Vidurkis += pazymys;
         }
 
         if (!studentas.pazymiai.empty()) {
             Vidurkis /= studentas.pazymiai.size();
         }
 
         vector<int> sortedPazymiai = studentas.pazymiai;
         sort(sortedPazymiai.begin(), sortedPazymiai.end());
 
         if (!sortedPazymiai.empty()) {
             int n = sortedPazymiai.size();
             Mediana = (n % 2 == 0) ? (sortedPazymiai[n / 2 - 1] + sortedPazymiai[n / 2]) / 2.0 
                                    : sortedPazymiai[n / 2];
         }
 
         GalutinisBalasMediana = 0.4 * Mediana + 0.6 * studentas.egzaminoPazimys;
         GalutinisBalasVidurkis = 0.4 * Vidurkis + 0.6 * studentas.egzaminoPazimys;
 
         cout << left << setw(20) << studentas.vardas  << left << setw(20) << studentas.pavarde  << left << setw(18) << fixed << setprecision(2) << GalutinisBalasVidurkis <<  left << setw(18) << fixed << setprecision(2) << GalutinisBalasMediana << endl;
     }
 
     return 0;
 }
 