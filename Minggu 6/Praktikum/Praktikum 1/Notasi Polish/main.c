#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

typedef char itemType;
typedef struct
{
    itemType data [MAX];
    int count;
} stack;

void inisialisasiStack(stack *);
int isFull(stack *);
int isEmpty(stack *);
void push(itemType, stack *);
itemType pop(stack *);
void menu();
void tampil(stack *);
int derajad(itemType);

int main()
{
    char jwb;
    puts("MENGUBAH NOTASI INFIX MENJADI POSTFIX");
    printf("DENGAN MEMANFAATKAN STRUKTUR STACK\n\n");

    do
    {
        menu();

        fflush(stdin);
        printf("\nMau mencoba lagi (y/t) ? ");
        scanf("%c", &jwb);
    }
    while(jwb == 'y' || jwb == 'Y');
}

void menu()
{
    stack tumpukan, *p = &tumpukan;
    char s[20], *r = s;

    inisialisasiStack(&tumpukan);
    printf("Masukan ekspresi dalam notasi infix : ");
    scanf("%s", s);

    while(*r != '\0')
    {
        if(isalnum(*r))
            printf("%c ", *r);
        else if(*r == '(')
            push(*r, &tumpukan);
        else if(*r == ')')
        {
            while(p->count != 0){
                itemType item = pop(&tumpukan);
                if(item == '(')
                    break;
                else
                    printf("%c ", item);
            }
        }
        else
        {
            while(!isEmpty(&tumpukan) && derajad(r) <= derajad(p->data[p->count - 1]))
                pop(&tumpukan);
            push(*r, &tumpukan);
        }
        r++;
    }
    while(!isEmpty(&tumpukan))
        printf("%c ", pop(&tumpukan));
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
        puts("Stack kosong");
    else
    {
        s->count--;
        temp = s->data[s->count];
        if(temp != '(')
            return temp;
    }
}

void tampil(stack *s)
{
    if(isEmpty(s))
        puts("Stack Kosong");
    else
    {
        printf("\nIsi stack saat ini adalah :\n");
        for(int i = s->count - 1; i>= 0; --i)
        {
            printf("%c\n", s->data[i]);
        }
    }
}

int derajad(itemType x)
{
    if(x == '^')
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return 0;
}

