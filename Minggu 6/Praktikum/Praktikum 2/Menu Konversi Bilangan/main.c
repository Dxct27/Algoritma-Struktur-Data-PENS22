#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int itemType;
typedef struct
{
    itemType data[MAX];
    int count;
} stack;

void inisiasiStack(stack *);
int isEmpty(stack *);
int isFull(stack *);
void push(itemType, stack *);
itemType pop(stack *);
void menu(int);
void biner(int);
void oktal(int);
void heksa(int);

int i, j, n, data;
stack tumpukan;

int main()
{
    int desimal;
    puts("KONVERSI BILANGAN DESIMAL");
    printf("Masukkan bil desimal yg akan dikonversi : ");
    scanf("%d", &desimal);

    inisiasiStack(&tumpukan);

    do
    {
        menu(desimal);
    }
    while(1);
}

void menu(int bildes)
{
    int jwb;
    printf("\nMENU KONVERSI:\n");
    puts("1. BINER");
    puts("2. OKTAL");
    puts("3. HEKSADESIMAL");
    puts("4. Keluar");

    printf("\nMasukkan pilihan Anda : ");
    scanf("%d", &jwb);

    switch(jwb)
    {
    case 1:
        biner(bildes);
        break;
    case 2:
        oktal(bildes);
        break;
    case 3:
        heksa(bildes);
        break;
    case 4:
        exit(0);
        break;
    default :
        printf("Pilihan Anda Invalid");
    }
}

void biner(int input)
{
    for(i = 1, n = input; n>0;n=n/2, i++){
        data = n%2;
        push(data, &tumpukan);
    }

    printf("Hasil konversi %d ke BINER = ", input);
    for(j = i; j>1; j--)
        printf("%d", pop(&tumpukan));
    printf("\n");
}

void oktal(int input)
{
    for(i = 1, n = input; n>0;n=n/8, i++){
        data = n%8;
        push(data, &tumpukan);
    }

    printf("Hasil konversi %d ke OKTAL = ", input);
    for(j = i; j>1; j--)
        printf("%d", pop(&tumpukan));
    printf("\n");
}

void heksa(int input)
{
    for(i = 1, n = input; n>0;n=n/16, i++){
        data = n%16;
        push(data, &tumpukan);
    }

    printf("Hasil konversi %d ke HEKSADESIMAL = ", input);
    for(j = i; j>1; j--){
        int p = pop(&tumpukan);
        if(p<=9)
            printf("%d", p);
        else if(p==10)
            printf("A");
        else if(p==11)
            printf("B");
        else if(p==12)
            printf("C");
        else if(p==13)
            printf("D");
        else if(p==14)
            printf("E");
        else if(p==15)
            printf("F");
    }
    printf("\n");
}

void inisiasiStack(stack *s)
{
    s->count = 0;
}

int isEmpty(stack *s)
{
    if(s->count == 0)
        return 1;
    else
        return 0;
}

int isFull(stack *s)
{
    if(s->count == MAX)
        return 1;
    else
        return 0;
}

void push(itemType x, stack *s)
{
    if(isFull(s))
        puts("Stack penuh/overflow");
    else
    {
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop(stack *s)
{
    itemType temp;
    if(isEmpty(s))
        puts("Stack kosong/underflow");
    else
    {
        s->count--;
        temp = s->data[s->count];
        return temp;
    }
}

