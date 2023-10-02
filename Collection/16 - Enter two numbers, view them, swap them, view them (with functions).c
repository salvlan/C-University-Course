# include <stdio.h>
# include <stdlib.h>

void visualizza(int,int);
void scambia(int*,int*);

int main(){
    int a,b;
    
    printf("Dammi il primo numero: ");
    scanf("%d",&a);
    
    printf("\nDammi il secondo numero: ");
    scanf("%d",&b);
    
    visualizza(a,b);
    scambia(&a,&b);
    visualizza(a,b);
    
    printf("\n\n");
    
    system ("pause");
}
void visualizza(int x,int y){
     
     printf("\na=%d",x);
     printf("\nb=%d",y);
}
void scambia(int*p,int*q){
     int app;
     
     app=*p;
     *p=*q;
     *q=app;
}

