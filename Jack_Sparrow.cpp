#include "Jack_Sparrow.hpp"

Jack_Sparrow::Jack_Sparrow(Harta& h)
{
	this->xHarta = 0;
	this->yHarta = 0;
	this->comoara = false;
	this->nume_explorator = "Jack Sparrow";
	h.setValoare(0, 0, 'J');
}

void Jack_Sparrow::choose_new_position(Harta& h)
{
	//Cu ajutorul busolei sale, Jack Sparrow se poate muta in
	//cele 4 puncte cardinale, N E S V, in sensul acelor de ceas.
	//Daca unul dintre cele 4 puncte cardinale este deja explorat, 
	//va trece la urmatorul punct cardinal care ar fi venit la rand.
	
	//Ex: Incearca sa se mute la N, dar, daca este deja explorat, se va muta la E. 
	//Daca si estul este explorat, va incerca in S.
	//Daca toate cele 4 casute sunt explorate, va putea sa se mute o casuta pe diagonala,
	//stanga-sus sau dreapta-jos (NV sau SE).
	
	//Daca in jurul sau este o comoara, fiind un pirat fara scrupule, 
	//nu va mai tine cont de ordinea punctelor cardinale, se va duce la comoara.

	int x = get_xHarta();
	int y = get_yHarta();

	if (isAlive == true)
	{
		if ((x != 0 && h.getValoare(x - 1, y) == 'X') ||
			(y != (h.get_cols() - 1) && h.getValoare(x, y + 1) == 'X') ||
			(x != (h.get_rows() - 1) && h.getValoare(x + 1, y) == 'X') ||
			(y != 0 && h.getValoare(x, y - 1) == 'X'))
		{
			//pozitia lui actuala devine vizitata
			h.setValoare(x, y, 'J');
			h.creste_explorate();

			if (x != 0 && h.getValoare(x - 1, y) == 'X')
			{
				h.setValoare(x - 1, y, 'J');
				comoara = true;
				xHarta = x - 1;
				yHarta = y;
			}
			else if (y != (h.get_cols() - 1) && h.getValoare(x, y + 1) == 'X')
			{
				h.setValoare(x, y + 1, 'J');
				comoara = true;
				xHarta = x;
				yHarta = y + 1;
			}
			else if (x != (h.get_rows() - 1) && h.getValoare(x + 1, y) == 'X')
			{
				h.setValoare(x + 1, y, 'J');
				comoara = true;
				xHarta = x + 1;
				yHarta = y;
			}
			else if (y != 0 && h.getValoare(x, y - 1) == 'X')
			{

				h.setValoare(x, y - 1, 'J');
				comoara = true;
				xHarta = x;
				yHarta = y - 1;
			}
			cout << "\n\tJack Sparrow a gasit una dintre chei pe pozitia (" << xHarta << ", " << yHarta << ") \n"
				<< "\tGentlemen, m'lady...you will always remember this\n"
				<< "\t\t\tas the day that you almost caught Captain Jack Sparrow!\n";
			isAlive = false;
			h.scade_comori();
			h.scade_exploratori();
		}
		else {
			if (x != 0 && h.getValoare(x - 1, y) == '~')
			{
				h.setValoare(x, y, 'J');
				xHarta = x - 1;
				yHarta = y;
			}
			else if (y != (h.get_cols() - 1) && h.getValoare(x, y + 1) == '~')
			{
				h.setValoare(x, y, 'J');
				xHarta = x;
				yHarta = y + 1;
			}
			else if (x != (h.get_rows() - 1) && h.getValoare(x + 1, y) == '~')
			{
				h.setValoare(x, y, 'J');
				xHarta = x + 1;
				yHarta = y;
			}
			else if (y != 0 && h.getValoare(x, y - 1) == '~')
			{

				h.setValoare(x, y, 'J');
				xHarta = x;
				yHarta = y - 1;
			}
			else if (x != (h.get_rows() - 1) && y != (h.get_cols() - 1) && h.getValoare(x + 1, y + 1) == '~')
			{
				h.setValoare(x, y, 'J');
				xHarta = x + 1;
				yHarta = y + 1;
			}
			else if (x != 0 && y != 0 && h.getValoare(x - 1, y - 1) == '~')
			{
				h.setValoare(x, y, 'J');
				xHarta = x - 1;
				yHarta = y - 1;
			}
			else {
				cout << "\n\tJack Sparrow a naufragiat :( \n";
				isAlive = false;
				h.scade_exploratori();
			}
			if (isAlive)
			{
				cout << "\n\tJack Sparrow s-a mutat in pozitia (" << xHarta << ", " << yHarta << ")\n";
				h.setValoare(xHarta, yHarta, 'J');

			}

		}

	}


}