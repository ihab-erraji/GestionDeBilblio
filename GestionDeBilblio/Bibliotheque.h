#pragma once
#include "Livre.h"
#include <string>
using namespace std;

class Bibliotheque
{
private:
	string nom;
	Livre** livre;
	int capacite, nbLivre;
	static int nbBibliotheque;

public:
	Bibliotheque(string, int);
	Bibliotheque(const Bibliotheque&);
	void ajouterLivre(const Livre&);
	Bibliotheque& operator=(const Bibliotheque&);
	Bibliotheque& operator+=(const Livre&);
	void afficher() const;
    ~Bibliotheque();


};

