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
void kategorizuotiStudentus(Container& studentai, Container& vargsai, Container& kietiakiai) {
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
            cout << "Testavimas su vector failu: " << failas << endl;

            vector<Studentas> studentai, vargsai, kietiakiai;

            auto pradzia = high_resolution_clock::now();
            nuskaitytiStudentus(failas, studentai);
            auto pabaiga = high_resolution_clock::now();
            cout << "Duomenu nuskaitymo laikas (vector): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            pradzia = high_resolution_clock::now();
            kategorizuotiStudentus(studentai, vargsai, kietiakiai);
            pabaiga = high_resolution_clock::now();
            cout << "Kategorizavimo laikas (vector): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            pradzia = high_resolution_clock::now();
            issaugotiStudentusIFaila("vargsai_vector_" + failas, vargsai);
            issaugotiStudentusIFaila("kietiakiai_vector_" + failas, kietiakiai);
            pabaiga = high_resolution_clock::now();
            cout << "Failu issaugojimo laikas (vector): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;
        }

        {
            cout << "\nTestavimas su list failu: " << failas << endl;

            list<Studentas> studentai, vargsai, kietiakiai;

            auto pradzia = high_resolution_clock::now();
            nuskaitytiStudentus(failas, studentai);
            auto pabaiga = high_resolution_clock::now();
            cout << "Duomenu nuskaitymo laikas (list): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            pradzia = high_resolution_clock::now();
            kategorizuotiStudentus(studentai, vargsai, kietiakiai);
            pabaiga = high_resolution_clock::now();
            cout << "Kategorizavimo laikas (list): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            pradzia = high_resolution_clock::now();
            issaugotiStudentusIFaila("vargsai_list_" + failas, vargsai);
            issaugotiStudentusIFaila("kietiakiai_list_" + failas, kietiakiai);
            pabaiga = high_resolution_clock::now();
            cout << "Failu issaugojimo laikas (list): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;
        }

        {
            cout << "\nTestavimas su deque failu: " << failas << endl;

            deque<Studentas> studentai, vargsai, kietiakiai;

            auto pradzia = high_resolution_clock::now();
            nuskaitytiStudentus(failas, studentai);
            auto pabaiga = high_resolution_clock::now();
            cout << "Duomenu nuskaitymo laikas (deque): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            pradzia = high_resolution_clock::now();
            kategorizuotiStudentus(studentai, vargsai, kietiakiai);
            pabaiga = high_resolution_clock::now();
            cout << "Kategorizavimo laikas (deque): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;

            pradzia = high_resolution_clock::now();
            issaugotiStudentusIFaila("vargsai_deque_" + failas, vargsai);
            issaugotiStudentusIFaila("kietiakiai_deque_" + failas, kietiakiai);
            pabaiga = high_resolution_clock::now();
            cout << "Failu issaugojimo laikas (deque): " << duration_cast<milliseconds>(pabaiga - pradzia).count() << " ms" << endl;
        }

        cout << "----------------------------------------------\n" << endl;
    }

    return 0;
}
