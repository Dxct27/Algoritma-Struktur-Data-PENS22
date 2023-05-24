#include<stdio.h>
#include<stdlib.h>

typedef struct mhs
{
    int no;
    char nama[10];
    float nilai;
}mhs;

void selection(mhs *, int);
void insertion(mhs *, int);
void bubble(mhs [], int);
void shell(mhs [], int );
void tukar(int *, int*);
void tampil(mhs [], int);
void isiData(mhs *, int );
void menu(mhs *, int, int);
void mode_urut();

int mode;

int main()
{
    
    int n, pilihan_menu = 0;

    printf("Jumlah siswa yang akan dimasukkan : ");
    scanf("%d", &n);

    mhs mahasiswa[n];
    
    isiData(mahasiswa, n);

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

    switch(jwb)
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
}

void isiData(mhs *mahasiswa, int n)
{
    int i;
    char nama_temp[20];

    for (i = 0; i < n; i++)
    {
        printf("\nData siswa ke-%d :\n", i+1);
        printf("No\t: ");
        scanf("%d", &mahasiswa[i].no);
        fflush(stdin);
        printf("Nama\t: ");
        scanf("%s", mahasiswa[i].nama);
        //strcpy(mahasiswa[i].nama, nama_temp);
        fflush(stdin);
        printf("Nilai\t: ");
        scanf("%f", &mahasiswa[i].nilai);
        fflush(stdin);
    }
    
}


void selection(mhs *mahasiswa, int n)
{
    int i, j, min;

    for (i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(mode == 1 ? mahasiswa[j].no < mahasiswa[min].no : mahasiswa[j].no > mahasiswa[min].no)
            {
                min = j;
            }
        }
        tukar(&mahasiswa[min].no, &mahasiswa[i].no);
    }
    tampil(mahasiswa, n);
}

void insertion(mhs *mahasiswa, int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = mahasiswa[i].no;
        j = i - 1;
        while (j >= 0 && (mode == 1 ? mahasiswa[j].no > key : mahasiswa[j].no < key))
        {
            mahasiswa[j+1].no = mahasiswa[j].no;
            j--;
        }
        mahasiswa[j+1].no = key;
    }
    tampil(mahasiswa, n);
}

void bubble(mhs mahasiswa[], int n)
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
                if ( mode == 1 ? mahasiswa[j].no > mahasiswa[j+1].no : mahasiswa[j].no < mahasiswa[j+1].no)
                {
                    tukar(&mahasiswa[j].no, &mahasiswa[j+1].no);
                    did_swap = 1;
                }
            }            
        }
    }
}

void shell(mhs mahasiswa [], int n)
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
                if(mode == 1 ? mahasiswa[i].no > mahasiswa[i+jarak].no : mahasiswa[i].no < mahasiswa[i+jarak].no)
                {
                    tukar(&mahasiswa[i].no, &mahasiswa[i+jarak].no);
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

void tampil(mhs mahasiswa [], int n)
{
    int i;
    printf("\nNo\tNama\tNilai\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%g\n", mahasiswa[i].no, mahasiswa[i].nama, mahasiswa[i].nilai);
    }
    printf("\n");
}