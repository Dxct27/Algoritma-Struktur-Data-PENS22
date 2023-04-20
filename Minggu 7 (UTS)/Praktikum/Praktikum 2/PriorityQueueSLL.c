#include<stdio.h>
#include<stdlib.h>

typedef char itemType;
typedef struct simpul Node;
struct simpul
{
    itemType data;
    int priority;
    Node *next;
};

struct QueueSLL{
    Node *front, *rear;
}QueueSLL;

void alokasi();
int isEmpty(struct QueueSLL *);
void enqueue(struct QueueSLL *);
itemType dequeue(struct QueueSLL *);
void tampil(struct QueueSLL *);
void menu(struct QueueSLL *);

Node *p, *bef, *pbef;

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

    printf("\nMENU PRIORITY QUEUE using LINKED LIST :\n");
    printf("1. Mengisi Queue\n");
    printf("2. Mengambil isis Queue\n");
    printf("3. Menampilkan isis Queue\n");
    printf("4. Keluar\n");

    printf("Masukkan pilihan Anda : ");
    scanf("%d", &jwb);

    switch (jwb)
    {
    case 1:
        fflush(stdin);
        enqueue(q);
        break;
    case 2:
        printf("\nItem yang Anda ambil adalah %c\n", dequeue(q));
        break;
    case 3:
        tampil(q);
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Pilihan Anda Invalid\n");
        break;
    }

}

void alokasi()
{
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL){
        printf("Alokasi Gagal");
        exit(0);
    }
    else{
        printf("Masukkan data Anda : ");
        scanf("%c", &p->data);
        fflush(stdin);
        printf("Nilai prioritasnya : ");
        scanf("%d", &p->priority);
        p->next = NULL;
    }
}

void tampil(struct QueueSLL *q)
{
    Node *baca;
    if(isEmpty(q)){
        printf("Queue Kosong");
    }
    else{
        baca = q->front;
        printf("\nIsi Queue saat ini adalah :\n");
        printf("Data\tPrioritas\n");
        while(baca != NULL){
            printf("%c\t%d\n", baca->data, baca->priority);
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

    if(isEmpty(q)){
        q->front = q->rear = p; // initiate when kosongan;
    }
    else{
        if(q->front->priority > p->priority){   //awal;
            p->next = q->front;
            q->front = p;
        }
        else{
            if (q->rear->priority <= p->priority){   //akhir;
                q->rear->next = p;
                q->rear = p;
            }
            else{
                bef = q->front;     //ttt;
                while (p->priority >= bef->priority){
                    pbef = bef;
                    bef = bef->next;
                }
                p->next = bef;
                pbef->next = p;
            }
        }
    }

}

itemType dequeue(struct QueueSLL *q)
{
    itemType dataDequeue;
    if(isEmpty(q)){
        printf("Queue Kosong");
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