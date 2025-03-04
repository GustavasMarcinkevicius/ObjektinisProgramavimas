#include "Includes.h"

void generateFile(const std::string &filename, int numStudents) {
    std::ofstream file(filename);

    std::ios::sync_with_stdio(false);

    int pazymiuSkaicius = generateRandomNumber(5, 15);

    file << std::left << std::setw(25) << "Vardas"
         << std::setw(25) << "Pavarde";

    for (int i = 1; i <= pazymiuSkaicius; i++) {
        std::ostringstream ss;
        ss << "ND" << i;
        file << std::setw(6) << ss.str(); 
    }
    file << std::setw(6) << "Egz." << "\n"; 

    std::ostringstream buffer;
    for (int i = 1; i <= numStudents; i++) {
        buffer.str("");  
        buffer.clear();

        std::ostringstream name, surname;
        name << "Vardas" << i;
        surname << "Pavarde" << i;

        buffer << std::left << std::setw(25) << name.str()
               << std::setw(25) << surname.str();

        for (int j = 0; j < pazymiuSkaicius + 1; j++) { 
            buffer << std::setw(6) << generateRandomNumber(1, 10);
        }

        buffer << "\n";
        file << buffer.str();
    }

    file.close();
    std::cout << "File '" << filename << "' generated successfully!\n";
}

int main() {
    generateFile("students.txt", 1000000);
    return 0;
}
