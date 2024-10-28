typedef struct glossary{
    char* portugues;
    char* ingles;
    struct glossary* prox;
}glossary;

void alerta(const char*);
