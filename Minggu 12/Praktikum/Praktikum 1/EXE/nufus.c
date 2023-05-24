#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define maks 100000

void menu();
void generate(int[], int);
int urutan();
void menuinsert(int[], int);
void menuselection(int[], int);
void menububble(int[], int);
void menushell(int[], int);
void shellInsertion(int[], int, int);
void menuMerge(int[], int, int);
void merge(int[], int, int, int);
void mergerekursi(int[], int, int);
void quicksort(int[], int, int);
int partition(int[], int, int);
void tukar(int *, int *);
void waktu(clock_t, clock_t, int);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int jumlah, pilih, arr[maks], copy[maks];
    clock_t start, end;
    printf("Berapa Jumlah data (maks 100000)? ");
    scanf("%d", &jumlah);
    printf("jml = %d\n\n", jumlah);
    generate(arr, jumlah);
    do
    {
        memcpy(copy, arr, sizeof(int) * jumlah);
        puts("MENU METODE SORTING");
        puts("1. Insertion\n2. Selection\n3. Bubble\n4.Shell\n5. Merge\n6. Quick\n7. Keluar");
        printf("Pilihan anda : ");
        scanf(" %d", &pilih);
        if (pilih != 7)
        {
            switch (pilih)
            {
            case 1:
                menuinsert(copy, jumlah);
                break;
            case 2:
                menuselection(copy, jumlah);
                break;
            case 3:
                menububble(copy, jumlah);
                break;
            case 4:
                menushell(copy, jumlah);
                break;
            case 5:
                start = clock();
                mergerekursi(copy, 0, jumlah);
                end = clock();
                waktu(start, end, jumlah);
                break;
            case 6:
                srand(time(NULL));
                start = clock();
                quicksort(copy, 0, jumlah - 1);
                end = clock();
                waktu(start, end, jumlah);
                break;
            case 7:
                puts("\nPROGRAM DIHENTIKAN");
                exit(0);
            default:
                puts("\nINVALID INPUT\n");
                break;
            }
        }
    } while (pilih != 7);
}

void generate(int a[], int n)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        a[i] = rand() / 1000;
    }
}

void menuinsert(int a[], int n)
{
    int i, key, j, c = 0, s = 0, did_swap;
    clock_t start, end;
    start = clock();
    for (i = 1; i < n; i++)
    {
        did_swap = 1;
        key = a[i];
        j = i - 1;
        while (did_swap == 1)
        {
            did_swap = 0;
            while (j >= 0 && a[j] > key)
            {
                c++;
                a[j + 1] = a[j];
                j = j - 1;
                s++;
                did_swap = 1;
            }
        }
        c++;
        a[j + 1] = key;
    }
    end = clock();
    waktu(start, end, n);
}

void menuselection(int a[], int n)
{
    int i, j, k, min_idx;
    clock_t start, end;
    start = clock();

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
        {
            tukar(&a[i], &a[min_idx]);
        }
    }
    end = clock();
    waktu(start, end, n);
}

void menububble(int a[], int n)
{
    int i, j, did_swap = 1, akhir;
    clock_t start, end;
    start = clock();
    for (i = 0; i < n - 1; i++)
    {
        if (did_swap == 1)
        {
            did_swap = 0;
            for (j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    tukar(&a[j], &a[j + 1]);
                    did_swap = 1;
                }
            }
        }
    }
    end = clock();
    waktu(start, end, n);
}

void menushell(int a[], int n)
{
    int jarak = n / 2;
    int i, did_swap;
    clock_t start, end;
    start = clock();
    while (jarak > 0)
    {
        did_swap = 1;
        while (did_swap == 1)
        {
            did_swap = 0;
            for (i = 0; i < n - jarak; i++)
            {
                if (a[i] > a[i + jarak])
                {
                    tukar(&a[i], &a[i + jarak]);
                    did_swap = 1;
                }
            }
        }
        jarak = jarak / 2;
    }
    end = clock();
    waktu(start, end, n);
}

void mergerekursi(int a[], int l, int r)
{
    int median;
    if (l < r)
    {
        median = (l + r) / 2;
        mergerekursi(a, l, median);
        mergerekursi(a, median + 1, r);
        merge(a, l, median, r);
    }
}

void merge(int a[], int left, int median, int right)
{
    int kiri1, kanan1, kiri2, kanan2, i, hasil[maks], j;
    kiri1 = left;
    kanan1 = median;
    kiri2 = median + 1;
    kanan2 = right;
    i = left;
    while (kiri1 <= kanan1 && kiri2 <= kanan2)
    {
        if (a[kiri1] <= a[kiri2])
        {
            hasil[i] = a[kiri1];
            kiri1++;
        }
        else
        {
            hasil[i] = a[kiri2];
            kiri2++;
        }
        i++;
    }
    while (kiri1 <= kanan1)
    {
        hasil[i] = a[kiri1];
        kiri1++;
        i++;
    }
    while (kiri2 <= kanan2)
    {
        hasil[i] = a[kiri2];
        kiri2++;
        i++;
    }
    j = left;
    while (j <= right)
    {
        a[j] = hasil[j];
        j++;
    }
}

void quicksort(int a[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

int partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1, j;
    for (j = p; j <= r - 1; j++)
    {
        if (a[j] <= x)
        {
            i++;
            tukar(&a[i], &a[j]);
        }
    }
    tukar(&a[i + 1], &a[r]);
    return (i + 1);
}

void tukar(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void waktu(clock_t start, clock_t end, int n)
{
    double cpu_time_used;
    cpu_time_used = ((double)(end - start)) /
                    CLOCKS_PER_SEC;
    puts("======================================================================");
    printf("\nWaktu yang dibutuhkan untuk mengurutkan %d elemen adalah %.3f ms \n\n", n, cpu_time_used * 1000);

    puts("======================================================================");
}
