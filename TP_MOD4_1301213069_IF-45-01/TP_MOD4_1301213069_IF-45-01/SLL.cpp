#include "SLL.h"

void createList(List &I) {
    first(I) = nil;
}

adr newElement(Infotype x) {
    adr P;
    P = new Element;
    info(P) = x;
    next(P) = nil;
}

void insertFirst(List &I, adr P) {
    if (first(I) == nil) {
        first(I) = P;
        next(P) = nil;
    } else {
        next(P) = first(I);
        first(I) = P;
    }
}

void show(List I) {
    adr P;
    if (first(I) != nil) {
        P = first(I);
        while (P != nil){
            cout << info(P) << endl;
            P = next(P);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

adr deleteLast(List &I) {
    adr P;
    adr Q;

    if (first(I) != nil) {
        P = next(first(I));
        while (P != nil) {
            Q = P;
            P = next(P);
        }
    } else if (next(first(I)) == nil) {
        first(I) = nil;
    } else {
        cout << "List kosong" << endl;
    }
}

void insertAfter(List &I, adr P, adr prec) {
    adr Q;

    Q = first(I);

    while (Q != prec) {
        Q = next(Q);
    }

    next(P) = next(Q);
    next(Q) = P;
}
