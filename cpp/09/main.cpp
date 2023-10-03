#include <bits/stdc++.h>
using namespace std;

vector<long long int> musicas;
vector<long long int> custo;
set<long long int> caminho;
long long int n_musicas;

long long int calcula_custo(int n) {
    return n >= n_musicas ? custo[n_musicas-1] : custo[n];
}

long long int dp(long long int n) {
    if (n >= n_musicas) return musicas[n_musicas-1];
    if (custo[n] != 0) return custo[n];
    return custo[n] = min( calcula_custo(n+1)+abs(musicas[n] - dp(n+1)), calcula_custo(n+2)+abs(musicas[n] - dp(n+2)) );
}

void solve() {
    for (long long int i = n_musicas-1; i >= 0; i--) {
        dp(i);
    }

    for (long long int c : custo)
        cout << c << " ";
    cout << endl;
}

int main() {
    cin >> n_musicas;
    musicas.resize(n_musicas);
    custo.assign(n_musicas, 0);

    for (long long int i = 0; i < n_musicas; i++) 
        cin >> musicas[i];
    
    solve();
    long long int soma = 0;
    // for (long long int c : caminho)
    //     if (c < n_musicas)
    //         soma += custo[c];
    //         // cout << c << " ";
    // cout << soma << endl; 
    // cout << s << endl;
    return 0;
}