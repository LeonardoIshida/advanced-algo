#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num_estatuas;
    long long int deslocamento;
    int estatua_atual;
    int num_guardas = 1;
    int tmp;

    cin >> num_estatuas >> deslocamento >> estatua_atual;
    int cobertura_estatuas = (deslocamento * 2) + 1;
    for (int i = 1; i < num_estatuas; i++) {
        cin >> tmp;
        if (tmp >= estatua_atual + cobertura_estatuas) {
            num_guardas++;
            estatua_atual = tmp;
        }
    }

    cout << num_guardas << endl;
}

int main() {
    solve();
    return 0;
}