//SENDO IMPLEMENTADO
int counter_data(FILE* data){
    glossary* aux = carregar_no(data);
    int contador=0;

    if(sscanf(aux->ingles,"%d",&contador)==1){
            delete_no(aux);
            return contador;
    }else{
        alerta("arquivo comrropido Fx000");
        delete_no(aux);
        return -1;
    }
}

glossary* carregar_no(FILE* data){
    char buffer[256];
    char *portugues=NULL;
    char *ingles=NULL;

    if(fgets(buffer,sizeof(buffer),data)==NULL){
        alerta("Erro de leitura do arquivo Fx001");
        return NULL;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        extract_word(buffer,&portugues,&ingles);
        if(portugues==NULL || ingles==NULL){
            alerta("erro na leitura Fx002");
            return NULL;
        }
        glossary* novo=new_translate(portugues,ingles);
        return novo;
}

void extract_word(const char *buffer, char **portugues, char **ingles){
    int i = 0, j = 0;

    // Encontrar a posição do ':' para separar as palavras
    while (buffer[i] != ':' && buffer[i] != '\0') i++;

    // Alocar memória para a primeira palavra (português)
    *portugues = (char *)malloc(sizeof(char) * (i + 1)); // +1 para o '\0'
    if (*portugues == NULL) {
        alerta("Erro de alocaçao");
        return;
    }

    // Copiar a primeira palavra
    for (int x = 0; x < i; x++) {
        (*portugues)[x] = buffer[x];
    }
    (*portugues)[i] = '\0'; // Terminar a string

    // Verifica se encontrou ':' para continuar
    if (buffer[i] == ':') {
        i++; // Pular o ':'
    }

    // Contar o tamanho da segunda palavra
    while (buffer[i + j] != '\0') {
        j++;
    }

    // Alocar memória para a segunda palavra (inglês)
    *ingles = (char *)malloc(sizeof(char) * (j + 1)); // +1 para o '\0'
    if (*ingles == NULL) {
        alerta("erro de alocaçao");
        return;
    }

    // Copiar a segunda palavra
    for (int x = 0; x < j; x++) {
        (*ingles)[x] = buffer[i + x];
    }
    (*ingles)[j] = '\0'; // Terminar a string
}
