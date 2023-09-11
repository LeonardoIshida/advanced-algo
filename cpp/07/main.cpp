#include <bits/stdc++.h>
using namespace std;

struct aresta {
    int origem;
    int dest;
    int peso;
};

int solve(vector<aresta> arestas, int num_v, int num_a) {
    vector<int> passou(num_v+1, 0);
    int cont_a = 0;
    int peso_total = 0;

    for (int i = 0; i < num_a; i++) {
        if (passou[arestas[i].dest] == 0) {
            passou[arestas[i].dest] = 1;
            // passou[arestas[i].origem] = 1;
            cont_a++;
            peso_total += arestas[i].peso;
            cout << "total: " << peso_total << endl;
        }

        if (cont_a == num_v-1) return peso_total;
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

    sort(arestas.begin(), arestas.end(), [](aresta &a1, aresta &a2) {
        return a1.peso < a2.peso;
    });

    for (aresta a : arestas) {
        cout << "origem: " << a.origem << "dest: " << a.dest << "peso: " << a.peso << endl;
    }

    cout << solve(arestas, num_v, num_a) << endl;

    return 0;
}