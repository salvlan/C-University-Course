#include <conio.h>
#include <stdio.h>
#include <string.h>
#define F "merce.dat"

struct merce{
    char codice[10];
    char descrizione[20];
    float prezzo;
    int quantita;
    int eliminato;
};

void visualizza();
void visu(struct merce);
void ripristinarecord();

int main(){
    printf("\nMerce registrata:\n");
    visualizza();
    ripristinarecord();
    printf("\nMerce registrata dopo in ripristino:\n");
    visualizza();
    getch();    
}
void visualizza(){
    struct merce a; 
    FILE *fp;
    fp=fopen(F,"r");
    if(fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return;
    }
    while(fread(&a,sizeof(a),1,fp)!=0)
        if(!a.eliminato)
            visu(a);
    fclose(fp);
}
void visu (struct merce a){
    printf("\nCodice:%s",a.codice);
    printf("\nDescrizione:%s",a.descrizione);
    printf("\nPrezzo:%5.2f",a.prezzo);
    printf("\nQuantita:%d",a.quantita);
    printf("\n");
}
void ripristinarecord(void){
    char c[10],ris;
    struct merce a;
    FILE *fp;
    fp=fopen(F,"r+");
    if(fp==NULL){
        printf("\nErrore open file!");
        getch();
        return;
    }
    do{
        do{
            printf("\nDammi il codice: ");
            fflush(stdin);
            gets(c);
        }while(strlen(c)<3);
        while(fread(&a,sizeof(a),1,fp)!=0&&(strcmp(a.codice,c)!=0||a.eliminato==0));
        if(strcmp(a.codice,c)!=0)
        printf("\nCodice %s non trovato fra quelli eliminati\n",c);
        else{
            fseek(fp,-sizeof(a),1);
            a.eliminato=0;
            fwrite(&a,sizeof(a),1,fp);
            visu(a);
            printf("\nMerce ripristinata!\n"); 
        }
        printf("\nVuoi ripristinare un altro record? (s=si)");
        ris=getch();
        fseek(fp,0,0);
    }while(ris=='s' || ris=='S');                 
    fclose(fp);        
}

            
