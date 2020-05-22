#ifndef MENADZER_HPP_INCLUDED
#define MENADZER_HPP_INCLUDED

#include <string>

#include "osoba.hpp"
#include "igrac.hpp"
#include "tim.hpp"
#include "stattimova.hpp"

class Menadzer:public Osoba{
private:
    bool bioIgrac;
    string drzava;
    int rating;
public:
    Igrac(string menadzer_ime, string menadzer_prezime, int menadzer_godine, bool menadzer_bioIgrac, string menadzer_drzava, int menadzer_rating):Osoba(igrac_ime, igrac_prezime, igrac_godine)
    {
        bioIgrac = menadzer_bioIgrac;
        drzava = menadzer_drzava;
        rating = menadzer_rating;
    };

};

#endif // MENADZER_HPP_INCLUDED
