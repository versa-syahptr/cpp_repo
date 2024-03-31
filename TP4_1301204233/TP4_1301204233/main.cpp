#include "SLL.h"

/*
    Nama    : Aufa Mutia
    NIM     : 1301204233
    Kelas   : IF-44-09
*/

using namespace std;

int main() {
    List A;
    cout<<"first (A) sebelum createList : "<<first(A)<<endl;

    createList(A);
    cout<<"first(A) setelah createList : "<<first(A)<<endl;
    cout<<endl;

//  newElement
    adr p;
    p = newElement(100);
    cout<<"Info(P): "<<info(p)<<endl;
    cout<<"Next(P): "<<next(p)<<endl;
    cout<<endl;

//  insertFirst
    cout<<"first(A) sebelum insertFirst : "<<first(A)<<endl;
    insertFirst(A,p);
    cout<<"first(A) setelah insertFirst : "<<first(A)<<endl;
    cout<<"info first(A): "<<info(first(A))<<endl;

    p = newElement(200);
    insertFirst(A,p);
    cout<<"info first(A): "<<info(first(A))<<endl;
    cout<<endl;

//  show
    show(A);

    p = newElement(300);
    insertFirst(A,p);
    show(A);
    cout<<endl;

    adr prec;
    //prec = newElement('A');
    prec = deleteAfter(A,p);
    show(A);
    cout<<info(prec)<<endl;

//  deleteLast
    prec = deleteLast(A);
    show(A);
    cout<<info(prec)<<endl<<endl;
/*
    p = deleteLast(A);
    show(A);
    cout<<info(p)<<endl<<endl;

    p = deleteLast(A);
    show(A);
    cout<<info(p)<<endl<<endl;
*/
    return 0;
}
