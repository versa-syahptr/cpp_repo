#include "MLL.h"

void create_list(fak_list &l){
    l.first = NULL;
    l.last = NULL;
}

fakultas create_fakultas(string nama, string visi, string misi, string web, int n_jurusan){
    fakultas f;
    f.nama = nama;
    f.misi = misi;
    f.visi = visi;
    f.web = web;
    f.n_jurusan = n_jurusan;
    return f;
}
adrFak create_fak_node(fakultas info){
    adrFak node = new fak_node;
    node->info = info;
    node->pre = NULL;
    node->next = NULL;
    node->jur = NULL;
    return node;
}

void insert_fak(fak_list &l, adrFak p){
    if (l.first == NULL){
        l.first = p;
    } else {
        l.last->next = p;
    }
    l.last = p;
}

void insert_jur(adrFak &fak, adrJur p){
    adrJur q = fak->jur;
    if (q == NULL){
        fak->jur = p;
    } else {
        while (q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }

}

jurusan create_jurusan(string nama, string visi, string misi, string web, string akre){
    jurusan j;
    j.nama = nama;
    j.misi = misi;
    j.visi = visi;
    j.web = web;
    j.akre = akre;
    return j;
}

adrJur create_jur_node(jurusan info){
    adrJur jur = new jur_node;
    jur->info = info;
    jur->next = NULL;
    return jur;
}

adrFak search_fak(fak_list &l, string nama){
    adrFak p = l.first;
    while (p != NULL){
        if (p->info.nama == nama){
            return p;
        }
        p = p->next;
    }
    return p;
}

void delete_fak(fak_list &l, string nama){
    adrFak p = search_fak(l, nama);
    if (p == NULL){
        cout << "Fakultas " << nama << "tidak ditemukan\n";
    } else {
        p->pre->next = p->next;
        p->next->pre = p->pre;
        p->pre = NULL;
        p->next = NULL;
    }
}

void print(fak_list l){
    adrFak p = l.first;
    adrJur j;
    fakultas info;
    while (p != NULL){
        info = p->info;
        j = p->jur;
        cout << info.nama << " " << info.visi << " "<< info.misi << " "<< info.web << " Jrusan: "<< info.n_jurusan << endl;
        while (j != NULL){
            cout << "\tjurusan: " << p->jur->info.nama << endl;
            j = j->next;
        }
        p = p->next;
    }
}
