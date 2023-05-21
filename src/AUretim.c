#include "AUretim.h"
#include <stdlib.h>
ProductionA newProductionA()
{
    ProductionA this;
    this = (ProductionA)malloc(sizeof(struct PRODUCTION_A));
    this->super = newProduction();
    this->super->produce= &ProductionProduceA;
    this->deleteProductionA = &deleteProductionA;

    return this;
}
int ProductionProduceA(const ProductionA this)
{
    return 1+ rand()%5 +rand() %6 ;
}
void deleteProductionA(const ProductionA this)
{
     if (this == NULL) return;
       this->super->deleteProduction(this->super);
        free(this);
}


