/**
@file : commande_1.cpp
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
@brief : produit un probleme a partir du nombre de lignes, de colonnes, et du nombre de mines
*/
#include<iostream>
#include"commandes.h"

/**
@brief : test si un entier est contenu dans un tableau d'entier
@param [in] element : l'element a chercher
@param [in] tab : le tableau
@param [in] sizeTab : la taille du tableau
@return : un boolean
*/
bool is_contain_in_tab(int element, int tab[], int sizeTab){
    for (int i = 0 ; i < sizeTab ; i++)
        if (tab[i] == element)
            return true;
    return false;
}

/**
@brief : produit un probleme a partir du nombre de lignes, de colonnes, et du nombre de mines
@param [in] nbLignes : nombre de ligne de la grille
@param [in] nbColonnes : nombre de colonne de la grille
@param [in] nbMines : nombre de mines
*/
void make_problem(int nbLignes, int nbColonnes, int nbMines){
    cout << nbLignes << ' ' << nbColonnes << ' ' << nbMines << ' ';

    int *indexMines = new int [nbMines];
    int indexMinesSave;

    for (int i = 0 ; i < nbMines ; i++){
        indexMinesSave = rand()%(nbColonnes*nbLignes);
        if (!is_contain_in_tab(indexMinesSave, indexMines, nbMines))
            indexMines[i] = indexMinesSave;
        else
            i--;
    }

    for (int i = 0 ; i < nbMines ; i++)
        cout << indexMines[i] << ' ';
    cout << endl;
    delete [] indexMines;
}
