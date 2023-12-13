#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;
ll MAX = 1e9+7;

ll a, b, res, aux;
int n;

ll pot(ll base, ll exp, ll mod) {
    base %= mod;
    ll res = 1;

    while (exp > 0) {
        if (exp & 1) {
            res = res * base % mod;
        }

        base = base * base % mod;
        exp >>= 1;
    }

    return res;
}

ll solve(ll n1, ll n2) {
    return pot(n1, n2 , MAX);
}

int main() {
    cin >> n;
    // cout << n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        aux = solve(a , b);
        cout << aux << endl;
    }
    return 0;
}