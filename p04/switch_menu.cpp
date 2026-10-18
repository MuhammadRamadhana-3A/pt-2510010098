// switch: memilih satu dari beberapa kasus berdasarkan satu nilai bulat atau karakter.
// Jangan lupa break di akhir setiap kasus; tanpa break, eksekusi jatuh ke kasus berikutnya.

#include <iostream>
using namespace std;

int main() {
    char pilihan;

    cout << "=== Menu SiNilai ===\n";
    cout << "1. Tampilkan kartu nilai\n";
    cout << "2. Hitung ulang\n";
    cout << "3. Keluar\n";
    cout << "4. Tentang program\n";
    cout << "k. Keluar menggunakan huruf\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case '1':
            cout << "Menampilkan kartu nilai...\n";
            break;

        case '2':
            cout << "Menghitung ulang...\n";
            break;

        case '3':
        case 'k':
            cout << "Sampai jumpa.\n";
            break;

        case '4':
            cout << "Program SiNilai untuk mengelola nilai mahasiswa.\n";
            break;

        default:
            cout << "Pilihan tidak dikenal.\n";
            break;
    }

    return 0;
}

