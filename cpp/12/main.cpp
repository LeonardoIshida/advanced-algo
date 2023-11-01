#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int arestas;
int vertices;
int max_subset;
vector<vector<llint>> matriz;
vector<vector<llint>> mem;

void solve() {



}

int main() {
    cin >> vertices >> arestas;

    matriz.resize(vertices+1);
    mem.resize(vertices+1);
    max_subset = 1<<(vertices+1);
    
    for (int i = 0; i < vertices+1; i++) {
        matriz[i].assign(vertices+1, 0);
        mem[i].assign(max_subset, 0);
    }

    for (int i = 0; i < arestas; i++) {
        int orig, dest, peso;
        cin >> orig >> dest >> peso;

        matriz[orig][dest] = peso;
        matriz[dest][orig] = peso;
    }


    return 0;
}