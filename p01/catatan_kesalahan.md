# Catatan Kesalahan

| Berkas | Jenis kesalahan | Pesan yang muncul (salin baris pertamanya) | Cara kamu mengetahuinya |
|---|---|---|---|
| k1_sintaks.cpp | Sintaks | `k1_sintaks.cpp:7:5: error: expected ',' or ';' before 'std'` | Compiler menunjukkan kesalahan pada baris 7 kolom 5. Setelah diperiksa, ternyata pada baris sebelumnya kurang tanda titik koma (`;`) setelah `int nilai = 80`. |
| k2_nama.cpp | Nama/identifier | `k2_nama.cpp:8:31: error: 'Nilai' was not declared in this scope; did you mean 'nilai'?` | Compiler menunjukkan bahwa `Nilai` tidak dikenal karena nama variabel yang dibuat adalah `nilai`. Setelah itu ditemukan juga bahwa variabel `bonus` belum dideklarasikan. |
| k3_runtime.cpp | Runtime | `Tidak ada pesan compiler.` | Program berhasil di-compile tanpa error dan warning. Saat dijalankan dengan input 4, program menghasilkan rata-rata 60. Saat input 0, program berhenti mendadak sehingga terlihat bahwa kesalahan terjadi ketika program sedang berjalan. |
| k4_logika.cpp | Logika | `Tidak ada pesan.` | Program berhasil di-compile dan berjalan, tetapi hasil awalnya `Rata-rata: 81`, padahal hasil yang benar adalah sekitar 81.67. Setelah `3` diubah menjadi `3.0`, hasil menjadi `81.6667`. |

Menurut saya, kesalahan logika paling berbahaya karena program dapat berhasil di-compile dan berjalan tanpa pesan kesalahan, tetapi menghasilkan keluaran yang salah.