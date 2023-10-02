#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define M 10

struct agenda{
    char nome [20];
    char telefono [25];
};

int menu (void);
int inserisci (struct agenda*,int);
void visualizza (struct agenda*,int);
void visu (struct agenda);
void cercapernome (struct agenda*,int);
void cercapernumero (struct agenda*,int);

int main(){
    struct agenda a[M];
    int c=-1,s;
    do{
        s=menu();
        switch(s){
            case 1: c=inserisci(a,c); break;
            case 2: visualizza(a,c); break;
            case 3: cercapernome(a,c); break;
            case 4: cercapernumero(a,c); break;
        } 
    }while(s!=5);
}
int menu(void){
    int x;
    printf("\n1=Inserisci");
    printf("\n2=Visualizza");
    printf("\n3=Cerca per nome");
    printf("\n4=Cerca per numero");
    printf("\n5=Fine");
    printf("\nScegli:");
    scanf("%d",&x);
    return x;
}
int inserisci (struct agenda*w,int x){
    if(x==M-1){
        printf("\n\nAgenda piena!!!");
        return x;
    }
    x++;
    do{
        printf("\nDammi il nome:");
        fflush(stdin);
        gets((w+x)->nome);
    }while(strlen((w+x)->nome)<4);
    do{
        printf("Dammi il numero:");
        fflush(stdin);
        gets((w+x)->telefono);
    }while(strlen((w+x)->telefono)<6);
    return x;
}
void visualizza(struct agenda*w,int x){
    int i;
    if(x>=0)
        for (i=0;i<=x;i++)
            visu(*(w+i));
    else
        printf("\nAgenda vuota!!!\n");
}
void visu (struct agenda w){
    printf("\nNome:%s",w.nome);
    printf("\nTelefono:%s",w.telefono);
    printf("\n");
}
void cercapernome(struct agenda*w,int x){
    char n[20];
    int i,trovato=0;
    if(x==-1){
        printf("\nAgenda vuota!!!\n");
        return;
    }
    printf("\nDammi il nome:");
    fflush(stdin);
    gets(n);
    for(i=0;i<=x;i++)
        if(strcmp(n,(w+i)->nome)==0){
            visu(*(w+i));
            trovato=1;
        }
    if(!trovato)
        printf("\nNome non trovato!!!\n");
}

void cercapernumero(struct agenda*w,int x){
    char n[25];
    int i=0,trovato=0;
    if(x==-1){
        printf("\nAgenda vuota!!!\n");
        return;
    }
    printf("\nDammi il numero:");
    fflush(stdin);
    gets(n);
    while(i<=x&&strcmp(n,(w+i)->telefono)!=0)
        i++;
    if(i>x)
        printf("\nNumero non trovato!!!\n");
    else
        visu(*(w+i));
}

      
    
         
    
            
    
