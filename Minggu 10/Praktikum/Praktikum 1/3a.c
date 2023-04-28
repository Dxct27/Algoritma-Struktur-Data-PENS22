#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void insertion(int A[], int);
void selection(int A[], int);
void tukar(int *, int*);
void tampil(int A[]);
void menu();

//int c, m;
//TODO : add how many time checking and moving the elements;

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
    int jwb;
    int A[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};

    printf("\nMENU METODE SORTING\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Keluar\n");
    printf("Pilihan Anda [1/2/3] : ");
    scanf("%d", &jwb);

    switch (jwb)
    {
    case 1:
        insertion(A, MAX);
        printf("\nHasil seteleh Insertion\n");
        tampil(A);
        break;
    case 2:
        selection(A, MAX);
        printf("\nHasil seteleh Selection\n");
        tampil(A);
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Pilihan Anda Invalid");
        break;
    }
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