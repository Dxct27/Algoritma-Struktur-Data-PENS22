#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct mhs
{
    int no;
    char nama[10];
    float nilai;
}mhs;


void shell(mhs [], int);
void input(mhs *, int);
void tukar(int *, int*);
void tampil(mhs []);

int main()
{
    mhs mahasiswa[MAX] = {5,"Seulgi",'B',3,"Irene",'A',10,"Yerim",'C',2,"Joy",'C',7,"Wendy",'A'};
    puts("Before");
    tampil(mahasiswa);
    shell(mahasiswa, MAX);
    puts("After");
    tampil(mahasiswa);
    return 0;
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
                if(mahasiswa[i].no > mahasiswa[i+jarak].no)
                {
                    tukar(&mahasiswa[i].no, &mahasiswa[i+jarak].no);
                    did_swap = 1;
                }
            }
            //tampil(mahasiswa);
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

void tampil(mhs mahasiswa [])
{
    int i;
    printf("\nNo\tNama\tNilai\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d\t%s\t%g\n", mahasiswa[i].no, mahasiswa[i].nama, mahasiswa[i].nilai);
    }
    printf("\n");
}
