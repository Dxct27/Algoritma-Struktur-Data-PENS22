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
void insert_urut();
void delete_ttt();
void pencarian_data();
void menu_utama();

Node *head=NULL, *p, * tail, *bef, *pbef, *hapus, *phapus;

int main()
{
    int pilihan;
    do
    {
        fflush(stdin);
        menu_utama();
        printf("Masukkan pilihan anda : ");
        scanf("%d", &pilihan);
        switch(pilihan)
        {
        case 1:
            alokasi();
            insert_urut();
            break;
        case 2:
            pencarian_data();
            break;
        case 3:
            fflush(stdin);
            delete_ttt();
            break;
        case 4:
            break;
        default :
            puts("Pilihan anda invalid");
        }
    }
    while(pilihan != 4);
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
    baca = head;
    while(baca != NULL)
    {
        printf("%d ", baca->data);
        baca = baca->next;
    }
    printf("\n\n");
}

void insert_urut()
{
    if(head == NULL)
        head = p;
    else
    {
        if(head->data >= p->data)
        {
            p->next = head;
            head = p;
        }
        else
        {
            tail = head;
            while(tail->next != NULL)
                tail = tail->next;
            if(tail->data < p->data)
            {
                tail->next = p;
                tail = tail->next;
            }
            else
            {
                bef = head;
                while(bef->data < p->data)
                {
                    pbef = bef;
                    bef = bef->next;
                }
                p->next = bef;
                pbef->next = p;
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
    if(head->data == key)
        head = hapus->next;
    else
    {
        while(hapus->data != key)
        {
            if(hapus->next == NULL)
            {
                printf("Data %d tidak ada di LL\n", key);
                break;
            }
            else
            {
                phapus = hapus;
                hapus = hapus->next;
            }
        }
        phapus->next = hapus->next;
    }
    tampil();
    bebas();
}

void pencarian_data()
{
    int key, ketemu = 0;
    Node *cari;

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

void menu_utama()
{
    puts("MENU UTAMA :");
    puts("1. Penambahan secara terurut");
    puts("2. Pencarian data");
    puts("3. Penghapusan data");
    puts("4. Keluar");
}
