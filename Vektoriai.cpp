#include "Includes.h"
#include <fstream>
#include <sstream>


struct Studentas {
    string vardas;
    string pavarde;
    vector<int> pazymiai;  
    int egzaminoPazimys;
};

void WithVectors() {
    std::ostringstream output;
    vector<Studentas> studentai;
    int VeikimoPasirinkimas;
    int IsvedimoPasirinkimas;

    cout << "Pasirinkite: " << endl;
    cout << "Rasyti ranka - 1" << endl;
    cout << "Nuskaityti is failo - 2" << endl;
    cin >> VeikimoPasirinkimas;
    if (VeikimoPasirinkimas == 2){
        cout << "Duomenis isvesti i:" << endl;
        cout << "Ekrana - 1" << endl;
        cout << "Faila - 2" << endl;
        cin >> IsvedimoPasirinkimas;
    }

    if (VeikimoPasirinkimas == 1) {
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
                naujasStudentas.pazymiai.push_back(pazymys);  
    
                cout << "Ar norite prideti dar viena pazymi? (taip/ne): ";
                cin >> PazymiuIrasymoPasirinkimas;
            }
    
            cout << "Iveskite studento egzamino pazymi: ";
            cin >> naujasStudentas.egzaminoPazimys;
    
            studentai.push_back(naujasStudentas); 
    
            cout << "Prideti dar viena studenta? (taip/ne): ";
            cin >> choice;
    
        } while (choice == "taip");
    
        cout << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)" << endl;
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
            std::sort(sortedPazymiai.begin(), sortedPazymiai.end());
    
            if (!sortedPazymiai.empty()) {
                int n = sortedPazymiai.size();
                Mediana = (n % 2 == 0) ? (sortedPazymiai[n / 2 - 1] + sortedPazymiai[n / 2]) / 2.0 
                                       : sortedPazymiai[n / 2];
            }
    
            GalutinisBalasMediana = 0.4 * Mediana + 0.6 * studentas.egzaminoPazimys;
            GalutinisBalasVidurkis = 0.4 * Vidurkis + 0.6 * studentas.egzaminoPazimys;
    
            cout << left << setw(20) << studentas.vardas  
                      << left << setw(20) << studentas.pavarde  
                      << left << setw(18) << fixed << setprecision(2) << GalutinisBalasVidurkis 
                      << left << setw(18) << fixed << setprecision(2) << GalutinisBalasMediana << endl;
        }
    }
    

    if (VeikimoPasirinkimas == 2) {  
        std::ifstream InputFile("Studentai10000.txt", std::ios::in);
        std::ofstream OutputFile("StudentaiOutput.txt", std::ios::trunc); 
      

        string header;
        getline(InputFile, header);

        string line;
        while (getline(InputFile, line)) {
           std::istringstream lineStream(line);
            Studentas naujasStudentas;


            lineStream >> naujasStudentas.vardas >> naujasStudentas.pavarde;
            int pazymys;
            while (lineStream >> pazymys) {
                naujasStudentas.pazymiai.push_back(pazymys);
            }

      
            naujasStudentas.egzaminoPazimys = naujasStudentas.pazymiai.back();
            naujasStudentas.pazymiai.pop_back(); 

            studentai.push_back(naujasStudentas);
        }

        InputFile.close();

        if (IsvedimoPasirinkimas == 1){

        cout << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        }
        
if (IsvedimoPasirinkimas == 2){
    OutputFile << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)\n";
    OutputFile << "--------------------------------------------------------------------------\n";
    

}

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
                if (n % 2 == 0) {
                    Mediana = (sortedPazymiai[n / 2 - 1] + sortedPazymiai[n / 2]) / 2.0;
                } else {
                    Mediana = sortedPazymiai[n / 2];
                }
            }

        
            GalutinisBalasMediana = 0.4 * Mediana + 0.6 * studentas.egzaminoPazimys;
            GalutinisBalasVidurkis = 0.4 * Vidurkis + 0.6 * studentas.egzaminoPazimys;

            if (IsvedimoPasirinkimas == 1){
              output << left << setw(20) << studentas.vardas
            << left << setw(20) << studentas.pavarde
            << left << setw(18) << fixed << setprecision(2) << GalutinisBalasVidurkis
            << left << setw(18) << fixed << setprecision(2) << GalutinisBalasMediana
            << '\n';
            }
            if (IsvedimoPasirinkimas == 2){
                OutputFile << left << setw(20) << studentas.vardas
                << left << setw(20) << studentas.pavarde
                << left << setw(18) << fixed << setprecision(2) << GalutinisBalasVidurkis
                << left << setw(18) << fixed << setprecision(2) << GalutinisBalasMediana
                << '\n';
            }
        }
        cout << output.str();
    }
}

int main() {
    WithVectors();  
    return 0;
}
