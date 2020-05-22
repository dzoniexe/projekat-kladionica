#ifndef TIM_HPP_INCLUDED
#define TIM_HPP_INCLUDED
#include <string>
#include <vector>

#include "osoba.hpp"
#include "igrac.hpp"
#include "stattimova.hpp"

//Ova klasa je poprilično zeznuta - meni
//Najveći problem mi je računanje kvota, i zbog toga je u ovoj klasi i fansupport, uticaj menadzera... i slično

//Od kompleksnosti matematičkih jednačina izračunavanja kvota i simulacije meča zavisi da li će te "nebitne" stvari ostati

using namespace std;

class Tim:public StatTimova
{
private:
    string naziv;//ime tima
    string mesto;//odakle je
    vector<Igrac*> postava;//skup igrača koji su pod vlasništvom tima
    string trener;//glavni baja
    int rating;//koliko je tim jak, zbir rejtinga igrača koji su u prvom timu - verovatno, ako ne promenim
//    string stadion;
//    int fansupport;
public:
    // Ovo ispod ne zaboravi da promeniš kada menjaš prajvet

    int i = 1;

    Tim(string tim_naziv, string tim_mesto, string tim_trener, int tim_rating, int tim_pobede, int tim_porazi, int tim_bodovi, int tim_golovidati, int tim_goloviprimljeni):StatTimova(tim_pobede, tim_porazi, tim_bodovi, tim_golovidati, tim_goloviprimljeni)
    {
        naziv = tim_naziv;
        mesto = tim_mesto;
        trener = tim_trener;               //TRENERA NE ZABORAVI DA NAPRAVIŠ KLASU MENADZER, OVO JE KRŠ
        rating = tim_rating;
    }

    void dodaj(Igrac* igr)
    {
        postava.push_back(igr);
    }


    void ispisiInfoTim()
    {
        cout<< naziv <<" (";//Naziv tima
        cout<< mesto <<") ";//Mesto


        StatTimova::ispisiInfoTim();
        cout<<"POSTAVA: "<<endl;
        for (auto it=postava.begin(); it<postava.end(); it++)
        {
            cout<<i<<" ";
            (*it)->predstavise();
            i++;
        }
        cout<<endl;
        cout<<"Menadzer: "<< trener <<endl;
        cout<<"Rating: "<< rating <<endl;

        cout<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<endl;
    }
    void ispisiInfoTimBezPostave()
    {
        cout<< naziv <<" (";//Naziv tima
        cout<< mesto <<") ";//Mesto


        StatTimova::ispisiInfoTim();
     /*   cout<<"POSTAVA: "<<endl;
        for (auto it=postava.begin(); it<postava.end(); it++)
        {
            cout<<i<<" ";
            (*it)->predstavise();
            i++;
        }
        cout<<endl;
        cout<<"Menadzer: "<< trener <<endl;
        cout<<"Rating: "<< rating <<endl;
*/
        cout<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<endl;
    }
};

#endif // TIM_HPP_INCLUDED
