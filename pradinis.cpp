#include "Includes.h"

int main(){
const int StudentuSkaicius = 1;
const int NamuDarbuUzduociuSkaicius = 3;

    
struct Studentas{
string vardas;
string pavarde;
int namuDarbuTarpiniaiRezultatai[NamuDarbuUzduociuSkaicius];
int egzaminoRezultatas;
double galutinisBalasVidurkis;
double galutinisBalasMediana;

};

Studentas Studentas[StudentuSkaicius];

for (int i = 0; i < StudentuSkaicius; i++){
cout << "Iveskite studento varda: "; cin >> Studentas[i].vardas;
cout << "Iveskite studento pavarde: "; cin >> Studentas[i].pavarde;
int namuDarbuPazymiai = 0;
for (int o = 0; o<NamuDarbuUzduociuSkaicius; o++){
cout << "Iveskite studento namu darbu tarpini rezultata numeris " << o+1 << ": "; cin >> Studentas[i].namuDarbuTarpiniaiRezultatai[o];
namuDarbuPazymiai = namuDarbuPazymiai + Studentas[i].namuDarbuTarpiniaiRezultatai[o];
};
cout << "Iveskite studento egzamino rezultata: "; cin >> Studentas[i].egzaminoRezultatas;
Studentas[i].galutinisBalasVidurkis = 0.4 * namuDarbuPazymiai/NamuDarbuUzduociuSkaicius + 0.6 * Studentas[i].egzaminoRezultatas;
std::sort(Studentas[i].namuDarbuTarpiniaiRezultatai, Studentas[i].namuDarbuTarpiniaiRezultatai + NamuDarbuUzduociuSkaicius);

if (NamuDarbuUzduociuSkaicius % 2 == 0){
    double Mediana = (Studentas[i].namuDarbuTarpiniaiRezultatai[NamuDarbuUzduociuSkaicius/2] + Studentas[i].namuDarbuTarpiniaiRezultatai[(NamuDarbuUzduociuSkaicius/2)-1])/2.0;
    Studentas[i].galutinisBalasMediana = 0.4 * Mediana + 0.6 * Studentas[i].egzaminoRezultatas;
}
else { double Mediana = Studentas[i].namuDarbuTarpiniaiRezultatai[NamuDarbuUzduociuSkaicius/2];
Studentas[i].galutinisBalasMediana = 0.4 * Mediana + 0.6 * Studentas[i].egzaminoRezultatas;
}
};


cout << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)" << endl;
cout << "--------------------------------------------------------------------------" << endl;
for (int i = 0; i < StudentuSkaicius; i++){
cout << left << setw(20) << Studentas[i].vardas << left << setw(20)  << Studentas[i].pavarde  << left << setw(18) << setprecision(2) << fixed << Studentas[i].galutinisBalasVidurkis << setprecision(2) << fixed << Studentas[i].galutinisBalasMediana << endl;
};


return 0;
};