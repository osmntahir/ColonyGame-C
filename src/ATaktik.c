#include "ATaktik.h"


StrategyA newStrategyA()
{
    StrategyA this;
    this = (StrategyA)malloc(sizeof(struct STRATEGY_A));
    // ebebeyn nesnesi olusturma
    this->super = newStrategy();
    this->super->war = &StrategyWarA;
    this->deleteStrategyA = &deleteStrategyA;

    return this;
}

int StrategyWarA(const StrategyA this) 
{
  return  rand()%1001;
}


void deleteStrategyA(const StrategyA this)
{
    if (this == NULL) return;
       this->super->deleteStrategy(this->super);
        free(this);
}