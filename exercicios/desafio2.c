#include<stdio.h>
#include<stdlib.h> //necessária para o comando abs() e exit(1)
#include<string.h> //necessária para o comando strcmp() 

typedef struct{

char placa[8];
int hora;
int min;

}carro;

void entrada(int *vagas_disponiveis,int *tot_carros,carro *c){

if(*vagas_disponiveis > 0 && *vagas_disponiveis < 11){

    printf("Informe a placa:");
    getchar();
    scanf("%[^\n]",c[*tot_carros].placa);

    printf("Informe o horario de entrada:");
    scanf("%d:%d",&c[*tot_carros].hora,&c[*tot_carros].min);

    (*vagas_disponiveis)--; //Cada registo de um novo veículo irá tirar 1 vaga do estacionamento
    (*tot_carros)++; //aumenta em 1 a posicao.

    printf("Veiculo cadastrado com sucesso!\n");
    printf("Vagas disponiveis: %d\n",*vagas_disponiveis);
    }
    else{ //Caso o estacionamento esteja lotado
        printf("Estacionamento lotado!\n");
    }
    
}
//---------------------------------------------------------------------------------//

void saida(int *vagas_disponiveis,int *tot_carros,carro *c){

char placa_vei[8];
int hora,minuto,i,existe =-1,qtd_15 = 0,total_tempo = 0,x;
float pagamento;

printf("Informe a placa do veiculo:");
getchar();
scanf("%[^\n]",placa_vei);

for(i = 0; i < *tot_carros; i++){

    if(strcmp(c[i].placa,placa_vei)== 0){ //irá comparar se as placas são iguais
        existe = i;
        break;
    }
}    

if(existe != -1){
    printf("Informe o horario de saida:");
    scanf("%d:%d",&hora,&minuto); //Horario da saída do veiculo

    int tempo_entrada = 0, tempo_saida = 0;

    tempo_entrada = (c[i].hora * 60) + c[i].min; //calcula a hora da entrada em minutos
    tempo_saida = (hora * 60) + minuto; //calcula a hora da saida em minutos

    total_tempo = abs(tempo_entrada - tempo_saida);
    x = total_tempo;

    if(x <= 60.00){ //valor fixo até 1 hora no estacionamento
        pagamento = 5.00;
    }
    else {
        x -= 60.00; //Subtração da 1 hora
        qtd_15 = x / 15; //variavel qtd_15 apenas para armazenar de forma precisa a quantidade de 15min extras
        pagamento = 5 + (2.00 * qtd_15);
    }

    (*vagas_disponiveis) ++;
    (*tot_carros)--;

    printf("----------------------\n");
    printf("Recibo\n");
    printf("----------------------\n");
    printf("Placa: %s\n",placa_vei);
    printf("Entrada: %d:%d\n",c[i].hora,c[i].min);
    printf("Saida: %d:%d\n",hora,minuto);
    printf("Tempo total (em minutos): %d\n",total_tempo);
    printf("Total a pagar: R$%.2f\n",pagamento);
    printf("----------------------\n");
    printf("Vagas disponiveis: %d\n",*vagas_disponiveis);
}  
}
//---------------------------------------------------------------------------------//
void listar(int *vagas_disponiveis,int *tot_carros,carro *c){

int i;

printf("Nr.vaga          Placa          Entrada\n");
printf("--------------------------------------------\n");

for(i = 0; i < *tot_carros; i++){

    printf("%d              %s               %d:%d\n",i+1,c[i].placa,c[i].hora,c[i].min);
}    

printf("--------------------------------------------\n");
printf("Vagas disponiveis: %d\n",*vagas_disponiveis);
}
//---------------------------------------------------------------------------------//

int main() {

int escolha,vagas_disponiveis = 10,tot_carros = 0;

carro c[10];

do{

printf("\n# Estacionamento do Chaves #\n"); //Apresentando ao usuario as opcoes de escolha
printf("[1] Entrada de veiculo\n");
printf("[2] Saida de veiculo\n");
printf("[3] Listagem de veiculos\n");
printf("[4] Sair\n\n");
scanf("%d",&escolha);

while(escolha < 1 || escolha > 4){ //Condição caso o usuário informe um valor diferente das opções
    printf("Valor invalido, informe novamente:");
    scanf("%d",&escolha);
};

switch(escolha){ //Definição do que o programa irá executar conforme escolha do usuário

case 1:
    entrada(&vagas_disponiveis,&tot_carros,c);break;

case 2:
    saida(&vagas_disponiveis,&tot_carros,c);break;

case 3:
    listar(&vagas_disponiveis,&tot_carros,c);break;

case 4:
    exit(1);break;
}

}while(escolha != 4);

    return 0;
}