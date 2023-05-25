#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX 100000

void selection(int[], int);
void insertion(int[], int);
void bubble(int[], int);
void shell(int[], int);
void mergeSortRekursif(int[], int, int);
void merge(int[], int, int, int);
void quickSort(int[], int, int);
int partition(int[], int, int);
void tampil(int[], int);
void tukar(int *, int *);
void generate(int[], int);
void waktu(clock_t, clock_t, int);
void menu();
void mode_urut();

int mode;

int main()
{
    menu();
    return 0;
}

void menu()
{
    int n, jwb, arr[MAX], backup[MAX];
    clock_t start, end;

    printf("Berapa jumlah data (maks 100000) ? ");
    scanf("%d", &n);

    generate(arr, n);

    do
    {
        memcpy(backup, arr, sizeof(int) * n);
        printf("\nMENU METODE SORTING\n");
        printf("1. Insertion\n");
        printf("2. Selection\n");
        printf("3. Bubble\n");
        printf("4. Shell\n");
        printf("5. Merge\n");
        printf("6. Quick\n");
        printf("7. Keluar\n");
        printf("Pilihan Anda : ");
        scanf("%d", &jwb);

        mode_urut();

        //printf("\nBefore\n");
        //tampil(backup, n);

        srand(time(NULL));
        start = clock();
        
        switch (jwb)
        {
        case 1:
            insertion(backup, n);
            break;
        case 2:
            selection(backup, n);
            break;
        case 3:
            bubble(backup, n);
            break;
        case 4:
            shell(backup, n);
            break;
        case 5:
            mergeSortRekursif(backup, 0, n);
            break;
        case 6:
            quickSort(backup, 0, n - 1);
            break;
        case 7:
            printf("\nPROGRAM DIHENTIKAN\n");
            exit(0);
            break;
        default:
            printf("\nPilihan Anda Invalid\n");
            break;
        }
        
        //printf("After\n");
        //tampil(backup, n);
        
        end = clock();
        waktu(start, end, n);
    } while (jwb != 7);
}

void mode_urut()
{
    printf("\nPengurutan yang dipilih :\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan Anda [1/2] : ");
    scanf("%d", &mode);
}

void insertion(int x[], int n)
{
    int i, j, key;
    i = 1;
    while (i < n)
    {
        key = x[i];
        j = i - 1;
        while (j >= 0 && (mode == 1 ? x[j] > key : x[j] < key))
        {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = key;
        i++;
    }
}

void selection(int x[], int n)
{
    int i, j, min;

    while (i < n)
    {
        min = i;
        j = i + 1;
        while (j < n)
        {
            if (mode == 1 ? x[j] < x[min] : x[j] > x[min])
            {
                min = j;
            }
            j++;
        }
        tukar(&x[i], &x[min]);
        i++;
    }
}

void bubble(int x[], int n)
{
    int i, j, did_swap;
    did_swap = 1;

    for (i = 0; i < n - 1; i++)
    {
        if (did_swap)
        {
            did_swap = 0;
            for (j = 0; j < (n - i - 1); j++)
            {
                if (mode == 1 ? x[j] > x[j + 1] : x[j] < x[j + 1])
                {
                    tukar(&x[j], &x[j + 1]);
                    did_swap = 1;
                }
            }
        }
    }
}

void shell(int x[], int n)
{
    int jarak = n / 2;
    int i, did_swap;

    while (jarak > 0)
    {
        did_swap = 1;
        while (did_swap == 1)
        {
            did_swap = 0;
            for (i = 0; i < n - jarak; i++)
            {
                if (mode == 1 ? x[i] > x[i + jarak] : x[i] < x[i + jarak])
                {
                    tukar(&x[i], &x[i + jarak]);
                    did_swap = 1;
                }
            }
        }
        jarak = jarak / 2;
    }
}

void mergeSortRekursif(int data[], int l, int r)
{
    int med;
    if (l < r)
    {
        med = (l + r) / 2;
        mergeSortRekursif(data, l, med);
        mergeSortRekursif(data, med + 1, r);
        merge(data, l, med, r);
    }
}

void merge(int data[], int l, int m, int r)
{
    int i, j, ki1, ki2, ka1, ka2;
    int hasil[MAX];

    ki1 = l;
    ka1 = m;
    ki2 = m + 1;
    ka2 = r;
    i = l;

    while (ki1 <= ka1 && ki2 <= ka2)
    {
        // if(data[ki1] <= data[ki2])
        if ((mode == 1) ? data[ki1] <= data[ki2] : data[ki1] >= data[ki2])
        {
            hasil[i] = data[ki1];
            ki1++;
        }
        else
        {
            hasil[i] = data[ki2];
            ki2++;
        }
        i++;
    }
    while (ki1 <= ka1)
    {
        hasil[i] = data[ki1];
        ki1++;
        i++;
    }
    while (ki2 <= ka2)
    {
        hasil[i] = data[ki2];
        ki2++;
        i++;
    }

    j = l;
    while (j <= r)
    {
        data[j] = hasil[j];
        j++;
    }
}

void quickSort(int A[], int p, int r)
{
    int q;

    if (p < r)
    {
        q = partition(A, p, r);
        quickSort(A, p, q);
        quickSort(A, q + 1, r);
    }
}

int partition(int A[], int p, int r)
{
    int i, j, pivot;
    pivot = A[p];
    i = p;
    j = r;

    while (i <= j)
    {
        while ( (mode == 1) ? A[j] > pivot : A[j] < pivot )
        {
            j--;
        }

        while ((mode == 1) ? A[i] < pivot : A[i] > pivot )
        {
            i++;
        }

        if (i < j)
        {
            tukar(&A[i], &A[j]);
            j--;
            i++;
        }
        else
            return j;
    }
    return j;
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
    for (i = 0; i < n; i++)
    {
        x[i] = rand() / 1000;
    }
}

void waktu(clock_t start, clock_t end, int n)
{
    double cpu_time_used;
    cpu_time_used = ((double)end - start) / CLOCKS_PER_SEC;

    printf("\nWaktu yang dibutuhkan adalah %.2f ms\n", cpu_time_used * 1000);
}
