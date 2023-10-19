#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

vector<vector<llint>> matriz;
vector<vector<llint>> mem;
int linhas;
int colunas;


llint pd(int linha_atual, int coluna_atual, int col_ant) {
    if (mem[linha_atual][coluna_atual] != 0) 
        return mem[linha_atual][coluna_atual];

    llint max_linha = 0;
    for (int i = 0; i < colunas; i++) {
        // nao posso ir escolher o mesmo produto do dia anterior
        if (coluna_atual == i) continue; 

        max_linha = max(pd(linha_atual+1, i, coluna_atual), max_linha);  
    }

    return mem[linha_atual][coluna_atual] = matriz[linha_atual][coluna_atual] + max_linha;
}

llint solve() {
    for (int i = 0; i < colunas; i++)
        pd(0, i, -1);

    llint resp = 0; // pegando o maior valor da primeira linha(melhor resultado)
    for (int j = 0; j < colunas; j++) 
        resp = max(resp, mem[0][j]);
    
    return resp;
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

    // ultima linha da mem eh igual ao da matriz
    mem[linhas-1] = matriz[linhas-1]; 
    
    cout << solve() << endl;
    
    return 0;
}