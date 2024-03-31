#ifndef MEMBERH
#define MEMBERH
#include <iostream>

using namespace std;
const int MAX = 6;

struct member {
    string IDNumber;
    float Poin[MAX];
};

void inputData_1301213373(member *MB);
float ratarata_1301213373(member MB);
void showData_1301213373(member MB);

#endif // MEMBERH
