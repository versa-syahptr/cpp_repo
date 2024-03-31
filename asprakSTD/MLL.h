#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct fak_node *adrFak;
typedef struct jur_node *adrJur;

struct fakultas {
    string nama, visi, misi, web;
    int n_jurusan;
};

struct jurusan {
    string nama, visi, misi, web, akre;
};

struct jur_node {
    jurusan info;
    adrJur next;
};

struct fak_node {
    fakultas info;
    adrFak pre, next;
    adrJur jur;
};

struct fak_list {
    adrFak first, last;
};

void create_list(fak_list &l);
void insert_fak(fak_list &l, adrFak p);
adrFak create_fak_node(fakultas info);
fakultas create_fakultas(string nama, string visi, string misi, string web, int n_jurusan);

jurusan create_jurusan(string nama, string visi, string misi, string web, string akre);
adrJur create_jur_node(jurusan info);
void insert_jur(adrFak &fak, adrJur p);


adrFak search_fak(fak_list &l, string nama);
void delete_fak(fak_list &l, string nama);

void print(fak_list l);


#endif // MLL_H_INCLUDED
