#include <stdio.h>
#include <stdlib.h>

#define BOYUT 4
int dizi[BOYUT], top;

void push(int veri) {
    if (top + 1 == BOYUT) {
        printf("Stack is full!");
    } else {
        top = top + 1;
        dizi[top] = veri;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty!");
    } else {
        printf("pop : %d", dizi[top]);
        top = top - 1;
    }
}

int peek() {
    return dizi[top];
}

void display() {
    int i;
    for (i = 0; i < top + 1; i++) {
        printf(" %d ", dizi[i]);
    }
    printf("==>TOP");
}

int main() {
    top = -1;
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Top => %d", peek());
                break;
            case 5:
                exit(1);
            default:
                printf("\nInvalid Choice\n");
        }
    }
}


