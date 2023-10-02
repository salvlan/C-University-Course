#include <conio.h>
#include <stdio.h>
#include <string.h>
#define F "agenda.dat"

struct anagrafe{
    char nome [30];
    char numero [30];
    int cancellato;
};

int menu (void);
void inserisci ();
struct anagrafe dammi ();
void visualizza ();
void visu (struct anagrafe);
void cercapernome();
void cercapernumero();
void cancellarecord();
void cancellafile();

int main(){
    int s;
    do{
        s=menu();
        switch(s){
            case 1: inserisci(); break;
            case 2: visualizza(); break;
            case 3: cercapernome(); break;
            case 4: cercapernumero(); break;
            case 5: cancellarecord(); break;
            case 6: cancellafile(); break;
        }
    }while(s!=7);
}
int menu(void){
    int s;
    printf("\n1=Inserisci");
    printf("\n2=Visualizza");
    printf("\n3=Cerca per nome");
    printf("\n4=Cerca per numero");
    printf("\n5=Cancella numero");
    printf("\n6=Cancella tutto");
    printf("\n7=Fine");
    printf("\nScegli:");
    scanf("%d",&s);
    return s;
}
void inserisci(){
    struct anagrafe a;
    FILE *fp;
    fp=fopen(F,"a");
    if(fp==NULL){
        printf("\nErrore open file!!!\n");
        getch();
        return;
    }
    a=dammi();
    fwrite(&a,sizeof(a),1,fp);
    fclose(fp);
}
struct anagrafe dammi (){
    struct anagrafe a;
    printf("\nDammi il nome:");
    fflush(stdin);
    gets(a.nome);
    printf("\nDammi il numero:");
    fflush(stdin);
    gets(a.numero);
    a.cancellato=0;
    return a;
}
void visualizza (){
    struct anagrafe a;
    FILE *fp;
    fp=fopen(F,"r");
    if(fp==NULL){
        printf("\nAgenda vuota!!!\n");
        getch();
        return;
    }
    while(fread(&a,sizeof(a),1,fp)>0)
        if(!a.cancellato)
            visu(a);
    fclose(fp);
}
void visu(struct anagrafe a){
    printf("\nNome:%s",a.nome);
    printf("\nNumero:%s",a.numero);
    printf("\n");
}
void cercapernome(){
    struct anagrafe a;
    char n[30];
    int trovato=0;
    FILE *fp;
    printf("\nDammi il nome:");
    fflush(stdin);
    gets(n);
    fp=fopen(F,"r");
    if(fp==NULL){
        printf("\nAgenda vuota!!!\n");
        getch();
        return;
    }
    while(fread(&a,sizeof(a),1,fp)!=0)
        if(strcmp(n,a.nome)==0&&!a.cancellato){
            visu(a);
            trovato=1;
        }
    if(!trovato)
        printf("\nNon trovato!!!\n");
    fclose(fp);
}
void cercapernumero(){
    struct anagrafe a;
    char n[30];
    long pos;
    FILE *fp;
    printf("\nDammi il numero:");
    fflush(stdin);
    gets(n);
    fp=fopen(F,"r");
    if(fp==NULL){
        printf("\nAgenda vuota!!!\n");
        getch();
        return;
    }
    while(fread(&a,sizeof(a),1,fp)!=0&&(strcmp(a.numero,n)!=0)||a.cancellato==1);
    if(strcmp(a.numero,n)!=0){
        printf("\nNon trovato!!!\n");
        getch();
        return;
    }
    pos=ftell(fp)-sizeof(a)-1;
    fseek(fp,pos,0);
    visu(a);
    fclose(fp);
}
void cancellarecord(){
    struct anagrafe a;
    char n[30];
    FILE *fp;
    printf("\nDammi il numero:");
    fflush(stdin);
    gets(n);
    fp=fopen(F,"r+");
    if(fp==NULL){
        printf("\nAgenda vuota!!!\n");
        getch();
        return;
    }
    while(fread(&a,sizeof(a),1,fp)!=0&&(strcmp(a.numero,n)!=0)||a.cancellato==1);
    if(strcmp(a.numero,n)!=0)
        printf("\nNon trovato!!!\n");
    else{
        fseek(fp,-sizeof(a),1);        
        a.cancellato=1;
        fwrite(&a,sizeof(a),1,fp);
        printf("\nNumero cancellato!");
    }
    fclose(fp);
}
void cancellafile(){
    FILE *fp;
    fp=fopen(F,"w");
    if(fp==NULL){
        printf("\nErrore open file!!!\n");
        getch();
        return;
    }
    printf("\nAgenda svuotata!!!\n");
    fclose(fp);
}

    
        
    
    

    

 
