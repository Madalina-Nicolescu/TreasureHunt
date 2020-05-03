#pragma once
#ifndef HARTA_H
#define HARTA_H


#include<iostream>
using namespace std;

class Explorator;

class Harta {

    char** M;
    int rows, cols;
    static int explorate;
    static int comori;
    static int nr_exploratori;

public:

    Harta(int, int);
    ~Harta();

    int get_explorate() const; //retruneaza numarul de casute explorate
    int get_rows() const; //returneaza numarul de randuri
    int get_cols() const; //returneaza numarul de coloane
    int get_comori() const; //returneaza numarul de comori ramase pe harta
    char getValoare(const int,const int) const; // returneaza valoarea lui M[i][j]


    void setValoare(const int, const int, const char); //seteaza o valoare pentru M[i][j]


    void creste_explorate(); //creste nr de casute explorate
    void scade_comori(); //scade nr de comori ramase pe harta
    void scade_exploratori(); //scade nr de exploratori de pe harta

    void aseaza_comori(); //aseaza random cele 3 comori pe harta


    friend ostream& operator << (ostream&, Harta&); //supraincarcarea operatorului <<

    friend class Explorator;
};


#endif