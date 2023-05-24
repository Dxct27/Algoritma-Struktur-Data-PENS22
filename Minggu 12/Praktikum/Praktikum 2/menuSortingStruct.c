#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mhs
{
    int no;
    char nama[10];
    float nilai;
} mhs;

void selection(mhs *, int);
void insertion(mhs *, int);
void bubble(mhs[], int);
void shell(mhs[], int);
void mergeSortRekursif(mhs [], int , int);
void merge(mhs [], int , int, int);
void quickSort(mhs [], int, int);
int partition(mhs [], int, int);
void tukar(mhs *, mhs *);
void tampil(mhs[], int);
void isiData(mhs *, int);
void menu(mhs *, int, int);
void mode_urut();
void tipe_urut();

int mode, tipe;

int main()
{

    int n = 5, pilihan_menu = 0;

    //printf("Jumlah siswa yang akan dimasukkan : ");
    //scanf("%d", &n);

    //mhs mahasiswa[n];

    mhs mahasiswa[5] = {5, "Seulgi", 'B', 3, "Irene", 'A', 10, "Yerim", 'C', 2, "Joy", 'C', 7, "Wendy", 'A'};

    //isiData(mahasiswa, n);

    while (pilihan_menu != 7)
    {
        printf("\nMENU METODE SORTING\n");
        printf("1. Insertion sort\n");
        printf("2. Selection sort\n");
        printf("3. Bubble sort\n");
        printf("4. Shell sort\n");
        printf("5. Merge sort\n");
        printf("6. Quick sort\n");
        printf("7. Keluar\n");
        printf("Pilihan Anda [1/2/3/4/5] : ");
        scanf("%d", &pilihan_menu);

        menu(mahasiswa, pilihan_menu, n);
    }

    return 0;
}

void menu(mhs *mahasiswa, int jwb, int n)
{
    mode_urut();

    switch (jwb)
    {
    case 1:
        insertion(mahasiswa, n);
        break;
    case 2:
        selection(mahasiswa, n);
        break;
    case 3:
        bubble(mahasiswa, n);
        break;
    case 4:
        shell(mahasiswa, n);
        break;
    case 5:
        mergeSortRekursif(mahasiswa, 0, n-1);
        tampil(mahasiswa, n);
        break;
    case 6:
        quickSort(mahasiswa, 0, n-1);
        tampil(mahasiswa, n);
        break;
    case 7:
        exit(0);
        break;
    default:
        printf("Pilihan Anda Invalid");
        break;
    }
}

void mode_urut()
{
    printf("\nPengurutan yang dipilih :\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan Anda [1/2] : ");
    scanf("%d", &mode);

    tipe_urut();
}

void tipe_urut()
{
    printf("\nPengurutan berdasarkan :\n");
    printf("1. No\n");
    printf("2. Nama\n");
    printf("3. Nilai\n");
    printf("Pilihan Anda [1/2/3] : ");
    scanf("%d", &tipe);
}

void isiData(mhs *mahasiswa, int n)
{
    int i;
    char nama_temp[20];

    for (i = 0; i < n; i++)
    {
        printf("\nData siswa ke-%d :\n", i + 1);
        printf("No\t: ");
        scanf("%d", &mahasiswa[i].no);
        fflush(stdin);
        printf("Nama\t: ");
        scanf("%s", mahasiswa[i].nama);
        // strcpy(mahasiswa[i].nama, nama_temp);
        fflush(stdin);
        printf("Nilai\t: ");
        scanf("%f", &mahasiswa[i].nilai);
        fflush(stdin);
    }
}

void selection(mhs *mahasiswa, int n)
{
    int i, j, min, kondisi = 0;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {

            switch (tipe)
            {
            case 1:
                if (mode == 1)
                {
                    kondisi = mahasiswa[j].no < mahasiswa[min].no;
                }
                else
                    kondisi = mahasiswa[j].no > mahasiswa[min].no;
                break;
            case 2:
                if (mode == 1)
                {
                    kondisi = strcmp(mahasiswa[j].nama, mahasiswa[min].nama) < 0;
                }
                else
                    kondisi = strcmp(mahasiswa[j].nama, mahasiswa[min].nama) > 0;
                break;
            case 3:
                if (mode == 1)
                {
                    kondisi = mahasiswa[j].nilai < mahasiswa[min].nilai;
                }
                else
                    kondisi = mahasiswa[j].nilai > mahasiswa[min].nilai;
                break;
            default:
                kondisi = 0;
                break;
            }

            if (kondisi)
            {
                min = j;
            }
        }
        tukar(&mahasiswa[min], &mahasiswa[i]);
    }
    tampil(mahasiswa, n);
}

void insertion(mhs *mahasiswa, int n)
{
    int i, j, kondisi = 0;
    mhs key;

    for (i = 1; i < n; i++)
    {
        key = mahasiswa[i];
        j = i - 1;
        while (j >= 0)
        {
            switch (tipe)
            {
            case 1:
                if (mode == 1)
                {
                    kondisi = mahasiswa[j].no > key.no;
                }
                else
                    kondisi = mahasiswa[j].no < key.no;
                break;
            case 2:
                if (mode == 1)
                {
                    kondisi = strcmp(mahasiswa[j].nama, key.nama) > 0;
                }
                else
                    kondisi = strcmp(mahasiswa[j].nama, key.nama) < 0;
                break;
            case 3:
                if (mode == 1)
                {
                    kondisi = mahasiswa[j].nilai > key.nilai;
                }
                else
                    kondisi = mahasiswa[j].nilai < key.nilai;
                break;
            default:
                kondisi = 0;
                break;
            }

            if (kondisi)
            {
                mahasiswa[j + 1] = mahasiswa[j];
                j--;
            }
            else
                break;
        }
        mahasiswa[j + 1] = key;
    }
    tampil(mahasiswa, n);
}

void bubble(mhs mahasiswa[], int n)
{
    int i, j, did_swap, kondisi = 0;

    did_swap = 1;
    for (i = 0; i < n - 1; i++)
    {
        if (did_swap)
        {
            did_swap = 0;
            for (j = 0; j < (n - i - 1); j++)
            {
                switch (tipe)
                {
                case 1:
                    if (mode == 1)
                    {
                        kondisi = mahasiswa[j].no > mahasiswa[j + 1].no;
                    }
                    else
                        kondisi = mahasiswa[j].no < mahasiswa[j + 1].no;
                    break;
                case 2:
                    if (mode == 1)
                    {
                        kondisi = strcmp(mahasiswa[j].nama, mahasiswa[j + 1].nama) > 0;
                    }
                    else
                        kondisi = strcmp(mahasiswa[j].nama, mahasiswa[j + 1].nama) < 0;
                    break;
                case 3:
                    if (mode == 1)
                    {
                        kondisi = mahasiswa[j].nilai > mahasiswa[j + 1].nilai;
                    }
                    else
                        kondisi = mahasiswa[j].nilai < mahasiswa[j + 1].nilai;
                    break;
                default:
                    kondisi = 0;
                    break;
                }

                if (kondisi)
                {
                    tukar(&mahasiswa[j], &mahasiswa[j + 1]);
                    did_swap = 1;
                }
            }
        }
    }
    tampil(mahasiswa, n);
}

void shell(mhs mahasiswa[], int n)
{
    int jarak, i, did_swap, kondisi = 0;
    jarak = n;
    while (jarak > 1)
    {
        jarak = jarak / 2;
        did_swap = 1;
        while (did_swap)
        {
            did_swap = 0;
            for (i = 0; i < (n - jarak); i++)
            {
                switch (tipe)
                {
                case 1:
                    if (mode == 1)
                    {
                        kondisi = mahasiswa[i].no > mahasiswa[i + jarak].no;
                    }
                    else
                        kondisi = mahasiswa[i].no < mahasiswa[i + jarak].no;
                    break;
                case 2:
                    if (mode == 1)
                    {
                        kondisi = strcmp(mahasiswa[i].nama, mahasiswa[i + jarak].nama) > 0;
                    }
                    else
                        kondisi = strcmp(mahasiswa[i].nama, mahasiswa[i + jarak].nama) < 0;
                    break;
                case 3:
                    if (mode == 1)
                    {
                        kondisi = mahasiswa[i].nilai > mahasiswa[i + jarak].nilai;
                    }
                    else
                        kondisi = mahasiswa[i].nilai < mahasiswa[i + jarak].nilai;
                    break;
                default:
                    kondisi = 0;
                    break;
                }

                if (kondisi)
                {
                    tukar(&mahasiswa[i], &mahasiswa[i + jarak]);
                    did_swap = 1;
                }
            }
        }
    }
    tampil(mahasiswa, n);
}

void mergeSortRekursif(mhs mahasiswa[], int l, int r)
{
    int med;
    if(l < r)
    {
        med = (l+r) / 2;
        mergeSortRekursif(mahasiswa, l, med);
        mergeSortRekursif(mahasiswa, med+1, r);
        merge(mahasiswa, l, med, r);
    }
}

void merge(mhs mahasiswa[], int l, int m, int r)
{
    int i, j, ki1, ki2, ka1, ka2, kondisi = 0;
    mhs hasil[r+1];

    ki1 = l;
    ka1 = m;
    ki2 = m+1;
    ka2 = r;
    i = l;

    while (ki1 <= ka1 && ki2 <= ka2)
    {
        switch (tipe)
        {
            case 1:
                if (mode == 1)
                {
                    kondisi = mahasiswa[ki1].no <= mahasiswa[ki2].no;
                }
                else
                    kondisi = mahasiswa[ki1].no >= mahasiswa[ki2].no;
                break;
            case 2:
                if (mode == 1)
                {
                    kondisi = strcmp(mahasiswa[ki1].nama, mahasiswa[ki2].nama) < 0;
                }
                else
                    kondisi = strcmp(mahasiswa[ki1].nama, mahasiswa[ki2].nama) > 0;
                break;
            case 3:
                if (mode == 1)
                {
                    kondisi = mahasiswa[ki1].nilai <= mahasiswa[ki2].nilai;
                }
                else
                    kondisi = mahasiswa[ki1].nilai >= mahasiswa[ki2].nilai;
                break;
            default:
                kondisi = 0;
                break;
        }
        //if(data[ki1] <= data[ki2])
        //if ((mode == 1) ? mahasiswa[ki1] <= mahasiswa[ki2] : mahasiswa[ki1] >= mahasiswa[ki2])
        if (kondisi)
        {
            hasil[i] = mahasiswa[ki1];
            ki1++;
        }
        else
        {
            hasil[i] = mahasiswa[ki2];
            ki2++;
        }
        i++;
    }

    while (ki1 <= ka1)
    {
        hasil[i] = mahasiswa[ki1];
        ki1++;
        i++;
    }

    while (ki2 <= ka2)
    {
        hasil[i] = mahasiswa[ki2];
        ki2++;
        i++;
    }

    j = l;
    while (j <= r)
    {
        mahasiswa[j] = hasil[j];
        j++;
    }
}

void quickSort(mhs mahasiswa[], int p, int r)
{
    int q;

    if (p < r)
    {
        q = partition(mahasiswa, p, r);
        quickSort(mahasiswa, p, q-1);
        quickSort(mahasiswa, q+1, r);
    }
}

int partition(mhs mahasiswa[], int p , int r)
{
    int i, j, kondisi = 0;
    mhs x = mahasiswa[r];
    i = p - 1;

    for (j = p; j < r; j++)
    {
        switch (tipe)
        {
            case 1:
                if (mode == 1)
                {
                    kondisi = mahasiswa[j].no <= x.no;
                }
                else
                    kondisi = mahasiswa[j].no >= x.no;
                break;
            case 2:
                if (mode == 1)
                {
                    kondisi = strcmp(mahasiswa[j].nama, x.nama) < 0;
                }
                else
                    kondisi = strcmp(mahasiswa[j].nama, x.nama) > 0;
                break;
            case 3:
                if (mode == 1)
                {
                    kondisi = mahasiswa[j].nilai <= x.nilai;
                }
                else
                    kondisi = mahasiswa[j].nilai >= x.nilai;
                break;
            default:
                kondisi = 0;
                break;
        }
        //if (A[j] <= x)
        //if ((mode == 1) ? A[j] <= x : A[j] >= x)
        if (kondisi)
        {
            i++;
            tukar(&mahasiswa[i], &mahasiswa[j]);
        }
    }
    tukar(&mahasiswa[i+1], &mahasiswa[r]);
    return (i+1);
}

void tukar(mhs *a, mhs *b)
{
    mhs temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(mhs mahasiswa[], int n)
{
    int i;
    printf("\nNo\tNama\tNilai\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%g\n", mahasiswa[i].no, mahasiswa[i].nama, mahasiswa[i].nilai);
    }
    printf("\n");
}