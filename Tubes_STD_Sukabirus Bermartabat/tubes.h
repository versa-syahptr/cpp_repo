#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

struct Pasien {
    int record_id;
    string nama, statusBPJS;
    string hasil_pemeriksaan;
    int biaya_dokter, biaya_obat;
};

struct Jadwal
{
    string tanggal, jamPraktek, namaDokter, spesialisasi;
    int idDokter, kuotaPasien;
};

typedef struct ElementJadwal *adrJ;
typedef struct ElementPasien* adrP;

struct ElementJadwal
{
    Jadwal info;
    adrJ next;
};

struct ElementPasien {
    Pasien info;
    adrJ jadwal;
    adrP next;
};

struct ListPasien {
    adrP first;
};

struct ListJadwal
{
    adrJ first;
};

void createListPasien(ListPasien &LP);
Pasien CreateInfoPasien();
adrP CreateElementPasien(Pasien ip);
void InsertPasien(ListPasien &LP, adrP ptrPasien);
void TambahPasien(ListPasien &LP, ListJadwal &LJ);
void ShowAllPasien(ListPasien LP);
adrP SearchPasien(ListPasien LP, int idPasien, string nama);
void DeletePasien(ListPasien &LP, int idPasien, string nama);
void PeriksaPasien(ListPasien LP);
bool KuotaJadwalTersedia(ListJadwal LJ);

void CreateListJadwal(ListJadwal &LJ);
Jadwal CreateInfoJadwal();
adrJ CreateElemenJadwal(Jadwal x);
void InsertJadwal(ListJadwal &LJ, adrJ p);
void DeleteJadwal(ListJadwal &LJ, ListPasien &LP, adrJ &p);
void ShowAllJadwal(ListJadwal LJ);
void findConnection(ListJadwal LJ, ListPasien LP,int idPasien, string namaPasien, string tanggal);
void PindahJadwal(ListPasien &LP, ListJadwal LJ, int idPasien, string namaPasien);
adrJ SearchJadwal(ListJadwal LJ, string namaDokter, string tanggal);
int CountConnectedPasien(ListJadwal LJ, ListPasien LP, string tanggal);
void ShowPasienbyDate(ListJadwal LJ, ListPasien LP);
int ShowMenu();

#endif // TUBES_H_INCLUDED
