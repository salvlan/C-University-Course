# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define R 10
# define C 10

int main(){
    int m[R][C],r,c;
    
    srand (time(NULL));
    for(r=0;r<R;r++)
        for(c=0;c<C;c++)
            m[r][c]=rand()%500+1;
    
    printf("Matrice:\n");
    for(r=0;r<R;r++){
        for(c=0;c<C;c++)
            printf("%4d",m[r][c]);
        printf("\n");
    }
    
    printf("\n\nDiagonale:\n");
    for(r=0;r<R;r++){
        for(c=0;c<r;c++)
            printf("    ");
        printf("%4d\n",m[r][r]);
    }    
    
    printf("\n\nDiagonale opposta:\n");
    for(r=0;r<R;r++){
        for(c=R-r-1;c>0;c--)
            printf("    ");
        printf("%4d\n",m[r][R-r-1]);
    }    
    printf("\n"); 
    system("pause");
}    
