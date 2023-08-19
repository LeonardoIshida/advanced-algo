#include <iostream>
#include <map>
#include <set>
using namespace std;

int num_materias;
int num_matriculados;

void solve() {
    map<int, set<int>> alunos;
    map<int, int> materias;
    int key_aluno;

    // inserindo os alunos nas materias, e contando quantos alunos tem em cada materia
    cin >> num_materias;
    for (int i = 0; i < num_materias; i++) {
        cin >> num_matriculados;

        for (int j = 0; j < num_matriculados; j++) {
            cin >> key_aluno;

            if (alunos[key_aluno].insert(i).second) {
                materias[i]++;
            }
        }
    }

    // removendo alunos repetidos
    for(auto it = alunos.begin(); it != alunos.end(); it++) {
        if (it->second.size() > 1) {
            for (int mat: it->second) {
                materias[mat]--;
            }
        }
    }

    for (int i = 0; i < num_materias; i++) {
        cout << materias[i] << " ";
    }
    cout << "\n";
}

int main() {
    solve();

    return 0;
}