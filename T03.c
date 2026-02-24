// MarissaVictoriaSilalahi // 12S25055

#include <stdio.h>
#include <string.h>

// 1. Definisi Struktur Data Pesanan
typedef struct {
    int idPesanan;
    char nama[50];
    float berat;
    int jenisLayanan; // 1: Reguler (Rp 6000/kg), 2: Kilat (Rp 10000/kg)
    int totalHarga;
    int status;       // 0: Diproses, 1: Selesai
} Pesanan;

// Variabel Global untuk menyimpan data
Pesanan database[100];
int totalPesanan = 0;
int pendapatanHarian = 0;

// 2. Modul Fungsi: Menambah Pesanan Baru
void tambahPesanan() {
    printf("\n--- TAMBAH PESANAN BARU ---\n");
    database[totalPesanan].idPesanan = totalPesanan + 1;
    
    printf("Nama Pelanggan: ");
    scanf(" %[^\n]", database[totalPesanan].nama); // Membaca string dengan spasi
    
    printf("Berat Pakaian (kg): ");
    scanf("%f", &database[totalPesanan].berat);
    
    printf("Pilih Layanan (1: Reguler Rp6.000/kg, 2: Kilat Rp10.000/kg): ");
    scanf("%d", &database[totalPesanan].jenisLayanan);
    
    // Hitung total harga
    if (database[totalPesanan].jenisLayanan == 1) {
        database[totalPesanan].totalHarga = database[totalPesanan].berat * 6000;
    } else {
        database[totalPesanan].totalHarga = database[totalPesanan].berat * 10000;
    }
    
    database[totalPesanan].status = 0; // Set status awal ke 'Diproses'
    
    printf("Pesanan berhasil ditambahkan! Total Tagihan: Rp %d\n", database[totalPesanan].totalHarga);
    totalPesanan++;
}

// 3. Modul Fungsi: Menampilkan Semua Pesanan
void tampilkanPesanan() {
    printf("\n--- DAFTAR PESANAN LAUNDRY DEL ---\n");
    if (totalPesanan == 0) {
        printf("Belum ada pesanan hari ini.\n");
        return;
    }
    
    printf("ID\tNama\t\tBerat\tLayanan\tTotal Harga\tStatus\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < totalPesanan; i++) {
        char namaLayanan[10];
        char namaStatus[15];
        
        strcpy(namaLayanan, (database[i].jenisLayanan == 1) ? "Reguler" : "Kilat");
        strcpy(namaStatus, (database[i].status == 0) ? "Diproses" : "Selesai");
        
        printf("%d\t%s\t\t%.1f kg\t%s\tRp %d\t%s\n", 
               database[i].idPesanan, database[i].nama, database[i].berat, 
               namaLayanan, database[i].totalHarga, namaStatus);
    }
}

// 4. Modul Fungsi: Menyelesaikan Pesanan
void selesaikanPesanan() {
    int id;
    printf("\n--- SELESAIKAN PESANAN ---\n");
    printf("Masukkan ID Pesanan yang sudah selesai: ");
    scanf("%d", &id);
    
    if (id > 0 && id <= totalPesanan) {
        if (database[id-1].status == 0) {
            database[id-1].status = 1;
            pendapatanHarian += database[id-1].totalHarga;
            printf("Status pesanan %s berhasil diubah menjadi Selesai.\n", database[id-1].nama);
        } else {
            printf("Pesanan ini sudah diselesaikan sebelumnya.\n");
        }
    } else {
        printf("ID Pesanan tidak ditemukan!\n");
    }
}

// 5. Program Utama
int main() {
    int pilihan;
    
    do {
        printf("\n=================================\n");
        printf("   SISTEM MANAJEMEN LAUNDRY DEL  \n");
        printf("=================================\n");
        printf("1. Tambah Pesanan Baru\n");
        printf("2. Lihat Daftar Pesanan\n");
        printf("3. Selesaikan Pesanan\n");
        printf("4. Lihat Laporan Pendapatan Harian\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1: tambahPesanan(); break;
            case 2: tampilkanPesanan(); break;
            case 3: selesaikanPesanan(); break;
            case 4: 
                printf("\nTotal Pendapatan Harian: Rp %d\n", pendapatanHarian); 
                break;
            case 0: printf("Terima kasih telah menggunakan sistem Laundry Del!\n"); break;
            default: printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}