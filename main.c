#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

#include "funcoes_auxiliares.h"
#include "tabela.h"
#include "database.h"


int main(){

    FILE* arquivo = fopen(data_path,"r");

    //area de teste
    for(int x=0;x<5;x++)carregar_no(arquivo);

    glossary* novo_no= carregar_no(arquivo);

    printf("%s",novo_no->portugues);
    //final do teste


    delete_no(novo_no);
    return 0;

}
