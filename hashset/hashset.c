#include "hashset.h"

#include <stdio.h>
#include <stdlib.h>

/* --- Primeiro de tudo irei começar implementando uma tabela de hash para a estrutura --- */

#define MAX_SIZE_TABLE 1000

struct Node {
    int key;
    struct Node *next;
};

struct Hashtable {
    struct Node *buckets[MAX_SIZE_TABLE];
};

/* --- Hashtable implementada, irei definir uma função para o Hash --- */

unsigned int hash(int key) {
    return key % MAX_SIZE_TABLE;
}

/* -- Funções para inserir, consultar e afins -- */

int buscar(struct Hashtable *hashTable, int key) {
    unsigned int index = hash(key);
    
    struct Node *current = hashTable->buckets[index];
    
    while(current != NULL) {
        if(current->key == key) return 1;
        
        current = current->next;
    }
    
    return 0;
}

void inserir(struct Hashtable *hashTable, int key) {
    if(buscar(hashTable, key) == 0) {
        unsigned int index = hash(key);

        struct Node *new_node = malloc(sizeof(struct Node));
        
        new_node->key = key;
        new_node->next = hashTable->buckets[index];
        hashTable->buckets[index] = new_node;
    }
}

void imprimir(struct Hashtable *hashTable) {
    printf("Seu HashSet<Int>:\n");

    for(int i = 0; i < MAX_SIZE_TABLE; i++) {
        struct Node *current = hashTable->buckets[i];
    
        if(current != NULL) {
            while(current != NULL) {
                printf("=> %d\n", current->key);

                current = current->next;
            }
        }
    } 
}

void limpar_heap_memory(struct Hashtable *hashTable) {
    for(int i = 0; i < MAX_SIZE_TABLE; i++) {
        struct Node *current = hashTable->buckets[i];
    
        while(current != NULL) {
            struct Node *tmp = current;
            current = current->next;
            free(tmp);
        }
    
        hashTable->buckets[i] = NULL;

    } 
}

int main(void) {
    struct Hashtable table = {0}; // de maneira bem simples e eficiente, inicio um novo hashtable que servirá como o Hashset

    inserir(&table, 10);
    inserir(&table, 20);
    inserir(&table, 30);
    inserir(&table, 70);
    inserir(&table, 70); // Esse cara nao vai entrar na estrutura pq ja existe lá

    imprimir(&table);
    
    limpar_heap_memory(&table);

    return 0;
}