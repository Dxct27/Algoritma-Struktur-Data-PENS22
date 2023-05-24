#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void selection(int A[], int);
void tukar(int *, int*);
void tampil(int A[]);
int c, m, s;
//TODO : add how many time checking and moving the elements;

int main()
{
    //int A[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};   //acak
    //int A[MAX] = {1, 2, 3, 4, 5, 9, 7, 6, 8, 10};   //5 pertama urut kemudian acak
    //int A[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   //ascending
    int A[MAX] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};   //descending
    
    printf("SELECTION Sort\n");
    printf("Sebelum sorting : ");
    tampil(A);
    selection(A, MAX);
    printf("Setelah sorting : ");
    tampil(A);
    printf("C : %d\nM : %d\nS : %d\n", c, m, s);
    return 0;
}

void selection(int A[], int n)
{
    int i, j, min;

    for (i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        tukar(&A[min], &A[i]);
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