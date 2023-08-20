#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num_estatuas;
    int deslocamento;
    int pos;
    int ant;
    vector<int> estatuas;

    cin >> num_estatuas >> deslocamento >> pos;
    int cobertura_estatuas = (deslocamento * 2) + 1;
    for (int i = 0; i < num_estatuas; i++) {// inserindo as estatuas 
        estatuas.push_back(pos);
        ant = pos;
        cin >> pos;

        if (pos - ant < cobertura_estatuas && 
            pos != ant + 1) {
            while (ant < pos) {
                estatuas.push_back(0);
                ant++;
            }
        }
    }

    int len = estatuas.size();
    int num_guardas = 0;
    for (int i = 0; i < len; i++) {
        if (estatuas[i] == 0) continue;

        num_guardas++;
        i += cobertura_estatuas;
    }

    cout << num_guardas << endl;
}

int main() {
    solve();
    return 0;
}