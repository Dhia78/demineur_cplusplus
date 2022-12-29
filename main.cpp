/**
@file : main.cpp
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
*/
#include<iostream>
#include"commandes.h"
#pragma warning(disable:4703)

int main(){
    int commande, nbLignes, nbColonnes, nbMines, nbCoups;
    cin >> commande >> nbLignes >> nbColonnes;
    int *indexMines;
    Coups *historiqueCoups;

    if (commande != 5){
        cin >> nbMines;
        if (commande != 1){
            indexMines = new int[nbMines];
            for (int i = 0 ; i < nbMines ; i++)
                cin >> indexMines[i];

            cin >> nbCoups;
            historiqueCoups = new Coups[nbCoups];
            for (int i = 0 ; i < nbCoups ; i++)
                lireCoups(historiqueCoups[i]);
        }
    }

    if (commande == 1)
        make_problem(nbLignes, nbColonnes, nbMines);

    else if (commande == 2)
        print_grille(nbLignes, nbColonnes, nbMines, indexMines, nbCoups, historiqueCoups);

    else if (commande == 3){
        if (game_won(nbMines, indexMines, nbCoups, historiqueCoups))
            cout << "game won"; 
        else
            cout << "game not won";
    }

    else if (commande == 4){
        if (game_lost(nbMines, indexMines, nbCoups, historiqueCoups)) 
            cout << "game lost"; 
        else
            cout << "game not lost";
    }

    else if (commande == 5)
        cout << "D" << find_move(nbLignes, nbColonnes) << endl;

    return 0;
}