#include "Barba_Neagra.hpp"

Barba_Neagra::Barba_Neagra(Harta& h)
{
	this->xHarta = h.get_rows() - 1;
	this->yHarta = 0;
	this->comoara = false;
	this->nume_explorator = "Barba Neagra";
	h.setValoare(xHarta, yHarta, 'B');
	this->xdif = 0;
	this->ydif = 0;
	this->mutare = 2;
}

Barba_Neagra::~Barba_Neagra()
{
	this->xdif= 0;
	this->ydif = 0;
	this->mutare = 0;
}

void Barba_Neagra::choose_new_position(Harta& h)
{
	//Barba Neagra va efectua de doua ori aceeasi miscare.
	//Daca nu poate face asta (fie casuta pe care trebuie sa se mute este deja explorata,
	//fie ar iesi in afara hartii), se alege random o pozitie in jurul lui.
	//Poate lua o comoara doar daca aceasta se afla pe casutele din diagonala lui.

	int x = get_xHarta();
	int y = get_yHarta();

	if (isAlive)
	{
		if ((x != 0 && y != 0 && h.getValoare(x - 1, y - 1) == 'X') ||
			(x != 0 && y != (h.get_cols() - 1) && h.getValoare(x - 1, y + 1) == 'X') ||
			(x != (h.get_rows() - 1) && y != 0 && h.getValoare(x + 1, y - 1) == 'X') ||
			(x != (h.get_rows() - 1) && y != (h.get_cols() - 1) && h.getValoare(x + 1, y + 1) == 'X'))
		{
			//pozitia lui actuala devine vizitata
			h.setValoare(x, y, 'B');
			h.creste_explorate();

			if (x != 0 && y != 0 && h.getValoare(x - 1, y - 1) == 'X')
			{
				h.setValoare(x - 1, y - 1, 'B');
				comoara = true;
				xHarta = x - 1;
				yHarta = y - 1;
			}
			else if (x != 0 && y != h.get_cols() && h.getValoare(x - 1, y + 1) == 'X')
			{
				h.setValoare(x - 1, y + 1, 'B');
				comoara = true;
				xHarta = x - 1;
				yHarta = y + 1;

			}
			else if (x != h.get_rows() && y != 0 && h.getValoare(x + 1, y - 1) == 'X')
			{
				h.setValoare(x + 1, y - 1, 'B');
				comoara = true;
				xHarta = x + 1;
				yHarta = y - 1;
			}
			else if (x != h.get_rows() && y != h.get_cols() && h.getValoare(x + 1, y + 1) == 'X')
			{
				h.setValoare(x + 1, y + 1, 'B');
				comoara = true;
				xHarta = x + 1;
				yHarta = y + 1;
			}
			cout << "\n\tBarba Neagra a gasit una dintre chei pe pozitia (" << xHarta << ", " << yHarta << ") \n"
				<< "\t\tIf I don't kill a man every now and then, they forget who I am.\n";
			isAlive = false;
			h.scade_comori();
			h.scade_exploratori();
		}
		else
		{
			if (mutare == 2)
			{
				if (x != 0 && h.getValoare(x - 1, y) == '~')
				{
					h.setValoare(x, y, 'B');
					xHarta = x - 1;
					yHarta = y;
					mutare = 1;
					xdif = -1;
					ydif = 0;
				
				}
				else if (y != (h.get_cols() - 1) && h.getValoare(x, y + 1) == '~')
				{
					h.setValoare(x, y, 'B');
					xHarta = x;
					yHarta = y + 1;
					mutare = 1;
					xdif = 0;
					ydif = 1;
					
				}
				else if (x != (h.get_rows() - 1) && h.getValoare(x + 1, y) == '~')
				{
					h.setValoare(x, y, 'B');
					xHarta = x + 1;
					yHarta = y;
					mutare = 1;
					xdif = 1;
					ydif = 0;
					
				}
				else if (y != 0 && h.getValoare(x, y - 1) == '~')
				{

					h.setValoare(x, y, 'B');
					xHarta = x;
					yHarta = y - 1;
					mutare = 1;
					xdif = 0;
					ydif = -1;
					
				}
				else {
					cout << "\n\tBarba Neagra a naufragiat :( \n";
					isAlive = false;
					h.scade_exploratori();
				}
				if (isAlive)
				{
					cout << "\n\tBarba Neagra s-a mutat in pozitia (" << xHarta << ", " << yHarta << ")\n";
					h.setValoare(xHarta, yHarta, 'B');

				}

			}
			else
			{
				if ((x + xdif) >= 0 && (x + xdif) <= (h.get_rows() - 1) && (y + ydif) >= 0 && (y + ydif) <+ (h.get_cols() - 1) && h.getValoare(x + xdif, y + ydif) == '~')
				{
					h.setValoare(x, y, 'B');
					xHarta = x + xdif;
					yHarta = y +ydif;
					mutare = 2;
				}
				else
				{
					if (x != 0 && h.getValoare(x - 1, y) == '~')
					{
						h.setValoare(x, y, 'B');
						xHarta = x - 1;
						yHarta = y;
						mutare = 1;
						xdif = -1;
						ydif = 0;
						
					}
					else if (y != (h.get_cols() - 1) && h.getValoare(x, y + 1) == '~')
					{
						h.setValoare(x, y, 'B');
						xHarta = x;
						yHarta = y + 1;
						mutare = 1;
						xdif = 0;
						ydif = 1;
						
					}
					else if (x != (h.get_rows() - 1) && h.getValoare(x + 1, y) == '~')
					{
						h.setValoare(x, y, 'B');
						xHarta = x + 1;
						yHarta = y;
						mutare = 1;
						xdif = 1;
						ydif = 0;
						
					}
					else if (y != 0 && h.getValoare(x, y - 1) == '~')
					{

						h.setValoare(x, y, 'B');
						xHarta = x;
						yHarta = y - 1;
						mutare = 1;
						xdif = 0;
						ydif = -1;
					}
					else {
						cout << "\n\tBarba Neagra a naufragiat :( \n";
						isAlive = false;
						h.scade_exploratori();
					}
					

				}
				if (isAlive)
				{
					cout << "\n\tBarba Neagra s-a mutat in pozitia (" << xHarta << ", " << yHarta << ")\n";
					h.setValoare(xHarta, yHarta, 'B');


				}
			}

		}
	}

}