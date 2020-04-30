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
    Explorator(Harta&);
    virtual ~Explorator();

    int get_xHarta() const;
    int get_yHarta() const;
    string get_nume() const;
    bool get_isAlive() const;
    bool get_comoara() const;

    void set_comoara(const bool);

    virtual void choose_new_position(Harta&) = 0;

    friend ostream& operator << (ostream&, Explorator&);


};



#endif