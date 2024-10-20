#include "studentas.h"
#include "mylib.h"

using namespace std;
using namespace chrono;

template<typename Container>
void nuskaitytiStudentus(const string& failoPavadinimas, Container& studentai) {
    ifstream ivestiesFailas(failoPavadinimas);
    if (!ivestiesFailas) {
        throw runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
    }

    string eilute;
    getline(ivestiesFailas, eilute);

    while (getline(ivestiesFailas, eilute)) {
        istringstream iss(eilute);
        Studentas s;
        iss >> s;
        studentai.push_back(s);
    }
}

template<typename Container>
void pirmaStrategija(Container& studentai, Container& vargsai, Container& kietiakiai) {
    for (auto& s : studentai) {
        s.skaiciuotiGalutiniBala();
        if (s.getGalutinis() < 5.0) {
            vargsai.push_back(s);
        }
        else {
            kietiakiai.push_back(s);
        }
    }
}

template<typename Container>
void antraStrategija(Container& studentai, Container& vargsai) {
    auto it = studentai.begin();
    while (it != studentai.end()) {
        it->skaiciuotiGalutiniBala();
        if (it->getGalutinis() < 5.0) {
            vargsai.push_back(*it);
            it = studentai.erase(it);
        }
        else {
            ++it;
        }
    }
}

template<typename Container>
void treciaStrategija(Container& studentai, Container& vargsai) {
    auto partitionPoint = stable_partition(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.getGalutinis() < 5.0;
        });

    vargsai.insert(vargsai.end(), studentai.begin(), partitionPoint);
    studentai.erase(studentai.begin(), partitionPoint);
}

template<typename Container>
void issaugotiStudentusIFaila(const string& failoPavadinimas, const Container& studentai) {
    ofstream isvestiesFailas(failoPavadinimas);
    if (!isvestiesFailas) {
        throw runtime_error("Nepavyko sukurti failo: " + failoPavadinimas);
    }

    for (const auto& s : studentai) {
        isvestiesFailas << s << endl;
    }
}

int main() {
    vector<string> failai = {
        "studentai_1000.txt",
        "studentai_10000.txt",
        "studentai_100000.txt"
    };

    for (const auto& failas : failai) {
        {
            cout << "Pirma strategija su vector failu: " << failas << endl;

            vector<Studentas> studentai, vargsai, kietiakiai;

            auto pradzia = high_resolution_clock::now();
            nuskaitytiStudentus(failas, studentai);
            auto pabaiga = high_resolution_clock::now();
            cout << "Duomenu nuskaitymo laikas: " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            pradzia = high_resolution_clock::now();
            pirmaStrategija(studentai, vargsai, kietiakiai);
            pabaiga = high_resolution_clock::now();
            cout << "Kategorizavimo laikas (pirma strategija): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            issaugotiStudentusIFaila("vargsai_vector_pirma_" + failas, vargsai);
            issaugotiStudentusIFaila("kietiakiai_vector_pirma_" + failas, kietiakiai);
        }

        {
            cout << "\nAntra strategija su vector failu: " << failas << endl;

            vector<Studentas> studentai, vargsai;

            auto pradzia = high_resolution_clock::now();
            nuskaitytiStudentus(failas, studentai);
            auto pabaiga = high_resolution_clock::now();
            cout << "Duomenu nuskaitymo laikas: " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            pradzia = high_resolution_clock::now();
            antraStrategija(studentai, vargsai);
            pabaiga = high_resolution_clock::now();
            cout << "Kategorizavimo laikas (antra strategija): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            issaugotiStudentusIFaila("vargsai_vector_antra_" + failas, vargsai);
            issaugotiStudentusIFaila("kietiakiai_vector_antra_" + failas, studentai);
        }

        {
            cout << "\nTrečia strategija su vector failu: " << failas << endl;

            vector<Studentas> studentai, vargsai;

            auto pradzia = high_resolution_clock::now();
            nuskaitytiStudentus(failas, studentai);
            auto pabaiga = high_resolution_clock::now();
            cout << "Duomenu nuskaitymo laikas: " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            pradzia = high_resolution_clock::now();
            treciaStrategija(studentai, vargsai);
            pabaiga = high_resolution_clock::now();
            cout << "Kategorizavimo laikas (trečia strategija): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            issaugotiStudentusIFaila("vargsai_vector_trecia_" + failas, vargsai);
            issaugotiStudentusIFaila("kietiakiai_vector_trecia_" + failas, studentai);
        }

        cout << "----------------------------------------------\n" << endl;
    }

    return 0;
}
