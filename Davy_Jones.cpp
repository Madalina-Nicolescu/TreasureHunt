#include "Davy_Jones.hpp"

Davy_Jones::Davy_Jones(Harta& h)
{
	this->xHarta = h.get_rows() - 1;
	this->yHarta = h.get_cols() - 1;
	this->comoara = false;
	this->nume_explorator = "Davy Jones";
	h.setValoare(xHarta, yHarta, 'D');
}

void Davy_Jones::choose_new_position(Harta& h)
{
	//Davy Jones, indragostit de Tia Dalma, incearca sa ajunga la ea.
	//Verifica 2 casute in sus, la dreapta, in jos, la stanga.
	//Daca gaseste o casuta marcata cu T, se duce spre ea.
	//Daca nu mai are miscari valide, poate cobori o casuta pe diagonala (stanga jos, dreapta jos).
	//Dar, deoarece este mai important sa puna mana pe cheia cufarului, daca are in jurul sau o comoara,
	//nu o va mai urmari pe Tia Dalma, se va duce dupa comoara.

	int x = get_xHarta();
	int y = get_yHarta();

	if (isAlive)
	{
		if ((x != 0 && h.getValoare(x - 1, y) == 'X') ||
			(y != (h.get_cols() - 1) && h.getValoare(x, y + 1) == 'X') ||
			(x != (h.get_rows() - 1) && h.getValoare(x + 1, y) == 'X') ||
			(y != 0 && h.getValoare(x, y - 1) == 'X'))
		{
			h.setValoare(x, y, 'D');
			h.creste_explorate();
			if (x != 0 && h.getValoare(x - 1, y) == 'X')
			{
				h.setValoare(x - 1, y, 'D');
				comoara = true;
				xHarta = x - 1;
				yHarta = y;
			}
			else if (y != (h.get_cols() - 1) && h.getValoare(x, y + 1) == 'X')
			{
				h.setValoare(x, y + 1, 'D');
				comoara = true;
				xHarta = x;
				yHarta = y + 1;
			}
			else if (x != (h.get_rows() - 1) && h.getValoare(x + 1, y) == 'X')
			{
				h.setValoare(x + 1, y, 'D');
				comoara = true;
				xHarta = x + 1;
				yHarta = y;
			}
			else if (y != 0 && h.getValoare(x, y - 1) == 'X')
			{

				h.setValoare(x, y - 1, 'D');
				comoara = true;
				xHarta = x;
				yHarta = y - 1;
			}
			cout << "\n\tDavy Jones a gasit una dintre chei pe pozitia (" << xHarta << ", " << yHarta << ") \n"
				<< "\t\tDo you fear death? I can offer you...an escape.\n";
			isAlive = false;
			h.scade_comori();
			h.scade_exploratori();
		}
		else {
			if (x > 1 && h.getValoare(x - 2, y) == 'T' && h.getValoare(x - 1, y) == '~')
			{
				h.setValoare(x, y, 'D');
				xHarta = x - 1;
				yHarta = y;
			}
			else if (y < h.get_cols()-2 && h.getValoare(x, y + 2) == 'T' && h.getValoare(x, y + 1) == '~')
			{
				h.setValoare(x, y, 'D');
				xHarta = x;
				yHarta = y + 1;
			}
			else if (x < h.get_rows()-2 && h.getValoare(x + 2, y) == 'T' && h.getValoare(x + 1, y) == '~')
			{
				h.setValoare(x, y, 'D');
				xHarta = x + 1;
				yHarta = y;
			}
			else if (y > 1 && h.getValoare(x, y - 2) == 'T' && h.getValoare(x, y - 1) == '~')
			{
				h.setValoare(x, y, 'D');
				xHarta = x;
				yHarta = y - 1;
			}
			else if (x != 0 && h.getValoare(x - 1, y) == '~')
			{
				h.setValoare(x, y, 'D');
				xHarta = x - 1;
				yHarta = y;
			}
			else if (y != (h.get_cols() - 1) && h.getValoare(x, y + 1) == '~')
			{
				h.setValoare(x, y, 'D');
				xHarta = x;
				yHarta = y + 1;
			}
			else if (x != (h.get_rows() - 1) && h.getValoare(x + 1, y) == '~')
			{
				h.setValoare(x, y, 'D');
				xHarta = x + 1;
				yHarta = y;
			}
			else if (y != 0 && h.getValoare(x, y - 1) == '~')
			{
				h.setValoare(x, y, 'D');
				xHarta = x;
				yHarta = y - 1;
			}
			else if (x != (h.get_rows() - 1) && y != (h.get_cols() - 1) && h.getValoare(x + 1, y + 1) == '~')
			{
				h.setValoare(x, y, 'D');
				xHarta = x + 1;
				yHarta = y + 1;
			}
			else if (x != (h.get_rows() - 1) && y != 0 &&  h.getValoare(x + 1, y - 1) == '~')
			{
				h.setValoare(x, y, 'D');
				xHarta = x + 1;
				yHarta = y - 1;
			}
			else {
				cout << "\n\tDavy Jones a naufragiat :( \n";
				isAlive = false;
				h.scade_exploratori();
			}
			if (isAlive)
			{
				cout << "\n\tDavy Jones s-a mutat in pozitia (" << xHarta << ", " << yHarta << ")\n";
				h.setValoare(xHarta, yHarta, 'D');

			}
		}
		
	}


}