#pragma once

struct Tree;
struct Tree *createTree();

void printTree(struct Tree *root, int deg);
void insertValues(struct Tree **root, int value);
int search(struct Tree *root, int value);
void limpaArvore(struct Tree *root);

#pragma endregion