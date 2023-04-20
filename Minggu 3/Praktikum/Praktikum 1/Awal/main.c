#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

void alokasi();
void insert_akhir();
void bebas();
void hapus_awal();
void tampil();

Node *head = NULL, *p, *tail, *hapus;

int main()
{
    char jwb;
    do{
        fflush(stdin);
        insert_akhir();
        fflush(stdin);
        printf("Lagi (y/t) ? ");
        jwb = getchar();
       }while(jwb == 'y' || jwb == 'Y');

    hapus_awal();
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

void insert_akhir()
{
    alokasi();
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

void bebas()
{
    free(hapus);
    hapus = NULL;
}

void hapus_awal()
{
    hapus = head;
    if(head == NULL)
        puts("SLL masih kosong");
    else{
        if(head->next == NULL){
            head = NULL;
            bebas();
        }
        else{
            head = hapus->next;
            bebas();
        }
    }
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
