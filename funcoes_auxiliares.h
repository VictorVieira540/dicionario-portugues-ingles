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

void alerta(const char* message){
    printf("%s \n",message);
    system("pause");
}
