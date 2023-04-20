#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa Dnode;
struct siswa
{
    int no;
    char nama[20];
    float nilai;
    Dnode *prev, *next;
};

void alokasi();
void bebas();
void tampil();
void insert_urut();
void delete_ttt();
void pencarian_data();
void nilaiRata2();
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
    puts("4. Nilai rata-rata kelas");
    printf("5. Keluar\n");

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
        nilaiRata2();
        fflush(stdin);
        break;
    case 5:
        exit(0);
        break;
    default :
        puts("Pilihan Anda Invalid");
        break;
    }
}

void alokasi()
{
    char nama[20];

    p = (Dnode *)malloc(sizeof(Dnode));
    if(p == NULL)
    {
        puts("alokasi gagal");
        exit(0);
    }
    else
    {
        printf("\nNo : ");
        scanf("%d", &p->no);
        printf("Nama : ");
        scanf("%s", nama);
        printf("Nilai : ");
        scanf("%f", &p->nilai);

        strcpy(p->nama, nama);
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

    printf("\nData yang telah diinputkan : \n\n");
    printf("No\tNama\tNilai\n");

    baca = head;
    while(baca != NULL)
    {
        if(baca->next != NULL)
            printf("%d\t%s\t%g\n", baca->no, baca->nama, baca->nilai);
        else
            printf("%d\t%s\t%g\n\n", baca->no, baca->nama, baca->nilai);
        baca = baca->next;
    }
}

void insert_urut()
{
    if(head == NULL)
        head = p;
    else
    {
        if(p->no <= head->no)
        {
            p->next = head;
            head->prev = p;
            head = p;
        }
        else
        {
            tail = head;
            while(tail->next != NULL)
                tail = tail->next;
            if(tail->no <= p->no)
            {
                tail->next = p;
                p->prev = tail;
            }
            else
            {
                bef = head;
                while(p->no > bef->no)
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

    if(head == NULL)
        puts("LL kosong tidak bisa delete");
    else
    {

        printf("\nNode berisi nomor berapa yang akan dihapus ? ");
        scanf("%d", &key);

        hapus = head;
        while(hapus->no != key)
        {
            if(hapus->next == NULL)
            {
                printf("Data %d tidak ada dalam LL\n", key);
                tampil();
                menu_utama();
                break;
            }
            else
                hapus = hapus->next;
        }
        if(hapus->no == head->no) // hapus awal
        {
            if(head->next == NULL)
                head = NULL;
            else
            {
                head = hapus->next;
                hapus->next->prev = NULL;
            }
        }
        else if(hapus->next == NULL) // hapus akhir
            hapus->prev->next = NULL;
        else
        {
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
        }
        bebas();
        tampil();
    }
}

void pencarian_data()
{
    int key, ketemu = 0;
    Dnode *cari;

    printf("\nNode berisi nomor berapa yang dicari ? ");
    scanf("%d", &key);

    cari = head;
    while(cari != NULL)
    {
        if(cari->no == key)
            ketemu++;
        cari = cari->next;
    }
    if(ketemu == 0)
        printf("Data %d tidak ada dalam LL\n\n", key);
    else
        printf("Data %d ketemu sebanyak %d\n\n", key, ketemu);
}

void nilaiRata2()
{
    Dnode *rata2;
    float sumNilai = 0, count = 0, mean;

    rata2 = head;
    while(rata2 != NULL)
    {
        sumNilai += rata2->nilai;
        count++;
        rata2 = rata2->next;
    }
    mean = sumNilai / count;

    printf("\nNilai rata-ratanya = %.2f\n", mean);
}
