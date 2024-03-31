// DLL.h
#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
*/
#include <iostream>

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) (L).first
#define last(L) (L).last
#define nil NULL

using namespace std;

struct Ateka{
    int  ID_faktur;
    string nama_barang;
    int jumlah, harga;
};

typedef struct Ateka Infotype;
typedef struct Element *adr;

struct Element {
    Infotype info;
    adr next, prev;
};

struct List {
    adr first, last;
};

void createList_1301213373(List &L);
Ateka newAteka_1301213373();
adr newElement_1301213373(Infotype x);
void insertFirst_1301213373(List &L, adr P);
void show_1301213373(List L);
void tampilData_1301213373(List L);
void cetakItem_1301213373(Infotype x);
int showMenu_1301213373();

#endif // DLL_H_INCLUDED
