#include "stack.h"

/*
    Nama    : Versa Syahputra Santo
    NIM     : 1301213373
    Kelas   : IF-45-03
    File    : stack.cpp
*/

void createStack_1301213373(Stack &S){
    S.top = 0;
}

bool isEmpty_1301213373(Stack S){
    return S.top == 0;
}

bool isFull_1301213373(Stack S){
    return S.top == STACKMAX;
}

void push_1301213373(Stack &S, infotype x){
    if (!isFull_1301213373(S)){
        S.info[S.top] = x;
        S.top++;
    } else {
        cout << "Stack penuh!\n";
    }
}

infotype pop_1301213373(Stack &S){
    if (!isEmpty_1301213373(S)){
        S.top--;
        return S.info[S.top];
    } else {
        cout << "Stack kosong!\n";
    }
}

void printInfo_1301213373(Stack S){
    if (!isEmpty_1301213373(S)){
        for (int i=S.top-1; i>=0; i--){
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}
