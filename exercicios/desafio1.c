#include <stdio.h>

typedef struct {

char nome[40];
double byte_armazenado;

}usuarios;

void soma_espaco(int n, usuarios *u){

    int i;
    double total_disco = 0,media_disco;
    double conversao[n],media[n];

    //for utilizado para armazenar os valores de conversao por usuario e calcular o valor total do disco.
    for(i = 0; i < n; i++){
        conversao[i] = 0;
        conversao[i] = (u[i].byte_armazenado / 1024) / 1024;
        total_disco += conversao[i];
    }

    //media utilizada do disco até o momento
    media_disco = 0;
    media_disco = total_disco / n;

    for(i = 0; i < n; i++){
        media[i] = 0;
        media[i] = (conversao[i] * 100.0) / total_disco;
    }

    printf("Nr.      Usuario     Espaco Utilizado     %% de uso\n");
    printf("--------------------------------------------------------\n");

    for(i = 0; i < n; i++){
        printf("%d    %s        %.2lfMB       %.2lf\n",i+1,u[i].nome,conversao[i],media[i]);
    }
    printf("Espaco total ocupado:%.2lf MB\n",total_disco);
    printf("Espaco medio ocupado:%.2lf MB\n",media_disco);
}

int main() {

int n,i;

printf("Informe a quantidade de usuarios que serao digitados:");
scanf("%d",&n);

usuarios u[n];

for(i = 0; i < n;i++){
    printf("Nome do usuario[%d]:",i+1);
    getchar();
    scanf("%[^\n]",u[i].nome);
    printf("Bytes utilizados:");
    scanf("%lf",&u[i].byte_armazenado);
    printf("\n");
}
soma_espaco(n,u);

    return 0;
}