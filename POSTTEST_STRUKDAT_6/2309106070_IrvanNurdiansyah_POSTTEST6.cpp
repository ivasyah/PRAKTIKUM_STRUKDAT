#include <iostream>
#include <string>
#include <cmath> // untuk sqrt di Jump Search
#include <limits>

using namespace std;

// Struktur data untuk mewakili barang prabotan rumah tangga
struct BarangPrabotan {
    string nama;
    int kuantitas;
    float harga;
};

// Prototipe fungsi
void tambahkanBarang(BarangPrabotan* barang, int& jumlah);
void tampilkanBarang(BarangPrabotan* barang, int jumlah);
void perbaruiBarang(BarangPrabotan* barang, int jumlah);
void hapusBarang(BarangPrabotan* barang, int& jumlah);
void fibonacciSearch(BarangPrabotan* barang, int jumlah);
void jumpSearch(BarangPrabotan* barang, int jumlah);
void boyerMooreSearch(BarangPrabotan* barang, int jumlah);

// Fungsi Boyer-Moore Helper
int lastOccurrence(const string& pattern, char c);
int boyerMooreSearchHelper(const string& text, const string& pattern);

int main() {
    const int MAX_BARANG = 1000; // Maksimum jumlah barang prabotan rumah tangga
    BarangPrabotan* barang = new BarangPrabotan[MAX_BARANG]; // Array untuk menyimpan barang
    int jumlah = 0; // Jumlah barang saat ini
    int pilihan;

    do {
        cout << "\nSistem Manajemen Gudang Prabotan Rumah Tangga\n";
        cout << "1. Tambahkan Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Perbarui Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Pencarian dengan Fibonacci Search (kuantitas)\n";
        cout << "6. Pencarian dengan Jump Search (kuantitas)\n";
        cout << "7. Pencarian dengan Boyer-Moore Search (nama)\n";
        cout << "8. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahkanBarang(barang, jumlah);
                break;
            case 2:
                tampilkanBarang(barang, jumlah);
                break;
            case 3:
                perbaruiBarang(barang, jumlah);
                break;
            case 4:
                hapusBarang(barang, jumlah);
                break;
            case 5:
                fibonacciSearch(barang, jumlah);
                break;
            case 6:
                jumpSearch(barang, jumlah);
                break;
            case 7:
                boyerMooreSearch(barang, jumlah);
                break;
            case 8:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid Silakan coba lagi.\n";
        }
    } while (pilihan != 8);
    delete[] barang;
    return 0;
}

// Fungsi untuk menambahkan barang
void tambahkanBarang(BarangPrabotan* barang, int& jumlah) {
    if (jumlah < 100) {
        cout << "Masukkan nama barang: ";
        cin >> barang[jumlah].nama;

        while (true) {
            cout << "Masukkan jumlah stok: ";
            cin >> barang[jumlah].kuantitas;

            if (cin.fail() || barang[jumlah].kuantitas < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid Harap masukkan angka boloku.\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        while (true) {
            cout << "Masukkan harga: ";
            cin >> barang[jumlah].harga;

            if (cin.fail() || barang[jumlah].harga < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid Harap masukkan angka boloku.\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        jumlah++;
        cout << "Barang berhasil ditambahkan!\n";
    } else {
        cout << "Gudang penuh!\n";
    }
}

// Fungsi menampilkan semua barang
void tampilkanBarang(BarangPrabotan* barang, int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada barang di gudang.\n";
        return;
    }

    cout << "\nBarang-Barang di Gudang:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Nama: " << barang[i].nama
             << ", jumlah stok: " << barang[i].kuantitas
             << ", Harga: Rp." << barang[i].harga << endl;
    }
}

// Fungsi memperbarui barang
void perbaruiBarang(BarangPrabotan* barang, int jumlah) {
    tampilkanBarang(barang, jumlah);
    string nama;
    cout << "Masukkan nama barang yang ingin diperbarui: ";
    cin >> nama;

    for (int i = 0; i < jumlah; i++) {
        if (barang[i].nama == nama) {
            cout << "Masukkan jumlah stok terbaru: ";
            cin >> barang[i].kuantitas;
            cout << "Masukkan harga baru: ";
            cin >> barang[i].harga;
            cout << "Barang berhasil diperbarui!\n";
            return;
        }
    }

    cout << "Barang tidak ditemukan.\n";
}

// Fungsi untuk menghapus barang
void hapusBarang(BarangPrabotan* barang, int& jumlah) {
    tampilkanBarang(barang, jumlah);
    string nama;
    cout << "Masukkan nama barang yang ingin dihapus: ";
    cin >> nama;

    for (int i = 0; i < jumlah; i++) {
        if (barang[i].nama == nama) {
            for (int j = i; j < jumlah - 1; j++) {
                barang[j] = barang[j + 1];
            }
            jumlah--;
            cout << "Barang berhasil dihapus!\n";
            return;
        }
    }

    cout << "Barang tidak ditemukan.\n";
}

// Fungsi Fibonacci Search untuk kuantitas (integer)
void fibonacciSearch(BarangPrabotan* barang, int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada barang untuk dicari.\n";
        return;
    }

    int x;
    cout << "Masukkan jumlah stok yang ingin dicari: ";
    cin >> x;

    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < jumlah) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, jumlah - 1);

        if (barang[i].kuantitas < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (barang[i].kuantitas > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            cout << "Barang dengan kuantitas " << x << " ditemukan: " << barang[i].nama << endl;
            return;
        }
    }

    if (fibMMm1 && barang[offset + 1].kuantitas == x) {
        cout << "Barang dengan kuantitas " << x << " ditemukan: " << barang[offset + 1].nama << endl;
    } else {
        cout << "Barang tidak ditemukan.\n";
    }
}

// Fungsi Jump Search untuk kuantitas (integer)
void jumpSearch(BarangPrabotan* barang, int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada barang untuk dicari.\n";
        return;
    }

    int x;
    cout << "Masukkan jumlah stok yang ingin dicari: ";
    cin >> x;

    int step = sqrt(jumlah);
    int prev = 0;

    while (barang[min(step, jumlah) - 1].kuantitas < x) {
        prev = step;
        step += sqrt(jumlah);
        if (prev >= jumlah) {
            cout << "Barang tidak ditemukan.\n";
            return;
        }
    }

    for (int i = prev; i < min(step, jumlah); i++) {
        if (barang[i].kuantitas == x) {
            cout << "Barang dengan kuantitas " << x << " ditemukan: " << barang[i].nama << endl;
            return;
        }
    }

    cout << "Barang tidak ditemukan.\n";
}

// Fungsi Boyer-Moore Search untuk nama barang (string)
void boyerMooreSearch(BarangPrabotan* barang, int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada barang untuk dicari.\n";
        return;
    }

    string nama;
    cout << "Masukkan nama barang yang ingin dicari: ";
    cin >> nama;

    for (int i = 0; i < jumlah; i++) {
        if (boyerMooreSearchHelper(barang[i].nama, nama) != -1) {
            cout << "Barang ditemukan: " << barang[i].nama << ", Stok: " << barang[i].kuantitas << endl;
            return;
        }
    }

    cout << "Barang tidak ditemukan.\n";
}

// Fungsi pembantu Boyer-Moore (cari pola dalam teks)
int lastOccurrence(const string& pattern, char c) {
    for (int i = pattern.length() - 1; i >= 0; i--) {
        if (pattern[i] == c)
            return i;
    }
    return -1;
}

int boyerMooreSearchHelper(const string& text, const string& pattern) {
    int m = pattern.length();
    int n = text.length();

    int skip;

    for (int i = 0; i <= n - m; i += skip) {
        skip = 0;
        for (int j = m - 1; j >= 0; j--) {
            if (pattern[j] != text[i + j]) {
                skip = max(1, j - lastOccurrence(pattern, text[i + j]));
                break;
            }
        }
        if (skip == 0)
            return i;
    }
    return -1;
}
