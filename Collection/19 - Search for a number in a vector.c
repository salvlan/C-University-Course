# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define M 400

void carica (int*);
void visualizza(int*);
int dammi (void);
int ricerca (int*,int);
void risposta (int);

int main(){
    int V[M],n,pos;
    carica(V);
    visualizza(V);
    n=dammi();
    pos=ricerca (V,n);
    risposta (pos);
    system ("pause");
}
void carica(int*w){
     int i;
     srand(time(NULL));
     for(i=0;i<M;i++)
         *(w+i)=rand()%500+1;
}
void visualizza(int*w){
     int i;
     for(i=0;i<M;i++)
         printf("\t%d",*(w+i));
}
int dammi (void){
    int x;
    do{
        printf("\nDammi un numero compreso tra 1 e 500: ");
        scanf("%d",&x);
    }while (x<0||x>500);
    return x;
}
int ricerca (int*w,int x){
    int p=-1,i=0;
    while (i<M &&x!=*(w+i))
        i++;
    if (i<M)
        p=i;
    return p;
}
void risposta (int x){
    if (x==-1)
        printf("\nIl numero digitato non si trova nel vettore!\n\n");
    else
        printf ("\nIl numero digitato si trova nella posizione %d del vettore\n\n",x);
}     
     
     
