#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n = 4;
    double t[] = {0, 1, 2, 3};
    double x[] = {10, 18, 35, 63};
    double beda[4][4];

    for (int i = 0; i < n; i++) {
       beda[i][0]= x[i]; 
    } 

    for (int j = 1; j < n; j++) {
      for (int i = 0; i < n - j; i++) {
        beda [i][j] =
            (beda [i + 1][j - 1]- beda[i][j-1])/
            (t[i + j] - t[i]);
      }
    }

    cout << "\n--- Tabel Beda Terbagi ---" << endl;
    cout << "t\tPosisi\tBeda 1\tBeda 2\tBeda 3" <<endl;
    for (int i = 0; i < n; i++) {
        cout << t[i] << "\t";
        for (int j = 0; j < n - i; j++) {
            cout << beda [i][j] << "\t";
        }
        cout << endl;
    }
    cout << "------------------------\n" << endl;

    double nilai_t;
    cout << "=== INTERPOLASI BEDA NEWTON ===" << endl;
    cout << "Hero : Miya" << endl;
    cout << "Masukkan waktu yang ingin dicari (detik): ";
    cin >> nilai_t;

    double hasil = beda[0][0];
    double perkalian = 1;
    for (int i = 1; i < n; i++) {
        perkalian *= (nilai_t - t[i - 1]);
        hasil += beda[0][i] * perkalian;
    }
    cout << fixed << setprecision(3);
    cout << "\nWaktu yang dicari : " << nilai_t << " detik" << endl;
    cout << "Posisi hero Miya : " << hasil << " meter" << endl;
    return 0;

}