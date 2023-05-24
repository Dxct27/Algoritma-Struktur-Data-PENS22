#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void shell(int [], int);
void bubble(int [], int);
void menu(int n);
void mode_urut();
void generate(int [], int);
void tukar(int *, int*);
void tampil(int A[], int);
void sort_with_time(int [], int , void (*sort_func)(int[], int));

int mode;
//int c, m;
//TODO : add how many time checking and moving the elements;

int main()
{
    int n;

    printf("Berapa Jumlah data (maks 100000) ? ");
    scanf("%d", &n);
    while (1)
    {
        menu(n);
    }
    return 0;
}

void menu(int n)
{
    int jwb, A[n];

    generate(A, n);

    printf("\nMode urut\n");
    printf("1. Bubble\n");
    printf("2. Shell\n");
    printf("3. Keluar\n");
    printf("Pilihan Anda : ");
    scanf("%d", &jwb);

    
    switch (jwb)
    {
    case 1:
        mode_urut();
        sort_with_time(A, n, bubble);
        break;
    case 2:
        mode_urut();
        sort_with_time(A, n, shell);
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

void generate(int x[], int n)
{
    int i;
    srand(time(NULL));
    for(i = 0; i<n; i++)
    {
        x[i] = rand()/1000;
    }
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
            //tampil(A, n);
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
                //tampil(A, n);
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

void sort_with_time(int A[], int n, void (*sort_func)(int[], int))
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    (*sort_func)(A, n);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorting time: %f seconds\n", cpu_time_used);
}