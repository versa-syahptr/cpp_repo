// DLL2.cpp
#include "DLL2.h"

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
*/

void createList_1301213373(List &L){
    first(L) = nil;
    last(L) = nil;
}

adr newElement_1301213373(){
    adr P; Infotype x;
    cout << "Masukan data baru ";
    cin >> x.no_polis >> x.nama >> x.riwayat_penyakit >> x.premi;
    P = new Element;
    info(P) = x;
    next(P) = nil;
    prev(P) = nil;
    return P;
}

void insertFirst_1301213373(List &L, adr P){
    if (first(L) == nil){
        first(L) = P;
        last(L) = P;
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
        cout << "Data Nasabah Asuransi:\n";
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
    cout << "No polis: " << x.no_polis << endl;
    cout << "Nama: " << x.nama << endl;
    cout << "Riwayat penyakit: " << x.riwayat_penyakit << endl;
    cout << "premi: " << x.premi << endl;
    cout << endl;
}

int showMenu_1301213373(){
    int c=0;
    cout << "======MENU=======\n";
    cout << "1. Menambah N data baru\n";
    cout << "2. Menampilkan semua data\n";
    cout << "3. Tampilkan data terbesar ke-2\n";
    cout << "0. Exit\n";
    cout << "Pilihan menu: ";
    cin >> c;
    return c;
}

void secondBiggest_1301213373(List L){
    adr p;
    long int max1, max2;
    max1 = max2 = 0;

    p = first(L);
    while (p != nil){
        if (info(p).premi > max1){
            max2 = max1;
            max1 = info(p).premi;
        } else if (info(p).premi > max2 && info(p).premi != max1){
            max2 = info(p).premi;
        }
        p = next(p);
    }
    if (max2 != 0){
        cout << "nilai premi terbesar ke-2 adalah: " << max2 << endl;
    } else {
        cout << "tidak ada nilai terbesar ke-2\n";
    }
}
