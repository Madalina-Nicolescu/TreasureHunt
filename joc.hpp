#ifndef JOC_H
#define JOC_H

#include <vector>
#include "harta.hpp"
#include "explorator.hpp"
#include "Jack_Sparrow.hpp"
#include "Tia_Dalma.hpp"
#include "Barba_Neagra.hpp"
#include "Davy_Jones.hpp"


class Joc {

    Harta* h;
    vector<Explorator*> exploratori;
    vector<string> Clasament;
    vector<string> comoara_gasita;
    vector<string> blocati;
    static int noRound ;

public:

    Joc(int, int);
    ~Joc();

    int get_size_explorator() const; //returneaza numarul de exploratori care au mai ramas pe harta
    
    void runda(); // initiaza o runda
    void startJoc(); // desfasurarea jocului
    
    void afisHarta(); // afiseaza harta la momentul actual 
    void afisClasament(); //afiseaza clasamentul la finalul jocului

};



#endif