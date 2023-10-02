# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define M 30

void carica(int*);
void visualizza(int*);

int main(){
    int V[M];
    
    carica(V);
    visualizza(V);
    
    system ("pause");
}
void carica(int*w){
     int i;
     
     srand(time(NULL));
     for(i=0;i<M;i++)
         *(w+i)=rand()%2000;
}
void visualizza(int*w){
     int i;
     for(i=0;i<M;i++)
         printf("\t%d",*(w+i));
}
         
