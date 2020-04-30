#pragma once
#include "explorator.hpp"

class Davy_Jones : public Explorator
{
public:
	Davy_Jones(Harta& h);
	~Davy_Jones() {};

	void choose_new_position(Harta&);
};

