#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

#include "funcoes_auxiliares.h"
#include "tabela.h"
#include "database.h"


int main(){
    int dicionario_size=tamanho_incial;
    glossary** dicionario=NULL;

    //area de teste
    //
    dicionario= new_dictionary(dicionario_size);
    glossary* nova_traducao=new_translate("carro","car");
    add_glossary(nova_traducao,dicionario,1,dicionario_size);

  imprimir(search_no(&dicionario,"carro",dicionario_size,1));
    //final do teste

    delete_no(nova_traducao);

    free(dicionario);
    return 0;

}
