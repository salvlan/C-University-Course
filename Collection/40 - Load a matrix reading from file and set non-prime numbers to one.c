#include <stdio.h>
#include <conio.h>
#define M 10
#define F1 "numeri da caricare.txt"
#define F2 "numeri della matrice.txt"

void carica(int(*)[M]);
void rimuovi_numeri_non_primi(int(*)[M]);
int primo(int);
void visualizzamat(int(*)[M]);
void scrivifiletesto(int(*)[M]);

int main(){
    int m[M][M];
    carica(m);
    printf("\nMatrice:");
    visualizzamat (m);
    rimuovi_numeri_non_primi(m);
    printf("\nMatrice con numeri non primi=1:");
    visualizzamat (m);
    scrivifiletesto(m);
    getch();
}
void carica (int(*x)[M]){
    int r=-1,c,num;
    FILE *fp;
    fp=fopen(F1,"rt");
    if(fp==NULL){
        printf("\nErrore open file txt!");
        getch();
        return;
    }
    for(r=0;r<M;r++)
        for(c=0;c<M;c++){
            fscanf(fp,"%d",&num);
            x[r][c]=num;
        }
    fclose(fp);
}
void visualizzamat(int(*x)[M]){
    int r,c;
    for(r=0;r<M;r++){
        printf("\n");
        for(c=0;c<M;c++)
            printf("%5d\t",x[r][c]);
    }
}
void rimuovi_numeri_non_primi(int(*x)[M]){
    int r,c,i,ris;
    for(r=0;r<M;r++)
        for(c=0;c<M;c++){
            ris=primo(x[r][c]);
            if(ris==0)
                x[r][c]=1;
        }
}
int primo (int x){
    int i;
    for(i=2;i<x/2;i++)
        if(x%i==0)
            return 0;
    return 1;
}
void scrivifiletesto(int(*x)[M]){
    int r,c;
    FILE *fp;
    fp=fopen(F2,"at");
    if(fp==NULL){
        printf("\nErrore open file testo!\n");
        getch();
        return;
    }
    for(r=0;r<M;r++)
        for(c=0;c<M;c++)
            fprintf(fp,"%d",x[r][c]);
    fclose(fp);      
}

                   

    
                    
            
