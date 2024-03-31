#include "tubes.h"


void createListPasien(ListPasien &LP) {
	LP.first = NULL;
}

Pasien CreateInfoPasien(){
    Pasien p;
    cout << "Masukan record ID          : "; cin >> p.record_id;
    cout << "Masukan nama pasien        : "; cin >> p.nama;
    cout << "Masukan status BPJS pasien : "; cin >> p.statusBPJS;
    p.hasil_pemeriksaan = "";
    p.biaya_dokter = 0;
    p.biaya_obat = 0;
    return p;
}

adrP CreateElementPasien(Pasien ip){
    adrP ptrp;
    ptrp = new ElementPasien;
    ptrp->info = ip;
    ptrp->jadwal = NULL;
    ptrp->next = NULL;
    return ptrp;
}

void InsertPasien(ListPasien &LP, adrP ptrPasien){
    adrP p = LP.first;
    if (p == NULL){
        LP.first = ptrPasien;
    } else {
        while (p->next != NULL){
            p = p->next;
        }
        p->next = ptrPasien;
    }
}

void TambahPasien(ListPasien& LP, ListJadwal& LJ) {
    string nama_dokter, tgl;
    adrJ jadwalP;
    if (!KuotaJadwalTersedia(LJ)) {
        cout << "Maaf, semua kuota jadwal sudah penuh sehingga tidak bisa menambah pasien\n";
        return;
    }
    adrP pasienP = CreateElementPasien(CreateInfoPasien());
    if (LJ.first == NULL){
        InsertPasien(LP, pasienP);
        return;
    }

    do {
        cout << "Masukkan data reservasi\nMasukan nama dokter : "; cin >> nama_dokter;
        cout << "Masukan tanggal : "; cin >> tgl;
        jadwalP = SearchJadwal(LJ, nama_dokter, tgl);
        if (jadwalP == NULL) {
            cout << "Maaf, jadwal dokter " << nama_dokter << " pada tanggal " << tgl << " tidak tersedia\n";
        }
        else if (jadwalP->info.kuotaPasien == 0) {
            cout << "Maaf, jadwal dokter [ " << nama_dokter << " ] pada tanggal [ " << tgl << " ] sudah penuh!\n";
        }
    } while (jadwalP == NULL || jadwalP->info.kuotaPasien == 0);

    pasienP->jadwal = jadwalP;
    jadwalP->info.kuotaPasien = jadwalP->info.kuotaPasien - 1; //decrement kuota
    InsertPasien(LP, pasienP);
    cout << "Sukses menambahkan pasien\n";
}

bool KuotaJadwalTersedia(ListJadwal LJ){
    bool tersedia=true;
    adrJ p= LJ.first;
    if (p != NULL){
        do {
            tersedia = p->info.kuotaPasien > 0;
            p = p->next;
        } while (p->next != LJ.first && tersedia);
        return tersedia;
    } else {
        return false;
    }

}

void ShowAllPasien(ListPasien LP){
    int counter=0, totalBiaya=0;
    adrP pas = LP.first;
    cout << "Mencetak seluruh daftar pasien\n";
    while (pas != NULL){
        counter++;
        cout << "### Pasien " << counter << " ###\n";
        cout << "Record ID         : " << pas->info.record_id << endl;
        cout << "Nama              : " << pas->info.nama << endl;
        cout << "Status BPJS       : " << pas->info.statusBPJS << endl;
        if (pas->info.hasil_pemeriksaan != "") {
            cout << "Hasil Pemeriksaan : " << pas->info.hasil_pemeriksaan << endl;
            cout << "Biaya Dokter      : Rp." << pas->info.biaya_dokter << " ( belum BPJS )" << endl;
            cout << "Biaya Obat        : Rp." << pas->info.biaya_obat << " ( belum BPJS )" << endl;
            totalBiaya = pas->info.biaya_dokter + pas->info.biaya_obat;
            if (pas->info.statusBPJS == "bpjs") {
                totalBiaya = totalBiaya - 500000;
                if (totalBiaya < 0) {
                    totalBiaya = 0;
                }
            }
            cout << "Total biaya yang harus dibayar (setelah dicover bpjs) : Rp." << totalBiaya << endl;
        }
        else {
            cout << "Hasil Pemeriksaan : ( pasien belum diperiksa )" << endl;
        }
        pas = pas->next;
    }
}

adrP SearchPasien(ListPasien LP, int idPasien, string nama){
    adrP ptrP = LP.first;
    if (ptrP != NULL){
        while (ptrP != NULL){
            if (ptrP->info.record_id == idPasien && ptrP->info.nama == nama){
                return ptrP;
            }
            ptrP = ptrP->next;
        }
    }
    return NULL;
}

void DeletePasien(ListPasien &LP, int idPasien, string nama){
    adrP toDel, walker=LP.first;
    if (walker != NULL){
        toDel = SearchPasien(LP, idPasien, nama);
        if (toDel == walker){
            LP.first = NULL;
        } else if (toDel != NULL){
            while (walker->next != toDel){
                walker = walker->next;
            }
            walker->next = toDel->next;
            toDel->next = NULL;
            cout << "Sukses menghapus pasien atas nama [ " << nama << " ] \n";
        } else {
            cout << "Maaf, data pasien atas nama [ " << nama << " ] dan id [ " << idPasien << " ] tidak ditemukan!\n";
        }
    }


}

void PeriksaPasien(ListPasien LP) {
    int id;
    string nama;
    adrP ptrpas;
    cout << "Masukan data pemeriksaan pasien\n";
    cout << "Masukan ID pasien: "; cin >> id;
    cout << "Masukan Nama pasien: "; cin >> nama;
    ptrpas = SearchPasien(LP, id, nama);
    if (ptrpas != NULL) {
        cout << "Pasien atas nama " << nama << " ditemukan\n";
        cout << "Masukan hasil pemeriksaan : "; cin >> ptrpas->info.hasil_pemeriksaan;
        cout << "Masukan total biaya obat : "; cin >> ptrpas->info.biaya_obat;
        if (ptrpas->jadwal->info.spesialisasi == "umum") {
            ptrpas->info.biaya_dokter = 100000;
        }
        else {
            ptrpas->info.biaya_dokter = 200000;
        }
        cout << "Berhasil memperbarui data pasien!\n\n";
    }
    else {
        cout << "Maaf, data pasien atas nama [ " << nama << " ] dan id [ " << id << " ] tidak ditemukan!\n";
    }
}

void CreateListJadwal(ListJadwal &LJ)
{
    /* mengembalikan list jadwal kosong */
    LJ.first = NULL;
}

Jadwal CreateInfoJadwal()
{
    /* mengembalikan jadwal */
    Jadwal x;
    cout << "Masukan data jadwal\n";
    cout << "Tanggal(DD-MM-YYYY)      : ";
    cin >> x.tanggal;
    cout << "Jam Praktek (hh.mm-hh.mm): ";
    cin >> x.jamPraktek;
    cout << "ID Dokter                : ";
    cin >> x.idDokter;
    cout << "Nama Dokter              : ";
    cin >> x.namaDokter;
    cout << "Spesialisasi             : ";
    cin >> x.spesialisasi;
    cout << "Kuota Pasien             : ";
    cin >> x.kuotaPasien;
    return x;
}

adrJ CreateElemenJadwal(Jadwal x)
{
    /* mengembalikan alamat dari suatu elemen jadwal hasil alokasi, dengan info adalah x dan pointer next adalah NULL */
    adrJ p = new ElementJadwal;
    p->info = x;
    p->next = NULL;
    return p;
}

void InsertJadwal(ListJadwal &LJ, adrJ p)
{
    /* I.S. terdefinisi list LJ dan pointer p
    F.S. memasukkan jadwal dokter baru yang disimpan pointer p di posisi paling depan */
    if(LJ.first == NULL)
    {
        LJ.first = p;
        p->next = LJ.first;
    }
    else
    {
        adrJ q = LJ.first;
        while(q->next != LJ.first)
        {
            q = q->next;
        }
        p->next = LJ.first;
        LJ.first = p;
        q->next = LJ.first;
    }

    cout << "\nJadwal berhasil ditambahkan\n\n";
}

void DeleteJadwal(ListJadwal &LJ, ListPasien &LP, adrJ &p)
{
    /* I.S. terdefinisi list LJ dan LP, serta pointer p
    F.S. menghapus data jadwal berdasarkan data nama dokter dan tanggalnya */
    string namaDokter, tanggal;
    cout << "Jadwal yang ingin dihapus:\n";
    cout << "Nama Dokter : "; cin >> namaDokter;
    cout << "Tanggal     : "; cin >> tanggal;

    p = SearchJadwal(LJ, namaDokter, tanggal);

    if (p != NULL)
    {
        adrP x = LP.first;
        while (x != NULL)
        {
            if (x->jadwal == p)
            {
                if (x->info.hasil_pemeriksaan == "")
                {
                    cout << "\nPasien dokter " << p->info.namaDokter << " dengan Record ID " << x->info.record_id << " dan nama " << x->info.nama << " akan dipindahkan jadwalnya-\n\n";
                    PindahJadwal(LP, LJ, x->info.record_id, x->info.nama);
                }
                else
                {
                    x->jadwal = NULL;
                }
            }
            x = x->next;
        }

        if(p == LJ.first && p->next == LJ.first)
        {
            p->next = NULL;
            LJ.first = NULL;
        }
        else if (p == LJ.first && p->next != LJ.first)
        {
            adrJ q = LJ.first;
            while(q->next != LJ.first)
            {
                q = q->next;
            }
            LJ.first = p->next;
            p->next = NULL;
            q->next = LJ.first;
        }
        else if (p->next == LJ.first)
        {
            adrJ q = LJ.first;
            while(q->next != p)
            {
                q = q->next;
            }

            q->next = LJ.first;
            p->next = NULL;
        }
        else
        {
            adrJ prec = LJ.first;
            while(prec->next != p)
            {
                prec = prec->next;
            }

            prec->next = p->next;
            p->next = NULL;
        }

        cout << "Sukses menghapus jadwal\n\n";
    }
    else
    {
        cout << "\nJadwal yang ingin dihapus tidak ada\n\n";
    }
}



int CountConnectedPasien(ListJadwal LJ, ListPasien LP, string tanggal)
{
    // mengembalikan banyak elemen pasien di list LP pada tanggal tertentu
    int n = 0;
    adrP x = LP.first;
    while (x != NULL)
    {
        if (x->jadwal != NULL && x->jadwal->info.tanggal == tanggal)
        {
            n++;
        }
        x = x->next;
    }
    return n;
}

void ShowPasienbyDate(ListJadwal LJ, ListPasien LP)
{
    /* I.S. terdefinisi list LJ dan LP
    F.S. menampilkan jumlah pasien pada setiap tanggal beserta list seluruh data pasiennya*/
    if (LJ.first != NULL)
    {
        adrJ q = LJ.first;
        adrP x;
        string arrTgl[31];
        bool sudah = false;
        int idx_tgl = -1;
        int i;
        while (q->next != LJ.first)
        {
            for(i = 0; i <= idx_tgl; i++)
            {
                if (arrTgl[i] == q->info.tanggal)
                {
                    sudah = sudah || true;
                }
                else
                {
                    sudah = sudah || false;
                }
            }

            if (!sudah)
            {
                idx_tgl++;
                arrTgl[idx_tgl] = q->info.tanggal;
            }


            sudah = false;
            q = q->next;
        }

        for(i = 0; i <= idx_tgl; i++)
        {
            if (arrTgl[i] == q->info.tanggal)
            {
                sudah = sudah || true;
            }
            else
            {
                sudah = sudah || false;
            }
        }

        if (!sudah)
        {
            idx_tgl++;
            arrTgl[idx_tgl] = q->info.tanggal;
        }


        int banyakPasien;
        for (i = idx_tgl; i >= 0; i--)
        {
            banyakPasien = CountConnectedPasien(LJ,LP, arrTgl[i]);

            if (banyakPasien == 0)
            {
                cout << "- Pada tanggal " << arrTgl[i] << " tidak terdapat pasien.\n\n";
            }
            else
            {
                cout << "- Pada tanggal " << arrTgl[i] << " terdapat " << banyakPasien << " pasien, yaitu:\n";

                x = LP.first;
                int counter = 0;
                while (x != NULL)
                {
                    if (x->jadwal != NULL && x->jadwal->info.tanggal == arrTgl[i])
                    {
                        counter++;
                        cout << "### Pasien " << counter << " ###\n";
                        cout << "Record ID         : " << x->info.record_id << endl;
                        cout << "Nama              : " << x->info.nama << endl;
                        cout << "Status BPJS       : " << x->info.statusBPJS << endl;
                        cout << "Dokter            : " << x->jadwal->info.namaDokter << endl;
                        cout << "-------------------------------------------\n";
                    }
                    x = x->next;
                }
                cout << endl;
            }

        }
    }
    else
    {
        cout << "Maaf, jadwal belum tersedia\n\n";
    }

}

adrJ SearchJadwal(ListJadwal LJ, string namaDokter, string tanggal)
{
    /* mengembalikan alamat dari elemen list LJ memiliki namaDokter dan tanggal yang sesuai dengan input,
    atau NULL apabila tidak ditemukan */
    adrJ p = LJ.first;
    while (p->next != LJ.first)
    {
        if(p->info.namaDokter == namaDokter && p->info.tanggal == tanggal)
        {
        return p;
        }
        p = p->next;
    }
    if(p->info.namaDokter == namaDokter && p->info.tanggal == tanggal)
    {
        return p;
    }


    return NULL;
}

void ShowAllJadwal(ListJadwal LJ)
{
    /* I.S. terdefinisi list LJ (mungkin kosong)
    F.S. menampilkan isi dari list LJ */
    if (LJ.first == NULL)
    {
        cout << "Maaf, jadwal belum tersedia\n\n";
    }
    else
    {
        int counter = 0;
        adrJ p = LJ.first;
        cout << "Jadwal yang tersedia\n";
        while (p->next != LJ.first)
        {
            counter++;
            cout << "### Jadwal " << counter << " ###\n";
            cout << "Tanggal      : " << p->info.tanggal << endl;
            cout << "Jam Praktek  : " << p->info.jamPraktek << endl;
            cout << "ID Dokter    : " << p->info.idDokter << endl;
            cout << "Nama Dokter  : " << p->info.namaDokter << endl;
            cout << "Spesialisasi : " << p->info.spesialisasi << endl;
            cout << "Kuota Pasien : " << p->info.kuotaPasien << endl << endl;

            p = p->next;
        }
        counter++;
        cout << "### Jadwal " << counter << " ###\n";
        cout << "Tanggal      : " << p->info.tanggal << endl;
        cout << "Jam Praktek  : " << p->info.jamPraktek << endl;
        cout << "ID Dokter    : " << p->info.idDokter << endl;
        cout << "Nama Dokter  : " << p->info.namaDokter << endl;
        cout << "Spesialisasi : " << p->info.spesialisasi << endl;
        cout << "Kuota Pasien : " << p->info.kuotaPasien << endl << endl;
    }

}

void findConnection(ListJadwal LJ, ListPasien LP,int idPasien, string namaPasien, string tanggal)
{
    /* I.S. terdefinisi list LJ dan LP, idPasien, namaPasien, dan tanggal
    F.S. apabila pasien dengan namaPasien dan idPasien ada di list LP, maka program akan menampilkan nama dokter yang memeriksa pasien tersebut*/
    adrP pointerpas = SearchPasien(LP, idPasien, namaPasien);
    if (pointerpas != NULL)
    {
        if (pointerpas->jadwal->info.tanggal == tanggal)
        {
            cout << "\nPasien atas nama " << namaPasien << " akan diperiksa oleh Dokter " << pointerpas->jadwal->info.namaDokter << " pada tanggal " << tanggal << endl << endl;
        }
        else
        {
            cout << "\nPasien atas nama " << namaPasien << " tidak memiliki jadwal pemeriksaan pada tanggal " << tanggal << endl << endl;
        }
    }
    else
    {
        cout << "\nPasien atas nama " << namaPasien << " tidak ditemukan." << endl << endl;
    }
}

void PindahJadwal(ListPasien &LP, ListJadwal LJ, int idPasien, string namaPasien)
{
    /* I.S. terdefinisi list LJ dan LP, idPasien, dan namaPasien
    F.S. apabila pasien dengan namaPasien dan idPasien ada di list LP, maka program akan memindahkan jadwal pasien ke jadwal baru yang tersedia*/
    if (!KuotaJadwalTersedia(LJ))
    {
        cout << "Maaf, semua kuota jadwal sudah penuh!\n";
        return;
    }

    adrP pasien = SearchPasien(LP, idPasien, namaPasien);

    if (pasien != NULL && pasien->info.hasil_pemeriksaan == "")
    {
        (pasien->jadwal)->info.kuotaPasien++;

        string namaDokter, tanggal;
        cout << "Pindahkan ke jadwal dengan:\n";
        cout << "Nama Dokter : "; cin >> namaDokter;
        cout << "Tanggal     : "; cin >> tanggal;

        adrJ jadwalBaru = SearchJadwal(LJ, namaDokter, tanggal);

        while (jadwalBaru == NULL || jadwalBaru == pasien->jadwal || jadwalBaru->info.kuotaPasien == 0)
        {
            if (jadwalBaru == pasien->jadwal){
                cout << "\nMaaf anda memasukkan jadwal yang sama. Mohon masukan jadwal lain\n";
            }
            else{
                cout << "\nMaaf, jadwal dokter " << namaDokter << " tidak tersedia. Mohon masukan jadwal lain\n";
            }

            cout << "Pindahkan ke jadwal dengan:\n";
            cout << "Nama Dokter : "; cin >> namaDokter;
            cout << "Tanggal     : "; cin >> tanggal;

            jadwalBaru = SearchJadwal(LJ, namaDokter, tanggal);
        }

        pasien->jadwal = jadwalBaru;
        jadwalBaru->info.kuotaPasien--;
        cout << "\nJadwal pasien berhasil dipindahkan\n\n";
    }
    else
    {
        cout << "\nMaaf, pasien tidak ditemukan\n\n";
    }
}

int ShowMenu()
{
    int opsi;
    cout << "==================== MENU ====================" << endl;
    cout << "1. Menambahkan jadwal" << endl;
    cout << "2. Menambahkan pasien" << endl;
    cout << "3. Menampilkan jadwal yang tersedia" << endl;
    cout << "4. Menampilkan daftar pasien" << endl;
    cout << "5. Menampilkan pasien berdasarkan tanggal" << endl;
    cout << "6. Menghapus jadwal" << endl;
    cout << "7. Menghapus pasien" << endl;
    cout << "8. Memindahkan jadwal" << endl;
    cout << "9. Memasukan hasil pemeriksaan" << endl;
    cout << "10. Menampilkan nama dokter dari pasien" << endl;
    cout << "0. Exit" << endl;
    cout << "\nMasukan menu yang diinginkan: "; cin >> opsi;
    cout << endl;
    return opsi;
}
