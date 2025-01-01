#include<stdio.h>
#include<stdlib.h>

typedef struct{

    char modelo[40];
    int ano_fabricacao;
    float valor_veiculo;
    char placa[8];
    int renavam;
    char combustivel[12];

}carros;


float ipva(int n,carros *c){

    int i,ano = 0;
    float ipva = 0;

    for(i = 0; i < n; i++){

        ano = 2024 - c[i].ano_fabricacao;

        if(strcmp(c[i].combustivel,"gas")== 0 && ano < 20){

            ipva = 0.01;

        }
        else if(strcmp(c[i].combustivel,"flex")== 0 && ano < 20){

            ipva = 0.02;

        }

        else if(strcmp(c[i].combustivel,"gasolina")== 0 && ano < 20){

            ipva = 0.04;

        }
        else if(c[i].ano_fabricacao > 20){

            ipva = 0;
        }

        ipva = ipva * c[i].valor_veiculo;
    }

return ipva;
}

int main() {

int n,i;


printf("Informe o numero de veiculos que serao registrados:");
scanf("%d",&n);

carros c[n];
float calculo_ipva[n];

for(i = 0; i < n; i++){

    printf("Informe o modelo do veiculo:");
    fflush(stdin);
    scanf("%[^\n]",c[i].modelo);

    printf("Informe o ano de fabricacao:");
    scanf("%d",&c[i].ano_fabricacao);

    printf("Informe o valor do veiculo:");
    scanf("%f",&c[i].valor_veiculo);

    printf("Informe a placa:");
    fflush(stdin);
    scanf("%[^\n]",c[i].placa);

    printf("Informe o renavan do veiculo:");
    scanf("%d",&c[i].renavam);

    printf("Informe o tipo do combustivel:");
     fflush(stdin);
    scanf("%[^\n]",c[i].combustivel);

    printf("\n");

    calculo_ipva[i] = ipva(n,c);
}

for(i = 0; i < n; i++){

    printf("Modelo:%s\n",c[i].modelo);
    printf("Placa:%s\n",c[i].placa);
    printf("Renavam:%d\n",c[i].renavam);
    printf("IPVA:R$%.2f\n",calculo_ipva[i]);
    printf("\n");
}

    return 0;
}