
//funcao para criar uma nova tabela
glossario* Criar_dicionario(int tamanho){
    glossario** novo= (glossario**)malloc(sizeof(glossario)*tamanho);

    if(novo==NULL){
        printf("Ocorreu um erro ao criar o dicionario");
        exit(1);
    }else{
        for(int x=0;x<tamanho;x++){//loop para limpar o lixo das variaveis das estruturas
            novo[x]=NULL;
        }
        return novo;
    }
}
