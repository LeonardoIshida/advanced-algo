#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> lista_adj;
vector<int> visitado;
vector<int> tempo;
queue<int> pilha;
int num_v;
int num_a;

void tarjan(int tempo_atual, int vert) {
    tempo[vert] = tempo_atual;
    visitado[vert] = 1;
    pilha.push(vert);

    for (int visinho : lista_adj[vert]) {
        if (visitado[visinho] == 0)
            tarjan(tempo_atual+1, visinho);
    }
}

void solve() {
    visitado.assign(num_v+1, 0);
    tempo.assign(num_v+1, -1);
    int tempo_atual = 0;

    for (int i = 0; i < num_v+1; i++) {
        if (visitado[i] == 0)
            tarjan();
    }
}

int main() {
    cin >> num_v >> num_a;

    lista_adj.resize(num_v+1);
    for (int i = 0; i < num_a; i++) {
        int orig, dest;
        cin >> orig >> dest;

        lista_adj[orig].push_back(dest);
    }


    return 0;
}