/** 
* @file -->     AUretim.h
* @description  Uretim yapisindan kalitim alan AUretom sinifi
* @course       2-A
* @assignment   2
* @date         11/05/2023
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef PRODUCTIONA_H
#define PRODUCTIONA_H


#include "Production.h"

struct PRODUCTION_A
{
   Production super;
   void (*deleteProductionA) (struct PRODUCTION_A *);
};

typedef struct PRODUCTION_A *ProductionA ;

ProductionA newProductionA();
int ProductionProduceA(const ProductionA);
void deleteProductionA(const ProductionA);

#endif