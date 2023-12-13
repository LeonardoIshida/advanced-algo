#include<bits/stdc++.h>

using namespace std;
typedef long long ll; 

ll MOD = 1e9 + 7;

long long pot(ll base, ll exp, ll mod) {
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

ll solve(ll a, ll b, ll c) {
    return pot(a, pot(b, c, MOD - 1), MOD);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }

    return 0;
}