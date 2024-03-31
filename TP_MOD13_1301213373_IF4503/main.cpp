#include "graph.h"

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
    File : main.cpp
*/

int main()
{
    adrNode first = NULL;
    addNode_1301213373(first, newNode_1301213373('A'));
    addNode_1301213373(first, newNode_1301213373('B'));
    addNode_1301213373(first, newNode_1301213373('C'));
    addNode_1301213373(first, newNode_1301213373('D'));

    addEdge_1301213373(first, 'A','D'); // A <-> D
    addEdge_1301213373(first, 'A','C'); // A <-> C
    addEdge_1301213373(first, 'A','B'); // A <-> B
    addEdge_1301213373(first, 'B','D'); // B <-> D

    printGraph_1301213373(first);

    cout << boolalpha << "B <-> A: " << isConnected_1301213373(first, 'B', 'A') << endl;
    cout << boolalpha << "B <-> C: " << isConnected_1301213373(first, 'B', 'C') << endl;
    return 0;
}
