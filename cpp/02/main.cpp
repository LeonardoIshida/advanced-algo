#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num_palestras;
    int inicio;
    int fim;
    vector<pair<int, int>> palestras;

    cin >> num_palestras;
    for (int i = 0; i < num_palestras; i++) { // inserindo todas as palestras
        cin >> inicio >> fim;
        palestras.push_back(make_pair(inicio, fim));
    }

    // ordenando as palestras crescentementes pela hora de termino 
    sort(palestras.begin(), palestras.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    int num_max_palestras = 0;
    int tempo_fim_atual = 0;
    for (int i = 0; i < num_palestras; i++) {
        if (palestras[i].first >= tempo_fim_atual) {
            tempo_fim_atual = palestras[i].second;
            num_max_palestras++;
        }
    }

    cout << num_max_palestras << endl;
}

int main() {
    solve();
    return 0;
}