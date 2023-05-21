#include "Game.h"

#include <stdlib.h>
#include <stdio.h>

Game newGame(Colony *colonies,int coloniCounts)
{
    Game this;
    this = this = (Game) malloc(sizeof(struct GAME));
    this->colonies = colonies;
    this->colonyCounts = coloniCounts;
    this->ColonyWar = &ColonyWar;
    this->EndofTourOperations = &EndofTourOperations;
    this->Avengers = coloniCounts;
    this->WriteColonies = &WriteColonies;
    this->DeleteColonies =&DeleteColonies;
    this->printTheWinner = &printTheWinner;
    return this;
}
void ColonyWar(const Game this)
{
    int i, j;

    for (i = 0; i < this->colonyCounts; i++)
    {
        // koloni 1 olu ise atla
        if (!this->colonies[i]->isAlive)
        {
            continue;
        }

        for (j = i + 1; j < this->colonyCounts; j++)
        {
            // koloni 2 olu ise atla
            if (!this->colonies[j]->isAlive)
            {
                continue;
            }
            // farkli taktikler ile ebebeyn yapiya ulasip ayni fonksiyonu kendilerine gore cagirma
            int coloni1value = this->colonies[i]->strategy_a->super->war(this->colonies[i]->strategy_a);
            int coloni2value = this->colonies[j]->strategy_b->super->war(this->colonies[j]->strategy_b);
            
         //   printf("koloni1 deger    -    koloni2deger \n");
         //   printf("    %d        -        %d \n" , coloni1value, coloni2value);
             int  distinction =abs (coloni1value - coloni2value );
            
             double rate =(double) distinction / 1000;
       

    // koloni 1 kazandi
            if (coloni1value > coloni2value)
            {
                
                this->colonies[j]->population -=  (this->colonies[j]->population * rate);
                
                int foodAmount = (this->colonies[j]->foodStock * rate);
               
                this->colonies[j]->foodStock -= foodAmount;
                this->colonies[i]->foodStock += foodAmount;

                this->colonies[i]->winsCount++;
                this->colonies[j]->lostsCount++;
            }
            // koloni 2 kazandi
            else if (coloni1value < coloni2value)
            {
               
                this->colonies[i]->population -= (this->colonies[i]->population * rate);
                int foodAmount =  (this->colonies[i]->foodStock * rate);
                this->colonies[i]->foodStock -= foodAmount;
                this->colonies[j]->foodStock += foodAmount;

                this->colonies[j]->winsCount++;
                this->colonies[i]->lostsCount++;
            }
            // berabere durumu
            else
            {
                int populationDifference = this->colonies[i]->population - this->colonies[j]->population;

                if (populationDifference > 0)
                {
                    // koloni1 kazandı
                    this->colonies[i]->winsCount++;
                    this->colonies[j]->lostsCount++;
                }
                else if (populationDifference < 0)
                {
                    // koloni2 kazandı
                    this->colonies[j]->winsCount++;
                    this->colonies[i]->lostsCount++;
                   
                }
                //rastgele secim
                else
                {
                    int choice = rand() % 2;
                    if (choice == 0)
                    {
                        // koloni1 kazandı
                        this->colonies[i]->winsCount++;
                        this->colonies[j]->lostsCount++;
                    }
                    else
                    {
                        // koloni2 kazandı
                        this->colonies[j]->winsCount++;
                        this->colonies[i]->lostsCount++;
                    }
                }
            }
           
            
        }
    }
 
}

     // tur sonu guncellemesi              

void EndofTourOperations(const Game this)
{

   for (int i = 0; i <this->colonyCounts ; i++)
   {
		if (this->colonies[i]->isAlive )
		{
			  this->colonies[i]->tourUpdate(this->colonies[i]);

              // koloni oldurme
			 if(this->colonies[i]->population <= 0 || this->colonies[i]->foodStock <= 0)
			 {
				this->colonies[i]->isAlive = false;
				this->Avengers--;
             }
		}      
    }
}
// kolonuileti yazdirma
void WriteColonies (const Game this)
{
     for (int i = 0; i < this->colonyCounts; i++) {
            char *str = this->colonies[i]->toString(this->colonies[i]);
            printf("%s \n", str);
            free(str);
        }
}
void printTheWinner(const Game this)
{
    for (int i = 0; i < this->colonyCounts; i++)
    {
        if (this->colonies[i]->isAlive)
        {
            
            printf("\n\nThe Winning Colony : %c", this->colonies[i]->symbol);
           
        }
        
    }
    
}
// kolonileri bellekten temizleme
void DeleteColonies(const Game this)
{
        for (int i = 0; i < this->colonyCounts ; i++) {
            this->colonies[i]->delete(this->colonies[i]);
            
            }
}