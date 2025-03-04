#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <sstream> 

void generateFile(const std::string &filename, int numStudents) {
    std::ofstream file(filename);

    file << std::left << std::setw(25) << "Vardas"
         << std::setw(25) << "Pavarde";

    for (int i = 1; i <= 15; i++) {
        file << std::setw(10) << ("ND");
    }
    file << std::setw(10) << "Egz." << "\n";


    std::srand(std::time(nullptr));

 
    for (int i = 1; i <= numStudents; i++) {
        std::ostringstream name, surname;
        name << "Vardas" << i;
        surname << "Pavarde" << i;
    
        file << std::left << std::setw(25) << name.str()
             << std::setw(25) << surname.str();

        for (int j = 0; j < 16; j++) {
            file << std::setw(10) << (std::rand() % 10 + 1);
        }
        file << "\n";
    }

    file.close();
    std::cout << "File '" << filename << "' generated successfully!\n";
}

int main() {
    generateFile("students.txt", 8);
    return 0;
}