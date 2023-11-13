#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

llint max_prime;
int n;
vector<llint> num;
vector<llint> primos;
vector<bool> aux;

void sieve_sundaram(llint maximo) {
    max_prime = (maximo-1)/2;
    aux.assign(max_prime+1, false);

    for (int i = 1; i < max_prime; i++) {
        for (int j = i; (i + j + 2*i*j) <= max_prime; j++) {
            aux[i + j + 2*i*j] = true;
        }
    }

    for (int i = 1; i <= max_prime; i++)
        if (aux[i] == false)
            primos.push_back(2*i + 1);
}

void solve() {
    char resp[n];
    
    for (llint n : num) {
        int divisores = 0;
        for (llint p: primos) {
            if (n % p == 0)
                divisores++;
            
            if (divisores > 3) break;
        }
        if (divisores == 3)
            strcat(resp, "1");
        else 
            strcat(resp, "0");

    }

    cout << resp << endl;

}

int main() {
    cin >> n;
    num.resize(n);

    llint maximo = -1;
    llint tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        maximo = max(tmp, maximo);
        num[i] = tmp; 
    }

    sieve_sundaram(maximo);
    solve();

    return 0;
}