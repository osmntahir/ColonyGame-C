/** 
* @file -->     BTaktik.h
* @description  Taktik yapisindan kalitim alan BTaktik sinifi
* @course       2-A
* @assignment   2
* @date         10/05/2023
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef BTAKTIK_H
#define BTAKTIK_H




#include "Taktik.h" 

struct STRATEGY_B
{
   Strategy super;
   void (*deleteStrategyB) (struct STRATEGY_B *);
};

typedef struct STRATEGY_B *StrategyB ;

StrategyB newStrategyB();
int StrategyWarB(const StrategyB);
void deleteStrategyB(const StrategyB);







#endif
