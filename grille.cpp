/**
@file : grille.cpp
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
@brief : initialise une grille de demineur
*/
#include<iostream>
#include"grille.h"

/**
@brief : alloue dynamiquement la matrice représentant la grille
@param [in, out] grille : la grille
@param [in] nbLignes : le nombre de lignes de la matrice
@param [in] nbColonnes : le nombre de colonnes de la matrice
*/
void init_grille(Grille* grille, const int nbLignes, const int nbColonnes){
    grille->nbLignes = nbLignes;
    grille->nbColonnes = nbColonnes;
    grille->cases = new Case*[nbLignes];
    for (int i = 0 ; i < nbLignes ; i++)
        grille->cases[i] = new Case[nbColonnes];
}

/**
@brief : initialise les valeurs des cases d'une grille
@param [in, out] grille : la grille
@param [in] indexMines : tableau contenant les index des mines
@param [in] nbMines : le nombre de mines
*/
void init_cases(Grille* grille, const int indexMines[], int nbMines){
    //initialisation des valeurs par défaut des cases
    for (int i = 0 ; i < grille->nbLignes ; i++){
        for (int j = 0 ; j < grille->nbColonnes ; j++){
            grille->cases[i][j].estMine = false;
            grille->cases[i][j].estDecouvert = false;
            grille->cases[i][j].estMarquee = false;
            grille->cases[i][j].nbMinesEnvironnantes = 0;
        }
    }
    
    //initialisation des cases contenant des mines
    for (int i = 0; i < nbMines; i++)
        grille->cases[indexMines[i]/grille->nbColonnes][indexMines[i]%grille->nbColonnes].estMine = true;
    
    //initialisations des cases autour des mines
    for (int i = 0 ; i < grille->nbLignes ; i++){
        for (int j = 0 ; j < grille->nbColonnes ; j++){
            if (grille->cases[i][j].estMine){
                
                if (i > 0)
                    grille->cases[i-1][j].nbMinesEnvironnantes++;
                
                if (i < grille->nbLignes-1)
                    grille->cases[i+1][j].nbMinesEnvironnantes++;
                    
                if (j > 0){
                    grille->cases[i][j-1].nbMinesEnvironnantes++;
                    if (i > 0)
                        grille->cases[i-1][j-1].nbMinesEnvironnantes++;
                    if (i < grille->nbLignes-1)
                        grille->cases[i+1][j-1].nbMinesEnvironnantes++;
                }

                if (j < grille->nbColonnes-1){
                    grille->cases[i][j+1].nbMinesEnvironnantes++;
                    if (i > 0)
                        grille->cases[i-1][j+1].nbMinesEnvironnantes++;
                    if (i < grille->nbLignes-1)
                        grille->cases[i+1][j+1].nbMinesEnvironnantes++;
                }
            }
        }
    }
}

void demasquer(Grille* grille, int indexCaseDemasqueI, int indexCaseDemasqueJ){
    if (!grille->cases[indexCaseDemasqueI][indexCaseDemasqueJ].estDecouvert){
        grille->cases[indexCaseDemasqueI][indexCaseDemasqueJ].estDecouvert = true;
    
        if(grille->cases[indexCaseDemasqueI][indexCaseDemasqueJ].nbMinesEnvironnantes == 0){
            if (indexCaseDemasqueI > 0) 
                demasquer(grille, indexCaseDemasqueI-1, indexCaseDemasqueJ);
            
            if (indexCaseDemasqueI < grille->nbLignes-1)
                demasquer(grille, indexCaseDemasqueI+1, indexCaseDemasqueJ);
            
            if (indexCaseDemasqueJ > 0){
                demasquer(grille, indexCaseDemasqueI, indexCaseDemasqueJ-1);
                if (indexCaseDemasqueI > 0)
                    demasquer(grille, indexCaseDemasqueI-1, indexCaseDemasqueJ-1);
                if (indexCaseDemasqueI < grille->nbLignes-1)
                    demasquer(grille, indexCaseDemasqueI+1, indexCaseDemasqueJ-1);
            }
            
            if (indexCaseDemasqueJ < grille->nbColonnes-1){
                demasquer(grille, indexCaseDemasqueI, indexCaseDemasqueJ+1);
                if (indexCaseDemasqueI > 0)
                    demasquer(grille, indexCaseDemasqueI-1, indexCaseDemasqueJ+1);
                if (indexCaseDemasqueI < grille->nbLignes-1)
                    demasquer(grille, indexCaseDemasqueI+1, indexCaseDemasqueJ+1);
            }
        }
    }
}