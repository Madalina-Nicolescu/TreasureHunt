#include "joc.hpp"

Joc::Joc(int r, int c)
{
    this->h = new Harta(r, c);

    this->exploratori.push_back(new Jack_Sparrow(*h));
    this->exploratori.push_back(new Tia_Dalma(*h));
    this->exploratori.push_back(new Davy_Jones(*h));
    this->exploratori.push_back(new Barba_Neagra(*h));
    h->aseaza_comori();
}

void Joc::afisHarta()
{
    cout << (*h);
}


void Joc::afisClasament()
{
    cout << "\n\tJocul s-a terminat. Iata clasamentul :  ";

    cout << "\n\n";

    cout << "\t ================================\n";
    cout << "\t|                                |\n";

    for (auto i : Clasament)
    {
        cout << "\t|                                |\n";
        if (i.length() == 12)
        {
            cout << "\t|\t   " << i << "          |\n";
        }
        else if (i.length() == 10)
        {
            cout << "\t|\t    " << i << "           |\n";
        }
        else
        {
            cout << "\t|\t    " << i << "            |\n";
        }
        cout << "\t|                                |\n";
    }
    cout << "\t|                                |\n";
    cout << "\t ================================\n";
    

}



int Joc::get_zize_explorator() const
{
    return this->exploratori.size();
}

void Joc::runda()
{
   
    for (int i = 0; i < exploratori.size(); i++)
    {
        exploratori[i]->choose_new_position(*h);
        if (!exploratori[i]->get_isAlive())
        {
            if (exploratori[i]->get_comoara())
                comoara_gasita.push_back(exploratori[i]->get_nume());
            else blocati.push_back(exploratori[i]->get_nume());
            exploratori.erase(exploratori.begin() + i);
            i--;
        }
    }
    Clasament.clear();
    for (auto i : comoara_gasita)
        Clasament.push_back(i);
    for (vector<string>::reverse_iterator i = blocati.rbegin(); i != blocati.rend(); ++i)
    {
        Clasament.push_back(*i);
    }
    cout << (*h);
    
}

void Joc::startJoc()
{
    char ch;

    afisHarta();

    cout << "\n\tHai sa incepem!\n";
    cout << "\n\tCum vrei sa joci? Introdu cifra corespunzatoare modului de joc dorit.";
    cout << "\n\t1 - Cate o runda, cu posibilitatea opririi jocului oricand";
    cout << "\n\t2 - Simularea integrala a jocului";
    cout << "\n\t Optiunea ta : ";
    cin >> ch;
    cout << "\n";
    try
    {
        if (ch != '1' && ch != '2' )
            throw "Optiune invalida";
        while (ch == '1' || ch == 'y' || ch == 'Y' && get_zize_explorator() != 0)
        {
            runda();

            cout << "\n\tDoriti sa continuati? (y - yes, n - no, 2 - Vreau sa vad direct finalul)\n\t";
            cin >> ch;
            cout << "\n";
        }
        while (ch == '2' && get_zize_explorator() != 0)
        {
            runda();
        }
        if (get_zize_explorator() == 0)
        {
            afisClasament();
        }
    }
    catch (string s)
    {
        cout << s;
    }

}
