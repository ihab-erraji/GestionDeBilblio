// GestionDeBilblio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bibliotheque.h"

int main()
{
	date D(16, 12, 2005);
	D.afficher();
	Livre M("life", "IHAB", D, 3);
	Livre p("life", "IHAB", D, 3);
	Livre l("life", "IHAB", D, 3);
	M.afficher();
	M.ajouterNotes(15);
	M.ajouterNotes(20);
	M.ajouterNotes(18);
	M.afficher();
	Bibliotheque B("HALL", 3);
	//B.afficher();
	B.ajouterLivre(M);
	B.ajouterLivre(p);
	B.ajouterLivre(l);
	B.afficher();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
