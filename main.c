#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
#include "funcoes_principais.h"
#include "funcoes_auxiliares.h"


int main(){
    glossario** dicionario;
    dicionario= Criar_dicionario(10);

    dicionario[5]=(glossario*)malloc(sizeof(glossario));

    (*dicionario[5]).ingles = (char*)malloc(sizeof(char));
     (*dicionario[5]).ingles='d';
//teste
    return 0;
}
