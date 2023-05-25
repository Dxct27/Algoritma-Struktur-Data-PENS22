#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mhs
{
    int no;
    char nama[10];
    float nilai;
} mhs;

void seq(mhs[], int);
void bin(mhs[], int);
void mergeSortRekursif(mhs[], int, int);
void merge(mhs[], int, int, int);
void tampil(mhs[], int);
void isiData(mhs[], int);
void menu(mhs[], int, int);
void menu_tampilan_data(mhs[], int);
void menu_pencarian();

int pilihan_cari;

int main()
{
    int pilihan_menu, n;
    mhs mahasiswa[30];

    printf("Berapa Jumlah data (maks 30) ? ");
    scanf("%d", &n);

    isiData(mahasiswa, n);

    while (pilihan_menu = 4)
    {
        printf("\nMENU METODE SEARCHING\n");
        printf("1. Tampilkan Data\n");
        printf("2. Sequential Search\n");
        printf("3. Binary Search\n");
        printf("4. Keluar\n");
        printf("Pilihan anda [1/2/3/4] : ");
        scanf("%d", &pilihan_menu);

        menu(mahasiswa, n, pilihan_menu);
    }

    return 0;
}

void menu(mhs mahasiswa[], int n, int pilihan_menu)
{
    switch (pilihan_menu)
    {
    case 1:
        menu_tampilan_data(mahasiswa, n);
        break;
    case 2:
        seq(mahasiswa, n);
        break;
    case 3:
        bin(mahasiswa, n);
        break;
    case 4:
        exit(1);
        break;
    default:
        printf("Pilihan Anda Invalid\n");
        break;
    }
}

void menu_tampilan_data(mhs mahasiswa[], int n)
{
    int pilihan, i;
    mhs mhs_urut[n];

    printf("\nBENTUK DATA\n");
    printf("1. Tidak Terurut\n");
    printf("2. Terurut Berdasarkan No\n");
    printf("Pilihan Anda [1/2] : ");
    scanf("%d", &pilihan);

    if (pilihan == 1)
    {
        tampil(mahasiswa, n);
    }
    else if (pilihan == 2)
    {
        for (i = 0; i <= n; i++)
        {
            mhs_urut[i].no = mahasiswa[i].no;
            strcpy(mhs_urut[i].nama, mahasiswa[i].nama);
            mhs_urut[i].nilai = mahasiswa[i].nilai;
        }
        mergeSortRekursif(mhs_urut, 0, n - 1);
        tampil(mhs_urut, n);
    }
    else
        printf("Pilihan Anda invalid\n");
}

void menu_pencarian()
{
    printf("\nPENCARIAN BERDASARKAN\n");
    printf("1. No\n");
    printf("2. Nama\n");
    printf("Pilihan Anda [1/2] : ");
    scanf("%d", &pilihan_cari);
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

void seq(mhs mahasiswa[], int n)
{
    int i, ketemu = 0;
    int key_no;
    char key_nama[20];

    menu_pencarian();

    if (pilihan_cari == 1)
    {
        printf("Masukkan no mhs yang akan dicari : ");
        scanf("%d", &key_no);

        for (i = 0; i < n; i++)   
        {
            if (mahasiswa[i].no == key_no)
            {
                ketemu = 1;
                break;
            }
        }
    }
    else if (pilihan_cari == 2)
    {
        printf("Masukkan nama mhs yang akan dicari : ");
        scanf("%s", key_nama);

        for (i = 0; i < n; i++)
        {
            if (strcmp(mahasiswa[i].nama, key_nama) == 0)
            {
                ketemu = 1;
                break;
            }
        }
    }
    else
    {
        printf("Pilihan Anda Invalid\n");
        return;
    }

    if (ketemu)
    {
        printf("\nData ketemu pada indeks %d\n", i);
    }
    else
    {
        printf("Data tidak ditemukan\n");
    }
}

void bin(mhs mahasiswa[], int n)
{
    int l, r, med, ketemu;
    int key_no;
    char key_nama[20];

    menu_pencarian();

    l = 0;
    r = n - 1;
    ketemu = 0;

    if (pilihan_cari == 1)
    {
        printf("Masukkan no mhs yang akan dicari : ");
        scanf("%d", &key_no);

        while (l <= r && !ketemu)
        {
            med = (l + r) / 2;

            if (mahasiswa[med].no == key_no)
            {
                ketemu = 1;
            }
            else if (key_no == key_no < mahasiswa[med].no)
            {
                r = med - 1;
            }
            else
                l = med + 1;
        }
    }
    else if (pilihan_cari == 2)
    {
        
        printf("Masukkan nama mhs yang akan dicari : ");
        scanf("%s", key_nama);

        while (l <= r && !ketemu)
        {
            med = (l + r) / 2;

            if (strcmp(mahasiswa[med].nama, key_nama) == 0)
            {
                ketemu = 1;
            }
            else if (strcmp(key_nama, mahasiswa[med].nama) < 0)
            {
                r = med - 1;
            }
            else
                l = med + 1;
        }
    }
    else
    {
        printf("Pilihan Anda Invalid\n");
        return;
    }
    
    if (ketemu)
    {
        printf("\nData ketemu pada indeks %d\n", med);
    }
    else
    {
        printf("Data tidak ditemukan\n");
    }
}

void mergeSortRekursif(mhs mahasiswa[], int l, int r)
{
    int med;
    if (l < r)
    {
        med = (l + r) / 2;
        mergeSortRekursif(mahasiswa, l, med);
        mergeSortRekursif(mahasiswa, med + 1, r);
        merge(mahasiswa, l, med, r);
    }
}

void merge(mhs mahasiswa[], int l, int m, int r)
{
    int i, j, ki1, ki2, ka1, ka2;
    mhs hasil[r + 1];

    ki1 = l;
    ka1 = m;
    ki2 = m + 1;
    ka2 = r;
    i = l;

    while (ki1 <= ka1 && ki2 <= ka2)
    {
        if (mahasiswa[ki1].no <= mahasiswa[ki2].no)
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
