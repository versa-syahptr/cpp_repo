#include "flight.h"

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
    File : main.cpp
*/

int main()
{
    ListJadwal jadwal;
    adr_jadwalP found;
    infotype x;
    createListJadwal_1301213373(jadwal);

    x = newInfo("A21", "Airbus", "9-12-2022", "11:30:00", "JKT", "BDG", 250);
    InsertLastJ_1301213373(jadwal, createElemenJadwal_1301213373(x));

    x = newInfo("A22", "Airbus", "9-12-2022", "12:30:00", "JKT", "SBY", 350);
    InsertLastJ_1301213373(jadwal, createElemenJadwal_1301213373(x));

    x = newInfo("A23", "Airbus", "9-12-2022", "13:30:00", "JKT", "JED", 450);
    InsertLastJ_1301213373(jadwal, createElemenJadwal_1301213373(x));

    x = newInfo("A24", "Airbus", "9-12-2022", "14:30:00", "JKT", "MLG", 550);
    InsertLastJ_1301213373(jadwal, createElemenJadwal_1301213373(x));

    ShowJadwal_1301213373(jadwal);
    DeleteFirstJ_1301213373(jadwal);
    cout << "after delete\n";
    ShowJadwal_1301213373(jadwal);

    found = SearchJ_1301213373(jadwal, "JKT", "MLG", "9-12-2022");
    cout << "kode hasil pencarian: " << found->info.kode;
    return 0;
}
