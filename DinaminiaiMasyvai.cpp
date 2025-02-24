#include "Includes.h"

struct Studentas {
    string vardas;
    string pavarde;
    int* pazymiai;
    int pazymiuSkaicius;
    int pazymiuCapacity;
    int egzaminoPazimys;

    Studentas() {
        pazymiai = new int[1];
        pazymiuSkaicius = 0;
        pazymiuCapacity = 1;
        egzaminoPazimys = 0;
    }

    ~Studentas() {
        delete[] pazymiai;
    }
};

void runDinaminiaiMasyvai() {

    int size = 0;
    int capacity = 1;
    Studentas* studentas = new Studentas[capacity];

    string choice;
    do {
        if (size == capacity) {
            capacity++;
            Studentas* temp = new Studentas[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = studentas[i];
            }
            delete[] studentas;
            studentas = temp;
        }

        cout << "Iveskite studento varda: ";  cin >> studentas[size].vardas;
        cout << "Iveskite studento pavarde: ";   cin >> studentas[size].pavarde;

        string PazymiuIrasymoPasirinkimas = "taip";
        int indeksas = 0;

        while (PazymiuIrasymoPasirinkimas == "taip") {
            if (indeksas == studentas[size].pazymiuCapacity) {
                studentas[size].pazymiuCapacity++;
                int* naujiPazymiai = new int[studentas[size].pazymiuCapacity];
                for (int i = 0; i < indeksas; i++) {
                    naujiPazymiai[i] = studentas[size].pazymiai[i];
                }
                delete[] studentas[size].pazymiai;
                studentas[size].pazymiai = naujiPazymiai;
            }

            cout << "Irasykite pazymi numeris " << indeksas + 1 << ": ";
            cin >> studentas[size].pazymiai[indeksas];
            indeksas++;

            cout << "Ar norite prideti dar viena pazymi siam studentui: " 
                 << studentas[size].vardas << "(parasykite taip/ne): "; 
            cin >> PazymiuIrasymoPasirinkimas;
        }

        cout << "Iveskite studento egzamino pazymi: "; cin >> studentas[size].egzaminoPazimys;

        studentas[size].pazymiuSkaicius = indeksas;
        size++;

        cout << "Prideti dar viena studenta? (parasykite taip/ne): "; 
        cin >> choice;

    } while (choice == "taip");

    cout << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        double Vidurkis = 0;
        double Mediana = 0;
        double GalutinisBalasMediana = 0;
        double GalutinisBalasVidurkis = 0;

        for (int j = 0; j < studentas[i].pazymiuSkaicius; j++) {
            Vidurkis += studentas[i].pazymiai[j];
        }
        Vidurkis /= studentas[i].pazymiuSkaicius;

        std::sort(studentas[i].pazymiai, studentas[i].pazymiai + studentas[i].pazymiuSkaicius);

        if (studentas[i].pazymiuSkaicius % 2 == 0) {
            Mediana = (static_cast<double>(studentas[i].pazymiai[studentas[i].pazymiuSkaicius / 2 - 1]) 
                     + static_cast<double>(studentas[i].pazymiai[studentas[i].pazymiuSkaicius / 2])) / 2.0;
        } else {
            Mediana = studentas[i].pazymiai[studentas[i].pazymiuSkaicius / 2];
        }

        GalutinisBalasMediana = 0.4 * Mediana + 0.6 * studentas[i].egzaminoPazimys;
        GalutinisBalasVidurkis = 0.4 * Vidurkis + 0.6 * studentas[i].egzaminoPazimys;

        cout << left << setw(20) << studentas[i].vardas 
             << left << setw(20) << studentas[i].pavarde  
             << left << setw(18) << setprecision(2) << fixed << GalutinisBalasVidurkis 
             << left << setw(18) << setprecision(2) << fixed << GalutinisBalasMediana << endl;
    }

    delete[] studentas;


}
