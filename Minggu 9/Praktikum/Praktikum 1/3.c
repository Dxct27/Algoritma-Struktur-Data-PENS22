#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

void reverseKata(int);

char kata[MAX];

int main()
{
    
    printf("Program untuk membalik suatu kalimat\n");
    printf("Masukkan kalimat : ");
    scanf("%s", kata);

    reverseKata(strlen(kata));
    

    return 0;
}

void reverseKata(int n)
{
    if(n<0)
        return;
    else{
        printf("%c", kata[n]);
        reverseKata(n-1);
    }
}