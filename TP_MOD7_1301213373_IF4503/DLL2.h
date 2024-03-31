//DLL2.h
#ifndef DLL2_H_INCLUDED
#define DLL2_H_INCLUDED

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


struct Infotype{
    int no_polis;
    string nama, riwayat_penyakit;
    long int premi;
};

typedef struct Element *adr;

struct Element {
    Infotype info;
    adr next, prev;
};

struct List {
    adr first, last;
};

void createList_1301213373(List &L);
Infotype newInfotype_1301213373();
adr newElement_1301213373();
void insertFirst_1301213373(List &L, adr P);
void show_1301213373(List L);
List reverseList_1301213373(List L);
void secondBiggest_1301213373(List L);
void cetakItem_1301213373(Infotype x);
int showMenu_1301213373();

#endif // DLL2_H_INCLUDED
