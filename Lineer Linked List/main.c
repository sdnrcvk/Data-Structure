#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} deneme;

//add an element to the beginning of the list
deneme *basaekle(deneme *head, int new_data) {
    deneme *temp = (deneme *) malloc(sizeof(deneme));
    temp->data = new_data;
    temp->next = head;
    head = temp;
    return head;
}

//insert an element in a list
void arayaekle(deneme *head, int which_data, int new_data) {
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

//add element to the end of the list
deneme *sonaekle(deneme *head, int new_data) {
    deneme *temp = (deneme *) malloc(sizeof(deneme));
    temp->data = new_data;
    temp->next = NULL;

    if (head == NULL) {
        head->data = new_data;
        head->next = NULL;
    } else {
        deneme *last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }
    return head;
}

//delete the item at the beginning of the list
deneme *bastansil(deneme *head) {
    if (head == NULL) {
        printf("Listede eleman yok!");
    } else {
        deneme *second_node;
        second_node = head->next;
        free(head);
        head = second_node;
    }
    return head;
}

//delete the element in the list
deneme *aradansil(deneme *head, int key) {

    if (head != NULL) {
        deneme *temp = head;
        if (head->data == key) {
            head = head->next;
            free(temp);
        } else {
            while (temp->next != NULL && temp->next->data != key)
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

//delete the item at the end of the list
void sondansil(deneme *head) {
    if (head == NULL) {
        printf("Listede eleman yok!");
    } else {
        deneme *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

//delete the list completely
deneme *tumunusil(deneme *head) {
    struct node *temp;
    if (head == NULL) {
        return head;
    } else {
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    return head;
}

/*Recursive destroy
struct node *destroy1(struct node *head) {
    if (head == NULL)
        return head;
    else {
        return destroy1(head->next), free(head), head = NULL;
    }
}
*/

//Add the end of the list to the beginning of the list
deneme *sonubasaekle(deneme *head) {
    deneme *p, *q;
    p = head;
    q = p;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    p->next = head;
    q->next = NULL;
    head = p;

    return head;
}

//print list
void yazdir(deneme *head) {
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

//Tek bağlı liste elemanlarını özyinelemeli yazdırmak
/*  void print_recursive(struct node *head) {
      if(head == NULL)
          return;
      printf(" %d ", head -> data);
      print_recursive (head -> next);
  } */

//reverse the list
void tersyazdirma(deneme *head) {
    if (head == NULL) {
        return;
    } else {
        tersyazdirma(head->next);
        printf("%d ", head->data);
    }
}

/*void print_reverse(struct node *head) {
    struct node *head2 = NULL; // yeni listenin başını tutacak adres değişkeni
    struct node *temp = head;
    while (temp != NULL) {
        head2 = basaekle(head2, temp->data);
        temp = temp->next;
    }
    yazdir(head2);
}*/

//show list information
void listebilgisi(deneme *head) {
    int i = 1;

    while (head != NULL) {
        printf("Listenin %d. Dugumunun Adresi = %p \n", i, head);
        printf("Listenin %d. Dugumunun Verisi = %d \n", i, head->data);
        printf("Listenin %d. Dugumunun Bagli Oldugu Dugumun Adresi = %p \n\n", i, head->next);
        head = head->next;
        i++;
    }
}

//show the number of elements in the list
int sayac(deneme *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    printf("\n %d tane eleman var.", count);
    return count;
}

/* int count_recursive(struct node *head) {
     if (head == NULL)
         return 0;
     return count_recursive(head->next) + 1;
 } */


/* void concatenate(struct node *list_1, struct node *list_2) { // parametrelere dikkat
    if (list_l == NULL)
        list_1 = list_2;
    else
        last(list_l)->next = list_2; // last isimli fonksiyona çağrı yapılıyor
} */

/* struct node *copy(struct node *head) {
    struct node *kopya = NULL;
    if (head != NULL)
        do {
            concatenate(kopya, cons(head->data));
            head = head->next;
        } while (head != NULL);
    return kopya;
}  */

struct node* locate(struct node* head, int key) {
    struct node* locate = NULL;
    while(head != NULL)
        if(head -> data != key)
            head = head -> next;
        else {
            locate = head;
            break;
        }
    return(locate);
}

int main() {
    int secim;
    int veri, yer;
    deneme *head = NULL;
    while (1) {
        printf("\n\n1-Add an element to the beginning of the list ");
        printf("\n2-Insert an element in a list ");
        printf("\n3-Add element to the end of the list ");
        printf("\n4-Delete the item at the beginning of the list ");
        printf("\n5-Delete the element in the list ");
        printf("\n6-Delete the item at the end of the list ");
        printf("\n7-Delete the list completely ");
        printf("\n8-Print list ");
        printf("\n9-Show the number of elements in the list ");
        printf("\n10-Listenin tum eleman bilgilerini yazdir ");
        printf("\n11-Add the end of the list to the beginning of the list ");
        printf("\n12-Reverse the list");
        printf("\n13-Find locate");
        printf("\n14-Exit");
        printf("\nYour choice...? :");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                printf("\nEnter the data : ");
                scanf("%d", &veri);
                head = basaekle(head, veri);
                yazdir(head);
                break;;
            case 2:
                printf("\nEnter the value to add the element before : ");
                scanf("%d", &yer);
                printf("\nEnter the data : ");
                scanf("%d", &veri);
                arayaekle(head, yer, veri);
                yazdir(head);
                break;
            case 3:
                printf("\nEnter the data : ");
                scanf("%d", &veri);
                head = sonaekle(head, veri);
                yazdir(head);
                break;
            case 4:
                head = bastansil(head);
                yazdir(head);
                break;
            case 5:
                printf("\nValue to be deleted:");
                scanf("%d", &veri);
                head = aradansil(head, veri);
                yazdir(head);
                break;
            case 6:
                sondansil(head);
                yazdir(head);
                break;
            case 7:
                head = tumunusil(head);
                yazdir(head);
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
                head = sonubasaekle(head);
                yazdir(head);
                break;
            case 12:
                tersyazdirma(head);
                //print_reverse(head);
                break;
            case 13:
                printf("\nEnter the data for finding : ");
                scanf("%d", &veri);
                printf("\nBulunan elemanin adresi : %d",locate(head,veri));
                break;
            case 14:
                exit(1);
            default:
                printf("\nWrong choice! Try again...");
        }

    }
}