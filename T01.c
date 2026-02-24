 //MarissaVictoriaSilalahi // 12S25055

#include <stdio.h>
#include <string.h>

int main() {

    char kode[10];
    int porsiButet;
    int porsiUcok;
    int totalPorsi;
    int harga = 0;
    int subtotal;
    int total = 0;

    float diskon = 0;
    float potongan;
    float totalBayar;

    printf("===== WARUNG MAK ROBY =====\n\n");

    while(1) {

        printf("Masukkan kode menu (END untuk selesai): ");
        scanf("%s", kode);

        if(strcmp(kode, "END") == 0) {
            break;
        }

        printf("Masukkan porsi Butet: ");
        scanf("%d", &porsiButet);

        // Perbandingan berat 2:1
        porsiUcok = 2 * porsiButet;
        totalPorsi = porsiButet + porsiUcok;

        // Menentukan harga
        if(strcmp(kode, "NGS") == 0) harga = 15000;
        else if(strcmp(kode, "AP") == 0) harga = 20000;
        else if(strcmp(kode, "SA") == 0) harga = 25000;
        else if(strcmp(kode, "BU") == 0) harga = 18000;
        else if(strcmp(kode, "MAP") == 0) harga = 15000;
        else if(strcmp(kode, "GG") == 0) harga = 15000;
        else if(strcmp(kode, "SAM") == 0) harga = 17000;
        else if(strcmp(kode, "RD") == 0) harga = 25000;
        else if(strcmp(kode, "IB") == 0) harga = 35000;
        else if(strcmp(kode, "NUK") == 0) harga = 20000;
        else {
            printf("Kode tidak ditemukan!\n\n");
            continue;
        }

        subtotal = totalPorsi * harga;
        total += subtotal;

        printf("Total porsi (Ucok + Butet) = %d\n", totalPorsi);
        printf("Subtotal = %d\n\n", subtotal);
    }

}

    // Menentukan diskon berdasarkan total
    