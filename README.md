# Dicionário Português-Inglês

Dicionário bilíngue em C desenvolvido como projeto da disciplina de **Estrutura de Dados**. Implementa busca, tradução de frases e gerenciamento de verbetes usando **tabela hash com listas encadeadas** e **algoritmo de transposição** para otimização de consultas frequentes.

## Funcionalidades

- **Busca de palavras** — consulta português → inglês ou inglês → português
- **Tradução de frases** — traduz palavra por palavra, mantendo pontuação e palavras não encontradas
- **Listagem de verbetes** — exibe todo o dicionário paginado (20 itens por página)
- **Carregamento automático** — lê a base de palavras de um arquivo texto na inicialização
- **Transposição (move-to-front)** — reorganiza a lista encadeada a cada busca, movendo palavras consultadas com frequência para o início da lista

## Estruturas de Dados

| Estrutura | Finalidade |
|---|---|
| **Tabela Hash** (5000 índices) | Armazena os vetores de busca — função hash djb2 |
| **Lista Encadeada** | Trata colisões na tabela hash — cada nó contém par (português, inglês) |
| **Transposição** | Reorganiza a lista a cada acesso — palavras mais buscadas ficam no início |

## Como compilar e executar

```bash
# Compilar
gcc -o dicionario main.c -Wall

# Executar
./dicionario
```

O dicionário carrega automaticamente a base de palavras do arquivo `data/Database.txt`.

## Menu

```
========== BEM VINDO ==========
1- Abrir dicionário (buscar palavras)
2- Traduzir frases
3- Listar traduções cadastradas
4- Sair
```

## Stack

- **Linguagem:** C
- **Conceitos:** Tabela hash, listas encadeadas, alocação dinâmica, manipulação de arquivos
- **Disciplina:** Estrutura de Dados — UFV CRP
