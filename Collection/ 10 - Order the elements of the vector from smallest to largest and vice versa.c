# include <stdio.h>
# include <stdlib.h>
# define M 5

int main(){
    
    int V[M],i,app,j;
     
    for (i=0;i<M;i++){
        printf("\nDammi l'elemento %d del vettore: ",i);
        scanf("%d",&V[i]);
    }
    
    for(i=0;i<M-1;i++)
        for(j=i+1;j<M;j++)
            if(V[i]>V[j]){
                app=V[i];
                V[i]=V[j];
                V[j]=app;
            }
            
    printf("\n\nIn ordine crescente:\n\n");
            
    for(i=0;i<M;i++)
        printf("\t%d",V[i]);
        
    for(i=0;i<M-1;i++)
        for(j=i+1;j<M;j++)
            if(V[i]<V[j]){             
                app=V[i];
                V[i]=V[j];
                V[j]=app;
            }
            
    printf("\n\nIn ordine decrescente:\n\n");
    
    for(i=0;i<M;i++)       
        printf("\t%d",V[i]);
        
    printf("\n\n");
        
    system ("pause");
}                
                
            
