#include "RandomSymbol.h"

RandomNumber *random_number_create() {
    RandomNumber *rn = (RandomNumber *)malloc(sizeof(RandomNumber));
    if (rn == NULL) {
        return NULL;
    }

    rn->size = 94;
    rn->symbols = (char *)malloc(rn->size * sizeof(char));
    if (rn->symbols == NULL) {
        free(rn);
        return NULL;
    }

    for (int i = 0; i < rn->size; i++) {
        rn->symbols[i] = (char)(33 + i);
    }

  //  srand(time(NULL));
    return rn;
}

void random_number_destroy(RandomNumber *rn) {
    if (rn != NULL) {
        free(rn->symbols);
        free(rn);
    }
}

char random_number_get_symbol(RandomNumber *rn) {
    if (rn == NULL || rn->size == 0) {
        return '\0';
    }

    int random_index = rand() % rn->size;
    char symbol = rn->symbols[random_index];

    for (int i = random_index; i < rn->size - 1; i++) {
        rn->symbols[i] = rn->symbols[i + 1];
    }
    rn->size--;

    return symbol;
}
