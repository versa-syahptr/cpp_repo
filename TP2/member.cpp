#include "member.h"

void inputData_1301213373(member *MB) {
    int k;
    cout << "Tuliskan ID Number : ";
    cin >> (*MB).IDNumber;
    k = 0;

    while (k < MAX) {
        cout << "Poin bulan ke-" << k+1 << ": ";
        cin >> (*MB).Poin[k];
        k++;
    }
    cout << endl;
}

float ratarata_1301213373(member MB) {
    int jumlah = 0;
    float rerata;
    for (int i=0; i<MAX; i++){
        jumlah += MB.Poin[i];
    }

    rerata =  (float)jumlah/MAX;
    return rerata;
}

void showData_1301213373(member MB) {
    cout << "Data Member:\n";
    cout << "ID Number: " << MB.IDNumber << endl;
    cout << "Poin: ";
    for (int i=0; i<MAX; i++){
        cout << MB.Poin[i] << " ";
    }
    cout << endl;
}
