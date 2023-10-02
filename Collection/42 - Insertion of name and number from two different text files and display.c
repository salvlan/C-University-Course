#include <stdio.h>
#include <conio.h>

#define FB "agenda.dat"
#define FT1 "nomi.txt"
#define FT2 "numeri.txt"

struct agenda{
    char nome[20];
    char numerotelefono[20];
};

void inserisci();
void visualizza();
void visu(struct agenda);

int main(){
    inserisci();
    visualizza();
    getch();
}
void inserisci(){
    struct agenda a;
    FILE *fp,*fn,*ft;
    fp=fopen(FB,"w");
    if(fp==NULL){
        printf("\nErrore open file binario!");
        getch();
    }
    fn=fopen(FT1,"rt");
    if(fn==NULL){
        printf("\nFile testo nomi inesistente!");
        getch();
    }
    ft=fopen(FT2,"rt");
    if(ft==NULL){
        printf("\nFile testo numeri inesistente!");
        getch();
    }
    while(fscanf(fn,"%s",a.nome)>0&&fscanf(ft,"%s",a.numerotelefono)>0)
        fwrite(&a,sizeof(a),1,fp);
    fclose(fp);
    fclose(fn);
    fclose(ft);
}
void visualizza(){
    struct agenda a; 
    FILE *fp;
    fp=fopen(FB,"r");
    if(fp==NULL){
        printf("\nErrore open file binario!");
        getch();
    }
    while(fread(&a,sizeof(a),1,fp)!=0)
        visu(a);
    fclose(fp);
}
void visu(struct agenda a){
    printf("\n\nNome:%s",a.nome);
    printf("\nNumero:%s",a.numerotelefono);
}
    
