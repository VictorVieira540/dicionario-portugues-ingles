#ifndef HEAD_H
#define HEAD_H
#define tamanho_padrao 5000 //DEFINE O TAMANHO INICIAL DO DICIONARIO
#define standard_translation 1 //DEFINA 1 PARA TRADUZIR PORTUGUES PARA INGLES E 0 PARA INGLES PARA PORTUGUES
#define data_path "data/Database.txt"//CAMINHO PARA O ARQUIVO COM A BASE DE PALAVRAS

typedef struct glossary {
    char* portugues;
    char* ingles;
    struct glossary* prox;
} glossary;

//FUNCOES DA TABELA
glossary** new_dictionary(int tamanho);//CRIA UM DICIONARIO COM "TAMANHO" INDICES
glossary* search_no(glossary*** dicionario, const char* world, const int d_size, const int tipo);//PROCURA UM NO NO DICIONARIO E REOGARNIZA A LISTA USANDO TRASPONSICAO
glossary* new_translate(char* portugues,char* ingles);//CRIAR NOVO NO COM AS PALAVRAS
int add_glossary( glossary* novo_par, glossary** dicionario, const int tipo_de_traducao, const int dicionario_t);//ADICIONA UM NO COM A TRADUCAO AO DICIONARIO
void alerta(const char* message);//USADA NAS VERIFICACOES DE ERRO
int delete_dictionary(glossary** dicionario, int tamanho);//DESALOCA UM DICIONARIO
//FUNCOES DO ARQUIVO
glossary* carregar_no(FILE* data);
int counter_data(FILE* data); // Prototipo para counter_data
void extract_word(const char* buffer,char** portugues, char** ingles);

//INTERFACE
void open_dictionary(glossary** dicionario);
#endif
