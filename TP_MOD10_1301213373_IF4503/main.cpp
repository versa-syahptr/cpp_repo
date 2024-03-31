#include "stack.h"
/*
    Nama    : Versa Syahputra Santo
    NIM     : 1301213373
    Kelas   : IF-45-03
    File    : main.cpp
*/


// nim = 1301213373; (3) mod 4 = 3
int main()
{
    Stack s;
    createStack_1301213373(s);
    push_1301213373(s, 'A');
    push_1301213373(s, 'T');
    push_1301213373(s, 'A');
    push_1301213373(s, 'D');
    push_1301213373(s, 'R');
    push_1301213373(s, 'U');
    push_1301213373(s, 'T');
    push_1301213373(s, 'K');
    push_1301213373(s, 'U');
    push_1301213373(s, 'R');
    push_1301213373(s, 'T');
    push_1301213373(s, 'S');
    printInfo_1301213373(s);
    for (int i=0; i<8; i++){
        pop_1301213373(s);
    }
    printInfo_1301213373(s);
    return 0;
}
