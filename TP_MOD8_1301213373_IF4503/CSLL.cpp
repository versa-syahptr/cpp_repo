// CSLL.cpp
#include "CSLL.h"
/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
*/

void createList_1301213373(ListLagu &L){
    first(L) = nil;
}

Infotype newInfo_1301213373(string artis, string judul, string genre, int playtime){
    Infotype x;
    x.artis = artis;
    x.judul = judul;
    x.genre = genre;
    x.playtime = playtime;
    return x;
}

void newElement_1301213373(Infotype x, adr &P){
    P = new Element;
    info(P) = x;
    next(P) = nil;
}

void insertFirst_1301213373(ListLagu &L, adr P){
    if (first(L) == nil) { // kosong
        first(L) = P;
        next(P) = first(L);
    } else {
        adr q;
        next(P) = first(L);
        q = first(L);
        while (next(q) != first(L)){
            q = next(q);
        }
        next(q) = P;
        first(L) = P;
    }
}

void deleteLast_1301213373(ListLagu &L, adr &P){
    adr q;
    if (first(L) == nil) {
        cout << "List kosong" << endl;
    } else if (next(first(L)) == first(L)){
        P = first(L);
        next(P) = nil;
        first(L) = nil;
    } else {

        q = first(L);
        while (next(next(q)) != first(L)){
            q = next(q);
        }
        P = next(q);
        next(P) = nil;
        next(q) = first(L);

    }
}

void show_1301213373(ListLagu L){
    adr p;
    if (first(L) != nil){
        p = first(L);
        do {
            cout << "Artis: " << info(p).artis << endl;
            cout << "Judul: " << info(p).judul << endl;
            cout << "Genre: " << info(p).genre << endl;
            cout << "playtime: " << info(p).playtime << endl << endl;
            p = next(p);
        } while (p != first(L));
    } else {
        cout << "List kosong" << endl;
    }
}
