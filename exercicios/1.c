#include<stdio.h>

typedef struct{

    char nome_completo[60];
    int idade;
    float salario;
    int anos_exp;

}funcionarios;

void calc_media(int n,funcionarios *f){

    float media = 0;
    int i;

    for(i = 0; i < n; i++){

        media += f[i].idade;
    }

    media = media / n;
    printf("Media de idade:%.2f\n",media);

}

void calc_exp(int n,funcionarios *f){

    float maior = 0;
    int indice = 0,i;

    for(i = 0; i < n; i++){

        if(f[i].anos_exp > maior){

            maior = f[i].anos_exp;
            indice = i;
            
            }  
        }
        printf("Funcionario com mais experiencia:%s\n",f[indice].nome_completo);
    }

int main() {

    int n,i;

    printf("informe o numero de funcionarios:");
    scanf("%d",&n);

    funcionarios f[n];

    for(i = 0; i < n; i++){

        printf("Informe o nome completo do funcionario:");
        fflush(stdin);
        scanf("%[^\n]",&f[i].nome_completo);
        
        printf("Informe a sua idade:");
        scanf("%d",&f[i].idade);

        printf("Informe seu salario:");
        scanf("%f",&f[i].salario);

        printf("Informe quantos anos tem de experiencia:");
        scanf("%d",&f[i].anos_exp);
    }

    calc_media(n,f);
    calc_exp(n,f);

    return 0;
}