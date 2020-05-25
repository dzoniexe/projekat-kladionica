#ifndef KORISNIK_HPP_INCLUDED
#define KORISNIK_HPP_INCLUDED
#include <fstream>
class Korisnik
{
private:
    string ime;
    string prezime;
    string password;
    string username;
    int status;


public:
    Korisnik(string korisnik_ime, string korisnik_prezime, string korisnik_username, string korisnik_password, int korisnik_status)
    {
        ime=korisnik_ime;
        prezime=korisnik_prezime;
        username=korisnik_username;
        password=korisnik_password;
        status= korisnik_status;
    }
    string getKime()
    {
        return ime;
    }
    string getKprezime()
    {
        return prezime;
    }
    string getKusername()
    {
        return username;
    }
    string getKpassword()
    {
        return password;
    }
    int getKstatus()
    {
        return status;
    }


    bool Login(string im,string user, string pass)
    {
        if(user==username && pass==password && im==ime)
            return true;
        else
            return false;
    }





    void pisiTxt(char mode='w')
    {
        ofstream fajl;

        if (mode=='a'){
            fajl.open ("korisnik.txt", ios_base::app);
        }
        else{
            fajl.open ("korisnik.txt");
        }
        fajl<< ime <<"|"<< prezime <<"|"<< username <<"|"<< password<< "|" << status << endl;
        fajl.close();
    }








};
#endif // KORISNIK_HPP_INCLUDED
