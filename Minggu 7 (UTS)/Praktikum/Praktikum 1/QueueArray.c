#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef char itemType;
typedef struct {
    itemType item[MAX];
    int count;
    int front;
    int rear;
}Queue;

void inisialisasi(Queue *);
int isFull(Queue *);
int isEmpty(Queue *);
void enqueue(Queue *, itemType);
itemType dequeue(Queue *);
void tampil(Queue *);
void menu(Queue *);


int main()
{
    
    Queue antrian;
    inisialisasi(&antrian);
    while(1){
        menu(&antrian);
    }
}

void menu(Queue *q)
{
    int jwb;
    itemType x;

    printf("\nMENU QUEUE using ARRAY:\n");
    printf("1. Mengisi Queue <ENQUEUE>\n");
    printf("2. Mengambil isi Queue <DEQUEUE>\n");
    printf("3. Menampilkan isi Queue -> FIFO\n");
    printf("4. Keluar\n");

    printf("Masukkan Pilihan Anda : ");
    scanf("%d", &jwb);

    switch (jwb)
    {
    case 1:
        fflush(stdin);
        printf("Masukkan data Anda : ");
        scanf("%c", &x);
        enqueue(q, x);
        break;
    case 2:
        printf("Item yang Anda ambil adalah %c", dequeue(q));
        break;
    case 3:
        tampil(q);
        break;
    case 4:
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

int isFull(Queue *q)
{
    if(q->count == MAX)
        return 1;
    else
        return 0;
}

int isEmpty(Queue *q)
{
    if (q->count == 0)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, itemType x)
{
    if(isFull(q))
        printf("Queue penuh, data tidak dapat disimpan\n");
    else{
        q->item[q->rear] = x;
        q->rear = (q->rear+1) % MAX;
        q->count++;
    }
}

itemType dequeue(Queue *q)
{
    itemType temp;
    if(isEmpty(q)){
        printf("Queue kosong, tidak dapat mengambil data\n");
        return ' ';
    }
    else{
        temp = q->item[q->front];
        q->front = (q->front+1) % MAX;
        q->count--;
        return (temp);
    }
}

void tampil(Queue *q)
{
    int i;
    if(isEmpty(q))
        printf("Queue kosong");
    else{
        printf("\nIsi Queue saat ini adalah :\n");
        i = q->front;
        do{
            printf("%c\n", q->item[i]);
            i = (i+1) % MAX;
        }while(i != q->rear);
    }
}