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
    void utakmicaispis(){
        cout<<"DOMACIN: "<<tim1.naziv<<endl;
        cout<<"GOST   : "<<tim2.naziv<<endl;
    }
    float home, draw, away;
    void racunanjekvota(int random2, int random3){
        if(tim1.getRTG() > tim2.getRTG()){
            away = 2.0;
            draw = 3.0;
            home = 1.5;
            cout<<home<<" "<<draw<<" "<< away << endl;
        }
        else if(tim2.getRTG() > tim1.getRTG()){
            home = 2.0;
            draw = 3.0;
            away = 1.5;
            cout<<home<<" "<<draw<<" "<< away << endl;
        }
        else{
            home = 2.0;
            draw = 1.5;
            away = 2.0;
            cout<<home<<" "<<draw<<" "<< away << endl;
        }
    }

    int ispisrezultata(int random2, int random3, char placeBet, int status, int ulog){
        system("cls");
        cout<<tim1.getNaziv()<<" "<<random2<< " : " << random3 << tim2.getNaziv()<<endl;
        char result;
        if(random2 > random3){result = 'H';}
        if(random2 == random3){result = 'D';}
        if(random2 < random3){result = 'A';}
        if(tim1.getRTG() > tim2.getRTG()){
            away = 2.0;
            draw = 3.0;
            home = 1.5;
                if(placeBet == result && placeBet == 'H'){status = status * home; return status;}
                else if(placeBet == result && placeBet == 'D'){status = status * draw; return status;}
                else if(placeBet == result && placeBet == 'A'){status = status * away; return status;}
                else{status = status - ulog;cout<<status<<endl; return status;}
            cout<<home<<" "<<draw<<" "<< away << endl;
        }
        else if(tim2.getRTG() > tim1.getRTG()){
            home = 2.0;
            draw = 3.0;
            away = 1.5;
                if(placeBet == result && placeBet == 'H'){status = status * home; return status;}
                else if(placeBet == result && placeBet == 'D'){status = status * draw; return status;}
                else if(placeBet == result && placeBet == 'A'){status = status * away; return status;}
                else{status = status - ulog;cout<<status<<endl;return status;}
            cout<<home<<" "<<draw<<" "<< away << endl;
        }
        else{
            home = 2.0;
            draw = 1.5;
            away = 2.0;
                if(placeBet == result && placeBet == 'H'){status = status * home; return status;}
                else if(placeBet == result && placeBet == 'D'){status = status * draw; return status;}
                else if(placeBet == result && placeBet == 'A'){status = status * away; return status;}
                else{status = status - ulog;cout<<status<<endl;return status;}
            cout<<home<<" "<<draw<<" "<< away << endl;
        }
    }
};

#endif // UTAKMICA_HPP_INCLUDED
