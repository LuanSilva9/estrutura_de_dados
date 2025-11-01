#include <stdio.h>
#include <stdlib.h>

struct IntegerHashset {
    int value;
    struct IntegerHashset *NEXT;
};

int can_i_insert_this(struct IntegerHashset *head, int value) {
    struct IntegerHashset *current = head;

    while(current != NULL) {
        if(current->value == value) return 0;
        current = current->NEXT;
    }

    return 1;
}

void add(struct IntegerHashset *head, int value) {
    if(can_i_insert_this(head, value) == 0) {
        printf("Você não pode inserir esse valor, isso é um Set<>, valores iguais não sao permitidos");
        
        return;
    } else {
        if(head->NEXT == NULL && head->value == 0) {
            head->value = value;
            return;
        }

        struct IntegerHashset *current = head;

        while(current->NEXT != NULL) {
            current = current->NEXT;
        }

        struct IntegerHashset *next = malloc(sizeof(struct IntegerHashset));

        next->value = value;
        next->NEXT = NULL;
        
        current->NEXT = next;
    }
}

void get_values(struct IntegerHashset *head) {
    struct IntegerHashset *current = head;

    printf("Valores da struct do Hashset Atual\n");
    while(current != NULL) {
        printf("-> %d\n", current->value);

        current = current->NEXT;
    }
}

int lengthOfHashset() {
    int length;

    printf("Qual vai ser o valor do seu Hashset?\n");
    scanf("%d", &length);

    return length;
}

void dinamic_hashset(struct IntegerHashset *head) {
    int dinamicHashset = lengthOfHashset();

    for(int i = 0; i < dinamicHashset; i++) {
        int value;

        printf("\n Digite um valor: ");
        scanf("%d", &value);
        printf("\n");

        add(head, value);
    }
}

void clear_values(struct IntegerHashset *head) {
    struct IntegerHashset *current = head->NEXT;
    struct IntegerHashset *temp;
    
    while(current != NULL) {
        temp = current->NEXT;
        free(current);
        current = temp;
    }
}

int main(void) {
    struct IntegerHashset meuHashSet;

    meuHashSet.NEXT = NULL;

    dinamic_hashset(&meuHashSet);

    get_values(&meuHashSet);

    clear_values(&meuHashSet);

    return 0;
}