# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int main(){
    char s[100],s1[100];
    int n;
    printf("Inserisci la frase di massimo 100 caratteri: ");
    fflush(stdin);
    gets(s);
    printf("\nPrima stringa: %s\n\nSeconda stringa: %s",s,s1);
    printf("\n\nCopia di 4 caratteri della prima stringa nella seconda tramite il comando strncpy(s1,s,4):\n\n");
    strncpy(s1,s,4);
    printf("Prima stringa: %s\n\nSeconda stringa: %s",s,s1);
    printf("\n\nCopia del contenuto della prima stringa nella seconda stringa tramite il comando strcpy(s1,s):\n\n");
    strcpy(s1,s);
    printf("Prima stringa: %s\n\nSeconda stringa: %s",s,s1);
    printf("\n\nCopia del contenuto della prima stringa nella seconda senza cancellarne il contenuto tramite il comando strcat(s1,s):\n\n");
    strcat(s1,s);
    printf("Prima stringa: %s\n\nSeconda stringa: %s",s,s1);
    printf("\n\nCopia di 4 caratteri della prima stringa nella seconda senza cancellarne il contenuto tramite il comando strncat(s1,s,4):\n\n");
    strncat(s1,s,4);
    printf("Prima stringa: %s\n\nSeconda stringa: %s",s,s1);
    n=strlen(s1);
    printf("\n\nNumero di caratteri della seconda stringa tramite il comando n=strlen(s1): %d ",n);
    n=strcmp(s,s1);
    printf("\n\nVerifica se le stringhe hanno lo stesso contenuto tramite il comando n=strcmp(s,s1), se hanno lo stesso contenuto restituira zero, senno, se in ordine alfabetico s viene prima di s1 restituira un numero minore di zero, viceversa maggiore di zero: %d",n);
    printf("\n\n");
    system ("pause");
}
