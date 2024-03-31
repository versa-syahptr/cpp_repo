// menu.h
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
*/
#include <iostream>

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) (L).first
#define last(L) (L).last
#define nil NULL


using namespace std;

typedef char Infotype;
typedef struct Element *adr;

struct Element {
    Infotype info;
    adr next;
};

struct List {
    adr first = nil, last = nil;
    Infotype operator[] (int i);
};

void createList_1301213373(List &L);
adr newElement_1301213373(Infotype x);
void insertLast_1301213373(List &L, adr P);
void show_1301213373(List L);
float vocalPersentage_1301213373(List L);
adr showLastK_1301213373(List L, int k);
int showMenu_1301213373();
void tambahData_1301213373(List &L, Infotype x);


#endif // MENU_H_INCLUDED
