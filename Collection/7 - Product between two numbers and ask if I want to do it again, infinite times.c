#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n1,n2;
    char ris;
    
    do{printf("Dammi il primo numero: ");
       scanf("%d",&n1);
       
       printf("\nDammi il secondo numero: ");
       scanf("%d",&n2);
       
       printf("\n%d x %d = %d",n1,n2,n1*n2);
       fflush(stdin);
       
       printf("\n\nVuoi continuare?(S=si): ");
       scanf("%c",&ris);
       
    }while(ris=='s'||ris=='S');
    
    system ("pause");
    
}
        
