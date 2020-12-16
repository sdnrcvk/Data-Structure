#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[30];
    char author[30];
    int year;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
struct node *temp;

char bookName[30], author[30];
int year;

struct node *createBook(char name[], char author[], int year) {
    struct node *newbook = (struct node *) malloc(sizeof(struct node));
    strcpy(newbook->name, name);
    strcpy(newbook->author, author);
    newbook->year = year;
    newbook->next = NULL;

    return newbook;
};

void enQueueBook(char name[], char author[], int year) {
    struct node *book = createBook(name, author, year);
    if (front == NULL && rear == NULL) {
        front = book;
        rear = book;
    } else {
        rear->next = book;
        rear = book;
    }
}

void deQueue() {
    temp = front;
    if (front == NULL) {
        printf("\nQueue is empty, pls Enqueue...");
        return;
    }

    if (front == rear) {
        front = NULL;
        rear = NULL;
        return;
    }

    front = temp->next;
    free(temp);
}


void printQueue() {
    int i = 1;
    if (front == NULL) {
        return;
    }
    temp = front;
    while (temp->next != NULL) {
        printf("\n%d. Book => %s %s %d ", i, temp->name, temp->author, temp->year);

        temp = temp->next;
        i++;
    }
    printf("\n%d. Book => %s %s %d ", i, temp->name, temp->author, temp->year);
}


int main() {
    int choise;
    while (1 == 1) {
        printf("\n 1- Enqueue ... ");
        printf("\n 2- Dequeue ... ");
        printf("\nMake your choise : ");
        scanf("%d", &choise);

        switch (choise) {
            case 1:
                printf("\n Enter book name... ");
                scanf("%s", &bookName);
                printf("\n Enter author ... ");
                scanf("%s", &author);
                printf("\n Enter year of printing ... ");
                scanf("%d", &year);
                enQueueBook(bookName, author, year);
                printQueue();
                break;
            case 2:
                deQueue();
                printQueue();
                break;
        }
    }
}
