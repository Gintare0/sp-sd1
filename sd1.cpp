#include "mylib.h"
#include "studentas.h"

int main() {
    int studentuSkaicius;
    cout << "Įveskite studentų skaičių: ";
    cin >> studentuSkaicius;

    vector<Studentas> studentai(studentuSkaicius);

    for (int i = 0; i < studentuSkaicius; ++i) {
        cout << "Ar norite įvesti studento rezultatus rankiniu būdu? (1 - Taip, 0 - Generuoti): ";
        bool rankinisIvedimas;
        cin >> rankinisIvedimas;

        if (rankinisIvedimas) {
            cin >> studentai[i];
        }
        else {
            int ndKiekis;
            cout << "Įveskite namų darbų kiekį: ";
            cin >> ndKiekis;
            studentai[i].generuotiAtsitiktiniusRezultatus(ndKiekis);
        }

        studentai[i].skaiciuotiGalutiniBala();
    }

    // Output header
    cout << endl << setw(15) << left << "Pavardė"
        << setw(15) << "Vardas"
        << setw(10) << "Galutinis (Vid.)"
        << setw(10) << "Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (const auto& studentas : studentai) {
        cout << studentas << endl;
    }

    return 0;
}

