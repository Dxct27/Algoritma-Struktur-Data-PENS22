#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

void alokasi();
void awal();
void tampil();

Node *head = NULL, *p;

int main()
{
    char jwb;
    puts("Single Linked List - Insert Awal");

    do{
        fflush(stdin);
        alokasi();
        awal();
        fflush(stdin);
        printf("Lagi (y/t) ? ");
        jwb = getchar();
    }while(jwb == 'y' || jwb == 'Y');

    tampil();
}

void alokasi()
{
    int x;

    printf("Nilai yg akan disimpan : ");
    scanf("%d", &x);

    p = (Node *)malloc(sizeof(Node));
    if(p == NULL){
        printf("Alokasi gagal");
        exit(0);
    }
    else{
        p->data = x;
        p->next = NULL;
    }
}

void awal()
{
    if(head == NULL)
        head = p;
    else
        p->next = head;
    head = p;
}

void tampil()
{
    Node *baca;

    printf("\nData yg ada dlm SLL\n");
    baca = head;
    while(baca != NULL){
        printf("%d\n", baca->data);
        baca = baca->next;
    }

}
