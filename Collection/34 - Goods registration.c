#include <conio.h>
#include <stdio.h>
#include <string.h>
#define F "merce.dat"
#define FT "record.txt"

struct merce{
    char codicemerce [10];
    char descrizione [20];
    float prezzo;
    int quantita;
    int eliminato;
};

int inserisci();
void visualizza();
void visu(struct merce);
void scrivifiletesto(int);

int main(){
    int n;
    n=inserisci();
    visualizza();
    scrivifiletesto(n);
    getch();
}
int inserisci(){
    struct merce a;
    int x=0;
    char ris;
    FILE *fp;
    fp=fopen (F,"a");
    if (fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return 0;
    }
    do{
        do{
            printf("\nDammi il codice:");
            fflush(stdin);
            gets(a.codicemerce);
        }while(strlen(a.codicemerce)<3);
        do{
            printf("\nDammi la descrizione:");
            fflush(stdin);
            gets(a.descrizione);
        }while(strlen(a.descrizione)<3);
        do{
            printf("\nDammi il prezzo:");
            fflush(stdin);
            scanf("%f",&a.prezzo);
        }while(a.prezzo<=0);
        do{
            printf("\nDammi la quantita:");
            fflush(stdin);
            scanf("%d",&a.quantita);
        }while(a.quantita<0);
        a.eliminato=0;
        fwrite(&a,sizeof(a),1,fp);
        x++;
        printf("\nVuoi inserire altra merce? [s]=si:");
        ris=getch();
    }while(ris=='s'||ris=='S');
    fclose(fp);
    return x;
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
void visu(struct merce a){
    printf("\nCodice:%s",a.codicemerce);
    printf("\nDescrizione:%s",a.descrizione);
    printf("\nPrezzo:%5.2f",a.prezzo);
    printf("\nQuantita:%d",a.quantita);
    printf("\n");
}
void scrivifiletesto(int x){
    FILE *fp;
    fp=fopen(FT,"wt");
    if(fp==NULL){
        printf("\nErrore open file txt!\n");
        getch();
        return;
    }
    fprintf(fp,"%d%",x);
    fclose(fp);
}
    
         
        
            
    
           
