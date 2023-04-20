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

Dnode *head = NULL, *p;

int main()
{
    char jwb;

    puts("DLL insert awal");

    do
    {
        fflush(stdin);
        alokasi();
        insert_awal();
        fflush(stdin);
        printf("Mau lagi (y/t) ? ");
        jwb = getchar();
    }
    while(jwb == 'y' || jwb == 'Y');

    tampil();
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
