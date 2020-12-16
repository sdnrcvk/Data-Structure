#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node BTREE;

BTREE *new_node(int data) {
    BTREE *p = (BTREE *) malloc(sizeof(BTREE));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

BTREE *insert(BTREE *root, int data) { // root'u verilmiş ağaca ekleme yapılacak
    if (root != NULL) {
        if (data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    } else
        root = new_node(data);
    return root;
}

int height(BTREE *root) {
    if (root == NULL)
        return -1;
    else {
        int left_height, right_height;
        left_height = height(root->left);
        right_height = height(root->right);
        if (right_height > left_height)
            return right_height + 1;
        else
            return left_height + 1;
    }
}

BTREE *delete_node(BTREE *root, int x) {
    BTREE *p, *q;
    if (root == NULL)
        return NULL;
    if (root->data == x) {
        if (root->left == root->right) {
            free(root);
            return NULL;
        } else {
            if (root->left == NULL) {
                p = root->right;
                free(root);
                return p;
            } else if (root->right == NULL) {
                p = root->left;
                free(root);
                return p;
            } else {
                p = q = root->right;
                while (p->left != NULL)
                    p = p->left;
                p->left = root->left;
                free(root);
                return q;
            }
        }
    } else if (root->data < x)
        root->right = delete_node(root->right, x);
    else
        root->left = delete_node(root->left, x);
    return root;
}

BTREE *searchtree(BTREE *tree, int data) {
    if (tree != NULL)
        if (tree->data == data)
            return tree;
        else if (tree->data > data)
            searchtree(tree->left, data);
        else
            searchtree(tree->right, data);
    else
        return NULL;
}


int minValue(BTREE *root) {
    if (root == NULL)
        return 0;
    while (root->left != NULL)
        root = root->left;
    return (root->data);
}

int maxValue(BTREE *root) {
    if (root == NULL)
        return 0;
    while (root->right != NULL)
        root = root->right;
    return (root->data);
}


bool isBST(BTREE *root) { // boolean türü stack kısmında anlatılmıştı
    if (root == NULL)
        return 1;
    if (root->left != NULL && maxValue(root->left) > root->data)
        return 0;
    if (root->right != NULL && minValue(root->right) <= root->data)
        return 1;
    if (!isBST(root->left) || !isBST(root->right))
        return 0;
    return 1;
}


int isSame(BTREE *a, BTREE *b) {
    if (a == NULL && b == NULL)
        return 1; // İki ağaç da boş ise true döndürür
    else if (a != NULL && b != NULL)
        return (
                a->data == b->data && isSame(a->left, b->left) &&
                isSame(a->right, b->right) // Koşul doğru ise true döndürür
        );
    else
        return 0;
}

int size(BTREE *root) {
    if (root == NULL)
        return 0;
    else
        return size(root->left) + 1 + size(root->right);
}

int sizeLeaves(BTREE *root) {
    if (root == NULL)
        return 0;
    else {
        if (root->left == root->right)
            return 1;
        else
            return sizeLeaves(root->left) + sizeLeaves(root->right);
    }
}

void preorder(BTREE *root) {
    if (root != NULL) {
        printf("%3d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BTREE *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%3d ", root->data);
        inorder(root->right);
    }
}

void postorder(BTREE *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%3d ", root->data);
    }
}

void buyuktenKucuge(BTREE *root) {
    if (root != NULL) {
        buyuktenKucuge(root->right);
        printf("%3d ", root->data);
        buyuktenKucuge(root->left);
    }
}


/*sag ve sol cocuklar yer degisir
void mirror(BTREE* root) {
    if(root == NULL)
        return;
    else {
        BTREE* temp;
        mirror(root -> left);
        mirror(root -> right);
        temp = root -> left; // swap işlemi yapılıyor
        root -> left = root -> right;
        root -> right = temp;
    }
} */

BTREE *KthLargestUsingMorrisTraversal(BTREE *root, int k) {
    BTREE *curr = root;
    BTREE *Klargest = NULL;

    int count = 0;

    while (curr != NULL) {
        if (curr->right == NULL) {

            if (++count == k)
                Klargest = curr;

            curr = curr->left;
        } else {
            BTREE *succ = curr->right;

            while (succ->left != NULL && succ->left != curr)
                succ = succ->left;

            if (succ->left == NULL) {
                succ->left = curr;

                curr = curr->right;
            }else {

                succ->left = NULL;

                if (++count == k)
                    Klargest = curr;

                curr = curr->left;
            }
        }
    }
    return Klargest;
}

void oddNode(BTREE *root) //tek sayiii
{
    if (root != NULL) {
        oddNode(root->left);
        if (root->data % 2 != 0)
            printf("%d ", root->data);

        oddNode(root->right);
    }
}

int path(BTREE *root, int sum) {
    int pathSum;
    if (root == NULL) // Ağaç NULL ise
        return (sum == 0); // sum 0'a eşitse true dönüyor
    else {
        pathSum = sum - root->data;
        return (
                path(root->left, pathSum) ||
                path(root->right, pathSum)
        );
    }
}

BTREE *copyOdd(BTREE *root, BTREE *root2) {
    if (root != NULL) {
        if (root->data % 2 == 1)
            root2 = insert(root2, root->data);
        root2 = copyOdd(root->left, root2);
        root2 = copyOdd(root->right, root2);
    }
    return root2;
}

void evenNode(BTREE *root) //cift sayiiii
{
    if (root != NULL) {
        evenNode(root->left);
        if (root->data % 2 == 0)
            printf("%d ", root->data);

        evenNode(root->right);
    }
}


int main() {
    BTREE *myroot = NULL;
    BTREE *myroot2 = NULL;
    int i = 0;
    int sayi, secim;
    int k;
    while (1) {
        printf("\n1-Eleman ekle ");
        printf("\n2-Preorder-Inorder-Postorder");
        printf("\n3-Eleman sil");
        printf("\n4-Eleman bul ");
        printf("\n5-BST?-Min-Max-Yukseklik-ElemanSayisi-Yapraklar");
        printf("\n6-Tek sayilari bul ");
        printf("\n7-Cift sayilari bul ");
        printf("\n8-k'ninci buyuk elemani bul");
        printf("\n9-Exit");
        printf("\nYour choice...? :");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                printf("\nEnter the data : ");
                scanf("%d", &i);
                myroot = insert(myroot, i);
                break;
            case 2:
                printf("\nPreorder(Root-Left-Right) :");
                preorder(myroot);
                printf("\nInorder(Left-Root-Right) :");
                inorder(myroot);
                printf("\nPostorder(Left-Right-Root) :");
                postorder(myroot);
                printf("\nBuyukten kucuge siralama(Right-Root-Left) :");
                buyuktenKucuge(myroot);
                break;
            case 3:
                printf("\nSilmek istediginiz sayi : ");
                scanf("%d", &sayi);

                printf("\nSilinen elemanin adresi :%d ", delete_node(myroot, sayi));
                break;
            case 4:
                printf("\nBulmak istediginiz sayi : ");
                scanf("%d", &sayi);
                printf("\nBulunan elemanin adresi :%d ", searchtree(myroot, sayi));
                break;
            case 5:
                printf("\nBST mi ? %d", isBST(myroot));
                printf("\nMin deger : %d ", minValue(myroot));
                printf("\nMax deger : %d ", maxValue(myroot));
                printf("\nYukseklik: %d ", height(myroot));
                printf("\nSize : %d ", size(myroot));
                printf("\nSize Leaves : %d ", sizeLeaves(myroot));
                break;
            case 6:
                printf("\nTek node:");
                oddNode(myroot);
                break;
            case 7:
                printf("\nCift node:");
                evenNode(myroot);
                break;
            case 8:
                printf("\nEnter K :");
                scanf("%d", &k);
                printf("\nFinding %d th largest Node in BST : %d ", k, KthLargestUsingMorrisTraversal(myroot, k)->data);
                break;
            case 9:
                exit(1);
            default:
                printf("\nWrong choice! Try again...");
        }
    }
}
