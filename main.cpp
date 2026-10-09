#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

int main()
{
    char saisieRejouer; //L'utlisateur va saisir à la fin si il souhaite recommencé ou pas.
    do {


        const int maxNumber = 1000;
        const int nbcolones =5; //Nombre de colones affichage
        const int debutListe = 2;
        int finListe = 0; // Sera saisie par l'utilisateur.

        cout << "Ce programme affiche tous les nombres premiers situes entre 1 et une limite saisie."
        << '\n';

        do
        {
            cout << "entrer une valeur [2-1000] : ";
            cin >> finListe;

        }while (finListe < debutListe || finListe > maxNumber);


        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //On vide le buffer après utilisation.

        cout << "Voici la liste des nombres premiers";

        int iAffichage = 0; //Variable qui permet de compter le nombre de premier déjà affichés.
        for (int iNombre = debutListe; iNombre <= finListe; iNombre++)
        {
            bool estPremier = true;
            int limitTest = sqrt(iNombre); //On test si le nombre peut être divisé jusqu'à racine de lui même, on troque la partie flotante(pas besoin de tester le nombre lui même).

            for (int iDiviseur = debutListe; iDiviseur <= limitTest && estPremier; iDiviseur++)
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

        cout << '\n';

        do {
            cout << "Voulez-vous recommencer [O/N] : ";
            cin >> saisieRejouer;

        }while (saisieRejouer != 'O' && saisieRejouer != 'N');

    }while (saisieRejouer == 'O');

    cout << "Fin de programme" << endl;

    return 0;
}