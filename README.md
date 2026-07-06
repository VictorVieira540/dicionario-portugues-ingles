# Portuguese-English Dictionary

A bilingual dictionary in C developed as a project for the **Data Structures** course at UFV CRP. Implements word lookup, sentence translation, and entry management using a **hash table with linked lists** and a **transposition algorithm** (move-to-front) to optimize frequent queries.

## Features

- **Word lookup** — query Portuguese → English or English → Portuguese
- **Sentence translation** — translates word by word, preserving punctuation and unknown words
- **Entry listing** — displays the full dictionary with pagination (20 items per page)
- **Auto-loading** — reads the word database from a text file on startup
- **Move-to-front (transposition)** — reorganizes the linked list on each lookup, moving frequently queried words to the front

## Data Structures

| Structure | Purpose |
|---|---|
| **Hash Table** (5000 buckets) | Stores search vectors — djb2 hash function |
| **Linked List** | Handles hash collisions — each node stores a (portuguese, english) pair |
| **Transposition** | Reorganizes the list on each access — most searched words move to the front |

## Build & Run

```bash
# Compile
gcc -o dicionario main.c -Wall

# Run
./dicionario
```

The dictionary automatically loads the word database from `data/Database.txt`.

## Menu

```
========== WELCOME ==========
1- Open dictionary (search words)
2- Translate sentences
3- List registered translations
4- Exit
```

## Stack

- **Language:** C
- **Concepts:** Hash table, linked lists, dynamic memory allocation, file I/O
- **Course:** Data Structures — UFV CRP
