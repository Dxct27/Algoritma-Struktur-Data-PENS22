#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

void alokasi();
void akhir();
void after();
void tampil();

Node *head = NULL, *p, *tail, *aft;

int main()
{
    char jwb;
    puts("Single Linked List - Insert After");

    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Lagi (y/t) ? ");
        jwb = getchar();
    }while(jwb == 'y' || jwb == 'Y');

    tampil();

    after();
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

void akhir()
{
    if(head == NULL)
        head = p;
    else{
        tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = p;
        tail = tail->next; // bisa pakai tail = p; yang penting tail harus berada di akhir
    }
}

void after()
{
    int n;

    alokasi();
    printf("Disisipkan setelah data berapa ? ");
    scanf("%d", &n);

    if(head == NULL)
        puts("SLL masih kosong, tidak bisa insert after");
    else{
        aft = head;
        while(aft->data != n){
            if(aft->next == NULL){
                printf("Data %d tidak tersedia", n);
                exit(0);
            }
            else
            aft = aft->next;
        }
        p->next = aft->next;
        aft->next = p;
    }

    tampil();
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
