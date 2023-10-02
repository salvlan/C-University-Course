#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5

int main(){
    int V1[M],V2[M],i,j,OK,cont=0;
    for(i=0;i<M;i++)
        do{
            OK=1;
            do{
                printf("\nDammi il numero %d: ",i+1);
                scanf("%d",&V1[i]);
            }while(V1[i]<0||V1[i]>90);
            for(j=0;j<i;j++)
                if(V1[j]==V1[i])
                    OK=0;
        }while(!OK);
    srand(time(NULL));
    for(i=0;i<M;i++)
        do{
            OK=1;
            V2[i]=rand()%90+1;
            for(j=0;j<i;j++)
                if(V2[i]==V2[j])
                    OK=0;
        }while(!OK);
    printf("\n\nNumeri inseriti:\n\n");
    for(i=0;i<M;i++)
        printf("\t%d",V1[i]);
    printf("\n\nNumeri estratti:\n\n");
    for(i=0;i<M;i++)
        printf("\t%d",V2[i]);
    for(i=0;i<M;i++)
        for(j=0;j<M;j++)
            if(V1[i]==V2[j])
                cont++;
    switch(cont){
        case 0:printf("\n\nRitenta,sarai piu fortunato\n\n"); break;
        case 1:printf("\n\nAmbata\n\n"); break;
        case 2:printf("\n\nAmbo\n\n"); break;
        case 3:printf("\n\nTerno\n\n"); break;
        case 4:printf("\n\nQuaterna\n\n"); break;
        case 5:printf("\n\nCinquina\n\n");break;
    }
    system ("pause");    
}        
    
