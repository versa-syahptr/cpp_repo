// main.cpp
#include "CSLL.h"

int main()
{
    ListLagu lis;
    adr p, temp;

    createList_1301213373(lis);
    // angka belakang nim = 3; kelas 03 => 3+3=6 data
    newElement_1301213373(newInfo_1301213373("si a", "a", "pop", 15), p);
    insertFirst_1301213373(lis, p);
    newElement_1301213373(newInfo_1301213373("si b", "b", "pop", 14), p);
    insertFirst_1301213373(lis, p);
    newElement_1301213373(newInfo_1301213373("si c", "c", "pop", 18), p);
    insertFirst_1301213373(lis, p);
    newElement_1301213373(newInfo_1301213373("si d", "d", "pop", 23), p);
    insertFirst_1301213373(lis, p);
    newElement_1301213373(newInfo_1301213373("si e", "e", "pop", 65), p);
    insertFirst_1301213373(lis, p);
    newElement_1301213373(newInfo_1301213373("si f", "f", "pop", 17), p);
    insertFirst_1301213373(lis, p);

    //cetak
    show_1301213373(lis);

    // hapus
    deleteLast_1301213373(lis, temp);
    cout << "-----------------------\n";
    show_1301213373(lis);

    return 0;
}
