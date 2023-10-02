# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define M 13

int main(){
    
    int V1[M],V2[M],i,cont=0;
    
    for(i=0;i<M;i++)
        do{                 
            printf("\nDammi il risultato della partita numero %d: ",i+1);
            scanf("%d",&V1[i]);
        } while (V1[i]<0||V1[i]>2);
    
    srand(time(NULL));
    
    for(i=0;i<M;i++)
        V2[i]=rand()%3;
        
    for(i=0;i<M;i++)
        if(V1[i]==V2[i])
            cont++;
    
    printf("\nHai indovinato %d partite\n\n",cont);
    
    system("pause");
    
}        
        
