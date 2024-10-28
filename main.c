#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

#include "funcoes_auxiliares.h"
#include "tabela.h"
#include "database.h"



int main(){
    int dicionario_size=10;
    glossary** dicionario=NULL;

    //area de teste
    //
    dicionario= new_dictionary(dicionario_size);
    glossary* nova_traducao= new_translate("carro","car");//indice 6

    add_glossary(nova_traducao,&dicionario,1,dicionario_size);

    printf("%s  ::  ",(*dicionario[6]).portugues);
    printf("%s",(*dicionario[6]).ingles);

    //final do teste

    delete_translate(nova_traducao);
    free(dicionario);
    return 0;

}
