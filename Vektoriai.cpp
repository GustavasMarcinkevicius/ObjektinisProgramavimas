#include "Includes.h"


void WithVectors() {
#include "Struktura.h"

    std::ostringstream output;
    vector<Studentas> studentai;
    int VeikimoPasirinkimas;
    int IsvedimoPasirinkimas;
    int RusiavimoPasirinkimas;

    cout << "Pasirinkite: " << endl;
    cout << "Rasyti ranka - 1" << endl;
    cout << "Nuskaityti is failo - 2" << endl;
    cin >> VeikimoPasirinkimas;

        cout << "Duomenis isvesti i:" << endl;
        cout << "Ekrana - 1" << endl;
        cout << "Faila - 2" << endl;
        cin >> IsvedimoPasirinkimas;
    

    cout << "pasirinkite rusiavimo tipa:" << endl;
    cout << "Pagal varda - 1" << endl;
    cout << "Pagal pavarde - 2" << endl;
    cout << "Pagal galutini pazymi (nuo Vidurkio) - 3" << endl;
    cout << "Pagal galutini pazymi (nuo Medianos) - 4" << endl;
    cin >> RusiavimoPasirinkimas;


    if (VeikimoPasirinkimas == 1) { //rasyti ranka
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

        std::ofstream logFile("TestavimoLaikuLog.txt", std::ios::app);
        
      
        std::chrono::high_resolution_clock::time_point Readingstart = std::chrono::high_resolution_clock::now();

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

        std::chrono::high_resolution_clock::time_point Readingend = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> Readingduration = Readingend - Readingstart;
        


if (RusiavimoPasirinkimas == 1){ //sortint pagal varda/
    sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return a.vardas < b.vardas;
    });
    
}


if (RusiavimoPasirinkimas == 2){ //sortint pagal pavarde
    sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return a.pavarde < b.pavarde;
    });
    
}

if (RusiavimoPasirinkimas == 3){ //sortint pagal Vidurki

        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            double avgA = 0, avgB = 0;
            for (int pazymys : a.pazymiai) {
                avgA += pazymys;
            }
            if (!a.pazymiai.empty()) avgA /= a.pazymiai.size();
            for (int pazymys : b.pazymiai) {
                avgB += pazymys;
            }
            if (!b.pazymiai.empty()) avgB /= b.pazymiai.size();
    
            double galutinisA = 0.4 * avgA + 0.6 * a.egzaminoPazimys;
            double galutinisB = 0.4 * avgB + 0.6 * b.egzaminoPazimys;
            return galutinisA > galutinisB;
        });
    };

    if (RusiavimoPasirinkimas == 4){ //Sortint pagal mediana
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            vector<int> sortedA = a.pazymiai;
            sort(sortedA.begin(), sortedA.end());
            double medianA = 0;
            
            
                int pazymiuKiekis = sortedA.size();
                if (pazymiuKiekis % 2 == 0) {
                    medianA = (sortedA[pazymiuKiekis / 2 - 1] + sortedA[pazymiuKiekis / 2]) / 2.0;
                } else {
                    medianA = sortedA[pazymiuKiekis / 2];
                }
            
    
            vector<int> sortedB = b.pazymiai;
            sort(sortedB.begin(), sortedB.end());
            double medianB = 0;
            
                int n = sortedB.size();
                if (n % 2 == 0) {
                    medianB = (sortedB[n / 2 - 1] + sortedB[n / 2]) / 2.0;
                } else {
                    medianB = sortedB[n / 2];
                }
        
                double galutinisA = 0.4 * medianA + 0.6 * a.egzaminoPazimys;
                double galutinisB = 0.4 * medianB + 0.6 * b.egzaminoPazimys;
                return galutinisA > galutinisB;
        });
    }

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
        cout << "Skaitymo Laikas: " << Readingduration.count() << " sekundes" << endl;
        std::chrono::high_resolution_clock::time_point ProgramEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> ProgramDuration = ProgramEnd - Readingstart;
        cout << "Visos programos veikimo laikas: " << ProgramDuration.count() << " sekundes" << endl;
        logFile << Readingduration.count() << " " << ProgramDuration.count() << endl;
    }

}


  