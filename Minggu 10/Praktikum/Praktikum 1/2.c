#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void insertion(int A[], int);
void tukar(int *, int*);
void tampil(int A[]);

int c, m;
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
    insertion(A, MAX);
    printf("Setelah sorting : ");
    tampil(A);
    printf("C : %d\nM : %d\n", c, m);
    return 0;
}

void insertion(int A[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
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