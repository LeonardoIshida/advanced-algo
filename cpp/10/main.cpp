#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

vector<vector<llint>> matriz;
vector<vector<llint>> mem;
int linhas;
int colunas;


llint pd(int linha_atual, int coluna_atual, int col_ant) {
    // if (linha_atual == linhas) 
    //     return mem[linha_atual-1][coluna_atual] = matriz[linha_atual-1][coluna_atual];

    if (mem[linha_atual][coluna_atual] != 0) 
        return col_ant == coluna_atual ? 0 : mem[linha_atual][coluna_atual];

    int coluna_ant = coluna_atual; 
    llint max_linha = 0;
    for (int i = 0; i < colunas; i++) {
        max_linha = max(pd(linha_atual+1, i, coluna_ant), max_linha);  
    }

    // printf("linha %d coluna %lld com valor %lld + %lld\n", linha_atual, coluna_atual, matriz[linha_atual][coluna_atual], max_linha);
    return mem[linha_atual][coluna_atual] = matriz[linha_atual][coluna_atual] + max_linha;
}

int main() {
    cin >> linhas >> colunas;

    matriz.resize(linhas);
    mem.resize(linhas);

    llint soma0 = 0;
    llint soma1 = 0;
    llint soma2 = 0;
    llint soma4 = 0;

    for (int i = 0; i < linhas; i++) {
        matriz[i].resize(colunas);
        mem[i].assign(colunas, 0);

        for (int j = 0; j < colunas; j++) {
            cin >> matriz[i][j];
        }
    }

    mem[linhas-1] = matriz[linhas-1];
    for (int i = 0; i < colunas; i++)
        pd(0, i, -1);

    llint r = 0;
    for (int j = 0; j < colunas; j++) {
        r = max(r, mem[0][j]);
    }
    for (int j = 0; j < linhas; j++) {
        soma0 += matriz[j][0];
        soma1 += matriz[j][1];
        soma2 += matriz[j][2];
        soma4 += max(matriz[j][0], max(matriz[j][1], matriz[j][2]));
    }

    cout << soma0 << " " << soma1 << " " << soma2 << " " << soma4 << endl;
    cout << r << endl;
    // for (int i = 0; i < linhas; i++) {
    //     for (int j = 0; j < colunas; j++) {
    //         cout << mem[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    
    return 0;
}