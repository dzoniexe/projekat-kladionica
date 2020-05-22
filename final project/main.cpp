#include <iostream>
#include <string>
#include <conio.h>

#include "osoba.hpp"
#include "igrac.hpp"
#include "tim.hpp"
#include "stattimova.hpp"
#include "utakmica.hpp"
#include "korisnik.hpp"

//  cout << "Hello world!" << endl;
// !!!!!!!!! Za ovaj rok ću koristiti samo futsal, ako ne i do kraja
//Funkionalno je identično kao i fudbal, i verovatno košarka, ali neću se morati zamarati toliko oko broja igrača
//Nego ću se više fokusirati na kod

//BTW, ovo je mesto gde se magija događa

//P.S. Stvarno sam dao sve od sebe, ali nisam uspeo pre ponoći da uradim funkcionalnost. Bio sam blizu što se tiče ideje, ali nisam imao vremena da realizujem.

void startermeni();
void menikladionica();
void ispisiInfoTimPoziv();
void ispisiUcinakTimova();
void premenu();
void playgames();

using namespace std;









int main()
{

/*
    Utakmica u1(1, t1, t4, 0, 0);
    Utakmica u2(2, t4, t1, 0, 0);
    Utakmica u3(3, t1, t3, 0, 0);
    Utakmica u4(4, t3, t1, 0, 0);
    Utakmica u5(5, t1, t2, 0, 0);
    Utakmica u6(6, t2, t1, 0, 0);
    Utakmica u7(7, t2, t3, 0, 0);
    Utakmica u8(8, t3, t2, 0, 0);
    Utakmica u9(9, t2, t4, 0, 0);
    Utakmica u10(10, t4, t2, 0, 0);
    Utakmica u11(11, t3, t4, 0, 0);
    Utakmica u12(12, t4, t3, 0, 0);

*/

    int ukupniRating1;//preko ovoga računam ukupan rating tima
    int ukupniRating2;//isto kao gore
    int ukupniRating3;//isto kao gore
    int ukupniRating4;//isto kao gore

    //ZA IGRACE :::::::: Ime ; Prezime ; Godine ; Dres ; Rating ; Pozicija ;

    // PRVI TIM:

    Igrac i1("Teodor", "Perunicic", 16, 1, 97, "golman");
    Igrac i2("Andrej", "Hristic", 16, 2, 13, "odbrana");
    Igrac i3("Sava", "Gavrilovic", 17, 7, 67, "sredina");
    Igrac i4("Dragoslav", "Stojanovic", 31, 9, 73, "sredina");
    Igrac i5("Dusan", "Ivic", 23, 10, 99, "napad");

    // DRUGI TIM:

    Igrac i6("Mladen", "Filipovic", 16, 1, 97, "golman");
    Igrac i7("Isaija", "Dragic", 16, 2, 13, "odbrana");
    Igrac i8("Milos", "Jevric", 17, 7, 67, "sredina");
    Igrac i9("Vladimir", "Ivan", 31, 9, 73, "sredina");
    Igrac i10("Pa", "Nije", 23, 44180, 99, "napad");

    /*
        ukupniRating1 = (i1.rating + i2.rating + i3.rating + i4.rating + i5.rating)/5;
        ukupniRating2 = (i6.rating + i7.rating + i8.rating + i9.rating + i10.rating)/5;


    */


//    cout<<ukupniRating1<<endl;






    Tim t1("Crveni", "Novi Sad", "Sinisa Srdzanu", ukupniRating1, 0, 0, 0, 0, 0);
    Tim t2("Plavi", "Beograd", "Milan Savic", ukupniRating2, 0, 0, 0, 0, 0);
    Tim t3("Zeleni", "Zrenjanin", "Nikola Petric", 30, 0, 0, 0, 0, 0);
    Tim t4("Zuti", "Srbobran", "Nenad Lukic", 100, 0, 0, 0, 0, 0);

    t1.dodaj(&i1);
    t1.dodaj(&i2);
    t1.dodaj(&i3);
    t1.dodaj(&i4);
    t1.dodaj(&i5);

    t2.dodaj(&i6);
    t2.dodaj(&i7);
    t2.dodaj(&i8);
    t2.dodaj(&i9);
    t2.dodaj(&i10);
    /*
        t1.ispisiInfoTimBezPostave();
        t2.ispisiInfoTimBezPostave();
        t3.ispisiInfoTimBezPostave();
        t4.ispisiInfoTimBezPostave();

    */
    t1.ispisiInfoTim();
    t2.ispisiInfoTim();
    t3.ispisiInfoTim();
    t4.ispisiInfoTim();

    /*  char izbor; // za switch izbor običan


      cin>>izbor;
    */

    startermeni();



    return 0;
}

void startermeni()
{
    system("cls");
    cout<<":::DISCLAIMER:::::::::::::::::::::::"<<endl;
    cout<<":  Beta Verzija BetovenBet-a       :"<<endl;
    cout<<":  Trenutno podrzava samo futsal   :"<<endl;
    cout<<":  U buducnosti stize vise timova  :"<<endl;
    cout<<":  i vise sportova                 :"<<endl;
    cout<<":                                  :"<<endl;
    cout<<":      -Dzony from Ultimat Games   :"<<endl;
    cout<<":::DISCLAIMER:::::::::::::::::::::::"<<endl;
    char pritisni;
    do
    {


        cout<<endl;
        cout<<"Pritisni A (ADVANCE) da udjes u projekat"<<endl;
        cin>>pritisni;
        if(pritisni != 'A')
        {
            cout<<"Probaj ponovo"<<endl;
        }

    }
    while(pritisni != 'A');


    char izbor;

    do
    {
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*    Dobrodosli u BetBet!    *"<<endl;
        cout<<"******************************"<<endl;
        cout<<"*    IZABERI PROSTORIJU:     *"<<endl;
        cout<<"* B - KLADIONICA             *"<<endl;
        cout<<"* C - KAZINO (NIJE DOSTUPNO) *"<<endl;
        cout<<"* X - EXIT                   *"<<endl;
        cout<<"******************************"<<endl;
        cin>>izbor;
        switch(izbor)
        {
        case 'B':
            menikladionica();
            break;

        case 'C':
            system("cls");
            cout<<"Opcija jos nije dodata"<<endl;
            break;
        case 'X':
            system("cls");
            exit(0);
        default:
            system("cls");
            cout<<"Pa nije"<<endl;
            break;
        }
    }
    while(izbor!='X');

}

void menikladionica()
{





    char izbor;
    do
    {
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*         KLADIONICA         *"<<endl;
        cout<<"******************************"<<endl;
        cout<<"*      IZABERI OPCIJU:       *"<<endl;
        cout<<"* P - PLAY (nije dostupno)   *"<<endl;
        cout<<"* S - POSTAVA TIMOVA         *"<<endl;
        cout<<"* U - UCINAK TIMOVA          *"<<endl;
        cout<<"* X - BACK                   *"<<endl;
        cout<<"* TBA                        *"<<endl;
        cout<<"******************************"<<endl;
        cin>>izbor;
        switch(izbor)
        {
        case 'P':
            system("cls");
            cout<<"Radi ti kod smekeru, najjaci si!"<<endl;
            char pritisnix;
            playgames();
            break;
        case 'S':
            system("cls");
            ispisiInfoTimPoziv();
            break;
        case 'U':
            system("cls");
            ispisiUcinakTimova();
            break;
        case 'X':
            break;
        default:
            system("cls");
            cout<<"nema"<<endl;
            char pritisni;
            do
            {


                cout<<endl;
                cout<<"Pritisni A da se vratis nazad"<<endl;
                cin>>pritisni;
                if(pritisni != 'A')
                {
                    cout<<"Probaj ponovo"<<endl;
                }

            }
            while(pritisni != 'A');
        }
    }
    while(izbor != 'X');


}
void ispisiInfoTimPoziv()
{

    //ZA IGRACE :::::::: Ime ; Prezime ; Godine ; Dres ; Rating ; Pozicija ;

    // PRVI TIM:

    Igrac i1("Teodor", "Perunicic", 16, 1, 97, "golman");
    Igrac i2("Andrej", "Hristic", 16, 2, 13, "odbrana");
    Igrac i3("Sava", "Gavrilovic", 17, 7, 67, "sredina");
    Igrac i4("Dragoslav", "Stojanovic", 31, 9, 73, "sredina");
    Igrac i5("Dusan", "Ivic", 23, 10, 99, "napad");

    // DRUGI TIM:

    Igrac i6("Mladen", "Filipovic", 16, 1, 97, "golman");
    Igrac i7("Isaija", "Dragic", 16, 2, 13, "odbrana");
    Igrac i8("Milos", "Jevric", 17, 7, 67, "sredina");
    Igrac i9("Vladimir", "Ivan", 31, 9, 73, "sredina");
    Igrac i10("Pa", "Nije", 23, 44180, 99, "napad");

    Igrac i11("Vukasin", "Skrbic", 16, 1, 65, "golman");
    Igrac i12("Isaija", "Dragic", 16, 2, 13, "odbrana");
    Igrac i13("Milos", "Jevric", 17, 7, 67, "sredina");
    Igrac i14("Vladimir", "Ivan", 31, 9, 73, "sredina");
    Igrac i15("Pa", "Nije", 23, 44180, 99, "napad");

    Igrac i16("Vukasin", "Skrbic", 16, 1, 65, "golman");
    Igrac i17("Isaija", "Dragic", 16, 2, 13, "odbrana");
    Igrac i18("Milos", "Jevric", 17, 7, 67, "sredina");
    Igrac i19("Vladimir", "Ivan", 31, 9, 73, "sredina");
    Igrac i20("Pa", "Nije", 23, 44180, 99, "napad");


    int ukupniRating1 = (i1.rating + i2.rating + i3.rating + i4.rating + i5.rating)/5;
    int ukupniRating2 = (i6.rating + i7.rating + i8.rating + i9.rating + i10.rating)/5;
    int ukupniRating3 = (i6.rating + i7.rating + i8.rating + i9.rating + i10.rating)/5;
    int ukupniRating4 = (i6.rating + i7.rating + i8.rating + i9.rating + i10.rating)/5;


    Tim t1("Crveni", "Novi Sad", "Sinisa Srdzanu", ukupniRating1, 0, 0, 0, 0, 0);
    Tim t2("Plavi", "Beograd", "Milan Savic", ukupniRating2, 0, 0, 0, 0, 0);
    Tim t3("Zeleni", "Zrenjanin", "Nikola Petric", 30, 0, 0, 0, 0, 0);
    Tim t4("Zuti", "Srbobran", "Nenad Lukic", 100, 0, 0, 0, 0, 0);

    t1.dodaj(&i1);
    t1.dodaj(&i2);
    t1.dodaj(&i3);
    t1.dodaj(&i4);
    t1.dodaj(&i5);


    t2.dodaj(&i6);
    t2.dodaj(&i7);
    t2.dodaj(&i8);
    t2.dodaj(&i9);
    t2.dodaj(&i10);

    t3.dodaj(&i11);
    t3.dodaj(&i12);
    t3.dodaj(&i13);
    t3.dodaj(&i14);
    t3.dodaj(&i15);

    t4.dodaj(&i16);
    t4.dodaj(&i17);
    t4.dodaj(&i18);
    t4.dodaj(&i19);
    t4.dodaj(&i20);















    t1.ispisiInfoTim();
    t2.ispisiInfoTim();
    t3.ispisiInfoTim();
    t4.ispisiInfoTim();
    char pritisnix;
    do
    {


        cout<<endl;
        cout<<"Pritisni X da se vratis nazad"<<endl;
        cin>>pritisnix;
        if(pritisnix != 'X')
        {
            cout<<"Probaj ponovo"<<endl;
        }

    }
    while(pritisnix != 'X');
    return;
}
void ispisiUcinakTimova()
{

    //ZA IGRACE :::::::: Ime ; Prezime ; Godine ; Dres ; Rating ; Pozicija ;

    // PRVI TIM:

    Igrac i1("Teodor", "Perunicic", 16, 1, 97, "golman");
    Igrac i2("Andrej", "Hristic", 16, 2, 13, "odbrana");
    Igrac i3("Sava", "Gavrilovic", 17, 7, 67, "sredina");
    Igrac i4("Dragoslav", "Stojanovic", 31, 9, 73, "sredina");
    Igrac i5("Dusan", "Ivic", 23, 10, 99, "napad");

    // DRUGI TIM:

    Igrac i6("Mladen", "Filipovic", 16, 1, 97, "golman");
    Igrac i7("Isaija", "Dragic", 16, 2, 13, "odbrana");
    Igrac i8("Milos", "Jevric", 17, 7, 67, "sredina");
    Igrac i9("Vladimir", "Ivan", 31, 9, 73, "sredina");
    Igrac i10("Pa", "Nije", 23, 44180, 99, "napad");

    Igrac i11("Vukasin", "Skrbic", 16, 1, 65, "golman");
    Igrac i12("Isaija", "Dragic", 16, 2, 13, "odbrana");
    Igrac i13("Milos", "Jevric", 17, 7, 67, "sredina");
    Igrac i14("Vladimir", "Ivan", 31, 9, 73, "sredina");
    Igrac i15("Pa", "Nije", 23, 44180, 99, "napad");


    int ukupniRating1 = (i1.rating + i2.rating + i3.rating + i4.rating + i5.rating)/5;
    int ukupniRating2 = (i6.rating + i7.rating + i8.rating + i9.rating + i10.rating)/5;
    int ukupniRating3 = (i6.rating + i7.rating + i8.rating + i9.rating + i10.rating)/5;
    int ukupniRating4 = (i6.rating + i7.rating + i8.rating + i9.rating + i10.rating)/5;


    Tim t1("Crveni", "Novi Sad", "Sinisa Srdzanu", ukupniRating1, 0, 0, 0, 0, 0);
    Tim t2("Plavi", "Beograd", "Milan Savic", ukupniRating2, 0, 0, 0, 0, 0);
    Tim t3("Zeleni", "Zrenjanin", "Nikola Petric", 30, 0, 0, 0, 0, 0);
    Tim t4("Zuti", "Srbobran", "Nenad Lukic", 100, 0, 0, 0, 0, 0);

    t1.dodaj(&i1);
    t1.dodaj(&i2);
    t1.dodaj(&i3);
    t1.dodaj(&i4);
    t1.dodaj(&i5);

    t2.dodaj(&i6);
    t2.dodaj(&i7);
    t2.dodaj(&i8);
    t2.dodaj(&i9);
    t2.dodaj(&i10);

    t1.ispisiInfoTimBezPostave();
    t2.ispisiInfoTimBezPostave();
    t3.ispisiInfoTimBezPostave();
    t4.ispisiInfoTimBezPostave();
    char pritisnix;
    do
    {


        cout<<endl;
        cout<<"Pritisni X da se vratis nazad"<<endl;
        cin>>pritisnix;
        if(pritisnix != 'X')
        {
            cout<<"Probaj ponovo"<<endl;
        }

    }
    while(pritisnix != 'X');
    return;
}

void playgames(){

    cout<<"Danasnja utakmica: "<<endl;

    unsigned int random1, random2, random3;





}
