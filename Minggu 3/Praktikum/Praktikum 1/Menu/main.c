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
void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();
void hapus_awal();
void hapus_akhir();
void hapus_ttt();
void menu_SLL();
void menu_insert();
void menu_delete();

Node *head = NULL, *p, *tail, *aft, *bef, *pbef, *hapus, *phapus;

int main()
{
    int sll;

    do{
        fflush(stdin);
        menu_SLL();
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &sll);

        switch(sll){
            case 1:
                menu_insert();
                break;
            case 2:
                if(head == NULL)
                    puts("SLL masih kosong, tidak bisa delete");
                else
                    menu_delete();
                break;
            case 3:
                break;
            default:
                puts("Pilihan Anda Invalid");
        }
    }while(sll != 3);
}

void alokasi()
{
    int x;

    printf("Nilai yg akan disimpan : ");
    scanf("%d", &x);

    p = (Node *)malloc(sizeof(Node));
    if(p == NULL)
    {
        printf("Alokasi gagal");
        exit(0);
    }
    else
    {
        p->data = x;
        p->next = NULL;
    }
}

void bebas()
{
    free(hapus);
    hapus = NULL;
}

void tampil()
{
    Node *baca;

    printf("\nData yg ada dlm SLL\n");
    baca = head;
    while(baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}

void insert_awal()
{
    alokasi();
    if(head != NULL)
        p->next = head;
    head = p;
}

void insert_akhir()
{
    alokasi();
    if(head == NULL)
        head = p;
    else
    {
        tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = p;
        tail = tail->next; // bisa pakai tail = p; yang penting tail harus berada di akhir
    }
}

void insert_after()
{
    int key;

    alokasi();
    printf("Disisipkan setelah data berapa ? ");
    scanf("%d", &key);

    aft = head;
    while(aft->data != key){
        if(aft->next == NULL){
            printf("Data %d tidak tersedia", key);
            exit(0);
        }
        aft = aft->next;
    }
    p->next = aft->next;
    aft->next = p;
}

void insert_before()
{
    int key;

    alokasi();
    printf("Disisipkan sebelum data berapa ? ");
    scanf("%d", &key);

    if(head->data == key){
        p->next = head;
        head = p;
    }
    else{
        bef = head;
        while(bef->data != key){
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

void hapus_awal()
{
    hapus = head;
    if(head->next == NULL){
        head = NULL;
    }
    else{
        head = hapus->next;
    }
}

void hapus_akhir()
{
    hapus=head;
    if(head->next == NULL)
        head = hapus->next;
    else{
        while(hapus->next != NULL){
            phapus = hapus;
            hapus = hapus->next;
        }
        phapus->next = hapus->next;
    }
}

void hapus_ttt()
{
    int key;
    printf("Data yang mau dihapus : ");
    scanf("%d", &key);

    hapus=head;
    if(head->data == key)
        head = hapus->next;
    else{
        while(hapus->data != key){
            if(hapus->next == NULL){
                puts("key tidak ada");
                exit(0);
            }
            else{
                phapus = hapus;
                hapus = hapus->next;
            }
        }
        phapus->next = hapus->next;
    }
}

void menu_SLL()
{
    puts("Menu SLL");
    puts("1. Insert");
    puts("2. Delete");
    puts("3. Keluar");
}

void menu_insert()
{
    int ins;
    puts("Menu Insert");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. Sebelum");
    puts("4. Sesudah");

    printf("Masukkan pilihan Anda : ");
    scanf("%d", &ins);

    switch(ins){
    case 1:
        insert_awal();
        break;
    case 2:
        insert_akhir();
        break;
    case 3:
        if(head == NULL)
            puts("SLL masih kosong");
        else
            insert_before();
        break;
    case 4:
        if(head == NULL)
            puts("SLL masih kosong");
        else
            insert_after();
        break;
    default:
        puts("Pilihan Anda Invalid");
    }
    tampil();
}

void menu_delete()
{
    int del;
    puts("Menu DELETE");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. Tertentu");

    printf("Masukkan pilihan Anda : ");
    scanf("%d", &del);

    switch(del){
    case 1:
        hapus_awal();
        break;
    case 2:
        hapus_akhir();
        break;
    case 3:
        hapus_ttt();
        break;
    default:
        puts("Pilihan Anda Invalid");
    }
    bebas();
    tampil();
}
