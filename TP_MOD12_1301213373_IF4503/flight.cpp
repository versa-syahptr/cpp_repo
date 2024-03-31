#include "flight.h"

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
    File : flight.cpp
*/

void createListJadwal_1301213373(ListJadwal &L){
    L.first = NULL;
}

adr_jadwalP createElemenJadwal_1301213373(infotype x){
    adr_jadwalP p;
    p = new elementJadwal;
    p->info = x;
    p->next = NULL;
}

infotype newInfo(string kode, string jenis, string tanggal, string waktu, string asal, string tujuan, int kapasitas){
    infotype x;
    x.kode = kode;
    x.jenis = jenis;
    x.tanggal = tanggal;
    x.waktu = waktu;
    x.asal = asal;
    x.tujuan = tujuan;
    x.kapasitas = kapasitas;
    return x;
}

void InsertLastJ_1301213373(ListJadwal &L, adr_jadwalP p){
    adr_jadwalP f;
    f = L.first;
    if (f == NULL){
        L.first = p;
    } else {
        while (f->next != NULL){
            f = f->next;
        }
        f->next = p;
    }
}

void ShowJadwal_1301213373(ListJadwal L){
    adr_jadwalP p;
    if (L.first != NULL){
        p = L.first;
        while (p != NULL){
            cout << "(" << p->info.kode << ") " << p->info.jenis;
            cout << " [ " << p->info.asal << " - " << p->info.tujuan << " ] ";
            cout << " [ " << p->info.tanggal << " " << p->info.waktu << " ] ";
            cout << "Kap: " << p->info.kapasitas << endl;
            p = p->next;
        }
    }
}

adr_jadwalP DeleteFirstJ_1301213373(ListJadwal &L){
    adr_jadwalP p;
    p = L.first;
    if (p == NULL){
        cout << "kosong\n";
    } else if (p->next == NULL){
        L.first == NULL;
    } else {
        L.first = p->next;
        p->next = NULL;
    }
    return p;
}

adr_jadwalP SearchJ_1301213373(ListJadwal L, string dari, string ke, string tanggal){
    /* mengembalikan alamat dari elemen list L yang memiliki info
    asal=dari, tujuan=ke dan tanggal keberangkatan=tanggal, atau NIL
    apabila tidak ditemukan */
    adr_jadwalP p;
    if (L.first != NULL){
        p = L.first;
        while (p != NULL){
            if (p->info.asal == dari && p->info.tujuan == ke && p->info.tanggal == tanggal){
                return p;
            }
            p = p->next;
        }
    }
    return NULL;
}
