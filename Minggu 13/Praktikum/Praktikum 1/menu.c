#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define MAX 100000

void quickSort(int [], int, int);
int partition(int [], int, int);
void seq(int [], int , int);
void bin(int [], int, int);
void tukar(int *, int *);
void tampil(int [], int);
void generate(int [], int);
void waktu(struct timespec, struct timespec);
void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int n, key,  jwb, arr[MAX], backup[MAX];
    clock_t start, end;

    printf("Berapa Jumlah data (100000) : ");
    scanf("%d", &n);
    fflush(stdin);
    printf("Data yang dicari : ");
    scanf("%d", &key);

    generate(arr, n);

    do
    {
        memcpy(backup, arr, sizeof(int) * n);
        printf("\nMetode Searching\n");
        printf("1. Sequential Search (unsorted)\n");
        printf("2. Sequential Search (sorted)\n");
        printf("3. Binary Search (sorted)\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda : ");
        scanf("%d", &jwb);

        quickSort(backup, 0, n-1);

        switch (jwb)
        {
        case 1:
            seq(backup, n, key);
            break;
        case 2:
            seq(arr, n, key);
            break;
        case 3:
            bin(arr, n, key);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Pilihan Anda Invalid\n");
            break;
        }

    } while (jwb != 4);
    
}

void seq(int data[], int n, int key)
{
    int i, ketemu = 0;
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
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
    clock_gettime(CLOCK_MONOTONIC, &end);
    waktu(start, end);
}

void bin(int data[], int n, int key)
{
    struct timespec start, end;
    int l, r, med, ketemu;
    l = 0;
    r = n - 1;
    ketemu = 0;

    clock_gettime(CLOCK_MONOTONIC, &start);
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
    clock_gettime(CLOCK_MONOTONIC, &end);
    waktu(start, end);
}

void quickSort(int A[], int p, int r)
{
    int q;

    if (p < r)
    {
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
    
}

int partition(int A[], int p , int r)
{
    int i, j, x;
    x = A[r];
    i = p - 1;

    for (j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            tukar(&A[i], &A[j]);
        }
    }
    tukar(&A[i+1], &A[r]);
    return (i+1);
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

void generate(int x[], int n)
{
    int i;
    srand(time(NULL));
    for(i = 0; i<n; i++)
    {
        x[i] = rand()/1000;
    }
}

void waktu(struct timespec start, struct timespec end)
{
    double cpu_time_used;
    cpu_time_used = (end.tv_sec - start.tv_sec) * 1e9;
    cpu_time_used += (end.tv_nsec - start.tv_nsec);
    printf("\nWaktu yang dibutuhkan adalah %.2f ns\n", cpu_time_used);
}
