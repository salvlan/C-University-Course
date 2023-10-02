# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define M 1000

void carica (int*);
int numerocasuale (void);
int ricercanonordinato (int*,int);
void ordina (int*);
int ricercadicotomica (int*,int,int*);
void visualizza (int*,int);
void visualizzaris (int);
void visualizzarisdic (int,int);

int main(){
    int V[M],n,i,tentativi,tentatividic,trovato;
    srand (time(NULL));
    for(i=1;i<10;i++){         
        carica(V);
        n=numerocasuale();
        tentativi=ricercanonordinato (V,n);
        ordina (V);
        trovato=ricercadicotomica (V,n,&tentatividic);
        printf("\nRicerca di un numero in un vettore prima non ordinato e poi tramite ricerca dicotomica:\n");
        visualizza(V,n);
        visualizzaris (tentativi);
        visualizzarisdic (trovato,tentatividic);
    }
    system("pause");
}
void carica (int*w){
    int i;
    for(i=0;i<M;i++)
        *(w+i)=rand()%2000+1;
}
int numerocasuale (void){
    int x;
    x=rand()%2000+1;
    return x;
}
int ricercanonordinato (int*w,int x){
    int i=0;
    while(i<M && x!=*(w+i))
        i++;
    return i;
}
void ordina (int*w){
    int i,j,app;
    for(i=0;i<M-1;i++)
        for(j=i+1;j<M;j++)
            if(*(w+j)<*(w+i)){
                app=*(w+j);
                *(w+j)=*(w+i);
                *(w+i)=app;
            }
}
int ricercadicotomica (int*w,int x, int*t){
    int i=1,s,d,m;
    d=M-1;
    s=0;
    m=(int)((d+s)/2);
    while(d>=s&&*(w+m)!=x){
        if (*(w+m)>x)
            d=m-1;
        else
            s=m+1;
        m=(int)(d+s)/2;
        i++;
    }
    *t=i;
    if(*(w+m)==x)
        return 1; 
    else
        return 0;     
}
void visualizza (int*w,int x){
    int i;
    printf("\nVettore ordinato:\n");
    for(i=0;i<M;i++)
        printf("%5d",*(w+i));
    printf("\n\nNumero:%d\n",x);
}
void visualizzaris (int y){
    if(y<M)
        printf("\nIl numero e' stato trovato nel vettore non ordinato dopo %d tentativi!\n",y);
    else
        printf("\nIl numero non e' stato trovato nel vettore non ordinato dopo %d tentativi!\n",y);
}
void visualizzarisdic (int x,int y){
    if(x==1)
        printf("\nIl numero e' stato trovato tramite ricerca dicotomica dopo %d tentativi!\n",y);
    else      
        printf("\nIl numero non e' stato trovato tramite ricerca dicotomica dopo %d tentativi!\n",y);
}
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
    
