//AUXILIARES DA TABELA
//Gerador de hashes
unsigned long hash(const char *str) {
    unsigned long hash = 5381;  // Valor inicial
    int c;

    // Percorre cada caractere da string
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    }

    return hash;
}

////LISTAS
//pecorrer a lista e insere um novo no no final
void new_node(glossary* lista, glossary* novo_no){
    glossary* atual=lista;
    while(atual->prox!=NULL){
            atual= atual->prox;
    }
    atual->prox=novo_no;
}

//desalocar uma traducao existente
void delete_no(glossary* item) {
    if (item != NULL) {
        free(item->portugues);
        free(item->ingles);
        free(item);
    }
}
void replace_no(glossary** anterior_do_ant, glossary** atual){
    glossary* anterior=(*anterior_do_ant)->prox;
    anterior->prox=(*atual)->prox;
    (*atual)->prox=anterior;
    (*anterior_do_ant)->prox=*atual;
}


// usada em testes de verificaçao



void alerta(const char* message){
    printf("%s \n",message);
    system("pause");
}
//testes
void imprimir(glossary* item){
    if(item!=NULL){
        printf("%s  ::  %s",item->portugues,item->ingles);
    }else{
        printf("Traducao nao consta no banco de dados!");
    }
}

