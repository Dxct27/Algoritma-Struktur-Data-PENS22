#include<stdio.h>
#include<stdlib.h>

int faktorial(int);

int main()
{
    int n;

    printf("FAKTORIAL MENGGUNAKAN REKURSI\n");
    printf("Masukkan angka yang akan di faktorialkan : ");
    scanf("%d", &n);
    printf("Hasil faktorialnya adalah : %d", faktorial(n));
    
    return 0;
}

int faktorial(int n)
{
    if(n == 0)
        return 1;
    return n * faktorial(n-1);
}