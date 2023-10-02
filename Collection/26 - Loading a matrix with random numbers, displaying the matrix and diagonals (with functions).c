# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define R 10
# define C 10

void carica(int(*)[C]);
void visualizza (int(*)[C]);
void diagonaleprincipale (int(*)[C]);
void diagonalesecondaria (int(*)[C]);

int main (){
    int m[R][C];
    carica(m);
    visualizza(m);
    diagonaleprincipale(m);
    diagonalesecondaria(m);
    system ("pause");
}
void carica (int(*w)[C]){
    int r,c;
    srand (time(NULL));
    for(r=0;r<R;r++)
        for(c=0;c<C;c++)
            w[r][c]=rand()%500+1;
}
void visualizza (int(*w)[C]){
    int r,c;
    printf("Matrice:\n");
    for(r=0;r<R;r++){
        for(c=0;c<C;c++)
            printf("%4d",w[r][c]);
        printf("\n");
    }
} 
void diagonaleprincipale (int(*w)[C]){
    int r,c;
    printf("\nDiagonale principale:\n");
    for(r=0;r<R;r++){
        for(c=0;c<r;c++)
            printf("    ");
        printf("%4d\n",w[r][r]);
    }    
}               
void diagonalesecondaria(int(*w)[C]){
    int r,c;
    printf("\n\nDiagonale secondaria:\n");
    for(r=0;r<R;r++){         
        for(c=R-r-1;c>0;c--)
            printf("    ");    
        printf("%4d\n",w[r][R-r-1]);
    }
    printf("\n");
}
