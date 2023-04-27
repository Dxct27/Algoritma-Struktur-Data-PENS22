#include<stdio.h>
#include<stdlib.h>

int fpb(int, int);

int main()
{
    int bil1, bil2;

    printf("Program mencari FPB menggunakan Rekursi\n");
    printf("Masukkan bil1 : ");
    scanf("%d", &bil1);
    printf("Masukkan bil2 : ");
    scanf("%d", &bil2);

    printf("FPB dari %d dan %d adalah %d", bil1, bil2, fpb(bil1, bil2));
    
    return 0;
}

int fpb(int a, int b)
{
    if(b == 0)
        return a;
    else
        return fpb(b, a%b);
}