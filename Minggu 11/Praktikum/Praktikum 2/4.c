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

    // printf("Jumlah siswa yang akan dimasukkan : ");
    // scanf("%d", &n);

    // mhs mahasiswa[n];

    mhs mahasiswa[5] = {5, "Seulgi", 'B', 3, "Irene", 'A', 10, "Yerim", 'C', 2, "Joy", 'C', 7, "Wendy", 'A'};

    // isiData(mahasiswa, n);

    while (pilihan_menu != 5)
    {
        printf("\nMENU METODE SORTING\n");
        printf("1. Insertion sort\n");
        printf("2. Selection sort\n");
        printf("3. Bubble sort\n");
        printf("4. Shell sort\n");
        printf("5. Keluar\n");
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
                    kondisi = strcmp(mahasiswa[j].nama, mahasiswa[min].nama) <= 0;
                }
                else
                    kondisi = strcmp(mahasiswa[j].nama, mahasiswa[min].nama) >= 0;
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