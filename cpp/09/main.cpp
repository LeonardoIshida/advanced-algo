#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

vector<long long int> musicas;
vector<long long int> custo;
long long int n_musicas;

llint calcula_musica(int n) {
    if (n >= n_musicas) return musicas[n_musicas-1];
    return musicas[n];
}

llint dp(int i) {
    if (i >= n_musicas) return 0;
    if (custo[i] != 0) return custo[i];

    return custo[i] = min(
        dp(i+2) + abs(calcula_musica(i) - calcula_musica(i+2)),
        dp(i+1) + abs(calcula_musica(i) - calcula_musica(i+1))
    );
}

void solve() {
    dp(0);
}

int main() {
    cin >> n_musicas;
    musicas.resize(n_musicas);
    custo.assign(n_musicas, 0);

    for (int i = 0; i < n_musicas; i++) 
        cin >> musicas[i];
    
    solve();
    cout << custo[0] << endl;
    return 0;
}