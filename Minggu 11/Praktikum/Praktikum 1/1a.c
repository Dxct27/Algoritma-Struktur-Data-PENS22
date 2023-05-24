#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void shell(int [], int);
void bubble(int [], int);
void tukar(int *, int*);
void tampil(int A[]);
//int c, m;
//TODO : add how many time checking and moving the elements;

int main()
{
    int A[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};   //acak
    //int A[MAX] = {1, 2, 3, 4, 5, 9, 7, 6, 8, 10};   //5 pertama urut kemudian acak
    //int A[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   //ascending
    //int A[MAX] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};   //descending
    
    printf("SHELL Sort\n");
    printf("Sebelum sorting :\n");
    tampil(A);
    //shell(A, MAX);
    bubble(A, MAX);
    printf("Setelah sorting :\n");
    tampil(A);
    return 0;
}

void shell(int A[], int n)
{
    int jarak, i, did_swap; 
    jarak = n;
    while (jarak > 1)
    {
        jarak = jarak/2;
        did_swap = 1;
        while (did_swap)
        {
            did_swap = 0;
            for(i = 0; i < (n - jarak); i++)
            {
                if(A[i] > A[i+jarak])
                {
                    tukar(&A[i], &A[i+jarak]);
                    did_swap = 1;
                }
            }
            tampil(A);
        }
    }
}

void bubble(int A[], int n)
{
    int i, j, did_swap;

    did_swap = 1;
    for(i = 0; i < n-1; i++)
    {
        if (did_swap)
        {
            did_swap = 0;
            for(j = 0; j < (n - i - 1); j++)
            {
                if (A[j] > A[j+1])
                {
                    tukar(&A[j], &A[j+1]);
                    did_swap = 1;
                }
                tampil(A);
            }
            
        }
        
    }
    
}

void tukar(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(int A[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}