#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul
{
    int data;
    Dnode *prev, *next;
};

void alokasi();
void tampil();
void bebas();
void menu_utama();
void menu_insert();
void menu_delete();
void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();
void hapus_awal();
void hapus_akhir();
void hapus_ttt();

Dnode *head = NULL, *p, *tail, *after, *bef, *hapus;

int main()
{
    do
    {
        menu_utama();
    }
    while(1);
}

void alokasi()
{


    p = (Dnode *)malloc(sizeof(Dnode));
    if(p == NULL)
    {
        puts("alokasi gagal");
        exit(0);
    }
    else
    {
        p->next = NULL;
        p->prev = NULL;
        printf("Data yang mau disimpan? ");
        scanf("%d", &p->data);
    }
}

void tampil()
{
    Dnode *baca;

    printf("\nIsi dari DLL :\n");
    baca=head;
    while(baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
    if(head == NULL)
        puts("DLL kosong");
}

void bebas()
{
    free(hapus);
    hapus = NULL;
}

void menu_utama()
{
    int jwb;
    fflush(stdin);
    printf("\nMenu Utama\n");
    puts("1. Insert");
    puts("2. Delete");
    puts("3. Keluar");
    printf("Masukkan pilihan Anda : ");
    scanf("%d", &jwb);

    switch(jwb)
    {
    case 1:
        menu_insert();
        break;
    case 2:
        if(head == NULL)
            puts("DLL masih kosong tidak bisa delete");
        else
            menu_delete();
        break;
    case 3:
        exit(0);
        break;
    default:
        puts("Pilihan Anda Invalid");
        break;
    }
}

void menu_insert()
{
    int jwb;
    fflush(stdin);
    printf("\nMenu Insert\n");
    puts("1. Insert Awal");
    puts("2. Insert Akhir");
    puts("3. Insert After");
    puts("4. Insert Before");
    printf("Masukkan pilihan Anda : ");
    scanf("%d", &jwb);

    switch(jwb)
    {
    case 1:
        alokasi();
        insert_awal();
        break;
    case 2:
        alokasi();
        insert_akhir();
        break;
    case 3:
        if(head == NULL)
            puts("DLL masih kosong lakukan insert awal/akhir dulu");
        else
            insert_after();
        break;
    case 4:
        if(head == NULL)
            puts("DLL masih kosong lakukan insert awal/akhir dulu");
        else
            insert_before();
        break;
    default :
        puts("Pilihan Anda Invalid");
        break;
    }
}

void menu_delete()
{
    int jwb;
    fflush(stdin);
    printf("\nMenu Delete\n");
    puts("1. Delete Awal");
    puts("2. Delete Akhir");
    puts("3. Delete Tertentu");

    printf("Masukkan Pilihan Anda : ");
    scanf("%d", &jwb);

    switch(jwb)
    {
    case 1:
        hapus_awal();
        break;
    case 2:
        hapus_akhir();
        break;
    case 3:
        hapus_ttt();
        break;
    }
}

void insert_awal()
{
    if(head != NULL)
    {
        p->next = head;
        head->prev = p;
    }
    head = p;
    tampil();
}

void insert_akhir()
{
    if(head == NULL)
        insert_awal();
    else
    {
        tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = p;
        p->prev = tail;
        tampil();
    }
}

void insert_after()
{
    int key;

    puts("Insert After");
    alokasi();
    printf("Sisip after brp ? ");
    scanf("%d", &key);

    after = head;
    while(after->data != key)
    {
        if(after->next == NULL)
        {
            puts("key tidak ada");
            exit(0);
        }
        else
        {
            after = after->next;
        }
    }
    p->next = after->next;
    p->prev = after;
    if(after->next != NULL)
        after->next->prev = p;
    after->next = p;
    tampil();
}

void insert_before()
{
    int key;

    puts("Insert Before");
    alokasi();
    printf("Sisip before brp ? ");
    scanf("%d", &key);

    bef = head;
    while(bef->data != key)
    {
        if(bef->next == NULL)
        {
            puts("key tidak ada");
            exit(0);
        }
        else
        {
            bef = bef->next;
        }
    }

    if(bef->prev == NULL)
    {
        insert_awal();
    }
    else
    {
        p->next = bef;
        p->prev = bef->prev;
        bef->prev->next = p;
        bef->prev = p;
    tampil();
    }
}

void hapus_awal()
{
    hapus = head;
    if(head->next == NULL)
        head = NULL;
    else
    {
        head = hapus->next;
        hapus->next->prev = NULL;
    }
    bebas();
    tampil();
}

void hapus_akhir()
{
    hapus = head;
    if(head->next == NULL)
        head = NULL;
    else
    {
        while(hapus->next != NULL)
            hapus = hapus->next;
        hapus->prev->next = NULL;
    }
    bebas();
    tampil();
}

void hapus_ttt()
{
    int key;

    printf("Data yag mau dihapus ? ");
    scanf("%d", &key);

    hapus = head;
    while(hapus->data != key)
    {
        if(hapus->next == NULL)
        {
            puts("key tidak ada");
            exit(0);
        }
        else
        {
            hapus = hapus->next;
        }
    }
    if(hapus->data == head->data)
        hapus_awal();
    else if(hapus->next == NULL)
        hapus_akhir();
    else{
        hapus->prev->next = hapus->next;
        hapus->next->prev = hapus->prev;
        bebas();
        tampil();
    }
}
