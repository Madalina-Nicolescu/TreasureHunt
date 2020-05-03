#pragma once
#include "explorator.hpp"
class Tia_Dalma : public Explorator
{
public:
	Tia_Dalma(Harta&);
	~Tia_Dalma() {};

	void choose_new_position(Harta&); //alege noua pozitie pe harta
};

