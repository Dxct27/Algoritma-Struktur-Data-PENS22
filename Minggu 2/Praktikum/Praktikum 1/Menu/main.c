#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

void alokasi();
void awal();
void akhir();
void after();
void before();
void tampil();
void menu();

Node *head = NULL, *p, *tail, *aft, *bef, *pbef;

int main()
{
    int input;
    do{
        fflush(stdin);
        menu();
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &input);
        switch(input){

        case 1:
            awal();
            tampil();
            break;
        case 2:
            akhir();
            tampil();
            break;
        case 3:
            if(head != NULL)
                after();
            else
                puts("SLL masih kosong, tidak bisa insert after");
            tampil();
            break;
        case 4:
            if(head != NULL)
                before();
            else
                puts("SLL masih kosong, tidak bisa inserrt before");
            tampil();
            break;
       }
    }while(input != 5);
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
    alokasi();
    if(head == NULL)
        head = p;
    else
        p->next = head;
    head = p;
}

void akhir()
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

void after()
{
    int n;

    alokasi();
    printf("Disisipkan setelah data berapa ? ");
    scanf("%d", &n);

    aft = head;
    while(aft->data != n){
        if(aft->next == NULL){
            printf("Data %d tidak tersedia", n);
            exit(0);
        }
        aft = aft->next;
    }
    p->next = aft->next;
    aft->next = p;
}

void before()
{
    int n;

    alokasi();
    printf("Disisipkan sebelum data berapa ? ");
    scanf("%d", &n);

    if(head->data == n){
        p->next = head;
        head = p;
    }
    else{
        bef = head;
        while(bef->data != n){
            pbef = bef;
            if(bef->next == NULL){
                puts("Data tidak tersedia");
                exit(0);
            }
            bef = bef->next;
        }
        p->next = bef;
        pbef->next = p;
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

void menu()
{
    puts("Menu Insert");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. After");
    puts("4. Before");
    puts("5. Keluar");
}
