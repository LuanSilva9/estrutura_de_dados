#pragma once

struct NodeList;

struct NodeList *criarFila();
void inserirNaFila(struct NodeList **head, int value);
void deletarNaFila(struct NodeList **head);
void printarFila(struct NodeList *head);
int filaVazia(struct NodeList *head);

#pragma endregion