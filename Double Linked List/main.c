#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;;
    struct node *next;
    struct node *prev;
} deneme;

deneme *basaEkle(deneme *head, int new_data) {
    deneme *new_node = (deneme *) malloc(sizeof(deneme));
    new_node->data = new_data;
    new_node->next = head;
    new_node->prev = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->prev = new_node;
        head = new_node;
    }
    return head;
}

deneme *arayaEkle(deneme *head, int which_data, int new_data) {

    deneme *arayaeklenecek = (deneme *) malloc(sizeof(deneme));
    arayaeklenecek->data = new_data;
    deneme *temp = head;

    while (temp->next->data != which_data) {
        temp = temp->next;
    }
    deneme *onune;
    onune = temp->next;
    temp->next = arayaeklenecek;
    arayaeklenecek->next = onune;
}


deneme *sonaEkle(deneme *head, int veri) {
    deneme *temp = (deneme *) malloc(sizeof(deneme));
    temp->data = veri;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        deneme *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    return head;
}

deneme *bastanSil(deneme *head) {
    if (head == NULL) {
        printf("List is already empty!");
    } else {
        deneme *second_node;
        second_node = head->next;
        free(head);
        second_node->prev = NULL;
        head = second_node;
    }
    return head;
}

deneme *aradanSil(deneme *head, int deger) {

    if (head != NULL) {
        deneme *temp = head;
        if (head->data == deger) {
            head = head->next;
            free(temp);
        } else {
            while (temp->next != NULL && temp->next->data != deger)
                temp = temp->next;
            if (temp->next == NULL)
                return head;
            deneme *delete = temp->next;
            temp->next = delete->next;
            free(delete);
        }
    }
    return head;
}

deneme *sondanSil(deneme *head) {
    if (head == NULL) {
        printf("Liste is already empty!");
    }
    if (head->next == NULL) {
        bastanSil(head);
    }
    deneme *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    deneme *onceki = temp->prev;
    free(temp);
    onceki->next = NULL;
    return head;
}

deneme *tumunuSil(deneme *head) {
    deneme *temp = head;
    if (head == NULL) {
        printf("\nListe is already empty!");
    } else {
        while (head != NULL) {
            head = head->next;
            free(temp);
            temp = head;
        }
    }
    return head;
}

bool isPalindrome(deneme *left) {
    if (left == NULL)
        return true;

    // Find rightmost node
    struct node *right = left;
    while (right->next != NULL)
        right = right->next;

    while (left != right) {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }

    return true;
}

void yazdir(deneme *head) {

    printf("\nOlusturulan Liste \n");
    while (head != NULL) {
        printf(" %d ", head->data);
        head = head->next;
    }

}

void listebilgisi(deneme *head) {
    int i = 1;

    while (head != NULL) {
        printf("Listenin %d. Dugumune Bagli Olan Dugumun Adresi = %p \n", i, head->prev);
        printf("Listenin %d. Dugumunun Adresi = %p \n", i, head);
        printf("Listenin %d. Dugumunun Verisi = %d \n", i, head->data);
        printf("Listenin %d. Dugumunun Bagli Oldugu Dugumun Adresi = %p \n\n", i, head->next);
        head = head->next;
        i++;
    }
}

int sayac(deneme *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    printf("\n There are %d elements in the list.", count);
    return count;
}

// head listesinde data’sı veri olan node varsa adresini alma
struct node* locate(struct node* head,int veri) {
    struct node* locate = NULL;
    while(head != NULL) {
        if(head -> data != veri) {
            head = head -> next; // aranan veri yoksa liste taranıyor
        }
        else {
            locate = head;
            break; // veri bulunursa döngüden çıkılarak geri döndürülüyor
        }
    }
    return locate;
}

int main() {
    int secim;
    int veri, yer;
    deneme *head = NULL;

    while (1) {
        printf("\n1-Add an element to the beginning of the list ");
        printf("\n2-Insert an element in a list ");
        printf("\n3-Add element to the end of the list ");
        printf("\n4-Delete the item at the beginning of the list ");
        printf("\n5-Delete the element in the list ");
        printf("\n6-Delete the item at the end of the list ");
        printf("\n7-Delete the list completely ");
        printf("\n8-Print list ");
        printf("\n9-Show the number of elements in the list ");
        printf("\n10-Show the information of elements in the list ");
        printf("\n11-isPalindrome ?");
        printf("\n12-Finding locate ");
        printf("\n13-Exit ");
        printf("\nYour choice?....? :");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                printf("\nEnter the data : ");
                scanf("%d", &veri);
                head = basaEkle(head, veri);
                yazdir(head);
                break;
            case 2:
                printf("\nEnter the value to add the element before : ");
                scanf("%d", &yer);
                printf("\nEnter the data : ");
                scanf("%d", &veri);
                arayaEkle(head, yer, veri);
                yazdir(head);
                break;
            case 3:
                printf("\nEnter the data : ");
                scanf("%d", &veri);
                head = sonaEkle(head, veri);
                yazdir(head);
                break;
            case 4:
                head = bastanSil(head);
                yazdir(head);
                break;
            case 5:
                printf("\nValue to be deleted:");
                scanf("%d", &veri);
                head = aradanSil(head, veri);
                yazdir(head);
                break;
            case 6:
                sondanSil(head);
                yazdir(head);
                break;
            case 7:
                head = tumunuSil(head);
                printf("\nList is deleted! ");
                break;
            case 8:
                yazdir(head);
                break;
            case 9:
                sayac(head);
                break;
            case 10:
                listebilgisi(head);
                break;
            case 11:
                if (isPalindrome(head))
                    printf("\nIt is Palindrome");
                else
                    printf("\nNot Palindrome");
                break;
            case 12:
                printf("\nEnter the data : ");
                scanf("%d", &veri);
                printf("\nBulunan elemanin adresi : %d",locate(head,veri));
                break;
            case 13:
                exit(1);
            default:
                printf("\nWrong choice! Try again...");
        }

    }
}