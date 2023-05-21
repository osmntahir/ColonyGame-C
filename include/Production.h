/** 
* @file -->     Uretim.h
* @description  Uretim class gorevi ustlenen Uretim baslik dosyasi
* @course       2-A
* @assignment   2
* @date         10/05/2023
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/

#ifndef PRODUCTION_H

#define PRODUCTION_H




struct PRODUCTION {
    int (*produce) ();
     void(*deleteProduction) (struct PRODUCTION *);
};
typedef struct PRODUCTION * Production;

Production newProduction();
void deleteProduction(const Production);

#endif
