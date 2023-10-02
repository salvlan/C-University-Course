#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define F "numeri primi.txt"

void carica(int(*)[M]);
void scrivifiletesto(int(*)[M]);
int primo(int);
void visualizzamat(int(*)[M]);
void visualizzafile();

int main(){
    int m[M][M];
    carica(m);
    scrivifiletesto(m);
    visualizzamat (m);
    visualizzafile();
    getch();
}
void carica(int(*x)[M]){
    int r,c;
    srand(time(NULL));
    for(r=0;r<M;r++)
        for(c=0;c<M;c++)
            x[r][c]=rand()%10000+1;
}
void scrivifiletesto(int(*x)[M]){
    int r,c,i,ris;
    FILE *fp;
    fp=fopen(F,"wt");
    if(fp==NULL){
        printf("\nErrore open file testo!\n");
        getch();
        return;
    }
    for(r=0;r<M;r++)
        for(c=0;c<M;c++){
            ris=primo(x[r][c]);
            if(ris==1)
                fprintf(fp,"\n%d",x[r][c]);
        }
    fclose(fp);
}
int primo (int x){
    int i;
    for(i=2;i<x/2;i++)
        if(x%i==0)
            return 0;
    return 1;
}
void visualizzamat(int(*x)[M]){
    int r,c;
    printf("\nMatrice:");
    for(r=0;r<M;r++){
        printf("\n");
        for(c=0;c<M;c++)
            printf("%5d\t",x[r][c]);
    }
}
void visualizzafile(){
    int num; 
    FILE *fp;
    fp=fopen(F,"rt");
    if(fp==NULL){
        printf("\nErrore open file testo!\n");
        getch();
        return;
    }
    printf("\nFile:");
    while(fscanf(fp,"%d",&num)>0)
        printf("\n%d",num);
    fclose(fp);    
}
            
                   

    
                    
            
