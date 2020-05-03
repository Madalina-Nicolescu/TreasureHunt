#include<iostream>
#include "joc.hpp"

using namespace std;

void welcomeScreen()
{
    cout << "\n\n\t\t\t\t\t\tTREASURE HUNT\n\n";

    cout << "\tBine ai venit!\n\n";
    cout << "\tJack Sparrow, Davy Jones, Barba Neagra si Tia Dalma au pornit intr-o aventura.\n";
    cout << "\tEi trebuie sa gaseasca cheile cufarului in care se afla inima lui Davy Jones.\n";
    cout << "\n\tPe harta exista 3 chei. Fiecare jucator porneste dintr-un colt diferit al hartii.";
    cout << "\n\tPersonajele nu au voie sa treaca peste casute deja explorate de ei sau de ceilalti jucatori.";
    cout << "\n\tPrimul jucator care a gasit o cheie va fi castigator si va parasi harta.";
    cout << "\n\tJocul se desfasoara pana cand nu mai sunt chei pe harta sau pana cand nu mai exista \n"
        << "\tcasute neexplorate.\n";
    cout << "\n\n\tLa final, se va afisa clasamentul celor 4 exploratori";
    cout << "\n\tOare cine va pune mana pe cufarul atat de pretios?";
    cout << "\n\n\tSucces!";
    cout << "\n\n\n";
}

int main()
{
    welcomeScreen();

    int r, c;

    cout << "\tIntroduceti dimensiunile hartii\n";
    cout << "\tNumarul de linii (minim 15) = ";
    cin >> r;
    cout << "\tNumarul de coloane (minim 15) = ";
    cin >> c;

    try
    {

        if (r < 15 || c < 15)
            throw "Dimenisunile sunt prea mici";

        Joc j(r, c);
        j.startJoc();
        
    }
    catch (string n)
    {
        cout << n;
    }
    return 0;
}