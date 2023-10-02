# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define M 30

int main(){
    
    int V[M],i;
    
    srand(time(NULL));
    
    for(i=0;i<M;i++){
        V[i]=rand()%100+1;
        printf("\t%d",V[i]); 
    }
    system ("pause");

}
   
