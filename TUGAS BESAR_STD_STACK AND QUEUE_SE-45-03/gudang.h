#include <iostream>
#include <stdlib.h>
using namespace std;
//PROGRAM PENYIMPANAN BARANG UMUM
//STACK DIGUNAKAN UNTUK BARANG PADA RAK KARENA BARANG DALAM RAK DITUMPUK (FIRST IN LAST OUT)
//QUEUE DIGUNAKAN UNTUK MENGELUARKAN RAK TERLAMA DALAM LEMARI AGAR BARANG TIDAK RUSAK TERLALU LAMA BERADA DI RAK DALAM LEMARI (FIRST IN FIRST OUT)

struct Barang{
    string kode;
    int harga;
};

struct Rak{
    int id;
    int n = 0;
    int max = 100;
    Barang barang[100];
    Rak *next;
};

struct Lemari{
    Rak *head, *tail;
};

Lemari lemari;
int NO_RAK = 1;
