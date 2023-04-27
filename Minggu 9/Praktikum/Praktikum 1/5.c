#include<stdio.h>
#include<stdlib.h>

int faktorial(int);

int main()
{
    int n, r, permutasi, kombinasi;

    printf("PERMUTASI dan KOMBINASI\n");
    printf("Masukkan nilai n : ");
    scanf("%d", &n);
    printf("Masukkan nilai r : ");
    scanf("%d", &r);

    permutasi = faktorial(n) / faktorial(n - r);
    //kombinasi = faktorial(n) / (faktorial(r) * faktorial(n - r));

    printf("Permutasi dari %d dan %d adalah %d\n", n, r, permutasi);
    //printf("kombinasi dari %d dan %d adalah %d\n", n, r, kombinasi);
    //printf("%d", faktorial(n));
    //printf("%d", faktorial(r));
    return 0;
}

int faktorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * faktorial(n-1);
}