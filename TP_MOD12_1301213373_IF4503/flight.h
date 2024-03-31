#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
    File : flight.h
*/

#include <iostream>
using namespace std;

struct jadwalPenerbangan {
    string kode, jenis;
    string tanggal, waktu;
    string asal, tujuan;
    int kapasitas;
};

typedef struct elementJadwal *adr_jadwalP;
typedef struct jadwalPenerbangan infotype;

struct elementJadwal{
    infotype info;
    adr_jadwalP next;
};

struct ListJadwal {
    adr_jadwalP first;
};

void createListJadwal_1301213373(ListJadwal &L);
infotype newInfo(string kode, string jenis, string tanggal, string waktu, string asal, string tujuan, int kapasitas);
adr_jadwalP createElemenJadwal_1301213373(infotype x);
void InsertLastJ_1301213373(ListJadwal &L, adr_jadwalP p);
void ShowJadwal_1301213373(ListJadwal L);
adr_jadwalP DeleteFirstJ_1301213373(ListJadwal &L);
adr_jadwalP SearchJ_1301213373(ListJadwal L, string dari, string ke, string tanggal);
#endif // FLIGHT_H_INCLUDED
