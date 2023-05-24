#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct mhs
{
    int no;
    char nama[10];
    float nilai;
}mhs;


void bubble(mhs [], int);
void input(mhs *, int);
void tukar(int *, int*);
void tampil(mhs []);

int main()
{
    mhs mahasiswa[MAX] = {5,"Seulgi",'B',3,"Irene",'A',10,"Yerim",'C',2,"Joy",'C',7,"Wendy",'A'};
    puts("Before");
    tampil(mahasiswa);
    bubble(mahasiswa, MAX);
    puts("After");
    tampil(mahasiswa);
    return 0;
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
                if (mahasiswa[j].no > mahasiswa[j+1].no)
                {
                    tukar(&mahasiswa[j].no, &mahasiswa[j+1].no);
                    did_swap = 1;
                }
                //tampil(mahasiswa);
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
