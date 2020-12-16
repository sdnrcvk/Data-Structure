#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char kitapadigirdisi[20];
    char kitapyazarigirdisi[20];
    int basimtarihigirdisi;
    struct node *next;
} kitap;

struct queue {
    kitap *first;
    kitap *last;
    int counter;
};

void tanimla(struct queue *a) {
    a->first = NULL;
    a->last = NULL;
    a->counter = 0;
}

kitap* kitapolustur(struct queue *a, char kitapadigirdisi[], char kitapyazarigirdisi[], int basimtarihigirdisi)
{
    kitap *yenikitap = (kitap*)malloc(sizeof(kitap));
    strcpy(yenikitap->kitapadigirdisi, kitapadigirdisi);
    strcpy(yenikitap->kitapyazarigirdisi, kitapyazarigirdisi);
    yenikitap->basimtarihigirdisi = basimtarihigirdisi;
    yenikitap->next = NULL;
    if (a->first == NULL) {
        a->counter++;
        a->first = yenikitap;
        a->last = yenikitap;
    } else {
        a->counter++;
        a->last->next = yenikitap;
        a->last = yenikitap;
    }
    return yenikitap;
};

void kitabilistedencikar(struct queue *a)
{
    kitap *temp;
    if (a->first == NULL)
        printf("Liste Bos.");
    else {
        if (a->first == a->last) {
            free(a->first);
            a->first = NULL;
            a->last = NULL;
        } else {
            temp = a->first;
            a->first = a->first->next;
            free(temp);
        }
        a->counter--;
    }
}

void listeyibas(struct queue *a)
{
    kitap *temp;
    if(a->first == NULL)
    {
        return;
    }
    temp = a->first;
    while(temp != NULL)
    {
        printf("\n Kitap Adi => %s \n Kitap Yazari => %s\n Kitap Basim tarihi => %d ", temp->kitapadigirdisi, temp->kitapyazarigirdisi, temp->basimtarihigirdisi);
        temp = temp->next;
    }
}


void menu()
{
    struct queue a;
    char deneme;
    char kitapadi[20], kitapyazari[20];
    int basimtarihi, z = 0;
    int choice;
    while(1)
    {
        printf("\n 1- Listeye Kitap Ekle ");
        printf("\n 2- Listeden Kitap Cikar");
        printf("\n 1- Listeye bas ");
        printf("\nLutfen Secim Yapiniz : ");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
            case 1:
                if (z < 5) {
                    printf("\n Kitap adi: ");
                    fgets(kitapadi, 20, stdin);
                    printf("\n Kitap yazari: ");
                    fgets(kitapyazari, 20, stdin);
                    printf("\n Basim tarihi: ");
                    scanf(" %d", &basimtarihi);
                    getchar();
                    kitapolustur(&a, kitapadi, kitapyazari, basimtarihi);
                    z++;
                    break;
                } else {
                    printf("\n Liste Dolu! ");
                    break;
                }
            case 2:
                kitabilistedencikar(&a);
                listeyibas(&a);
                z--;
                break;
            case 3:
                listeyibas(&a);
                break;
        }
    }
}

int main()
{
    menu();
}