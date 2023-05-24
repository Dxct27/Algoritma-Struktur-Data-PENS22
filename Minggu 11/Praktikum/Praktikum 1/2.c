#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 10

void shell(int [], int);
void bubble(int [], int);
void menu();
void mode_urut();
void tukar(int *, int*);
void tampil(int A[], int);

int mode;

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
    int A[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};   //acak
    //int A[MAX] = {1, 2, 3, 4, 5, 9, 7, 6, 8, 10};   //5 pertama urut kemudian acak
    //int A[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   //ascending
    //int A[MAX] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};   //descending
    int jwb;
    

    printf("\nSORTING\n");
    printf("1. Bubble\n");
    printf("2. Shell\n");
    printf("3. Keluar\n");
    printf("Pilihan Anda : ");
    scanf("%d", &jwb);

    
    switch (jwb)
    {
    case 1:
        mode_urut();
        bubble(A, MAX);
        break;
    case 2:
        mode_urut();
        shell(A, MAX);
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Pilihan Anda Invalid");
        break;
    }
}

void mode_urut()
{
    printf("\nMode urut\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan Anda : ");
    scanf("%d", &mode);
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
                if(mode == 1 ? A[i] > A[i+jarak] : A[i] < A[i+jarak])
                {
                    tukar(&A[i], &A[i+jarak]);
                    did_swap = 1;
                }
            }
            tampil(A, n);
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
                if(mode == 1 ? A[j] > A[j+1] : A[j] < A[j+1])
                {
                    tukar(&A[j], &A[j+1]);
                    did_swap = 1;
                }
                tampil(A, n);
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

void tampil(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}