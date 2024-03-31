// DLL.cpp
#include "DLL.h"

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
*/

void createList_1301213373(List &L){
    first(L) = nil;
    last(L) = nil;
}

Ateka newAteka_1301213373(){
    Ateka atk;
    cout << "Masukan ID Faktur: ";
    cin >> atk.ID_faktur;
    cout << "Masukan Nama barang: ";
    cin >> atk.nama_barang;
    cout << "Masukan jumlah: ";
    cin >> atk.jumlah;
    cout << "Masukan harga: ";
    cin >> atk.harga;
    cout << endl;
    return atk;
}


adr newElement_1301213373(Infotype x){
    adr P;
    P = new Element;
    info(P) = x;
    next(P) = nil;
    prev(P) = nil;
    return P;
}

void insertFirst_1301213373(List &L, adr P){
    if (first(L) == nil){
        first(L) = P;
        last(L) = P
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void show_1301213373(List L){
    adr P;
    Infotype x;
    if (first(L) != nil) {
        P = first(L);
        cout << "Data penjualan Alat Tulis:\n";
        while (P != nil){
            x = info(P);
            cetakItem_1301213373(x);
            P = next(P);
        }
        cout << endl;
    } else {
        cout << "List kosong" << endl;
    }
}

void cetakItem_1301213373(Infotype x){
    cout << "ID Faktur:\t" << x.ID_faktur << endl;
    cout << "Nama Barang:\t" << x.nama_barang << endl;
    cout << "Jumlah:\t" << x.jumlah << endl;
    cout << "Harga:\t" << x.harga << endl;
    cout << endl;
}

void tampilData_1301213373(List L){
    adr p;
    p = first(L);
    if (p != nil){
        for (int i=0; i<4 && p != nil; i++){
            p = next(p);
        }
        if (p != nil) {
            cetakItem_1301213373(info(p));
        }
    } else {
        cout << "List kosong" << endl;
    }
}

int showMenu_1301213373(){
    int c=0;
    cout << "======MENU=======\n";
    cout << "1. Menambah N data baru\n";
    cout << "2. Menampilkan semua data\n";
    cout << "3. Tampilkan data ke-4\n";
    cout << "0. Exit\n";
    cout << "Pilihan menu: ";
    cin >> c;
    return c;
}
