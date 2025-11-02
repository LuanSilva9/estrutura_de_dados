#pragma once

struct Node;
struct Hashtable;

unsigned int hash(int key);
int buscar(struct Hashtable *hashTable, int key);
void inserir(struct Hashtable *hashTable, int key);
void imprimir(struct Hashtable *hashTable);
void limpar_heap_memory(struct Hashtable *hashTable);

#pragma endregion