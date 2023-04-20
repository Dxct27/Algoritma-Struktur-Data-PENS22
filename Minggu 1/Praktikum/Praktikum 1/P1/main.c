#include <stdio.h>
#include <stdlib.h>

struct mhs{
    char nama [30], n_grade;
    int n_tugas, n_UTS, n_UAS, n_akhir;
}mahasiswa [30];

void input(struct mhs mahasiswa[], int);
void tampil(struct mhs mahasiswa[], int);

int nilai_akhir(int, int, int);
char nilai_grade(int);

int main()
{
    int n;
    printf("MENGHITUNG NILAI AKHIR\n");
    printf("MATA KULIAH KONSEP PEMROGRAMAN\n\n");
    printf("Berapa jumlah mahasiswa ? ");
    scanf("%d", &n);
    printf("\nMasukan DATA Mahasiswa\n");

    input(mahasiswa, n);
    tampil(mahasiswa, n);
}

void input(struct mhs mahasiswa[], int n)
{
    int i;
    for(i=0; i<n; i++){
        printf("\nMahasiswa ke %d", i+1);
        printf("\nNama\t\t : ");
        scanf("%s", &mahasiswa[i].nama);
        fflush(stdin);
        printf("Nilai tugas\t : ");
        scanf("%d", &mahasiswa[i].n_tugas);
        printf("Nilai uts\t : ");
        scanf("%d", &mahasiswa[i].n_UTS);
        printf("Nilai uas\t : ");
        scanf("%d", &mahasiswa[i].n_UAS);
    }
    for(i=0; i<n; i++){
        mahasiswa[i].n_akhir = nilai_akhir(mahasiswa[i].n_tugas,
        mahasiswa[i].n_UTS, mahasiswa[i].n_UAS);

        mahasiswa[i].n_grade = nilai_grade(mahasiswa[i].n_akhir);
    }
}

void tampil(struct mhs mahasiswa[], int n)
{
    printf("\n\t\tDAFTAR NILAI\n");
    printf("\t\tMATAKULIAH KONSEP PEMROGRAMAN\n");
    printf("----------------------------------------\n");
    printf("No\tNama\t\t\t\tNilai\t\tGrade\n");
    printf("\tMahasiswa\t\tTugas\tUTS\tUAS\tAhir\n");
    printf("----------------------------------------\n");
    for(int i=0; i<n; i++){
        printf("%d\t%s\t\t%d\t%d\t%d\t%d\t%c\n", i+1, mahasiswa[i].nama,
               mahasiswa[i].n_tugas, mahasiswa[i].n_UTS, mahasiswa[i].n_UAS,
               mahasiswa[i].n_akhir, mahasiswa[i].n_grade);
    }
    printf("----------------------------------------\n");
    printf("\nTotal Mahasiswa = %d\n", n);
}

int nilai_akhir(int tugas, int uts, int uas)
{
    int jumlah;
    jumlah = (2*tugas/10) +( 4*(uts+uas)/10);
    return jumlah;
}

char nilai_grade(int akhir)
{
    char grade;
    if(akhir >= 80)
        grade='A';
    else if(akhir >= 70)
        grade='B';
    else if(akhir >= 60)
        grade='C';
    else if(akhir >= 50)
        grade='D';
    else
        grade='E';
    return grade;
}
