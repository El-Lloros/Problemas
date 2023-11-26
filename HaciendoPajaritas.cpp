#include <iostream>

using namespace std;

int pajaritas(int mm1, int mm2) {
    if (mm1 <= 9 || mm2 <= 9) {
        return 0;
    }

    int a;
    if (mm1 > mm2) {
        a = mm1 / mm2;
        mm1 -= mm2 * a;
    } else {
        a = mm2 / mm1;
        mm2 -= mm1 * a;
    }

    return a + pajaritas(mm1, mm2);
}

int main() {
    int mm1, mm2;
    cin >> mm1 >> mm2 ;
    while ((mm1 != 0 || mm2 != 0)) {
        int cont = pajaritas(mm1, mm2);
        cout << cont << '\n';
        cin >> mm1 >> mm2 ;
    }

    return 0;
}
