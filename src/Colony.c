#include "Colony.h"
#include <stdlib.h>



Colony new_Coloni(char symbol , int population)
{
    Colony this;
    this = (Colony) malloc(sizeof(struct COLONY));
    this->population = population;
    this->foodStock = this->population * this->population;
    this->lostsCount =0;
    this->winsCount =0;
    this->symbol = symbol;
    this->isAlive = true;

    
    this->strategy_a = newStrategyA();
    this->strategy_b = newStrategyB();

    this->production_a = newProductionA();
    this->production_b = newProductionB();

    this->delete = &deleteColoni;
    this->tourUpdate = &tourUpdate;
    this->toString = &toString;

    return this;
    
}
// tur sonu islemleri yapilir
void tourUpdate(const Colony this)
{
     this->population += this->population * 0.20 ;
     this->foodStock -= (this->population * 2);
   
   
// koloninin rastgele bir sekilde farkli bir uretim teknigi kullanmasini saglama
    if (rand() % 2 == 0)
    {
        this->foodStock +=(this->production_b->super->produce(this->production_b));
    }
    else
    {
        this->foodStock += (this->production_a->super->produce(this->production_a));
    }
}

void deleteColoni(const Colony this)
{
    this->production_a->deleteProductionA(this->production_a);
    this->production_b->deleteProductionB(this->production_b);
    this->strategy_a->deleteStrategyA(this->strategy_a);
    this->strategy_b->deleteStrategyB(this->strategy_b);

    free(this);
}

// koloni yazdirma fonksiyonu
char *toString(const Colony this)
{
     char *srt = (char*)malloc(sizeof(char) * 1000);

    if (!this->isAlive) {
        snprintf(srt, 1000, "%-15c %-20s %-20s %-20s %-20s", this->symbol, "--", "--", "--", "--");
    }
    else {
        snprintf(srt, 1000, "%-15c %-20d %-20d %-20d %-20d",
            this->symbol, this->population, this->foodStock,
            this->winsCount, this->lostsCount);
    }
    
    return srt;
}