// UTS Praktikum Paket B: Fotokopi Kampus.
// Lengkapi TODO 1 sampai TODO 6 sesuai lembar soal. Bagian yang sudah ada jangan diubah kecuali diminta.
// Bangun dengan baseline kelas; program harus bebas warning. Uji dengan: ./fotokopi < contoh_masukan.txt
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int HARGA_KECIL = 300;     // 1 sampai 50 halaman
    const int HARGA_SEDANG = 250;    // 51 sampai 200 halaman
    const int HARGA_BESAR = 200;     // lebih dari 200 halaman
    const int BATAS_KECIL = 50;
    const int BATAS_SEDANG = 200;
    const int MAKS_HALAMAN = 1000;

    int jumlah = 0;
    cout << "=== Fotokopi Kampus ===\n";
    cout << "Jumlah pesanan: ";
    cin >> jumlah;
    while (cin.fail() || jumlah < 1) {           // contoh pembacaan aman; pakai pola ini untuk halaman
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat paling sedikit 1. Jumlah pesanan: ";
        cin >> jumlah;
    }
    cin.ignore(1000, '\n');

    cout << fixed << setprecision(2);

    int total_halaman = 0;
    int total_pendapatan = 0;
    int banyak_kecil = 0;
    int banyak_sedang = 0;
    int banyak_besar = 0;
    // TODO 5a: deklarasikan penampung biaya terbesar (mulai -1) dan nama pemesannya.
    int biaya_terbesar = -1;
    string nama_terbesar;

    for (int i = 1; i <= jumlah; i++) {
        string nama;
        int halaman = 0;
        char warna = ' ';

        cout << "\n--- Pesanan ke-" << i << " dari " << jumlah << " ---\n";

        // TODO 1: baca nama sampai sah, lalu rapikan menjadi Huruf Besar Di Awal Kata.
        bool nama_sah = false;
        do {
            cout << "Nama pemesan : ";
            getline(cin, nama);

            if (nama.find_first_not_of(" \t\r\n") == string::npos) {
                cout << "Nama tidak boleh kosong.\n";
            } else {
                bool mengandung_angka = false;
                for (char karakter : nama) {
                    if (isdigit(static_cast<unsigned char>(karakter))) {
                        mengandung_angka = true;
                        break;
                    }
                }

                if (mengandung_angka) {
                    cout << "Nama tidak boleh mengandung angka.\n";
                } else {
                    bool awal_kata = true;
                    for (char &karakter : nama) {
                        if (isspace(static_cast<unsigned char>(karakter))) {
                            awal_kata = true;
                        } else if (awal_kata) {
                            karakter = static_cast<char>(toupper(static_cast<unsigned char>(karakter)));
                            awal_kata = false;
                        } else {
                            karakter = static_cast<char>(tolower(static_cast<unsigned char>(karakter)));
                        }
                    }
                    nama_sah = true;
                }
            }
        } while (!nama_sah);

        // TODO 2: baca halaman dengan aman (bilangan bulat 1 sampai MAKS_HALAMAN).
        cout << "Halaman (1-" << MAKS_HALAMAN << "): ";
        while (true) {
            if (!(cin >> halaman)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Harus bilangan bulat 1 sampai 1000. Halaman: ";
            } else if (halaman < 1 || halaman > MAKS_HALAMAN) {
                cin.ignore(1000, '\n');
                cout << "Harus bilangan bulat 1 sampai 1000. Halaman: ";
            } else {
                cin.ignore(1000, '\n');
                break;
            }
        }

        // TODO 3: baca warna, jadikan huruf besar, ulangi selama bukan 'Y' atau 'T'.
        cout << "Berwarna (Y/T): ";
        string masukan_warna;
        while (true) {
            if (!(cin >> masukan_warna)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Hanya Y atau T. Berwarna (Y/T): ";
                continue;
            }

            if (masukan_warna.size() == 1) {
                warna = static_cast<char>(toupper(static_cast<unsigned char>(masukan_warna[0])));
            } else {
                warna = ' ';
            }

            cin.ignore(1000, '\n');
            if (warna == 'Y' || warna == 'T') {
                break;
            }
            cout << "Hanya Y atau T. Berwarna (Y/T): ";
        }

        // TODO 4: tentukan harga, hitung kategori, dan hitung biaya.
        int biaya = 0;
        int harga_per_halaman = 0;

        if (halaman <= BATAS_KECIL) {
            harga_per_halaman = HARGA_KECIL;
            banyak_kecil++;
        } else if (halaman <= BATAS_SEDANG) {
            harga_per_halaman = HARGA_SEDANG;
            banyak_sedang++;
        } else {
            harga_per_halaman = HARGA_BESAR;
            banyak_besar++;
        }

        biaya = halaman * harga_per_halaman;
        if (warna == 'Y') {
            biaya *= 2;
        }

        cout << "  " << left << setw(16) << nama << right << setw(6) << halaman;
        if (warna == 'Y') {
            cout << setw(7) << "Warna";
        } else {
            cout << setw(7) << "Hitam";
        }
        cout << setw(9) << biaya << "\n";

        total_halaman += halaman;
        total_pendapatan += biaya;
        // TODO 5b: perbarui biaya terbesar dan nama pemesannya bila biaya ini lebih besar.
        if (biaya > biaya_terbesar) {
            biaya_terbesar = biaya;
            nama_terbesar = nama;
        }
    }

    cout << "\n=== Rekap Hari Ini ===\n";
    cout << "Jumlah pesanan    : " << jumlah << "\n";
    cout << "Total halaman     : " << total_halaman << "\n";
    cout << "Total pendapatan  : " << total_pendapatan << "\n";
    cout << "Rata-rata halaman : " << static_cast<double>(total_halaman) / jumlah << "\n";
    // TODO 5c: cetak pesanan dengan biaya terbesar.
    cout << "Terbesar          : " << nama_terbesar << " (" << biaya_terbesar << ")\n";

    cout << "\nSebaran ukuran pesanan:\n";
    // TODO 6: tiga baris batang menggunakan perulangan bersarang.
    const string label_kategori[] = {"Kecil", "Sedang", "Besar"};
    const int jumlah_kategori[] = {banyak_kecil, banyak_sedang, banyak_besar};

    for (int i = 0; i < 3; i++) {
        cout << left << setw(7) << label_kategori[i] << "| ";
        for (int j = 0; j < jumlah_kategori[i]; j++) {
            cout << "#";
        }
        cout << " " << jumlah_kategori[i] << "\n";
    }

    return 0;
}
