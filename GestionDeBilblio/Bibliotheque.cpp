#include "Bibliotheque.h"
#include <iostream>

int Bibliotheque::nbBibliotheque = 0;
Bibliotheque::Bibliotheque(string nom, int cap) :nom(nom), capacite(cap), nbLivre(0)
{
	if (cap <= 0)
		cout << "Capacite invalide" << endl;

	livre = new Livre * [cap];

	for (int i = 0; i < capacite; i++) 
	{
	    livre[i] = nullptr;
    }

	nbBibliotheque++;
}
	

Bibliotheque::Bibliotheque(const Bibliotheque& B):nom(B.nom),capacite(B.capacite), nbLivre(B.nbLivre)
{
	livre = new Livre * [B.capacite];
	if(nbLivre==0)
	{
		for (int i = 0; i < capacite; i++)
			livre[i] = nullptr;
	}
	else {
		for (int i = 0; i < B.nbLivre; i++)
		{
			livre[i] = new Livre(*B.livre[i]);
		}
	}
	
	

	nbBibliotheque++;
}

void Bibliotheque::ajouterLivre(const Livre& M)
{
	if (nbLivre >= capacite)
	{
		cout << "Le tableau des livres est sature !" << endl;
		return;
	}

	livre[nbLivre] = new Livre(M);
	nbLivre++;
}

Bibliotheque& Bibliotheque::operator=(const Bibliotheque& B)
{
	if (this == &B)
		return *this;


	this->capacite = B.capacite;
	this->nbLivre = B.nbLivre;
	this->nom = B.nom;
	this->livre = new Livre * [B.capacite];
	if (nbLivre == 0)
	{
		for (int i = 0; i < capacite; i++)
			this->livre[i] = nullptr;
	}
	else {
		for (int i = 0; i < B.nbLivre; i++)
		{
			this->livre[i] = new Livre(*B.livre[i]);
		}
	}

	return *this;
}

Bibliotheque& Bibliotheque::operator+=(const Livre& M)
{
	this->ajouterLivre(M);
	return *this;
}

void Bibliotheque::afficher() const
{
	cout << "-La bibliotheque " << nom << " :" << endl ;
	if (nbLivre==0) {
		cout << "  La bibliotheque " << nom << "est vide!" << endl;
	}
	else {
		cout << "  nombres de livre : " << nbLivre << endl;
		for (int y = 0; y < nbLivre ; y++) {

			livre[y]->affichernom();
		
		}
	}

}

Bibliotheque::~Bibliotheque()
{
	for (int l = 0; l < capacite; l++) 
	{
		delete livre[l];
	}
	delete[] livre;
	nbBibliotheque--;
}

