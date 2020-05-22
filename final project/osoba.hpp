#ifndef OSOBA_HPP_INCLUDED
#define OSOBA_HPP_INCLUDED
#include <string>

//Standard klasa osoba koja će se naslediti, ništa specijalno

using namespace std;

class Osoba
{
private:
    string ime;
    string prezime;
    int godine;
public:
    Osoba(string osoba_ime, string osoba_prezime, int osoba_godine):ime(osoba_ime), prezime(osoba_prezime), godine(osoba_godine) {};
    virtual void predstavise ()
    {
        cout << ime << ", " << prezime << ", GOD: " << godine << ", ";


    }
};

#endif // OSOBA_HPP_INCLUDED
