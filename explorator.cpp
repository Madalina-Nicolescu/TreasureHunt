#include "explorator.hpp"

Explorator::Explorator() {
    this->xHarta = -1;
    this->yHarta = -1;
    this->comoara = false;
    this->nume_explorator = "";
    this->isAlive = true;
}

Explorator::Explorator(Harta& h, int x, int y, bool c, bool a, string n): xHarta(x), yHarta(y), comoara(c), isAlive(a), nume_explorator(n)
{}

Explorator::~Explorator()
{
    this->nume_explorator = "";
    this->xHarta = 0;
    this->yHarta = 0;
    this->comoara = false;
}


//-----GETTERS-----

int Explorator::get_xHarta() const {
    return this->xHarta;
}

int Explorator::get_yHarta() const {
    return this->yHarta;
}

string Explorator::get_nume() const
{
    return this->nume_explorator;
}

bool Explorator::get_isAlive() const
{
    return this->isAlive;
}

bool Explorator::get_comoara() const
{
    return this->comoara;
}

