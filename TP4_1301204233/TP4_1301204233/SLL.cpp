#include "SLL.h"

/*
    Nama    : Aufa Mutia
    NIM     : 1301204233
    Kelas   : IF-44-09
*/

void createList(List &A){
    first(A) = nil;
}

adr newElement(infotype x){
    adr P = new element;
    info(P) = x;
    next(P) = nil;
    return P;
}

void insertFirst(List &A, adr p){
    if (first(A)==nil) {
        first(A) = p;
    } else {
        next(p) = first(A);
        first(A) = p;
    }
}

void insertLast(List &A, adr p){
    adr q;
    if (first(A)==nil){
        first(A) = p;
    } else {
        q = first(A);
        while (next(q)!=0){
            q = next(q)
        }
        next(q) = p;
    }
}

void insertAfter(List &A, adr prec, adr p){
    adr q;
    q = first(A);
    while (next(q)!=prec){
        q = next(q);
    }
    next(p) = next(prec);
    next(prec) = p;
}

adr deleteFirst(List &A){
    adr p;
    p = first(A);
    first(A) = next(first(A))
    return p;
}

adr deleteLast(List &A){
    adr p, q;
    if (first(A)==nil){
        p = nil;
        cout<<"List Kosong"<<endl;
    } else if (next(p)==nil){
        p = first(A);
        first(A) = nil;
    } else {
        q = first(A);
        p = first(A);
        while (next(p)!=nil) {
            q = p;
            p = next(p);
        }
        next(q) = nil;
    }
    return p;
}

adr deleteAfter(List &A, adr prec){
    adr p, q;
    if (first(A)==nil) {
        p = nil;
    } else {
        q = first(A);
        p = next(first(A));
        while (next(p)!=prec) {
            q = p;
            p = next(p);
        }
        q = p;
        next(p) = next(prec);
        next(q) = prec;
        next(prec) = next(p);
    }
    return p;
}

void show(List A){
    adr p;
    if (first(A)!=nil) {
        p = first(A);
        while (p!=nil) {
            cout<<info(p)<<" ";
            p = next(p);
        }
        cout<<endl;
    } else {
        cout<<"List Kosong"<<endl;
    }

}
