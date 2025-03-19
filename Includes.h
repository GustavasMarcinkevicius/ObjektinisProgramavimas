
#ifndef INCLUDES_H
#define INCLUDES_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono> 
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include <sstream> 
#include "Struktura.h"
#include <list>
#include <deque>

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;
using std::left;
using std::setw;
using std::setprecision;
using std::fixed;



int generateRandomNumber(int min, int max);
string generateRandomName();
string generateRandomSurname();
void ApskaiciuotiVeikimoLaikoVidurki();
template <typename Container>
void sortStudentai(Container& studentai, int RusiavimoPasirinkimas, int DuomenuKiekis = 0);
void generateFile(int numStudents);
void runDinaminiaiMasyvai(); 
void WithRandomNumbers();
void GenerateRandomNumbersAndNames();
void WithVectors();
void WithRandomNumbersArrays(int);
void SuListais();
void sortStudentaiList(std::list<Studentas>& studentai, int RusiavimoPasirinkimas);
void SuDeque();


#endif 

