#include<stdio.h>
#include<stdlib.h>

int faktorial(int);

int main()
{
    int n;

    printf("FAKTORIAL MENGGUNAKAN ITERASI\n");
    printf("Masukkan angka yang akan di faktorialkan : ");
    scanf("%d", &n);
    printf("Hasil faktorialnya adalah : %d", faktorial(n));
    
    return 0;
}

int faktorial(int n)
{
    int i, hasil = 1;
    for (i = n; i > 1; i--)
    {
        hasil *= i;
    }
    return hasil;
}