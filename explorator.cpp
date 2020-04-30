#include "explorator.hpp"

Explorator::Explorator() {
    this->xHarta = -1;
    this->yHarta = -1;
    this->comoara = false;
    this->nume_explorator = "";
    this->isAlive = true;
}

Explorator::Explorator(Harta& h)
{
    this->xHarta = -1;
    this->yHarta = -1;
    this->comoara = false;
    this->nume_explorator = "";
    this->isAlive = true;
}

Explorator::~Explorator()
{
    this->nume_explorator = "";
    this->xHarta = 0;
    this->yHarta = 0;
    this->comoara = false;
}

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

void Explorator::set_comoara(const bool f)
{
    this->comoara = f;
}

bool Explorator::get_isAlive() const
{
    return this->isAlive;
}

bool Explorator::get_comoara() const
{
    return this->comoara;
}

ostream& operator <<(ostream& out, Explorator& e)
{
    if (e.isAlive)
    {
        out<<e.nume_explorator<<" s-a mutat pe pozitia (" << e.xHarta << ", " << e.yHarta << ")\n"; 
    }
    else
    {
        if (!e.comoara)
            out << e.nume_explorator << " a naufragiat :(.\n";
    }
    return out;
}