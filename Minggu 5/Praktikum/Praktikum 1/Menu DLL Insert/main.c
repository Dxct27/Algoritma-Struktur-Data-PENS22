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
void menu();
void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();
Dnode *head = NULL, *p, *tail, *after, *bef;

int main()
{
    do
    {
        menu();
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

    printf("\n\nIsi dari DLL :\n");
    baca=head;
    while(baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}

void menu()
{
    int jwb;
    fflush(stdin);
    printf("\nMenu Insert\n");
    puts("1. Insert Awal");
    puts("2. Insert Akhir");
    puts("3. Insert After");
    puts("4. Insert Before");
    puts("5. Keluar");
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
    case 5:
        exit(0);
        break;
    default:
        puts("Pilihan Anda Invalid");
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
    }
    tampil();
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
    }

    tampil();
}
