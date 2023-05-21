/** 
* @file -->     RandomSembol.h
* @description  Random karakter baslik dosyasi
* @course       2-A
* @assignment   2
* @date         9/05/2023
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/

#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <stdlib.h>
#include <time.h>

typedef struct {
    char *symbols;
    int size;
} RandomNumber;

RandomNumber *random_number_create();
void random_number_destroy(RandomNumber *rn);
char random_number_get_symbol(RandomNumber *rn);

#endif
