#pragma once
#ifndef EXPLORATOR_H
#define EXPLORATOR_H


#include<string>
#include "harta.hpp"

using namespace std;


class Explorator {

protected:
    int xHarta, yHarta;
    bool comoara;
    bool isAlive;
    string nume_explorator;


public:

    Explorator();
    Explorator(Harta&, int,int,bool,bool,string);
    virtual ~Explorator();

    int get_xHarta() const; //returneaza coordonata x 
    int get_yHarta() const; // retruneaza coordonata y
    string get_nume() const; // returneaza numele jucatorului
    bool get_isAlive() const; //true daca jucatorul este inca pe harta, false altfel
    bool get_comoara() const; //true daca jucatorul a gasit comoara, false altfel

    virtual void choose_new_position(Harta&) = 0; //functie virtuala pura care alege noua pozitie pe harta

};



#endif