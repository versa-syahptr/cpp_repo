// main.cpp

#include "DLL.h"

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
*/

int main()
{
    List data;
    adr p;
    Infotype dataBaru;
    createList_1301213373(data);

    int pilihan, n;

    pilihan = showMenu_1301213373();

    while (pilihan != 0){
        char balik;

        switch (pilihan){
        case 1:
            cout << "jumlah data: ";
            cin >> n;
            for (int i=0; i<n; i++){
                dataBaru = newAteka_1301213373();
                p = newElement_1301213373(dataBaru);
                insertFirst_1301213373(data, p);
            }
            cout << endl;
            break;;
        case 2:
            show_1301213373(data);
            cout << endl;
            break;;
        case 4:
            tampilData_1301213373(data);
        default:
            cout << "tidak valid!\n";
            break;;
        }
        cout << "kembali ke menu utama? (y/n)";
        cin >> balik;
        if (balik == 'n'){
            pilihan = 0;
        } else {
            pilihan = showMenu_1301213373();
        }

    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM";
    return 0;
}
