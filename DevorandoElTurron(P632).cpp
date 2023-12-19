#include <iostream>
using namespace std;

int v[400000], w[200000];

int turron(int v[], int n, int m, int t);

int turron(int v[], int n, int m, int t) {
    int a = 0;
    int b = 0;
    int TempRest = t;
    int k = n + m;
    int mas = 0;
    int ret = 0;

    while (b <k) {
        if (TempRest - v[b] >= 0) {
            
            TempRest -= v[b];
            b++;
            ret++;
        }
        else {
            TempRest += v[a];
            a++;
            ret--;
        }
        if (a <= n && b > n - 1) {
            mas = max(mas,ret);
        }
       
    }



    return mas;
}

int main() {
    int m, n, t;

    while (cin >> n >> m >> t) {
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        for (int j = 0; j < m; ++j) {
            cin >> w[j];
        }
        for (int j = 0; j < m; ++j) {
             v[n+j]=w[m-1-j];
        }


        cout << turron(v, n, m, t) << '\n';
    }

    return 0;
}
