#include <stdio.h>
#include <stdlib.h>

#define bool int

struct node {
    char data;
    struct node *next;
};

void push(struct node **head, int new_data) {

    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Stack overflow n");
        getchar();
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}


int pop(struct node **head) {
    char res;
    struct node *top;

    if (*head == NULL) {
        printf("Stack overflow n");
        getchar();
        exit(0);
    } else {
        top = *head;
        res = top->data;
        *head = top->next;
        free(top);
        return res;
    }
}

bool ciftlerEslendimi(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

bool parantezlerDengelimi(char array[]) {
    int i = 0;
    struct node *stack = NULL;

    while (array[i]) {
        if (array[i] == '{' || array[i] == '(' || array[i] == '[')

            push(&stack, array[i]);

        if (array[i] == '}' || array[i] == ')' || array[i] == ']') {

            if (stack == NULL)
                return 0;

            else if (!ciftlerEslendimi(pop(&stack), array[i]))
                return 0;
        }
        i++;
    }
    if (stack == NULL)
        return 1; // balanced
    else
        return 0; // not balanced
}

int main() {
    char array[100];

    printf("Bir karakter dizisi giriniz (max:100): ");
    gets(array);

    if (parantezlerDengelimi(array))
        printf("\nDengeli! ");
    else
        printf("\nDengeli Degil! ");
    return 0;
}
