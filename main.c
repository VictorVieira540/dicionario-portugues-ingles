#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

#include "funcoes_auxiliares.h"
#include "tabela.h"
#include "database.h"


int main(){
    int dicionario_size=tamanho_padrao;
    glossary  **dicionario1, **dicionario2;

    //area de teste
    //
    dicionario1= new_dictionary(dicionario_size);
    dicionario2=new_dictionary(10);

    glossary* nova_traducao[5];

    nova_traducao[0]=new_translate("carro","car");
    nova_traducao[1]=new_translate("mae","mother");

    nova_traducao[2]=new_translate("carro","boy");
    nova_traducao[3]=new_translate("irma","sister");
    nova_traducao[4]=new_translate("aviao","airplane");

    add_glossary(nova_traducao[0],dicionario1,1,dicionario_size);
    add_glossary(nova_traducao[1],dicionario1,1,dicionario_size);

    add_glossary(nova_traducao[2],dicionario2,1,10);
    add_glossary(nova_traducao[3],dicionario2,1,10);
    add_glossary(nova_traducao[4],dicionario2,1,10);

    imprimir(search_no(&dicionario1,"mae",tamanho_padrao,1));
    //final do teste

    return 0;

}
