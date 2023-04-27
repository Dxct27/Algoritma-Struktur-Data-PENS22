#include<stdio.h>
#include<stdlib.h>

int faktorial(int, int);

int main()
{
    int n, hasil;

    printf("FAKTORIAL MENGGUNAKAN REKURSI TAIL\n");
    printf("Masukkan angka yang akan di faktorialkan : ");
    scanf("%d", &n);

    hasil = faktorial(n, 1);

    printf("Hasil faktorialnya adalah : %d", hasil);
    
    return 0;
}

int faktorial(int n, int a)
{
    if(n == 0)
        return a;
    else
        return faktorial(n-1, n*a);
}