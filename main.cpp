#include <iostream>
#include <ctime>
using namespace std;

// Hitung umur dalam tahun
int hitungTahun(int y, int m, int d) {
    time_t t = time(0);
    tm* now = localtime(&t);

    int tahun = (now->tm_year + 1900) - y;

    if ((now->tm_mon + 1 < m) || 
       (now->tm_mon + 1 == m && now->tm_mday < d)) {
        tahun--;
    }

    return tahun;
}

// Hitung umur dalam bulan
int hitungBulan(int y, int m, int d) {
    time_t t = time(0);
    tm* now = localtime(&t);

    int bulan = (now->tm_year + 1900 - y) * 12 + (now->tm_mon + 1 - m);

    if (now->tm_mday < d) {
        bulan--;
    }

    return bulan;
}

// Cari hari dalam minggu
string hariDalamMinggu(int y, int m, int d) {
    tm waktu = {};
    waktu.tm_year = y - 1900;
    waktu.tm_mon = m - 1;
    waktu.tm_mday = d;

    mktime(&waktu);

    string hari[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    return hari[waktu.tm_wday];
}

int main() {
    int y, m, d;

    cout << "Masukkan tahun lahir: ";
    cin >> y;
    cout << "Masukkan bulan lahir: ";
    cin >> m;
    cout << "Masukkan tanggal lahir: ";
    cin >> d;

    cout << "Umur (tahun): " << hitungTahun(y, m, d) << endl;
    cout << "Umur (bulan): " << hitungBulan(y, m, d) << endl;
    cout << "Hari lahir: " << hariDalamMinggu(y, m, d) << endl;

    return 0;
}
