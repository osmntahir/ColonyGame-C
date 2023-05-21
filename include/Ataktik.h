/** 
* @file -->     Ataktik.h
* @description  Taktik yapisindan kalitim alan Ataktik sinifi
* @course       2-A
* @assignment   2
* @date         10/05/2023
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef ATAKTIK_H
#define ATAKTIK_H


#include "Taktik.h"

struct STRATEGY_A
{
   Strategy super;
   void (*deleteStrategyA) (struct STRATEGY_A *);
};

typedef struct STRATEGY_A *StrategyA ;

StrategyA newStrategyA();
int StrategyWarA(const StrategyA);
void deleteStrategyA(const StrategyA);

#endif