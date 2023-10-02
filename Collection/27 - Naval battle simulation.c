# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define R 10
# define C 10
# define N 5

void zero (int (*)[C]);
void navicm (int(*)[C]);
void naviio (int(*)[C]);
void visualizza (int(*)[C]);
int giocoio (int,int(*)[C]);
int giocacm (int,int(*)[C]);

int main(){
    int io[R][C],cm[R][C],nio=N,ncm=N;
    srand (time(NULL));
    zero(io);
    zero(cm);
    navicm(cm);
    naviio(io);
    while(nio>0&&ncm>0){
        printf("\nTu:\n");
        visualizza(io);
        printf("\nSono rimaste %d navi nemiche",ncm);
        ncm=giocoio(ncm,cm);
        if(ncm!=0)
            nio=giocacm (nio,io);
    }
    if(ncm==0)
        printf("\n\nHai vinto!!!!!!\n\n");
    else
        printf("\n\nHai perso!!!!!!\n\n");
    printf("Tu:\n");
    visualizza(io);
    printf("\n\nComputer:\n");
    visualizza(cm);
    system("pause");     
}
void zero (int(*w)[C]){
    int r,c;
    for(r=0;r<R;r++)
        for(c=0;c<C;c++)
            w[r][c]=0;
}
void navicm (int(*w)[C]){
    int i,c,r;
    for(i=1;i<=N;i++){
        do{
            r=rand()%R;
            c=rand()%C;
        }while(w[r][c]==1);
        w[r][c]=1;
    }
}
void naviio (int(*w)[C]){
    int i,c,r;
    for (i=1;i<=N;i++){
        do{
            do{ 
                printf("\nDammi la righa compresa tra 0 & 9 dove posizionare la nave:");
                scanf("%d",&r);
            }while(r<0||r>R-1);
            do{
                printf("\nDammi la colonna compresa tra 0 & 9 dove posizionare la nave:");
                scanf("%d",&c);
            }while(c<0||c>R-1);
        }while(w[r][c]==1);
        w[r][c]=1;
    }
}
void visualizza (int(*w)[C]){
    int r,c;    
    for(r=0;r<R;r++){
        for(c=0;c<C;c++)
            printf("%4d",w[r][c]);
        printf("\n");
    }
}
int giocoio (int x,int(*w)[C]){
    int c,r;
    do{
        do{ 
            printf("\nDammi la righa compresa tra 0 & 9 dove lanciare la bomba:");
            scanf("%d",&r);
        }while(r<0||r>R-1);
        do{
            printf("\nDammi la colonna compresa tra 0 & 9 dove lanciare la bomba:");
            scanf("%d",&c);
        }while(c<0||c>R-1);
    }while(w[r][c]==2||w[r][c]==3);    
    if(w[r][c]==1){
        printf("\nColpito!!!\n");
        x--;
        w[r][c]=2;
    }
    else
        printf("\nAcqua!!!\n");
        w[r][c]=3;
    return x;
}
int giocacm (int x,int(*w)[C]){
    int r,c;
    do{
        r=rand()%R;
        c=rand()%C;
    }while(w[r][c]==2||w[r][c]==3);
    if(w[r][c]==1){
        x--;
        w[r][c]=2;
    }
    else
        w[r][c]=3;
    return x;
}    

             
     
