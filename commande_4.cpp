/**
@file : commande_4.cpp
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
@brief : fonction d'evaluation de l'echec de la partie
*/
#include<iostream>
#include"commandes.h"

/**
@brief : indique si la partie est perdue ou encore en cours
@param [in] nbMines : nombre de mines
@param [in] indexMines : tableau des index des mines
@param [in] nbCoups : nombre de coups deja joues
@param [in] historiqueCoups : tableau des coups deja joues
@return : un booléen
*/
bool game_lost(int nbMines, const int indexMines[], int nbCoups, const Coups historiqueCoups[]){
    bool is_lost = true;
    for (int i = 0 ; i < nbCoups ; i++){
        if (historiqueCoups[i].typeCoup == 'D')
            for(int j = 0 ; j < nbMines ; j++)
                if (historiqueCoups[i].index == indexMines[j])
                    return true;

        if (historiqueCoups[i].typeCoup == 'M'){
            is_lost = true;
            for(int j = 0 ; j < nbMines ; j++)
                if (historiqueCoups[i].index == indexMines[j])
                    is_lost = false;
        }
    }
    return is_lost;
}
