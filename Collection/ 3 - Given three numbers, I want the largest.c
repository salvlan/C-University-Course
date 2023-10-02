#include <stdlib.h>
#include <stdio.h>

int main(){
    
    int n1, n2, n3;
    
    printf ("Dammi il primo numero ");
    scanf ("%d",&n1);
    
    printf ("\nDammi il secondo numero ");
    scanf ("%d",&n2);
    
    printf ("\nDammi il terzo numero ");
    scanf ("%d",&n3);
    
    if(n1>n2&&n1>n3)
        printf ("\nIl maggiore e %d\n\n",n1);
    else 
        if (n1>n3)
            printf ("\nIl maggiore e %d\n\n",n2);
        else
            printf ("\nIl maggiore e %d\n\n",n3);
    
    system ("PAUSE");
}  
         
