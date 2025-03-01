#include "Includes.h"

void WithRandomNumbersArrays(int ArGeneruotiVardus) {
    struct StudentasMasyvas {
        string vardas;
        string pavarde;
        int* pazymiai;
        int pazymiuSkaicius;
        int pazymiuCapacity;
        int egzaminoPazimys;
    };

    int size = 0;
    int capacity = 1;
    StudentasMasyvas* studentas = new StudentasMasyvas[capacity];

    string choice = "taip";
    while (choice == "taip"){
        if (size == capacity) {
            capacity++;
            StudentasMasyvas* temp = new StudentasMasyvas[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = studentas[i]; 
                temp[i].pazymiai = new int[studentas[i].pazymiuCapacity]; 
                for (int j = 0; j < studentas[i].pazymiuSkaicius; j++) {
                    temp[i].pazymiai[j] = studentas[i].pazymiai[j]; 
                }
            }
            delete[] studentas;
            studentas = temp;
        }

        studentas[size].pazymiuSkaicius = 0;
        studentas[size].pazymiuCapacity = 1;
        studentas[size].pazymiai = new int[studentas[size].pazymiuCapacity]; 
        studentas[size].egzaminoPazimys = 0;

        if (ArGeneruotiVardus == 0) {
            cout << "Iveskite studento varda: ";  
            cin >> studentas[size].vardas;
            cout << "Iveskite studento pavarde: ";   
            cin >> studentas[size].pavarde;
        } else {
            studentas[size].vardas = generateRandomName();
            studentas[size].pavarde = generateRandomSurname();
        }

        int indeksas = 0;
        int pazymiuKiekis = generateRandomNumber(3, 10);
        for (int i = 0; i < pazymiuKiekis; i++) {
            if (indeksas == studentas[size].pazymiuCapacity) {
                studentas[size].pazymiuCapacity *= 2;
                int* naujiPazymiai = new int[studentas[size].pazymiuCapacity];
                for (int j = 0; j < indeksas; j++) {
                    naujiPazymiai[j] = studentas[size].pazymiai[j];
                }
                delete[] studentas[size].pazymiai;
                studentas[size].pazymiai = naujiPazymiai;
            }
            studentas[size].pazymiai[indeksas++] = generateRandomNumber(1, 10);
        }

        studentas[size].egzaminoPazimys = generateRandomNumber(1, 10);
        studentas[size].pazymiuSkaicius = indeksas;
        size++;

        cout << "Prideti dar viena studenta? (parasykite taip/ne): "; 
        cin >> choice;
    } 

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

    for (int i = 0; i < size; i++) {
        delete[] studentas[i].pazymiai; 
    }
    delete[] studentas; 
}
