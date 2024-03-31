#include "graph.h"

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
    File : graph.cpp
*/

adrNode newNode_1301213373(char x){
    adrNode np = new Node;
    np->info = x;
    np->child = NULL;
    np->next = NULL;
    return np;
}

void addNode_1301213373(adrNode &G, adrNode p){
    // G is the first node; q is a walker
    adrNode q;
    if (G != NULL){
        q = G;
        while (q->next != NULL){
            q = q->next;
        }
        q->next = p;
    } else {
        G = p;
    }
}

adrNode findNode_1301213373(adrNode G, char x){
    if (G != NULL){
        while (G->info != x){
            G = G->next;
        }
    }
    return G; // G can be NULL
}

adrEdge newEdge_1301213373(char y){
    adrEdge ep = new Edge;
    ep->info = y;
    ep->next = NULL;
    return ep;
}

void addEdge_1301213373(adrNode &G, char x, char y){
    adrNode nodeX, nodeY;
    nodeX = findNode_1301213373(G, x);
    nodeY = findNode_1301213373(G, y);
    if (nodeX == NULL){
        cout << "node " << x << " tidak ditemukan!\n";
    } else if (nodeY == NULL){
        cout << "node " << y << " tidak ditemukan!\n";
    } else {
        adrEdge edgeX, edgeY;
        edgeX = newEdge_1301213373(x);
        edgeY = newEdge_1301213373(y);
        // connect x -> y
        edgeX->next = nodeY->child;
        nodeY->child = edgeX;
        // connect y -> x
        edgeY->next = nodeX->child;
        nodeX->child = edgeY;
    }
}

bool isConnected_1301213373(adrNode G, char x, char y){
    bool foundX = false, foundY = false;
    adrNode nodeX, nodeY;
    adrEdge edgeX, edgeY;
    nodeX = findNode_1301213373(G, x);
    nodeY = findNode_1301213373(G, y);
    if (nodeX != NULL && nodeY != NULL){
        edgeX = nodeX->child;
        while (edgeX != NULL && !foundX){
            foundX = edgeX->info == y;
            edgeX = edgeX->next;
        }
        edgeY = nodeY->child;
        while (edgeY != NULL && !foundY){
            foundY = edgeY->info == x;
            edgeY = edgeY->next;
        }
        return foundX && foundY;
    }
    return false;
}

void printGraph_1301213373(adrNode G){
    adrEdge edge;
    while (G != NULL){
        cout << "node " << G->info << ": ";
        edge = G->child;
        while (edge != NULL){
            cout << edge->info << " - ";
            edge = edge->next;
        }
        cout << endl;
        G = G->next;
    }
}
