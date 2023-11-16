#include <bits/stdc++.h>

using namespace std;

typedef long long int llint;
#define MAX 10000000

int n;
vector<llint> primos;
bitset<MAX> crivo;

void criar_crivo() {
    crivo.set();
    crivo[0].flip();
    crivo[1].flip();

    for (llint i = 2; i < MAX; i++) {
        if (!crivo[i]) continue; // nao eh primo

        for (llint j = i*i; j < MAX; j += i) {
            crivo[j].flip();
        }

        primos.push_back(i*i);
    }
}

bool solve(llint num) {
    return binary_search(primos.begin(), primos.end(), num);
}

int main() {
    cin >> n;
    criar_crivo();

    llint tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (solve(tmp))
            cout << "1";
        else 
            cout << "0";
    }
    cout << endl;

    return 0;
}