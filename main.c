#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "head.h"

#include "funcoes_auxiliares.h"
#include "tabela.h"
#include "database.h"

void menu(glossary*** dicionario){
    //menu
    char input[10];
    int op=0,e=0;
    do{
        limparTela();
        printf("==========BEM VINDO==========\nEscolha o numero referente a opcao desejada:\n1-Abrir dicionario\n2-traduzir frases\n3-listar traducoes cadastradas\n4-sair\n");
       if(e==1)printf("Atencao escolha somente o numero referente a opcao!!\n");
       scanf("%9s", input);

        if (isdigit(input[0]) && input[1] == '\0') {
            op = input[0] - '0';
        } else {
            op = 0;
        }

        e=1;


        switch (op) {
        case 1:
            break;
        case 2:
            printf("Traduzindo frases...\n");
            // Chame a função correspondente aqui
            break;
        case 3:
            printf("Listando traducoes cadastradas...\n");
            // Chame a função correspondente aqui
            break;
        case 4:
            delete_dictionary(*dicionario,tamanho_padrao);
            exit(1);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
    }while(op!=4);
}

int main(){
    glossary** dicionario = new_dictionary(tamanho_padrao);

    load_database(dicionario,tamanho_padrao,1);
    open_dictionary(dicionario);
    return 0;
}


void open_dictionary(glossary** dicionario) {
    int tipo = -1;
    int op = 0;
    char buffer[64];

    // Selecao do tipo de traducao
    do {
        limparTela();
        printf("Qual tipo de traducao voce deseja:\n1 - Portugues para ingles\n2 - Ingles para portugues\n");
        scanf("%d", &tipo) != 1 || (tipo != 1 && tipo != 2)) {
    } while (tipo != 1 && tipo != 2);

 
    do {
        limparTela();
        printf("Insira a palavra: ");
        getchar();
        fgets(buffer, sizeof(buffer), stdin);
  
        buffer[strcspn(buffer, "\n")] = '\0'; 

        glossary* no = search_no(&dicionario, buffer, tamanho_padrao, tipo);

        if (no != NULL) {
            if (tipo == 1) {
                printf("A traducao de %s e '%s'.\n", buffer, no->ingles);
            } else {
                printf("A traducao de %s e '%s'.\n", buffer, no->portugues);
            }
        } else {
            printf("Palavra nao cadastrada!\n");
        }



        op = 0;
        do {
            printf("Nova traducao? (1 - sim, 2 - nao): ");
            scanf("%d", &op);
        }while (op != 1 && op != 2);


    } while (op != 2);
}
