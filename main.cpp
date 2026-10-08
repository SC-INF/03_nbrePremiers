#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

int main()
{
    const int maxNumber{1000};
    const int nbcolones{5}; //Nombre de colones affichage
    const int debutListe{1}; // Le premier nombre premier est obligatoirement 1
    int finListe{0}; // Sera saisie par l'utilisateur.

    cout << "Ce programme affiche tous les nombres premiers situes entre 1 et une limite saisie."
    << '\n';

    do
    {
        cout << "entrer une valeur [2-1000] : ";
        cin >> finListe;

    }while (finListe < (debutListe+1) || finListe > maxNumber);


    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Voici la liste des nombres premiers";

    int iAffichage = 0; //Variable qui permet de compter le nombre de premier déjà affichés.
    for (int iNombre = debutListe+1; iNombre <= finListe; iNombre++)
    {
        bool estPremier = true;
        int limitTest = sqrt(iNombre); //On test si le nombre peut être divisé jusqu'à racine de lui même.

        for (int iDiviseur = debutListe+1; iDiviseur <= limitTest && estPremier; iDiviseur++)
        {
            if (iNombre % iDiviseur == 0)
            {
                estPremier = false;
            }
        }
        if (estPremier)
        {
            if (iAffichage % nbcolones == 0) {
                cout << '\n';
            }
            cout << setw(10) << iNombre;
            iAffichage++;
        }
    }
    return 0;
}