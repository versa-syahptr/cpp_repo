#include "queue.h"

/*
    Nama    : Versa Syahputra Santo
    NIM     : 1301213373
    Kelas   : IF-45-03
    File    : main.cpp
*/


int main()
{
    playlistLagu plist;
    adr p;
    createPlaylist_1301213373(plist);
    // digit terakhir NIM + kelas
    // 3 + 3 = 6 data
    p = newElement_1301213373(newInfo_1301213373("Ed Sheeran", "Perfect"));
    enqueue_1301213373(plist, p);
    p = newElement_1301213373(newInfo_1301213373("Shawn Mendes", "Stitches"));
    enqueue_1301213373(plist, p);
    p = newElement_1301213373(newInfo_1301213373("Nial horan", "Too much to ask"));
    enqueue_1301213373(plist, p);
    p = newElement_1301213373(newInfo_1301213373("Tulus", "Hati-hati dijalan"));
    enqueue_1301213373(plist, p);
    p = newElement_1301213373(newInfo_1301213373("Hindia", "Evaluasi"));
    enqueue_1301213373(plist, p);
    p = newElement_1301213373(newInfo_1301213373("Hal", "L"));
    enqueue_1301213373(plist, p);

    cout << "Semua lagu: \n";
    showSemuaLagu_1301213373(plist);

    // hapus playlist
    while (plist.head != NULL){
        dequeue_1301213373(plist);
    }
    cout << "Setelah dihapus: \n";
    showSemuaLagu_1301213373(plist);
    return 0;
}
