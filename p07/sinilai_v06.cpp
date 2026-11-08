
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int jumlah_mahasiswa = 0;

    cout << "=== SiNilai v0.6 ===\n";

    // TODO 1: Validasi jumlah mahasiswa
    cout << "Jumlah mahasiswa (paling sedikit 1): ";
    cin >> jumlah_mahasiswa;

    while (cin.fail() || jumlah_mahasiswa < 1) {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Masukan tidak valid. Masukkan bilangan bulat minimal 1.\n";
        cout << "Jumlah mahasiswa (paling sedikit 1): ";
        cin >> jumlah_mahasiswa;
    }

    cin.ignore(1000, '\n');

    cout << fixed << setprecision(2);

    double total_nilai = 0;
    int jumlah_lulus = 0;

    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;

    double nilai_tertinggi = -1;
    string nama_tertinggi;

    cout << "\n=== Data Mahasiswa ===\n";

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama;
        string npm;
        double kehadiran = 0;
        double mingguan = 0;
        double uts = 0;
        double uas = 0;

        cout << "\n--- Mahasiswa ke-" << i
             << " dari " << jumlah_mahasiswa << " ---\n";

        // TODO 2: Validasi nama
        bool nama_valid = false;

        do {
            cout << "Nama      : ";
            getline(cin, nama);

            bool kosong = true;
            bool ada_angka = false;

            for (int k = 0; k < static_cast<int>(nama.length()); k++) {
                unsigned char karakter =
                    static_cast<unsigned char>(nama[k]);

                if (!isspace(karakter)) {
                    kosong = false;
                }

                if (isdigit(karakter)) {
                    ada_angka = true;
                }
            }

            if (kosong) {
                cout << "Nama tidak boleh kosong.\n";
            } else if (ada_angka) {
                cout << "Nama tidak boleh mengandung angka.\n";
            } else {
                nama_valid = true;
            }

        } while (!nama_valid);

        // TODO 3: Merapikan nama menjadi Title Case
        bool awal_kata = true;

        for (int k = 0; k < static_cast<int>(nama.length()); k++) {
            unsigned char karakter =
                static_cast<unsigned char>(nama[k]);

            if (isspace(karakter)) {
                awal_kata = true;
            } else {
                if (awal_kata) {
                    nama[k] = static_cast<char>(toupper(karakter));
                } else {
                    nama[k] = static_cast<char>(tolower(karakter));
                }

                awal_kata = false;
            }
        }

        cout << "NPM       : ";
        getline(cin, npm);

        // TODO 4: Validasi nilai kehadiran
        cout << "Kehadiran : ";
        cin >> kehadiran;

        while (cin.fail() || kehadiran < 0 || kehadiran > 100) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Harus angka 0 sampai 100.\n";
            cout << "Kehadiran : ";
            cin >> kehadiran;
        }

        // TODO 5: Validasi nilai mingguan
        cout << "Mingguan  : ";
        cin >> mingguan;

        while (cin.fail() || mingguan < 0 || mingguan > 100) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Harus angka 0 sampai 100.\n";
            cout << "Mingguan  : ";
            cin >> mingguan;
        }

        // Validasi nilai UTS
        cout << "UTS       : ";
        cin >> uts;

        while (cin.fail() || uts < 0 || uts > 100) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Harus angka 0 sampai 100.\n";
            cout << "UTS       : ";
            cin >> uts;
        }

        // Validasi nilai UAS
        cout << "UAS       : ";
        cin >> uas;

        while (cin.fail() || uas < 0 || uas > 100) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Harus angka 0 sampai 100.\n";
            cout << "UAS       : ";
            cin >> uas;
        }

        cin.ignore(1000, '\n');

        // Perhitungan nilai akhir, sama seperti v0.5
        double nilai_akhir =
            (kehadiran * 0.10) +
            (mingguan * 0.45) +
            (uts * 0.25) +
            (uas * 0.20);

        string huruf_mutu;
        string keterangan;

        if (nilai_akhir >= 80) {
            huruf_mutu = "A";
            keterangan = "Sangat baik";
        } else if (nilai_akhir >= 75) {
            huruf_mutu = "B+";
            keterangan = "Baik";
        } else if (nilai_akhir >= 70) {
            huruf_mutu = "B";
            keterangan = "Baik";
        } else if (nilai_akhir >= 65) {
            huruf_mutu = "C+";
            keterangan = "Cukup";
        } else if (nilai_akhir >= 60) {
            huruf_mutu = "C";
            keterangan = "Cukup";
        } else if (nilai_akhir >= 50) {
            huruf_mutu = "D";
            keterangan = "Kurang";
        } else {
            huruf_mutu = "E";
            keterangan = "Sangat kurang";
        }

        bool lulus = nilai_akhir >= 60;

        // Mencetak satu baris data mahasiswa
        cout << "  " << left << setw(20) << nama
             << right << setw(7) << nilai_akhir
             << "  " << left << setw(3) << huruf_mutu;

        if (lulus) {
            cout << " Lulus\n";
        } else {
            cout << " Belum lulus\n";
        }

        // Menambahkan nilai ke total kelas
        total_nilai += nilai_akhir;

        if (lulus) {
            jumlah_lulus++;
        }

        // Menghitung jumlah setiap huruf mutu
        switch (huruf_mutu[0]) {
            case 'A':
                jumlah_a++;
                break;
            case 'B':
                jumlah_b++;
                break;
            case 'C':
                jumlah_c++;
                break;
            case 'D':
                jumlah_d++;
                break;
            default:
                jumlah_e++;
                break;
        }

        // Menyimpan mahasiswa dengan nilai tertinggi
        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }
    }

    // Laporan kelas
    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : "
         << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas : "
         << total_nilai / jumlah_mahasiswa << "\n";
    cout << "Tertinggi        : " << nama_tertinggi
         << " (" << nilai_tertinggi << ")\n";

    // Sebaran huruf mutu
    cout << "\nSebaran huruf mutu:\n";

    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;

        if (huruf == 'A') {
            banyak = jumlah_a;
        } else if (huruf == 'B') {
            banyak = jumlah_b;
        } else if (huruf == 'C') {
            banyak = jumlah_c;
        } else if (huruf == 'D') {
            banyak = jumlah_d;
        } else {
            banyak = jumlah_e;
        }

        cout << huruf << " | ";

        for (int j = 1; j <= banyak; j++) {
            cout << "#";
        }

        cout << " " << banyak << "\n";
    }

    return 0;
}
