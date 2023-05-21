#include "BUretim.h"
#include <stdlib.h>

 ProductionB newProductionB()
{
    ProductionB this;
    this = (ProductionB)malloc(sizeof(struct PRODUCTION_B));
    this->super = newProduction();
    this->super->produce= &ProductionProduceB;
    this->deleteProductionB = &deleteProductionB;

    return this;
}
int ProductionProduceB(const ProductionB this)
{
    return 1+ rand() %10;
}
void deleteProductionB(const ProductionB this)
{
   
     if (this == NULL) return;
      this->super->deleteProduction(this->super);
        free(this);
}
