# include <stdlib.h>
# include <stdio.h>
# define M 10

int menu(void);
int inserisci(int*,int);
void visualizza(int*,int);
void minimo(int*,int);
void massimo(int*,int);
int somma(int*,int);
void media(int*,int);

int main(){
    int V[M],sc,n=-1,s;
    do{
        sc=menu();
        switch(sc){
            case 1: n=inserisci(V,n); break;
            case 2: visualizza(V,n); break;
            case 3: minimo(V,n); break;
            case 4: massimo(V,n); break;
            case 5: s=somma(V,n); printf("La somma e:%d",s); break;
            case 6: media(V,n); break;
        }
    }while(sc!=7);
    system ("pause");
}
int menu(void){
    int s;
    printf("\n");
    printf("\n1=Inserisci");
    printf("\n2=Visualizza");
    printf("\n3=Minimo");
    printf("\n4=Massimo");
    printf("\n5=Somma");
    printf("\n6=Media");
    printf("\n7=Fine");
    printf("\nScegli: ");
    scanf("%d",&s);
    printf("\n");
    return s;
}
int inserisci (int*w,int x){
    if(x==M-1){
        printf("Vettore pieno!");
        return x;
    }
    x++;
    printf("Dammi il valore: ");
    scanf("%d",w+x);
    return x;
}
void visualizza(int*w,int x){
     int i;
     if(x==-1)
         printf("Vettore vuoto!");
     else
         for(i=0;i<=x;i++)
             printf("\t%d",*(w+i));
}
void minimo(int*w,int x){
     int min,i;
     if(x==-1)
         printf("Vettore vuoto!");
     else{
         min=*w;
         for(i=1;i<=x;i++)
             if(*(w+i)<min)
                 min=*(w+i);
         printf("Il minimo e:%d",min);
     }
}         
void massimo(int*w,int x){
     int max,i;
     if(x==-1)
         printf("Vettore vuoto!");
     else{
         max=*w;
         for(i=1;i<=x;i++)
             if(*(w+i)>max)
                 max=*(w+i);
         printf("Il massimo e:%d",max);
     }
}              
int somma(int*w,int x){
    int s=0,i;      
    for(i=0;i<=x;i++)
        s+=*(w+i);
    return s;
}
void media(int*w,int x){
     float m;
     if(x==-1)
         printf("Vettore vuoto!");
     else{
         m=(float)somma(w,x)/(x+1);
         printf("La media e:%f",m);
     }
}         
