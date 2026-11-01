#pragma once
class date
{
public:

    date();
    date(int, int, int);
    static bool estBissextile(int);
    static bool estValide(int, int, int);
    bool operator==(const date&)const;
    bool operator<(const date&)const;
    void afficher() const;

private:

    int jour, mois, annee;
};
