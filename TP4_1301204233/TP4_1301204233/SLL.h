#ifndef SLL_H_INCLUDE
#define SLL_H_INCLUDE

/*
    Nama    : Aufa Mutia
    NIM     : 1301204233
    Kelas   : IF-44-09
*/

#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define nil NULL

typedef int infotype; //type char, karena angka belakang nim 3
typedef struct element *adr;

struct element {
    infotype info;
    adr next;
};

struct List {
    adr first;
};

void createList(List &A); //nama var huruf terakhir nama lengkap, karena nim%4=1
adr newElement(infotype x);
void insertFirst(List &A, adr p);
void insertLast(List &A, adr p);
void insertAfter(List &A, adr prec, adr p);
adr deleteFirst(List &A);
adr deleteLast(List &A);
adr deleteAfter(List &A, adr prec);
void show(List A);

#endif // SLL_H_INCLUDE
