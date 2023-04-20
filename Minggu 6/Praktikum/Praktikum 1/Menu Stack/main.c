#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef char itemType;
typedef struct{
    itemType data [MAX];
    int count;
}stack;

void inisialisasiStack(stack *);
int isFull(stack *);
int isEmpty(stack *);
void push(itemType, stack *);
itemType pop(stack *);
void menu();
void tampil(stack *);

int main()
{
    do{
        menu();
    }while(1);
}

void menu()
{
    stack tumpukan;
    itemType x;
    int jwb;

    printf("\nMENU STACK using ARRAY :\n");
    puts("1. Mengisi Stack (PUSH)");
    puts("2. Mengambil isi Stack (POP)");
    puts("3. Menampilkan isi Stack -> LIFO");
    printf("4. Keluar\n\n");

    fflush(stdin);
    printf("Masukkan pilihan Anda : ");
    scanf("%d", &jwb);
    switch(jwb)
    {
    case 1:
        if(isEmpty(&tumpukan))
            inisialisasiStack(&tumpukan);
        fflush(stdin);
        printf("Masukkan data Anda : ");
        scanf("%c", &x);
        push(x, &tumpukan);
        break;
    case 2:
        pop(&tumpukan);
        break;
    case 3:
        tampil(&tumpukan);
        break;
    case 4:
        exit(0);
        break;
    default :
        puts("Pilihan Anda Invalid");
        break;
    }

}

void inisialisasiStack(stack *s)
{
    s->count = 0;
}

int isFull(stack *s)
{
    if(s->count == MAX)
        return 1;
    else
        return 0;
}

int isEmpty(stack *s)
{
    if(s->count == 0)
        return 1;
    else
        return 0;
}

void push(itemType x, stack *s)
{
    if(isFull(s))
        puts("Stack penuh");
    else{
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop(stack *s)
{
    if(isEmpty(s))
        puts("Stack kosong");
    else
        s->count--;
        return s->data[s->count];

}

void tampil(stack *s)
{
    if(isEmpty(s))
        puts("Stack Kosong");
    else{
        printf("\nIsi stack saat ini adalah :\n");
        for(int i = s->count - 1; i>= 0; --i){
            printf("%c\n", s->data[i]);
        }
    }
}
