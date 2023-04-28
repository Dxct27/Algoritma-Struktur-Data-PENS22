#include<stdio.h>
#include<stdlib.h>

void fibonacci_it(int);
int fibonacci_re(int);
void menu(int);

int main()
{
    int n;
    
    printf("Program menampilkan deret fibonacci\n");

    printf("Masukkan jumlah deret fibonacci : ");
    scanf("%d", &n);
    
    while (1)
    {
        menu(n);
    }
    return 0;
}

void menu(int n)
{
    int jwb, i;
    
    printf("\nMENU program fibonacci\n");
    printf("1. Iterasi\n");
    printf("2. Rekursi\n");
    printf("3. Keluar\n");
    
    printf("Masukkan pilihan Anda : ");
    scanf("%d", &jwb);

    //TODO : add time check
    switch (jwb)
    {
    case 1:
        fibonacci_it(n);
        break;
    case 2:
        printf("Deret Fibonacci : \n");
        for(i = 0; i < n; i++)
        {
            printf("%d ", fibonacci_re(i));
        }
        printf("\n");
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Pilihan anda Invalid");
        break;
    }
}

void fibonacci_it(int n)
{
    int i, t1 = 0, t2 = 1;
    int tn = t1 + t2;

    printf("Deret fibonacci : %d %d ", t1, t2);
    for (i = 3; i <= n; i++)
    {
        printf("%d ", tn);
        t1 = t2;
        t2 = tn;
        tn = t1 + t2;
    }
    printf("\n");
}

int fibonacci_re(int n)
{
    if(n <= 1)
        return n;
    else
        return (fibonacci_re(n-1) + fibonacci_re(n-2));
}