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

public:

    Joc(int, int);
    ~Joc() {};

    int get_zize_explorator() const;
    
    
    void runda();
    void startJoc();
    void afisHarta();
    void afisClasament();

};



#endif