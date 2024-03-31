// SLL.h
#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
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

typedef char Infotype;
typedef struct Element *adr;

struct Element {
    Infotype info;
    adr next;
};

struct List {
    adr first;
};

void createList_1301213373(List &OV);
adr newElement_1301213373(Infotype x);
void insertFirst_1301213373(List &OV, adr P);
void show_1301213373(List OV);
adr deleteLast_1301213373(List &OV);
adr deleteLast_1301213373(List &OV, adr prec);


#endif // SLL_H_INCLUDED
