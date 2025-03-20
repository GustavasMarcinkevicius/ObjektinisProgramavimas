#include "Struktura.h"
#include "Includes.h"



int main() {
    int choice1;
    int choice2;
    cout << "Pasirinkite programos veikimo buda: " << endl;
    cout << "1 - Su vektoriais" << endl;
    cout << "2 - Su C masyvais" << endl;
    cout << "3 - Isskirstyti studentus is sugeneruoto failo" << endl;
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


            case 3:

cout << "Pasirinkite:" << endl;
cout <<"1. Su vektoriais" << endl;
cout <<"2. Su list'ais" << endl;
cout <<"3. Su deque'ais" << endl;
int StrukturosPasirinkimas;
cin >> StrukturosPasirinkimas;

cout << "Pasirinkite strategija: 1, 2 arba 3" << endl;
int StrategijosPasirinkimas;
cin >> StrategijosPasirinkimas;

if (StrukturosPasirinkimas == 1){
    int StudentuKiekis;
    int Rusiavimas;
    std::ostringstream output;
    vector<Studentas> studentai;
    vector<Studentas> kietekai;  
    vector<Studentas> vargsiukai;  

    cout << "Irasykite studentu kieki: "; cin >> StudentuKiekis;
    cout << "Pasirinkite rusiavimo tipa:" << endl;
    cout << "Pagal galutini pazymi (nuo Vidurkio) - 1" << endl;
    cout << "Pagal galutini pazymi (nuo Medianos) - 2" << endl;
    cin >> Rusiavimas;
    Rusiavimas = Rusiavimas+2; // +2, nes atmesti rusiavimai pagal varda ir pavarde, kurie buvo 1 ir 2
    std::string directory = "C:\\Users\\gusta\\Desktop\\Objektinis Github\\SugeneruotiFailai";
    std::string filename = directory + "\\SugeneruotiStudentai" + std::to_string(StudentuKiekis) + ".txt";

    namespace fs = std::filesystem;

    std::ifstream InputFile(filename, std::ios::in);
    std::ofstream OutputFile1("Kietekai.txt", std::ios::trunc);
    std::ofstream OutputFile2("Vargsiukai.txt", std::ios::trunc);

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

    std::chrono::high_resolution_clock::time_point RikiavimoPradzia = std::chrono::high_resolution_clock::now();

    for  (auto& studentas : studentai) {
        double Vidurkis = 0, Mediana = 0;
         studentas.GalutinisBalasVidurkis = 0, studentas.GalutinisBalasMediana = 0;

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

        studentas.GalutinisBalasMediana = 0.4 * Mediana + 0.6 * studentas.egzaminoPazimys;
        studentas.GalutinisBalasVidurkis = 0.4 * Vidurkis + 0.6 * studentas.egzaminoPazimys;
    }; 
    
    sortStudentai(studentai, Rusiavimas, 1);

    std::chrono::high_resolution_clock::time_point RikiavimoPabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> RikiavimoLaikas = RikiavimoPabaiga - RikiavimoPradzia;

    
    std::chrono::high_resolution_clock::time_point RusiavimoPradzia = std::chrono::high_resolution_clock::now();

if(StrategijosPasirinkimas == 1){

    for  (auto& studentas : studentai) {
        if (Rusiavimas == 3) { 
            if (studentas.GalutinisBalasVidurkis >= 5) {
                kietekai.push_back(studentas);
            } else {
                vargsiukai.push_back(studentas); 
            }
        } else if (Rusiavimas == 4) {  
            if (studentas.GalutinisBalasMediana >= 5) {
                kietekai.push_back(studentas);  
            } else {
                vargsiukai.push_back(studentas);
            }
        }
    }

    studentai.shrink_to_fit();
    kietekai.shrink_to_fit();
    vargsiukai.shrink_to_fit();

}
      
    std::chrono::high_resolution_clock::time_point RusiavimoPabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> RusiavimoLaikas = RusiavimoPabaiga - RusiavimoPradzia;

    std::chrono::high_resolution_clock::time_point KietekuPradzia = std::chrono::high_resolution_clock::now();
    OutputFile1 << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)\n";
    OutputFile1 << "--------------------------------------------------------------------------\n";

    for (const auto& studentas : kietekai) {
        OutputFile1 << left << setw(20) << studentas.vardas
                   << left << setw(20) << studentas.pavarde
                   << left << setw(18) << fixed << setprecision(2) << studentas.GalutinisBalasVidurkis
                   << left << setw(18) << fixed << setprecision(2) << studentas.GalutinisBalasMediana
                   << '\n';
    }
    std::chrono::high_resolution_clock::time_point KietekuPabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> KietekuLaikas = KietekuPabaiga - KietekuPradzia;

    
    std::chrono::high_resolution_clock::time_point VargsiukuPradzia = std::chrono::high_resolution_clock::now();
    OutputFile2 << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)\n";
    OutputFile2 << "--------------------------------------------------------------------------\n";
    for (const auto& studentas : vargsiukai) {
        OutputFile2 << left << setw(20) << studentas.vardas
                   << left << setw(20) << studentas.pavarde
                   << left << setw(18) << fixed << setprecision(2) << studentas.GalutinisBalasVidurkis
                   << left << setw(18) << fixed << setprecision(2) << studentas.GalutinisBalasMediana
                   << '\n';
    }
    std::chrono::high_resolution_clock::time_point VargsiukuPabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> VargsiukuLaikas = KietekuPabaiga - KietekuPradzia;
    
    std::chrono::high_resolution_clock::time_point ProgramEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> ProgramDuration = ProgramEnd - Readingstart;
    cout << "Failo su " << StudentuKiekis << " studentu nuskaitymo laikas: " << Readingduration.count() << " sekundes" << endl;
    cout << StudentuKiekis << " Studentu isskirstymas didejimo tvarka: " << RikiavimoLaikas.count() << " sekundes" << endl;
    cout << StudentuKiekis << " Studentu isskirstymo i kietekus ir vargsiukus laikas: " << RusiavimoLaikas.count() << " sekundes" << endl;
    cout << StudentuKiekis << " Studentu kieteku irasymo laikas: " << KietekuLaikas.count() << " sekundes" << endl;
    cout << StudentuKiekis << " Studentu vargsiuku irasymo laikas: " << VargsiukuLaikas.count() << " sekundes" << endl;
    cout << "Visos programos veikimo laikas: " << ProgramDuration.count() << " sekundes" << endl;
}

else if (StrukturosPasirinkimas == 2){
    SuListais();
}

else if (StrukturosPasirinkimas == 3){
    SuDeque();
}

            break;
        

    };

            return 0;
}