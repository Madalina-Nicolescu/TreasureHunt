#include "Tia_Dalma.hpp"

Tia_Dalma::Tia_Dalma(Harta& h)
{
	this->xHarta = 0;
	this->yHarta = h.get_cols() - 1;
	this->comoara = false;
	this->nume_explorator = "Tia Dalma";
	h.setValoare(xHarta, yHarta, 'T');
}

void Tia_Dalma::choose_new_position(Harta& h)
{
	//Tia Dalma, Calypso, vrajitoarea marilor, se poate misca doar pe diagonala.
	//Daca nu mai sunt casute neexplorate in jurul ei, poate urca sau cobori o casuta pe verticala.

	int x = get_xHarta();
	int y = get_yHarta();
	int r = h.get_rows();
	int c = h.get_cols();

	if (isAlive == true)
	{
		if ((x != 0 && y != 0 && h.getValoare(x - 1, y - 1) == 'X') ||
			(x != 0 && y != (h.get_cols() - 1) && h.getValoare(x - 1, y + 1) == 'X') ||
			(x != (h.get_rows()-1) && y != 0 && h.getValoare(x + 1, y - 1) == 'X') ||
			(x != (h.get_rows()-1) && y != (h.get_cols()-1) && h.getValoare(x + 1, y + 1) == 'X'))
		{
			//pozitia lui actuala devine vizitata
			h.setValoare(x, y, 'T');
			h.creste_explorate();

			if (x != 0 && y != 0 && h.getValoare(x - 1, y - 1) == 'X')
			{
				h.setValoare(x - 1, y - 1, 'T');
				comoara = true;
				xHarta = x - 1;
				yHarta = y - 1;
			}
			else if (x != 0 && y != h.get_cols() && h.getValoare(x - 1, y + 1) == 'X')
			{
				h.setValoare(x - 1, y + 1, 'T');
				comoara = true;
				xHarta = x - 1;
				yHarta = y + 1;
				
			}
			else if (x != h.get_rows() && y != 0 && h.getValoare(x + 1, y - 1) == 'X')
			{
				h.setValoare(x + 1, y - 1, 'T');
				comoara = true;
				xHarta = x + 1;
				yHarta = y - 1;
			}
			else if (x != h.get_rows() && y != h.get_cols() && h.getValoare(x + 1, y + 1) == 'X')
			{

				h.setValoare(x + 1, y + 1, 'T');
				comoara = true;
				xHarta = x + 1;
				yHarta = y + 1;
			}
			cout << "\n\tTia Dalma a gasit una dintre chei pe pozitia (" << xHarta << ", " << yHarta << ") \n"
				<< "\t\tA touch... of destiny.\n";
			isAlive = false;
			h.scade_comori();
			h.scade_exploratori();
		}
		else {
			if (x != 0 && y != 0 &&  h.getValoare(x - 1, y - 1) == '~')
			{
				h.setValoare(x, y, 'T');
				xHarta = x - 1;
				yHarta = y - 1;
			}
			else if (x != 0 && y != (h.get_cols() - 1) && h.getValoare(x - 1, y + 1) == '~')
			{
				h.setValoare(x, y, 'T');
				xHarta = x - 1;
				yHarta = y + 1;
			}
			else if (x != (h.get_rows() - 1) && y != 0 && h.getValoare(x + 1, y - 1) == '~')
			{
				h.setValoare(x, y, 'T');
				xHarta = x + 1;
				yHarta = y - 1;
			}
			else if (x != (h.get_rows() - 1) && y != (h.get_cols() - 1) && h.getValoare(x + 1, y + 1) == '~')
			{

				h.setValoare(x, y, 'T');
				xHarta = x + 1;
				yHarta = y + 1;
			}
			else if (x != (h.get_rows() - 1) &&  h.getValoare(x + 1, y) == '~')
			{
				h.setValoare(x, y, 'T');
				xHarta = x + 1;
				yHarta = y;
			}
			else if (x != 0 && h.getValoare(x - 1, y) == '~')
			{
				h.setValoare(x, y, 'T');
				xHarta = x - 1;
				yHarta = y;
			}
			else {
				cout << "\n\tTia Dalma a naufragiat :( \n";
				isAlive = false;
				h.scade_exploratori();
			}
			if (isAlive)
			{
				cout << "\n\tTia Dalma s-a mutat in pozitia (" << xHarta << ", " << yHarta << ")\n";
				h.setValoare(xHarta, yHarta, 'T');
			}
		}
	}

}