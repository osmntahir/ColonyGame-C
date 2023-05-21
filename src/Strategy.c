#include "Strategy.h"

Strategy newStrategy()
{
    Strategy this;
    this = (Strategy)malloc(sizeof(struct STRATEGY));
    this->deleteStrategy = &deleteStrategy;

    return this;

}
void deleteStrategy(const Strategy this)
{
    free(this);
}