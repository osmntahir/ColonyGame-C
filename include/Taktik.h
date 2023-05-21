/** 
* @file -->     Taktik.h
* @description  Ebebeyn class gorevi ustlenen Taktik baslik dosyasi
* @course       2-A
* @assignment   2
* @date         10/05/2023
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/

#ifndef TAKTIK_H
#define TAKTIK_H

#include <stdlib.h>


struct STRATEGY {
    int (*war) ();
    void(*deleteStrategy) (struct STRATEGY *);
};
typedef struct STRATEGY * Strategy;

Strategy newStrategy();
void deleteStrategy(const Strategy);

#endif
