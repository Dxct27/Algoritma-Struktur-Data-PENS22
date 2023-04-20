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
void insert_awal();
void insert_akhir();
void insert_before();
Dnode *head = NULL, *p, *tail, *bef;

int main()
{
    char jwb;

    puts("DLL insert akhir");

    do
    {
        fflush(stdin);
        alokasi();
        insert_akhir();
        fflush(stdin);
        printf("Mau lagi (y/t) ? ");
        jwb = getchar();
    }
    while(jwb == 'y' || jwb == 'Y');

    tampil();
    insert_before();
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

    printf("Isi dari DLL :\n");
    baca=head;
    while(baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
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

    if(bef->prev == NULL){
        insert_awal();
    }
    else{
        p->next = bef;
        p->prev = bef->prev;
        bef->prev->next = p;
        bef->prev = p;
    }

    tampil();
}
