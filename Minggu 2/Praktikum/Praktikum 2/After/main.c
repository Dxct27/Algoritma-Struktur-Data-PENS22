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
void akhir();
void after();
void tampil();

Node *head=NULL, *p, *tail, *aft;

int main()
{
    char jwb;
    puts("Linked List untuk aplikasi INSERT AFTER");
    puts("Membentuk linked list dg Insert di akhir");

    do
    {
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Ada data lagi (y/t) ? ");
        jwb = getchar();
        printf("\n");
    }
    while(jwb == 'y' || jwb == 'Y');

    after();

    tampil();
}

void akhir()
{
    if(head == NULL)
        head = p;
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
    int n;
    char jwb;

    fflush(stdin);
    printf("Ingin memasukkan data setelah data ttt (y/t) ? ");
    scanf("%c", &jwb);

    // can use while for multiple data input
    // while(jwb == 'y' || jwb == 'Y')
    if(jwb == 'y' || jwb == 'Y')
    {
        alokasi();

        printf("Data tsb disisipkan setelah nomor berapa : ");
        scanf("%d", &n);

        aft = head;
        while(aft->no != n)
        {
            if(aft->next == NULL)
            {
                puts("key tidak ada");
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
}

void alokasi()
{
    p= (Node *)malloc(sizeof(Node));
    if(p == NULL)
        puts("Alokasi gagal");
    else
    {
        int no;
        char nama[20];
        float nilai;

        printf("No\t : ");
        scanf("%d", &no);
        printf("Nama\t : ");
        scanf("%s", nama);
        printf("Nilai\t : ");
        scanf("%f", &nilai);

        p->no = no;
        strcpy(p->nama, nama);
//        p->nama = nama; gaiso error
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
        printf("%d\t%s\t%g\t\n", baca->no, baca->nama, baca->nilai);
        baca = baca->next;
    }
}
