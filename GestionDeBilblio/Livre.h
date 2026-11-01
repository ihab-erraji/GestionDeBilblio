#pragma once
#include "date.h"
#include <string>
using namespace std;

class Livre
{
public:

    Livre();
    void ajouterNotes(float);
    Livre(string, string, date, int);
    Livre(const Livre&);
    Livre operator=(const Livre&);
    void afficher() const;
    void affichernom() const;
    ~Livre();

private:

    const int id;
    string tittre, auteur;
    date parution;
    int* notes;
    int nbNotes;
    int c;
    static int compteurId, nbInstance;
};

