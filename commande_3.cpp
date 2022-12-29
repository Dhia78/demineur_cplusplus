/**
@file : commande_3.cpp
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
@brief : fonction d'evaluation de la reussite d'une partie
*/
#include<iostream>
#include<string>
#include"commandes.h"

/**
@brief : renvoie un booleen pour indiquer si la partie est gagnée ou toujours en cours
@param [in] nbMines : nombre de mines
@param [in] indexMines : tableau des index des mines
@param [in] nbCoups : nombre de coups deja joues
@param [in] historiqueCoups : tableau des coups deja joues
@return : un booleen
*/
bool game_won(int nbMines, const int indexMines[], int nbCoups, const Coups historiqueCoups[]){
    int *minesDemasquee = new int[nbMines];
    //initialisation des valeurs par defaut
    for (int i = 0 ; i < nbCoups ; i++)
        minesDemasquee[i] = 0; 

    for (int i = 0 ; i < nbCoups ; i++){
        if (historiqueCoups[i].typeCoup == 'M')
            for (int j = 0 ; j < nbMines ; j++)
                if (historiqueCoups[i].index == indexMines[j])
                    minesDemasquee[j] = 1;

        else if (historiqueCoups[i].typeCoup == 'D')
            for (int j = 0 ; j < nbMines ; j++)
                if (historiqueCoups[i].index == indexMines[j])
                    return false;
    }
    
    //test de victoire
    for (int i = 0 ; i < nbMines ; i++)
        if (indexMines[i]  != 0){
            delete [] minesDemasquee;
            return false;
        }
    delete [] minesDemasquee;
    return true;

}
