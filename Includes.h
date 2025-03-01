
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
#include "Struktura.h"

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
void sortStudentai(std::vector<Studentas>& studentai, int RusiavimoPasirinkimas);

#endif 

