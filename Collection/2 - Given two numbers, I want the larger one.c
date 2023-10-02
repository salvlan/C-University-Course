#include <stdlib.h>
#include <stdio.h>

int main (){
    
    int n1, n2;
    
    printf ("Dammi il primo numero ");
    scanf ("%d",&n1);
    
    printf ("\nDammi il secondo numero ");
    scanf ("%d",&n2);
    
    if (n1>n2)
        printf ("\nIl maggiore e %d\n\n",n1);
    else
        printf ("\nIl maggiore e %d\n\n",n2);
        
    system ("PAUSE");

}    
    
