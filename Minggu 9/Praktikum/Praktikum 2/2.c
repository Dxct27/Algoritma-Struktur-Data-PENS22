#include<stdio.h>
#include<stdlib.h>

void fibonacci(int);

int main()
{
    int n;

    printf("Program fibonacci menggunakan ITERASI\n");
    printf("Masukkan n : ");
    scanf("%d", &n);

    fibonacci(n);
    
    return 0;
}

void fibonacci(int n)
{
    int i, t1 = 0, t2 = 1;
    int tn = t1 + t2;

    printf("Fibonacci : %d, %d, ", t1, t2);
    for (i = 3; i <= n; i++)
    {
        printf("%d, ", tn);
        t1 = t2;
        t2 = tn;
        tn = t1 + t2;
    }
    
}