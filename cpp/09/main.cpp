#include <bits/stdc++.h>
using namespace std;

vector<long long int> musicas;
vector<long long int> custo;
set<long long int> caminho;
long long int n_musicas;

long long int calcula_custo(int n) {
    return n >= n_musicas-1 ? custo[n_musicas-1] : custo[n];
}

long long int dp(int n) {
    if (n >= n_musicas-1) return musicas[n_musicas-1]; // caso que estoura o vetor
    if (custo[n] != 0) return musicas[n]; // ja calculado
    return custo[n] = min( 
        calcula_custo(n+1) + abs(musicas[n] - dp(n+1)), 
        calcula_custo(n+2) + abs(musicas[n] - dp(n+2)) 
    );
}

void solve() {
    for (int i = n_musicas-1; i >= 0; i--) {
        dp(i);
    }
}

int main() {
    cin >> n_musicas;
    musicas.resize(n_musicas);
    custo.assign(n_musicas, 0);

    for (long long int i = 0; i < n_musicas; i++) 
        cin >> musicas[i];
    
    solve();
    cout << custo[0] << endl;
    return 0;
}