
#include "studentas.h"

Studentas::Studentas() : vardas(""), pavarde(""), egzaminas(0), galutinisBalas(0.0) {}

Studentas::Studentas(const Studentas& other)
    : vardas(other.vardas), pavarde(other.pavarde), namuDarbai(other.namuDarbai), egzaminas(other.egzaminas), galutinisBalas(other.galutinisBalas) {}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        namuDarbai = other.namuDarbai;
        egzaminas = other.egzaminas;
        galutinisBalas = other.galutinisBalas;
    }
    return *this;
}

Studentas::~Studentas() {
 
}

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
        << setw(10) << fixed << setprecision(2) << s.galutinisBalas;
    return out;
}


void Studentas::skaiciuotiGalutiniBala(bool pagalVidurki) {
    double namuDarbaiRezultatas = 0.0;

    if (pagalVidurki) {
       
        double vidurkis = accumulate(namuDarbai.begin(), namuDarbai.end(), 0.0) / namuDarbai.size();
        namuDarbaiRezultatas = vidurkis;
    }
    else {
        
        sort(namuDarbai.begin(), namuDarbai.end());
        if (namuDarbai.size() % 2 == 0) {
            namuDarbaiRezultatas = (namuDarbai[namuDarbai.size() / 2 - 1] + namuDarbai[namuDarbai.size() / 2]) / 2.0;
        }
        else {
            namuDarbaiRezultatas = namuDarbai[namuDarbai.size() / 2];
        }
    }

    galutinisBalas = 0.4 * namuDarbaiRezultatas + 0.6 * egzaminas;
}
