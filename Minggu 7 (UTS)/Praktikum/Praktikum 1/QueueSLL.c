#include<stdio.h>
#include<stdlib.h>

typedef char itemType;
typedef struct simpul Node;
struct simpul
{
    itemType data;
    Node *next;
};

struct QueueSLL
{
    Node *front, *rear;
};


void alokasi();
void tampil(struct QueueSLL *);
int isEmpty(struct QueueSLL *);
void enqueue(struct QueueSLL *);
itemType dequeue(struct QueueSLL *);
void menu(struct QueueSLL *);

Node *p;

int main()
{
    struct QueueSLL *q = (struct QueueSLL *)malloc(sizeof(struct QueueSLL));
    q->front = NULL; 
    q->rear = NULL;

    while(1){
        menu(q);
    }
    return 0;
}

void menu(struct QueueSLL *q)
{
    int jwb;

    printf("\nMENU QUEUE using LINKED LIST :\n");
    printf("1. Mengisi Queue (ENQUEUE)\n");
    printf("2. Mengambil isi Queue (DEQUEUE)\n");
    printf("3. Menampilkan isi Queue -> FIFO\n");
    printf("4. Keluar\n\n");

    printf("Masukkan Pilihan Anda : ");
    scanf("%d", &jwb);

    switch (jwb)
    {
    case 1:
        fflush(stdin);
        enqueue(q);
        break;
    case 2:
        printf("\nItem yang Anda ambil adalah : %c\n", dequeue(q));
        break;
    case 3:
        if (isEmpty(q))
            printf("Queue kosong\n");
        else
            tampil(q);
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("\nPilihan Anda Invalid\n");
        break;
    }
}

void alokasi()
{
    p = (Node *)malloc(sizeof(Node));

    if(p==NULL){
        puts("Alokasi gagal");
        exit(0);
    }
    printf("Masukkan data Anda : ");
    scanf("%c", &p->data);
    p->next = NULL;
}

void tampil(struct QueueSLL *q)
{
    if(q->front == NULL){
        printf("Queue kosong");
    }
    else{
        Node *baca = q->front;
        while(baca != NULL){
            printf("%c\n", baca->data);
            baca = baca->next;
        }
    }
}

int isEmpty(struct QueueSLL *q)
{
    if(q->front == NULL)
        return 1;
    else
        return 0;
}

void enqueue(struct QueueSLL *q)
{
    alokasi();
    if(q->rear == NULL){
        q->front = q->rear = p;
    }
    q->rear->next = p;
    q->rear = p;
}

itemType dequeue(struct QueueSLL *q)
{
    itemType dataDequeue;
    if(isEmpty(q)){
        printf("Queue kosong\n");
    }
    else{
        dataDequeue = q->front->data;
        Node *temp = q->front;
        q->front = q->front->next;
        free(temp);
        temp = NULL;
    }
    return dataDequeue;
}