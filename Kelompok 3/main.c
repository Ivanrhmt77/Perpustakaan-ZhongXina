#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

struct identitas{
    char nama[50];
    char id[15];
};

struct informasi{
    int kode;
    char judul[50];
    char penulis[50];
    int jumlah;
    int ada;
    int dipinjam;
};

struct pinjam{
    struct identitas peminjam;
    struct informasi book;
    char status[15];
};

void daftar(struct identitas [], int *);
void daftarAnggota(struct identitas [], int *);
void daftarBuku(struct informasi []);
void cariBuku(struct informasi []);
void pinjamBuku(struct identitas [], struct informasi [], struct pinjam [], int *);
void kembalikanBuku(struct identitas [], struct informasi [], struct pinjam [], int *);
void statusBuku(struct informasi []);
void riwayatPinjam(struct pinjam [], int *);
int main()
{
    struct identitas anggota[MAX];
    struct informasi buku[MAX] = {
        {1, "Berserk", "Kentarou Miura", 10, 10, 0},
        {2, "Steel Ball Run", "Hirohiko Araki", 23, 23, 0},
        {3, "Vagabond", "Takehiko Inoue", 3, 3, 0},
        {4, "One Piece", "Eiichiro Oda", 50, 50, 0},
        {5, "Monster", "Naoki Urasawa", 34, 34, 0},
        {6, "Slam Dunk", "Takehiko Inoue", 1, 1, 0},
        {7, "Vinland Saga", "Makoto Yukimura", 30, 30, 0},
        {8, "Fullmetal Alchemist", "Hiromu Arakawa", 8, 8, 0},
        {9, "Grand Blue", "Kenji Inoue", 5, 5, 0},
        {10, "Oyasumi Punpun", "Inio Asano", 15, 15, 0}
    };
    struct pinjam perpustakaan[MAX];
    int pilih, jumlahAnggota = 0, jumlahPinjam = 0;

    while(1){
        printf("==========================================\n");
        printf("|        PERPUSTAKAAN ZHONG XINA         |\n");
        printf("==========================================\n");
        printf("| No.\t| Menu\t\t\t\t |\n");
        printf("==========================================\n");
        printf("| 1.\t| Register\t\t\t |\n");
        printf("| 2.\t| Daftar Anggota\t\t |\n");
        printf("| 3.\t| Daftar Buku\t\t\t |\n");
        printf("| 4.\t| Pencarian Buku\t\t |\n");
        printf("| 5.\t| Meminjam Buku\t\t\t |\n");
        printf("| 6.\t| Mengembalikan Buku\t\t |\n");
        printf("| 7.\t| Status Buku\t\t\t |\n");
        printf("| 8.\t| Riwayat Peminjaman\t\t |\n");
        printf("| 0.\t| Keluar dari program\t\t |\n");
        printf("------------------------------------------\n");

        printf("\nMasukkan Pilihan: ");
        scanf("%d", &pilih);
        fflush(stdin);
        printf("\n");

        switch(pilih){
        case 1:
            daftar(anggota, &jumlahAnggota);
            break;
        case 2:
            daftarAnggota(anggota, &jumlahAnggota);
            break;
        case 3:
            daftarBuku(buku);
            break;
        case 4:
            cariBuku(buku);
            break;
        case 5:
            pinjamBuku(anggota, buku, perpustakaan, &jumlahPinjam);
            break;
        case 6:
            kembalikanBuku(anggota, buku, perpustakaan, &jumlahPinjam);
            break;
        case 7:
            statusBuku(buku);
            break;
        case 8:
            riwayatPinjam(perpustakaan, &jumlahPinjam);
            break;
        case 0:
            return 0;
        default:
            printf("Pilihan Tidak Ada :(\n\n");
            break;
        }
    }
    return 0;
}

void daftar(struct identitas anggota[], int *jumlahAnggota){
    char lagi, kembali;
    int i, j;

    do{
        printf("Masukkan Nama: ");
        gets(anggota[*jumlahAnggota].nama);
        printf("Masukkan ID : ");
        gets(anggota[*jumlahAnggota].id);

        for(j = 0; j < *jumlahAnggota; j++){
            if(strcmp(anggota[*jumlahAnggota].id, anggota[j].id) == 0){
                printf("ID sudah terdaftar!\n");
                printf("Masukkan ID : ");
                gets(anggota[*jumlahAnggota].id);
            }
        }

        printf("\nIngin mendaftarkan anggota lagi (y/t) ? ");
        scanf("%c", &lagi);
        fflush(stdin);
        printf("\n");
        (*jumlahAnggota)++;
    }while(lagi == 'Y' || lagi == 'y');

    for(i = 0; i < *jumlahAnggota; i++){
        printf("%s telah menjadi anggota dari Perpustakaan Zhong Xina\n", anggota[i].nama);
    }
    printf("\n");

    do{
        printf("Tekan Enter untuk kembali ");
        scanf("%c", &kembali);
        fflush(stdin);
        printf("\n");
    }while(kembali != '\n');
}

void daftarAnggota(struct identitas anggota[], int *jumlahAnggota){
    int i;
    char kembali;

    printf("==========================================================================\n");
    printf("|                 DAFTAR ANGGOTA PERPUSTAKAAN ZHONG XINA                 |\n");
    printf("==========================================================================\n");
    printf("| No.\t| \t\t\tNama\t\t\t | \tID\t |\n");
    printf("==========================================================================\n");
    for(i = 0; i < *jumlahAnggota; i++){
        printf("| %d.\t| %-46s | %-13s |\n", i+1, anggota[i].nama, anggota[i].id);
    }
    printf("--------------------------------------------------------------------------\n\n");

    do{
        printf("Tekan Enter untuk kembali ");
        scanf("%c", &kembali);
        fflush(stdin);
        printf("\n");
    }while(kembali != '\n');
}

void daftarBuku(struct informasi buku[]){
    int i;
    char kembali;

    printf("===========================================================================================================\n");
    printf("|                                   DAFTAR BUKU PERPUSTAKAAN ZHONG XINA                                   |\n");
    printf("===========================================================================================================\n");
    printf("| Kode\t| \t\t\tJudul\t\t\t | \t\t\tPenulis\t\t\t  |\n");
    printf("===========================================================================================================\n");
    for(i = 0; i < 10; i++){
        printf("| %.3d\t| %-46s | %-46s |\n", buku[i].kode, buku[i].judul, buku[i].penulis);
    }
    printf("-----------------------------------------------------------------------------------------------------------\n\n");

    do{
        printf("Tekan Enter untuk kembali ");
        scanf("%c", &kembali);
        fflush(stdin);
        printf("\n");
    }while(kembali != '\n');
}

void cariBuku(struct informasi buku[]){
    char cari[50], kembali;
    int i, j = 0, found[MAX];

    printf("Cari Buku: ");
    gets(cari);
    printf("\n");

    for(i = 0; i < 10; i++){
        if(strstr(buku[i].judul, cari) != NULL || strstr(buku[i].penulis, cari) != NULL){
            found[j] = i+1;
            j++;
        }
    }

    j = 0;

    printf("===========================================================================================================\n");
    printf("|                                   DAFTAR BUKU PERPUSTAKAAN ZHONG XINA                                   |\n");
    printf("===========================================================================================================\n");
    printf("| Kode\t| \t\t\tJudul\t\t\t | \t\t\tPenulis\t\t\t  |\n");
    printf("===========================================================================================================\n");
    for(i = 0; i < 10; i++){
        if(buku[i].kode == found[j]){
            printf("| %.3d\t| %-46s | %-46s |\n", buku[i].kode, buku[i].judul, buku[i].penulis);
            j++;
        }
    }
    printf("-----------------------------------------------------------------------------------------------------------\n\n");

    do{
        printf("Tekan Enter untuk kembali ");
        scanf("%c", &kembali);
        fflush(stdin);
        printf("\n");
    }while(kembali != '\n');
}

void pinjamBuku(struct identitas anggota[], struct informasi buku[], struct pinjam perpustakaan[], int *jumlahPinjam){
    char inputID[15], ask, lain, kembali;
    int valid = 0, i, batas = 0, foundID = 0, j, inputKode, foundKode = 0;

    do{
        printf("Masukkan ID Anggota: ");
        gets(inputID);

        for(i = 0; i < MAX; i++){
            if(strcmp(inputID, anggota[i].id) == 0){
                printf("\nNama : %s\n", anggota[i].nama);
                printf("ID : %s\n\n", anggota[i].id);

                printf("===========================================================================================================\n");
                printf("|                                   DAFTAR BUKU PERPUSTAKAAN ZHONG XINA                                   |\n");
                printf("===========================================================================================================\n");
                printf("| Kode\t| \t\t\tJudul\t\t\t | \t\t\tPenulis\t\t\t  |\n");
                printf("===========================================================================================================\n");
                for(j = 0; j < 10; j++){
                    printf("| %.3d\t| %-46s | %-46s |\n", buku[j].kode, buku[j].judul, buku[j].penulis);
                }
                printf("-----------------------------------------------------------------------------------------------------------\n\n");

                do{
                    printf("Masukkan Kode Buku Untuk Meminjam: ");
                    scanf("%d", &inputKode);
                    fflush(stdin);

                    for(j = 0; j < MAX; j++){
                        if(inputKode == buku[j].kode){
                            if(buku[j].ada <= 0){
                                printf("\nMaaf, Buku sedang dipinjam\n");
                                printf("Ingin meminjam buku lain (y/t) ? ");
                                scanf("%c", &lain);
                                printf("\n");
                                fflush(stdin);

                                if(lain != 'y' && lain != 'Y'){
                                    foundKode++;
                                }
                            } else {
                                strcpy(perpustakaan[*jumlahPinjam].peminjam.nama, anggota[i].nama);
                                strcpy(perpustakaan[*jumlahPinjam].peminjam.id, anggota[i].id);
                                strcpy(perpustakaan[*jumlahPinjam].book.judul, buku[j].judul);
                                strcpy(perpustakaan[*jumlahPinjam].status, "Dipinjam");
                                perpustakaan[*jumlahPinjam].book.kode = buku[j].kode;
                                buku[j].ada--;
                                buku[j].dipinjam++;
                                (*jumlahPinjam)++;

                                printf("\n%s berhasil meminjam buku yang berjudul %s\n\n", anggota[i].nama, buku[j].judul);
                                foundKode++;
                            }
                        }
                    }
                }while(foundKode == 0);

                foundID++;
                valid++;
                break;
            }
        }

        if(foundID == 0){
            printf("ID tidak terdaftar!!\n");
            batas++;
            if(batas > 3){
                printf("\nSudah mendaftar menjadi anggota Perpustakaan Zhong Xina (y/t) ? ");
                scanf("%c", &ask);
                fflush(stdin);
                printf("\n");
                if(ask == 'y' || ask == 'Y'){
                    batas = 0;
                } else {
                    printf("Silakan melakukan Registerasi terlebih dahulu!\n\n");
                    valid++;
                }
            }
        }
    }while(valid == 0);

    do{
        printf("Tekan Enter untuk kembali ");
        scanf("%c", &kembali);
        fflush(stdin);
        printf("\n");
    }while(kembali != '\n');
}

void kembalikanBuku(struct identitas anggota[], struct informasi buku[], struct pinjam perpustakaan[], int *jumlahPinjam){
    char inputID[15], ask, lain, kembali;
    int valid = 0, i, foundID = 0, j, inputKode, foundKode = 0;

    do{
        printf("Masukkan ID Anggota: ");
        gets(inputID);
        printf("Masukkan Kode Buku yang dipinjam: ");
        scanf("%d", &inputKode);
        fflush(stdin);

        for(i = 0; i < *jumlahPinjam; i++){
            if(strcmp(inputID, perpustakaan[i].peminjam.id) == 0 && inputKode == perpustakaan[i].book.kode){
                for(j = 0; j < MAX; j++){
                    if(inputKode == buku[j].kode && inputKode == perpustakaan[i].book.kode){
                        buku[j].ada++;
                        buku[j].dipinjam--;
                        strcpy(perpustakaan[i].status, "Dikembalikan");

                        printf("\n%s berhasil mengembalikan buku yang berjudul %s\n\n", perpustakaan[i].peminjam.nama, buku[j].judul);
                    }
                }
                foundKode++;
                foundID++;
                valid++;
                break;
            }
        }

        for(i = 0; i < MAX; i++){
            if(strcmp(inputID, perpustakaan[i].peminjam.id) == 0){
                foundID++;
                break;
            }
            if(inputKode == perpustakaan[i].book.kode){
                foundKode++;
                break;
            }
        }

        if(foundID == 0){
            for(i = 0; i < MAX; i++){
                if(strcmp(inputID, anggota[i].id) == 0){
                    printf("\nAnda belum meminjam buku\n\n");
                    break;
                } else {
                    printf("\nID tidak terdaftar!!\n\n");
                    break;
                }
            }
            foundKode++;
            valid++;
        }
        if(foundKode == 0){
            if(inputKode > 10){
                printf("\nBuku tidak ada dalam daftar buku\n\n");
            } else {
                printf("\nAnda tidak meminjam buku %s\n\n", buku[inputKode-1].judul);
            }
            valid++;
        }
    }while(valid == 0);

    do{
        printf("Tekan Enter untuk kembali ");
        scanf("%c", &kembali);
        fflush(stdin);
        printf("\n");
    }while(kembali != '\n');
}

void statusBuku(struct informasi buku[]){
    int i;
    char kembali;

    printf("==================================================================================================\n");
    printf("|                                         Status Buku                                            |\n");
    printf("==================================================================================================\n");
    printf("| \t\t\tJudul\t\t\t | Jumlah\t | Tersedia\t | Dipinjam\t |\n");
    printf("==================================================================================================\n");
    for(i = 0; i < 10; i++){
        printf("| %-46s | %d\t\t | %d\t\t | %d\t\t |\n", buku[i].judul, buku[i].jumlah, buku[i].ada, buku[i].dipinjam);
    }
    printf("--------------------------------------------------------------------------------------------------\n\n");

    do{
        printf("Tekan Enter untuk kembali ");
        scanf("%c", &kembali);
        fflush(stdin);
        printf("\n");
    }while(kembali != '\n');
}

void riwayatPinjam(struct pinjam perpustakaan[], int *jumlahPinjam){
    int i;
    char kembali;

    printf("==========================================================================================================================================\n");
    printf("|                                                       Riwayat Peminjaman Buku                                                          |\n");
    printf("==========================================================================================================================================\n");
    printf("| No.\t| \t\t\tNama\t\t\t | \tID\t | \t\t\tJudul\t\t\t | Status\t |\n");
    printf("==========================================================================================================================================\n");
    for(i = 0; i < *jumlahPinjam; i++){
        printf("| %d.\t| %-46s | %-13s | %-45s | %-13s |\n", i+1, perpustakaan[i].peminjam.nama, perpustakaan[i].peminjam.id, perpustakaan[i].book.judul, perpustakaan[i].status);
    }
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    do{
        printf("Tekan Enter untuk kembali ");
        scanf("%c", &kembali);
        fflush(stdin);
        printf("\n");
    }while(kembali != '\n');
}
