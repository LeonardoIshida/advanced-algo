#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector<ll> num;

int solve() {
    int aux = 0;
    for (auto n : num)
        aux = aux ^ n;

    return !aux;
}

int main() {
    int casos;
    int n_pilhas;

    cin >> casos;
    for (int i = 0; i < casos; i++) {

        cin >> n_pilhas;
        num.resize(n_pilhas);
        for (int j = 0; j < n_pilhas; j++) {
            cin >> num[j];
        }

        cout << solve() << endl;
        num.clear();
    }

    return 0;
}