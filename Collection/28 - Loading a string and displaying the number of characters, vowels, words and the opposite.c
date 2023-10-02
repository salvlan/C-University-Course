# include <stdlib.h>
# include <stdio.h>

int contacaratteri (char*);
int contavocali (char*);
int contaparole (char*);
void contrario (char*);

int main (){
    char s[1000];
    int n;
    
    printf("Digita la frase di massimo 1000 caratteri: ");
    fflush(stdin);
    gets(s);
    n=contacaratteri (s);
    printf("\n\nIl numero di caratteri e: %d",n);
    n=contavocali(s);
    printf("\n\nIl numero di vocali e:%d",n);
    n=contaparole(s);
    printf("\n\nIl numero di parole e:%d",n);
    contrario(s);
    printf("\n\n");
    system("pause");
}
int contacaratteri (char*s){
    int i=0;
    while(*(s+i)!='\0')
        i++;
    return i;
}
int contavocali (char*s){
    int i=0,c=0;
    while(*(s+i)!='\0'){
        if(*(s+i)=='A'||*(s+i)=='a'||*(s+i)=='E'||*(s+i)=='e'||*(s+i)=='I'||*(s+i)=='i'||*(s+i)=='O'||*(s+i)=='o'||*(s+i)=='U'||*(s+i)=='u')
            c++;
        i++;
    }
    return c;
}
int contaparole (char*s){
    int i=0,c=1;
    while(*(s+i)!='\0'){
        if(*(s+i)==' ')
            c++;
        i++;
    }
    return c;
}
void contrario (char*s){
    int i,n;
    n=contacaratteri(s);
    printf("\n\nLa frase al contrario e: ");
    for(i=n-1;i>=0;i--)
        printf("%c",*(s+i));
}

