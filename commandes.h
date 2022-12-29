/**
@file : commandes.h
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
@brief : fonctions de creation ou d'interpretation d'une partie de demineur
*/
#ifndef COMMANDES
#define COMMANDES

using namespace std;

struct Coups{
    char typeCoup;
    int index;
};


/**
@brief : permet d'interpréter un coup entré par l'utilsateur et d'affecter les valeurs correspondantes à une variable de type Coups
@param [in, out] coups : la variable de type Coups
*/
void lireCoups(Coups& coups);

/**
@brief : test si un entier est contenu dans un tableau d'entier
@param [in] element : l'element a chercher
@param [in] tab : le tableau
@param [in] sizeTab : la taille du tableau
@return : un boolean
*/
bool is_contain_in_tab(int element, int tab[], int sizeTab);

/**
@brief : produit un probleme a partir du nombre de lignes, de colonnes, et du nombre de mines
@param [in] nbLignes : nombre de ligne de la grille
@param [in] nbColonnes : nombre de colonne de la grille
@param [in] nbMines : nombre de mines
*/
void make_problem(int nbLignes, int nbColonnes, int nbMines);

/**
@brief : affiche l'état d'une grille a partir d'un probleme et d'un historique de coups
@param [in] nbLignes : nombre de ligne de la grille
@param [in] nbColonnes : nombre de colonne de la grille
@param [in] nbMines : nombre de mines
@param [in] indexMines : tableau des index des mines
@param [in] nbCoups : nombre de coups deja joues
@param [in] historiqueCoups : tableau des coups deja joues
*/
void print_grille(int nbLignes, int nbColonnes, int nbMines, const int indexMines[], int nbCoups, const Coups historiqueCoups[]);

/**
@brief : renvoie un booleen pour indiquer si la partie est gagnée ou toujours en cours
@param [in] nbMines : nombre de mines
@param [in] indexMines : tableau des index des mines
@param [in] nbCoups : nombre de coups deja joues
@param [in] historiqueCoups : tableau des coups deja joues
@return : un booleen
*/
bool game_won(int nbMines, const int indexMines[], int nbCoups, const Coups historiqueCoups[]);

/**
@brief : indique si la partie est perdue ou encore en cours
@param [in] nbMines : nombre de mines
@param [in] indexMines : tableau des index des mines
@param [in] nbCoups : nombre de coups deja joues
@param [in] historiqueCoups : tableau des coups deja joues
@return : un booléen
*/
bool game_lost(int nbMines, const int indexMines[], int nbCoups, const Coups historiqueCoups[]);

/**
@brief : trouve une case a demasquer ou affiche une erreur si elle n'en trouve pas
@param [in] nbLignes : nombre de ligne de la grille
@param [in] nbColonnes : nombre de colonne de la grille
@return : l'index d'une case 
*/
int find_move(int nbLignes, int nbColonnes);

#endif
