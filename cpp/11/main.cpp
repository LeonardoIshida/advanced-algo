#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

vector<vector<llint>> matriz;
vector<vector<llint>> mem;
vector<vector<llint>> menor_custo;
int n_vert;
int n_arestas;

void calc_menor_custo() {
    for (int i = 0; i < n_vert; i++) {
        for (int j = 0; j < n_vert; j++) {
            if (i == j) menor_custo[i][j] = 0;
            else menor_custo[i][j] = 1e9;
        }
    }

    
}

int main() {
    cin >> n_vert >> n_arestas;

    matriz.resize(n_vert+1);
    mem.resize(n_vert+1);
    llint pot2 = 1 < (n_vert+1);

    for (int i = 0; i < n_vert; i++) {
        matriz[i].resize(n_vert+1);
        mem[i].resize(pot2);
    }

    for (int i = 0; i < n_arestas; i++) {
        int orig, dest, peso;
        cin >> orig >> dest >> peso;
        matriz[orig][dest] = peso;
    }



    return 0;
}