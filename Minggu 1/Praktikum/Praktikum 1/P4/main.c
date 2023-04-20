#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nama[50], n_grade;
    int NRP, n_tugas, n_UTS, n_UAS, n_akhir;
}nilai;

struct max{
    char nama[20];
    float nilai_tertinggi;
};

void input(nilai *mahasiswa, int);
void tampil(nilai *mahasiswa, int);

int nilai_akhir(int ,int, int);
char nilai_huruf(int);

int main()
{
    nilai mahasiswa[30];
    int n;
    printf("Berapa jumlah mahasiswa? ");
    scanf("%d", &n);

    input(mahasiswa, n);
    tampil(mahasiswa, n);
}

void input(nilai *mahasiswa, int n)
{
    int i;
    for(i=0; i<n; i++){
        printf("\nMahasiswa ke-%d", i+1);
        printf("\nNama\t\t: ");
        scanf("%s", &(*mahasiswa).nama);
        printf("Nilai tugas\t: ");
        fflush(stdin);
        scanf("%d", &(*mahasiswa).n_tugas);
        printf("Nilai uts\t: ");
        scanf("%d", &(*mahasiswa).n_UTS);
        printf("Nilai uas\t: ");
        scanf("%d", &(*mahasiswa).n_UAS);
        (*mahasiswa).n_akhir = nilai_akhir((*mahasiswa).n_tugas,
        (*mahasiswa).n_UTS, (*mahasiswa).n_UAS);

        (*mahasiswa).n_grade = nilai_huruf((*mahasiswa).n_akhir);
        mahasiswa++;
    }
}

void tampil(nilai *mahasiswa, int n)
{
    struct max highest;
    printf("\n\t\t\tDAFTAR NILAI\n");
    printf("\t\tMATAKULIAH KONSEP PEMROGRAMAN\n");
    printf("==================================================================\n");
    printf("No\tNama\t\t\t\t\tNilai\t\tGrade\n");
    printf("\tMahasiswa\t\tTugas\tUTS\tUAS\tAkhir\n");
    printf("==================================================================\n");

    for(int i=0; i<n; i++){

    float akhir = (0.2 * (*mahasiswa).n_tugas) + (0.4 * (*mahasiswa).n_UAS) + + (0.4 * (*mahasiswa).n_UTS);
    if(i == 0 || highest.nilai_tertinggi < akhir){
        strcpy(highest.nama,(*mahasiswa).nama);
        highest.nilai_tertinggi = akhir;
    }
        printf("%d\t%s\t\t%d\t%d\t%d\t%d\t%c\n", i+1, (*mahasiswa).nama, (*mahasiswa).n_tugas,
               (*mahasiswa).n_UTS, (*mahasiswa).n_UAS, (*mahasiswa).n_akhir, (*mahasiswa).n_grade);
               mahasiswa++;
    }
    printf("==================================================================\n");
    printf("Total mahasiswa = %d\n\n", n);

    printf("\n\nNilai Tertinggi");
    printf("\nNama mahasiswa\t= %s", highest.nama);
    printf("\nNilai\t= %g", highest.nilai_tertinggi);
}


int nilai_akhir(int tugas, int uts, int uas)
{
    int jumlah;
    jumlah = (2 * tugas / 10) + (4 * (uts + uas) / 10);
    return jumlah;
}

char nilai_huruf(int akhir)
{
    char grade;
    if(akhir >= 80)
        grade = 'A';
    else if(akhir >= 70)
        grade = 'B';
    else if(akhir >= 60)
        grade = 'C';
    else if(akhir >= 50)
        grade = 'D';
    else
        grade = 'E';

    return grade;
}
