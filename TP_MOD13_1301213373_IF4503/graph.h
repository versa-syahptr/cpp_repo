#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
    File : graph.h
*/

#include <iostream>

using namespace std;

typedef struct Node *adrNode;
typedef struct Edge *adrEdge;

struct Edge {
    char info;
    adrEdge next;
};

struct Node {
    char info;
    adrEdge child;
    adrNode next;
};


adrNode newNode_1301213373(char x);
/* mengembalikan alamat sebuah node baru dengan info berupa x */
void addNode_1301213373(adrNode &G, adrNode p);
/* I.S. terdefinisi alamat elemen pertama dari graph G (mungkin kosong), dan
sebuah alamat dari node baru yang disimpan pada p.
F.S. node baru ditambahkan ke dalam list parent sebagai elemen terakhir*/
adrNode findNode_1301213373(adrNode G, char x);
/* mengembalikan alamat node dengan info x pada graph G, atau NULL apabila
tidak ditemukan */
adrEdge newEdge_1301213373(char y);
void addEdge_1301213373(adrNode &G, char x, char y);
/* I.S. terdefinisi alamat elemen pertama dari graph G (mungkin kosong), dan
character x dan y.
F.S. node dengan info x dan y terhubung oleh sebuah edge, edge ditambahkan
di awal pada list */
bool isConnected_1301213373(adrNode G, char x, char y);
/* mengembalikan true apabila x dan y terhubung oleh sebuah edge, atau false
apabila tidak terhubung */
void printGraph_1301213373(adrNode G);
/* I.S. terdefinisi alamat elemen pertama dari graph G (mungkin kosong).
F.S. menampilkan adjacency graph, perhatikan contoh yang diberikan */

#endif // GRAPH_H_INCLUDED
