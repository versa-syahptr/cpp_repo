// CSLL.h
#ifndef CSLL_H_INCLUDED
#define CSLL_H_INCLUDED
/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
*/
#include <iostream>

#define info(P) (P)->info
#define next(P) (P)->next
#define first(I) (I).first
#define nil NULL

using namespace std;

struct Infotype{
    string artis, judul, genre;
    int playtime;
};
typedef struct Element *adr;

struct Element {
    Infotype info;
    adr next;
};

struct ListLagu {
    adr first;
};

void createList_1301213373(ListLagu &L);
Infotype newInfo_1301213373(string artis, string judul, string genre, int playtime);
void newElement_1301213373(Infotype x, adr &P);
void insertFirst_1301213373(ListLagu &L, adr P);
void deleteLast_1301213373(ListLagu &L, adr &P);
void show_1301213373(ListLagu L);

#endif // CSLL_H_INCLUDED
