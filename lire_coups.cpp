/**
@file : lire_coups.cpp
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
@brief : fonction d'interpretation d'un coups entré par l'utilisateur
*/
#include<iostream>
#include"commandes.h"

/**
@brief : permet d'interpréter un coup entré par l'utilsateur et d'affecter les valeurs correspondantes à une variable de type Coups
@param [in, out] coups : la variable de type Coups
*/
void lireCoups(Coups& coups){
    cin >> ws; 
    cin.get(coups.typeCoup);
    cin >> coups.index;
}
