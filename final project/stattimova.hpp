#ifndef TIMUCINAK_HPP_INCLUDED
#define TIMUCINAK_HPP_INCLUDED

///ovo koristimo za tim kao nasledjivanje

class StatTimova
{
protected:
    int pobede;

    int porazi;

    int bodovi;
    int golovidati;
    int goloviprimljeni;
public:
    StatTimova (int p1, int p2, int b, int gd, int gp)
    {
        pobede=p1;
        porazi=p2;
        bodovi=b;
        golovidati=gd;
        goloviprimljeni=gp;
    }
    void ispisiInfoTim()
    {

        cout << "W: " << pobede << " / ";
        cout << "L: " << porazi << " / ";

        cout << "GS: " << golovidati << " / GC: " << goloviprimljeni <<" ";
        cout << "POENI: " << bodovi << endl;

        cout << endl;
    }
};

#endif // TIMUCINAK_HPP_INCLUDED
