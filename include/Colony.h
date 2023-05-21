/** 
* @file -->     Koloni.h
* @description  Kolonilerin ozelliklerini tutan koloni baslik dosyasi
* @course       2-A
* @assignment   2
* @date         8/05/2023
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/

#ifndef COLONY_H
#define COLONY_H

#include "ProductionA.h"
#include "ProductionB.h"
#include "StrategyA.h"
#include "StrategyB.h"


#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef enum Bool{false,true}boolean;

struct COLONY {
    char symbol;
    int population;
    int foodStock;
    int winsCount;
    int lostsCount;

    StrategyA strategy_a;
    StrategyB strategy_b;

    ProductionA production_a;
    ProductionB production_b;
    boolean isAlive;

    void (*tourUpdate) (struct COLONY *);
    void (*delete) (struct COLONY *);
    char* (*toString) (struct COLONY*);
 
};
typedef struct COLONY * Colony;

Colony new_Coloni(char symbol , int population);
void tourUpdate(const Colony);
void deleteColoni(const Colony);
char *toString(const Colony);

#endif
