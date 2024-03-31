#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
#include <iostream>
#define info(P) (P)->info
#define next(P) (P)->next
#define first(I) (I).first
#define nil NULL



using namespace std;

typedef string Infotype;
typedef struct Element *adr;

struct Element {
    Infotype info;
    adr next;
};

struct List {
    adr first;
};

void createList(List &I);
adr newElement(Infotype x);
void insertFirst(List &I, adr P);
void show(List I);
adr deleteLast(List &I);
void insertAfter(List &I, adr P, adr prec);

#endif // SLL_H_INCLUDED
