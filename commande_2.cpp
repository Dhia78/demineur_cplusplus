/**
@file : commande_2.cpp
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
@brief : affiche l'etat d'une grille a partir d'un probleme et d'un historique de coups
*/
#include<iostream>
#include"commandes.h"
#include"grille.h"


/**
@brief : affiche l'état d'une grille a partir d'un probleme et d'un historique de coups
@param [in] nbLignes : nombre de ligne de la grille
@param [in] nbColonnes : nombre de colonne de la grille
@param [in] nbMines : nombre de mines
@param [in] indexMines : tableau des index des mines
@param [in] nbCoups : nombre de coups deja joues
@param [in] historiqueCoups : tableau des coups deja joues
*/
void print_grille(int nbLignes, int nbColonnes, int nbMines, const int indexMines[], int nbCoups, const Coups historiqueCoups[]){
    bool is_game_finished = false;
    Grille grille;
    
    cout << nbLignes << ' ' << nbColonnes << endl;
    
    init_grille(&grille, nbLignes, nbColonnes);

    init_cases(&grille, indexMines, nbMines);

    //intégration des coups deja joues a l'etat de la grille de jeux
    for (int i = 0 ; i < nbCoups ; i++){
        if(historiqueCoups[i].typeCoup == 'M'){
            grille.cases[historiqueCoups[i].index/nbColonnes][historiqueCoups[i].index%nbColonnes].estMarquee = true;
        }
        else if(historiqueCoups[i].typeCoup == 'D'){
            demasquer(&grille, historiqueCoups[i].index/nbColonnes, historiqueCoups[i].index%nbColonnes);
        }
    }
    
    //affichage de la grille
    for (int i = 0 ; i < nbLignes ; i++){
        for(int j = 0 ; j < nbColonnes ; j++)
            cout << " ___";
        cout << '\n';

    for (int j = 0; j < nbColonnes; j++) {
        cout << "| ";
        if (game_won(nbMines, indexMines, nbCoups, historiqueCoups) || game_lost(nbMines, indexMines, nbCoups, historiqueCoups)) {
            if (grille.cases[i][j].estMine)
                cout << "m ";

            else if (grille.cases[i][j].estMarquee)
                cout << "x ";

            else if (grille.cases[i][j].estDecouvert) {
                if (grille.cases[i][j].nbMinesEnvironnantes == 0)
                    cout << "  ";
                else
                    cout << grille.cases[i][j].nbMinesEnvironnantes << ' ';
            }

            else
                cout << ". ";
        }
        else {
            if (grille.cases[i][j].estMarquee)
            cout << "x ";

            else if (grille.cases[i][j].estDecouvert) {
            if (grille.cases[i][j].nbMinesEnvironnantes == 0)
                cout << "  ";
            else
                cout << grille.cases[i][j].nbMinesEnvironnantes << ' ';
            }

            else
            cout << ". ";
        }
    }
    cout << '|' << endl;
}
for (int j = 0; j < nbColonnes; j++)
    cout << " ___";
cout << '\n';
}

