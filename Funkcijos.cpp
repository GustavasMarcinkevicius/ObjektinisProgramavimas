
#include "Includes.h"


int generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
}

string generateRandomName() {   
    vector<string> vardai = {"Lonnie", "Sylvain", "Lukas", "Ignas", "Dovydas", "Laurynas", "Alen", "Matt", "Tomas", "Bryant", "Brady", "Arnas", "Deividas", "Edgaras"};
    return vardai[generateRandomNumber(0, vardai.size() -1 )];
}

string generateRandomSurname() {
    vector<string> pavardes = {"Walker IV", "Francisko", "Lekavicius", "Brazdeikis", "Giedraitis", "Birutis", "Smailagic", "Mitchell", "Dimsa", "Dunston", "Manek", "Butkevicius", "Sirvydis", "Ulanovas"};
    return pavardes[generateRandomNumber(0, pavardes.size() -1)];
}

void ApskaiciuotiVeikimoLaikoVidurki(){
    std::ifstream file("TestavimoLaikuLog.txt");

    double inputTime, runningTime;
    std::vector<double> inputTimes;
    std::vector<double> runningTimes;

    while (file >> inputTime >> runningTime) {
        inputTimes.push_back(inputTime);
        runningTimes.push_back(runningTime);
    }

    file.close();

    double totalInputTime = 0.0;
    for (double time : inputTimes) {
        totalInputTime += time;
    }
    double avgInputTime = totalInputTime / inputTimes.size();

    double totalRunningTime = 0.0;
    for (double time : runningTimes) {
        totalRunningTime += time;
    }
    double avgRunningTime = totalRunningTime / runningTimes.size();

    std::cout << "Vidutinis Skaitymo laikas: " << std::fixed << std::setprecision(6) << avgInputTime << " sekundziu" << endl;;
    std::cout << "Vidutinis Programos veikimo laikas: " << std::fixed << std::setprecision(6) << avgRunningTime << " sekundziu" << endl;;
}