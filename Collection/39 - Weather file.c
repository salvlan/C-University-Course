#include <stdio.h>
#include <conio.h>
#define F "meteo"

struct meteo{
    int giorno;
    int mese;
    int anno;
    float tempmax;
    float tempmin;
    int umidita;
    int eliminato;
};

int menu();
void inserisci();
void visualizza();
void visu(struct meteo);
void ricerca();
void cancellagiorno();
void ripristinagiornoeliminato();
void cancellafile();


int main(){
    int s;
    do{
        s=menu();
        switch(s){
            case 1: inserisci(); break;
            case 2: visualizza(); break;
            case 3: ricerca(); break;
            case 4: cancellagiorno(); break;
            case 5: ripristinagiornoeliminato(); break;
            case 6: cancellafile(); break;
        }
    }while(s!=7);
}
int menu(){
    int x;
    printf("\n1=Inserisci");
    printf("\n2=Visualizza");
    printf("\n3=Ricerca");
    printf("\n4=Cancella giorno");
    printf("\n5=Ripristina giorno eliminato");
    printf("\n6=Cancella file");
    printf("\n7=Fine");
    printf("\nScegli:");
    scanf("%d",&x);
    return x;
}
void inserisci(){
    struct meteo a;
    int f;
    char ris; 
    FILE *fp;
    fp=fopen(F,"a");
    if(fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return;
    }
    do{
        do{
            f=1;
            do{printf("\nDammi il giorno:");
                fflush(stdin);
                scanf("%d",&a.giorno);
            }while (a.giorno<1||a.giorno>31);
            do{printf("\nDammi il mese:");
                fflush(stdin);
                scanf("%d",&a.mese);
            }while (a.mese<1||a.mese>12);
            do{printf("\nDammi l'anno:");
                fflush(stdin);
                scanf("%d",&a.anno);
            }while (a.anno<1000||a.anno>2100);
            if(a.mese==1||a.mese==3||a.mese==5||a.mese==7||a.mese==8||a.mese==10||a.mese==12)
                continue;
            if(a.giorno==31){
                f=0;
                continue;
            }
            if(a.mese!=2||a.giorno<29)
                continue;
            if(a.mese==2&&a.giorno==30){
                f=0;
                continue;
            }
            if(a.anno%4!=0){
                f=0;
                continue;
            }
            if(a.anno%100==0&&a.anno%400!=0)
                f=0;
        }while(!f);
        do{
            printf("\nDammi la temperatura massima:");
            fflush(stdin);
            scanf("%f",&a.tempmax);
        }while(a.tempmax<-50||a.tempmax>70);
        do{
            printf("\nDammi la temperatura minima:");
            fflush(stdin);
            scanf("%f",&a.tempmin);
        }while(a.tempmin<-50||a.tempmin>70);
        do{
            printf("\nDammi l'umidita':");
            fflush(stdin);
            scanf("%d",&a.umidita);
        }while(a.umidita<0||a.umidita>100);
        a.eliminato=0;
        fwrite(&a,sizeof(a),1,fp);
        printf("\nVuoi inserire un'altro giorno? [s]=si:");
        ris=getch();
    }while(ris=='s'||ris=='S');
    fclose(fp);
}
void visualizza(){
    struct meteo a;
    FILE *fp;
    fp=fopen(F,"r");
    if(fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return;
    }
    while(fread(&a,sizeof(a),1,fp)!=0)
        if(a.eliminato==0)
            visu(a);
    fclose(fp);
}
void visu (struct meteo a){
    printf("\nGiorno:%d",a.giorno);
    printf("\nMese:%d",a.mese);
    printf("\nAnno:%d",a.anno);
    printf("\nTemperatura massima:%5.2f",a.tempmax);
    printf("\nTemperatura minima:%5.2f",a.tempmin);
    printf("\nUmidita:%d",a.umidita);
    printf("\n");
}
void ricerca(){
    struct meteo a;
    int gg,mm,aa,f;
    FILE *fp;
    do{
        f=1;
        do{printf("\nDammi il giorno:");
            fflush(stdin);
            scanf("%d",&gg);
        }while (gg<1||gg>31);
        do{printf("\nDammi il mese:");
            fflush(stdin);
            scanf("%d",&mm);
        }while (mm<1||mm>12);
        do{printf("\nDammi l'anno:");
            fflush(stdin);
            scanf("%d",&aa);
        }while (aa<1000||aa>2100);
        if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
            continue;
        if(gg==31){
            f=0;
            continue;
        }
        if(mm!=2||gg<29)
            continue;
        if(mm==2&&gg==30){
            f=0;
            continue;
        }
        if(aa%4!=0){
            f=0;
            continue;
        }
        if(aa%100==0&&aa%400!=0)
            f=0;
    }while(!f);
    fp=fopen(F,"r");
    if(fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return;
    }
    while((fread(&a,sizeof(a),1,fp)!=0)&&(gg!=a.giorno||mm!=a.mese||aa!=a.anno||a.eliminato!=0));
    if(gg==a.giorno&&mm==a.mese&&aa==a.anno&&a.eliminato==0)
        visu(a);
    else
        printf("\nNon trovato!\n");
    fclose(fp);
}
void cancellagiorno(){
    struct meteo a;
    int gg,mm,aa,f;
    char ris;
    FILE *fp;
    do{
        f=1;
        do{printf("\nDammi il giorno:");
            fflush(stdin);
            scanf("%d",&gg);
        }while (gg<1||gg>31);
        do{printf("\nDammi il mese:");
            fflush(stdin);
            scanf("%d",&mm);
        }while (mm<1||mm>12);
        do{printf("\nDammi l'anno:");
            fflush(stdin);
            scanf("%d",&aa);
        }while (aa<1000||aa>2100);
        if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
            continue;
        if(gg==31){
            f=0;
            continue;
        }
        if(mm!=2||gg<29)
            continue;
        if(mm==2&&gg==30){
            f=0;
            continue;
        }
        if(aa%4!=0){
            f=0;
            continue;
        }
        if(aa%100==0&&aa%400!=0)
            f=0;
    }while(!f);
    fp=fopen(F,"r+");
    if(fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return;
    }
    while((fread(&a,sizeof(a),1,fp)!=0)&&(gg!=a.giorno||mm!=a.mese||aa!=a.anno||a.eliminato!=0));
    if(gg!=a.giorno&&mm!=a.mese&&aa!=a.anno&&a.eliminato!=1)
        printf("\nNon trovato!\n");
    else{
        visu(a);
        printf("\nSei sicuro di volerlo eliminare? [s]=si:");
        ris=getch();
        if(ris=='s'||ris=='S'){
            fseek(fp,-sizeof(a),1);
            a.eliminato=1;
            fwrite(&a,sizeof(a),1,fp);
            printf("\n\nGiorno eliminato!\n");
        }
    }
    fclose(fp);
}
void ripristinagiornoeliminato(){
    struct meteo a;
    int gg,mm,aa,f;
    char ris;
    FILE *fp;
    do{
        f=1;
        do{printf("\nDammi il giorno:");
            fflush(stdin);
            scanf("%d",&gg);
        }while (gg<1||gg>31);
        do{printf("\nDammi il mese:");
            fflush(stdin);
            scanf("%d",&mm);
        }while (mm<1||mm>12);
        do{printf("\nDammi l'anno:");
            fflush(stdin);
            scanf("%d",&aa);
        }while (aa<1000||aa>2100);
        if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
            continue;
        if(gg==31){
            f=0;
            continue;
        }
        if(mm!=2||gg<29)
            continue;
        if(mm==2&&gg==30){
            f=0;
            continue;
        }
        if(aa%4!=0){
            f=0;
            continue;
        }
        if(aa%100==0&&aa%400!=0)
            f=0;
    }while(!f);
    fp=fopen(F,"r+");
    if(fp==NULL){
        printf("\nErrore open file!\n");
        getch();
        return;
    }
    while((fread(&a,sizeof(a),1,fp)!=0)&&(gg!=a.giorno||mm!=a.mese||aa!=a.anno||a.eliminato!=1));
    if(gg!=a.giorno&&mm!=a.mese&&aa!=a.anno&&a.eliminato!=1)
        printf("\nNon trovato!\n");
    else{
        visu(a);
        printf("\nSei sicuro di volerlo ripristinare? [s]=si:");
        ris=getch();
        if(ris=='s'||ris=='S'){
            fseek(fp,-sizeof(a),1);
            a.eliminato=0;
            fwrite(&a,sizeof(a),1,fp);
            printf("\n\nGiorno ripristinato!\n");
        }
    }
    fclose(fp);
}
void cancellafile(){
    char ris; 
    FILE *fp;
    printf("\nSei sicuro di voler cancellare il file? [s]=si:");
    ris=getch();
    if(ris=='s'||ris=='S'){
        fp=fopen(F,"w");
        if(fp==NULL){
            printf("\nErrore open file!");
            getch();
            return;
        }
        fclose(fp);
        printf("\n\nFile cancellato!\n");
    }
}
  
        
        
    
    
    
    
     
          
