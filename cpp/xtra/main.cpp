#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

vector<vector<int>> mem;
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

    mem.resize(peso_max+1);
    for (int i = 0; i < peso_max+1; i++)
        mem[i].assign(n+1, 0);

    itens.resize(n+1);
    itens[0] = make_pair(0, 0);

    for (int i = 1; i <= n; i++) {
        int p, valor;
        cin >> p >> valor;

        itens[i] = make_pair(p, valor);
    }

    solve();
    for (int i = 0; i <= peso_max; i++) {
        for (int j = 0; j <= n; j++)
            cout << mem[i][j] << " ";
        cout << endl;
    }
    // cout << mem[n-1][peso_max-1] << endl;

    return 0;
}