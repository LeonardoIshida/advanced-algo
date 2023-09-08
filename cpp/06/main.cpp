#include <bits/stdc++.h>
using namespace std;

bool verifica(vector<int> estatuas, int range, int num_est, int total_expl) {
    int estatua_atual = estatuas[0];
    int num_expl = 1;
    
    for (int i = 1; i < num_est; i++) {
        if (estatuas[i] >= estatua_atual + range) {
            num_expl++;
            estatua_atual = estatuas[i];
        }

        if (num_expl > total_expl) return false;
    }

    return true;
}

int solve(vector<int> estatuas, int num_est, int total_expl) {
    int fim = 1e9;
    int inicio = 0;
    int meio;

    while (inicio <= fim) { // busca binaria
        meio = (fim+inicio) / 2;

        if (verifica(estatuas, meio*2 + 1, num_est, total_expl))
            fim = meio-1;
        else    
            inicio = meio+1;
    }

    return inicio;
}

int main() {
    vector<int> estatuas;
    int num_estatuas;
    int num_expl;
    int tmp;

    cin >> num_estatuas >> num_expl;

    for (int i = 0; i < num_estatuas; i++) {
        cin >> tmp;
        estatuas.push_back(tmp);
    }

    cout << solve(estatuas, num_estatuas, num_expl) << endl;

    return 0;
}