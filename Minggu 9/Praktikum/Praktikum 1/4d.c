#include<stdio.h>
#include<stdlib.h>

int faktorial_it(int);
int faktorial_re(int);
int faktorial_retail(int, int);
void menu();

int main()
{
    while (1)
    {
        menu();
    }
    
    return 0;
}

void menu()
{
    int jwb, n;

    printf("Program Mencari faktorial dari suatu bilangan\n");
    printf("Masukkan bilangan yang akan difaktorialkan : ");
    scanf("%d", &n);
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
        printf("Hasil faktorial dari %d adalah %d\n", n, faktorial_it(n));
        break;
    case 2:
        printf("Hasil faktorial dari %d adalah %d", n, faktorial_re(n));
        break;
    case 3:
        printf("Hasil faktorial dari %d adalah %d\n", n, faktorial_retail(n, 1));
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Pilihan Anda Invalid");
        break;
    }
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
    return n * faktorial(n-1);
}

int faktorial_retail(int n, int a)
{
    if(n == 0)
        return a;
    else
        return faktorial(n-1, n*a);
}