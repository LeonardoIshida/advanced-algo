#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

struct aresta {
    int origem;
    int dest;
    int peso;
};

bool msm_grupo(vector<int>& pais, int v1, int v2) {
    return pais[v1] == pais[v2];
}

int encontrar_grupo(vector<int>& pais, int v) {
    return pais[v] == v ? v : pais[v] = encontrar_grupo(pais, pais[v]);
}

void agrupar(vector<int>& pais, vector<int>& rank, int v1, int v2) {
    if (msm_grupo(pais, v1, v2)) return;

    int g1 = encontrar_grupo(pais, v1);
    int g2 = encontrar_grupo(pais, v2);

    if (rank[g1] > rank[g2]) {
        pais[g2] = g1;
    } 
    else {
        pais[g1] = g2;
        if (rank[g1] == rank[g2]) 
            rank[g2]++;
    }
}

lli solve(vector<aresta> arestas, int num_v) {
    vector<int> rank(num_v+1, 0);
    vector<int> pais(num_v+1, -1);
    for (int i = 0; i < num_v+1; i++)
        pais[i] = i;

    lli total = 0;
    int mst_arestas = 0;
    for (aresta aresta : arestas) {
        int v1 = aresta.origem;
        int v2 = aresta.dest;

        if (encontrar_grupo(pais, v1) != encontrar_grupo(pais, v2)) {
            agrupar(pais, rank, v1, v2);
            total += aresta.peso;
            mst_arestas++;
        }   

        if (mst_arestas == num_v-1) return total;
    }

    return -1;
}

int main() {
    int num_v;
    int num_a;
    cin >> num_v >> num_a;

    int orig, dest, peso;
    vector<aresta> arestas;
    for (int i = 0; i < num_a; i++) {
        cin >> orig >> dest >> peso;

        arestas.push_back({orig, dest, peso});
    }

    // ordenando arestas pelo peso
    sort(arestas.begin(), arestas.end(), [](aresta &a1, aresta &a2) {
        return a1.peso < a2.peso;
    });

    cout << solve(arestas, num_v) << endl;

    return 0;
}