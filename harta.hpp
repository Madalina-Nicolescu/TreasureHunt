#pragma once
#ifndef HARTA_H
#define HARTA_H


#include<iostream>
using namespace std;

class Explorator;

class Harta {

    char** M;
    int rows, cols;
    int explorate;
    int comori;
    int nr_exploratori;

public:

    Harta(int, int);
    ~Harta();

    int get_explorate() const;
    int get_rows() const;
    int get_cols() const;
    int get_comori() const;
    int get_nr_exploratori() const;
    char getValoare(const int,const int) const;


    void setValoare(const int, const int, const char);


    void creste_explorate();
    void scade_comori();
    void scade_exploratori();

    void aseaza_comori();


    friend ostream& operator << (ostream&, Harta&);

    friend class Explorator;
};


#endif