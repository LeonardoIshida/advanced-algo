#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> lista_adj, int origem) {
    
}

void solve() {

}

int main() {
    int num_v;
    int num_a;
    cin >> num_v >> num_a;

    vector<vector<pair<int, int>>> lista_adj(num_v);
    int peso, tmp_v1, tmp_v2;
    for (int i = 0; i < num_a; i++) {
        cin >> tmp_v1 >> tmp_v2 >> peso;

        lista_adj[tmp_v1].push_back(make_pair(tmp_v2, peso));
        lista_adj[tmp_v2].push_back(make_pair(tmp_v1, peso));
    }


    return 0;
}