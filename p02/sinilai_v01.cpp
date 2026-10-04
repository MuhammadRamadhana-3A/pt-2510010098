// SiNilai v0.1: data satu mahasiswa.
// Program membaca nama, NPM, dan empat komponen nilai, lalu menampilkannya sebagai kartu.
// Lengkapi bagian TODO. Versi ini belum menghitung apa-apa; itu tugas Pertemuan 3.

#include <iostream>
#include <string>
using namespace std;

int main() {
    // TODO 1: deklarasikan variabel untuk nama dan NPM.
    string nama;
    string npm;
    int semester;
    // TODO 2: deklarasikan empat variabel nilai.
    double kehadiran;
    double mingguan;
    double uts;
    double uas;

    cout << "=== SiNilai v0.1 ===\n";

    cout << "Nama : ";
    // TODO 3: baca nama. Ingat, nama bisa mengandung spasi.
    getline(cin, nama);

    cout << "NPM : ";
    // TODO 4: baca NPM.
    cin >> npm;

    cout << "Semester : ";
    // Meminta dan membaca semester.
    cin >> semester;

    cout << "Kehadiran : ";
    // TODO 5: baca keempat komponen nilai, satu per satu.
    cin >> kehadiran;

    cout << "Mingguan : ";
    cin >> mingguan;

    cout << "UTS : ";
    cin >> uts;

    cout << "UAS : ";
    cin >> uas;

    cout << "\n--- Kartu Data Mahasiswa ---\n";

    // TODO 6: tampilkan semua data yang tadi dibaca.
    cout << "Nama : " << nama << "\n";
    cout << "NPM : " << npm << "\n";
    cout << "Semester : " << semester << "\n";
    cout << "Kehadiran : " << kehadiran << "\n";
    cout << "Mingguan : " << mingguan << "\n";
    cout << "UTS : " << uts << "\n";
    cout << "UAS : " << uas << "\n";

    return 0;
}

