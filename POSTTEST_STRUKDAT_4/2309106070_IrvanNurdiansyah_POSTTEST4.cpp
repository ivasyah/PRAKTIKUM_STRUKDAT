#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct BarangPrabotan {
    string nama;
    int kuantitas;
    float harga;
    BarangPrabotan* next; // Pointer ke node berikutnya
};

// Struktur data untuk Stack
struct Stack {
    BarangPrabotan* top; // Pointer ke elemen teratas stack
};

// Struktur data untuk Queue
struct Queue {
    BarangPrabotan* front; // Pointer ke elemen terdepan queue
    BarangPrabotan* rear;  // Pointer ke elemen belakang queue
};

// Prototipe fungsi
void tambahkanBarang(BarangPrabotan*& head);
void tampilkanBarang(BarangPrabotan* head);
void perbaruiBarang(BarangPrabotan* head);
void hapusBarang(BarangPrabotan*& head);
void hapusSemuaBarang(BarangPrabotan*& head); // Fungsi untuk membersihkan memori

// Fungsi Stack
void push(Stack& stack, BarangPrabotan* barang);
BarangPrabotan* pop(Stack& stack);
bool isEmptyStack(Stack& stack);

// Fungsi Queue
void enqueue(Queue& queue, BarangPrabotan* barang);
BarangPrabotan* dequeue(Queue& queue);
bool isEmptyQueue(Queue& queue);

int main() {
    BarangPrabotan* head = nullptr; // Pointer ke kepala linked list
    Stack stack = { nullptr };       // Inisialisasi stack
    Queue queue = { nullptr, nullptr }; // Inisialisasi queue
    int pilihan;

    do {
        cout << "\nSistem Manajemen Gudang Prabotan Rumah Tangga\n";
        cout << "1. Tambahkan Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Perbarui Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Push ke Stack\n";
        cout << "6. Pop dari Stack\n";
        cout << "7. Enqueue ke Queue\n";
        cout << "8. Dequeue dari Queue\n";
        cout << "9. Keluar\n";
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
            case 5: {
                if (head != nullptr) {
                    push(stack, head); // Push barang pertama ke stack
                    cout << "Barang berhasil dipush ke stack!\n";
                } else {
                    cout << "Tidak ada barang untuk dipush ke stack.\n";
                }
                break;
            }
            case 6: {
                BarangPrabotan* barang = pop(stack);
                if (barang) {
                    cout << "Pop dari stack: " << barang->nama << endl;
                    delete barang; // Hapus barang setelah pop
                } else {
                    cout << "Stack kosong.\n";
                }
                break;
            }
            case 7: {
                if (head != nullptr) {
                    enqueue(queue, head); // Enqueue barang pertama ke queue
                    cout << "Barang berhasil dienqueue!\n";
                } else {
                    cout << "Tidak ada barang untuk dienqueue.\n";
                }
                break;
            }
            case 8: {
                BarangPrabotan* barang = dequeue(queue);
                if (barang) {
                    cout << "Dequeue dari queue: " << barang->nama << endl;
                    delete barang; // Hapus barang setelah dequeue
                } else {
                    cout << "Queue kosong.\n";
                }
                break;
            }
            case 9:
                cout << "Program selesai.\n";
                hapusSemuaBarang(head); // Bersihkan memori sebelum keluar
                break;
            default:
                cout << "Pilihan tidak valid Silakan coba lagi.\n";
        }
    } while (pilihan != 9);

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

// Implementasi fungsi Stack

void push(Stack& stack, BarangPrabotan* barang) {
    BarangPrabotan* newNode = new BarangPrabotan(*barang); // Salin data barang ke node baru
    newNode->next = stack.top; // Hubungkan dengan elemen teratas yang ada sebelumnya
    stack.top = newNode; // Perbarui top menjadi node baru
}

BarangPrabotan* pop(Stack& stack) {
    if (isEmptyStack(stack)) return nullptr; // Jika stack kosong

    BarangPrabotan* temp = stack.top; // Ambil elemen teratas stack
    stack.top = stack.top->next; // Pindah top ke elemen berikutnya

    return temp; // Kembalikan elemen yang dipop dari stack
}

bool isEmptyStack(Stack& stack) {
   return stack.top == nullptr; // Cek apakah stack kosong
}

// Implementasi fungsi Queue

void enqueue(Queue& queue, BarangPrabotan* barang) {
   BarangPrabotan* newNode = new BarangPrabotan(*barang); // Salin data barang ke node baru

   if (isEmptyQueue(queue)) { 
       queue.front = queue.rear = newNode; // Jika queue kosong, set front dan rear menjadi node baru
   } else { 
       queue.rear->next = newNode; // Hubungkan rear dengan node baru dan perbarui rear
       queue.rear = newNode;
   }
}

BarangPrabotan* dequeue(Queue& queue) {
   if (isEmptyQueue(queue)) return nullptr; // Jika queue kosong

   BarangPrabotan* temp = queue.front; // Ambil elemen terdepan dari queue

   queue.front = queue.front->next; // Pindah front ke elemen berikutnya

   if (queue.front == nullptr) { // Jika setelah dequeue front menjadi null, set rear juga null.
       queue.rear = nullptr;
   }

   return temp; // Kembalikan elemen yang dikeluarkan dari queue.
}

bool isEmptyQueue(Queue& queue) {
   return queue.front == nullptr; // Cek apakah queue kosong.
}