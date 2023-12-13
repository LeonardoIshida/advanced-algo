#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll calcula_num(ll n, char c) {
    return ((n << 1) + (c - '0')) % 131071;
}

int main() {
    char c;
    ll n = 0;

    while (cin >> c) {
        if (c == '#') {
            cout << (n == 0 ? "YES\n" : "NO\n");
            n = 0;
        } else {
            n = calcula_num(n, c);
        }
    }
    
    return 0;
}