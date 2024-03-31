#include "queue.h"

/*
    Nama    : Versa Syahputra Santo
    NIM     : 1301213373
    Kelas   : IF-45-03
    File    : queue.h
*/


void createPlaylist_1301213373(playlistLagu &Q){
    Q.head = NULL;
    Q.tail = NULL;
}

adr newElement_1301213373(Infotype x) {
    adr P;
    P = new Element;
    P->info = x;
    P->next = NULL;
    return P;
}

Infotype newInfo_1301213373(string artis, string judul){
    Infotype x;
    x.artis = artis;
    x.judul = judul;
    return x;
}

void enqueue_1301213373(playlistLagu &Q, adr P){
    if (Q.tail == NULL){
        Q.head = P;
    } else {
        Q.tail->next = P;
    }
    Q.tail = P;
}

adr dequeue_1301213373(playlistLagu &Q){
    adr p = Q.head;
    if (p == NULL){
        cout << "Empty\n";
    } else if (p->next == NULL){
        Q.head = NULL;
        Q.tail = NULL;
    } else {
        Q.head = p->next;
        p->next = NULL;
    }
    return p;
}

void showSemuaLagu_1301213373(playlistLagu Q){
    adr P;
    if (Q.head != NULL) {
        P = Q.head;
        while (P != NULL){
            cout << P->info.artis << " - " << P->info.judul << endl;
            P = P->next;
        }
        cout << endl;
    } else {
        cout << "Playlist kosong" << endl;
    }
}
