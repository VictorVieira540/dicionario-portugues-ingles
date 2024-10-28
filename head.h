#ifndef HEAD_H // Verifica se HEAD_H não foi definido
#define HEAD_H // Define HEAD_H


typedef struct glossary {
    char* portugues;
    char* ingles;
    struct glossary* prox;
} glossary;

void alerta(const char* message);

#endif // Fim da proteção contra múltiplas inclusões
