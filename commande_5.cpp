/**
@file : commande_5.cpp
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 22/12/21
@brief : fonction de recherche d'une case a demasquer
 */
#include<iostream>
#include"commandes.h"

/**
@brief : trouve une case a demasquer ou affiche une erreur si elle n'en trouve pas
@param [in] nbLignes : nombre de ligne de la grille
@param [in] nbColonnes : nombre de colonne de la grille
@return : l'index d'une case 
*/
int find_move(int nbLignes, int nbColonnes){
    //trouve une case non demasquee
    char cara = ' ';
    int i = 0;
    while (cara != '.'){
        cin >> cara;
        if (cara == '|')
            i++;
    }

    int indexLigne = i/(nbColonnes+1); //i contera nbColonnes+1 barre vertical par ligne, donc pour avoir le nombre de ligne, nous devons diviser i par nbColonnes+1
    return indexLigne*nbColonnes + i%(nbColonnes+1) - 1;
}
