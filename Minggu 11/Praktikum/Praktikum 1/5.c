#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void insertion(int [], int);
void selection(int [], int);
void shell(int [], int);
void bubble(int [], int);
void tukar(int *, int*);
void tampil(int [], int);
void generate(int [], int);
void menu_utama(int [], int, int);
void mode_urutan();
void backup(int [], int [], int);
void waktu(int [], int , void (*sort_func)(int[], int));

int mode;

int main()
{
    int pilihan_menu = 0;
    int n;

    printf("Masukkan jumlah data : ");
    scanf("%d", &n);
    
    int A[n], B[n];
    
    generate(A, n);
    backup(A, B, n);
    do
    {
        printf("\nMENU METODE SORTING\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Shell Sort\n");
        printf("4. Bubble Sort\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda : ");
        scanf("%d", &pilihan_menu);

        menu_utama(B, pilihan_menu, n);
    }while(pilihan_menu != 5);
    
    return 0;
}

void menu_utama(int A[], int jwb, int n)
{
    mode_urutan();
    switch (jwb)
    {
    case 1:
        waktu(A, n, insertion);
        break;
    case 2:
        waktu(A, n, selection);
        break;
    case 3:
        waktu(A, n, bubble);
        break;
    case 4:
        waktu(A, n, shell);
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("Pilihan Anda Invalid");
        break;
    }
}

void mode_urutan()
{
    printf("\nMENU METODE SORTING\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan anda [1/2] : ");
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

void selection(int A[], int n)
{
    int i, j, min;

    for (i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if (mode == 1 ? A[j] < A[min] : A[j] > A[min])
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
        while (j >= 0 && (mode == 1 ? A[j] > key : A[j] < key))
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
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
                if (mode == 1 ? A[j] > A[j+1] : A[j] < A[j+1])
                {
                    tukar(&A[j], &A[j+1]);
                    did_swap = 1;
                }
                
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

void backup(int A[], int B[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
}


void waktu(int A[], int n, void (*sort_func)(int[], int))
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    (*sort_func)(A, n);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorting time: %f seconds\n", cpu_time_used);
}