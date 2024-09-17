#include <iostream>
using namespace std;

int pascal(int baris, int kolom) {
    if (kolom == 1 || kolom == baris) {
        return 1;
    } else {
        return pascal(baris - 1, kolom - 1) + pascal(baris - 1, kolom);
    }
}

void SegitigaPascal(int tingkat) {
    for (int i = 1; i <= tingkat; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << pascal(i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int tingkat = 3;
    SegitigaPascal(tingkat);
    return 0;
}