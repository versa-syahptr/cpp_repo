#include <iostream>

using namespace std;

typedef int infotype;


class List{
    struct Elmt {
        infotype info;
        Elmt *next = NULL, *prev = NULL;
    };
    Elmt *first = NULL, *last = NULL;
    int last_index = -1;
    infotype operator [](int i){
        Elmt *p;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
