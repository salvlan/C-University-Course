#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int g,m,a,f;
    
    do{f=1;
        do{printf ("\nDammi il giorno: ");
           scanf ("%d",&g);
        }while (g<1||g>31);
        
        do{printf ("\nDammi il mese: ");
           scanf ("%d",&m);
        }while (m<1||m>12);
        
        do{printf ("\nDammi l'anno: ");
           scanf ("%d",&a);
        }while (a<1000||a>2100);
        
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
            continue;
        
        if(g==31){
            f=0;
            continue;
        }
        
        if(m!=2||g<29)
            continue;
        
        if(m==2&&g==30){
            f=0;
            continue;
        }
            
        if(a%4!=0){
            f=0;
            continue;
        }
        
        if(a%100==0&&a%400!=0)
            f=0;
            
    }while(!f);
    
    system ("pause");
    
}


          
