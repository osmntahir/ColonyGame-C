/** 
* @file -->     BUretim.h
* @description  Uretim yapisindan kalitim alan AUreyim sinifi
* @course       2-A
* @assignment   2
* @date         10/05/2023
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef PRODUCTIONB_H
#define PRODUCTIONB_H


#include "Production.h"

struct PRODUCTION_B
{
   Production super;
   void (*deleteProductionB) (struct PRODUCTION_B *);
};

typedef struct PRODUCTION_B *ProductionB ;

ProductionB newProductionB();
int ProductionProduceB(const ProductionB);
void deleteProductionB(const ProductionB);

#endif