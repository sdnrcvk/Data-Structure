#include<stdio.h>
#include<stdlib.h>

/* Structure to create a node with data and pointer */

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = value; // get value for the node
    if (top == NULL)
        newnode->next = NULL;
    else
        newnode->next = top; // Make the node as TOP
    top = newnode;
    printf("node is Inserted\n\n");
}

void pop() {
    if (top == NULL)
        printf("\nEMPTY STACK\n");
    else {
        struct node *temp = top;
        printf("\nPopped Element : %d", temp->data);
        printf("\n");
        top = temp->next; // After popping, make the next node as TOP
        free(temp);
    }
}

void display() {
// Print the Stack with LL
    if (top == NULL)
        printf("\nEMPTY STACK\n");
    else {
        printf("The Stack with LL is \n");
        struct node *temp = top;
        while (temp->next != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n\n", temp->data);
    }
}

int peek() {
    return top->data;
}

int main() {
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
                exit(0);
            default:
                printf("\nInvalid Choice\n");
        }
    }
}




