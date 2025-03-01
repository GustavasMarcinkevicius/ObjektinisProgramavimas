#ifndef STRUKTURA_H
#define STRUKTURA_H
#include <iostream>
#include <vector>

using std::string;
using std::vector;


struct Studentas {
    string vardas;
    string pavarde;
    vector<int> pazymiai;  
    int egzaminoPazimys;
};

#endif 

