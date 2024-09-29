
#include "mylib.h"

int main() {
    int studentuSkaicius;
    cout << "Įveskite studentų skaičių: ";
    cin >> studentuSkaicius;

    vector<Studentas> studentai(studentuSkaicius);

    for (int i = 0; i < studentuSkaicius; ++i) {
        cin >> studentai[i];

        bool pagalVidurki;
        cout << "Skaičiuoti galutinį pagal vidurkį? (1 - taip, 0 - ne): ";
        cin >> pagalVidurki;

        studentai[i].skaiciuotiGalutiniBala(pagalVidurki);
    }

    cout << endl << setw(15) << left << "Pavardė"
        << setw(15) << "Vardas"
        << setw(10) << "Galutinis (Vid.)" << endl;
    cout << "--------------------------------------------------" << endl;

    for (const auto& studentas : studentai) {
        cout << studentas << endl;
    }

    return 0;
}
