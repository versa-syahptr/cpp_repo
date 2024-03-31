#include "MLL.h"



int main()
{
    fak_list fl;
    adrFak pf;
    create_list(fl);
    pf = create_fak_node(create_fakultas("fakultas 1", "a", "b", "c", 1));
    insert_jur(pf, create_jur_node(create_jurusan("Jur 1", "a", "f", "c", "g")));
    insert_jur(pf, create_jur_node(create_jurusan("Jur 2", "a", "f", "c", "g")));
    insert_fak(fl, pf);
    insert_fak(fl, create_fak_node(create_fakultas("fakultas 2", "a", "f", "c", 2)));
    insert_fak(fl, create_fak_node(create_fakultas("fakultas 3", "a", "b", "r", 3)));
    print(fl);
    return 0;
}
