// MarissaVictoriaSilalahi // 12S25055

#include <stdio.h>

int main() {
    // 1. Deklarasi Variabel
    int N;              // Jumlah total data siswa
    int nilai[100];     // Array untuk menyimpan nilai (maksimal 100 data)
    int kode_kelompok;  // Kode kelompok yang diminta (1 atau 2)
    int total = 0;      // Variabel penampung hasil penjumlahan
    int i;              // Variabel iterator untuk looping

    // 2. Input Jumlah Data (N)
    printf("Masukkan Jumlah Total Data (N): ");
    scanf("%d", &N);

    // 3. Input Deret Nilai Siswa
    printf("Masukkan %d Nilai Siswa:\n", N);
    for (i = 0; i < N; i++) {
        printf("Nilai siswa ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
    }

    // 4. Input Kode Kelompok
    printf("\nMasukkan Kode Kelompok (1 untuk Ganjil, 2 untuk Genap): ");
    scanf("%d", &kode_kelompok);

    // 5. Proses Penjumlahan Berdasarkan Kelompok
    // Kita melakukan loop dari 0 sampai N-1
    for (i = 0; i < N; i++) {
        int posisi_sekarang = i + 1; // Mengubah index 0 menjadi posisi 1 (manusiawi)

        if (kode_kelompok == 1) {
            // Jika kode 1, cari posisi GANJIL (1, 3, 5...)
            // Ganjil adalah jika posisi modulus 2 sisa 1
            if (posisi_sekarang % 2 != 0) {
                total += nilai[i];
            }
        } 
        else if (kode_kelompok == 2) {
            // Jika kode 2, cari posisi GENAP (2, 4, 6...)
            // Genap adalah jika posisi modulus 2 sisa 0
            if (posisi_sekarang % 2 == 0) {
                total += nilai[i];
            }
        }
    }

    // 6. Output Hasil
    printf("\n------------------------------\n");
    printf("Total Nilai Kelompok %d adalah: %d\n", kode_kelompok);
    printf("------------------------------\n");

    return 0;
}