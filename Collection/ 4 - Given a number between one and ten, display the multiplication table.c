#include <stdlib.h>
#include <stdio.h>

int main (){
    
    int n1, i;
    
    do{
        printf ("Dammi un numero compreso tra 1 e 10: ");
        scanf ("%d",&n1);
    } while (n1<1||n1>10);
    
    for (i=1;i<=10;i++)
        printf ("\t%d\n\n",n1*i);

    system ("PAUSE");
}
