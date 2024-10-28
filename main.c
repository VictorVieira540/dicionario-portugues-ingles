#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
#include "funcoes_principais.h"
#include "funcoes_auxiliares.h"


int main(){
    glossary** dicionario=NULL;


    //area de teste
    dicionario= new_dictionary(10);
    dicionario[0]=new_translate("gato","cat");
    printf("%s",(*dicionario[0]).portugues);
    return 0;

}
