#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int faktorial_it(int);
int faktorial_re(int);
int faktorial_retail(int, int);
void waktu(int, int(*)(int));
void menu(int);

int main()
{
    int n;

    printf("Program Mencari faktorial dari suatu bilangan\n");
    printf("Masukkan bilangan yang akan difaktorialkan : ");
    scanf("%d", &n);
    while (1)
    {
        menu(n);
    }
    
    return 0;
}

void menu(int n)
{
    int jwb;

    printf("\nMENU Faktorial\n");
    printf("1. Iterasi\n");
    printf("2. Rekursi\n");
    printf("3. Rekursi Tail\n");
    printf("4. Keluar\n");

    printf("Masukkan Pilihan Anda : ");
    scanf("%d", &jwb);

    // TODO : time check not yet implemented;
    switch (jwb)
    {
    case 1:
        waktu(n, faktorial_it);
        break;
    case 2:
        waktu(n, faktorial_re);
        break;
    case 3:
        waktu(n, faktorial_retail);     //mumet makkk;
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Pilihan Anda Invalid");
        break;
    }
}

void waktu(int n, int(*faktorial)(int))
{
    clock_t start, end;
    double waktu;
    start = clock();
    printf("Hasil faktorial dari %d adalah %d\n", n, faktorial(n));
    end = clock();
    waktu = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Waktu komputasi : %f detik\n");
}

int faktorial_it(int n)
{
    int i, hasil = 1;
    for (i = n; i > 1; i--)
    {
        hasil *= i;
    }
    return hasil;
}

int faktorial_re(int n)
{
    if(n == 0)
        return 1;
    return n * faktorial_re(n-1);
}

int faktorial_retail(int n, int a)
{
    if(n == 0)
        return a;
    else
        return faktorial_retail(n-1, n*a);
}