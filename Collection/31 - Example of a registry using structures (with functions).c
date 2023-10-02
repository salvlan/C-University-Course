# include <stdlib.h>
# include <stdio.h>
# include <string.h>

struct anagrafe{
    char codicefiscale [17];
    char nome [30];
    char cognome [30];
    int eta;
    char sesso;
};

struct anagrafe acquisisci (void);
void visualizza (struct anagrafe);

int main(){
    struct anagrafe a1;
    a1=acquisisci();
    visualizza(a1);
    printf("\n\n");
    system ("pause");
}
struct anagrafe acquisisci (void){
    struct anagrafe x;
    do{
        printf("\nDammi il nome: ");  
        fflush(stdin);
        gets(x.nome);
    }while(strlen(x.nome)<2);
    do{
        printf("\nDammi il cognome: ");  
        fflush(stdin);
        gets(x.cognome);
    }while(strlen(x.cognome)<2);
    do{
        printf("\nDammi il sesso: ");
        scanf("%c",&x.sesso);
    }while(x.sesso!='M'&&x.sesso!='m'&&x.sesso!='F'&&x.sesso!='f');
    do{
        printf("\nDammi l'eta': ");
        scanf("%d",&x.eta);
    }while(x.eta<0||x.eta>130);
     do{
        printf("\nDammi il codice fiscale: ");  
        fflush(stdin);
        gets(x.codicefiscale);
    }while(strlen(x.codicefiscale)!=16);
    return x;
}
void visualizza (struct anagrafe x){
    printf("\nIl codice fiscale del signor %s %s di sesso: %c, di anni: %d e %s.",x.cognome,x.nome,x.sesso,x.eta,x.codicefiscale);
}
   
    
    
    
