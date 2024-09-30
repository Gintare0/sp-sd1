#include "studentas.h"
#include <random>


Studentas::Studentas() : vardas(""), pavarde(""), egzaminas(0), galutinisVidurkis(0.0), galutinisMediana(0.0) {}

Studentas::Studentas(const Studentas& other)
    : vardas(other.vardas), pavarde(other.pavarde), namuDarbai(other.namuDarbai), egzaminas(other.egzaminas),
    galutinisVidurkis(other.galutinisVidurkis), galutinisMediana(other.galutinisMediana) {}

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

istream& operator>>(istream& in, Studentas& s) {
    cout << "Įveskite studento vardą: ";
    in >> s.vardas;
    cout << "Įveskite studento pavardę: ";
    in >> s.pavarde;

    int nd;
    cout << "Įveskite namų darbų rezultatus (įveskite -1, kad baigtumėte): ";
    while (in >> nd && nd != -1) {
        s.namuDarbai.push_back(nd);
    }

    cout << "Įveskite egzamino rezultatą: ";
    in >> s.egzaminas;

    return in;
}

ostream& operator<<(ostream& out, const Studentas& s) {
    out << setw(15) << left << s.pavarde
        << setw(15) << s.vardas
        << setw(10) << fixed << setprecision(2) << s.galutinisVidurkis
        << setw(10) << s.galutinisMediana;
    return out;
}
void Studentas::skaiciuotiGalutiniBala() {
    double namuDarbaiVidurkis = accumulate(namuDarbai.begin(), namuDarbai.end(), 0.0) / namuDarbai.size();

    sort(namuDarbai.begin(), namuDarbai.end());
    double namuDarbaiMediana;
    if (namuDarbai.size() % 2 == 0) {
        namuDarbaiMediana = (namuDarbai[namuDarbai.size() / 2 - 1] + namuDarbai[namuDarbai.size() / 2]) / 2.0;
    }
    else {
        namuDarbaiMediana = namuDarbai[namuDarbai.size() / 2];
    }

    galutinisVidurkis = 0.4 * namuDarbaiVidurkis + 0.6 * egzaminas;
    galutinisMediana = 0.4 * namuDarbaiMediana + 0.6 * egzaminas;
}


void Studentas::generuotiAtsitiktiniusRezultatus(int ndKiekis) {
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(1, 10); 

    namuDarbai.clear(); 
    for (int i = 0; i < ndKiekis; ++i) {
        namuDarbai.push_back(distrib(gen)); 
    }

    egzaminas = distrib(gen);
}

