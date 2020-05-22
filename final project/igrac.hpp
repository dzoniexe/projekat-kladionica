#ifndef IGRAC_HPP_INCLUDED
#define IGRAC_HPP_INCLUDED
#include <string>

#include "osoba.hpp"

//Ovde osoba učestvuje kao igrač na terenu.
//Dobija svoj broj po čemu će se tražiti u fajlu - ako se odlučim da koristim fajlove za to-

using namespace std;

enum Pozicija {golman, odbrana, sredina, napad};

class Igrac:public Osoba
{
private:
    int broj;
    string pozicija;
    //nešto ovde fali
public:
        int rating;//OVO VRATI U PRIVATE, U PUBLICU JE SAMO TBOG TESTA
  //  Igrac():Osoba("Teodor", "Perunicic", 16), broj(1), rating(60), pozicija("odbrana") {};

    Igrac(string igrac_ime, string igrac_prezime, int igrac_godine, int igrac_broj, int igrac_rating, string igrac_pozicija):Osoba(igrac_ime, igrac_prezime, igrac_godine)
    {
        broj = igrac_broj;
        rating = igrac_rating;
        pozicija = igrac_pozicija;
    };

    void predstavise ()
    {
        Osoba::predstavise();
        cout << "BR: " << broj << " RTG: " << rating << " POS: " << pozicija << endl;

    }
    int getRTG(){return rating;}
};

#endif // IGRAC_HPP_INCLUDED
