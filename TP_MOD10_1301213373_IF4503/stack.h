#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/*
    Nama    : Versa Syahputra Santo
    NIM     : 1301213373
    Kelas   : IF-45-03
    File    : stack.h
*/

#include <iostream>

using namespace std;

typedef char infotype;
const int STACKMAX = 15;

struct Stack{
    infotype info[STACKMAX];
    int top;
};

void createStack_1301213373(Stack &S);
bool isEmpty_1301213373(Stack S);
bool isFull_1301213373(Stack S);
void push_1301213373(Stack &S, infotype x);
infotype pop_1301213373(Stack &S);
void printInfo_1301213373(Stack S);
#endif // STACK_H_INCLUDED
