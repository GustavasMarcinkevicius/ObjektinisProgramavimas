//Failas, kuriame galima sukurti failus, skirtas tik laiko testavimo tikslams (kompiliuojant naudodi o2 flag'a)

#include "Includes.h"

int main(){

int numStudents;
cout << "Iveskite studentu kieki: " << endl;
 cin >> numStudents;
 std::chrono::high_resolution_clock::time_point FailoKurimoPradzia = std::chrono::high_resolution_clock::now();
 generateFile(numStudents);
 std::chrono::high_resolution_clock::time_point FailoSukurimoPabaiga = std::chrono::high_resolution_clock::now();
 std::chrono::duration<double> ProgramosVeikimoLaikas = FailoSukurimoPabaiga - FailoKurimoPradzia;
 cout << "Failo kurimas su " << numStudents << " Studentu uztruko " <<  ProgramosVeikimoLaikas.count() << " sekundziu" << endl;
return 0;
}