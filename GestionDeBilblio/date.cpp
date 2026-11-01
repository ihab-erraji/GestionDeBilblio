#include "date.h"
#include <iostream>
using namespace std;
date::date() : jour(1), mois(1), annee(2000) {}
date::date(int d, int m, int y) :jour(1), mois(1), annee(2000) {
    if (estValide(d, m, y)) {
        this->jour = d;
        this->mois = m;
        this->annee = y;
    }
    else cerr << "date n'est pas valide!" << endl;

}

bool date::estBissextile(int a) {

    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

bool date::estValide(int d, int m, int y)
{
    if (m >= 1 && m <= 7) {
        if (m % 2 == 0) {
            if (m != 2) {
                return d >= 1 && d <= 30;
            }
            else {
                if (estBissextile(y))
                    return d >= 1 && d <= 29;
                else return d >= 1 && d <= 28;
            }

        }
        else return d >= 1 && d <= 31;


    } else if(m<1) return false;

    if (m >= 8 && m <= 12) {
        if (m % 2 == 0)
            return d >= 1 && d <= 31;
        else return d >= 1 && d <= 30;


    }else if(m>12)
    return false;
}

bool date::operator==(const date& y)const {

    return this->annee == y.annee && this->mois == y.mois && this->jour == y.jour;
}

bool date::operator<(const date& y)const {
    if (this->annee == y.annee)
        return this->mois < y.mois;
    else return this->annee < y.annee;

    if (this->mois == y.mois)
        return this->jour < y.jour;
    else return this->mois < y.mois;

}

void date::afficher() const
{
    cout << jour << "/" << mois << "/" << annee << endl;
}
