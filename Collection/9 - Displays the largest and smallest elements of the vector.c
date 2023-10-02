# include <stdio.h>
# include <stdlib.h>
# define M 5

int main(){
    
    int V[M],i,max,min;
    
    for(i=0;i<M;i++){
        printf("\nDammi l'elemento %d del vettore: ",i);
        scanf("%d",&V[i]);
    }
    
    max=V[0];
    
    for(i=1;i<M;i++)
        if(V[i]>max)
            max=V[i];
    
    printf("\nIl maggiore e: %d\n\n",max);
            
    min=V[0];
    
    for(i=1;i<M;i++)
        if(V[i]<min)
            min=V[i];
    
    printf("\nIlminore e: %d\n\n",min);
               
    system ("pause");
    
}    
            
