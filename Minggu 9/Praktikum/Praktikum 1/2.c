#include<stdio.h>
#include<stdlib.h>

void angkaTampil(int);

int main()
{
    int n;

    printf("Program untuk menampilkan angaka dari 0 ke n menggunakan rekursi\n");
    printf("Masukkan n : ");
    scanf("%d", &n);

    angkaTampil(n);

    return 0;
}

void angkaTampil(int n)
{
    if(n < 0){
        return;
    }
    printf("%d ", n);
    angkaTampil(n-1);
}