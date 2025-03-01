    #include "Includes.h"



    void WithVectors() {

  #include "Struktura.h"
  #include <filesystem>
    

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
        

                try {
                cout << "Iveskite studento varda: ";
                cin >> naujasStudentas.vardas;
                cout << "Iveskite studento pavarde: ";
                cin >> naujasStudentas.pavarde;
                
            if (naujasStudentas.vardas.size() == 0 || naujasStudentas.vardas.size() == 0){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::out_of_range("Prasome ivesti varda/pavarde");
            } 
            } catch (const std::out_of_range& e) {
                std::cerr << "Prasome ivesti varda/pavarde" << std::endl;
            }
                string PazymiuIrasymoPasirinkimas = "taip";
                while (PazymiuIrasymoPasirinkimas == "taip") {
                    int pazymys;
                    try {
                    cout << "Irasykite pazymi: ";
                    cin >> pazymys;
                    if (pazymys < 1 || pazymys > 10) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::out_of_range("Klaida: Pazymys turi buti tarp 1 ir 10.");
                    }
                    }    catch (const std::out_of_range& e) {
                        std::cerr << "Klaida: Pazymys turi buti tarp 1 ir 10!" << std::endl;
                    }
                    naujasStudentas.pazymiai.push_back(pazymys);  
        
                    try {
                    cout << "Ar norite prideti dar viena pazymi? (taip/ne): ";
                    cin >> PazymiuIrasymoPasirinkimas;

                        if (PazymiuIrasymoPasirinkimas != "taip" && PazymiuIrasymoPasirinkimas != "ne") {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            throw std::out_of_range("Pasirinkimas turi buti taip arba ne");
                        }
                        }    catch (const std::out_of_range& e) {
                            std::cerr << "Pasirinkimas turi buti taip arba ne" << std::endl;
                        }
                }
        
                cout << "Iveskite studento egzamino pazymi: ";
                cin >> naujasStudentas.egzaminoPazimys;
        
                studentai.push_back(naujasStudentas); 
        

                try {
                cout << "Prideti dar viena studenta? (taip/ne): ";
                cin >> choice;
                
            if (choice != "taip" && choice != "ne"){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::out_of_range("Pasirinkimas turi buti taip arba ne");
            }
            } catch (const std::out_of_range& e) {
                std::cerr << "Pasirinkimas turi buti taip arba ne" << std::endl;
            }
        
            } while (choice == "taip");

        
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
        
            }

            
            sortStudentai(studentai, RusiavimoPasirinkimas);

            if (IsvedimoPasirinkimas == 1){

            cout << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            }
            
    if (IsvedimoPasirinkimas == 2){

        std::ofstream OutputFile("StudentaiOutput.txt", std::ios::trunc); 
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
                    std::ofstream OutputFile("StudentaiOutput.txt", std::ios::trunc); 
                    OutputFile << left << setw(20) << studentas.vardas
                    << left << setw(20) << studentas.pavarde
                    << left << setw(18) << fixed << setprecision(2) << GalutinisBalasVidurkis
                    << left << setw(18) << fixed << setprecision(2) << GalutinisBalasMediana
                    << '\n';
                }
            }
        }
        

        if (VeikimoPasirinkimas == 2) {   //skaityt
            namespace fs = std::filesystem;
            fs::path currentPath = fs::current_path();
            std::cout << "Iveskite failo pavadinima: ";
            string filename;
            std::cin >> filename;
            fs::path filePath = currentPath / filename;

            try {
                
                if (!fs::exists(filePath)) {
                    throw std::runtime_error("Klaida: Failas su tokiu pavadinimu neegzistuoja.");
                }
            std::ifstream InputFile(filePath, std::ios::in);
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
            
            sortStudentai(studentai, RusiavimoPasirinkimas);
  
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
        }catch (const std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    }


    