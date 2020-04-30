#include "harta.hpp"
#include <time.h>

Harta::Harta(int r, int c)
{
    this->cols = c;
    this->rows = r;
    this->explorate = 4;
    this->comori = 3;
    this->nr_exploratori = 4; // sa nu uit s o schimb
    this->M = new char* [this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->M[i] = new char[this->cols];
        for (int j = 0; j < this->cols; j++)
        {
            this->M[i][j] = '~';
        }
    }

}

Harta::~Harta()
{
    for (int i = 0; i < this->rows; i++)
    {
        delete[] this->M[i];
    }
    delete[] this->M;
    this->cols = 0;
    this->rows = 0;
    this->explorate = 0;
}

int Harta::get_explorate() const {
    return this->explorate;
}

int Harta::get_cols() const {
    return this->cols;
}

int Harta::get_rows() const {
    return this->rows;
}

int Harta::get_comori() const {
    return this->comori;
}

int Harta::get_nr_exploratori() const{
    return this->nr_exploratori;
}


char Harta::getValoare(int i, int j) const
{
    return this->M[i][j];
}

void Harta::setValoare(int i, int j, char ch)
{
    this->M[i][j] = ch;
}


void Harta::creste_explorate()
{
    this->explorate++;
}

void Harta::scade_comori()
{
    this->comori--;
}

void Harta::scade_exploratori()
{
    this->nr_exploratori--;
}

void Harta::aseaza_comori()
{
    srand(time(0));
    int x, y;
    for (int i = 0; i < 3; i++)
    {
        do
        {
            x = rand() % rows;
            y = rand() % cols;
        } while (x == 0 || x == (rows - 1) || y == 0 || y == (cols - 1));
        M[x][y] = 'X';
    }
}

ostream& operator <<(ostream& g, Harta& h)
{
    g << "\n";
    for (int i = 0; i < h.rows; i++)
    {
        g << "\t";
        for (int j = 0; j < h.cols; j++)
        {
            g << h.M[i][j] << " ";
        }
        g << endl;
    }

    return g;
}