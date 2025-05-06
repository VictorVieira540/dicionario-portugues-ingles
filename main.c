#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "head.h"

#include "funcoes_auxiliares.h"
#include "tabela.h"
#include "database.h"

// Função para traduzir frases
void traduzir_frases(glossary** dicionario) {
    char frase[256];
    char palavra[64];
    int i = 0, j = 0;
    int tipo;
    
    do {
        limparTela();
        printf("Qual tipo de traducao voce deseja:\n1 - Portugues para ingles\n2 - Ingles para portugues\n");
        scanf("%d", &tipo);
        getchar(); // Limpar o buffer
    } while (tipo != 1 && tipo != 2);
    
    limparTela();
    printf("Digite a frase para traduzir: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';
    
    printf("\nTraducao: ");
    i = 0;
    
    while (frase[i] != '\0') {
        // Pular espaços e pontuações
        if (isspace(frase[i]) || ispunct(frase[i])) {
            printf("%c", frase[i]);
            i++;
            continue;
        }
        
        // Extrair a palavra
        j = 0;
        while (frase[i] != '\0' && !isspace(frase[i]) && !ispunct(frase[i])) {
            palavra[j++] = frase[i++];
        }
        palavra[j] = '\0';
        
        // Buscar tradução
        glossary* no = search_no(&dicionario, palavra, tamanho_padrao, tipo);
        
        if (no != NULL) {
            if (tipo == 1) {
                printf("%s", no->ingles);
            } else {
                printf("%s", no->portugues);
            }
        } else {
            // Se não encontrar tradução, manter a palavra original
            printf("%s", palavra);
        }
    }
    
    printf("\n\nPressione Enter para continuar...");
    getchar();
}

// Função para listar traduções cadastradas
void listar_traducoes(glossary** dicionario) {
    int contador = 0;
    int tipo;
    
    do {
        limparTela();
        printf("Qual listagem voce deseja ver:\n1 - Portugues para ingles\n2 - Ingles para portugues\n");
        scanf("%d", &tipo);
    } while (tipo != 1 && tipo != 2);
    
    limparTela();
    printf("===== LISTAGEM DE TRADUCOES =====\n\n");
    
    for (int i = 0; i < tamanho_padrao; i++) {
        glossary* atual = dicionario[i];
        
        while (atual != NULL) {
            if (tipo == 1) {
                printf("%s: %s\n", atual->portugues, atual->ingles);
            } else {
                printf("%s: %s\n", atual->ingles, atual->portugues);
            }
            
            atual = atual->prox;
            contador++;
            
            // Mostrar em páginas de 20 itens
            if (contador % 20 == 0) {
                printf("\nPressione Enter para continuar...");
                getchar();
                getchar(); // Limpar o buffer
                limparTela();
                printf("===== LISTAGEM DE TRADUCOES (continuação) =====\n\n");
            }
        }
    }
    
    if (contador == 0) {
        printf("Nenhuma traducao encontrada.\n");
    } else {
        printf("\nTotal de traducoes: %d\n", contador);
    }
    
    printf("\nPressione Enter para voltar ao menu...");
    getchar();
    getchar(); // Limpar o buffer
}

void menu(glossary*** dicionario){
    //menu
    char input[10];
    int op=0,e=0;
    do{
        limparTela();
        printf("==========BEM VINDO==========\n");
        printf("Escolha o numero referente a opcao desejada:\n");
        printf("1-Abrir dicionario (buscar palavras)\n");
        printf("2-Traduzir frases\n");
        printf("3-Listar traducoes cadastradas\n");
        printf("4-Sair\n");
       
       if(e==1) printf("Atencao escolha somente o numero referente a opcao!!\n");
       scanf("%9s", input);

        if (isdigit(input[0]) && input[1] == '\0') {
            op = input[0] - '0';
        } else {
            op = 0;
        }

        e=1;

        switch (op) {
        case 1:
            open_dictionary(*dicionario);
            break;
        case 2:
            traduzir_frases(*dicionario);
            break;
        case 3:
            listar_traducoes(*dicionario);
            break;
        case 4:
            delete_dictionary(*dicionario,tamanho_padrao);
            printf("Obrigado por usar o dicionario!\n");
            exit(0);
            break;
        default:
            printf("Opcao invalida.\n");
            printf("Pressione Enter para continuar...");
            getchar();
            getchar(); // Limpar o buffer
            break;
        }
    } while(op!=4);
}

int main(){
    glossary** dicionario = new_dictionary(tamanho_padrao);

    load_database(dicionario,tamanho_padrao,standard_translation);
    menu(&dicionario);
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
        scanf("%d", &tipo);
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
        } while (op != 1 && op != 2);

    } while (op != 2);
}
