#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

#include "funcoes_auxiliares.h"
#include "tabela.h"
#include "database.h"
// 529 elementos

int main(){
    int tipo=0;
    glossary **dicionario= new_dictionary(tamanho_padrao);

    //area de teste
    load_database(dicionario,tamanho_padrao,tipo);

    glossary* busca= search_no(&dicionario,"develop",tamanho_padrao,tipo);
    imprimir(busca);
    //final do teste
    delete_dictionary(dicionario,tamanho_padrao);
    return 0;

}
