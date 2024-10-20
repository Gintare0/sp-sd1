#include "studentas.h"

Studentas::Studentas() : vardas(""), pavarde(""), egzaminas(0), galutinisVidurkis(0), galutinisMediana(0) {}

Studentas::Studentas(const Studentas& other) {
    vardas = other.vardas;
    pavarde = other.pavarde;
    namuDarbai = other.namuDarbai;
    egzaminas = other.egzaminas;
    galutinisVidurkis = other.galutinisVidurkis;
    galutinisMediana = other.galutinisMediana;
}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        namuDarbai = other.namuDarbai;
        egzaminas = other.egzaminas;
        galutinisVidurkis = other.galutinisVidurkis;
        galutinisMediana = other.galutinisMediana;
    }
    return *this;
}

Studentas::~Studentas() {}

void Studentas::skaiciuotiGalutiniBala() {
    double suma = accumulate(namuDarbai.begin(), namuDarbai.end(), 0.0);
    double vidurkis = suma / namuDarbai.size();
    galutinisVidurkis = 0.4 * vidurkis + 0.6 * egzaminas;

    sort(namuDarbai.begin(), namuDarbai.end());
    if (namuDarbai.size() % 2 == 0) {
        galutinisMediana = 0.4 * ((namuDarbai[namuDarbai.size() / 2 - 1] + namuDarbai[namuDarbai.size() / 2]) / 2.0) + 0.6 * egzaminas;
    }
    else {
        galutinisMediana = 0.4 * namuDarbai[namuDarbai.size() / 2] + 0.6 * egzaminas;
    }
}

istream& operator>>(istream& in, Studentas& s) {
    in >> s.vardas >> s.pavarde;
    s.namuDarbai.clear();
    int nd;
    for (int i = 0; i < 5; ++i) {
        if (in >> nd) {
            s.namuDarbai.push_back(nd);
        }
    }
    in >> s.egzaminas;
    s.skaiciuotiGalutiniBala();
    return in;
}

ostream& operator<<(ostream& out, const Studentas& s) {
    out << setw(15) << left << s.pavarde
        << setw(15) << s.vardas
        << setw(20) << fixed << setprecision(2) << s.galutinisVidurkis
        << setw(20) << fixed << setprecision(2) << s.galutinisMediana;
    return out;
}

vector<Studentas> Studentas::nuskaitytiIsFailo(const string& failoPavadinimas) {
    vector<Studentas> studentai;
    ifstream inFile(failoPavadinimas);
    if (!inFile) {
        throw runtime_error("Failas neegzistuoja: " + failoPavadinimas);
    }

    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
        istringstream iss(line);
        Studentas s;
        iss >> s;
        studentai.push_back(s);
    }
    return studentai;
}

void Studentas::rusiuotiStudentus(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return a.pavarde < b.pavarde || (a.pavarde == b.pavarde && a.vardas < b.vardas);
        });
}
