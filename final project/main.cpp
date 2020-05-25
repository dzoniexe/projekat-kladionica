#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>

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

//P.S. Neke stvari su zbrzane da bi kod radio (primeti se šta), sve greške i gluposti nameštam za konačnu predaju,
//za ovaj rok ponestalo vremena

//Korisnik će trebati da se uloguje, registruje... Nisam stigao da to napišem, biće za kraj

// Zaista sam se potrudio da uradim kako treba
// Boli me glava

void startermeni();
void menikladionica();
void ispisiInfoTimPoziv();
void ispisiUcinakTimova();
void premenu();
void playgames();
void ulazmeni();

using namespace std;



vector<string> splitSen(string str, char c=',')
{
    string w = "";
    vector<string> v;
    for (auto rem : str)
    {
        if (rem==c)
        {
            v.push_back(w);
            w="";
        }
        else
        {
            w=w+rem;
        }
    }
    v.push_back(w);

    return v;
}



void ucitajKorisnike(vector<Korisnik> *korisnici)
{
        string linija;
        vector<string> result;
        ifstream fajl ("korisnik.txt");

        if (fajl.is_open())
        {
            while (getline(fajl,linija))
            {
                if (linija!="")
                {
                    result = splitSen(linija,'|');
                    Korisnik k(result[0], result[1],result[2], result[3], stoi(result[4]));
                    korisnici->push_back(k);
                }
            }
            fajl.close();
        }

        else
            cout << "Neuspesno otvoren fajl"<<endl;
}



void Registracija(vector<Korisnik> *korisnici)
{

    cout<<"Ime: "<<endl;
    string i;
    cin>>i;
    cout<<"Prezime: "<<endl;
    string p;
    cin>>p;
    cout<<"Username: "<<endl;
    string user;
    cin>>user;
    cout<<"Sifra: "<<endl;
    string pas;
    cin>>pas;
    cout<<"Ponovite sifru: "<<endl;
    string pas1;
    cin>>pas1;
    while(pas1!=pas){
            cout<<"Sifre se ne poklapaju: ";
            cin>>pas1;
    }
    Korisnik a(i,p,user,pas,1000);
    a.pisiTxt('a');
    korisnici->push_back(a);
    return;
}




void Login(vector<Korisnik> *a)
{
    cout<<"Ime: ";
    string im;
    cin>>im;
    cout<<"Username: ";
    string user;
    cin>>user;
    cout<<"Password: ";
    string pas;
    cin>>pas;
    cout<<endl;
    ucitajKorisnike(a);
    int i=0;
    while(i<a->size())
    {
        if(a->at(i).Login(im,user,pas)==true){
                startermeni();
            return;
        }
        i++;
    }
    cout<<"Akaunt ne postoji."<<endl;
    cout<<"1. Login"<<endl;
    cout<<"2. Registracija"<<endl;
    cout<<"0. Nazad"<<endl;
    int br;
    cin>>br;
    if(br==1)
        Login(a);
    else if(br==2)
    {
        Registracija(a);
        Login(a);
    }
    else
        return;

}














int main()
{

 //   Registracija(&k);
  //  Login(&k);
    ulazmeni();



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
            cout<<"!!!44810!!!"<<endl;
            break;
        }
    }
    while(izbor!='X');

}


void ulazmeni(){

    vector<Korisnik> k;
    ucitajKorisnike(&k);

    char pritisni;



    char izbor;

    do
    {
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*    Dobrodosli u BetBet!    *"<<endl;
        cout<<"******************************"<<endl;
        cout<<"*      IZABERI OPCIJU:       *"<<endl;
        cout<<"* R - REGISTRACIJA           *"<<endl;
        cout<<"* L - LOGIN                  *"<<endl;
        cout<<"* X - EXIT                   *"<<endl;
        cout<<"******************************"<<endl;
        cin>>izbor;
        switch(izbor)
        {
        case 'R':
            Registracija(&k);
            break;

        case 'L':

            Login(&k);
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


    int status =1000;


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
        case 'P':{
            system("cls");
            cout<<"Radi ti kod smekeru, najjaci si!"<<endl;
            char pritisnix;

            playgames();
            break;}
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

    Igrac i11("Marko", "Skrbic", 16, 1, 65, "golman");
    Igrac i12("Petar", "Dragic", 16, 2, 75, "odbrana");
    Igrac i13("Stefan", "Jevric", 17, 7, 23, "sredina");
    Igrac i14("Zvonko", "Ivan", 31, 9, 91, "sredina");
    Igrac i15("Ranko", "Nije", 23, 44180, 99, "napad");

    Igrac i16("Vladislav", "Nikolic", 16, 1, 75, "golman");
    Igrac i17("Lignjoslav", "Pipak", 16, 2, 99, "odbrana");
    Igrac i18("Arkan", "Jevric", 17, 7, 89, "sredina");
    Igrac i19("Uros", "Jovanovic", 31, 9, 11, "sredina");
    Igrac i20("Bogdan", "Ilic", 23, 44180, 99, "napad");


    int ukupniRating1 = (i1.getRTG() + i2.getRTG() + i3.getRTG() + i4.getRTG() + i5.getRTG())/5;
    int ukupniRating2 = (i6.getRTG() + i7.getRTG() + i8.getRTG() + i9.getRTG() + i10.getRTG())/5;
    int ukupniRating3 = (i11.getRTG() + i12.getRTG() + i13.getRTG() + i14.getRTG() + i15.getRTG())/5;
    int ukupniRating4 = (i16.getRTG() + i17.getRTG() + i18.getRTG() + i19.getRTG() + i20.getRTG())/5;


    Tim t1("Crveni", "Novi Sad", "Sinisa Srdzanu", ukupniRating1, 0, 0, 0, 0, 0);
    Tim t2("Plavi", "Beograd", "Milan Savic", ukupniRating2, 0, 0, 0, 0, 0);
    Tim t3("Zeleni", "Zrenjanin", "Nikola Petric", ukupniRating3, 0, 0, 0, 0, 0);
    Tim t4("Zuti", "Srbobran", "Nenad Lukic", ukupniRating4, 0, 0, 0, 0, 0);

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

    Igrac i11("Marko", "Skrbic", 16, 1, 65, "golman");
    Igrac i12("Petar", "Dragic", 16, 2, 75, "odbrana");
    Igrac i13("Stefan", "Jevric", 17, 7, 23, "sredina");
    Igrac i14("Zvonko", "Ivan", 31, 9, 91, "sredina");
    Igrac i15("Ranko", "Nije", 23, 44180, 99, "napad");

    Igrac i16("Vladislav", "Nikolic", 16, 1, 75, "golman");
    Igrac i17("Lignjoslav", "Pipak", 16, 2, 99, "odbrana");
    Igrac i18("Arkan", "Jevric", 17, 7, 89, "sredina");
    Igrac i19("Uros", "Jovanovic", 31, 9, 11, "sredina");
    Igrac i20("Bogdan", "Ilic", 23, 44180, 99, "napad");


    int ukupniRating1 = (i1.getRTG() + i2.getRTG() + i3.getRTG() + i4.getRTG() + i5.getRTG())/5;
    int ukupniRating2 = (i6.getRTG() + i7.getRTG() + i8.getRTG() + i9.getRTG() + i10.getRTG())/5;
    int ukupniRating3 = (i11.getRTG() + i12.getRTG() + i13.getRTG() + i14.getRTG() + i15.getRTG())/5;
    int ukupniRating4 = (i16.getRTG() + i17.getRTG() + i18.getRTG() + i19.getRTG() + i20.getRTG())/5;


    Tim t1("Crveni", "Novi Sad", "Sinisa Srdzanu", ukupniRating1, 0, 0, 0, 0, 0);
    Tim t2("Plavi", "Beograd", "Milan Savic", ukupniRating2, 0, 0, 0, 0, 0);
    Tim t3("Zeleni", "Zrenjanin", "Nikola Petric", ukupniRating3, 0, 0, 0, 0, 0);
    Tim t4("Zuti", "Srbobran", "Nenad Lukic", ukupniRating4, 0, 0, 0, 0, 0);

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

void playgames()
{

    int status = 1000;

    vector<Korisnik> k;
    cout<<"Danasnja utakmica: "<<endl;

    unsigned int random1, random2, random3;
    srand(unsigned(time(NULL)));
    random1 = rand()%12+1;
    random2 = rand()%5+1;
    random3 = rand()%5+1;

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

    Igrac i11("Marko", "Skrbic", 16, 1, 65, "golman");
    Igrac i12("Petar", "Dragic", 16, 2, 75, "odbrana");
    Igrac i13("Stefan", "Jevric", 17, 7, 23, "sredina");
    Igrac i14("Zvonko", "Ivan", 31, 9, 91, "sredina");
    Igrac i15("Ranko", "Nije", 23, 44180, 99, "napad");

    Igrac i16("Vladislav", "Nikolic", 16, 1, 75, "golman");
    Igrac i17("Lignjoslav", "Pipak", 16, 2, 99, "odbrana");
    Igrac i18("Arkan", "Jevric", 17, 7, 89, "sredina");
    Igrac i19("Uros", "Jovanovic", 31, 9, 11, "sredina");
    Igrac i20("Bogdan", "Ilic", 23, 44180, 99, "napad");


    int ukupniRating1 = (i1.getRTG() + i2.getRTG() + i3.getRTG() + i4.getRTG() + i5.getRTG())/5;
    int ukupniRating2 = (i6.getRTG() + i7.getRTG() + i8.getRTG() + i9.getRTG() + i10.getRTG())/5;
    int ukupniRating3 = (i11.getRTG() + i12.getRTG() + i13.getRTG() + i14.getRTG() + i15.getRTG())/5;
    int ukupniRating4 = (i16.getRTG() + i17.getRTG() + i18.getRTG() + i19.getRTG() + i20.getRTG())/5;


    Tim t1("Crveni", "Novi Sad", "Sinisa Srdzanu", ukupniRating1, 0, 0, 0, 0, 0);
    Tim t2("Plavi", "Beograd", "Milan Savic", ukupniRating2, 0, 0, 0, 0, 0);
    Tim t3("Zeleni", "Zrenjanin", "Nikola Petric", ukupniRating3, 0, 0, 0, 0, 0);
    Tim t4("Zuti", "Srbobran", "Nenad Lukic", ukupniRating4, 0, 0, 0, 0, 0);

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





    char placeBet;
    int ulog;
    switch(random1)
    {
    case 1:
    {

        Utakmica u1(1, t1, t4, 0, 0);
        u1.utakmicaispis();
        u1.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status = u1.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
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
        break;
    }
    case 2:
    {

        Utakmica u2(2, t4, t1, 0, 0);
        u2.utakmicaispis();
        u2.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status =  u2.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
        char pritisnix1;
        do
        {


            cout<<endl;
            cout<<"Pritisni X da se vratis nazad"<<endl;
            cin>>pritisnix1;
            if(pritisnix1 != 'X')
            {
                cout<<"Probaj ponovo"<<endl;
            }

        }
        while(pritisnix1!= 'X');
        break;
    }
    case 3:
    {

        Utakmica u3(3, t1, t3, 0, 0);
        u3.utakmicaispis();
        u3.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status = u3.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
        char pritisnix2;
        do
        {


            cout<<endl;
            cout<<"Pritisni X da se vratis nazad"<<endl;
            cin>>pritisnix2;
            if(pritisnix2 != 'X')
            {
                cout<<"Probaj ponovo"<<endl;
            }

        }
        while(pritisnix2 != 'X');
        break;
    }
    case 4:
    {

        Utakmica u4(4, t3, t1, 0, 0);
        u4.utakmicaispis();
        u4.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status = u4.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
        char pritisnix3;
        do
        {


            cout<<endl;
            cout<<"Pritisni X da se vratis nazad"<<endl;
            cin>>pritisnix3;
            if(pritisnix3 != 'X')
            {
                cout<<"Probaj ponovo"<<endl;
            }

        }
        while(pritisnix3 != 'X');
        break;
    }
    case 5:
    {

        Utakmica u5(5, t1, t2, 0, 0);
        u5.utakmicaispis();
        u5.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status = u5.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
        char pritisnix4;
        do
        {


            cout<<endl;
            cout<<"Pritisni X da se vratis nazad"<<endl;
            cin>>pritisnix4;
            if(pritisnix4 != 'X')
            {
                cout<<"Probaj ponovo"<<endl;
            }

        }
        while(pritisnix4 != 'X');
        break;
    }
    case 6:
    {

        Utakmica u6(6, t2, t1, 0, 0);
        u6.utakmicaispis();
        u6.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status = u6.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
        char pritisnix5;
        do
        {


            cout<<endl;
            cout<<"Pritisni X da se vratis nazad"<<endl;
            cin>>pritisnix5;
            if(pritisnix5 != 'X')
            {
                cout<<"Probaj ponovo"<<endl;
            }

        }
        while(pritisnix5 != 'X');
        break;
    }
    case 7:
    {

        Utakmica u7(7, t2, t3, 0, 0);
        u7.utakmicaispis();
        u7.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status = u7.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
        char pritisnix6;
        do
        {


            cout<<endl;
            cout<<"Pritisni X da se vratis nazad"<<endl;
            cin>>pritisnix6;
            if(pritisnix6 != 'X')
            {
                cout<<"Probaj ponovo"<<endl;
            }

        }
        while(pritisnix6 != 'X');
        break;
    }
    case 8:
    {

        Utakmica u8(8, t3, t2, 0, 0);
        u8.utakmicaispis();
        u8.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status = u8.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
        char pritisnix7;
        do
        {


            cout<<endl;
            cout<<"Pritisni X da se vratis nazad"<<endl;
            cin>>pritisnix7;
            if(pritisnix7 != 'X')
            {
                cout<<"Probaj ponovo"<<endl;
            }

        }
        while(pritisnix7 != 'X');
        break;
    }
    case 9:
    {

        Utakmica u9(9, t2, t4, 0, 0);
        u9.utakmicaispis();
        u9.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status = u9.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
        char pritisnix8;
        do
        {


            cout<<endl;
            cout<<"Pritisni X da se vratis nazad"<<endl;
            cin>>pritisnix8;
            if(pritisnix8 != 'X')
            {
                cout<<"Probaj ponovo"<<endl;
            }

        }
        while(pritisnix8 != 'X');
        break;
    }
    case 10:
    {

        Utakmica u10(10, t4, t2, 0, 0);
        u10.utakmicaispis();
        u10.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status = u10.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
        char pritisnix9;
        do
        {


            cout<<endl;
            cout<<"Pritisni X da se vratis nazad"<<endl;
            cin>>pritisnix9;
            if(pritisnix9 != 'X')
            {
                cout<<"Probaj ponovo"<<endl;
            }

        }
        while(pritisnix9 != 'X');
        break;
    }
    case 11:
    {

        Utakmica u11(11, t3, t4, 0, 0);
        u11.utakmicaispis();
        u11.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status = u11.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
        char pritisnix10;
        do
        {


            cout<<endl;
            cout<<"Pritisni X da se vratis nazad"<<endl;
            cin>>pritisnix10;
            if(pritisnix10 != 'X')
            {
                cout<<"Probaj ponovo"<<endl;
            }

        }
        while(pritisnix10 != 'X');
        break;
    }
    case 12:
    {

        Utakmica u12(12, t4, t3, 0, 0);
        u12.utakmicaispis();
        u12.racunanjekvota(random2, random3);
        cout<<"H - HOME WILL WIN "<<endl;
        cout<<"D - THE GAME WILL BE DRAW "<<endl;
        cout<<"A - AWAY WILL WIN "<<endl;
        cout<<"Place your bet and ulog: "<<endl;
        cout<<"status: "<<status<<endl;
        cin>>placeBet;
        cin>>ulog;

        status = u12.ispisrezultata(random2, random3, placeBet, status, ulog);//status će biti u korisniku, prvo sam ga ispisao, pa mi se nije svideo, i sada privremeno koristim ovako
        char pritisnix12;
        do
        {


            cout<<endl;
            cout<<"Pritisni X da se vratis nazad"<<endl;
            cin>>pritisnix12;
            if(pritisnix12 != 'X')
            {
                cout<<"Probaj ponovo"<<endl;
            }

        }
        while(pritisnix12 != 'X');
        break;
    }
    }

}

