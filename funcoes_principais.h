
//funcao para criar uma nova tabela
glossary** new_dictionary(int tamanho){
    glossary** novo= (glossary**)malloc(sizeof(glossary*)*tamanho);

    if(novo==NULL){
        alerta("Ocorreu um erro ao criar o dicionario");
        return NULL;
    }else{
        for(int x=0;x<tamanho;x++){//loop para limpar o lixo das variaveis das estruturas
            novo[x]=NULL;
        }
        return novo;
    }
}

glossary* new_translate(const char* portugues, const char* ingles) {

    if (portugues == NULL || ingles == NULL) {
        alerta("Um dos parametros e nulo");
        return NULL;
    }

    glossary* nova_traducao = (glossary*)malloc(sizeof(glossary));

    if (nova_traducao == NULL) {
        alerta("Erro ao alocar memoria para nova traducao");
        return NULL;
    }

    nova_traducao->portugues = strdup(portugues);
    nova_traducao->ingles = strdup(ingles);
    nova_traducao->prox = NULL;

    return nova_traducao;
}
