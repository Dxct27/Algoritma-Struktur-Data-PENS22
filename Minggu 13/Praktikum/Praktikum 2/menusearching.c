#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mhs
{
    int no;
    char nama[10];
    float nilai;
} mhs;


void mergeSortRekursif(mhs [], int , int);
void merge(mhs [], int , int, int);


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
