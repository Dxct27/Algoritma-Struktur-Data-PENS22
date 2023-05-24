#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void seq(int [], int, int);
void bin(int [], int, int);

int main()
{
    int A[MAX] = {1,2,3,4,5,6,7,8,9,10};
    int n;

    printf("Data yang akan di cari : ");
    scanf("%d", &n);

    bin(A, MAX, n);
    //seq(A, MAX, n);
    return 0;
}

void seq(int data[], int n, int key)
{
    int i, ketemu = 0;
    
    while (!ketemu && i < n)
    {
        //printf("data %d, index %d, key %d\n", data[i], i, key);
        if ( data[i] == key)
        {
            ketemu = 1;
        }
        else
        {
            i++;
        }
    }
    if (ketemu)
    {
        printf("Data %d ketemu pada indeks %d\n", key, i);
    }
    else
    {
        printf("Data tidak ditemukan\n");
    }
}

void bin(int data[], int n, int key)
{
    int l, r, med, ketemu;
    l = 0;
    r = n - 1;
    ketemu = 0;

    while ( l <= r && !ketemu )
    {
        med = (l+r) / 2;
        if (data[med] == key)
        {
            ketemu = 1;
        }
        if (key < data[med])
        {
            r = med - 1;
        }
        if (key > data[med])
        {
            l = med + 1;
        }
    }
    if (ketemu)
    {
        printf("Data %d ketemu pada indeks %d\n", key, med);
    }
    else
    {
        printf("Data tidak ditemukan\n");
    }
}
