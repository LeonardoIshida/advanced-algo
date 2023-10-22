#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

vector<vector<llint>> mem;
vector<pair<int, int>> itens;
int peso_max;
int n;

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= peso_max; j++) {
            if (itens[i].first > j)
                mem[i][j] = mem[i-1][j];
            else 
                mem[i][j] = max(
                    itens[i].second + mem[i-1][j-itens[i].first],
                    mem[i-1][j]      
                );
        }
    }
}

int main() {
    cin >> n >> peso_max;

    mem.resize(n+1);
    for (int i = 0; i < n+1; i++)
        mem[i].assign(peso_max+1, 0);

    itens.resize(n+1);
    itens[0] = make_pair(0, 0); // primeiro item 0 peso e 0 valor

    for (int i = 1; i <= n; i++) {
        int p, valor;
        cin >> p >> valor;

        itens[i] = make_pair(p, valor);
    }

    solve();
    cout << mem[n][peso_max] << endl;

    return 0;
}