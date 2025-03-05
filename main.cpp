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
    cout << "3 - Sugeneruoti failus ir isskirstyti studentus" << endl;
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
    int StudentuKiekis;
    int Rusiavimas;
    std::ostringstream output;
    vector<Studentas> studentai;

    cout << "Irasykite studentu kieki: "; cin >> StudentuKiekis;
    cout << "Pasirinkite rusiavimo tipa:" << endl;
    cout << "Pagal galutini pazymi (nuo Vidurkio) - 1" << endl;
    cout << "Pagal galutini pazymi (nuo Medianos) - 2" << endl;
    cin >> Rusiavimas;
    Rusiavimas = Rusiavimas+2; // +2, nes atmesti rusiavimai pagal varda ir pavarde, kurie buvo 1 ir 2
    std::string filename = "SugeneruotiStudentai" + std::to_string(StudentuKiekis) + ".txt";
    generateFile(StudentuKiekis);

    namespace fs = std::filesystem;

    std::ifstream InputFile(filename, std::ios::in);
    std::ofstream OutputFile1("Kietekai.txt", std::ios::trunc);
    std::ofstream OutputFile2("Vargsiukai.txt", std::ios::trunc);

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

    sortStudentai(studentai, Rusiavimas);

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

        if (Rusiavimas == 3) { 
            if (GalutinisBalasVidurkis >= 5) {
                OutputFile1 << left << setw(20) << studentas.vardas
                << left << setw(20) << studentas.pavarde
                << left << setw(18) << fixed << setprecision(2) << GalutinisBalasVidurkis
                << left << setw(18) << fixed << setprecision(2) << GalutinisBalasMediana
                << '\n';
            } else {
                OutputFile2 << left << setw(20) << studentas.vardas
                << left << setw(20) << studentas.pavarde
                << left << setw(18) << fixed << setprecision(2) << GalutinisBalasVidurkis
                << left << setw(18) << fixed << setprecision(2) << GalutinisBalasMediana
                << '\n';
            }
        } else if (Rusiavimas == 4) {  
            if (GalutinisBalasMediana >= 5) {
                OutputFile1 << left << setw(20) << studentas.vardas
                << left << setw(20) << studentas.pavarde
                << left << setw(18) << fixed << setprecision(2) << GalutinisBalasVidurkis
                << left << setw(18) << fixed << setprecision(2) << GalutinisBalasMediana
                << '\n';            } else {
                    OutputFile2 << left << setw(20) << studentas.vardas
                    << left << setw(20) << studentas.pavarde
                    << left << setw(18) << fixed << setprecision(2) << GalutinisBalasVidurkis
                    << left << setw(18) << fixed << setprecision(2) << GalutinisBalasMediana
                    << '\n';            }
        }
    }

    cout << output.str();
    cout << "Skaitymo Laikas: " << Readingduration.count() << " sekundes" << endl;
    std::chrono::high_resolution_clock::time_point ProgramEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> ProgramDuration = ProgramEnd - Readingstart;
    cout << "Visos programos veikimo laikas: " << ProgramDuration.count() << " sekundes" << endl;
    logFile << Readingduration.count() << " " << ProgramDuration.count() << endl;

            break;
        

    };

            return 0;
}
