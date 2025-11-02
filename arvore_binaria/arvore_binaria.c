#include "arvore_binaria.h"

#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int value;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *createTree() {
    return NULL;
}

void printTree(struct Tree *root, int deg) {
    if(root == NULL) {
        for(int i = 0; i < deg; i++) printf(" ");
        printf("NULL\n");
        return;
    } 

    for(int i = 0; i < deg; i++) printf(" ");
    printf("%d\n", root->value);

    printTree(root->left, deg+1);
    printTree(root->right, deg+1);
    
}

void insertValues(struct Tree **root, int value) {
    if(*root == NULL) {
        *root = (struct Tree *) malloc(sizeof(struct Tree));

        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if(value < (*root)->value) {
            insertValues(&(*root)->left, value);
        } else {
            insertValues(&(*root)->right, value);
        }
    }
}

int search(struct Tree *root, int value) {
    if(root == NULL) return 0;
    else if (value < root->value) return search(root->left, value);
    else return search(root->right, value);
}

void limpaArvore(struct Tree *root) {
    if(root == NULL) return;
    
    limpaArvore(root->left);
    limpaArvore(root->right);
    
    free(root);
    
}

int main(void) {
    struct Tree *minhaArvore = createTree();

    insertValues(&minhaArvore, 10);
    insertValues(&minhaArvore, 60);
    insertValues(&minhaArvore, 20);
    insertValues(&minhaArvore, 80);

    printTree(minhaArvore, 0);

    limpaArvore(minhaArvore);

    return 0;
}