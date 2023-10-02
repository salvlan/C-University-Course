#include <conio.h>
#include <stdio.h>
#include <string.h>
#define FB "merce.dat"
#define FT "codici da eliminare.txt"

struct merce{
    char codice[10];
    char descrizione[20];
    float prezzo;
    int quantita;
    int eliminato;
};

void visualizza ();
void visu (struct merce);
void elimina();
void eliminarecord(char*);

int main(){
    printf("\nMerce registrata:\n");
    visualizza();
    elimina();
    printf("\nMerce registrata dopo l'eliminazione:\n");
    visualizza();
    getch();
}
void visualizza(){
    struct merce a;
    FILE *fp;
    fp=fopen(FB,"r");
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
void elimina(){
    char x[10];
    FILE *fp;
    fp=fopen(FT,"rt");
    if(fp==NULL){
        printf("\nErrore open file txt");
        getch();
        return;
    }
    while(fscanf(fp,"%s",x)>0)
        eliminarecord(x);
    fclose(fp);
}
void eliminarecord (char*x){
    struct merce a;
    FILE *fp;
    fp=fopen(FB,"r+");
    if(fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return;
    }
    while(fread(&a,sizeof(a),1,fp)!=0&&strcmp(x,a.codice)!=0||a.eliminato==1);
    if(strcmp(x,a.codice)!=0)
        printf("\nCodice %s non trovato!",x);
    else{
        fseek(fp,-sizeof(a),1);        
        a.eliminato=1;
        fwrite(&a,sizeof(a),1,fp);
        printf("\nCodice %s eliminato!",x);
    }
    fclose(fp);
}
        
    

     
    
