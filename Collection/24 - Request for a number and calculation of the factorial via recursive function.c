# include <stdlib.h>
# include <stdio.h>

int dammi (void);
long int fattoriale (int);

int main (){
    int n;
    long int f;
    
    n=dammi ();
    f=fattoriale (n);
    printf ("\nIl fattoriale del numero %d e': %d",n,f);
    printf("\n\n");  
    system ("pause");
}
int dammi (void){
    int n;
    
    printf("\nDammi il numero: ");
    scanf("%d",&n);
    return n;
}
long int fattoriale (int x){
    
    if(x==0)
        return 1;
    else
        return x*fattoriale (x-1);
}         
