#include "tree.h"
/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
    File : main.cpp
*/

int main()
{
    int x[9] = {5,3,9,10,4,7,1,8,6};
    adrNode root = NULL, p;

    for (int i=0; i<9; i++){
        cout << x[i] << " ";
        insertNode_1301213373(root, newNode_1301213373(x[i]));
    }
    cout << "\n\nPreorder\t: ";
    printPreOrder_1301213373(root);
    cout << "\n\nDescendent of Node 9\t: ";
    printDescendant_1301213373(root, 9);
    cout << "\n\nSum of BST Info\t: " << sumNode_1301213373(root);
    cout << "\nNumber of Leaves\t: " << countLeaves_1301213373(root);
    cout << "\nHeight of Tree\t: " << heightTree_1301213373(root);

    return 0;
}
