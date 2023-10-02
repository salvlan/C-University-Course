# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define M 400

void carica (int*);
void ordina (int*);
void visualizza(int*);
int dammi (void);
int ricerca (int*,int);
void risposta (int);

int main(){
    int V[M],n,pos;
    carica(V);
    ordina (V);
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
void ordina(int*w){
     int i,j,app;
     for (i=0;i<M-1;i++)
         for (j=i+1;j<M;j++)
             if (*(w+j)<*(w+i)){
                 app=*(w+j);
                 *(w+j)=*(w+i);
                 *(w+i)=app;
             }
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
    int p=-1,s=0,d=M-1,m;
    do{
        m=(int)((d+s)/2);
        if (*(w+m)==x)
            p=m;
        else
            if(*(w+m)>x)
                d=m-1;
            else
                s=m+1;
    }while (p==-1&&s<=d);
    return p;
}
void risposta (int x){
    if (x==-1)
        printf("\nIl numero digitato non si trova nel vettore!\n\n");
    else
        printf ("\nIl numero digitato si trova nella posizione %d del vettore\n\n",x);
}     
     
