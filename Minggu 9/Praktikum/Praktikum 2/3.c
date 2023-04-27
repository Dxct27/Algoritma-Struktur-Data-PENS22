#include<stdio.h>
#include<stdlib.h>

int fibonacci(int);

int main()
{
    int n, i;

    printf("Program fibonacci menggunakan REKURSI\n");
    printf("Masukkan n : ");
    scanf("%d", &n);

    printf("Deret Fibonacci : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }
    
    return 0;
}

int fibonacci(int n)
{
    if(n <= 1)
        return n;
    else
        return (fibonacci(n-1) + fibonacci(n-2));
}