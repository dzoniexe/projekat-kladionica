#ifndef KORISNIK_HPP_INCLUDED
#define KORISNIK_HPP_INCLUDED"
#include <fstream>
class Korisnik
{
private:
    string ime;
    string prezime;
    string password;
    string username;
    int status;
    static int brojKorisnika;

public:
    Korisnik(string korisnik_ime, string korisnik_prezime, string korisnik_username, string korisnik_password, int korisnik_status)
    {
        ime=korisnik_ime;
        prezime=korisnik_prezime;
        username=korisnik_username;
        password=korisnik_password;
        status= korisnik_status;
        {
            brojKorisnika++;
        }
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



};

#endif // KORISNIK_HPP_INCLUDED
