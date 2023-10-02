#include <stdio.h>
#include <string.h>
#include <conio.h>
#define F "alunni.dat"
#define FT1 "alunni da eliminare.txt"
#define FT2 "alunni da ripristinare.txt" 

struct alunno{
    char matricola[15];
    char nome[15];
    char cognome[15];
    int eliminato;
};

int menu();
void inserisci();
void visualizza();
void visu(struct alunno);
void ricerca();
long confronto();
void cancellarecord();
void ripristinarecord();
void cancelladafiletesto();
void ripristinadafiletesto();
void cancellafile();

int main(){
    int s;
    do{
        s=menu();
        switch(s){
            case 1: inserisci(); break;
            case 2: visualizza(); break;
            case 3: ricerca(); break;
            case 4: cancellarecord(); break;
            case 5: ripristinarecord(); break;
            case 6: cancelladafiletesto(); break;
            case 7: ripristinadafiletesto(); break;
            case 8: cancellafile(); break;
        }
    }while(s!=9);
}
int menu(){
    int s;
    printf("\n1=Inserisci");
    printf("\n2=Visualizza");
    printf("\n3=Ricerca");
    printf("\n4=Elimina alunno");
    printf("\n5=Ripristina alunno eliminato");
    printf("\n6=Elimina alunno da file testo");
    printf("\n7=Ripristina alunno da file testo");
    printf("\n8=Cancella file");
    printf("\n9=Fine");
    printf("\nScegli:");
    scanf("%d",&s);
    return s;
}
void inserisci (){
    struct alunno a;
    int ris;
    FILE *fp;
    fp=fopen(F,"a");
    if(fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return;
    }
    do{
        do{
            printf("\nDammi la matricola:");
            fflush(stdin);
            gets(a.matricola);
        }while(strlen(a.matricola)<3);
        do{
            printf("\nDammi il nome:");
            fflush(stdin);
            gets(a.nome);
        }while(strlen(a.nome)<3);
        do{
            printf("\nDammi il cognome:");
            fflush(stdin);
            gets(a.cognome);
        }while(strlen(a.cognome)<3);
        a.eliminato=0;
        fwrite(&a,sizeof(a),1,fp);
        printf("\nVuoi inserire un'altro alunno? [s]=si:");
        ris=getch();
    }while(ris=='s'||ris=='S');
    fclose(fp);
}
void visualizza(){
    struct alunno a;
    FILE *fp;
    fp=fopen(F,"r");
    if(fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return;
    }
    while(fread(&a,sizeof(a),1,fp)>0)
        if(!a.eliminato)
            visu(a);
    fclose(fp);
}
void visu (struct alunno a){
     printf("\nMatricola:%s",a.matricola);
     printf("\nNome:%s",a.nome);
     printf("\nCognome:%s",a.cognome);
     printf("\n");
}
void ricerca(){
    struct alunno a;
    long pos;
    FILE *fp;
    pos=confronto();
    if(pos==-1)
        printf("\nAlunno non trovato!\n");
    else{
        fp=fopen(F,"r");
        if(fp==NULL){
            printf("\nErrore open file!\n");
            getch();
            return;
        }
        fseek(fp,pos,0);
        fread(&a,sizeof(a),1,fp);
        visu(a);
        fclose(fp); 
    }
}
long confronto(){
    struct alunno a;
    char m[15];
    long pos;
    FILE *fp;
    fp=fopen(F,"r");
    if(fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return -1;
    }
    do{
        printf("\nDammi la matricola:");
        fflush(stdin);
        gets(m);
    }while(strlen(a.matricola)<3);
    while(fread(&a,sizeof(a),1,fp)!=0&&strcmp(m,a.matricola)!=0||a.eliminato!=0);
    if(strcmp(m,a.matricola)==0)
        pos=ftell(fp)-sizeof(a)-1;
    else
        pos=-1;
    fclose(fp);
    return pos;
}
void cancellarecord(){
    struct alunno a;
    FILE *fp;
    long pos;
    char ris;
    pos=confronto();
    if(pos==-1)
        printf("\nAlunno non trovato!\n");
    else{
        fp=fopen(F,"a");
        if(fp==NULL){
            printf("\nErrore open file!\n");
            getch();
            return;
        }
        fseek(fp,pos,0);
        fread(&a,sizeof(a),1,fp);
        visu(a);
        printf("\nSei sicuro di volerlo eliminare? [s]=si:");
        ris=getch();
        if(ris=='s'||ris=='S'){
            fseek(fp,pos,0);
            a.eliminato=1;
            fwrite(&a,sizeof(a),1,fp);
            printf("\nAlunno eliminato!\n");
        }
        fclose(fp);
    }
}
void ripristinarecord(){
    struct alunno a;
    char m[15],ris;
    FILE *fp;
    fp=fopen(F,"r+");
    if(fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return;
    }
    do{
        printf("\nDammi la matricola:");
        fflush(stdin);
        gets(m);
    }while(strlen(a.matricola)<3);
    while(fread(&a,sizeof(a),1,fp)!=0&&strcmp(m,a.matricola)!=0||a.eliminato!=1);
    if(strcmp(m,a.matricola)==0){
        fseek(fp,-sizeof(a),1);
        fread(&a,sizeof(a),1,fp);
        visu(a);
        printf("\nSei sicuro di volerlo ripristinare? [s]=si:");
        ris=getch();
        if(ris=='s'||ris=='S'){
            a.eliminato=0;
            fwrite(&a,sizeof(a),1,fp);
            printf("\nAlunno ripristinato!\n");
        }
    }
    fclose(fp);
}
void cancelladafiletesto(){
} 
void ripristinadafiletesto(){
}
void cancellafile(){
}   
