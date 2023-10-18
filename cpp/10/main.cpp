#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;

vector<vector<lint>> matriz;
vector<vector<lint>> mem;
int linhas;
int colunas;

// alocar a ultima linha fora da recursao
// dar um jeito na coluna anterior, salvar no comeco da func ?

lint pd(int linha_atual, int coluna_atual) {
    if (linha_atual == linhas) 
        return mem[linha_atual-1][coluna_atual] = matriz[linha_atual-1][coluna_atual];

    if (mem[linha_atual][coluna_atual] != 0) 
        return mem[linha_atual][coluna_atual];

    int coluna_ant = coluna_atual; 
    lint max_linha = 0;
    for (int i = 0; i < colunas; i++) {
        max_linha = max(pd(linha_atual+1, i), max_linha);  
    }
    if (linha_atual == linhas-1) max_linha = 0;

    return mem[linha_atual][coluna_atual] = matriz[linha_atual][coluna_atual] + max_linha;
}

int main() {
    cin >> linhas >> colunas;

    matriz.resize(linhas);
    mem.resize(linhas);

    for (int i = 0; i < linhas; i++) {
        matriz[i].resize(colunas);
        mem[i].assign(colunas, 0);

        for (int j = 0; j < colunas; j++) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < colunas; i++)
        pd(0, i);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << mem[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}