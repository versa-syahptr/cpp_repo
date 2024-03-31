// main.cpp
#include "SLL.h"
/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
*/

int main()
{
    List OV;
    cout << "first(OV) sebelum createlist " << first(OV) << endl;

    createList_1301213373(OV);
    cout << "first(OV) setelah createlist " << first(OV) << endl;
        cout<<endl;

//  newElement_1301213373
    adr p;
    p = newElement_1301213373('z');
    cout<<"Info(P): "<<info(p)<<endl;
    cout<<"Next(P): "<<next(p)<<endl;
    cout<<endl;

//  insertFirst
    cout <<"first(OV) sebelum insertFirst : "<< first(OV)<<endl;
    insertFirst_1301213373(OV,p);
    cout<<"first(OV) setelah insertFirst : "<<first(OV)<<endl;
    cout<<"info first(OV): "<<info(first(OV))<<endl;

    p = newElement_1301213373('y');
    insertFirst_1301213373(OV,p);
    cout<<"info first(OV): "<<info(first(OV))<<endl;
    cout<<endl;

//  show
    show_1301213373(OV);

    p = newElement_1301213373('x');
    insertFirst_1301213373(OV,p);
    show_1301213373(OV);
    cout<<endl;

    adr prec;
    //prec = newElement('OV');
    prec = deleteLast_1301213373(OV,p);
    show_1301213373(OV);
    cout<<info(prec)<<endl;

//  deleteLast
    prec = deleteLast_1301213373(OV);
    show_1301213373(OV);
    cout<<info(prec)<<endl<<endl;

    return 0;
}
