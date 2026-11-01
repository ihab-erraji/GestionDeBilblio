#include "Livre.h"
#include <iostream>

int Livre::compteurId = 0;
int Livre::nbInstance = 0;

Livre::Livre():id(++compteurId){}

void Livre::ajouterNotes(float v)
{
   
    if (c < this->nbNotes) {
        if (v >= 0 && v <= 20)
            this->notes[++this->c] = v;
        else cout << "note non valide ! ( 0 <= note <= 20) " << endl;
    }else cout << "Nombre maximal de notes atteint !" << endl;
   
}

Livre::Livre(string t, string a, date d, int nb) :id(++compteurId), tittre(t), auteur(a), parution(d), nbNotes(nb),c(-1)
{
    this->notes = new int[nb];
    nbInstance++;
}

Livre::Livre(const Livre& L) :id(++compteurId),c(-1)
{
    this->auteur = L.auteur;
    this->tittre = L.tittre;
    this->parution = L.parution;
    this->notes = new int[L.nbNotes];
    this->nbNotes = L.nbNotes;
    nbInstance++;
}

Livre Livre::operator=(const Livre& L)
{
    return Livre(L.tittre,L.auteur,L.parution,L.nbNotes);
}

void Livre::afficher() const
{ 
    float S = 0;
    cout << "informations du livre " << id << " :" << endl;
    cout << "  -Titre: " << tittre << endl;
    cout << "  -Auteur: " << auteur << endl;
    cout << "  -Parution: "; this->parution.afficher();
    cout << "  -Les notes du livre " << id << " :" << endl;
    if(c==-1)
        cout << "Il n'existe aucune note!" << endl;
    else {
        for (int p = 0; p <= c; p++) {
            cout << "      -Note" << p + 1 << " : " << notes[p] << endl;
            S += notes[p];
        }
        cout << "  -la moyenne des notes est: " << (S / (c + 1)) << endl;
    } 
}

void Livre::affichernom() const
{
    cout << "  -Livre " << tittre << endl;
}

Livre::~Livre()
{
    delete[] notes;
    nbInstance--;
}
