#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int arestas;
int vertices;
int max_subset;
vector<vector<llint>> matriz;
vector<vector<llint>> mem;
vector<pair<llint, int>> resp;
int vert_origem;

void print_mat() {
    for (int i = 0; i < vertices+1; i++) {
        for (int j = 0; j < vertices+1; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void print_mem() {
    for (int i = 1; i < vertices+1; i++) {
        for (int j = 0; j < max_subset; j++) {
            cout << mem[i][j] << " ";
        }
        cout << endl;
    }
}

int calcula_mascara(int n) {
    return 1 << n;
}

llint pd(int u, int v, int mascara) {
    if (mascara == max_subset-2) {
        // cout << "alouuu" << endl;
        return -1e15;
    }
    if (mem[v][mascara] != 0) return mem[v][mascara];

    llint menor = 1e15;
    for (int i = 1; i < vertices+1; i++) {
        if (matriz[v][i] != 0 && !(mascara & calcula_mascara(i))) {
            // matriz[v][i].second = true;
            // cout << "indo para " << i << "com mascara = "<< (mascara | calcula_mascara(i)) << endl;
            menor = min( 
                pd(v, i, mascara ^ (calcula_mascara(i))) + matriz[v][i],
                menor
            );
            // matriz[v][i].second = false;
            // mascara = mascara | (!calcula_mascara(i));
        }
    }

    // cout << "mem de v e mascara: " << v  << " " << mascara << " = " << menor << endl;
    // print_mem();
    mem[v][mascara] = menor;
    return mem[v][mascara] == 1e15 ? 0 : mem[v][mascara];
}

void solve() {
    llint menor = 1e15;
    for (vert_origem = 2; vert_origem < vertices+1; vert_origem++) {
        if (matriz[1][vert_origem] != 0) {
            // matriz[i][1].second = true;
            // cout << "saindo de " << i << endl;
            
            pd(1, vert_origem, 2 | calcula_mascara(vert_origem));
        
            // matriz[i][1].second = false;

            // printf("mascara = %d\n", 2|calcula_mascara(i));
        }
    }

    // print_mem();
    // cout << menor << endl;
    // for (int i = 1; i < vertices+1; i++)
    //     cout << mem[i][calcula_mascara(i) + 2] + matriz[1][i].first << " ";
    // cout << endl;
}

int main() {
    cin >> vertices >> arestas;

    matriz.resize(vertices+1);
    mem.resize(vertices+1);
    max_subset = 1<<(vertices+1);
    // cout << max_subset;
    
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
    // print_mat();
    solve();
    llint res = 1e15;
    for (int i = 1; i < vertices+1; i++) {
        if (mem[i][calcula_mascara(i) + 2] + matriz[1][i] > 1e9) {
            cout << -1 << endl;
            return 0;
        }

        res = min(
            mem[i][calcula_mascara(i) + 2] + matriz[1][i],
            res
        );
    }

    cout << res+1e15 << endl;

    return 0;
}