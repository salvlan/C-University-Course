#include <conio.h>
#include <stdio.h>
#define FT "numeri.txt"
#define M 10

void azzera (int(*)[M]);
void carica (int(*)[M]);
void visualizza (int(*)[M]);

int main(){
    int m[M][M];
    azzera(m);
    carica(m);
    visualizza(m);
    getch();
}
void azzera (int(*x)[M]){
    int r,c;
    for(r=0;r<M;r++)
        for(c=0;c<M;c++)
            x[r][c]=0;
}
void carica (int(*x)[M]){
    int r=-1,c,num,i;
    FILE *fp;
    fp=fopen(FT,"rt");
    if(fp==NULL){
        printf("\nErrore open file txt!");
        getch();
        return;
    }
    while(fscanf(fp,"%d",&num)>0&&r<9){
        r++;
        c=-1;
        for(i=1;i<=num/2&&c<8;i++)
            if(num%i==0){
                c++;
                x[r][c]=i;
            }
        c++;
        x[r][c]=num;
    }
    fclose(fp);
}
void visualizza (int(*x)[M]){
    int r,c;
    for(r=0;r<M;r++){
        printf("\n");
        for(c=0;c<M;c++)
            printf("%5d\t",x[r][c]);
    }
}
