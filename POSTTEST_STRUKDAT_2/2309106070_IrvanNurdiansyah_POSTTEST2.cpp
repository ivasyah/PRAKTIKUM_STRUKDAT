#include <iostream>
#include <string>
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
        cout << "5. Keluar\n";
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
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid Silakan coba lagi.\n";
        }
    } while (pilihan != 5);
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

        // error handling
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
    
    cout << "Kau tidak lihat listnya kah bro!! DIBACA!\n";
}

// Fungsi untuk menghapus barang
void hapusBarang(BarangPrabotan* barang, int& jumlah) {
    tampilkanBarang(barang, jumlah);
    string nama;
    cout << "Masukkan nama barang yang ingin dihapus: ";
    cin >> nama;

    for (int i = 0; i < jumlah; i++) {
        if (barang[i].nama == nama) {
            // Memindahkan posisi barang ke yang kososng
            for (int j = i; j < jumlah - 1; j++) {
                barang[j] = barang[j + 1];
            }
            jumlah--;
            cout << "Barang berhasil dihapus!\n";
            return;
        }
    }

    cout << "MASIH GABISA BACA SI ******!\n";
}