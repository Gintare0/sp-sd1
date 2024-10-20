#include "studentas.h"
#include "mylib.h"

using namespace std;
using namespace chrono;

void generuotiStudentuDuomenuFailus() {
    vector<int> dydziai = { 1000, 10000, 100000, 1000000, 10000000 };
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> skirstymas(1, 10);

    for (int dydis : dydziai) {
        string failoPavadinimas = "studentai_" + to_string(dydis) + ".txt";
        ofstream isvestiesFailas(failoPavadinimas);

        if (!isvestiesFailas) {
            cerr << "Nepavyko sukurti failo: " << failoPavadinimas << endl;
            continue;
        }

        isvestiesFailas << "Vardas     Pavarde    ND1  ND2  ND3  ND4  ND5  Egzaminas" << endl;

        for (int i = 1; i <= dydis; ++i) {
            isvestiesFailas << "Vardas" << i << " Pavarde" << i;
            for (int j = 0; j < 5; ++j) {
                isvestiesFailas << " " << skirstymas(gen);
            }
            isvestiesFailas << " " << skirstymas(gen) << endl;
        }
        isvestiesFailas.close();
    }
}

void kategorizuotiStudentus(const string& ivestiesFailoPavadinimas) {
    ifstream ivestiesFailas(ivestiesFailoPavadinimas);
    if (!ivestiesFailas) {
        throw runtime_error("Nepavyko atidaryti failo: " + ivestiesFailoPavadinimas);
    }

    vector<Studentas> vargsai;
    vector<Studentas> kietiakiai;

    string eilute;
    getline(ivestiesFailas, eilute);

    while (getline(ivestiesFailas, eilute)) {
        istringstream iss(eilute);
        Studentas s;
        iss >> s;
        s.skaiciuotiGalutiniBala();

        if (s.getGalutinis() < 5.0) {
            vargsai.push_back(s);
        }
        else {
            kietiakiai.push_back(s);
        }
    }
    ivestiesFailas.close();

    ofstream isvestiesFailasVargsams("vargsai_" + ivestiesFailoPavadinimas);
    ofstream isvestiesFailasKietiakiams("kietiakiai_" + ivestiesFailoPavadinimas);

    for (const auto& s : vargsai) {
        isvestiesFailasVargsams << s << endl;
    }
    for (const auto& s : kietiakiai) {
        isvestiesFailasKietiakiams << s << endl;
    }
}

int main() {
    try {
        auto pradzia = high_resolution_clock::now();
        generuotiStudentuDuomenuFailus();
        auto pabaiga = high_resolution_clock::now();
        cout << "Failu generavimo laikas: " << duration_cast<seconds>(pabaiga - pradzia).count() << " sekundes" << endl;

        vector<string> failai = { "studentai_1000.txt", "studentai_10000.txt", "studentai_100000.txt", "studentai_1000000.txt", "studentai_10000000.txt" };

        for (const auto& failas : failai) {
            pradzia = high_resolution_clock::now();
            kategorizuotiStudentus(failas);
            pabaiga = high_resolution_clock::now();
            cout << "Apdorojimo laikas failui " << failas << ": " << duration_cast<seconds>(pabaiga - pradzia).count() << " sekundes" << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }

    return 0;
}
