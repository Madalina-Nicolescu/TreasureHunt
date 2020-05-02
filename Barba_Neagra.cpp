#include "Barba_Neagra.hpp"

Barba_Neagra::Barba_Neagra(Harta& h): Explorator(h, h.get_rows()-1, 0, false, true, "Barba Neagra"),xdif(0), ydif(0), mutare(2)
{}

Barba_Neagra::~Barba_Neagra()
{
	this->xdif= 0;
	this->ydif = 0;
	this->mutare = 0;
}

void Barba_Neagra::choose_new_position(Harta& h)
{
	//Barba Neagra va efectua de doua ori aceeasi miscare.
	//Poate lua o comoara doar daca aceasta se afla pe casutele din diagonala lui.

	int x = get_xHarta();
	int y = get_yHarta();

	if (isAlive)
	{
		//verific prima data daca are o comoara in jurul sau
		if ((x != 0 && y != 0 && h.getValoare(x - 1, y - 1) == 'X') ||
			(x != 0 && y != (h.get_cols() - 1) && h.getValoare(x - 1, y + 1) == 'X') ||
			(x != (h.get_rows() - 1) && y != 0 && h.getValoare(x + 1, y - 1) == 'X') ||
			(x != (h.get_rows() - 1) && y != (h.get_cols() - 1) && h.getValoare(x + 1, y + 1) == 'X'))
		{
			//pozitia lui actuala devine vizitata
			h.setValoare(x, y, 'B');
			h.creste_explorate();


			//caut casuta pe care se afla comoara si schimb coordonatele si setez comoara ca fiind gasita
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
			isAlive = false; //jucatorul iese din joc
			h.scade_comori();
			h.scade_exploratori();
		}
		else
		{
			if (mutare == 2) //daca deja au fost facute 2 mutari, se alege una noua

			//se retine in ce parte a fost facuta noua mutare cu ajutorul lui xdif si ydif
			//pentru a putea repeta miscarea
			{
				if (y != (h.get_cols() - 1) && h.getValoare(x, y + 1) == '~')
				{
					h.setValoare(x, y, 'B');
					xHarta = x;
					yHarta = y + 1;
					mutare = 1;
					xdif = 0;
					ydif = 1;

				}
				else if (x != 0 && h.getValoare(x - 1, y) == '~')
				{
					h.setValoare(x, y, 'B');
					xHarta = x - 1;
					yHarta = y;
					mutare = 1;
					xdif = -1;
					ydif = 0;
				
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
					//daca nu mai exista casute valabile, jucatorul paraseste jocul
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
				//daca suntem de abia dupa prima mutare, trebuie sa o repetam pe cea veche
				
				if ((x + xdif) >= 0 && (x + xdif) <= (h.get_rows() - 1) && (y + ydif) >= 0 && (y + ydif) <+ (h.get_cols() - 1) && h.getValoare(x + xdif, y + ydif) == '~')
				{
					h.setValoare(x, y, 'B');
					xHarta = x + xdif;
					yHarta = y +ydif;
					mutare = 2;
					//repetarea miscarii a fost acceptata
				}
				else
				{
					//daca nu se poate repeta miscarea (fie casuta este deja explorata, fie se iese in afara hartii),
					//se alege alta pozitie si se reseteaza variabilate mutare
					if (y != (h.get_cols() - 1) && h.getValoare(x, y + 1) == '~')
					{
						h.setValoare(x, y, 'B');
						xHarta = x;
						yHarta = y + 1;
						mutare = 1;
						xdif = 0;
						ydif = 1;

					}
					else if (x != 0 && h.getValoare(x - 1, y) == '~')
					{
						h.setValoare(x, y, 'B');
						xHarta = x - 1;
						yHarta = y;
						mutare = 1;
						xdif = -1;
						ydif = 0;
						
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