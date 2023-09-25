#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> lista_adj;
vector<int> visitado;
vector<int> low;
stack<int> pilha;
vector<int> na_pilha;
int num_v;
int num_a;
int num_cfc = 0;
int tempo_atual = 1;

void tarjan(int vert) {
    low[vert] = tempo_atual;
    visitado[vert] = tempo_atual;
    pilha.push(vert);
    na_pilha[vert] = 1;
    tempo_atual += 1;

    cout << "estou em " << vert << endl;

    for (int visinho : lista_adj[vert]) {
        if (visitado[visinho] == 0) {
            // cout << "indo para " << visinho << endl;
            tarjan(visinho);

            low[vert] = min(low[vert], low[visinho]);
        }
        else if (na_pilha[visinho] == 1) {
            low[vert] = min(low[vert], visitado[visinho]);
        }
    }

    cout << "low[u] = " << low[vert] << " == visitado[vert] = " << visitado[vert] << endl;
    if (low[vert] == visitado[vert]) {
        while (pilha.top() != vert) {
            int v = pilha.top();
            na_pilha[v] = 0;
            pilha.pop();
        }
        int v = pilha.top();
        na_pilha[v] = 0;
        pilha.pop();
        num_cfc += 1;
    }
}

void solve() {
    visitado.assign(num_v+1, 0);
    low.assign(num_v+1, -1);
    na_pilha.assign(num_v+1, 0);

    for (int i = 1; i < num_v+1; i++) {
        if (visitado[i] == 0)
            tarjan(i);
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
    solve();

    cout << "num cfc " << num_cfc << endl;
    return 0;
}