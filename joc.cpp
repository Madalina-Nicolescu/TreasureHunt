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


//-----AFISARI-----

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

//-----GETTER-----

int Joc::get_zize_explorator() const
{
    return this->exploratori.size();
}

//-----DESFASURARE RUNDA-----

void Joc::runda()
{
   
    for (int i = 0; i < exploratori.size(); i++) // pentru fiecare dintre cei 4 exploratori
                                                 // se alege noua pozitie
    {
        exploratori[i]->choose_new_position(*h);
        if (!exploratori[i]->get_isAlive()) // daca exploratorul a parasit harta la runda curenta, este scos din joc
        {
            if (exploratori[i]->get_comoara()) //daca a parasit harta pentru ca a gasit o comoara,
                                               //este adaugat in vectorul cu exploratori care au gasit comori
                comoara_gasita.push_back(exploratori[i]->get_nume());

            else blocati.push_back(exploratori[i]->get_nume()); //daca a parasit harta pentru ca a ramas blocat,
                                                                //este adaugat in vectorul cu exploratori blocati
            exploratori.erase(exploratori.begin() + i);
            i--;
        }
    }

    //Clasamentul se va forma in felul urmator:
    //Jucatorii care au gasit comoara vor fi primii in clasament, in ordinea in care au gasit comoara,
    //iar jucatorii care s-au blocat vor fi adaugati la sfarsitul clasamentului, in ordine inversa
    //fata de ordinea in care s-au blocat. Astfel, primul jucator care s-a blocat pe traseu va fi ultimul in clasament.
    //Primul jucator care a gasit comoara va fi castigator.
    //Daca toti jucatorii s-au blocat pe traseu, castigatorul va fi cel care a rezistat cel mai mult timp in joc.

    Clasament.clear();

    for (auto i : comoara_gasita)
        Clasament.push_back(i);

    for (vector<string>::reverse_iterator i = blocati.rbegin(); i != blocati.rend(); ++i)
    {
        Clasament.push_back(*i);
    }

    cout << (*h); //harta se afiseaza dupa fiecare runda
    
}

//-----DESFASURARE JOC-----

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
            throw "Optiune invalida"; //daca utilizatorul a ales o optiune invalida, se arunca o exceptie

        while ((ch == '1' || ch == 'y' || ch == 'Y') && get_zize_explorator() != 0 && h->get_explorate() != (h->get_cols()*h->get_rows()) ) 
        {
            //daca optiunea utilizatorului este 1, sau daca vrea sa continue jocul,
            //daca mai sunt exploratori pe harta sau casute neexplorate,
            //jocul se desfasoara runda cu runda

            runda();

            cout << "\n\tDoriti sa continuati? (y - yes, n - no, 2 - Vreau sa vad direct finalul)\n\t";
            cin >> ch;
            cout << "\n";

            //utilizatorul poate oricand sa schimbe modul jocului si sa aleaga sa
            //desfasoare integral jocul
        }

        while (ch == '2' && get_zize_explorator() != 0 && h->get_explorate() != (h->get_cols() * h->get_rows()))
        {
            //daca utilizatorul a ales optiunea 2, jocul se va desfasura integral

            runda();
        }

        if (get_zize_explorator() == 0)
        {
            //daca jocul s-a terminat, se afiseaza clasamentul

            afisClasament();
        }
    }
    catch (string s)
    {
        cout << s;
    }

}
