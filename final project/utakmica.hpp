#ifndef UTAKMICA_HPP_INCLUDED
#define UTAKMICA_HPP_INCLUDED

#include "osoba.hpp"
#include "igrac.hpp"
#include "tim.hpp"
#include "stattimova.hpp"

//OVDE JE SVE MAĐIJJJAAAAA

class Utakmica{
private:
    int idutakmice; // verovatno će se promeniti nakon ovog roka,
    Tim tim1, tim2;
 // int kolo;
    int tim1poena, tim2poena;

public:
    Utakmica(int utakmica_idutakmice, Tim t1, Tim t2, int utakmica_tim1poena, int utakmica_tim2poena):tim1(t1), tim2(t2){
    idutakmice = utakmica_idutakmice;
    tim1poena = utakmica_tim1poena;
    tim2poena = utakmica_tim2poena;
    }
};

#endif // UTAKMICA_HPP_INCLUDED
