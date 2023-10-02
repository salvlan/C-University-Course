# include <stdio.h>
# include <stdlib.h>

int somma(int,int);

int main (){
    int a,b,s;
    
    printf("Dammi il primo numero: ");
    scanf("%d",&a);
    
    printf("\nDammi il secondo numero: ");
    scanf("%d",&b);
    
    s=somma(a,b);
    printf("\nLa somma e:%d\n\n",s);
    
    system ("pause");
}
int somma(int x,int y){
    int z;
    
    z=x+y;
    
    return z;
}
            
