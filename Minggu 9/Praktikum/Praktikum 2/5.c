#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int prime(int, int);

int main()
{
    int n;
    printf("Program mengecek bilangan prima\n");
    printf("Masukkan bilangan yg akan dicek : ");
    scanf("%d", &n);

    if(prime(n, sqrt(n)))
    {
        printf("Bilangan %d prima\n", n);
    }
    else
    {
        printf("Bilangan %d bukan prima\n", n);
    }

    return 0;
}

int prime(int n, int a)
{
    if(a < 2)
        return 1;
    else if (n % a == 0)
        return 0;
    else
        prime(n, a-1);
}