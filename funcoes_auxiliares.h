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
//pecorrer a lista e insere um novo no no final
void new_node(glossary* lista, glossary* novo_no){
    glossary* atual=lista;
    while(atual->prox!=NULL){
            atual= atual->prox;
    }
    atual->prox=novo_no;
}

//desalocar uma traducao existente
void delete_translate(glossary* item) {
    if (item != NULL) {
        free(item->portugues);
        free(item->ingles);
        free(item);
    }
}

// usada em testes de verificaçao
void alerta(const char* message){
    printf("%s \n",message);
    system("pause");
}


