# include <stdlib.h>
# include <stdio.h>

int numero (void);
void tabellina (int);

int main(){
    int a;
    
        a=numero();
        tabellina (a);
        
        system ("pause");
}
int numero (void){
    int y;
    
    do{
        printf("Dammi il numero compreso tra 1 e 10: ");
        scanf("%d",&y);
    }while (y<1||y>10);
    
    return y;
}
void tabellina (int x){
     int i;
     
     for(i=1;i<=10;i++)
         printf("\t%d\n\n",x*i);
}
     
