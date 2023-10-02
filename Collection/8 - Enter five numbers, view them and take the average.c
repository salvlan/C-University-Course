# include <stdio.h>
# include <stdlib.h>
# define M 5
int main(){
    
    int V[M],i,s=0; 
    float m;
    
    for(i=0;i<M;i++){
        printf("\nDammi l'elemento %d del vettore: ",i);
        scanf("%d",&V[i]);
    }
    
    for(i=0;i<M;i++)
        printf("\t%d",V[i]);
    
    for(i=0;i<M;i++)
        s+=V[i];
        
    m=(float)s/M;
    printf("\n\nLa media e: %f\n\n",m);
    
    system ("pause");
}
