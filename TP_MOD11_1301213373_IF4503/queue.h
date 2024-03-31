#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

/*
    Nama    : Versa Syahputra Santo
    NIM     : 1301213373
    Kelas   : IF-45-03
    File    : queue.h
*/

#include <iostream>

using namespace std;

struct Infotype {
    string artis, judul;
};

typedef struct Element *adr;

struct Element {
    Infotype info;
    adr next;
};

struct playlistLagu {
    adr head, tail;
};

void createPlaylist_1301213373(playlistLagu &Q);
adr newElement_1301213373(Infotype x);
Infotype newInfo_1301213373(string artis, string judul);
void enqueue_1301213373(playlistLagu &Q, adr P);
adr dequeue_1301213373(playlistLagu &Q);
void showSemuaLagu_1301213373(playlistLagu Q);
#endif // QUEUE_H_INCLUDED
