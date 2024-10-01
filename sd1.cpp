#include "studentas.h"
#include "mylib.h"



int main() {
    try {
        
        vector<Studentas> studentai = Studentas::nuskaitytiIsFailo("kursiokai.txt");

        Studentas::rusiuotiStudentus(studentai);

        cout << setw(15) << left << "Pavardė"
            << setw(15) << "Vardas"
            << setw(20) << "Galutinis (Vid.)"
            << setw(20) << "Galutinis (Med.)" << endl;
        cout << "----------------------------------------------------------" << endl;

        for (const auto& studentas : studentai) {
            cout << studentas << endl;
        }
    }
    catch (const std::exception& e) {
        cout << "Klaida: " << e.what() << endl;
    }

    return 0;
}
