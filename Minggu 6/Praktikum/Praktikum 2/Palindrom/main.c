#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int count;
} stack;

void insisiasiVoid(stack *);
int isEmpty(stack *);
int isFull(stack *);
void push(itemType, stack *);
itemType pop(stack *);
void palindrom(itemType [], stack *);

int main()
{
    stack tumpukan;
    char jwb;

    puts("MENGECEK PALINDROM");
    do{
        itemType input[MAX];
        fflush(stdin);
        printf("Masukkan kata yang akan dicek : ");
        gets(input);

        palindrom(input, &tumpukan);
        fflush(stdin);
        printf("\nMau coba lagi (y/t) ? ");
        scanf("%c", &jwb);
    }while(jwb == 'y' || jwb == 'Y');
}

void palindrom(itemType input[], stack *s)
{
    itemType r[MAX];
    int i, j = 0;

    for(i = 0; i < strlen(input); i++){
        char c = input[i];
        push(c, s);
    }

    while(s->count != 0){
        r[j] = pop(s);
        j++;
    }
    r[j] ='\0';

    if(strcmpi(input, r))
        printf("%s adalah BUKAN PALINDROM\n", input);
    else
        printf("%s adalah PALINDROM\n", input);
}

void insisiasiVoid(stack *s)
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
    else{
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop(stack *s)
{
    itemType temp;
    if(isEmpty(s))
        puts("Stack kosong/underflow");
    else{
        s->count--;
        temp = s->data[s->count];
    }
    return temp;
}

