/** 
* @file -->     Oyun.h
* @description  koloniler ile ilgili islemleri yapan oyun baslik dosyasi
* @course       2-A
* @assignment   2
* @date         9/05/2023
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/

#ifndef GAME_H
#define GAME_H

#include "Colony.h" 


struct GAME
{
    
    Colony* colonies;
    void (*ColonyWar) ( struct GAME *);
    void (*EndofTourOperations) ( struct GAME *) ;
    void (*WriteColonies) ( struct GAME *) ;
     void (*DeleteColonies) ( struct GAME *) ;
     void (*printTheWinner)(struct GAME *);
    int Avengers;
    int colonyCounts;
};


typedef struct GAME * Game;
Game newGame(Colony *colonies, int colonyCounts);
void ColonyWar(const Game);
void EndofTourOperations( const Game);
void WriteColonies(const Game);
void DeleteColonies(const Game);
void printTheWinner(const Game);




















#endif