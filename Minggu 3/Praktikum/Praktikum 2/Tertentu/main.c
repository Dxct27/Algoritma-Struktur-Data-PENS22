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
void insert_akhir();
void hapus_ttt();

Node *head = NULL, *p, *tail, *hapus, *phapus;

int main()
{
    char jwb;

    printf("SLL DELETE TERTENTU - data struct\n");
    printf("Linked List untuk aplikasi INSERT DI AKHIR\n");
    printf("Membentuk linked list dg Insert di akhir\n");

    do{
        fflush(stdin);
        alokasi();
        insert_akhir();
        fflush(stdin);
        printf("Ada data lagi (y/t) ? ");
        jwb = getchar();
    }while(jwb == 'y' || jwb == 'Y');

    tampil();
    fflush(stdin);
    char hps_jwb;
    printf("Mau menghapus node setelah node ttt ?  ");
    scanf("%c", &hps_jwb);
    if(hps_jwb == 'y' || hps_jwb == 'Y')
        hapus_ttt();
    tampil();
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

void insert_akhir()
{
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

void hapus_ttt()
{
    int key;
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
