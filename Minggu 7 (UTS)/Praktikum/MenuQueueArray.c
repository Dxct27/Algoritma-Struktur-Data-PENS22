#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef int itemType;
typedef struct
{
    itemType item[MAX];
    int front;
    int rear;
    int count;
}Queue;

void inisialisasi(Queue *);
int isEmpty(Queue *);
int isFull(Queue*);
void enqueue(Queue *, itemType);
itemType dequeue(Queue*);
void dataMinMax(Queue *);
void cariData(Queue *);
void tampil(Queue *);
void menu(Queue *);

int main()
{
    Queue antrian;
    inisialisasi(&antrian);
    while(1){
        menu(&antrian);
    }
    return 0;
}

void menu(Queue *q)
{
    int jwb;
    itemType x;

    printf("\nMenu QUEUE using ARRAY:\n");
    printf("1. Tambah Data\n");
    printf("2. Hapus Data\n");
    printf("3. Tampilkan data min & max\n");
    printf("4. Cari data\n");
    printf("5. Cetak isi Queue\n");
    printf("6. Keluar\n");

    printf("Masukkan pilihan Anda : ");
    scanf("%d", &jwb);

    switch (jwb)
    {
    case 1:
        fflush(stdin);
        printf("Masukkan data Anda : ");
        scanf("%d", &x);
        enqueue(q, x);
        break;
    case 2:
        printf("Item yang Anda ambil adalah %d\n", dequeue(q));
        break;
    case 3:
        dataMinMax(q);
        break;
    case 4:
        cariData(q);
        break;
    case 5:
        tampil(q);
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("Pilihan Anda Invalid");
        break;
    }
}

void inisialisasi(Queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q)
{
    if(q->count == 0)
        return 1;
    else
        return 0;
}

int isFull(Queue *q)
{
    if(q->count == MAX)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, itemType x)
{
    if(isFull(q))
        printf("Queue Penuh");
    else{
        q->item[q->rear] = x;
        q->rear = (q->rear+1) % MAX;
        q->count++;
    }
}

itemType dequeue(Queue *q)
{
    itemType temp;
    if(isEmpty(q))
        printf("Queue Kosong");
    else{
        temp = q->item[q->front];
        q->front = (q->front+1) % MAX;
        q->count--;
    }
    return temp;
}

void dataMinMax(Queue *q)
{
    int i;
    itemType min, max;
    min = max = q->item[q->front];

    i = q->front;
    while(i != q->rear)
    {
        if(q->item[i] > max)
            max = q->item[i];
        if(q->item[i] < min)
            min = q->item[i];
        i = (i+1) % MAX;
    }
    printf("\nData terkecil : %d\n", min);
    printf("Data terbesar : %d\n", max);
}

void cariData(Queue *q)
{
    int i, key, ketemu = 0;
    
    printf("Data yang dicari : ");
    scanf("%d", &key);

    i = q->front;
    while(i != q->rear)
    {
        if(q->item[i] == key){
            ketemu++;
        }
        i = (i+1) % MAX;
    }
    if(ketemu == 0)
        printf("%d tidak ada dalam Queue\n", key);
    else
        printf("%d muncul %d kali dalam Queue\n", key, ketemu);
}

void tampil(Queue *q)
{
    int i;
    if(isEmpty(q))
        printf("Queue Kosong");
    else{
        printf("\nIsi Queue saat ini adalah :\n");
        i = q->front;
        do
        {
            printf("%d\n", q->item[i]);
            i = (i+1) % MAX;
        } while (i != q->rear);
        
    }
}