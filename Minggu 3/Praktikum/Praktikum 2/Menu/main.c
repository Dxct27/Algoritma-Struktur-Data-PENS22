#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa Node;
struct siswa{
    int no;
    char nama[20];
    float nilai;
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

void bebas()
{
    free(hapus);
    hapus = NULL;
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

void insert_awal()
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

void insert_akhir()
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
        tail = tail->next;
    }
}

void insert_after()
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

void insert_before()
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

void hapus_awal()
{
    hapus=head;
    if(head->next == NULL){
        head = NULL;
        bebas();
    }
    else{
        head = hapus->next;
        bebas();
    }
}

void hapus_akhir()
{
    hapus=head;
    if(head->next == NULL){
        head = NULL;
        bebas();
    }
    else{
        while(hapus->next != NULL){
            phapus = hapus;
            hapus = hapus->next;
        }
        phapus->next = NULL;
        bebas();
    }
}

void hapus_ttt()
{
    int key;

    printf("Mau menghapus node setelah node ttt ?  ");
    printf("Node yg akan dihapus ? ");
    scanf("%d", &key);

    hapus=head;
    while(hapus->no != key){
        if(hapus->next == NULL)
            puts("key tidak ada");
        else{
            phapus = hapus;
            hapus = phapus->next;
        }
    }
    phapus->next = hapus->next;
    bebas();
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
        insert_before();
        break;
    case 4:
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
    tampil();
}

