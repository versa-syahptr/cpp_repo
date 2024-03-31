#include "menu.h"

int main()
{
    List data;
    adr p;

    createList_1301213373(data);

    int pilihan;

    pilihan = showMenu_1301213373();

    while (pilihan != 0){
        char balik;

        switch (pilihan){
        case 1:
            int n;
            cout << "jumlah daata: ";
            cin >> n;
            Infotype dataBaru;
            for (int i=0; i<n; i++){
                cout << "data: ";
                cin >> dataBaru;
                tambahData_1301213373(data, dataBaru);
            }
            cout << endl;
            break;;
        case 2:
            show_1301213373(data);
            cout << endl;
            break;;
        case 3:
            cout << "presentase vocal ";
            cout << vocalPersentage_1301213373(data) << "%\n";
        case 4:
            int k;
            cout << "data ke berapa: ";
            cin >> k;
            showLastK_1301213373(data, k);
        default:
            cout << "tidak valid!\n";
            break;
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
}
