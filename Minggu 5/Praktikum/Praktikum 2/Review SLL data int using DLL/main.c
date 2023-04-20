#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul
{
    int data;
    Dnode *prev, *next;
};

void alokasi();
void bebas();
void tampil();
void insert_urut();
void delete_ttt();
void pencarian_data();
void menu_utama();

Dnode *head = NULL, *p, *tail, *bef, *hapus;

int main()
{
    do
    {
        menu_utama();
    }
    while(1);
}

void menu_utama()
{
    int jwb;

    fflush(stdin);
    printf("\nMENU UTAMA :\n");
    puts("1. Penambahan secara terurut");
    puts("2. Pencarian data");
    puts("3. Penghapusan data");
    printf("4. Keluar\n");

    printf("Masukkan pilihan Anda : ");
    scanf("%d", &jwb);

    switch(jwb)
    {
    case 1:
        alokasi();
        insert_urut();
        break;
    case 2:
        pencarian_data();
        break;
    case 3:
        delete_ttt();
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
    p = (Dnode *)malloc(sizeof(Dnode));
    if(p == NULL)
    {
        puts("alokasi gagal");
        exit(0);
    }
    else
    {
        printf("Masukkan datanya : ");
        scanf("%d", &p->data);
        p->prev = NULL;
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
    Dnode *baca;

    printf("\nIsi dari DLL\n");
    baca = head;
    while(baca != NULL)
    {
        printf("%d ", baca->data);
        baca = baca->next;
    }
}

void insert_urut()
{
    if(head == NULL)    // initiate;
        head = p;
    else
    {
        if(p->data <= head->data)   // awal;
        {
            p->next = head;
            head->prev = p;
            head = p;
        }
        else
        {
            tail = head;    // akhir;
            while(tail->next != NULL)
                tail = tail->next;
            if(tail->data <= p->data)
            {
                tail->next = p;
                p->prev = tail;
            }
            else
            {
                bef = head;     // ttt;
                while(p->data > bef->data)
                {
                    bef = bef->next;
                }
                p->next = bef;
                p->prev = bef->prev;
                bef->prev->next = p;
                bef->prev = p;
            }
        }
    }
    tampil();
}

void delete_ttt()
{
    int key;

    printf("Masukkan data yang mau dihapus : ");
    scanf("%d", &key);

    hapus = head;
    while(hapus->data != key)
    {
        if(hapus->next == NULL)
            puts("Key tidak ada");
        else
            hapus = hapus->next;
    }
    if(hapus->data == head->data)
    {
        if(head->next == NULL)
            head = NULL;
        else
        {
            head = hapus->next;
            hapus->next->prev = NULL;
        }
    }
    else if(hapus->next == NULL)
        hapus->prev->next = NULL;
    else
    {
        hapus->prev->next = hapus->next;
        hapus->next->prev = hapus->prev;
    }
    bebas();
    tampil();
}

void pencarian_data()
{
    int key, ketemu = 0;
    Dnode *cari;

    printf("Masukkan data yang mau dicari : ");
    scanf("%d", &key);

    cari = head;
    while(cari->next != NULL)
    {
        if(cari->data == key)
            ketemu++;
        cari = cari->next;
    }
    printf("Data %d ketemu sebanyak %d\n\n", key, ketemu);
}

