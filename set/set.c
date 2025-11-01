#include <stdio.h>
#include <stdlib.h>

struct IntegerSet {
    int value;
    struct IntegerSet *NEXT;
};

int can_i_insert_this(struct IntegerSet *head, int value) {
    struct IntegerSet *current = head;

    while(current != NULL) {
        if(current->value == value) return 0;
        current = current->NEXT;
    }

    return 1;
}

void add(struct IntegerSet *head, int value) {
    if(!can_i_insert_this(head, value)) {
        printf("Você não pode inserir esse valor, isso é um Set<>, valores iguais não sao permitidos\n----\n");
        
        return;
    } else {
        if(head->NEXT == NULL && head->value == 0) {
            head->value = value;
            return;
        }

        struct IntegerSet *current = head;

        while(current->NEXT != NULL) {
            current = current->NEXT;
        }

        struct IntegerSet *next = malloc(sizeof(struct IntegerSet));

        next->value = value;
        next->NEXT = NULL;
        
        current->NEXT = next;
    }
}

void get_values(struct IntegerSet *head) {
    struct IntegerSet *current = head;

    printf("Valores da struct do Hashset Atual\n");
    while(current != NULL) {
        printf("-> %d\n", current->value);

        current = current->NEXT;
    }
}

void dinamic_hashset(struct IntegerSet *head) {
    int length;

    printf("Qual vai ser o valor do seu Hashset?\n");
    scanf("%d", &length);

    for(int i = 0; i < length; i++) {
        int value;

        printf("Digite um valor: ");
        scanf("%d", &value);
        printf("\n");

        add(head, value);
    }
}

void clear_values(struct IntegerSet *head) {
    struct IntegerSet *current = head->NEXT;
    struct IntegerSet *temp;
    
    while(current != NULL) {
        temp = current->NEXT;
        free(current);
        current = temp;
    }
}

int main(void) {
    struct IntegerSet meuHashSet;
    meuHashSet.NEXT = NULL;

    dinamic_hashset(&meuHashSet);

    get_values(&meuHashSet);

    clear_values(&meuHashSet);

    return 0;
}