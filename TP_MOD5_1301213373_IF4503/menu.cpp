// menu.cpp
#include "menu.h"
/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
*/

void createList_1301213373(List &L) {
    first(L) = nil;
}

adr newElement_1301213373(Infotype x) {
    adr P;
    P = new Element;
    info(P) = x;
    next(P) = nil;
}

void insertLast_1301213373(List &L, adr P){
    adr f = first(L);
    if (f == nil){
        first(L) = P;
    } else if (next(f) == nil) {
        next(f) = P;
    } else {
        while (next(f) != nil){
            f = next(f);
        }
        next(f) = P;
    }
}

void show_1301213373(List L) {
    adr P;
    if (first(L) != nil) {
        P = first(L);
        while (P != nil){
            cout << info(P) << " ";
            P = next(P);
        }
        cout << endl;
    } else {
        cout << "List kosong" << endl;
    }
}

float vocalPersentage_1301213373(List L){
    adr P;
    float total=0, vocal=0;
    float persen = 0;
    if (first(L) != nil) {
        P = first(L);
        while (P != nil){
            if (info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o'){
                cout << info(P) << " ";
                vocal++;
            }
            total++;
            P = next(P);
        }
        cout << "\n";
        persen = (vocal/total)*100;
    } else {
        cout << "List kosong" << endl;
    }
    return persen;
}

adr showLastK_1301213373(List L, int k){
    adr P = nil;
    int total=0;
    int i=0;
    if (first(L) != nil) {
        P = first(L);
        while (P != nil){
            P = next(P);
            total++;
        }
        while( i < total-(k-1)){
            P = next(P);
            i++;
        }
        cout << info(P) << endl;
    }
    return P;
}

int showMenu_1301213373(){
    int c=0;
    cout << "======MENU=======\n";
    cout << "1. Menambah N data baru\n";
    cout << "2. Menampilkan semua data\n";
    cout << "3. presentase vocal\n";
    cout << "4. show last K\n";
    cout << "0. Exit\n";
    cout << "Pilihan menu: ";
    cin >> c;
    return c;
}

void tambahData_1301213373(List &L, Infotype x){
    adr p;
    p = newElement_1301213373(x);
    insertLast_1301213373(L, p);
}

