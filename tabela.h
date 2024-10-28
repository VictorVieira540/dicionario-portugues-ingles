
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
int add_glossary(const glossary* translate, glossary** dicionario, const int tipo_de_traducao, const int dicionario_t){
    if(translate==NULL||dicionario==NULL){
        alerta("Erro de parametro");
        return 1;
    }
    //variaveis a serem usadas
    //glossary** dicionario=*d;//usada para facilitar a implementaçao
    unsigned long chave=
    (tipo_de_traducao==1)?
        hash(translate->portugues)%dicionario_t:
        hash(translate->ingles)%dicionario_t;//1:portugues, 0:ingles

    //gerenciar a lista no indice de dicionario[chave]
    if(dicionario[chave]!=NULL){
            new_node(dicionario[chave],translate);
    }else{
        dicionario[chave]=translate;
    }
    return 0;
}

glossary* search_no(glossary*** dicionario, const char* world, const int d_size, const int tipo ){
    //verificaçoes
    if(*dicionario==NULL || world == NULL){
        alerta("Erro ao buscar o no!");
        return NULL;
    }
    //variaveis
    unsigned long chave= hash(world)%d_size;
    glossary** d=*dicionario;
    glossary* anterior=NULL;
    glossary* anterior_do_anterior=NULL;
    glossary* atual=d[chave];

    //o tipo vai definir a busca
    //O while vai mover o ponteiro ate encontrar o no com a palavra correspondente, caso não encontre 'atual' sera nulo
   if(tipo==1){
    while(atual!=NULL && strcmp(world,atual->portugues)!=0){
          anterior_do_anterior=anterior;
          anterior=atual;
          atual=atual->prox;
    }
   }else{
           while(atual!=NULL && strcmp(world,atual->ingles)!=0){
          anterior_do_anterior=anterior;
          anterior=atual;
          atual=atual->prox;
    }
   }

    if(atual==NULL)return NULL;//Caso atual seja NULL, ou o valor buscado nao existe, ou nao existe lista

    if(anterior==NULL)return atual;//se o primeiro elemento da lista for o que esta sendo buscado nao tem necessidade de trocar, entao so retorna esse no

    if(anterior_do_anterior==NULL){//Se o valor estiver no segundo elemento so sera necessario trocar o primeiro com o segundo nao precisando chamar a funçao 'replace_no'
        anterior->prox=atual->prox;
        atual->prox=anterior;
        d[chave]=atual;// aqui a funçao acessa diretamente o endereço e altera seu valor
        return atual;
    }else{
      replace_no(&anterior_do_anterior,&atual);
      return atual;
    }
}

