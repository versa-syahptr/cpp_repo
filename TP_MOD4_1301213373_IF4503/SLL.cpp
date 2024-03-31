// SLL.cpp
#include "SLL.h"
/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
*/

void createList_1301213373(List &OV) {
    first(OV) = nil;
}

adr newElement_1301213373(Infotype x) {
    adr P;
    P = new Element;
    info(P) = x;
    next(P) = nil;
}

void insertFirst_1301213373(List &OV, adr P) {
    if (first(OV) == nil) {
        first(OV) = P;
        next(P) = nil;
    } else {
        next(P) = first(OV);
        first(OV) = P;
    }
}

void show_1301213373(List OV) {
    adr P;
    if (first(OV) != nil) {
        P = first(OV);
        while (P != nil){
            cout << info(P) << " ";
            P = next(P);
        }
        cout << endl;
    } else {
        cout << "List kosong" << endl;
    }
}

adr deleteLast_1301213373(List &OV) {
    adr P;
    adr Q;

    adr p, q;
    if (first(OV)==nil){
        p = nil;
        cout<<"List Kosong"<<endl;
    } else if (next(first(OV))==nil){
        p = first(OV);
        first(OV) = nil;
    } else {
        q = first(OV);
        p = first(OV);
        while (next(p)!=nil) {
            q = p;
            p = next(p);
        }
        next(q) = nil;
    }
    return p;
}

adr deleteLast_1301213373(List &OV, adr prec){
    adr p;
    if (first(OV)==nil) {
        p = nil;
    } else {
        p = next(prec);
        next(prec) = next(next(prec));
    }
    return p;
}

