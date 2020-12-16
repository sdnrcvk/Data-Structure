#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

void insertAtFront(int key) {
    if (head == NULL) {
        head = (struct node *) malloc(sizeof(struct node));
        head->data = key;
        head->next = head;
    } else {
        struct node *temp = (struct node *) malloc(sizeof(struct node));
        struct node *last = head;
        temp->data = key;
        while (last->next != head) // listenin son elemanı bulunuyor.
            last = last->next;
        temp->next = head;
        last->next = temp;
        head = temp;
    }
}

void insertAtLast(int key) {
    if (head == NULL) {
        head = (struct node *) malloc(sizeof(struct node));
        head->data = key;
        head->next = head;
    } else {
        struct node *temp = (struct node *) malloc(sizeof(struct node));
        struct node *last = head;
        temp->data = key;
// listenin son elemanı bulunuyor.
        while (last->next != head)
            last = last->next;
        temp->next = head;
        last->next = temp;
    }
}

// list_1 listesinin sonuna list_2 listesini eklemek
/*void concatenate(struct node *& list_1,struct node *list_2){ //parametrelere dikkat
    if(list_l == NULL)
    list_1 = list_2;
    else {
    // Birinci listenin son düğümünü last olarak bulmak için
    struct node *last = list_1;
    while(last -> next != list_1)
    last = last->next;
    last->
    next = list_2; //Birinci listenin sonu ikinci listenin başına bağlandı
    // İkinci listenin son düğümünü last olarak bulmak için
    last = list_2;
    while(last -> next != list_2)
    last = last->next;
    last->
    next = list_2; //İkinci listenin sonu birinci listenin başına bağlandı
    }
} */

//head listesinde data'sı veri olan node varsa adresini alma
/*struct node* locate(int veri, struct node* head) {
    struct node* locate = NULL;
    struct node* temp = head;
    do {
        if(head -> data != veri)
            head = head -> next;
        else {
            locate = head;
            break;
        } while(head != temp);
        return(locate);
    } */

struct node *deletenode(struct node *head, int key) {
    if (head == NULL) {
        printf("Listede eleman yok\n");
        return head;
    }
    struct node *temp = head;
    if (head->data == key) { // ilk düğüm silinecek mi diye kontrol ediliyor.
        struct node *last = head;
        while (last->next != head)
            last = last->next;
        head = head->next; // head artık bir sonraki eleman.
        last->next = head;
        free(temp);
    } else if (temp->next == NULL) { // Listede tek düğüm bulunabilir.
        printf("Silmek istediginiz veri bulunmamaktadir.\n\n");
    } else {
        while (temp->next->data != key) {
            if (temp->next->next == NULL) {
                printf("Silmek istediginiz veri bulunmamaktadir.\n\n");
                return head;
            }
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
    return head;
}

void yazdir(struct node *head) {
    if (head == NULL) {
        printf("\nListe eleman yok!");
    } else {
        printf("\n ~Olusturulan Liste~ \n");
        struct node *temp2 = head;
        while (temp2 != NULL) {
            printf(" %d ", temp2->data);
            temp2 = temp2->next;
        }
    }
}


int main() {
    int secim;
    int veri, yer;

    while (1) {
        printf("\n1-Add an element to the beginning of the list ");
        printf("\n2-Add element to the end of the list ");
        printf("\n3-Delete the element in the list ");
        printf("\n5-Exit");
        printf("\nYour choice...? :");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                printf("\nEnter the data : ");
                scanf("%d", &veri);
                insertAtFront(veri);
                yazdir(head);
                break;;
            case 2:
                printf("\nEnter the data : ");
                scanf("%d", &veri);
                insertAtLast(veri);
                yazdir(head);
                break;
            case 3:
                printf("\nEnter the data : ");
                scanf("%d", &veri);
                deletenode(head, veri);
                yazdir(head);
                break;
            case 4:
                exit(1);
            default:
                printf("\nWrong choice! Try again...");
        }

    }
}