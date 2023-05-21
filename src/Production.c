#include  "Production.h"
#include  "stdlib.h"

Production newProduction()
{
    Production this;
    this = (Production)malloc(sizeof(struct PRODUCTION));
    this->deleteProduction = &deleteProduction;
    return this;

}

void deleteProduction(const Production this)
{
    free(this);
}
Production newProduction();
void deleteProduction(const Production);