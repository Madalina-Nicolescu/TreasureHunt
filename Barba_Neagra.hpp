#pragma once
#include "explorator.hpp"
class Barba_Neagra:public Explorator
{
	int xdif, ydif;
	int mutare;
public:
	Barba_Neagra(Harta&);
	~Barba_Neagra();

	void choose_new_position(Harta&); //alege noua pozitie pe harta
};

