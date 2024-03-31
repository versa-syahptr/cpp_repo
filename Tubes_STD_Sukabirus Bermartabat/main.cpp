#include "tubes.h"

int main()
{
    char kembali;
    ListJadwal LJ;
    ListPasien LP;
    CreateListJadwal(LJ);
    createListPasien(LP);
    cout << "======== TUBES STD TOPIK RUMAH SAKIT =========" << endl << endl;
    int opsi = ShowMenu();
    while (opsi != 0)
    {
        if (opsi == 1)
        {
            InsertJadwal(LJ, CreateElemenJadwal(CreateInfoJadwal()));
        }
        else if (opsi == 2)
        {
            TambahPasien(LP, LJ);
        }
        else if (opsi == 3)
        {
            ShowAllJadwal(LJ);
        }
        else if (opsi == 4)
        {
            ShowAllPasien(LP);
        }
        else if (opsi == 5)
        {
            ShowPasienbyDate(LJ, LP);
        }
        else if (opsi == 6)
        {
            if (LJ.first != NULL)
            {
                adrJ p;
                DeleteJadwal(LJ, LP, p);
            }
            else
            {
                cout << "Maaf, data jadwal sudah kosong\n\n";
            }
        }
        else if (opsi == 7) {
            if (LP.first != NULL) {
                int id;
                string nama;
                cout << "Masukkan id pasien yang akan dihapus   :"; cin >> id;
                cout << "Masukkan nama pasien yang akan dihapus :"; cin >> nama;
                DeletePasien(LP, id, nama);
            }
            else {
                cout << "Maaf daftar pasien kosong!\n\n";
            }
        }
        else if (opsi == 8) {
            if (LP.first != NULL)
            {
                int idPasien;
                string namaPasien;
                cout << "Masukkan id pasien yang akan dipindahkan   : "; cin >> idPasien;
                cout << "Masukkan nama pasien yang akan dipindahkan : "; cin >> namaPasien;
                PindahJadwal(LP, LJ, idPasien, namaPasien);
            }
            else
            {
                cout << "Maaf, daftar pasien masih kosong\n\n";
            }
        }
        else if (opsi == 9){
            PeriksaPasien(LP);
        }
        else if (opsi == 10){
            if (LP.first != NULL)
            {
                int idPasien;
                string namaPasien, tanggal;
                cout << "Masukkan id pasien                        : "; cin >> idPasien;
                cout << "Masukkan nama pasien                      : "; cin >> namaPasien;
                cout << "Masukkan tanggal pemeriksaan (DD-MM-YYYY) : "; cin >> tanggal;
                findConnection(LJ, LP, idPasien, namaPasien, tanggal);
            }
            else
            {
                cout << "Maaf, daftar pasien masih kosong\n\n";
            }
        }
        else {
            cout << "Maaf, menu tidak tersedia.\n\n";
        }
        do {
            cout << "Kembali ke menu utama? (y/n) "; cin >> kembali;
        } while (kembali != 'y' && kembali != 'n');
        if (kembali == 'n') {
            opsi = 0;
        }
        else if (kembali == 'y') {
            opsi = ShowMenu();
        }
        kembali = 0;
        cout << "\n\n";
    }
    return 0;
}
