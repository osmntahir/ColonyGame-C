#include "BTaktik.h"


StrategyB newStrategyB()
{
    StrategyB this;
    this = (StrategyB)malloc(sizeof(struct STRATEGY_B));
    this->super = newStrategy();
    this->super->war = &StrategyWarB;
    this->deleteStrategyB = &deleteStrategyB;

    return this;
}

int StrategyWarB(const StrategyB this) 
{
   return rand()%1001;
}
void deleteStrategyB(const StrategyB this)
{
     if (this == NULL) return;
       this->super->deleteStrategy(this->super);
        free(this);
}