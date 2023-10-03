#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> lista_adj;
vector<int> visitado;
vector<int> low;
stack<int> pilha;
vector<int> na_pilha;
vector<int*> to_print;
vector<pair<int, int*>> grupo;
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

    for (int visinho : lista_adj[vert]) {
        if (visitado[visinho] == 0) {
            tarjan(visinho);

            low[vert] = min(low[vert], low[visinho]);
        }
        else if (na_pilha[visinho] == 1) {
            low[vert] = min(low[vert], visitado[visinho]);
        }
    }

    if (low[vert] == visitado[vert]) {
        int aux;
        int *g = (int *)malloc(sizeof(int));
        while (pilha.top() != vert) {

            int v = pilha.top(); // tarjan
            na_pilha[v] = 0;
            pilha.pop();

            to_print[v] = g; // printar resultado
            aux = min(aux, v);
        }

        int v = pilha.top(); // tarjan
        na_pilha[v] = 0;
        pilha.pop();
        num_cfc += 1;

        aux = min(aux, v); // printar resultado
        grupo.push_back(make_pair(aux, g));
        to_print[v] = g;
    }
}

void sort_e_atribui() {
    sort(grupo.begin(), grupo.end(), [](const auto& a, const auto& b) { 
        return a.first < b.first; 
    });

    for (int i = 0; i < grupo.size(); i++) {
        *(grupo[i].second) = i+1;
    }
}

void solve() {
    visitado.assign(num_v+1, 0);
    low.assign(num_v+1, -1);
    na_pilha.assign(num_v+1, 0);
    to_print.resize(num_v+1);

    for (int i = 1; i < num_v+1; i++) {
        if (visitado[i] == 0)
            tarjan(i);
    }

    sort_e_atribui();
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
    cout << num_cfc << endl;
    for (int i = 1; i < num_v+1; i++) {
        cout << *(to_print[i]) << " ";
    }
    cout << endl;
    
    return 0;
}