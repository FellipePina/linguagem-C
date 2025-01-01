#include<stdio.h>
#include<string.h>

typedef struct{

    char nome_cidade[40];
    double renda;
    float idh;
    double populacao;

}cidades;

void renda_per(int n, cidades *c){

    double media = 0;
    int i;

    for(i = 0; i < n; i++){

        media += c[i].renda;

    }

    media = media / n;
    printf("Media de renda per capta:%.lf\n",media);
}

void maior_pop(int n, cidades *c){

    double maior = 0;
    int i,indice = 0;

    for(i = 0; i < n; i++){

        if(c[i].populacao > maior){

            maior = c[i].populacao;
            indice = i;
        }
    }

    printf("Cidade com maior populacao:%s\n",c[indice].nome_cidade);
}

void info(int n, cidades *c,char *cidade){

    int i;

    for(i = 0; i < n; i++){

        if(strcmp(cidade,c[i].nome_cidade) == 0){
            printf("Renda per capita:%.lf\n",c[i].renda);
            printf("IDH:%.2f\n",c[i].idh);
            printf("Populacao:%.2lf\n",c[i].populacao);
        }
    }
}

int main() {

int n,i;
char cidade[40];

printf("Informe o numero de cidades:");
scanf("%d",&n);

cidades c[n];

for(i = 0; i < n; i++){

    printf("Informe o nome da cidade(primeira letra Maiuscula)");
    getchar();
    scanf("%[^\n]",c[i].nome_cidade);

    printf("Iforme a renda per capita:");
    scanf("%lf",&c[i].renda);

    printf("Iforme o IDH:");
    scanf("%f",&c[i].idh);

    printf("Iforme a populacao:");
    scanf("%lf",&c[i].populacao);
}

renda_per(n,c);
maior_pop(n,c);

printf("Informe uma cidade para exibir as informacoes(exatamente como informado):");
getchar();
scanf("%[^\n]",cidade);

info(n,c,cidade);

    return 0;
}