#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char nama[20];
    char gender;
    int no_id, tgl_lahir, gaji;
}pegawai;


void input(pegawai *data, int);
void tampil(pegawai *data, int);

int main()
{
    int n;
    pegawai emp[10];
    printf("\t\tDATA PEGAWAI\n\n");
    printf("Berapa jumlah pegawai : ");
    scanf("%d", &n);

    input(emp, n);
    tampil(emp, n);
}
 void input(pegawai *data, int n)
 {
     for(int i=0; i<n; i++){
        (*data).no_id = i+1;
        printf("\nData pegawai ke-%d", (*data).no_id);
        printf("\nNama\t\t\t: ");
        scanf("%s", &(*data).nama);
        fflush(stdin);
        printf("Tgl lahir (dd-mm-yyy)\t: ");
        scanf("%d", &(*data).tgl_lahir);
        fflush(stdin);
        printf("Jenis kelamin[L/P]\t: ");
        scanf("%s", &(*data).gender);
        fflush(stdin);
        printf("Gaji/bln\t\t: ");
        scanf("%d", &(*data).gaji);
        fflush(stdin);
        data++;
     }
 }

 void tampil(pegawai *data, int n)
 {
     printf("\n\nData pegawai yang telah diinputkan\n");
     for(int i=0; i<n; i++){
      printf("\nNo id\t\t: %d", (*data).no_id);
      printf("\nNama\t\t: %s", (*data).nama);
      printf("\nTgl lahir\t: %d", (*data).tgl_lahir);
      printf("\nJenis kelamin\t: %c", (*data).gender);
      printf("\nGaji/bln\t: %d\n", (*data).gaji);
      data++;
     }
 }
