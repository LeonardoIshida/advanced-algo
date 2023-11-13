#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int arestas;
int vertices;
int max_subset;
vector<vector<llint>> matriz;
vector<vector<llint>> mem;

int calcula_mascara(int n) {
    return 1 << n;
}

llint pd(int v, int mascara) {
    if (mascara == max_subset-2) // visitei todos os vertices
        return 0;
    
    if (mem[v][mascara] != 0) // resultado ja calculado
        return mem[v][mascara];
    
    llint menor_custo = 1e9;
    for (int i = 1; i < vertices+1; i++) {
        // se vertice nao foi visitado, entao visitar
        if (!(mascara & calcula_mascara(i))) {
            // setando nova mascara
            int nova_mascara = mascara | calcula_mascara(i);

            // selecionando menor custo
            menor_custo = min(
                matriz[v][i] + pd(i, nova_mascara),
                menor_custo
            );
        }
    }
    
    return mem[v][mascara] = menor_custo;
}

void solve() {
    // partindo do vertice 1
    int mascara = calcula_mascara(1);
    llint resp = pd(1, mascara);

    // se resp == 1e9 nao existe caminho 
    cout << (resp == 1e9 ? -1: resp) << endl;
}

int main() {
    cin >> vertices >> arestas;

    matriz.resize(vertices+1);
    mem.resize(vertices+1);
    max_subset = 1<<(vertices+1);
    
    for (int i = 0; i < vertices+1; i++) {
        matriz[i].assign(vertices+1, 1e9);
        mem[i].assign(max_subset, 0);
        matriz[i][i] = 0;
    }

    for (int i = 0; i < arestas; i++) {
        int orig, dest, peso;
        cin >> orig >> dest >> peso;

        matriz[orig][dest] = peso;
        matriz[dest][orig] = peso;
    }

    solve();

    return 0;
}