#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Struktur data untuk mewakili barang prabotan rumah tangga
struct BarangPrabotan {
    string nama;
    int kuantitas;
    float harga;
    BarangPrabotan* next; // Pointer ke node berikutnya
};

// Prototipe fungsi
void tambahkanBarang(BarangPrabotan*& head);
void tampilkanBarang(BarangPrabotan* head);
void perbaruiBarang(BarangPrabotan* head);
void hapusBarang(BarangPrabotan*& head);
void hapusSemuaBarang(BarangPrabotan*& head); // Fungsi untuk membersihkan memori

int main() {
    BarangPrabotan* head = nullptr; // Pointer ke kepala linked list
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
                tambahkanBarang(head);
                break;
            case 2:
                tampilkanBarang(head);
                break;
            case 3:
                perbaruiBarang(head);
                break;
            case 4:
                hapusBarang(head);
                break;
            case 5:
                cout << "Program selesai.\n";
                hapusSemuaBarang(head); // Bersihkan memori sebelum keluar
                break;
            default:
                cout << "Pilihan tidak valid Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}

// Fungsi untuk menambahkan barang
void tambahkanBarang(BarangPrabotan*& head) {
    BarangPrabotan* baru = new BarangPrabotan;

    cout << "Masukkan nama barang: ";
    cin >> baru->nama;

    while (true) {
        cout << "Masukkan jumlah stok: ";
        cin >> baru->kuantitas;

        if (cin.fail() || baru->kuantitas < 0) { 
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
        cin >> baru->harga;

        if (cin.fail() || baru->harga < 0) { 
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid Harap masukkan angka boloku.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    // Menambahkan barang ke linked list
    baru->next = head; // Menghubungkan node baru dengan kepala
    head = baru; // Memperbarui kepala ke node baru
    cout << "Barang berhasil ditambahkan!\n";
}

// Fungsi menampilkan semua barang
void tampilkanBarang(BarangPrabotan* head) {
    if (head == nullptr) {
        cout << "Tidak ada barang di gudang.\n";
        return;
    }
    
    cout << "\nBarang-Barang di Gudang:\n";
    BarangPrabotan* current = head;
    while (current != nullptr) {
        cout << "Nama: " << current->nama 
             << ", jumlah stok: " << current->kuantitas 
             << ", Harga: Rp." << current->harga << endl;
        current = current->next; // Pindah ke node berikutnya
    }
}

// Fungsi memperbarui barang
void perbaruiBarang(BarangPrabotan* head) {
    tampilkanBarang(head);
    string nama;
    cout << "Masukkan nama barang yang ingin diperbarui: ";
    cin >> nama;

    BarangPrabotan* current = head;
    while (current != nullptr) {
        if (current->nama == nama) {
            cout << "Masukkan jumlah stok terbaru: ";
            cin >> current->kuantitas;
            cout << "Masukkan harga baru: ";
            cin >> current->harga;
            cout << "Barang berhasil diperbarui!\n";
            return;
        }
        current = current->next; // Pindah ke node berikutnya
    }
    
    cout << "Kau tidak lihat listnya kah bro!! DIBACA!\n";
}

// Fungsi untuk menghapus barang
void hapusBarang(BarangPrabotan*& head) {
    tampilkanBarang(head);
    
    if (head == nullptr) return; // Jika tidak ada barang

    string nama;
    cout << "Masukkan nama barang yang ingin dihapus: ";
    cin >> nama;

    BarangPrabotan* current = head;
    BarangPrabotan* previous = nullptr;

    while (current != nullptr) {
        if (current->nama == nama) {
            if (previous == nullptr) { // Menghapus node pertama
                head = current->next; // Memperbarui kepala
            } else {
                previous->next = current->next; // Menghubungkan previous dengan next
            }
            delete current; // Menghapus node dari memori
            cout << "Barang berhasil dihapus!\n";
            return;
        }
        previous = current; // Memperbarui previous
        current = current->next; // Pindah ke node berikutnya
    }

    cout << "MASIH GABISA BACA SI ******!\n";
}

// Fungsi untuk membersihkan semua barang dari memori
void hapusSemuaBarang(BarangPrabotan*& head) {
    while (head != nullptr) {
        BarangPrabotan* temp = head;
        head = head->next; // Pindah ke node berikutnya
        delete temp; // Hapus node dari memori
    }
}
