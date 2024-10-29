#ifndef HEAD_H
#define HEAD_H
#define tamanho_padrao 500 //DEFINE O TAMANHO INICIAL DO DICIONARIO
#define standard_translation 1 //DEFINA 1 PARA TRADUZIR PORTUGUES PARA INGLES E 0 PARA INGLES PARA PORTUGUES
#define data_path "data/Database.txt"//CAMINHO PARA O ARQUIVO COM A BASE DE PALAVRAS

typedef struct glossary {
    char* portugues;
    char* ingles;
    struct glossary* prox;
} glossary;

void alerta(const char* message);//USADA NAS VERIFICACOES DE ERRO
glossary** new_dictionary(int tamanho);//CRIA UM DICIONARIO COM "TAMANHO" INDICES
glossary* new_translate(char* portugues,char* ingles);//CRIAR NOVO NO COM AS PALAVRAS
int add_glossary(const glossary* novo_par, glossary** dicionario, const int tipo_de_traducao, const int dicionario_t);//ADICIONA UM NO COM A TRADUCAO AO DICIONARIO
/*NOVO_PAR: PONTEIRO DO NO QUE CONTEM A TRADUCAO
DICIONARIO: PONTEIRO DO DICIONARIO
TIPO_DE_TRADUCAO: DEFINIDO EM 'STANDARD_TRASLATION'
DICIONARIO_T: QUANTOS INDICES O DICIONARIO TEM
*/
glossary* search_no(glossary*** dicionario, const char* world, const int d_size, const int tipo);//PROCURA UM NO NO DICIONARIO E REOGARNIZA A LISTA USANDO TRASPONSICAO

int delete_dictionary(glossary** dicionario, int tamanho);//DESALOCA UM DICIONARIO
#endif
