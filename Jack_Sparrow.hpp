#pragma once
#include "explorator.hpp"

class Jack_Sparrow: public Explorator
{
public:
	Jack_Sparrow(Harta&);
	~Jack_Sparrow() {}; //daca adaug ceva in plus fata de exp

	void choose_new_position(Harta&);
};

