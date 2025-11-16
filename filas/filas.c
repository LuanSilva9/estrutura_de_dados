#include <stdio.h>
#include <stdlib.h>

#include "filas.h"

struct NodeList {
    int value;
    struct NodeList *next;
};

struct NodeList *criarFila() {
    return NULL;
}

// FIFO

void inserirNaFila(struct NodeList **head, int value) {
    struct NodeList *newNode = malloc(sizeof(struct NodeList));

    newNode->value = value;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct NodeList *current = *head;

    while(current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
}

void deletarNaFila(struct NodeList **head) {
    if(*head == NULL) return;
    
    struct NodeList *tmp = *head;

    *head = (*head)->next;

    free(tmp);
}

void printarFila(struct NodeList *head) {
    struct NodeList *current = head;

    if(current == NULL) {
        printf("Fila vazia");

        return;
    }

    while(current != NULL) {
        printf("%d", current->value);

        current = current->next;
    }
}

int filaVazia(struct NodeList *head) {
    return head == NULL;
}

int main(void) {
    struct NodeList *fila = criarFila();

    inserirNaFila(&fila, 10);
    inserirNaFila(&fila, 20);
    inserirNaFila(&fila, 30);

    deletarNaFila(&fila);
    deletarNaFila(&fila);
    deletarNaFila(&fila);

    printarFila(fila);
}