#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa Node;
struct siswa
{
    int no;
    char nama[20];
    float nilai;
    Node *next;
};

void alokasi();
void tampil();
void menu();
void awal();
void akhir();
void after();
void before();

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
    int no;
    char nama[20];
    float nilai;

    p = (Node *)malloc(sizeof(Node));
    if(p == NULL)
    {
        puts("Alokasi gagal");
        exit(0);
    }
    else
    {
        printf("\nNo\t : ");
        scanf("%d", &no);
        printf("Nama\t : ");
        scanf("%s", nama);
        printf("Nilai \t : ");
        scanf("%f", &nilai);

        p->no = no;
        strcpy(p->nama, nama);
        p->nilai = nilai;
        p->next = NULL;
    }
}

void tampil()
{
    Node *baca;

    printf("\nData yang telah diinputkan : \n");
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

void menu()
{
    printf("Menu Insert\n");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. After");
    puts("4. Before");
    puts("5. Keluar");
}

void awal()
{
    alokasi();

    if(head == NULL)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
}

void akhir()
{
    alokasi();

    if(head == NULL)
    {
        head = p;
    }
    else
    {
        tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = p;
        tail = tail->next;
    }
}

void after()
{
    int key;

    alokasi();
    fflush(stdin);
    printf("Data tsb disisipkan setelah nomor berapa : ");
    scanf("%d", &key);

    aft = head;
    while(aft->no != key)
    {
        if(aft->next == NULL)
        {
            puts("Key tidak ada");
            exit(0);
        }
        else
        {
            aft = aft->next;
        }
    }
    p->next = aft->next;
    aft->next = p;
}

void before()
{
    int key;

    alokasi();
    fflush(stdin);
    printf("Data tsb akan disisipkan sebelum nomor berapa : ");
    scanf("%d", &key);

    bef = head;
    while(bef->no != key)
    {
        if(bef->next == NULL)
        {
            puts("Key tidak ada");
            exit(0);
        }
        else
        {
            pbef = bef;
            bef = bef->next;
        }
    }
    p->next = bef;
    pbef->next = p;
}
