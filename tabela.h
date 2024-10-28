
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

//criar novo nó de traduçao
glossary* new_translate(const char* portugues, const char* ingles) {

    if (portugues == NULL || ingles == NULL) {
        alerta("Erro de parametro");
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

//inserir nova traducao na tabela
int add_glossary(const glossary* translate, glossary*** d, const int tipo_de_traducao, const int dicionario_t){
    if(translate==NULL||d==NULL){
        alerta("Erro de parametro");
        return 1;
    }
    //variaveis a serem usadas
    glossary** dicionario=*d;//usada para facilitar a implementaçao
    unsigned long chave=(tipo_de_traducao==1)?hash(translate->portugues)%dicionario_t:hash(translate->ingles)%dicionario_t;//1:portugues, 0:ingles

    //gerenciar a lista no indice de dicionario[chave]
    if(dicionario[chave]!=NULL){
            new_node(dicionario[chave],translate);
    }else{
        dicionario[chave]=translate;
    }
    return 0;
}


