#include <stdio.h>
#include <stdlib.h>

int main (){
    
    int m;
    
    do{
           printf("Dammi un numero compreso tra 1 e 12: ");
           scanf("%d",&m);
    } while (m<1||m>12);
    
    switch(m){
           case 1: printf("\nGennaio\n\n"); break;
           case 2: printf("\nFebbraio\n\n"); break;
           case 3: printf("\nMarzo\n\n"); break;
           case 4: printf("\nAprile\n\n"); break;
           case 5: printf("\nMaggio\n\n"); break;
           case 6: printf("\nGiugno\n\n"); break;
           case 7: printf("\nLuglio\n\n"); break;
           case 8: printf("\nAgosto\n\n"); break;
           case 9: printf("\nSettembre\n\n"); break;
           case 10: printf("\nOttobre\n\n"); break;
           case 11: printf("\nNovembre\n\n"); break;
           case 12: printf("\nDicembre\n\n"); break;
    }
    
    system ("pause");
    
}
