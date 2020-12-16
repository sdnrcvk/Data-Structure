#include<stdio.h>
#include<stdlib.h>
struct Kitap{
    char KitapAd[50];
    char KitapYazar[50];
    int  BasimYili;
    struct Kitap*Sonraki;
};
struct Kitap* front= NULL;
struct Kitap* rear=NULL;
struct Kitap* Olustur(){
    struct Kitap* YeniKitap= (struct Kitap*)malloc(sizeof(struct Kitap));
    YeniKitap->Sonraki=NULL;
    return YeniKitap;
}

void EnQueue(struct Kitap *EklenecekKitap){

    if(front==NULL){
        front=EklenecekKitap;
        rear=EklenecekKitap;
    }
    else{
        rear->Sonraki=EklenecekKitap;
        rear=EklenecekKitap;
    }
}

struct Kitap* DeQueue(){
    if(front==NULL){
        printf("\nkuyruk bos\n");
        return NULL;
    }
    struct Kitap* Cikarilacak=front;
    struct Kitap* YeniFront=front->Sonraki;
    free(front);
    front=YeniFront;
    return Cikarilacak;
}
void Yazdir(){
    if(front==NULL){
        printf("kuyruk bos\n");
        return;
    }
    struct Kitap* temp= front;
    int counter=1;
    while(temp != NULL){
        printf("\n****** KITAP NUMARASI:%d ******\n",counter);
        printf("\nKITAP ADI:%s \n",temp->KitapAd);
        printf("\nKITAP YAZARI:%s \n",temp->KitapYazar);
        printf("\nBASIM YILI:%d \n",temp->BasimYili);
        temp=temp->Sonraki;
        counter++;
    }
}

int main()
{
    int secim;
    struct Kitap* YeniKitap;
    while(1)
    {
        printf("\n 1- Ekle");
        printf("\n 2- Cikar ");
        printf("\n Secim yapiniz : ");
        scanf("%d", &secim);
        switch(secim)
        {
            case 1:
                YeniKitap = Olustur();
                printf("\n Kitap adini giriniz: ");
                scanf("%s", YeniKitap->KitapAd);
                printf("\n Kitabin yazarinin adini giriniz:");
                scanf("%s", YeniKitap->KitapYazar);
                printf("\n Basim yilini giriniz: ");
                scanf("%d", &YeniKitap->BasimYili);
                EnQueue(YeniKitap);
                Yazdir();
                break;
            case 2:
                DeQueue();
                Yazdir();
                break;
        }
    }
}