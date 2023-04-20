#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};

void alokasi();
void bebas();
void tampil();
void push();
void pop();
void menu();

Node *head = NULL, *p, *hapus;

int main()
{
    do{
        menu();
    }while(1);
}

void menu()
{
    int jwb;

    printf("\nMENU STACK using ARRAY :\n");
    puts("1. Mengisi Stack (PUSH)");
    puts("2. Mengambil isi Stack (POP)");
    puts("3. Menampilkan isi Stack -> LIFO");
    printf("4. Keluar\n\n");

    fflush(stdin);
    printf("Masukkan pilihan Anda : ");
    scanf("%d", &jwb);
    switch(jwb)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        tampil();
        break;
    case 4:
        exit(0);
        break;
    default :
        puts("Pilihan Anda Invalid");
        break;
    }
}

void alokasi()
{
    p = (Node *)malloc(sizeof(Node));

    if(p == NULL)
        exit(0);
    printf("Masukkan datanya : ");
    scanf("%d", &p->data);
    p->next = NULL;
}

void bebas()
{
    free(hapus);
    hapus = NULL;
}

void tampil()
{
    Node *baca;

    printf("Isi dari stack =\n");
    baca = head;
    while(baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
    printf("\n\n");
}

void push()
{
    alokasi();
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
}

void pop()
{
    hapus = head;
    printf("Data yang diambil dari stack = %d\n", head->data);
    if(head->next == NULL){
        head = NULL;
    }
    else{
        head = hapus->next;
    }
}
