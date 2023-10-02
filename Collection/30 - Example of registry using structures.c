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

int main(){
    struct anagrafe a1,a2;
    
    a1.eta=22;
    strcpy(a1.codicefiscale,"h58djsh3j6lf83et");
    strcpy(a1.nome,"Paolo");
    strcpy(a1.cognome,"Rossi");
    a1.sesso='m';
    printf("Il codice fiscale del signor %s %s di sesso: %c, di anni: %d e %s.",a1.cognome,a1.nome,a1.sesso,a1.eta,a1.codicefiscale);
    
    printf("\nDammi il nome: ");
    scanf("%s",a2.nome);
    printf("\nDammi il cognome: ");
    scanf("%s",a2.cognome);
    printf("\nDammi l'eta': ");
    scanf("%d",&a2.eta);
    printf("\nDammi il sesso: ");
    scanf("%s",&a2.sesso);
    printf("\nDammi il codice fiscale: ");
    scanf("%s",a2.codicefiscale);
    printf("\nIl codice fiscale del signor %s %s di sesso: %c, di anni: %d e %s.",a2.cognome,a2.nome,a2.sesso,a2.eta,a2.codicefiscale);
    printf("\n\n");
    system ("pause"); 
}

