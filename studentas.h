
#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "mylib.h"

class Studentas {
private:
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas;

public:
   
    Studentas();

    Studentas(const Studentas& other);

    Studentas& operator=(const Studentas& other);

    ~Studentas();

    friend istream& operator>>(istream& in, Studentas& s);

    friend ostream& operator<<(ostream& out, const Studentas& s);

    void skaiciuotiGalutiniBala(bool pagalVidurki);
};

#endif // STUDENTAS_H

