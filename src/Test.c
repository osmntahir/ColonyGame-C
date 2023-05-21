/** 
* @file -->     Testc.c
* @description  Programin test edilisi
* @course       2-A
* @assignment   2
* @date         16/05/2023
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#include "Koloni.h"
#include "Oyun.h"
#include "RandomSembol.h"
#include <time.h>

int main()
{
    // farkli sayilar uretmeyi saglar
    srand(time(NULL));

    while (1) {
        // komut satirini temizler
        system("cls");

        // dinamik dizi olusturma
        int capacity = 5; // Dizi kapasitesi
        int size = 0;     // Dizinin mevcut boyutu
        int *populasyonlar = (int *)malloc(capacity * sizeof(int)); // Dinamik dizi oluşturulması

        printf("-- Sayilari boslukla ayirarak girin (Son sayidan hemen sonra enter a basiniz):\n\n");

        // Sayıları okuma ve dinamik diziye ekleme işlemi
        while (1) {
            int num;
            int result = scanf("%d", &num);

            if (result == EOF || result == 0) { // EOF veya hatalı giriş durumu
                break;
            }

            populasyonlar[size] = num;
            size++;

            if (size == capacity) { // Dizi kapasitesinin dolması durumu
                capacity *= 2; // Kapasiteyi iki katına çıkarma
                populasyonlar = (int *)realloc(populasyonlar, capacity * sizeof(int)); // Diziyi yeniden boyutlandırma
            }
            
                if ( getchar() == '\n') {
                    break;
                }

        }

        printf("Girilen sayilar: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", populasyonlar[i]);
        }
        printf("\n\n\n");

        int tourCounts = 0;
        // random karakter olusturma
        RandomNumber *rn = random_number_create();
        // koloniler dinamik dizisi ve bellekten yer ayirma
        Colony *colonies = (Colony *)malloc(size * sizeof(struct COLONY));

        // kolonileri olusturma
        for (int i = 0; i < size; i++) {
            colonies[i] = new_Coloni(random_number_get_symbol(rn), populasyonlar[i]);
        }

        Game game = newGame(colonies, size);

        printf("%-14s %-19s %-19s %-19s %-19s\n", "koloni", "populasyon", "yemekstogu", "kazanma", "kaybetme");
    
       // koloni yazdir
             game->WriteColonies(game);

        do {
            
            game->ColonyWar(game);
            game->EndofTourOperations(game);
            
            printf("\n\n");
            tourCounts++;
            printf("tur sayisi : %d \n", tourCounts);
            printf("%-14s %-19s %-19s %-19s %-19s\n", "koloni", "populasyon", "yemekstogu", "kazanma", "kaybetme");
            
             game->WriteColonies(game);
            } while (game->Avengers > 1);

    // kolonileri silme (bellek iadesi)
  //  game->DeleteColonies(game);
    printf("\n\n");

    // bellekte olusturulan nesneleri iade etme
    random_number_destroy(rn);
    free(game);
    free(populasyonlar);

    printf("Devam etmek istiyor musunuz (e/h) ? ");
    char choose;
    scanf(" %c", &choose);
    if (choose == 'H' || choose == 'h') {
        break;
    }
         getchar(); // Önceki scanf işleminden kalan newline karakterini tüketmek için getchar çağrısı
}

return 0;
}